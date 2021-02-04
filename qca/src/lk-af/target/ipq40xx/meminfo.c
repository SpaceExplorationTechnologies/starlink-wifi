/* Copyright (c) 2009-2012, The Linux Foundation. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of The Linux Foundation nor
 *       the names of its contributors may be used to endorse or promote
 *       products derived from this software without specific prior written
 *       permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NON-INFRINGEMENT ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
 * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

#if DEVICE_TREE			/* If using device tree */

#include <reg.h>
#include <debug.h>
#include <malloc.h>
#include <smem.h>
#include <stdint.h>
#include <libfdt.h>
#include <platform/iomap.h>

#define SIZE_1M             (1024 * 1024)

typedef struct {
	uint32_t size;
	uint32_t start_addr;
} mem_info;

mem_info fixed_memory[] = {
	{.size = 0x10000000, .start_addr = 0x80000000},
};

uint32_t *
target_mem_dev_tree_create(uint32_t * ptr, uint32_t size, uint32_t addr)
{
	*ptr++ = cpu_to_fdt32(addr);
	*ptr++ = cpu_to_fdt32(size);

	return ptr;
}

uint32_t *
target_dev_tree_create(uint32_t * ptr, mem_info usable_mem_map[],
		       uint32_t num_regions)
{
	uint32_t i;

	ASSERT(num_regions);

	dprintf(SPEW, "Number of HLOS regions in 1st bank = %u\n", num_regions);

	for (i = 0; i < num_regions; i++) {
		ptr = target_mem_dev_tree_create(ptr,
						 usable_mem_map[i].size,
						 usable_mem_map[i].start_addr);
	}
	return ptr;
}

uint32_t *
target_dev_tree_mem(uint32_t * num_of_entries)
{
	struct smem_ram_ptable_v1 ram_ptable;
	uint32_t *meminfo_ptr;
	uint32_t num_of_sections = 0;
	uint32_t *ptr;
	uint32_t last_fixed_add;
	int n;
	uint32_t i;
	int index = 0;
	int count = 0;
	int overflow = 0;

	/* Make sure RAM partition table is initialized */
	if (!(smem_ram_ptable_init_v1(&ram_ptable))) {
		dprintf(CRITICAL, "%s: ERROR: RAM partition table is not initialized \n",
			__func__);
		return NULL;
	}

	n = ARRAY_SIZE(fixed_memory);
	last_fixed_add = fixed_memory[n - 1].start_addr +
	    fixed_memory[n - 1].size;

	/* Find the number of parts in ram_ptable of category SDRAM and type SYS_MEMORY */
	for (i = 0; i < ram_ptable.len; i++) {
		if ((ram_ptable.parts[i].category == SDRAM) &&
		    (ram_ptable.parts[i].type == SYS_MEMORY))
			count++;
	}

	/* Calculating the size of the mem_info_ptr */
	for (i = 0; i < ram_ptable.len; i++) {
		if ((ram_ptable.parts[i].category == SDRAM) &&
		    (ram_ptable.parts[i].type == SYS_MEMORY)) {
			if ((ram_ptable.parts[i].start <= last_fixed_add) &&
			    ((ram_ptable.parts[i].start +
			      ram_ptable.parts[i].size) >= last_fixed_add)) {
				if ((ram_ptable.parts[i].start +
				     ram_ptable.parts[i].size) ==
				    last_fixed_add) {
					num_of_sections = n + (count - i - 1);
				} else {
					num_of_sections = n + (count - i);
					overflow = 1;
				}
				index = i + 1;
				break;
			}
		}
	}

	*num_of_entries = num_of_sections;
	meminfo_ptr =
	    (uint32_t *) malloc(sizeof(uint32_t) * num_of_sections * 2);

	if (!meminfo_ptr) {
		dprintf(CRITICAL, "%s: malloc failed\n",__func__);
		return NULL;
	}

	ptr = meminfo_ptr;

#if 0
	/* Assumption that the fixed memory region always starts from the first ram_ptable part */
	ASSERT((ram_ptable.parts[0].category == SDRAM) &&
	       (ram_ptable.parts[0].type == SYS_MEMORY) &&
	       (ram_ptable.parts[0].start == SDRAM_START_ADDR));
#endif

	/* Pass along all fixed memory regions to Linux */
	meminfo_ptr = target_dev_tree_create(meminfo_ptr, fixed_memory,
					     ARRAY_SIZE(fixed_memory));

	if (overflow) {
		/* Pass the memory beyond the fixed memory present in the partition */
		meminfo_ptr = target_mem_dev_tree_create(meminfo_ptr,
							 ram_ptable.parts[i].
							 size - last_fixed_add,
							 ram_ptable.parts[i].
							 start +
							 last_fixed_add);
	}
	for (i = index; i < ram_ptable.len; i++) {
		if ((ram_ptable.parts[i].category == SDRAM) &&
		    (ram_ptable.parts[i].type == SYS_MEMORY)) {
			/* Pass along all other usable memory regions to Linux */
			meminfo_ptr = target_mem_dev_tree_create(meminfo_ptr,
								 ram_ptable.
								 parts[i].size,
								 ram_ptable.
								 parts[i].
								 start);
		}
	}

	return ptr;
}
#endif /* DEVICE_TREE */
