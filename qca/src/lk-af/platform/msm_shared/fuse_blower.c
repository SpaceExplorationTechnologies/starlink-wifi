/*
 * Copyright (c) 2013-2016 The Linux Foundation. All rights reserved.
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

#include <string.h>
#include <stdint.h>
#include <scm.h>
#include <stdio.h>

int fuseipq(uint32_t address)
{
	int ret;
	uint32_t fuse_status = 0;
	struct fuse_blow {
		uint32_t address;
		uint32_t status;
	} fuseip;

	fuseip.address = address;
	fuseip.status = (uint32_t)&fuse_status;

	ret = scm_call(SCM_SVC_FUSE, TZ_BLOW_FUSE_SECDAT,
			&fuseip, sizeof(fuseip), NULL, 0);
	if (ret || fuse_status)
		printf("%s: Error in QFPROM write (%d, %d)\n",
			__func__, ret, fuse_status);

	if (fuse_status == FUSEPROV_SECDAT_LOCK_BLOWN)
		printf("Fuse already blown\n");
	else if (fuse_status == FUSEPROV_INVALID_HASH)
		printf("Invalid sec.dat\n");
	else if (fuse_status  != FUSEPROV_SUCCESS)
		printf("Failed to Blow fuses");
	else
		printf("Blow Success\n");

	return fuse_status;
}
