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

int main(int argc, char *argv[])
{
    FILE *in;
    char *fname = argv[1];
    unsigned char c;
    int count = 0;
    
    if (fname == NULL) {
        printf("input name error\n");
        return -1;
    }

    if ((in = fopen(fname, "rb")) == NULL) {
        printf("open file fails\n");
        return -1;
    }

    printf("const unsigned char vmlrd_lzma[] = {\n");

    while (fread(&c, sizeof(unsigned char), 1, in)) {
        printf("0x%02x, ", c);
        count++;
        if (count % 16 == 0)
            printf("\n");
    }

    printf("0x00};\n");
    printf("const unsigned long vmlrd_lzmaSize = sizeof(vmlrd_lzma);\n");

    fclose(in);
        
    return 0;
}
