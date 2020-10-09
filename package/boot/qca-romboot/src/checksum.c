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
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/mman.h>
#include <fcntl.h>

unsigned
checksum(unsigned *data, unsigned size, int byteswap)
{
	unsigned checksum = 0;
	int i;

	for (i = 0; i < size; i += 4) {
		checksum = checksum ^ *data;
		data++;
	}

	if (byteswap) {
		checksum =
			(((checksum >>  0) & 0xff) << 24) |
			(((checksum >>  8) & 0xff) << 16) |
			(((checksum >> 16) & 0xff) <<  8) |
			(((checksum >> 24) & 0xff) <<  0);
	}

	return checksum;
}

int main(int argc, char* argv[])
{
	int		fd, bs = 0;
	unsigned	*data;
	struct stat	stat;

	if (argc != 2 && argc != 3) {
		fprintf(stderr, "Usage: %s <filename> byteswap\n", argv[0]);
		return 1;
	}

	if ((fd = open(argv[1], O_RDONLY)) < 0) {
		perror(argv[1]);
		return 1;
	}

	if (fstat(fd, &stat) < 0) {
		perror(argv[1]);
		return 1;
	}

	data = mmap(NULL, stat.st_size, PROT_READ, MAP_SHARED, fd, 0);
	if (data == MAP_FAILED) {
		perror(argv[1]);
		return 1;
	}


	fprintf(stdout, "%08x", checksum(data, stat.st_size, (argc == 3)));

	return 0;	// data will automatically be unmapped at exit
}
