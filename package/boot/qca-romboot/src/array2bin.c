/*
 * Copyright (c) 2016, The Linux Foundation. All rights reserved.
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
*/

#include <stdio.h>

static int is_little_endian(void)
{
    unsigned int word = 0x1;
    unsigned char *byte = (unsigned char *) &word ;

    return (byte[0] ? 1 : 0);
}

int main(int argc, char *argv[])
{
    FILE *in;
    FILE *out;
    char *infname = argv[1];
    char *outfname = argv[2];
    unsigned char c;
    unsigned char tempArray[9] = {0};
    unsigned int tempInt = 0;
    unsigned int dataInt = 0;
    unsigned int hex_digit, i;
    unsigned int convert_base[8] = {268435456, 16777216, 1048576, 65536, 4096, 256, 16, 1};
   
    if ((infname == NULL) || (outfname == NULL)) {
        printf("input name error\n");
        return -1;
    }

    if ((in = fopen(infname, "rb")) == NULL) {
        printf("open input file fails\n");
        return -1;
    }

    if ((out = fopen(outfname, "wb")) == NULL) {
        printf("open output file fails\n");
        return -1;
    }

    while (fread(&c, sizeof(unsigned char), 1, in)) {
        if (c == '0') {
		    fread(&c, sizeof(unsigned char), 1, in);
		    if (c == 'x') {
			    fread(tempArray, sizeof(unsigned char), 8, in);
			    tempArray[8] = 0;
			    for (i = 8; i > 0; i--) {
				    if ((tempArray[i-1] > 47) && (tempArray[i-1] < 58)) {
					    hex_digit = tempArray[i-1] - 48;
				    } else if ((tempArray[i-1] > 64) && (tempArray[i-1] < 71)) {
					    hex_digit = tempArray[i-1] - 55;
				    } else {
        				printf("input name error\n");
        				return -1;
				    }   
				    tempInt += (hex_digit * convert_base[i-1]);
			    }   

			    if(is_little_endian()) {
				    for (i = 0; i < 4; i++) {
					    *(((char *)&dataInt)+i) = *(((char *)&tempInt)+(3-i));
				    }
			    } else {
				    dataInt = tempInt;
			    }

			    fwrite((char *)&dataInt, sizeof(unsigned char), 4, out);
			    tempInt = 0;
			    dataInt = 0;
		    }
	    }
    }

    fclose(in);
    fclose(out);
        
    return 0;
}
