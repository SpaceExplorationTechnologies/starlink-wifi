/*
 * Copyright (c) 2013, The Linux Foundation. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 and
 * only version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#include <stdio.h>
#include <string.h>

#define MAX_READ_SIZE	80
#define HIF_USB          1

unsigned long checksum = 0;

void write_file(FILE * out, unsigned char *buf, unsigned long size,
		unsigned char *endian, unsigned char nl)
{
	int i = 0;
	unsigned char tmp_buf[4];

	for (i = 0; i < size; i += 4) {

		if (nl == 2) {
			tmp_buf[0] = buf[i + 3];
			tmp_buf[1] = buf[i + 2];
			tmp_buf[2] = buf[i + 1];
			tmp_buf[3] = buf[i + 0];
			fprintf(out, "%08X\n",
				*((unsigned long *)(&tmp_buf[0])));
		} else {

			if (i % 16 == 0) {
				fprintf(out, "\n");
			}
			tmp_buf[0] = buf[i + 3];
			tmp_buf[1] = buf[i + 2];
			tmp_buf[2] = buf[i + 1];
			tmp_buf[3] = buf[i + 0];
			fprintf(out, "0x%08X,",
				*((unsigned long *)(&tmp_buf[0])));
		}
		checksum = checksum ^ *((unsigned long *)(&tmp_buf[0]));
	}
}

void write_rom(FILE * out, FILE * in)
{
	int size;
	long file_size;
	unsigned char buffer[MAX_READ_SIZE];
	int multiple = 0;

	file_size = size = 0;

	while (1) {
		size = fread(buffer, sizeof(unsigned char), sizeof(buffer), in);
		file_size += size;

		//write_file(out, buffer, size, NULL, 0);
		if (size == 0) {
			if (multiple)
				fprintf(out, "%08X\n", checksum);

			goto ERR_DONE;
		} else if (size < MAX_READ_SIZE) {
			multiple = 0;
			write_file(out, buffer, size, NULL, 2);
			fprintf(out, "%08X\n", checksum);
			goto ERR_DONE;
		} else if (size == MAX_READ_SIZE) {
			multiple = 1;
			write_file(out, buffer, MAX_READ_SIZE, NULL, 2);
		} else
			goto ERR_DONE;
	}

ERR_DONE:

	return;
}

const char DEFAULT_NAME[] = "zcFwImage";
void write_array(FILE * out, FILE * in, unsigned char hif, char *varname)
{
	int size;
	long file_size;
	unsigned char buffer[MAX_READ_SIZE];
	int multiple = 0;
	char *name;

	if (varname == NULL || strlen(varname) == 0) {
		name = (char *)DEFAULT_NAME;
	} else {
		name = varname;
	}

	file_size = size = 0;

	//  fprintf(out, "#include \"80211core_sh.h\"\n");
	fprintf(out, "const unsigned long %s[] = {", name);

	while (1) {
		size = fread(buffer, sizeof(unsigned char), sizeof(buffer), in);
		file_size += size;
		if (size == 0) {
			if (multiple) {
				fprintf(out, "0x%08X\n", checksum);
				file_size += 4;
			}

			fprintf(out, "};\n");
			fprintf(out,
				"\nconst unsigned long %sSize = sizeof(%s);\n",
				name, name);

			goto ERR_DONE;
		} else if (size < MAX_READ_SIZE) {
			multiple = 0;

			write_file(out, buffer, size, NULL, hif);

			fprintf(out, "0x%08X\n", checksum);

			if ((size % 4) != 0)
				file_size += (4 - (size % 4));

			file_size += 4;
			fprintf(out, "};\n");
			fprintf(out,
				"\nconst unsigned long %sSize = sizeof(%s);\n",
				name, name);

			goto ERR_DONE;
		} else if (size == MAX_READ_SIZE) {
			multiple = 1;
			write_file(out, buffer, MAX_READ_SIZE, NULL, hif);
		} else {
			goto ERR_DONE;
		}
	}

ERR_DONE:
	return;
}

int main(int argc, char *argv[])
{
	FILE *in, *out;
	int retVal;
	int i = 0;

	in = out = 0x0;

	if (argc < 3) {
		printf
		    ("\"bin2hex [input_file] [output_file] - gen array data\"!\n\r");
		printf
		    ("\"bin2hex [input_file] [output_file] [rom]- gen rom code\"!\n\r");
		goto ERR_DONE;
	}
	printf("bin2h %s %s!\n\r", argv[1], argv[2]);

	if ((in = fopen(argv[1], "rb")) == NULL)
		goto ERR_DONE;

	if ((out = fopen(argv[2], "wt")) == NULL)
		goto ERR_DONE;

	if (!strcmp(argv[3], "rom")) {
		/* for loading into RAM directly, e.g ROM code or patch code */
		write_rom(out, in);
	} else {
		write_array(out, in, 0, argc > 5 ? argv[5] : NULL);
	}

ERR_DONE:

	if (in)
		fclose(in);
	if (out)
		fclose(out);

	return 0;

}
