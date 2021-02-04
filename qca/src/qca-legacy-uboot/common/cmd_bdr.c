/* 
 * Copyright (c) 2014 Qualcomm Atheros, Inc.
 * 
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 * 
 */

/*     The module is designed to support a BDR with the highest sequence number in the flash.
 *	If it is successfule, bootloader will choose the BDR to startup.
 *  
 *
 */

#include <common.h>
#include <command.h>
#include <flash.h>
#include <malloc.h>
#include <configs/ap93-hgw.h>

#define TOTALFLASHSIZE 		CFG_FLASH_SIZE
#define FLASHSTARTADDRESS 	CFG_FLASH_BASE
#define FLASH_BLOCK_SIZE	CFG_FLASH_SECTOR_SIZE
/*
* Boot description record definitions
*/
#define BDRWordSize 4

#define BDRHeaderNWords 4
#define BDRHeaderNBytes (BDRHeaderNWords * BDRWordSize)
#define BDRHeader_OffsetMagic 0      /* bytes */
#define BDRHeader_OffsetSize 4      /* bytes */
#define BDRHeader_OffsetChecksum 8      /* bytes */
#define BDRHeader_OffsetSequence 12      /* bytes */
#define BDR_BeginMagic 0xFEEDCAFE

#define BDRTailerNWords 4
#define BDRTailerNBytes (BDRTailerNWords * BDRWordSize)
#define BDRTailer_OffsetMagic 4      /* bytes before end */
#define BDRTailer_OffsetSize 8      /* bytes before end */
#define BDR_EndMagic   0xFEEDFADE

#define TagWordToSelf(TagWord) (((TagWord)>>24)&0xff)
#define TagWordToTag(TagWord) (((TagWord)>>16)&0xff)
#define TagWordToNWords(TagWord) ((TagWord)&0x3fff)

#define BDRTag_STOP 1
#define BDRTag_BOOTADDR 2
#define BDRTag_BOOTARGS 3
#define BDRTag_REQUESTNUMBER 4

#define BDR_SIZE	256

unsigned int bdr_bootaddr = 0;
unsigned int bdr_seq = 0; 
char bdr_bootarg[512];

extern flash_info_t flash_info[];
/*
* Boot description records can be written at begin and/or end of each
*       64KB block of flash (regardless of erase block size)
*/
#define BDRBlockSize 0x10000

#define flashaddr(x)	(char *)((volatile char *)0xbf000000+(x))


/* big endian -- extract big endian integer from byte stream
*/
static inline unsigned big_endian(unsigned char *p)
{
    return ((p[0]<<24) | (p[1]<<16) | (p[2]<<8) | p[3]);
}	

/*
 * fix endian
 */
static inline unsigned fix_endian(unsigned word)
{
	return word;
}

/*
 * Big endian in the flash.
 * 0:OK,-1:parameters error,-2: NO STOP tag.
 */
int parse_tag(int * bdrp,int size){

	int tags = 0,tagname = 0,tagsize = 0,tagno = 0;
	int i = 0;
	unsigned data;

	// Reset the value to prevent the failure of parsing the bdr.	
	bdr_bootaddr = 0;
	memset(bdr_bootarg,0,sizeof(bdr_bootarg));

	for(i = 0;i<size;i++)
	{
		data = big_endian((char *)bdrp);
		printf(" -Tag 0x%x.\n",*bdrp);
		tagname = (data>>16)&0xff;
		tagno = (data>>24)&0xff;
		tagsize = (data & 0xffff) - 1;

		if((tags != tagno)||(tagsize<0)) return -1;

		switch(tagname)
		{
			case BDRTag_STOP:
				if(tagsize==0) return 0;
				else return -1;

			case BDRTag_BOOTADDR:
				bdrp++;
				if(tagsize==1){
					bdr_bootaddr = big_endian((char *)bdrp);
					printf("  --Boot address:0x%x at sequence 0x%x.\n",bdr_bootaddr,bdr_seq);
					bdrp++;
					break;
				}else return -1;

			case BDRTag_BOOTARGS:
				bdrp++;
				if(tagsize < 130){
					memcpy(bdr_bootarg,(char *)bdrp,tagsize * BDRWordSize);
					bdrp += tagsize;
					break;
				}else return -1;

			case BDRTag_REQUESTNUMBER:
				bdrp += tagsize +1;
				break;

			default:
				bdrp += tagsize + 1;
				break;
		}
			
		tags++;
	}

	return -2;
}

/* findBDRstart -- look for BDR at the beginning of 64KB of flash,
*       return sequence no.
*       Return 0 if not found (which is not a valid sequence number).
*
*       This is used for searching for existing sequence number so we
*       can be sure to have a larger one.
*       Sequence numbers are in BDRs (Boot Description Records) which
*       can be at the begin or end of any 64KB section of flash
*       (regardless of the erase block size).
*/

unsigned findBDRstart(int offset)
{
    unsigned magic1;
    unsigned magic2;
    unsigned size;
    unsigned sequence;
    unsigned char bottom[BDRHeaderNBytes];
    unsigned char top[BDRTailerNBytes];
    unsigned topoffset;
    unsigned bdrblock[BDR_SIZE];

    memcpy(bottom, flashaddr(offset),sizeof(bottom));
    memcpy(bdrblock,flashaddr(offset),sizeof(bdrblock));
    magic1 = big_endian(bottom + BDRHeader_OffsetMagic);

    if (magic1 != BDR_BeginMagic)
        return 0;

    size = BDRWordSize*big_endian( bottom + BDRHeader_OffsetSize);

    if (size <= BDRHeaderNBytes+BDRTailerNBytes)
        return 0;

    if (size >= BDRBlockSize)
        return 0;

    topoffset = offset + size;

    memcpy(top, flashaddr(topoffset-sizeof(top)),sizeof(top));

    magic2 = big_endian(top + sizeof(top)-BDRTailer_OffsetMagic);
    if (magic2 != BDR_EndMagic)
        return 0;

    if (BDRWordSize*big_endian(
                top+sizeof(top)-BDRTailer_OffsetSize) != size)
        return 0;

    sequence = big_endian(bottom + BDRHeader_OffsetSequence);

    if (sequence == 0 || sequence == 0xffffffff)
        return 0;       /* invalid */

    printf("Found starting sequence: 0x%x in offset 0x%x.\n",sequence,offset);
    if(sequence > bdr_seq){
	bdr_seq = sequence;
	parse_tag(bdrblock + BDRHeaderNWords,BDR_SIZE);
    }

    return sequence;
}

unsigned findBDRend(int offset) /* offset of begin of 64KB section */
{
    unsigned magic1;
    unsigned magic2;
    unsigned size;
    unsigned sequence;
    unsigned char bottom[BDRHeaderNBytes];
    unsigned char top[BDRTailerNBytes];
    unsigned topoffset;
    unsigned bottomoffset;
    unsigned bdrblock[BDR_SIZE];

    topoffset = offset + BDRBlockSize;

    memcpy(top, flashaddr(topoffset-sizeof(top)),sizeof(top));
    memcpy(bdrblock, flashaddr(topoffset-sizeof(bdrblock)),sizeof(bdrblock));

    magic2 = big_endian(top + sizeof(top)-BDRTailer_OffsetMagic);

    if (magic2 != BDR_EndMagic)
        return 0;

    size = BDRWordSize*big_endian(top+sizeof(top)-BDRTailer_OffsetSize);

    if (size <= BDRHeaderNBytes+BDRTailerNBytes)
        return 0;

    if (size >= BDRBlockSize)
        return 0;

    bottomoffset = topoffset - size;

    memcpy(bottom, flashaddr(bottomoffset),sizeof(bottom));

    magic1 = big_endian(bottom + BDRHeader_OffsetMagic);

    if (magic1 != BDR_BeginMagic)
        return 0;

    if (BDRWordSize*big_endian(bottom + BDRHeader_OffsetSize) != size)
        return 0;

    sequence = big_endian(bottom+BDRHeader_OffsetSequence);

    if (sequence == 0 || sequence == 0xffffffff)
        return 0;       /* invalid */

    printf("Found end sequence: 0x%x in offset 0x%x.\n",sequence,offset);
    if(sequence > bdr_seq){
	bdr_seq = sequence;
	parse_tag(bdrblock + BDRTailerNWords,BDR_SIZE);
    }
	
    return sequence;
}


/* return  0: no existing valid Boot Description Recorder
 *         1: Found a valid DBR and set bootm and bootarg.
 */
unsigned findbdr(unsigned int flashaddr){
	int offset = 0;
	char buf[64];

	if(flashaddr >= FLASHSTARTADDRESS) flashaddr -= FLASHSTARTADDRESS;

	printf("findbdr flashaddr 0x%x.\n",flashaddr);
	bdr_seq = 0;
	bdr_bootaddr = 0xffffffff;
	memset(bdr_bootarg,0,sizeof(bdr_bootarg));

	for(offset =flashaddr;offset < TOTALFLASHSIZE;offset += BDRBlockSize)
	{
		findBDRstart(offset);
		findBDRend(offset);		
	}

	// if bootaddr is equal to 0xffffffff or 0x0, it is not valid.
	if(bdr_seq == 0||bdr_bootaddr==0xffffffff||bdr_bootaddr==0x0){
		printf("Failed to find a good BDR at seq 0x%x.\n",bdr_seq);
		return 0;
	}
	
	if(bdr_bootaddr < TOTALFLASHSIZE) bdr_bootaddr |= FLASHSTARTADDRESS;
	sprintf(buf,"%s 0x%x","bootm",bdr_bootaddr);
	setenv("bootcmd",buf);
	setenv("bootargs",bdr_bootarg);
	printf("Got a good Boot Descriptor Record.\n  -Sequence:0x%x.\n",bdr_seq);
	printf("  -Boot address: 0x%x.\n",bdr_bootaddr);
	if(strlen(bdr_bootarg) < 512)	
		printf("  -Boot arguments: %s.\n",bdr_bootarg);
	return 1;

}


int do_findbdr (cmd_tbl_t *cmdtp, int flag, int argc, char *argv[])
{
	int err = 0;

	unsigned int addr;

	if(argc < 2)
		err = findbdr(0);
	else{
		addr = simple_strtoul(argv[1], NULL, 16);
		err = findbdr(addr);
	}
	
	return err;
}
/*
 * flashaddr is the aboslute address.(0xbf.....)
 */
static unsigned writebdr(unsigned int flashaddr,unsigned bootaddr,char * cmdline){
	unsigned bdrblock[BDR_SIZE];
	unsigned * bdrp =  bdrblock;
	unsigned flash_offset = flashaddr - FLASHSTARTADDRESS;
	int err;
	unsigned seq;
	unsigned tags;
	char * p;
	char buffer[64];
	
	//Make sure the flashaddr is located at X*1024.
	if(flashaddr &0x3ff) return 1;
	
	err = findbdr(0);
	seq = bdr_seq + 1;

	bdrp[0]	= fix_endian(BDR_BeginMagic);
	bdrp[BDR_SIZE-1] = fix_endian(BDR_EndMagic);
	bdrp[1] = bdrp[BDR_SIZE-2] = fix_endian(BDR_SIZE);
	bdrp[2] = 0;
	bdrp[3] = seq;
	
	bdrp += 4;
	tags = 0;

	*bdrp++ = fix_endian(tags++<<24| BDRTag_REQUESTNUMBER<<16|2);
	*bdrp++ = fix_endian(0);//request number.

	*bdrp++ = fix_endian(tags++<<24| BDRTag_BOOTADDR <<16|2);
	*bdrp++ = fix_endian(bootaddr);//bootaddr.


	*bdrp++ = fix_endian(tags++<<24| BDRTag_BOOTARGS <<16|(1+sizeof(bdr_bootarg)/sizeof(int)));
	memcpy(bdrp,cmdline,sizeof(bdr_bootarg));
	bdrp += sizeof(bdr_bootarg)/sizeof(int);//bootarg.	

	*bdrp++ = fix_endian(tags++<<24| BDRTag_STOP<<16|1);//STOP tag
	p = (char *)malloc(FLASH_BLOCK_SIZE);

	memcpy(p,(char *)(((unsigned int )flashaddr/FLASH_BLOCK_SIZE )* FLASH_BLOCK_SIZE),FLASH_BLOCK_SIZE);
	memcpy(p + ((unsigned int )flashaddr%FLASH_BLOCK_SIZE), bdrblock,BDR_SIZE * 4);

	flash_erase(&flash_info[0],flash_offset/FLASH_BLOCK_SIZE,flash_offset/FLASH_BLOCK_SIZE);
	err = flash_write(p,((unsigned int )flashaddr/FLASH_BLOCK_SIZE )* FLASH_BLOCK_SIZE, FLASH_BLOCK_SIZE);

	free(p);

	if(err){
		flash_perror(err);
		return 1;
	}

	if(memcmp((char *)flashaddr,bdrblock,BDR_SIZE * 4)){
		printf("Error when writing bdr into flash.\n");
		return 1;
	}
	
	printf("BDR has been successfully written.\n");
	printf("BDR boot address: 0x%x.\n",bootaddr);
	printf("BDR boot arg: %s.\n",cmdline);

	sprintf(buffer,"%s 0x%x","bootm",bootaddr);
	setenv("bootcmd",buffer);
	setenv("bootargs",cmdline);

	return 0;
}

int do_writebdr (cmd_tbl_t *cmdtp, int flag, int argc, char *argv[])
{
	int err = 0;

	unsigned int flashaddr;
	unsigned int bootaddr;
	char cmd[512];

	char * s = getenv("bootargs");
	
	printf("do_writebdr :: size %d bootargs = %s .\n",sizeof(s),s);
	if(argc < 2)
		return 1;
	else{
		flashaddr = simple_strtoul(argv[1], NULL, 16);
		if(argc == 3 ) bootaddr = simple_strtoul(argv[2], NULL, 16);

		if(flashaddr < TOTALFLASHSIZE) flashaddr |= FLASHSTARTADDRESS;
		if(flashaddr < (FLASHSTARTADDRESS|0x80000)) return 1;
		memset(cmd,0,sizeof(cmd));
		memcpy(cmd,s,sizeof(cmd));
		//printf("do_writebdr :: bdr_bootargs = %s size %d.\n",bdr_bootarg,sizeof(bdr_bootarg));		
		err = writebdr(flashaddr,bootaddr,cmd);
	}
	
	return err;
}

U_BOOT_CMD(
 	writebdr,	CFG_MAXARGS,	1,	do_writebdr,
 	"writebdr- write a valid bdr in the flash based on existing sequences\n",
 	"[writebdr [arg ...]]\n  write a valid bdr based on existing sequences at the designed address  - \n"
 	"\tpassing arguments 'flash_offset, bootaddr'; you may assign the flash address,\n"
 	"\t'bootaddr' can be ignored or set it.\n"
);

U_BOOT_CMD(
 	findbdr,	CFG_MAXARGS,	1,	do_findbdr,
 	"findbdr - find a valid bdr with the highest sequence in the flash\n",
 	"[findbdr [arg ...]]\n  find a valid bdr with the highest sequence in the flash from the starting address  - \n"
 	"\tpassing arguments 'arg ...'; you may assign the address or not,\n"
 	"\t'arg' can be the starting address of search.\n"
);


