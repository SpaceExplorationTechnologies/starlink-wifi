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
#ifndef __LACPD_PORT_H
#define __LACPD_PORT_H

#include <libubox/list.h>

#include "fsm.h"
#include "port_info.h"
#include "lacp.h"
#include "lacpdu.h"

#define LACP_PORT_DUPLEX_DEFAULT 1
#define LACP_PORT_SPEED_DEFAULT 8
#define LACP_PORT_USER_KEY_DEFAULT 0
#define lacp_port_key_make(USER_KEY, SPEED, DUPLEX) (((USER_KEY)<<6) | (SPEED)<<1 | (DUPLEX))
#define lacp_port_key_get_user(KEY) (((KEY)>>6) & 0x3ff)
#define lacp_port_key_get_speed(KEY) (((KEY)>>1) & 0x1f)
#define lacp_port_key_get_duplex(KEY) ((KEY) & 0x1)
#define LACP_PORT_BITS_OF_SPEED 5
#define DEFAULT_PORT_PRIORITY 0xff

enum lacpd_port_state_machines {
	LACPD_PORT_STATE_MACHINE_RECEIVE,
	LACPD_PORT_STATE_MACHINE_PERIODIC,
	LACPD_PORT_STATE_MACHINE_SELECT,
	LACPD_PORT_STATE_MACHINE_MUX,
	LACPD_PORT_STATE_MACHINE_TRANSMIT,
	LACPD_PORT_STATE_MACHINE_MAX
};

enum lacpd_port_selecte_state {
	LACPD_SEL_STATE_SELECTED,				/*Selection Logic state machine has selected an aggregator for port*/
	LACPD_SEL_STATE_UNSELECTED,				/*Didn't selecte an aggregator for port*/
	LACPD_SEL_STATE_STANDBY					/*Though an aggregator is selected for port, but port can't be added into aggregator now*/
};

struct lacpd_port {
	struct list_head node;					/*Link to lacp->ports*/
	struct list_head aggregator_node;			/*Link to aggregator->ports*/

	struct lacpd_port_info actor_admin_port_info;		/*Instance of "struct lacpd_port_info". Only 'key' and 'state' are effective*/
	struct lacpd_port_info actor_port_info;			/*Instance of "struct lacpd_port_info"*/
	struct lacpd_port_info partner_admin_port_info;		/*Instance of "struct lacpd_port_info"*/
	struct lacpd_port_info partner_port_info;		/*Instance of "struct lacpd_port_info"*/
	uint32_t actor_port_aggregator_identifier;		/*Id of attached aggregator*/
	bool ntt;						/*Need to transmit lacpdu on this port*/
	bool port_enabled;					/*Link status of this port is ready*/

	/*bool begin*/						/*Not used. Need to init all state machines of this port*/
	bool lacp_enabled;					/*Lacp protocol is enabled on this port.Only set to true if port is full duplex*/
	bool actor_churn;					/*Local port enter wrong state, and can't be recovered. Need to report to Administrator*/
	bool partner_churn;					/*Peer port enter wrong state, and can't be recovered. Need to report to Administrator*/
	bool ready_N;						/*Port is ready to attach to selected aggregator. Set after wait_while_timer expired*/
	enum lacpd_port_selecte_state selected;			/*Do we have selected an aggregator for this port? "selected|unselected|standby"*/
	bool port_moved;					/*Previously port is connected to aother system, now it is connected self system*/

	/*struct uloop_timeout actor_churn_timer;*/		/*Not used. Timer to detect if local port entered error state. Time is Churn_Detection_Time*/
	/*struct uloop_timeout partner_churn_timer;*/		/*Not used. Timer to detect if peer port entered error state. Time is Churn_Detection_Time*/

	struct lacpd_lacp *lacp;				/*Lacp protocol instance this aggregator belongs to*/
	uint8_t mac[6];						/*Port's own mac address, it is used to send lacpdu*/
	uint32_t dev_ifindex;					/*Ifindex of physical network device which this port represent*/
	bool lacpdu_indicate;					/*Lacpdu arrived on this port*/
	struct lacpdu message[1];				/*Pending lacp packet to process*/

	struct fsm_runner runner;				/*All state machines of this port*/

	uint32_t tx_successes;					/*Stats for successful transmistion*/
	uint32_t tx_error;					/*Stats for failed transmistion*/
	uint32_t rx_successes;					/*Stats for successful receiving*/
	uint32_t rx_error;					/*Stats for failed receiving*/
};

/*
 * lacpd_port_fsm_schedule_run : state of port changed, we need to run all state machines of port after a specific time
 */
static inline void lacpd_port_fsm_schedule_run(struct lacpd_port *port)
{
	fsm_runner_schedule(&port->runner);
}

/*
 * lacpd_port_speed_to_key: convert speed in Mbps to bitmap
 */
static inline uint16_t lacpd_port_speed_to_key(uint32_t speed)
{
	uint32_t idx, speeds[LACP_PORT_BITS_OF_SPEED] = {1, 10, 100, 1000, 10000};

	for (idx = 0; idx < LACP_PORT_BITS_OF_SPEED; idx++) {
		if (speeds[idx] == speed) {
			return (1 << idx);
		}
	}

	return 0;
}

/*
 * lacpd_port_key_to_speed: convert speed in bitmap to Mbps
 */
static inline uint32_t lacpd_port_key_to_speed(uint32_t speed_key)
{
	uint32_t idx, speed = 1;

	for (idx = 0; idx < LACP_PORT_BITS_OF_SPEED; idx++, speed *= 10) {
		if ((1 << idx) & speed_key) {
			return speed;
		}
	}

	return 0;
}

/*
 * lacpd_port_lookup : lookup port by its physical network device
 * lacp: LACP protocol instance
 * dev_ifindex: requested network device
 * return value: found port or NULL
 */
struct lacpd_port *lacpd_port_lookup(struct lacpd_lacp *lacp, uint32_t dev_ifindex);
/*
 * lacpd_port_state_machine_get : get a specific type of state machine of port
 * port: LACP port to lookup
 * type: type of state machine to get
 * return value: found state machine or NULL
 */
struct state_machine *lacpd_port_state_machine_get(struct lacpd_port *port, enum lacpd_port_state_machines type);
/*
 * lacpd_port_dump_status : get status of LACP port
 * port: LACP port whose status to get
 * p: lacp use this printer to print content of status
 */
void lacpd_port_dump_status(struct lacpd_port *port, struct lacpd_status_printer *p);
/*
 * lacpd_port_new : create port base on a physical network device
 * lacp: LACP protocol instance
 * port_num: id of port in above LACP protocol instance
 * dev_ifindex: network device for this LACP port
 * param: parameters for this LACP port
 * return value: created LACP port or NULL
 */
struct lacpd_port *lacpd_port_new(struct lacpd_lacp *lacp, uint32_t port_num, uint32_t dev_ifindex, struct lacp_port_parameters *param);
/*
 * lacpd_port_destroy: stop all state machines of port, delete it from its attached aggregator, free it
 * port: LACP port to destroy
 */
void lacpd_port_destroy(struct lacpd_port *port);

#endif /*__LACPD_PORT_H*/
