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
#ifndef __PORT_INFO_H
#define __PORT_INFO_H

#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

struct lacpd_port_info_state {
	uint8_t activity:1;		/*Port is active or passive on the link*/
	uint8_t timeout:1;		/*Timeout of partner's information, true: short; false: long*/
	uint8_t aggregation:1;		/*Port is aggregatable or individual*/
	uint8_t synchronization:1;	/*Have been added into an aggregator, true: yes; false: no*/
	uint8_t collecting:1;		/*Receiving is enabled*/
	uint8_t distributing:1;		/*Transmiting is enabled*/
	uint8_t defaulted:1;		/*Partner's information is default value which is set by administrator*/
	uint8_t expired:1;		/*Partner's information has expired*/
};

struct lacpd_port_info {
	uint16_t system_priority;	/*System priority, big endian*/
	uint8_t system[6];		/*Mac address of system*/
	uint16_t key;			/* User key(10bit)|speed(5bit)|duplex(1bit) , big endian*/
	uint16_t port_priority;		/*Port priority, big endian*/
	uint16_t port;			/*Port number in system, big endian*/
	struct lacpd_port_info_state state;	/*Instance of "enum lacpd_port_info_state"*/
};

#define ignore_mask_system_priority 		(1<<0)
#define ignore_mask_system 					(1<<1)
#define ignore_mask_key 					(1<<2)
#define ignore_mask_port_priority 			(1<<3)
#define ignore_mask_port 					(1<<4)
#define ignore_mask_state_activity 			(1<<5)
#define ignore_mask_state_timeout 			(1<<6)
#define ignore_mask_state_aggregation 		(1<<7)
#define ignore_mask_state_synchronization 	(1<<8)
#define ignore_mask_state_collecting 		(1<<9)
#define ignore_mask_state_distributing 		(1<<10)
#define ignore_mask_state_defaulted 		(1<<11)
#define ignore_mask_state_expired 			(1<<12)
#define ignore_mask_state_NA 				(0)

#define ignore_states(n1, n2, n3, n4) ((ignore_mask_state_ ## n1) | (ignore_mask_state_ ## n2) | (ignore_mask_state_ ## n3) | (ignore_mask_state_ ## n4))
#define ignore_all_states (ignore_states(activity, timeout, aggregation, synchronization) | ignore_states(collecting, distributing, defaulted, expired))
#define ignore_all_states_except(name) (ignore_all_states & ~(ignore_mask_state_ ## name))

/*
 * port_info_equal : check if informations of two port are the same. Ignore some fields specified in 'ignore_mask'
 */
bool port_info_equal(struct lacpd_port_info *a, struct lacpd_port_info *b, uint32_t ignore_mask);

#endif /*__PORT_INFO_H*/
