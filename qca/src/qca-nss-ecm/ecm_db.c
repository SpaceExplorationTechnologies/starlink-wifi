/*
 **************************************************************************
 * Copyright (c) 2014-2018, The Linux Foundation. All rights reserved.
 * Permission to use, copy, modify, and/or distribute this software for
 * any purpose with or without fee is hereby granted, provided that the
 * above copyright notice and this permission notice appear in all copies.
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT
 * OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 **************************************************************************
 */

#include <linux/version.h>
#include <linux/types.h>
#include <linux/ip.h>
#include <linux/tcp.h>
#include <linux/module.h>
#include <linux/skbuff.h>
#include <linux/icmp.h>
#include <linux/kthread.h>
#include <linux/debugfs.h>
#include <linux/pkt_sched.h>
#include <linux/string.h>
#include <linux/random.h>
#include <net/route.h>
#include <net/ip.h>
#include <net/tcp.h>
#include <asm/unaligned.h>
#include <asm/uaccess.h>	/* for put_user */
#include <net/ipv6.h>
#include <net/ip6_route.h>
#include <linux/inet.h>
#include <linux/in.h>
#include <linux/udp.h>
#include <linux/tcp.h>
#include <linux/netfilter_ipv4.h>
#include <linux/netfilter_bridge.h>
#include <net/netfilter/nf_conntrack.h>
#include <net/netfilter/nf_conntrack_helper.h>
#include <net/netfilter/nf_conntrack_l4proto.h>
#include <net/netfilter/nf_conntrack_l3proto.h>
#include <net/netfilter/nf_conntrack_core.h>
#include <net/netfilter/ipv4/nf_conntrack_ipv4.h>
#include <net/netfilter/ipv4/nf_defrag_ipv4.h>

/*
 * Debug output levels
 * 0 = OFF
 * 1 = ASSERTS / ERRORS
 * 2 = 1 + WARN
 * 3 = 2 + INFO
 * 4 = 3 + TRACE
 */
#define DEBUG_LEVEL ECM_DB_DEBUG_LEVEL

#include "ecm_types.h"
#include "ecm_db_types.h"
#include "ecm_state.h"
#include "ecm_tracker.h"
#include "ecm_classifier.h"
#include "ecm_front_end_types.h"
#include "ecm_classifier_default.h"
#include "ecm_db.h"

/*
 * Magic numbers
 */
#define ECM_DB_CONNECTION_INSTANCE_MAGIC 0xff23
#define ECM_DB_HOST_INSTANCE_MAGIC 0x2873
#define ECM_DB_MAPPING_INSTANCE_MAGIC 0x8765
#define ECM_DB_LISTENER_INSTANCE_MAGIC 0x9876
#define ECM_DB_NODE_INSTANCE_MAGIC 0x3312
#define ECM_DB_IFACE_INSTANCE_MAGIC 0xAEF1
#ifdef ECM_DB_CTA_TRACK_ENABLE
#define ECM_DB_CLASSIFIER_TYPE_ASSIGNMENT_MAGIC 0xAEF4
#endif
#ifdef ECM_MULTICAST_ENABLE
#define ECM_DB_MULTICAST_INSTANCE_MAGIC 0xc34a
#endif

/*
 * Check the configured HZ value.
 */
#if HZ > 100000
#error "Bad HZ value"
#endif

/*
 * Global lists.
 * All instances are inserted into global list - this allows easy iteration of all instances of a particular type.
 * The list is doubly linked for fast removal.  The list is in no particular order.
 */
struct ecm_db_connection_instance *ecm_db_connections = NULL;
struct ecm_db_mapping_instance *ecm_db_mappings = NULL;
struct ecm_db_host_instance *ecm_db_hosts = NULL;
struct ecm_db_node_instance *ecm_db_nodes = NULL;
struct ecm_db_iface_instance *ecm_db_interfaces = NULL;

/*
 * Connection hash table
 */
#define ECM_DB_CONNECTION_HASH_SLOTS 32768
static struct ecm_db_connection_instance **ecm_db_connection_table;
						/* Slots of the connection hash table */
static int *ecm_db_connection_table_lengths;
						/* Tracks how long each chain is */
static int ecm_db_connection_count = 0;		/* Number of connections allocated */
static int ecm_db_connection_serial = 0;	/* Serial number - ensures each connection has a unique serial number.
						 * Serial numbers are used mainly by classifiers that keep their own state
						 * and can 'link' their state to the right connection using a serial number.
						 * The serial number is also used as a soft linkage to other subsystems such as NA.
						 */
typedef uint32_t ecm_db_connection_hash_t;

/*
 * Connection serial number hash table
 */
#define ECM_DB_CONNECTION_SERIAL_HASH_SLOTS 32768
static struct ecm_db_connection_instance **ecm_db_connection_serial_table;
						/* Slots of the connection serial hash table */
static int *ecm_db_connection_serial_table_lengths;
						/* Tracks how long each chain is */
typedef uint32_t ecm_db_connection_serial_hash_t;

/*
 * Mapping hash table
 */
#define ECM_DB_MAPPING_HASH_SLOTS 32768
static struct ecm_db_mapping_instance **ecm_db_mapping_table;
							/* Slots of the mapping hash table */
static int *ecm_db_mapping_table_lengths;
							/* Tracks how long each chain is */
static int ecm_db_mapping_count = 0;			/* Number of mappings allocated */
typedef uint32_t ecm_db_mapping_hash_t;

/*
 * Host hash table
 */
#define ECM_DB_HOST_HASH_SLOTS 32768
static struct ecm_db_host_instance **ecm_db_host_table;
							/* Slots of the host hash table */
static int *ecm_db_host_table_lengths;
							/* Tracks how long each chain is */
static int ecm_db_host_count = 0;			/* Number of hosts allocated */
typedef uint32_t ecm_db_host_hash_t;

/*
 * Node hash table
 */
#define ECM_DB_NODE_HASH_SLOTS 32768
static struct ecm_db_node_instance **ecm_db_node_table;
							/* Slots of the node hash table */
static int *ecm_db_node_table_lengths;
							/* Tracks how long each chain is */
static int ecm_db_node_count = 0;			/* Number of nodes allocated */
typedef uint32_t ecm_db_node_hash_t;

/*
 * Interface hash table
 */
#define ECM_DB_IFACE_HASH_SLOTS 8
static struct ecm_db_iface_instance *ecm_db_iface_table[ECM_DB_IFACE_HASH_SLOTS];
							/* Slots of the interface hash table */
static int ecm_db_iface_table_lengths[ECM_DB_IFACE_HASH_SLOTS];
							/* Tracks how long each chain is */
static int ecm_db_iface_count = 0;			/* Number of interfaces allocated */
typedef uint32_t ecm_db_iface_hash_t;

#define ECM_DB_IFACE_ID_HASH_SLOTS 8
static struct ecm_db_iface_instance *ecm_db_iface_id_table[ECM_DB_IFACE_ID_HASH_SLOTS];
							/* Slots of the interface id hash table */
static int ecm_db_iface_id_table_lengths[ECM_DB_IFACE_ID_HASH_SLOTS];
							/* Tracks how long each chain is */
typedef uint32_t ecm_db_iface_id_hash_t;

/*
 * Listeners
 */
static int ecm_db_listeners_count = 0;			/* Number of listeners allocated */
static struct ecm_db_listener_instance *ecm_db_listeners = NULL;
							/* Event listeners */

#ifdef ECM_STATE_OUTPUT_ENABLE
/*
 * ecm_db_iface_state_get_method_t
 *	Used to obtain interface state
 */
typedef int (*ecm_db_iface_state_get_method_t)(struct ecm_db_iface_instance *ii, struct ecm_state_file_instance *sfi);
#endif

/*
 * struct ecm_db_iface_instance
 */
struct ecm_db_iface_instance {
	struct ecm_db_iface_instance *next;		/* Next instance in global list */
	struct ecm_db_iface_instance *prev;		/* Previous instance in global list */
	struct ecm_db_iface_instance *hash_next;	/* Next Interface in the chain of Interfaces */
	struct ecm_db_iface_instance *hash_prev;	/* previous Interface in the chain of Interfaces */
	ecm_db_iface_type_t type;			/* RO: Type of interface */
	uint32_t time_added;				/* RO: DB time stamp when the Interface was added into the database */

	int32_t interface_identifier;			/* RO: The operating system dependent identifier of this interface */
	int32_t ae_interface_identifier;		/* RO: The accel engine identifier of this interface */
	char name[IFNAMSIZ];				/* Name of interface */
	int32_t mtu;					/* Interface MTU */

	struct ecm_db_iface_instance *iface_id_hash_next;	/* Next interface in the chain of interface id table */
	struct ecm_db_iface_instance *iface_id_hash_prev;	/* Previous interface in the chain of interface id table */
	ecm_db_iface_id_hash_t iface_id_hash_index;		/* Hash index value of chains */

#ifdef ECM_DB_ADVANCED_STATS_ENABLE
	uint64_t from_data_total;			/* Total of data sent by this Interface */
	uint64_t to_data_total;				/* Total of data sent to this Interface */
	uint64_t from_packet_total;			/* Total of packets sent by this Interface */
	uint64_t to_packet_total;			/* Total of packets sent to this Interface */
	uint64_t from_data_total_dropped;
	uint64_t to_data_total_dropped;
	uint64_t from_packet_total_dropped;
	uint64_t to_packet_total_dropped;
#endif

#ifdef ECM_DB_XREF_ENABLE
	/*
	 * For convenience interfaces keep lists of connections that have been established
	 * from them and to them.
	 * In fact the same connection could be listed as from & to on the same interface (think: WLAN<>WLAN AP function)
	 * Interfaces keep this information for rapid iteration of connections e.g. when an interface 'goes down' we
	 * can defunct all associated connections or destroy any accel engine rules.
	 */
	struct ecm_db_connection_instance *from_connections;		/* list of connections made from this interface */
	struct ecm_db_connection_instance *to_connections;		/* list of connections made to this interface */

	struct ecm_db_connection_instance *from_nat_connections;	/* list of NAT connections made from this interface */
	struct ecm_db_connection_instance *to_nat_connections;		/* list of NAT connections made to this interface */

	/*
	 * Normally only the node refers to the interfaces which it is reachable upon.
	 * The interface  also keeps a list of all nodes that can be reached.
	 */
	struct ecm_db_node_instance *nodes;				/* Nodes associated with this Interface */
	int node_count;							/* Number of Nodes in the nodes list */
#endif

	/*
	 * Interface specific information.
	 * type identifies which information is applicable.
	 */
	union {
		struct ecm_db_interface_info_ethernet ethernet;		/* type == ECM_DB_IFACE_TYPE_ETHERNET */
#ifdef ECM_INTERFACE_VLAN_ENABLE
		struct ecm_db_interface_info_vlan vlan;			/* type == ECM_DB_IFACE_TYPE_VLAN */
#endif
#ifdef ECM_INTERFACE_BOND_ENABLE
		struct ecm_db_interface_info_lag lag;			/* type == ECM_DB_IFACE_TYPE_LAG */
#endif
		struct ecm_db_interface_info_bridge bridge;		/* type == ECM_DB_IFACE_TYPE_BRIDGE */
#ifdef ECM_INTERFACE_PPPOE_ENABLE
		struct ecm_db_interface_info_pppoe pppoe;		/* type == ECM_DB_IFACE_TYPE_PPPOE */
#endif
#ifdef ECM_INTERFACE_L2TPV2_ENABLE
		struct ecm_db_interface_info_pppol2tpv2 pppol2tpv2;	/* type == ECM_DB_IFACE_TYPE_PPPOL2TPV2 */
#endif
#ifdef ECM_INTERFACE_PPTP_ENABLE
		struct ecm_db_interface_info_pptp pptp;			/* type == ECM_DB_IFACE_TYPE_PPTP */
#endif
#ifdef ECM_INTERFACE_MAP_T_ENABLE
		struct ecm_db_interface_info_map_t map_t;		/* type == ECM_DB_IFACE_TYPE_MAP_T */
#endif
		struct ecm_db_interface_info_unknown unknown;		/* type == ECM_DB_IFACE_TYPE_UNKNOWN */
		struct ecm_db_interface_info_loopback loopback;		/* type == ECM_DB_IFACE_TYPE_LOOPBACK */
#ifdef ECM_INTERFACE_IPSEC_ENABLE
		struct ecm_db_interface_info_ipsec_tunnel ipsec_tunnel;	/* type == ECM_DB_IFACE_TYPE_IPSEC_TUNNEL */
#endif
#ifdef ECM_INTERFACE_SIT_ENABLE
		struct ecm_db_interface_info_sit sit;			/* type == ECM_DB_IFACE_TYPE_SIT (6-in-4) */
#endif
#ifdef ECM_INTERFACE_TUNIPIP6_ENABLE
#ifdef ECM_IPV6_ENABLE
		struct ecm_db_interface_info_tunipip6 tunipip6;		/* type == ECM_DB_IFACE_TYPE_TUNIPIP6 (IPIP v6 Tunnel i.e. TUNNEL6) */
#endif
#endif
	} type_info;

#ifdef ECM_STATE_OUTPUT_ENABLE
	ecm_db_iface_state_get_method_t state_get;	/* Type specific method to return state */
#endif

	ecm_db_iface_final_callback_t final;		/* Callback to owner when object is destroyed */
	void *arg;					/* Argument returned to owner in callbacks */
	uint32_t flags;
	int refs;					/* Integer to trap we never go negative */
	ecm_db_iface_hash_t hash_index;
#if (DEBUG_LEVEL > 0)
	uint16_t magic;
#endif
};

/*
 * Interface flags
 */
#define ECM_DB_IFACE_FLAGS_INSERTED 1			/* Interface is inserted into connection database tables */

/*
 * struct ecm_db_node_instance
 */
struct ecm_db_node_instance {
	struct ecm_db_node_instance *next;		/* Next instance in global list */
	struct ecm_db_node_instance *prev;		/* Previous instance in global list */
	struct ecm_db_node_instance *hash_next;		/* Next node in the chain of nodes */
	struct ecm_db_node_instance *hash_prev;		/* previous node in the chain of nodes */
	uint8_t address[ETH_ALEN];			/* RO: MAC Address of this node */

#ifdef ECM_DB_XREF_ENABLE
	/*
	 * For convenience nodes keep lists of connections that have been established from them and to them.
	 * In fact the same connection could be listed as from & to on the same interface (think: WLAN<>WLAN AP function)
	 * Nodes keep this information for rapid iteration of connections e.g. when a node 'goes down' we
	 * can defunct all associated connections or destroy any accel engine rules.
	 */
	struct ecm_db_connection_instance *from_connections;		/* list of connections made from this node */
	struct ecm_db_connection_instance *to_connections;		/* list of connections made to this node */
	int from_connections_count;					/* Number of connections in the from_connections list */
	int to_connections_count;					/* Number of connections in the to_connections list */

	struct ecm_db_connection_instance *from_nat_connections;	/* list of NAT connections made from this node */
	struct ecm_db_connection_instance *to_nat_connections;		/* list of NAT connections made to this node */
	int from_nat_connections_count;					/* Number of connections in the from_nat_connections list */
	int to_nat_connections_count;					/* Number of connections in the to_nat_connections list */

	/*
	 * Nodes reachable from an interface are stored in a linked list maintained by that interface.
	 * This is so, given an interface, you can examine all nodes reachable from it.
	 */
	struct ecm_db_node_instance *node_next;				/* The next node within the same iface nodes list */
	struct ecm_db_node_instance *node_prev;				/* The previous node within the same iface nodes list */
#endif

	uint32_t time_added;				/* RO: DB time stamp when the node was added into the database */

#ifdef ECM_DB_ADVANCED_STATS_ENABLE
	uint64_t from_data_total;			/* Total of data sent by this node */
	uint64_t to_data_total;				/* Total of data sent to this node */
	uint64_t from_packet_total;			/* Total of packets sent by this node */
	uint64_t to_packet_total;			/* Total of packets sent to this node */
	uint64_t from_data_total_dropped;
	uint64_t to_data_total_dropped;
	uint64_t from_packet_total_dropped;
	uint64_t to_packet_total_dropped;
#endif

	struct ecm_db_iface_instance *iface;		/* The interface to which this node relates */

	ecm_db_node_final_callback_t final;		/* Callback to owner when object is destroyed */
	void *arg;					/* Argument returned to owner in callbacks */
	uint8_t flags;
	int refs;					/* Integer to trap we never go negative */
	ecm_db_node_hash_t hash_index;
#if (DEBUG_LEVEL > 0)
	uint16_t magic;
#endif
};

/*
 * Node flags
 */
#define ECM_DB_NODE_FLAGS_INSERTED 1			/* Node is inserted into connection database tables */

/*
 * struct ecm_db_host_instance
 */
struct ecm_db_host_instance {
	struct ecm_db_host_instance *next;		/* Next instance in global list */
	struct ecm_db_host_instance *prev;		/* Previous instance in global list */
	struct ecm_db_host_instance *hash_next;		/* Next host in the chain of hosts */
	struct ecm_db_host_instance *hash_prev;		/* previous host in the chain of hosts */
	ip_addr_t address;				/* RO: IPv4/v6 Address of this host */
	bool on_link;					/* RO: false when this host is reached via a gateway */
	uint32_t time_added;				/* RO: DB time stamp when the host was added into the database */

#ifdef ECM_DB_XREF_ENABLE
	/*
	 * Normally the mapping refers to the host it requires.
	 * However the host also keeps a list of all mappings that are associated with it.
	 */
	struct ecm_db_mapping_instance *mappings;	/* Mappings made on this host */
	int mapping_count;				/* Number of mappings in the mapping list */
#endif

#ifdef ECM_DB_ADVANCED_STATS_ENABLE
	uint64_t from_data_total;			/* Total of data sent by this host */
	uint64_t to_data_total;				/* Total of data sent to this host */
	uint64_t from_packet_total;			/* Total of packets sent by this host */
	uint64_t to_packet_total;			/* Total of packets sent to this host */
	uint64_t from_data_total_dropped;
	uint64_t to_data_total_dropped;
	uint64_t from_packet_total_dropped;
	uint64_t to_packet_total_dropped;
#endif

	ecm_db_host_final_callback_t final;		/* Callback to owner when object is destroyed */
	void *arg;					/* Argument returned to owner in callbacks */
	uint32_t flags;
	int refs;					/* Integer to trap we never go negative */
	ecm_db_host_hash_t hash_index;
#if (DEBUG_LEVEL > 0)
	uint16_t magic;
#endif
};

/*
 * Host flags
 */
#define ECM_DB_HOST_FLAGS_INSERTED 1			/* Host is inserted into connection database tables */

/*
 * struct ecm_db_mapping_instance
 */
struct ecm_db_mapping_instance {
	struct ecm_db_mapping_instance *next;				/* Next instance in global list */
	struct ecm_db_mapping_instance *prev;				/* Previous instance in global list */

	struct ecm_db_mapping_instance *hash_next;			/* Next mapping in the chain of mappings */
	struct ecm_db_mapping_instance *hash_prev;			/* previous mapping in the chain of mappings */

	uint32_t time_added;						/* RO: DB time stamp when the connection was added into the database */
	struct ecm_db_host_instance *host;				/* The host to which this mapping relates */
	int port;							/* RO: The port number on the host - only applicable for mapping protocols that are port based */

#ifdef ECM_DB_XREF_ENABLE
	/*
	 * For convenience mappings keep lists of connections that have been established from them and to them.
	 * In fact the same connection could be listed as from & to on the same interface (think: WLAN<>WLAN AP function)
	 * Mappings keep this information for rapid iteration of connections e.g. given a mapping we
	 * can defunct all associated connections or destroy any accel engine rules.
	 */
	struct ecm_db_connection_instance *from_connections;		/* list of connections made from this host mapping */
	struct ecm_db_connection_instance *to_connections;		/* list of connections made to this host mapping */

	struct ecm_db_connection_instance *from_nat_connections;	/* list of NAT connections made from this host mapping */
	struct ecm_db_connection_instance *to_nat_connections;		/* list of NAT connections made to this host mapping */

	/*
	 * While a mapping refers to the host it requires.
	 * The host also keeps a list of all mappings that are associated with it, this is that list linkage.
	 */
	struct ecm_db_mapping_instance *mapping_next;			/* Next mapping in the list of mappings for the host */
	struct ecm_db_mapping_instance *mapping_prev;			/* previous mapping in the list of mappings for the host */
#endif

	/*
	 * Connection counts
	 */
	int tcp_from;
	int tcp_to;
	int udp_from;
	int udp_to;
	int tcp_nat_from;
	int tcp_nat_to;
	int udp_nat_from;
	int udp_nat_to;

	/*
	 * Connection counts
	 */
	int from;							/* Number of connections made from */
	int to;								/* Number of connections made to */
	int nat_from;							/* Number of connections made from (nat) */
	int nat_to;							/* Number of connections made to (nat) */

#ifdef ECM_DB_ADVANCED_STATS_ENABLE
	/*
	 * Data totals
	 */
	uint64_t from_data_total;					/* Total of data sent by this mapping */
	uint64_t to_data_total;						/* Total of data sent to this mapping */
	uint64_t from_packet_total;					/* Total of packets sent by this mapping */
	uint64_t to_packet_total;					/* Total of packets sent to this mapping */
	uint64_t from_data_total_dropped;
	uint64_t to_data_total_dropped;
	uint64_t from_packet_total_dropped;
	uint64_t to_packet_total_dropped;
#endif

	ecm_db_mapping_final_callback_t final;				/* Callback to owner when object is destroyed */
	void *arg;							/* Argument returned to owner in callbacks */
	uint32_t flags;
	int refs;							/* Integer to trap we never go negative */
	ecm_db_mapping_hash_t hash_index;
#if (DEBUG_LEVEL > 0)
	uint16_t magic;
#endif
};

/*
 * Mapping flags
 */
#define ECM_DB_MAPPING_FLAGS_INSERTED 1	/* Mapping is inserted into connection database tables */

/*
 * struct ecm_db_timer_group
 *	A timer group - all group members within the same group have the same TTL reset value.
 *
 * Expiry of entries occurs from tail to head.
 */
struct ecm_db_timer_group {
	struct ecm_db_timer_group_entry *head;		/* Most recently used entry in this timer group */
	struct ecm_db_timer_group_entry *tail;		/* Least recently used entry in this timer group. */
	uint32_t time;					/* Time in seconds a group entry will be given to live when 'touched' */
	ecm_db_timer_group_t tg;			/* RO: The group id */
#if (DEBUG_LEVEL > 0)
	uint16_t magic;
#endif
};

/*
 * Timers and cleanup
 */
static uint32_t ecm_db_time = 0;					/* Time in seconds since start */
static struct ecm_db_timer_group ecm_db_timer_groups[ECM_DB_TIMER_GROUPS_MAX];
								/* Timer groups */
static struct timer_list ecm_db_timer;				/* Timer to drive timer groups */

#ifdef ECM_DB_CTA_TRACK_ENABLE
/*
 * Classifier TYPE assignment lists.
 *
 * For each type of classifier a list is kept of all connections assigned a classifier of that type.
 * This permits a classifier type to rapidly retrieve all connections with classifiers assigned to it of that type.
 *
 * NOTE: This is in addition to the basic functionality whereby a connection keeps a list of classifier instances
 * that are assigned to it in descending order of priority.
 */

/*
 * struct ecm_db_connection_classifier_type_assignment
 *	List linkage
 */
struct ecm_db_connection_classifier_type_assignment {
	struct ecm_db_connection_instance *next;	/* Next connection assigned to a classifier of this type */
	struct ecm_db_connection_instance *prev;	/* Previous connection assigned to a classifier of this type */
	int iteration_count;				/* >0 if something is examining this list entry and it may not be unlinked.  The connection will persist. */
	bool pending_unassign;				/* True when the connection has been unassigned from the type, when iteration_count drops to 0 it may be removed from the list */
#if (DEBUG_LEVEL > 0)
	uint16_t magic;
#endif
};

/*
 * struct ecm_db_connection_classifier_type_assignment_list
 *	A list, one for each classifier type.
 */
struct ecm_db_connection_classifier_type_assignment_list {
	struct ecm_db_connection_instance *type_assignments_list;
							/* Lists of connections assigned to this type of classifier */
	int32_t type_assignment_count;			/* Number of connections in the list */
} ecm_db_connection_classifier_type_assignments[ECM_CLASSIFIER_TYPES];
							/* Each classifier type has a list of connections that are assigned to classifier instances of that type */
#endif

/*
 * struct ecm_db_connection_instance
 */
struct ecm_db_connection_instance {
	struct ecm_db_connection_instance *next;		/* Next instance in global list */
	struct ecm_db_connection_instance *prev;		/* Previous instance in global list */

	struct ecm_db_connection_instance *hash_next;		/* Next connection in chain */
	struct ecm_db_connection_instance *hash_prev;		/* Previous connection in chain */
	ecm_db_connection_hash_t hash_index;			/* The hash table slot whose chain of connections this is inserted into */

	struct ecm_db_connection_instance *serial_hash_next;	/* Next connection in serial hash chain */
	struct ecm_db_connection_instance *serial_hash_prev;	/* Previous connection in serial hash chain */
	ecm_db_connection_hash_t serial_hash_index;		/* The hash table slot whose chain of connections this is inserted into */

	uint32_t time_added;					/* RO: DB time stamp when the connection was added into the database */

	int ip_version;						/* RO: The version of IP protocol this connection was established for */
	int protocol;						/* RO: Protocol of the connection */
	ecm_db_direction_t direction;				/* RO: 'Direction' of connection establishment. */
	bool is_routed;						/* RO: True when connection is routed, false when not */

	/*
	 * Connection endpoint mapping
	 */
	struct ecm_db_mapping_instance *mapping_from;		/* The connection was established from this mapping */
	struct ecm_db_mapping_instance *mapping_to;		/* The connection was established to this mapping */

	/*
	 * Connection endpoint mapping for NAT purposes
	 * NOTE: For non-NAT connections these would be identical to the endpoint mappings.
	 */
	struct ecm_db_mapping_instance *mapping_nat_from;	/* The connection was established from this mapping */
	struct ecm_db_mapping_instance *mapping_nat_to;		/* The connection was established to this mapping */

	/*
	 * From / To Node (NAT and non-NAT).
	 * Connections keep references to the nodes upon which they operate.
	 * Gut feeling would tell us this is unusual since it should be the case that
	 * the HOST refer to the node, e.g. IP address to a MAC address.
	 * However there are some 'interesting' usage models where the same IP address may appear
	 * from different nodes / MAC addresses because of this the unique element here is the connection
	 * and so we record the node information directly here.
	 */
	struct ecm_db_node_instance *from_node;			/* Node from which this connection was established */
	struct ecm_db_node_instance *to_node;			/* Node to which this connection was established */
	struct ecm_db_node_instance *from_nat_node;		/* Node from which this connection was established */
	struct ecm_db_node_instance *to_nat_node;		/* Node to which this connection was established */

#ifdef ECM_DB_XREF_ENABLE
	/*
	 * The connection has references to the mappings (both nat and non-nat) as required above.
	 * Also mappings keep lists of connections made to/from them so that they may be iterated
	 * to determine associated connections in each direction/situation (e.g. "defuncting all connections made to/from a mapping").
	 */
	struct ecm_db_connection_instance *from_next;		/* Next connection made from the same mapping */
	struct ecm_db_connection_instance *from_prev;		/* Previous connection made from the same mapping */
	struct ecm_db_connection_instance *to_next;		/* Next connection made to the same mapping */
	struct ecm_db_connection_instance *to_prev;		/* Previous connection made to the same mapping */

	struct ecm_db_connection_instance *from_nat_next;	/* Next connection made from the same mapping */
	struct ecm_db_connection_instance *from_nat_prev;	/* Previous connection made from the same mapping */
	struct ecm_db_connection_instance *to_nat_next;		/* Next connection made to the same mapping */
	struct ecm_db_connection_instance *to_nat_prev;		/* Previous connection made to the same mapping */

	/*
	 * Connection endpoint interface
	 * GGG TODO Deprecated - use interface lists instead.
	 * To be removed when interface heirarchies are implemented to provide the same functionality.
	 */
	struct ecm_db_connection_instance *iface_from_next;	/* Next connection made from the same interface */
	struct ecm_db_connection_instance *iface_from_prev;	/* Previous connection made from the same interface */
	struct ecm_db_connection_instance *iface_to_next;	/* Next connection made to the same interface */
	struct ecm_db_connection_instance *iface_to_prev;	/* Previous connection made to the same interface */

	/*
	 * Connection endpoint interface for NAT purposes
	 * NOTE: For non-NAT connections these would be identical to the endpoint interface.
	 * GGG TODO Deprecated - use interface lists instead.
	 * To be removed when interface heirarchies are implemented to provide the same functionality.
	 */
	struct ecm_db_connection_instance *iface_from_nat_next;	/* Next connection made from the same interface */
	struct ecm_db_connection_instance *iface_from_nat_prev;	/* Previous connection made from the same interface */
	struct ecm_db_connection_instance *iface_to_nat_next;	/* Next connection made to the same interface */
	struct ecm_db_connection_instance *iface_to_nat_prev;	/* Previous connection made to the same interface */

	/*
	 * As well as keeping a reference to the node which this connection uses the nodes
	 * also keep lists of connections made from/to them.
	 */
	struct ecm_db_connection_instance *node_from_next;	/* Next connection in the nodes from_connections list */
	struct ecm_db_connection_instance *node_from_prev;	/* Prev connection in the nodes from_connections list */
	struct ecm_db_connection_instance *node_to_next;	/* Next connection in the nodes to_connections list */
	struct ecm_db_connection_instance *node_to_prev;	/* Prev connection in the nodes to_connections list */

	struct ecm_db_connection_instance *node_from_nat_next;	/* Next connection in the nodes from_nat_connections list */
	struct ecm_db_connection_instance *node_from_nat_prev;	/* Prev connection in the nodes from_nat_connections list */
	struct ecm_db_connection_instance *node_to_nat_next;	/* Next connection in the nodes to_nat_connections list */
	struct ecm_db_connection_instance *node_to_nat_prev;	/* Prev connection in the nodes to_nat_connections list */
#endif

	/*
	 * From / To interfaces list
	 */
	struct ecm_db_iface_instance *from_interfaces[ECM_DB_IFACE_HEIRARCHY_MAX];
								/* The outermost to innnermost interface this connection is using in the from path.
								 * Relationships are recorded from [ECM_DB_IFACE_HEIRARCHY_MAX - 1] to [0]
								 */
	int32_t from_interface_first;				/* The index of the first interface in the list */
	bool from_interface_set;				/* True when a list has been set - even if there is NO list, it's still deliberately set that way. */
	struct ecm_db_iface_instance *to_interfaces[ECM_DB_IFACE_HEIRARCHY_MAX];
								/* The outermost to innnermost interface this connection is using in the to path */
	int32_t to_interface_first;				/* The index of the first interface in the list */
	bool to_interface_set;					/* True when a list has been set - even if there is NO list, it's still deliberately set that way. */

	/*
	 * From / To NAT interfaces list
	 * GGG TODO Not sure if NAT interface lists are necessary or appropriate or practical.
	 * Needs to be assessed if it gives any clear benefit and possibly remove these if not.
	 */
	struct ecm_db_iface_instance *from_nat_interfaces[ECM_DB_IFACE_HEIRARCHY_MAX];
								/* The outermost to innnermost interface this connection is using in the from path.
								 * Relationships are recorded from [ECM_DB_IFACE_HEIRARCHY_MAX - 1] to [0]
								 */
	int32_t from_nat_interface_first;			/* The index of the first interface in the list */
	bool from_nat_interface_set;				/* True when a list has been set - even if there is NO list, it's still deliberately set that way. */
	struct ecm_db_iface_instance *to_nat_interfaces[ECM_DB_IFACE_HEIRARCHY_MAX];
								/* The outermost to innnermost interface this connection is using in the to path */
	int32_t to_nat_interface_first;				/* The index of the first interface in the list */
	bool to_nat_interface_set;				/* True when a list has been set - even if there is NO list, it's still deliberately set that way. */

#ifdef ECM_MULTICAST_ENABLE
	/*
	 * Destination Multicast interfaces list
	 */
	struct ecm_db_iface_instance *to_mcast_interfaces;
								/* The outermost to innnermost interfaces this connection is using in multicast path.
								 * The size of the buffer allocated for the to_mcast_interfaces heirarchies is as large as
								 * sizeof(struct ecm_db_iface_instance *) * ECM_DB_MULTICAST_IF_MAX * ECM_DB_IFACE_HEIRARCHY_MAX. */
	int32_t to_mcast_interface_first[ECM_DB_MULTICAST_IF_MAX];
								/* The indexes of the first interfaces in the destinaiton interface list */
	struct ecm_db_multicast_tuple_instance *ti; 		/* Multicast Connection instance */
	bool to_mcast_interfaces_set;				/* Flag to indicate if the destination interface list is currently empty or not */
#endif
	/*
	 * Time values in seconds
	 */
	struct ecm_db_timer_group_entry defunct_timer;		/* Used to defunct the connection on inactivity */

	/*
	 * Byte and packet counts
	 */
	uint64_t from_data_total;				/* Totals of data as sent by the 'from' side of this connection */
	uint64_t to_data_total;					/* Totals of data as sent by the 'to' side of this connection */
	uint64_t from_packet_total;				/* Totals of packets as sent by the 'from' side of this connection */
	uint64_t to_packet_total;				/* Totals of packets as sent by the 'to' side of this connection */
	uint64_t from_data_total_dropped;			/* Total data sent by the 'from' side that we purposely dropped - the 'to' side has not seen this data */
	uint64_t to_data_total_dropped;				/* Total data sent by the 'to' side that we purposely dropped - the 'from' side has not seen this data */
	uint64_t from_packet_total_dropped;			/* Total packets sent by the 'from' side that we purposely dropped - the 'to' side has not seen this data */
	uint64_t to_packet_total_dropped;			/* Total packets sent by the 'to' side that we purposely dropped - the 'from' side has not seen this data */

	/*
	 * Classifiers attached to this connection
	 */
	struct ecm_classifier_instance *assignments;		/* A list of all classifiers that are still assigned to this connection.
								 * When a connection is created, one instance of every type of classifier is assigned to the connection.
								 * Classifiers are added in ascending order of priority - so the most important processes a packet last.
								 * Classifiers may drop out of this list (become unassigned) at any time.
								 */
	struct ecm_classifier_instance *assignments_by_type[ECM_CLASSIFIER_TYPES];
								/* All assignments are also recorded in this array, since there can be only one of each type, this array allows
								 * rapid retrieval of a classifier type, saving having to iterate the assignments list.
								 */

#ifdef ECM_DB_CTA_TRACK_ENABLE
	struct ecm_db_connection_classifier_type_assignment type_assignment[ECM_CLASSIFIER_TYPES];
								/*
								 * Each classifier TYPE has a list of connections that are assigned to it.
								 * This permits a classifier TYPE to rapidly retrieve all connections associated with it.
								 */
#endif

	/*
	 * Re-generation.
	 * When system or classifier state changes, affected connections may need to have their state re-generated.
	 * This ensures that a connection does not continue to operate on stale state which could affect the sanity of acceleration rules.
	 * A connection needs to be re-generated when its regen_required is > 0.
	 * When a re-generation is completed successfully the counter is decremented.
	 * The counter ensures that any further changes of state while re-generation is under way is not missed.
	 * While a connection needs re-generation (regen_required > 0), acceleration should not be permitted.
	 * It may not always be practical to flag individual connections for re-generation (time consuming with large numbers of connections).
	 * The "generation" is a numerical counter comparison against the global "ecm_db_connection_generation".
	 * This ecm_db_connection_generation can be incremented causing a numerical difference between the connections counter and this global.
	 * This is enough to flag that a re-generation is needed.
	 * Further, it is possible that re-generation may be required DURING a rule construction.  Since constructing a rule
	 * can require lengthy non-atomic processes there needs to be a way to ensure that changes during construction of a rule are caught.
	 * The regen_occurances is a counter that is incremented whenever regen_required is also incremented.
	 * However it is never decremented.  This permits the caller to obtain this count before a non-atomic procedure and then afterwards.
	 * If there is any change in the counter value there is a change of generation!  And the operation should be aborted.
	 */
	bool regen_in_progress;					/* The connection is under regeneration right now and is used to provide atomic re-generation in SMP */
	uint16_t regen_required;				/* The connection needs to be re-generated when > 0 */
	uint16_t regen_occurances;				/* Total number of regens required */
	uint16_t generation;					/* Used to detect when a re-evaluation of this connection is necessary by comparing with ecm_db_connection_generation */
	uint32_t regen_success;					/* Tracks how many times re-generation was successfully completed */
	uint32_t regen_fail;					/* Tracks how many times re-generation failed */

	struct ecm_front_end_connection_instance *feci;		/* Front end instance specific to this connection */

	ecm_db_connection_defunct_callback_t defunct;		/* Callback to be called when connection has become defunct */
	ecm_db_connection_final_callback_t final;		/* Callback to owner when object is destroyed */
	void *arg;						/* Argument returned to owner in callbacks */

	uint32_t serial;					/* RO: Serial number for the connection - unique for run lifetime */
	uint32_t flags;
	int refs;						/* Integer to trap we never go negative */
#if (DEBUG_LEVEL > 0)
	uint16_t magic;
#endif
};

/*
 * Connection flags
 */
#define ECM_DB_CONNECTION_FLAGS_INSERTED 1			/* Connection is inserted into connection database tables */

/*
 * struct ecm_db_listener_instance
 *	listener instances
 */
struct ecm_db_listener_instance {
	struct ecm_db_listener_instance *next;
	struct ecm_db_listener_instance *event_next;
	uint32_t flags;
	void *arg;
	int refs;							/* Integer to trap we never go negative */
	ecm_db_mapping_final_callback_t final;				/* Final callback for this instance */

	ecm_db_iface_listener_added_callback_t iface_added;
	ecm_db_iface_listener_removed_callback_t iface_removed;
	ecm_db_node_listener_added_callback_t node_added;
	ecm_db_node_listener_removed_callback_t node_removed;
	ecm_db_host_listener_added_callback_t host_added;
	ecm_db_host_listener_removed_callback_t host_removed;
	ecm_db_mapping_listener_added_callback_t mapping_added;
	ecm_db_mapping_listener_removed_callback_t mapping_removed;
	ecm_db_connection_listener_added_callback_t connection_added;
	ecm_db_connection_listener_removed_callback_t connection_removed;
#if (DEBUG_LEVEL > 0)
	uint16_t magic;
#endif
};

/*
 * Listener flags
 */
#define ECM_DB_LISTENER_FLAGS_INSERTED 1			/* Is inserted into database */

#ifdef ECM_MULTICAST_ENABLE
/*
 * struct ecm_db_multicast_tuple_instance
 * 	Tuple information for an accelerated multicast connection.
 * 	This tuple information is further used to find an attached
 * 	connection for the multicast flow.
 */
struct ecm_db_multicast_tuple_instance {
	struct ecm_db_multicast_tuple_instance *next;	/* Next instance in global list */
	struct ecm_db_multicast_tuple_instance *prev;	/* Previous instance in global list */
	struct ecm_db_connection_instance *ci;	/* Pointer to the DB Connection Instance */
	uint16_t src_port;	/* RO: IPv4/v6 Source Port */
	uint16_t dst_port;	/* RO: IPv4/v6 Destination Port */
	ip_addr_t src_ip;	/* RO: IPv4/v6 Source Address */
	ip_addr_t grp_ip;	/* RO: IPv4/v6 Multicast Group Address */
	uint32_t flags;		/* Flags for this instance node */
	uint32_t hash_index;	/* Hash index of this node */
	int proto;		/* RO: Protocol */
	int refs;		/* Integer to trap we never go negative */
#if (DEBUG_LEVEL > 0)
	uint16_t magic;		/* Magic value for debug */
#endif
};

#define ECM_DB_MULTICAST_TUPLE_INSTANCE_HASH_SLOTS 16
typedef uint32_t ecm_db_multicast_tuple_instance_hash_t;

/*
 * Multicast connection tuple table
 * 	This table is used to lookup a complete tuple for multicast connections
 * 	using the multicast group address
 */
static struct ecm_db_multicast_tuple_instance *ecm_db_multicast_tuple_instance_table[ECM_DB_MULTICAST_TUPLE_INSTANCE_HASH_SLOTS];
#endif

/*
 * Simple stats
 */
#define ECM_DB_PROTOCOL_COUNT 256
static int ecm_db_connection_count_by_protocol[ECM_DB_PROTOCOL_COUNT];	/* Each IP protocol has its own count */

/*
 * Locking of the database - concurrency control
 */
static DEFINE_SPINLOCK(ecm_db_lock);					/* Protect the table from SMP access. */

/*
 * Connection state validity
 * This counter is incremented whenever a general change is detected which requires re-generation of state for ALL connections.
 */
static uint16_t ecm_db_connection_generation = 0;		/* Generation counter to detect when all connection state is considered stale and all must be re-generated */

/*
 * Debugfs dentry object.
 */
static struct dentry *ecm_db_dentry;

/*
 * Management thread control
 */
static bool ecm_db_terminate_pending = false;			/* When true the user has requested termination */

/*
 * ecm_db_interface_type_names[]
 *	Array that maps the interface type to a string
 */
static char *ecm_db_interface_type_names[ECM_DB_IFACE_TYPE_COUNT] = {
	"ETHERNET",
	"PPPoE",
	"LINK-AGGREGATION",
	"VLAN",
	"BRIDGE",
	"LOOPBACK",
	"IPSEC_TUNNEL",
	"UNKNOWN",
	"SIT",
	"TUNIPIP6",
	"PPPoL2TPV2",
	"PPTP"
};

/*
 * Random seed used during hash calculations
 */
static uint32_t ecm_db_jhash_rnd __read_mostly;

/*
 * Max work count for IPv6 route change event handler.
 */
#define ECM_DB_IP6ROUTE_MAX_WORK_COUNT	16

/*
 * IPv6 rount change event work counter.
 */
static atomic_t ecm_db_ip6route_work_count;

/*
 * ecm_db_connection_count_get()
 *	Return the connection count
 */
int ecm_db_connection_count_get(void)
{
	int count;

	spin_lock_bh(&ecm_db_lock);
	count = ecm_db_connection_count;
	spin_unlock_bh(&ecm_db_lock);
	return count;
}
EXPORT_SYMBOL(ecm_db_connection_count_get);

/*
 * ecm_db_interface_type_to_string()
 *	Return a string buffer containing the type name of the interface
 */
char *ecm_db_interface_type_to_string(ecm_db_iface_type_t type)
{
	DEBUG_ASSERT((type >= 0) && (type < ECM_DB_IFACE_TYPE_COUNT), "Invalid type: %d\n", type);
	return ecm_db_interface_type_names[(int)type];
}
EXPORT_SYMBOL(ecm_db_interface_type_to_string);

/*
 * ecm_db_connection_count_by_protocol_get()
 *	Return # connections for the given protocol
 */
int ecm_db_connection_count_by_protocol_get(int protocol)
{
	int count;

	DEBUG_ASSERT((protocol >= 0) && (protocol < ECM_DB_PROTOCOL_COUNT), "Bad protocol: %d\n", protocol);
	spin_lock_bh(&ecm_db_lock);
	count = ecm_db_connection_count_by_protocol[protocol];
	spin_unlock_bh(&ecm_db_lock);
	return count;
}
EXPORT_SYMBOL(ecm_db_connection_count_by_protocol_get);

/*
 * ecm_db_iface_ae_interface_identifier_get()
 *	Return the accel engine interface number of this ecm interface
 */
int32_t ecm_db_iface_ae_interface_identifier_get(struct ecm_db_iface_instance *ii)
{
	DEBUG_CHECK_MAGIC(ii, ECM_DB_IFACE_INSTANCE_MAGIC, "%p: magic failed", ii);
	return ii->ae_interface_identifier;
}
EXPORT_SYMBOL(ecm_db_iface_ae_interface_identifier_get);

/*
 * ecm_db_iface_ae_interface_identifier_set()
 *	Sets accel engine  interface number of this ecm interface
 */
void ecm_db_iface_ae_interface_identifier_set(struct ecm_db_iface_instance *ii, uint32_t num)
{
	DEBUG_CHECK_MAGIC(ii, ECM_DB_IFACE_INSTANCE_MAGIC, "%p: magic failed", ii);
	ii->ae_interface_identifier = num;
}
EXPORT_SYMBOL(ecm_db_iface_ae_interface_identifier_set);

/*
 * ecm_db_iface_interface_identifier_get()
 *	Return the interface number of this ecm interface
 */
int32_t ecm_db_iface_interface_identifier_get(struct ecm_db_iface_instance *ii)
{
	DEBUG_CHECK_MAGIC(ii, ECM_DB_IFACE_INSTANCE_MAGIC, "%p: magic failed", ii);
	return ii->interface_identifier;
}
EXPORT_SYMBOL(ecm_db_iface_interface_identifier_get);

/*
 * ecm_db_iface_interface_name_get()
 *	Return the interface name of this ecm interface
 *
 * name_buffer should be at least of size IFNAMSIZ
 */
void ecm_db_iface_interface_name_get(struct ecm_db_iface_instance *ii, char *name_buffer)
{
	DEBUG_CHECK_MAGIC(ii,
		ECM_DB_IFACE_INSTANCE_MAGIC, "%p: magic failed", ii);
	strlcpy(name_buffer, ii->name, IFNAMSIZ);
}
EXPORT_SYMBOL(ecm_db_iface_interface_name_get);

/*
 * ecm_db_iface_mtu_reset()
 *	Reset the mtu
 */
int32_t ecm_db_iface_mtu_reset(struct ecm_db_iface_instance *ii, int32_t mtu)
{
	int32_t mtu_old;
	DEBUG_CHECK_MAGIC(ii, ECM_DB_IFACE_INSTANCE_MAGIC, "%p: magic failed", ii);
	spin_lock_bh(&ecm_db_lock);
	mtu_old = ii->mtu;
	ii->mtu = mtu;
	spin_unlock_bh(&ecm_db_lock);
	DEBUG_INFO("%p: Mtu change from %d to %d\n", ii, mtu_old, mtu);

	return mtu_old;
}
EXPORT_SYMBOL(ecm_db_iface_mtu_reset);

/*
 * ecm_db_connection_front_end_get_and_ref()
 *	Return ref to the front end instance of the connection
 */
struct ecm_front_end_connection_instance *ecm_db_connection_front_end_get_and_ref(struct ecm_db_connection_instance *ci)
{
	DEBUG_CHECK_MAGIC(ci, ECM_DB_CONNECTION_INSTANCE_MAGIC, "%p: magic failed", ci);
	ci->feci->ref(ci->feci);
	return ci->feci;
}
EXPORT_SYMBOL(ecm_db_connection_front_end_get_and_ref);

/*
 * ecm_db_connection_defunct_callback()
 *	Invoked by the expiration of the defunct_timer contained in a connection instance
 */
static void ecm_db_connection_defunct_callback(void *arg)
{
	struct ecm_front_end_connection_instance *feci;
	ecm_front_end_acceleration_mode_t accel_mode;
	struct ecm_db_connection_instance *ci = (struct ecm_db_connection_instance *)arg;
	DEBUG_CHECK_MAGIC(ci, ECM_DB_CONNECTION_INSTANCE_MAGIC, "%p: magic failed", ci);

	DEBUG_INFO("%p: defunct timer expired\n", ci);

	if (ci->defunct) {
		ci->defunct(ci->feci);
	}

	feci = ecm_db_connection_front_end_get_and_ref(ci);
	accel_mode = feci->accel_state_get(feci);
	feci->deref(feci);

	/*
	 * It is possible that the defunct process fails and re-try is in progress.
	 * In that case we set the accel mode of the connection to
	 * ECM_FRONT_END_ACCELERATION_MODE_ACCEL so that in the next destroy try the connection
	 * status would be correct. So, if the accel_mode is ECM_FRONT_END_ACCELERATION_MODE_ACCEL,
	 * we shouldn't release the last reference count.
	 */
	if (accel_mode != ECM_FRONT_END_ACCELERATION_MODE_ACCEL) {
		ecm_db_connection_deref(ci);
	}
}

/*
 * ecm_db_connection_elapsed_defunct_timer()
 *	Returns the elapsed time of defunct timer.
 * If the timer is already expired and not removed from the database, the
 * function returns a negative value. The caller MUST handle this return value.
 */
int ecm_db_connection_elapsed_defunct_timer(struct ecm_db_connection_instance *ci)
{
	long int expires_in;
	int elapsed;

	DEBUG_CHECK_MAGIC(ci, ECM_DB_CONNECTION_INSTANCE_MAGIC, "%p: magic failed", ci);

	/*
	 * Do some sanity checks.
	 * If it is not in a timer group, which means already expired, or the
	 * connection has not been fully created yet. Just return 0.
	 */
	spin_lock_bh(&ecm_db_lock);
	if (ci->defunct_timer.group == ECM_DB_TIMER_GROUPS_MAX) {
		spin_unlock_bh(&ecm_db_lock);
		return -1;
	}

	/*
	 * Already expired, but not removed from the database completely.
	 */
	expires_in = (long int)(ci->defunct_timer.timeout - ecm_db_time);
	if (expires_in < 0) {
		spin_unlock_bh(&ecm_db_lock);
		return -1;
	}

	elapsed = ecm_db_timer_groups[ci->defunct_timer.group].time - expires_in;
	spin_unlock_bh(&ecm_db_lock);

	return elapsed;
}
EXPORT_SYMBOL(ecm_db_connection_elapsed_defunct_timer);

/*
 * ecm_db_connection_defunct_timer_reset()
 *	Set/change the timer group associated with a connection.  Returns false if the connection has become defunct and the new group cannot be set for that reason.
 */
bool ecm_db_connection_defunct_timer_reset(struct ecm_db_connection_instance *ci, ecm_db_timer_group_t tg)
{
	DEBUG_CHECK_MAGIC(ci, ECM_DB_CONNECTION_INSTANCE_MAGIC, "%p: magic failed", ci);
	return ecm_db_timer_group_entry_reset(&ci->defunct_timer, tg);
}
EXPORT_SYMBOL(ecm_db_connection_defunct_timer_reset);

/*
 * ecm_db_connection_defunct_timer_touch()
 *	Update the connections defunct timer to stop it timing out.  Returns false if the connection defunct timer has expired.
 */
bool ecm_db_connection_defunct_timer_touch(struct ecm_db_connection_instance *ci)
{
	DEBUG_CHECK_MAGIC(ci, ECM_DB_CONNECTION_INSTANCE_MAGIC, "%p: magic failed", ci);
	return ecm_db_timer_group_entry_touch(&ci->defunct_timer);
}
EXPORT_SYMBOL(ecm_db_connection_defunct_timer_touch);

/*
 * ecm_db_connection_timer_group_get()
 *	Return the timer group id
 */
ecm_db_timer_group_t ecm_db_connection_timer_group_get(struct ecm_db_connection_instance *ci)
{
	ecm_db_timer_group_t tg;
	DEBUG_CHECK_MAGIC(ci, ECM_DB_CONNECTION_INSTANCE_MAGIC, "%p: magic failed", ci);

	spin_lock_bh(&ecm_db_lock);
	tg = ci->defunct_timer.group;
	spin_unlock_bh(&ecm_db_lock);
	return tg;
}
EXPORT_SYMBOL(ecm_db_connection_timer_group_get);

/*
 * ecm_db_connection_make_defunct()
 *	Make connection defunct.
 */
void ecm_db_connection_make_defunct(struct ecm_db_connection_instance *ci)
{
	struct ecm_front_end_connection_instance *feci;
	ecm_front_end_acceleration_mode_t accel_mode;

	DEBUG_CHECK_MAGIC(ci, ECM_DB_CONNECTION_INSTANCE_MAGIC, "%p: magic failed", ci);

	if (ci->defunct) {
		ci->defunct(ci->feci);
	}

	feci = ecm_db_connection_front_end_get_and_ref(ci);
	accel_mode = feci->accel_state_get(feci);
	feci->deref(feci);

	/*
	 * It is possible that the defunct process fails and re-try is in progress.
	 * In that case, the connection's defunct timer is reset to defunct re-try
	 * timeout value and the connection waits for the next defunct call. So, we
	 * should remove the timer from the timer group, if the re-acceleration for this
	 * connection is not possible which means "decel pending" or one of the
	 * "accel fail" modes. Otherwise, the timer will be removed and re-try will not happen.
	 */
	if (ECM_FRONT_END_ACCELERATION_NOT_POSSIBLE(accel_mode)) {
		if (ecm_db_timer_group_entry_remove(&ci->defunct_timer)) {
			ecm_db_connection_deref(ci);
		}
	}
}
EXPORT_SYMBOL(ecm_db_connection_make_defunct);

/*
 * ecm_db_connection_data_totals_update()
 *	Update the total data (and packets) sent/received by the given host
 */
void ecm_db_connection_data_totals_update(struct ecm_db_connection_instance *ci, bool is_from, uint64_t size, uint64_t packets)
{
	int32_t i;

	DEBUG_CHECK_MAGIC(ci, ECM_DB_CONNECTION_INSTANCE_MAGIC, "%p: magic failed\n", ci);

	spin_lock_bh(&ecm_db_lock);

	if (is_from) {
		/*
		 * Update totals sent by the FROM side of connection
		 */
		ci->from_data_total += size;
		ci->from_packet_total += packets;
#ifdef ECM_DB_ADVANCED_STATS_ENABLE
		ci->mapping_from->from_data_total += size;
		ci->mapping_from->host->from_data_total += size;
		ci->from_node->from_data_total += size;
		ci->mapping_from->from_packet_total += packets;
		ci->mapping_from->host->from_packet_total += packets;
		ci->from_node->from_packet_total += packets;

		/*
		 * Data from the host is essentially TO the interface on which the host is reachable
		 */
		for (i = ci->from_interface_first; i < ECM_DB_IFACE_HEIRARCHY_MAX; ++i) {
			ci->from_interfaces[i]->to_data_total += size;
			ci->from_interfaces[i]->to_packet_total += packets;
		}

		/*
		 * Update totals sent TO the other side of the connection
		 */
		ci->mapping_to->to_data_total += size;
		ci->mapping_to->host->to_data_total += size;
		ci->to_node->to_data_total += size;
		ci->mapping_to->to_packet_total += packets;
		ci->mapping_to->host->to_packet_total += packets;
		ci->to_node->to_packet_total += packets;

		/*
		 * Sending to the other side means FROM the interface we reach that host
		 */
		for (i = ci->to_interface_first; i < ECM_DB_IFACE_HEIRARCHY_MAX; ++i) {
			ci->to_interfaces[i]->from_data_total += size;
			ci->to_interfaces[i]->from_packet_total += packets;
		}
#endif
		spin_unlock_bh(&ecm_db_lock);
		return;
	}

	/*
	 * Update totals sent by the TO side of this connection
	 */
	ci->to_data_total += size;
	ci->to_packet_total += packets;
#ifdef ECM_DB_ADVANCED_STATS_ENABLE
	ci->mapping_to->from_data_total += size;
	ci->mapping_to->host->from_data_total += size;
	ci->to_node->from_data_total += size;
	ci->mapping_to->from_packet_total += packets;
	ci->mapping_to->host->from_packet_total += packets;
	ci->to_node->from_packet_total += packets;

	/*
	 * Data from the host is essentially TO the interface on which the host is reachable
	 */
	for (i = ci->to_interface_first; i < ECM_DB_IFACE_HEIRARCHY_MAX; ++i) {
		ci->to_interfaces[i]->to_data_total += size;
		ci->to_interfaces[i]->to_packet_total += packets;
	}

	/*
	 * Update totals sent TO the other side of the connection
	 */
	ci->mapping_from->to_data_total += size;
	ci->mapping_from->host->to_data_total += size;
	ci->from_node->to_data_total += size;
	ci->mapping_from->to_packet_total += packets;
	ci->mapping_from->host->to_packet_total += packets;
	ci->from_node->to_packet_total += packets;

	/*
	 * Sending to the other side means FROM the interface we reach that host
	 */
	for (i = ci->from_interface_first; i < ECM_DB_IFACE_HEIRARCHY_MAX; ++i) {
		ci->from_interfaces[i]->from_data_total += size;
		ci->from_interfaces[i]->from_packet_total += packets;
	}
#endif
	spin_unlock_bh(&ecm_db_lock);
}
EXPORT_SYMBOL(ecm_db_connection_data_totals_update);

#ifdef ECM_MULTICAST_ENABLE
/*
 * ecm_db_multicast_connection_data_totals_update()
 *	Update the total bytes and packets sent/received by the multicast connection
 *	TODO: This function is almost similar to unicast connection_data_totals_update() except few
 *	      lines of code. The next merge should have a common logic for both unicast and multicast.
 */
void ecm_db_multicast_connection_data_totals_update(struct ecm_db_connection_instance *ci, bool is_from, uint64_t size, uint64_t packets)
{
	int32_t i;

	DEBUG_CHECK_MAGIC(ci, ECM_DB_CONNECTION_INSTANCE_MAGIC, "%p: magic failed\n", ci);

	spin_lock_bh(&ecm_db_lock);

	if (is_from) {
		/*
		 * Update totals sent by the FROM side of connection
		 */
		ci->from_data_total += size;
		ci->from_packet_total += packets;
#ifdef ECM_DB_ADVANCED_STATS_ENABLE
		ci->mapping_from->from_data_total += size;
		ci->mapping_from->host->from_data_total += size;
		ci->from_node->from_data_total += size;
		ci->mapping_from->from_packet_total += packets;
		ci->mapping_from->host->from_packet_total += packets;
		ci->from_node->from_packet_total += packets;

		/*
		 * Data from the host is essentially TO the interface on which the host is reachable
		 */
		for (i = ci->from_interface_first; i < ECM_DB_IFACE_HEIRARCHY_MAX; ++i) {
			ci->from_interfaces[i]->to_data_total += size;
			ci->from_interfaces[i]->to_packet_total += packets;
		}

		/*
		 * Update totals sent TO the other side of the connection
		 */
		ci->mapping_to->to_data_total += size;
		ci->mapping_to->host->to_data_total += size;
		ci->to_node->to_data_total += size;
		ci->mapping_to->to_packet_total += packets;
		ci->mapping_to->host->to_packet_total += packets;
		ci->to_node->to_packet_total += packets;
#endif
		spin_unlock_bh(&ecm_db_lock);
		return;
	}

	/*
	 * Update totals sent by the TO side of this connection
	 */
	ci->to_data_total += size;
	ci->to_packet_total += packets;
#ifdef ECM_DB_ADVANCED_STATS_ENABLE
	ci->mapping_to->from_data_total += size;
	ci->mapping_to->host->from_data_total += size;
	ci->to_node->from_data_total += size;
	ci->mapping_to->from_packet_total += packets;
	ci->mapping_to->host->from_packet_total += packets;
	ci->to_node->from_packet_total += packets;

	/*
	 * Update totals sent TO the other side of the connection
	 */
	ci->mapping_from->to_data_total += size;
	ci->mapping_from->host->to_data_total += size;
	ci->from_node->to_data_total += size;
	ci->mapping_from->to_packet_total += packets;
	ci->mapping_from->host->to_packet_total += packets;
	ci->from_node->to_packet_total += packets;

	/*
	 * Sending to the other side means FROM the interface we reach that host
	 */
	for (i = ci->from_interface_first; i < ECM_DB_IFACE_HEIRARCHY_MAX; ++i) {
		ci->from_interfaces[i]->from_data_total += size;
		ci->from_interfaces[i]->from_packet_total += packets;
	}
#endif
	spin_unlock_bh(&ecm_db_lock);
}
EXPORT_SYMBOL(ecm_db_multicast_connection_data_totals_update);

/*
 * ecm_db_multicast_connection_interface_heirarchy_stats_update()
 * 	Traverse through the multicast destination interface heirarchy and update the stats (data and packets).
 */
void ecm_db_multicast_connection_interface_heirarchy_stats_update(struct ecm_db_connection_instance *ci, uint64_t size, uint64_t packets)
{
	struct ecm_db_iface_instance *to_mc_ifaces;
	struct ecm_db_iface_instance *ii;
	struct ecm_db_iface_instance **ifaces;
	struct ecm_db_iface_instance *ii_temp;
	int32_t *to_mc_ifaces_first;
	int heirarchy_index;
	int ret;

	ret = ecm_db_multicast_connection_to_interfaces_get_and_ref_all(ci, &to_mc_ifaces, &to_mc_ifaces_first);
	if (ret == 0) {
		DEBUG_WARN("%p: no interfaces in to_multicast_interfaces list!\n", ci);
		return;
	}

	spin_lock_bh(&ecm_db_lock);
	for (heirarchy_index = 0; heirarchy_index < ECM_DB_MULTICAST_IF_MAX; heirarchy_index++) {

		if (to_mc_ifaces_first[heirarchy_index] < ECM_DB_IFACE_HEIRARCHY_MAX) {
			ii_temp = ecm_db_multicast_if_heirarchy_get(to_mc_ifaces, heirarchy_index);
			ii_temp = ecm_db_multicast_if_instance_get_at_index(ii_temp, ECM_DB_IFACE_HEIRARCHY_MAX - 1);
			ifaces = (struct ecm_db_iface_instance **)ii_temp;
			ii = *ifaces;
			ii->to_data_total += size;
			ii->to_packet_total += packets;
		}
	}
	spin_unlock_bh(&ecm_db_lock);

	ecm_db_multicast_connection_to_interfaces_deref_all(to_mc_ifaces, to_mc_ifaces_first);
}
EXPORT_SYMBOL(ecm_db_multicast_connection_interface_heirarchy_stats_update);
#endif

/*
 * ecm_db_connection_data_totals_update_dropped()
 *	Update the total data (and packets) sent by the given host but which we dropped
 */
void ecm_db_connection_data_totals_update_dropped(struct ecm_db_connection_instance *ci, bool is_from, uint64_t size, uint64_t packets)
{
	int32_t i;

	DEBUG_CHECK_MAGIC(ci, ECM_DB_CONNECTION_INSTANCE_MAGIC, "%p: magic failed\n", ci);

	if (is_from) {
		/*
		 * Update dropped totals sent by the FROM side
		 */
		spin_lock_bh(&ecm_db_lock);
		ci->from_data_total_dropped += size;
		ci->from_packet_total_dropped += packets;
#ifdef ECM_DB_ADVANCED_STATS_ENABLE
		ci->mapping_from->from_data_total_dropped += size;
		ci->mapping_from->host->from_data_total_dropped += size;
		ci->from_node->from_data_total_dropped += size;
		ci->mapping_from->from_packet_total_dropped += packets;
		ci->mapping_from->host->from_packet_total_dropped += packets;
		ci->from_node->from_packet_total_dropped += packets;

		/*
		 * Data from the host is essentially TO the interface on which the host is reachable
		 */
		for (i = ci->from_interface_first; i < ECM_DB_IFACE_HEIRARCHY_MAX; ++i) {
			ci->from_interfaces[i]->to_data_total_dropped += size;
			ci->from_interfaces[i]->to_packet_total_dropped += packets;
		}
#endif
		spin_unlock_bh(&ecm_db_lock);
		return;
	}

	/*
	 * Update dropped totals sent by the TO side of this connection
	 */
	spin_lock_bh(&ecm_db_lock);
	ci->to_data_total_dropped += size;
	ci->to_packet_total_dropped += packets;
#ifdef ECM_DB_ADVANCED_STATS_ENABLE
	ci->mapping_to->from_data_total_dropped += size;
	ci->mapping_to->host->from_data_total_dropped += size;
	ci->to_node->from_data_total_dropped += size;
	ci->mapping_to->from_packet_total_dropped += packets;
	ci->mapping_to->host->from_packet_total_dropped += packets;
	ci->to_node->from_packet_total_dropped += packets;

	/*
	 * Data from the host is essentially TO the interface on which the host is reachable
	 */
	for (i = ci->to_interface_first; i < ECM_DB_IFACE_HEIRARCHY_MAX; ++i) {
		ci->to_interfaces[i]->to_data_total_dropped += size;
		ci->to_interfaces[i]->to_packet_total_dropped += packets;
	}
#endif
	spin_unlock_bh(&ecm_db_lock);
}
EXPORT_SYMBOL(ecm_db_connection_data_totals_update_dropped);

/*
 * ecm_db_connection_data_stats_get()
 *	Return data stats for the instance
 */
void ecm_db_connection_data_stats_get(struct ecm_db_connection_instance *ci, uint64_t *from_data_total, uint64_t *to_data_total,
						uint64_t *from_packet_total, uint64_t *to_packet_total,
						uint64_t *from_data_total_dropped, uint64_t *to_data_total_dropped,
						uint64_t *from_packet_total_dropped, uint64_t *to_packet_total_dropped)
{
	DEBUG_CHECK_MAGIC(ci, ECM_DB_CONNECTION_INSTANCE_MAGIC, "%p: magic failed", ci);

	spin_lock_bh(&ecm_db_lock);
	if (from_data_total) {
		*from_data_total = ci->from_data_total;
	}
	if (to_data_total) {
		*to_data_total = ci->to_data_total;
	}
	if (from_packet_total) {
		*from_packet_total = ci->from_packet_total;
	}
	if (to_packet_total) {
		*to_packet_total = ci->to_packet_total;
	}
	if (from_data_total_dropped) {
		*from_data_total_dropped = ci->from_data_total_dropped;
	}
	if (to_data_total_dropped) {
		*to_data_total_dropped = ci->to_data_total_dropped;
	}
	if (from_packet_total_dropped) {
		*from_packet_total_dropped = ci->from_packet_total_dropped;
	}
	if (to_packet_total_dropped) {
		*to_packet_total_dropped = ci->to_packet_total_dropped;
	}
	spin_unlock_bh(&ecm_db_lock);
}
EXPORT_SYMBOL(ecm_db_connection_data_stats_get);

#ifdef ECM_DB_ADVANCED_STATS_ENABLE
/*
 * ecm_db_mapping_data_stats_get()
 *	Return data stats for the instance
 */
void ecm_db_mapping_data_stats_get(struct ecm_db_mapping_instance *mi, uint64_t *from_data_total, uint64_t *to_data_total,
						uint64_t *from_packet_total, uint64_t *to_packet_total,
						uint64_t *from_data_total_dropped, uint64_t *to_data_total_dropped,
						uint64_t *from_packet_total_dropped, uint64_t *to_packet_total_dropped)
{
	DEBUG_CHECK_MAGIC(mi, ECM_DB_MAPPING_INSTANCE_MAGIC, "%p: magic failed", mi);
	spin_lock_bh(&ecm_db_lock);
	if (from_data_total) {
		*from_data_total = mi->from_data_total;
	}
	if (to_data_total) {
		*to_data_total = mi->to_data_total;
	}
	if (from_packet_total) {
		*from_packet_total = mi->from_packet_total;
	}
	if (to_packet_total) {
		*to_packet_total = mi->to_packet_total;
	}
	if (from_data_total_dropped) {
		*from_data_total_dropped = mi->from_data_total_dropped;
	}
	if (to_data_total_dropped) {
		*to_data_total_dropped = mi->to_data_total_dropped;
	}
	if (from_packet_total_dropped) {
		*from_packet_total_dropped = mi->from_packet_total_dropped;
	}
	if (to_packet_total_dropped) {
		*to_packet_total_dropped = mi->to_packet_total_dropped;
	}
	spin_unlock_bh(&ecm_db_lock);
}
EXPORT_SYMBOL(ecm_db_mapping_data_stats_get);
#endif

#ifdef ECM_DB_ADVANCED_STATS_ENABLE
/*
 * ecm_db_host_data_stats_get()
 *	Return data stats for the instance
 */
void ecm_db_host_data_stats_get(struct ecm_db_host_instance *hi, uint64_t *from_data_total, uint64_t *to_data_total,
						uint64_t *from_packet_total, uint64_t *to_packet_total,
						uint64_t *from_data_total_dropped, uint64_t *to_data_total_dropped,
						uint64_t *from_packet_total_dropped, uint64_t *to_packet_total_dropped)
{
	DEBUG_CHECK_MAGIC(hi, ECM_DB_HOST_INSTANCE_MAGIC, "%p: magic failed", hi);
	spin_lock_bh(&ecm_db_lock);
	if (from_data_total) {
		*from_data_total = hi->from_data_total;
	}
	if (to_data_total) {
		*to_data_total = hi->to_data_total;
	}
	if (from_packet_total) {
		*from_packet_total = hi->from_packet_total;
	}
	if (to_packet_total) {
		*to_packet_total = hi->to_packet_total;
	}
	if (from_data_total_dropped) {
		*from_data_total_dropped = hi->from_data_total_dropped;
	}
	if (to_data_total_dropped) {
		*to_data_total_dropped = hi->to_data_total_dropped;
	}
	if (from_packet_total_dropped) {
		*from_packet_total_dropped = hi->from_packet_total_dropped;
	}
	if (to_packet_total_dropped) {
		*to_packet_total_dropped = hi->to_packet_total_dropped;
	}
	spin_unlock_bh(&ecm_db_lock);
}
EXPORT_SYMBOL(ecm_db_host_data_stats_get);
#endif

#ifdef ECM_DB_ADVANCED_STATS_ENABLE
/*
 * ecm_db_node_data_stats_get()
 *	Return data stats for the instance
 */
void ecm_db_node_data_stats_get(struct ecm_db_node_instance *ni, uint64_t *from_data_total, uint64_t *to_data_total,
						uint64_t *from_packet_total, uint64_t *to_packet_total,
						uint64_t *from_data_total_dropped, uint64_t *to_data_total_dropped,
						uint64_t *from_packet_total_dropped, uint64_t *to_packet_total_dropped)
{
	DEBUG_CHECK_MAGIC(ni, ECM_DB_NODE_INSTANCE_MAGIC, "%p: magic failed", ni);
	spin_lock_bh(&ecm_db_lock);
	if (from_data_total) {
		*from_data_total = ni->from_data_total;
	}
	if (to_data_total) {
		*to_data_total = ni->to_data_total;
	}
	if (from_packet_total) {
		*from_packet_total = ni->from_packet_total;
	}
	if (to_packet_total) {
		*to_packet_total = ni->to_packet_total;
	}
	if (from_data_total_dropped) {
		*from_data_total_dropped = ni->from_data_total_dropped;
	}
	if (to_data_total_dropped) {
		*to_data_total_dropped = ni->to_data_total_dropped;
	}
	if (from_packet_total_dropped) {
		*from_packet_total_dropped = ni->from_packet_total_dropped;
	}
	if (to_packet_total_dropped) {
		*to_packet_total_dropped = ni->to_packet_total_dropped;
	}
	spin_unlock_bh(&ecm_db_lock);
}
EXPORT_SYMBOL(ecm_db_node_data_stats_get);
#endif

#ifdef ECM_DB_ADVANCED_STATS_ENABLE
/*
 * ecm_db_iface_data_stats_get()
 *	Return data stats for the instance
 */
void ecm_db_iface_data_stats_get(struct ecm_db_iface_instance *ii, uint64_t *from_data_total, uint64_t *to_data_total,
						uint64_t *from_packet_total, uint64_t *to_packet_total,
						uint64_t *from_data_total_dropped, uint64_t *to_data_total_dropped,
						uint64_t *from_packet_total_dropped, uint64_t *to_packet_total_dropped)
{
	DEBUG_CHECK_MAGIC(ii, ECM_DB_IFACE_INSTANCE_MAGIC, "%p: magic failed", ii);
	spin_lock_bh(&ecm_db_lock);
	if (from_data_total) {
		*from_data_total = ii->from_data_total;
	}
	if (to_data_total) {
		*to_data_total = ii->to_data_total;
	}
	if (from_packet_total) {
		*from_packet_total = ii->from_packet_total;
	}
	if (to_packet_total) {
		*to_packet_total = ii->to_packet_total;
	}
	if (from_data_total_dropped) {
		*from_data_total_dropped = ii->from_data_total_dropped;
	}
	if (to_data_total_dropped) {
		*to_data_total_dropped = ii->to_data_total_dropped;
	}
	if (from_packet_total_dropped) {
		*from_packet_total_dropped = ii->from_packet_total_dropped;
	}
	if (to_packet_total_dropped) {
		*to_packet_total_dropped = ii->to_packet_total_dropped;
	}
	spin_unlock_bh(&ecm_db_lock);
}
EXPORT_SYMBOL(ecm_db_iface_data_stats_get);
#endif

/*
 * ecm_db_connection_serial_get()
 *	Return serial
 */
uint32_t ecm_db_connection_serial_get(struct ecm_db_connection_instance *ci)
{
	DEBUG_CHECK_MAGIC(ci, ECM_DB_CONNECTION_INSTANCE_MAGIC, "%p: magic failed", ci);
	return ci->serial;
}
EXPORT_SYMBOL(ecm_db_connection_serial_get);

/*
 * ecm_db_connection_from_address_get()
 *	Return ip address address
 */
void ecm_db_connection_from_address_get(struct ecm_db_connection_instance *ci, ip_addr_t addr)
{
	DEBUG_CHECK_MAGIC(ci, ECM_DB_CONNECTION_INSTANCE_MAGIC, "%p: magic failed", ci);
	DEBUG_CHECK_MAGIC(ci->mapping_from, ECM_DB_MAPPING_INSTANCE_MAGIC, "%p: magic failed", ci->mapping_from);
	DEBUG_CHECK_MAGIC(ci->mapping_from->host, ECM_DB_HOST_INSTANCE_MAGIC, "%p: magic failed", ci->mapping_from->host);
	ECM_IP_ADDR_COPY(addr, ci->mapping_from->host->address);
}
EXPORT_SYMBOL(ecm_db_connection_from_address_get);

/*
 * ecm_db_connection_from_address_nat_get()
 *	Return NAT ip address address
 */
void ecm_db_connection_from_address_nat_get(struct ecm_db_connection_instance *ci, ip_addr_t addr)
{
	DEBUG_CHECK_MAGIC(ci, ECM_DB_CONNECTION_INSTANCE_MAGIC, "%p: magic failed", ci);
	DEBUG_CHECK_MAGIC(ci->mapping_nat_from, ECM_DB_MAPPING_INSTANCE_MAGIC, "%p: magic failed", ci->mapping_nat_from);
	DEBUG_CHECK_MAGIC(ci->mapping_nat_from->host, ECM_DB_HOST_INSTANCE_MAGIC, "%p: magic failed", ci->mapping_nat_from->host);
	ECM_IP_ADDR_COPY(addr, ci->mapping_nat_from->host->address);
}
EXPORT_SYMBOL(ecm_db_connection_from_address_nat_get);

/*
 * ecm_db_connection_to_address_get()
 *	Return ip address address
 */
void ecm_db_connection_to_address_get(struct ecm_db_connection_instance *ci, ip_addr_t addr)
{
	DEBUG_CHECK_MAGIC(ci, ECM_DB_CONNECTION_INSTANCE_MAGIC, "%p: magic failed", ci);
	DEBUG_CHECK_MAGIC(ci->mapping_to, ECM_DB_MAPPING_INSTANCE_MAGIC, "%p: magic failed", ci->mapping_to);
	DEBUG_CHECK_MAGIC(ci->mapping_to->host, ECM_DB_HOST_INSTANCE_MAGIC, "%p: magic failed", ci->mapping_to->host);
	ECM_IP_ADDR_COPY(addr, ci->mapping_to->host->address);
}
EXPORT_SYMBOL(ecm_db_connection_to_address_get);

/*
 * ecm_db_connection_to_address_nat_get()
 *	Return NAT ip address address
 */
void ecm_db_connection_to_address_nat_get(struct ecm_db_connection_instance *ci, ip_addr_t addr)
{
	DEBUG_CHECK_MAGIC(ci, ECM_DB_CONNECTION_INSTANCE_MAGIC, "%p: magic failed", ci);
	DEBUG_CHECK_MAGIC(ci->mapping_nat_to, ECM_DB_MAPPING_INSTANCE_MAGIC, "%p: magic failed", ci->mapping_nat_to);
	DEBUG_CHECK_MAGIC(ci->mapping_nat_to->host, ECM_DB_HOST_INSTANCE_MAGIC, "%p: magic failed", ci->mapping_nat_to->host);
	ECM_IP_ADDR_COPY(addr, ci->mapping_nat_to->host->address);
}
EXPORT_SYMBOL(ecm_db_connection_to_address_nat_get);

/*
 * ecm_db_connection_to_port_get()
 *	Return port
 */
int ecm_db_connection_to_port_get(struct ecm_db_connection_instance *ci)
{
	DEBUG_CHECK_MAGIC(ci, ECM_DB_CONNECTION_INSTANCE_MAGIC, "%p: magic failed", ci);
	DEBUG_CHECK_MAGIC(ci->mapping_to, ECM_DB_MAPPING_INSTANCE_MAGIC, "%p: magic failed", ci->mapping_to);
	return ci->mapping_to->port;
}
EXPORT_SYMBOL(ecm_db_connection_to_port_get);

/*
 * ecm_db_connection_to_port_nat_get()
 *	Return port
 */
int ecm_db_connection_to_port_nat_get(struct ecm_db_connection_instance *ci)
{
	DEBUG_CHECK_MAGIC(ci, ECM_DB_CONNECTION_INSTANCE_MAGIC, "%p: magic failed", ci);
	DEBUG_CHECK_MAGIC(ci->mapping_nat_to, ECM_DB_MAPPING_INSTANCE_MAGIC, "%p: magic failed", ci->mapping_nat_to);
	return ci->mapping_nat_to->port;
}
EXPORT_SYMBOL(ecm_db_connection_to_port_nat_get);

/*
 * ecm_db_connection_from_port_get()
 *	Return port
 */
int ecm_db_connection_from_port_get(struct ecm_db_connection_instance *ci)
{
	DEBUG_CHECK_MAGIC(ci, ECM_DB_CONNECTION_INSTANCE_MAGIC, "%p: magic failed", ci);
	DEBUG_CHECK_MAGIC(ci->mapping_from, ECM_DB_MAPPING_INSTANCE_MAGIC, "%p: magic failed", ci->mapping_from);
	return ci->mapping_from->port;
}
EXPORT_SYMBOL(ecm_db_connection_from_port_get);

/*
 * ecm_db_connection_from_port_nat_get()
 *	Return port
 */
int ecm_db_connection_from_port_nat_get(struct ecm_db_connection_instance *ci)
{
	DEBUG_CHECK_MAGIC(ci, ECM_DB_CONNECTION_INSTANCE_MAGIC, "%p: magic failed", ci);
	DEBUG_CHECK_MAGIC(ci->mapping_nat_from, ECM_DB_MAPPING_INSTANCE_MAGIC, "%p: magic failed", ci->mapping_nat_from);
	return ci->mapping_nat_from->port;
}
EXPORT_SYMBOL(ecm_db_connection_from_port_nat_get);

/*
 * ecm_db_connection_to_node_address_get()
 *	Return address of the node used when sending packets to the 'to' side.
 */
void ecm_db_connection_to_node_address_get(struct ecm_db_connection_instance *ci, uint8_t *address_buffer)
{
	DEBUG_CHECK_MAGIC(ci, ECM_DB_CONNECTION_INSTANCE_MAGIC, "%p: magic failed", ci);
	memcpy(address_buffer, ci->to_node->address, ETH_ALEN);
}
EXPORT_SYMBOL(ecm_db_connection_to_node_address_get);

/*
 * ecm_db_connection_from_node_address_get()
 *	Return address of the node used when sending packets to the 'from' side.
 */
void ecm_db_connection_from_node_address_get(struct ecm_db_connection_instance *ci, uint8_t *address_buffer)
{
	DEBUG_CHECK_MAGIC(ci, ECM_DB_CONNECTION_INSTANCE_MAGIC, "%p: magic failed", ci);
	memcpy(address_buffer, ci->from_node->address, ETH_ALEN);
}
EXPORT_SYMBOL(ecm_db_connection_from_node_address_get);

/*
 * ecm_db_connection_to_nat_node_address_get()
 *	Return address of the node used when sending packets to the 'to' NAT side.
 */
void ecm_db_connection_to_nat_node_address_get(struct ecm_db_connection_instance *ci, uint8_t *address_buffer)
{
	DEBUG_CHECK_MAGIC(ci, ECM_DB_CONNECTION_INSTANCE_MAGIC, "%p: magic failed", ci);
	memcpy(address_buffer, ci->to_nat_node->address, ETH_ALEN);
}
EXPORT_SYMBOL(ecm_db_connection_to_nat_node_address_get);

/*
 * ecm_db_connection_from_nat_node_address_get()
 *	Return address of the node used when sending packets to the 'from' NAT side.
 */
void ecm_db_connection_from_nat_node_address_get(struct ecm_db_connection_instance *ci, uint8_t *address_buffer)
{
	DEBUG_CHECK_MAGIC(ci, ECM_DB_CONNECTION_INSTANCE_MAGIC, "%p: magic failed", ci);
	memcpy(address_buffer, ci->from_nat_node->address, ETH_ALEN);
}
EXPORT_SYMBOL(ecm_db_connection_from_nat_node_address_get);

/*
 * ecm_db_connection_to_iface_name_get()
 *	Return name of interface on which the 'to' side may be reached
 */
void ecm_db_connection_to_iface_name_get(struct ecm_db_connection_instance *ci, char *name_buffer)
{
	DEBUG_CHECK_MAGIC(ci, ECM_DB_CONNECTION_INSTANCE_MAGIC, "%p: magic failed", ci);
	strcpy(name_buffer, ci->to_node->iface->name);
}
EXPORT_SYMBOL(ecm_db_connection_to_iface_name_get);

/*
 * ecm_db_connection_from_iface_name_get()
 *	Return name of interface on which the 'from' side may be reached
 */
void ecm_db_connection_from_iface_name_get(struct ecm_db_connection_instance *ci, char *name_buffer)
{
	DEBUG_CHECK_MAGIC(ci, ECM_DB_CONNECTION_INSTANCE_MAGIC, "%p: magic failed", ci);
	strcpy(name_buffer, ci->from_node->iface->name);
}
EXPORT_SYMBOL(ecm_db_connection_from_iface_name_get);

/*
 * ecm_db_connection_to_iface_mtu_get()
 *	Return MTU of interface on which the 'to' side may be reached
 */
int ecm_db_connection_to_iface_mtu_get(struct ecm_db_connection_instance *ci)
{
	int mtu;
	DEBUG_CHECK_MAGIC(ci, ECM_DB_CONNECTION_INSTANCE_MAGIC, "%p: magic failed", ci);
	spin_lock_bh(&ecm_db_lock);
	mtu = ci->to_node->iface->mtu;
	spin_unlock_bh(&ecm_db_lock);
	return mtu;
}
EXPORT_SYMBOL(ecm_db_connection_to_iface_mtu_get);

/*
 * ecm_db_connection_to_iface_type_get()
 *	Return type of interface on which the 'to' side may be reached
 */
ecm_db_iface_type_t ecm_db_connection_to_iface_type_get(struct ecm_db_connection_instance *ci)
{
	ecm_db_iface_type_t type;

	DEBUG_CHECK_MAGIC(ci, ECM_DB_CONNECTION_INSTANCE_MAGIC, "%p: magic failed", ci);
	spin_lock_bh(&ecm_db_lock);
	type = ci->to_node->iface->type;
	spin_unlock_bh(&ecm_db_lock);
	return type;
}
EXPORT_SYMBOL(ecm_db_connection_to_iface_type_get);

/*
 * ecm_db_connection_from_iface_mtu_get()
 *	Return MTU of interface on which the 'from' side may be reached
 */
int ecm_db_connection_from_iface_mtu_get(struct ecm_db_connection_instance *ci)
{
	int mtu;
	DEBUG_CHECK_MAGIC(ci, ECM_DB_CONNECTION_INSTANCE_MAGIC, "%p: magic failed", ci);
	spin_lock_bh(&ecm_db_lock);
	mtu = ci->from_node->iface->mtu;
	spin_unlock_bh(&ecm_db_lock);
	return mtu;
}
EXPORT_SYMBOL(ecm_db_connection_from_iface_mtu_get);

/*
 * ecm_db_connection_from_iface_type_get()
 *	Return type of interface on which the 'from' side may be reached
 */
ecm_db_iface_type_t ecm_db_connection_from_iface_type_get(struct ecm_db_connection_instance *ci)
{
	ecm_db_iface_type_t type;

	DEBUG_CHECK_MAGIC(ci, ECM_DB_CONNECTION_INSTANCE_MAGIC, "%p: magic failed", ci);
	spin_lock_bh(&ecm_db_lock);
	type = ci->from_node->iface->type;
	spin_unlock_bh(&ecm_db_lock);
	return type;
}
EXPORT_SYMBOL(ecm_db_connection_from_iface_type_get);

/*
 * ecm_db_connection_iface_type_get()
 *	Return type of interface
 */
ecm_db_iface_type_t ecm_db_connection_iface_type_get(struct ecm_db_iface_instance *ii)
{
	DEBUG_CHECK_MAGIC(ii, ECM_DB_IFACE_INSTANCE_MAGIC, "%p: magic failed", ii);
	return ii->type;
}
EXPORT_SYMBOL(ecm_db_connection_iface_type_get);

/*
 * ecm_db_connection_regeneration_occurrances_get()
 *	Get the number of regeneration occurrances that have occurred since the connection was created.
 */
uint16_t ecm_db_connection_regeneration_occurrances_get(struct ecm_db_connection_instance *ci)
{
	uint16_t occurances;
	DEBUG_CHECK_MAGIC(ci, ECM_DB_CONNECTION_INSTANCE_MAGIC, "%p: magic failed", ci);

	spin_lock_bh(&ecm_db_lock);
	occurances = ci->regen_occurances;
	spin_unlock_bh(&ecm_db_lock);
	return occurances;
}
EXPORT_SYMBOL(ecm_db_connection_regeneration_occurrances_get);

/*
 * ecm_db_conection_regeneration_completed()
 *	Re-generation was completed successfully
 */
void ecm_db_conection_regeneration_completed(struct ecm_db_connection_instance *ci)
{
	DEBUG_CHECK_MAGIC(ci, ECM_DB_CONNECTION_INSTANCE_MAGIC, "%p: magic failed", ci);

	spin_lock_bh(&ecm_db_lock);

	DEBUG_ASSERT(ci->regen_in_progress, "%p: Bad call", ci);
	DEBUG_ASSERT(ci->regen_required > 0, "%p: Bad call", ci);

	/*
	 * Decrement the required counter by 1.
	 * This may mean that regeneration is still required due to another change occuring _during_ re-generation.
	 */
	ci->regen_required--;
	ci->regen_in_progress = false;
	ci->regen_success++;
	spin_unlock_bh(&ecm_db_lock);
}
EXPORT_SYMBOL(ecm_db_conection_regeneration_completed);

/*
 * ecm_db_conection_regeneration_failed()
 *	Re-generation failed
 */
void ecm_db_conection_regeneration_failed(struct ecm_db_connection_instance *ci)
{
	DEBUG_CHECK_MAGIC(ci, ECM_DB_CONNECTION_INSTANCE_MAGIC, "%p: magic failed", ci);

	spin_lock_bh(&ecm_db_lock);

	DEBUG_ASSERT(ci->regen_in_progress, "%p: Bad call", ci);
	DEBUG_ASSERT(ci->regen_required > 0, "%p: Bad call", ci);

	/*
	 * Re-generation is no longer in progress BUT we leave the regen
	 * counter as it is so as to indicate re-generation is still needed
	 */
	ci->regen_in_progress = false;
	ci->regen_fail++;
	spin_unlock_bh(&ecm_db_lock);
}
EXPORT_SYMBOL(ecm_db_conection_regeneration_failed);

/*
 * ecm_db_connection_regeneration_required_check()
 *	Returns true if the connection needs to be re-generated.
 *
 * If re-generation is needed this will mark the connection to indicate that re-generation is needed AND in progress.
 * If the return code is TRUE the caller MUST handle the re-generation.
 * Upon re-generation completion you must call ecm_db_conection_regeneration_completed() or ecm_db_conection_regeneration_failed().
 */
bool ecm_db_connection_regeneration_required_check(struct ecm_db_connection_instance *ci)
{
	DEBUG_CHECK_MAGIC(ci, ECM_DB_CONNECTION_INSTANCE_MAGIC, "%p: magic failed", ci);

	/*
	 * Check the global generation counter for changes
	 */
	spin_lock_bh(&ecm_db_lock);
	if (ci->generation != ecm_db_connection_generation) {
		/*
		 * Re-generation is needed
		 */
		ci->regen_occurances++;
		ci->regen_required++;

		/*
		 * Record that we have seen this change
		 */
		ci->generation = ecm_db_connection_generation;
	}

	/*
	 * If re-generation is in progress then something is handling re-generation already
	 * so we tell the caller that it cannot handle re-generation.
	 */
	if (ci->regen_in_progress) {
		spin_unlock_bh(&ecm_db_lock);
		return false;
	}

	/*
	 * Is re-generation required?
	 */
	if (ci->regen_required == 0) {
		spin_unlock_bh(&ecm_db_lock);
		return false;
	}

	/*
	 * Flag that re-generation is in progress and tell the caller to handle re-generation
	 */
	ci->regen_in_progress = true;
	spin_unlock_bh(&ecm_db_lock);
	return true;
}
EXPORT_SYMBOL(ecm_db_connection_regeneration_required_check);

/*
 * ecm_db_connection_regeneration_required_peek()
 *	Returns true if the connection needs to be regenerated.
 *
 * NOTE: The caller MUST NOT handle re-generation, the caller may use this indication
 * to determine the sanity of the connection state and whether acceleration is permitted.
 */
bool ecm_db_connection_regeneration_required_peek(struct ecm_db_connection_instance *ci)
{
	DEBUG_CHECK_MAGIC(ci, ECM_DB_CONNECTION_INSTANCE_MAGIC, "%p: magic failed", ci);

	spin_lock_bh(&ecm_db_lock);

	/*
	 * Check the global generation counter for changes (record any change now)
	 */
	if (ci->generation != ecm_db_connection_generation) {
		/*
		 * Re-generation is needed, flag the connection as needing re-generation now.
		 */
		ci->regen_occurances++;
		ci->regen_required++;

		/*
		 * Record that we have seen this change
		 */
		ci->generation = ecm_db_connection_generation;
	}
	if (ci->regen_required == 0) {
		spin_unlock_bh(&ecm_db_lock);
		return false;
	}
	spin_unlock_bh(&ecm_db_lock);
	return true;
}
EXPORT_SYMBOL(ecm_db_connection_regeneration_required_peek);

/*
 * ecm_db_connection_regeneration_needed()
 *	Cause a specific connection to require re-generation
 *
 * NOTE: This only flags that re-generation is needed.
 * The connection will typically be re-generated when ecm_db_connection_regeneration_required_check() is invoked.
 */
void ecm_db_connection_regeneration_needed(struct ecm_db_connection_instance *ci)
{
	DEBUG_CHECK_MAGIC(ci, ECM_DB_CONNECTION_INSTANCE_MAGIC, "%p: magic failed", ci);

	spin_lock_bh(&ecm_db_lock);
	ci->regen_occurances++;
	ci->regen_required++;
	spin_unlock_bh(&ecm_db_lock);
}
EXPORT_SYMBOL(ecm_db_connection_regeneration_needed);

/*
 * ecm_db_regeneration_needed()
 *	Bump the global generation index to cause a re-generation of all connections state.
 */
void ecm_db_regeneration_needed(void)
{
	spin_lock_bh(&ecm_db_lock);
	ecm_db_connection_generation++;
	spin_unlock_bh(&ecm_db_lock);
}
EXPORT_SYMBOL(ecm_db_regeneration_needed);

/*
 * ecm_db_connection_regenerate()
 *	Re-generate a specific connection
 */
void ecm_db_connection_regenerate(struct ecm_db_connection_instance *ci)
{
	struct ecm_front_end_connection_instance *feci;

	DEBUG_TRACE("Regenerate connection: %p\n", ci);

	DEBUG_CHECK_MAGIC(ci, ECM_DB_CONNECTION_INSTANCE_MAGIC, "%p: magic failed", ci);

	/*
	 * Notify front end to regenerate a connection.
	 */
	feci = ecm_db_connection_front_end_get_and_ref(ci);
	feci->regenerate(feci, ci);
	feci->deref(feci);
}
EXPORT_SYMBOL(ecm_db_connection_regenerate);

/*
 * ecm_db_connection_direction_get()
 *	Return direction of the connection.
 *
 * NOTE: an EGRESS connection means that packets being sent to mapping_to should have qos applied.
 * INGRESS means that packets being sent to mapping_from should have qos applied.
 */
ecm_db_direction_t ecm_db_connection_direction_get(struct ecm_db_connection_instance *ci)
{
	DEBUG_CHECK_MAGIC(ci, ECM_DB_CONNECTION_INSTANCE_MAGIC, "%p: magic failed", ci);
	return ci->direction;
}
EXPORT_SYMBOL(ecm_db_connection_direction_get);

/*
 * ecm_db_mapping_port_count_get()
 *	Return port count stats for a mapping.
 */
void ecm_db_mapping_port_count_get(struct ecm_db_mapping_instance *mi,
						int *tcp_from, int *tcp_to, int *udp_from, int *udp_to, int *from, int *to,
						int *tcp_nat_from, int *tcp_nat_to, int *udp_nat_from, int *udp_nat_to, int *nat_from, int *nat_to)
{
	DEBUG_CHECK_MAGIC(mi, ECM_DB_MAPPING_INSTANCE_MAGIC, "%p: magic failed", mi);

	spin_lock_bh(&ecm_db_lock);

	*tcp_from = mi->tcp_from;
	*tcp_to = mi->tcp_to;
	*udp_from = mi->udp_from;
	*udp_to = mi->udp_to;
	*from = mi->from;
	*to = mi->to;

	*tcp_nat_from = mi->tcp_nat_from;
	*tcp_nat_to = mi->tcp_nat_to;
	*udp_nat_from = mi->udp_nat_from;
	*udp_nat_to = mi->udp_nat_to;
	*nat_from = mi->nat_from;
	*nat_to = mi->nat_to;

	spin_unlock_bh(&ecm_db_lock);
}
EXPORT_SYMBOL(ecm_db_mapping_port_count_get);

/*
 * ecm_db_connection_is_routed_get()
 *	Return whether connection is a routed path or not
 */
bool ecm_db_connection_is_routed_get(struct ecm_db_connection_instance *ci)
{
	DEBUG_CHECK_MAGIC(ci, ECM_DB_CONNECTION_INSTANCE_MAGIC, "%p: magic failed", ci);
	return ci->is_routed;
}
EXPORT_SYMBOL(ecm_db_connection_is_routed_get);

/*
 * ecm_db_connection_protocol_get()
 *	Return protocol of connection
 */
int ecm_db_connection_protocol_get(struct ecm_db_connection_instance *ci)
{
	DEBUG_CHECK_MAGIC(ci, ECM_DB_CONNECTION_INSTANCE_MAGIC, "%p: magic failed", ci);
	return ci->protocol;
}
EXPORT_SYMBOL(ecm_db_connection_protocol_get);

/*
 * ecm_db_connection_ip_version_get()
 *	Return IP version of connection
 */
int ecm_db_connection_ip_version_get(struct ecm_db_connection_instance *ci)
{
	DEBUG_CHECK_MAGIC(ci, ECM_DB_CONNECTION_INSTANCE_MAGIC, "%p: magic failed", ci);
	return ci->ip_version;
}
EXPORT_SYMBOL(ecm_db_connection_ip_version_get);

/*
 * ecm_db_host_address_get()
 *	Return address of host
 */
void ecm_db_host_address_get(struct ecm_db_host_instance *hi, ip_addr_t addr)
{
	DEBUG_CHECK_MAGIC(hi, ECM_DB_HOST_INSTANCE_MAGIC, "%p: magic failed", hi);
	ECM_IP_ADDR_COPY(addr, hi->address);
}
EXPORT_SYMBOL(ecm_db_host_address_get);

/*
 * ecm_db_host_on_link_get()
 *	Return on link status of host
 */
bool ecm_db_host_on_link_get(struct ecm_db_host_instance *hi)
{
	DEBUG_CHECK_MAGIC(hi, ECM_DB_HOST_INSTANCE_MAGIC, "%p: magic failed", hi);
	return hi->on_link;
}
EXPORT_SYMBOL(ecm_db_host_on_link_get);

/*
 * ecm_db_mapping_adress_get()
 *	Return address
 */
void ecm_db_mapping_adress_get(struct ecm_db_mapping_instance *mi, ip_addr_t addr)
{
	DEBUG_CHECK_MAGIC(mi, ECM_DB_MAPPING_INSTANCE_MAGIC, "%p: magic failed", mi);
	ECM_IP_ADDR_COPY(addr, mi->host->address);
}
EXPORT_SYMBOL(ecm_db_mapping_adress_get);

/*
 * ecm_db_mapping_port_get()
 *	Return port
 */
int ecm_db_mapping_port_get(struct ecm_db_mapping_instance *mi)
{
	DEBUG_CHECK_MAGIC(mi, ECM_DB_MAPPING_INSTANCE_MAGIC, "%p: magic failed", mi);
	return mi->port;
}
EXPORT_SYMBOL(ecm_db_mapping_port_get);

/*
 * ecm_db_node_adress_get()
 *	Return address
 */
void ecm_db_node_adress_get(struct ecm_db_node_instance *ni, uint8_t *address_buffer)
{
	DEBUG_CHECK_MAGIC(ni, ECM_DB_NODE_INSTANCE_MAGIC, "%p: magic failed", ni);
	memcpy(address_buffer, ni->address, ETH_ALEN);
}
EXPORT_SYMBOL(ecm_db_node_adress_get);

/*
 * _ecm_db_timer_group_entry_remove()
 *	Remove the entry from its timer group, returns false if the entry has already expired.
 */
static bool _ecm_db_timer_group_entry_remove(struct ecm_db_timer_group_entry *tge)
{
	struct ecm_db_timer_group *timer_group;

	/*
	 * If not in a timer group then it is already removed
	 */
	if (tge->group == ECM_DB_TIMER_GROUPS_MAX) {
		return false;
	}

	/*
	 * Remove the connection from its current group
	 */
	timer_group = &ecm_db_timer_groups[tge->group];

	/*
	 * Somewhere in the list?
	 */
	if (tge->prev) {
		tge->prev->next = tge->next;
	} else {
		/*
		 * First in the group
		 */
		DEBUG_ASSERT(timer_group->head == tge, "%p: bad head, expecting %p, got %p\n", timer_group, tge, timer_group->head);
		timer_group->head = tge->next;
	}

	if (tge->next) {
		tge->next->prev = tge->prev;
	} else {
		/*
		 * No next so this must be the last item - we need to adjust the tail pointer
		 */
		DEBUG_ASSERT(timer_group->tail == tge, "%p: bad tail, expecting %p got %p\n", timer_group, tge, timer_group->tail);
		timer_group->tail = tge->prev;
	}

	/*
	 * No longer a part of a timer group
	 */
	tge->group = ECM_DB_TIMER_GROUPS_MAX;
	return true;
}

/*
 * ecm_db_timer_group_entry_remove()
 *	Remove the connection from its timer group, returns false if the entry has already expired.
 */
bool ecm_db_timer_group_entry_remove(struct ecm_db_timer_group_entry *tge)
{
	bool res;
	spin_lock_bh(&ecm_db_lock);
	res = _ecm_db_timer_group_entry_remove(tge);
	spin_unlock_bh(&ecm_db_lock);
	return res;
}
EXPORT_SYMBOL(ecm_db_timer_group_entry_remove);

/*
 * _ecm_db_timer_group_entry_set()
 *	Set the timer group to which this entry will be a member
 */
void _ecm_db_timer_group_entry_set(struct ecm_db_timer_group_entry *tge, ecm_db_timer_group_t tg)
{
	struct ecm_db_timer_group *timer_group;

	DEBUG_ASSERT(tge->group == ECM_DB_TIMER_GROUPS_MAX, "%p: already set\n", tge);

	/*
	 * Set group
	 */
	tge->group = tg;
	timer_group = &ecm_db_timer_groups[tge->group];
	tge->timeout = timer_group->time + ecm_db_time;

	/*
	 * Insert into a timer group at the head (as this is now touched)
	 */
	tge->prev = NULL;
	tge->next = timer_group->head;
	if (!timer_group->head) {
		/*
		 * As there is no head there is also no tail so we need to set that
		 */
		timer_group->tail = tge;
	} else {
		/*
		 * As there is a head already there must be a tail.  Since we insert before
		 * the current head we don't adjust the tail.
		 */
		timer_group->head->prev = tge;
	}
	timer_group->head = tge;
}

/*
 * ecm_db_timer_group_entry_reset()
 *	Re-set the timer group to which this entry will be a member.
 *
 * Returns false if the timer cannot be reset because it has expired
 */
bool ecm_db_timer_group_entry_reset(struct ecm_db_timer_group_entry *tge, ecm_db_timer_group_t tg)
{
	spin_lock_bh(&ecm_db_lock);

	/*
	 * Remove it from its current group, if any
	 */
	if (!_ecm_db_timer_group_entry_remove(tge)) {
		spin_unlock_bh(&ecm_db_lock);
		return false;
	}

	/*
	 * Set new group
	 */
	_ecm_db_timer_group_entry_set(tge, tg);
	spin_unlock_bh(&ecm_db_lock);
	return true;
}
EXPORT_SYMBOL(ecm_db_timer_group_entry_reset);

/*
 * ecm_db_timer_group_entry_set()
 *	Set the timer group to which this entry will be a member
 */
void ecm_db_timer_group_entry_set(struct ecm_db_timer_group_entry *tge, ecm_db_timer_group_t tg)
{
	spin_lock_bh(&ecm_db_lock);
	_ecm_db_timer_group_entry_set(tge, tg);
	spin_unlock_bh(&ecm_db_lock);
}
EXPORT_SYMBOL(ecm_db_timer_group_entry_set);

/*
 * ecm_db_connection_defunct_timer_remove_and_set()
 *	Move the connection to a new timer group.
 *
 * Before setting the new group, check if the timer group is set. If it is set,
 * remove it first from the current group.
 *
 */
void ecm_db_connection_defunct_timer_remove_and_set(struct ecm_db_connection_instance *ci, ecm_db_timer_group_t tg)
{
	struct ecm_db_timer_group_entry *tge;

	DEBUG_CHECK_MAGIC(ci, ECM_DB_CONNECTION_INSTANCE_MAGIC, "%p: magic failed", ci);
	DEBUG_TRACE("%p: ecm_db_connection_defunct_timer_remove_and_set\n", ci);

	spin_lock_bh(&ecm_db_lock);
	tge = &ci->defunct_timer;
	if (tge->group == tg) {
		spin_unlock_bh(&ecm_db_lock);
		DEBUG_TRACE("%p: timer group is aslready equal to %d\n", ci, tg);
		return;
	}

	if (tge->group != ECM_DB_TIMER_GROUPS_MAX) {
		_ecm_db_timer_group_entry_remove(tge);
	}

	/*
	 * Set new group
	 */
	_ecm_db_timer_group_entry_set(tge, tg);
	spin_unlock_bh(&ecm_db_lock);
	DEBUG_TRACE("%p: New timer group is: %d\n", ci, tge->group);
}
EXPORT_SYMBOL(ecm_db_connection_defunct_timer_remove_and_set);

/*
 * ecm_db_timer_group_entry_init()
 *	Initialise a timer entry ready for setting
 */
void ecm_db_timer_group_entry_init(struct ecm_db_timer_group_entry *tge, ecm_db_timer_group_entry_callback_t fn, void *arg)
{
	memset(tge, 0, sizeof(struct ecm_db_timer_group_entry));
	tge->group = ECM_DB_TIMER_GROUPS_MAX;
	tge->arg = arg;
	tge->fn = fn;
}
EXPORT_SYMBOL(ecm_db_timer_group_entry_init);

/*
 * ecm_db_timer_group_entry_touch()
 *	Update the timeout, if the timer is not running this has no effect.
 * It returns false if the timer is not running.
 */
bool ecm_db_timer_group_entry_touch(struct ecm_db_timer_group_entry *tge)
{
	struct ecm_db_timer_group *timer_group;

	spin_lock_bh(&ecm_db_lock);

	/*
	 * If not in a timer group then do nothing
	 */
	if (tge->group == ECM_DB_TIMER_GROUPS_MAX) {
		spin_unlock_bh(&ecm_db_lock);
		return false;
	}

	/*
	 * Update time to live
	 */
	timer_group = &ecm_db_timer_groups[tge->group];

	/*
	 * Link out of its current position.
	 */
	if (!tge->prev) {
		/*
		 * Already at the head, just update the time
		 */
		tge->timeout = timer_group->time + ecm_db_time;
		spin_unlock_bh(&ecm_db_lock);
		return true;
	}

	/*
	 * tge->prev is not null, so:
	 * 1) it is in a timer list
	 * 2) is not at the head of the list
	 * 3) there is a head already (so more than one item on the list)
	 * 4) there is a prev pointer.
	 * Somewhere in the group list - unlink it.
	 */
	tge->prev->next = tge->next;

	if (tge->next) {
		tge->next->prev = tge->prev;
	} else {
		/*
		 * Since there is no next this must be the tail
		 */
		DEBUG_ASSERT(timer_group->tail == tge, "%p: bad tail, expecting %p got %p\n", timer_group, tge, timer_group->tail);
		timer_group->tail = tge->prev;
	}

	/*
	 * Link in to head.
	 */
	tge->timeout = timer_group->time + ecm_db_time;
	tge->prev = NULL;
	tge->next = timer_group->head;
	timer_group->head->prev = tge;
	timer_group->head = tge;
	spin_unlock_bh(&ecm_db_lock);
	return true;
}
EXPORT_SYMBOL(ecm_db_timer_group_entry_touch);

/*
 * _ecm_db_connection_ref()
 */
static void _ecm_db_connection_ref(struct ecm_db_connection_instance *ci)
{
	DEBUG_CHECK_MAGIC(ci, ECM_DB_CONNECTION_INSTANCE_MAGIC, "%p: magic failed", ci);
	ci->refs++;
	DEBUG_TRACE("%p: connection ref %d\n", ci, ci->refs);
	DEBUG_ASSERT(ci->refs > 0, "%p: ref wrap\n", ci);
}

/*
 * ecm_db_connection_ref()
 */
void ecm_db_connection_ref(struct ecm_db_connection_instance *ci)
{
	spin_lock_bh(&ecm_db_lock);
	_ecm_db_connection_ref(ci);
	spin_unlock_bh(&ecm_db_lock);
}
EXPORT_SYMBOL(ecm_db_connection_ref);

/*
 * _ecm_db_mapping_ref()
 */
static void _ecm_db_mapping_ref(struct ecm_db_mapping_instance *mi)
{
	DEBUG_CHECK_MAGIC(mi, ECM_DB_MAPPING_INSTANCE_MAGIC, "%p: magic failed\n", mi);
	mi->refs++;
	DEBUG_TRACE("%p: mapping ref %d\n", mi, mi->refs);
	DEBUG_ASSERT(mi->refs > 0, "%p: ref wrap\n", mi);
}

/*
 * ecm_db_mapping_ref()
 */
void ecm_db_mapping_ref(struct ecm_db_mapping_instance *mi)
{
	spin_lock_bh(&ecm_db_lock);
	_ecm_db_mapping_ref(mi);
	spin_unlock_bh(&ecm_db_lock);
}
EXPORT_SYMBOL(ecm_db_mapping_ref);

/*
 * _ecm_db_host_ref()
 */
static void _ecm_db_host_ref(struct ecm_db_host_instance *hi)
{
	DEBUG_CHECK_MAGIC(hi, ECM_DB_HOST_INSTANCE_MAGIC, "%p: magic failed\n", hi);
	hi->refs++;
	DEBUG_TRACE("%p: host ref %d\n", hi, hi->refs);
	DEBUG_ASSERT(hi->refs > 0, "%p: ref wrap\n", hi);
}

/*
 * ecm_db_host_ref()
 */
void ecm_db_host_ref(struct ecm_db_host_instance *hi)
{
	spin_lock_bh(&ecm_db_lock);
	_ecm_db_host_ref(hi);
	spin_unlock_bh(&ecm_db_lock);
}
EXPORT_SYMBOL(ecm_db_host_ref);

/*
 * _ecm_db_node_ref()
 */
static void _ecm_db_node_ref(struct ecm_db_node_instance *ni)
{
	DEBUG_CHECK_MAGIC(ni, ECM_DB_NODE_INSTANCE_MAGIC, "%p: magic failed\n", ni);
	ni->refs++;
	DEBUG_TRACE("%p: node ref %d\n", ni, ni->refs);
	DEBUG_ASSERT(ni->refs > 0, "%p: ref wrap\n", ni);
}

/*
 * ecm_db_node_ref()
 */
void ecm_db_node_ref(struct ecm_db_node_instance *ni)
{
	spin_lock_bh(&ecm_db_lock);
	_ecm_db_node_ref(ni);
	spin_unlock_bh(&ecm_db_lock);
}
EXPORT_SYMBOL(ecm_db_node_ref);

/*
 * _ecm_db_iface_ref()
 */
static void _ecm_db_iface_ref(struct ecm_db_iface_instance *ii)
{
	DEBUG_CHECK_MAGIC(ii, ECM_DB_IFACE_INSTANCE_MAGIC, "%p: magic failed\n", ii);
	ii->refs++;
	DEBUG_TRACE("%p: iface ref %d\n", ii, ii->refs);
	DEBUG_ASSERT(ii->refs > 0, "%p: ref wrap\n", ii);
}

/*
 * ecm_db_iface_ref()
 */
void ecm_db_iface_ref(struct ecm_db_iface_instance *ii)
{
	spin_lock_bh(&ecm_db_lock);
	_ecm_db_iface_ref(ii);
	spin_unlock_bh(&ecm_db_lock);
}
EXPORT_SYMBOL(ecm_db_iface_ref);

/*
 * _ecm_db_listener_ref()
 */
static void _ecm_db_listener_ref(struct ecm_db_listener_instance *li)
{
	DEBUG_CHECK_MAGIC(li, ECM_DB_LISTENER_INSTANCE_MAGIC, "%p: magic failed", li);
	li->refs++;
	DEBUG_ASSERT(li->refs > 0, "%p: ref wrap\n", li);
}

/*
 * ecm_db_listener_ref()
 */
void ecm_db_listener_ref(struct ecm_db_listener_instance *li)
{
	spin_lock_bh(&ecm_db_lock);
	_ecm_db_listener_ref(li);
	spin_unlock_bh(&ecm_db_lock);
}
EXPORT_SYMBOL(ecm_db_listener_ref);

/*
 * ecm_db_connections_get_and_ref_first()
 *	Obtain a ref to the first connection instance, if any
 */
struct ecm_db_connection_instance *ecm_db_connections_get_and_ref_first(void)
{
	struct ecm_db_connection_instance *ci;
	spin_lock_bh(&ecm_db_lock);
	ci = ecm_db_connections;
	if (ci) {
		_ecm_db_connection_ref(ci);
	}
	spin_unlock_bh(&ecm_db_lock);
	return ci;
}
EXPORT_SYMBOL(ecm_db_connections_get_and_ref_first);

/*
 * ecm_db_connection_get_and_ref_next()
 *	Return the next connection in the list given a connection
 */
struct ecm_db_connection_instance *ecm_db_connection_get_and_ref_next(struct ecm_db_connection_instance *ci)
{
	struct ecm_db_connection_instance *cin;
	DEBUG_CHECK_MAGIC(ci, ECM_DB_CONNECTION_INSTANCE_MAGIC, "%p: magic failed", ci);
	spin_lock_bh(&ecm_db_lock);
	cin = ci->next;
	if (cin) {
		_ecm_db_connection_ref(cin);
	}
	spin_unlock_bh(&ecm_db_lock);
	return cin;
}
EXPORT_SYMBOL(ecm_db_connection_get_and_ref_next);

/*
 * ecm_db_mappings_get_and_ref_first()
 *	Obtain a ref to the first mapping instance, if any
 */
struct ecm_db_mapping_instance *ecm_db_mappings_get_and_ref_first(void)
{
	struct ecm_db_mapping_instance *mi;
	spin_lock_bh(&ecm_db_lock);
	mi = ecm_db_mappings;
	if (mi) {
		_ecm_db_mapping_ref(mi);
	}
	spin_unlock_bh(&ecm_db_lock);
	return mi;
}
EXPORT_SYMBOL(ecm_db_mappings_get_and_ref_first);

/*
 * ecm_db_mapping_get_and_ref_next()
 *	Return the next mapping in the list given a mapping
 */
struct ecm_db_mapping_instance *ecm_db_mapping_get_and_ref_next(struct ecm_db_mapping_instance *mi)
{
	struct ecm_db_mapping_instance *min;
	DEBUG_CHECK_MAGIC(mi, ECM_DB_MAPPING_INSTANCE_MAGIC, "%p: magic failed", mi);
	spin_lock_bh(&ecm_db_lock);
	min = mi->next;
	if (min) {
		_ecm_db_mapping_ref(min);
	}
	spin_unlock_bh(&ecm_db_lock);
	return min;
}
EXPORT_SYMBOL(ecm_db_mapping_get_and_ref_next);

/*
 * ecm_db_hosts_get_and_ref_first()
 *	Obtain a ref to the first host instance, if any
 */
struct ecm_db_host_instance *ecm_db_hosts_get_and_ref_first(void)
{
	struct ecm_db_host_instance *hi;
	spin_lock_bh(&ecm_db_lock);
	hi = ecm_db_hosts;
	if (hi) {
		_ecm_db_host_ref(hi);
	}
	spin_unlock_bh(&ecm_db_lock);
	return hi;
}
EXPORT_SYMBOL(ecm_db_hosts_get_and_ref_first);

/*
 * ecm_db_host_get_and_ref_next()
 *	Return the next host in the list given a host
 */
struct ecm_db_host_instance *ecm_db_host_get_and_ref_next(struct ecm_db_host_instance *hi)
{
	struct ecm_db_host_instance *hin;
	DEBUG_CHECK_MAGIC(hi, ECM_DB_HOST_INSTANCE_MAGIC, "%p: magic failed", hi);
	spin_lock_bh(&ecm_db_lock);
	hin = hi->next;
	if (hin) {
		_ecm_db_host_ref(hin);
	}
	spin_unlock_bh(&ecm_db_lock);
	return hin;
}
EXPORT_SYMBOL(ecm_db_host_get_and_ref_next);

/*
 * ecm_db_listeners_get_and_ref_first()
 *	Obtain a ref to the first listener instance, if any
 */
static struct ecm_db_listener_instance *ecm_db_listeners_get_and_ref_first(void)
{
	struct ecm_db_listener_instance *li;
	spin_lock_bh(&ecm_db_lock);
	li = ecm_db_listeners;
	if (li) {
		_ecm_db_listener_ref(li);
	}
	spin_unlock_bh(&ecm_db_lock);
	return li;
}

/*
 * ecm_db_listener_get_and_ref_next()
 *	Return the next listener in the list given a listener
 */
static struct ecm_db_listener_instance *ecm_db_listener_get_and_ref_next(struct ecm_db_listener_instance *li)
{
	struct ecm_db_listener_instance *lin;
	DEBUG_CHECK_MAGIC(li, ECM_DB_LISTENER_INSTANCE_MAGIC, "%p: magic failed", li);
	spin_lock_bh(&ecm_db_lock);
	lin = li->next;
	if (lin) {
		_ecm_db_listener_ref(lin);
	}
	spin_unlock_bh(&ecm_db_lock);
	return lin;
}

/*
 * ecm_db_nodes_get_and_ref_first()
 *	Obtain a ref to the first node instance, if any
 */
struct ecm_db_node_instance *ecm_db_nodes_get_and_ref_first(void)
{
	struct ecm_db_node_instance *ni;
	spin_lock_bh(&ecm_db_lock);
	ni = ecm_db_nodes;
	if (ni) {
		_ecm_db_node_ref(ni);
	}
	spin_unlock_bh(&ecm_db_lock);
	return ni;
}
EXPORT_SYMBOL(ecm_db_nodes_get_and_ref_first);

/*
 * ecm_db_node_get_and_ref_next()
 *	Return the next node in the list given a node
 */
struct ecm_db_node_instance *ecm_db_node_get_and_ref_next(struct ecm_db_node_instance *ni)
{
	struct ecm_db_node_instance *nin;
	DEBUG_CHECK_MAGIC(ni, ECM_DB_NODE_INSTANCE_MAGIC, "%p: magic failed", ni);
	spin_lock_bh(&ecm_db_lock);
	nin = ni->next;
	if (nin) {
		_ecm_db_node_ref(nin);
	}
	spin_unlock_bh(&ecm_db_lock);
	return nin;
}
EXPORT_SYMBOL(ecm_db_node_get_and_ref_next);

/*
 * ecm_db_interfaces_get_and_ref_first()
 *	Obtain a ref to the first iface instance, if any
 */
struct ecm_db_iface_instance *ecm_db_interfaces_get_and_ref_first(void)
{
	struct ecm_db_iface_instance *ii;
	spin_lock_bh(&ecm_db_lock);
	ii = ecm_db_interfaces;
	if (ii) {
		_ecm_db_iface_ref(ii);
	}
	spin_unlock_bh(&ecm_db_lock);
	return ii;
}
EXPORT_SYMBOL(ecm_db_interfaces_get_and_ref_first);

/*
 * ecm_db_interface_get_and_ref_next()
 *	Return the next iface in the list given a iface
 */
struct ecm_db_iface_instance *ecm_db_interface_get_and_ref_next(struct ecm_db_iface_instance *ii)
{
	struct ecm_db_iface_instance *iin;
	DEBUG_CHECK_MAGIC(ii, ECM_DB_IFACE_INSTANCE_MAGIC, "%p: magic failed", ii);
	spin_lock_bh(&ecm_db_lock);
	iin = ii->next;
	if (iin) {
		_ecm_db_iface_ref(iin);
	}
	spin_unlock_bh(&ecm_db_lock);
	return iin;
}
EXPORT_SYMBOL(ecm_db_interface_get_and_ref_next);

#ifdef ECM_DB_CTA_TRACK_ENABLE
/*
 * _ecm_db_classifier_type_assignment_remove()
 *	Remove the connection from the classifier type assignment list (of the given type)
 */
static void _ecm_db_classifier_type_assignment_remove(struct ecm_db_connection_instance *ci, ecm_classifier_type_t ca_type)
{
	struct ecm_db_connection_classifier_type_assignment *ta;
	struct ecm_db_connection_classifier_type_assignment_list *tal;

	DEBUG_ASSERT(spin_is_locked(&ecm_db_lock), "%p: lock is not held\n", ci);

	DEBUG_TRACE("%p: Classifier type assignment remove: %d\n", ci, ca_type);
	ta = &ci->type_assignment[ca_type];
	DEBUG_CHECK_MAGIC(ta, ECM_DB_CLASSIFIER_TYPE_ASSIGNMENT_MAGIC, "%p: magic failed, ci: %p\n", ta, ci);
	DEBUG_ASSERT(ta->iteration_count == 0, "%p: iteration count: %d, type: %d\n", ci, ta->iteration_count, ca_type);

	if (ta->next) {
		struct ecm_db_connection_classifier_type_assignment *tan = &ta->next->type_assignment[ca_type];
		DEBUG_ASSERT(tan->prev == ci, "Bad list, expecting: %p, got: %p\n", ci, tan->prev);
		tan->prev = ta->prev;
	}

	tal = &ecm_db_connection_classifier_type_assignments[ca_type];
	if (ta->prev) {
		struct ecm_db_connection_classifier_type_assignment *tap = &ta->prev->type_assignment[ca_type];
		DEBUG_ASSERT(tap->next == ci, "Bad list, expecting: %p, got: %p\n", ci, tap->next);
		tap->next = ta->next;
	} else {
		/*
		 * Set new head of list
		 */
		DEBUG_ASSERT(tal->type_assignments_list == ci, "Bad head, expecting %p, got %p, type: %d\n", ci, tal->type_assignments_list, ca_type);
		tal->type_assignments_list = ta->next;
	}
	ta->next = NULL;
	ta->prev = NULL;
	ta->pending_unassign = false;

	/*
	 * Decrement assignment count
	 */
	tal->type_assignment_count--;
	DEBUG_ASSERT(tal->type_assignment_count >= 0, "Bad type assignment count: %d, type: %d\n", tal->type_assignment_count, ca_type);

	DEBUG_CLEAR_MAGIC(ta);
}
#endif

/*
 * _ecm_db_connection_classifier_unassign()
 *	Unassign a classifier and remove the classifier type
 *
 * The default classifier cannot be unassigned.
 */
static inline void _ecm_db_connection_classifier_unassign(struct ecm_db_connection_instance *ci, struct ecm_classifier_instance *cci, ecm_classifier_type_t ca_type)
{
#ifdef ECM_DB_CTA_TRACK_ENABLE
	struct ecm_db_connection_classifier_type_assignment *ta;
#endif
	DEBUG_ASSERT(spin_is_locked(&ecm_db_lock), "%p: lock is not held\n", ci);

	/*
	 * Clear the assignment.
	 */
	ci->assignments_by_type[ca_type] = NULL;

	/*
	 * Link out of assignments list
	 */
	if (cci->ca_prev) {
		cci->ca_prev->ca_next = cci->ca_next;
	} else {
		DEBUG_ASSERT(ci->assignments == cci, "%p: Bad assigmnment list, expecting: %p, got: %p", ci, cci, ci->assignments);
		ci->assignments = cci->ca_next;
	}
	if (cci->ca_next) {
		cci->ca_next->ca_prev = cci->ca_prev;
	}

#ifdef ECM_DB_CTA_TRACK_ENABLE
	/*
	 * Remove from the classifier type assignment list
	 */
	ta = &ci->type_assignment[ca_type];
	DEBUG_CHECK_MAGIC(ta, ECM_DB_CLASSIFIER_TYPE_ASSIGNMENT_MAGIC, "%p: magic failed, ci: %p", ta, ci);
	if (ta->iteration_count > 0) {
		/*
		 * The list entry is being iterated outside of db lock being held.
		 * We cannot remove this entry since it would mess up iteration.
		 * Set the pending flag to be actioned another time
		 */
		ta->pending_unassign = true;
		return;
	}

	/*
	 * Remove the list entry
	 */
	DEBUG_INFO("%p: Remove type assignment: %d\n", ci, ca_type);
	_ecm_db_classifier_type_assignment_remove(ci, ca_type);
#endif
	cci->deref(cci);
}

#ifdef ECM_MULTICAST_ENABLE
/*
 * _ecm_db_multicast_tuple_instance_deref()
 * 	Deref the reference count or
 * 	Free the tuple_instance struct, when the multicast connection dies
 */
int _ecm_db_multicast_tuple_instance_deref(struct ecm_db_multicast_tuple_instance *ti)
{
	DEBUG_CHECK_MAGIC(ti, ECM_DB_MULTICAST_INSTANCE_MAGIC, "%p: magic failed", ti);
	ti->refs--;
	DEBUG_TRACE("%p: ti deref %d\n", ti, ti->refs);
	DEBUG_ASSERT(ti->refs >= 0, "%p: ref wrap\n", ti);

	if (ti->refs > 0) {
		return ti->refs;
	}

	if (ti->flags & ECM_DB_MULTICAST_TUPLE_INSTANCE_FLAGS_INSERTED) {
		if (!ti->prev) {
			DEBUG_ASSERT(ecm_db_multicast_tuple_instance_table[ti->hash_index] == ti, "%p: hash table bad\n", ti);
			ecm_db_multicast_tuple_instance_table[ti->hash_index] = ti->next;
		} else {
			ti->prev->next = ti->next;
		}

		if (ti->next) {
			ti->next->prev = ti->prev;
		}
	}

	DEBUG_CLEAR_MAGIC(ti);
	kfree(ti);

	return 0;
}
#endif

/*
 * ecm_db_connection_deref()
 *	Release reference to connection.  Connection is removed from database on final deref and destroyed.
 */
int ecm_db_connection_deref(struct ecm_db_connection_instance *ci)
{
#ifdef ECM_DB_CTA_TRACK_ENABLE
	ecm_classifier_type_t ca_type;
#endif
	int32_t i;

	DEBUG_CHECK_MAGIC(ci, ECM_DB_CONNECTION_INSTANCE_MAGIC, "%p: magic failed", ci);

	spin_lock_bh(&ecm_db_lock);
	ci->refs--;
	DEBUG_TRACE("%p: connection deref %d\n", ci, ci->refs);
	DEBUG_ASSERT(ci->refs >= 0, "%p: ref wrap\n", ci);

	if (ci->refs > 0) {
		int refs = ci->refs;
		spin_unlock_bh(&ecm_db_lock);
		return refs;
	}

#ifdef ECM_MULTICAST_ENABLE
	/*
	 * For multicast connections, we need to deref the
	 * associated tuple instance as well
	 */
	if (ci->ti) {
		_ecm_db_multicast_tuple_instance_deref(ci->ti);
	}
#endif
	/*
	 * Remove from database if inserted
	 */
	if (!ci->flags & ECM_DB_CONNECTION_FLAGS_INSERTED) {
		spin_unlock_bh(&ecm_db_lock);
	} else {
		struct ecm_db_listener_instance *li;
#ifdef ECM_DB_XREF_ENABLE
		struct ecm_db_iface_instance *iface_from;
		struct ecm_db_iface_instance *iface_to;
		struct ecm_db_iface_instance *iface_nat_from;
		struct ecm_db_iface_instance *iface_nat_to;
#endif

		/*
		 * Remove it from the connection hash table
		 */
		if (!ci->hash_prev) {
			DEBUG_ASSERT(ecm_db_connection_table[ci->hash_index] == ci, "%p: hash table bad\n", ci);
			ecm_db_connection_table[ci->hash_index] = ci->hash_next;
		} else {
			ci->hash_prev->hash_next = ci->hash_next;
		}
		if (ci->hash_next) {
			ci->hash_next->hash_prev = ci->hash_prev;
		}
		ecm_db_connection_table_lengths[ci->hash_index]--;
		DEBUG_ASSERT(ecm_db_connection_table_lengths[ci->hash_index] >= 0, "%p: invalid table len %d\n", ci, ecm_db_connection_table_lengths[ci->hash_index]);

		/*
		 * Remove it from the connection serial hash table
		 */
		if (!ci->serial_hash_prev) {
			DEBUG_ASSERT(ecm_db_connection_serial_table[ci->serial_hash_index] == ci, "%p: hash table bad\n", ci);
			ecm_db_connection_serial_table[ci->serial_hash_index] = ci->serial_hash_next;
		} else {
			ci->serial_hash_prev->serial_hash_next = ci->serial_hash_next;
		}
		if (ci->serial_hash_next) {
			ci->serial_hash_next->serial_hash_prev = ci->serial_hash_prev;
		}
		ecm_db_connection_serial_table_lengths[ci->serial_hash_index]--;
		DEBUG_ASSERT(ecm_db_connection_serial_table_lengths[ci->serial_hash_index] >= 0, "%p: invalid table len %d\n", ci, ecm_db_connection_serial_table_lengths[ci->serial_hash_index]);

		/*
		 * Remove from the global list
		 */
		if (!ci->prev) {
			DEBUG_ASSERT(ecm_db_connections == ci, "%p: conn table bad\n", ci);
			ecm_db_connections = ci->next;
		} else {
			ci->prev->next = ci->next;
		}
		if (ci->next) {
			ci->next->prev = ci->prev;
		}

#ifdef ECM_DB_XREF_ENABLE
		/*
		 * Remove connection from the "from" mapping connection list
		 */
		if (!ci->from_prev) {
			DEBUG_ASSERT(ci->mapping_from->from_connections == ci, "%p: from conn table bad\n", ci);
			ci->mapping_from->from_connections = ci->from_next;
		} else {
			ci->from_prev->from_next = ci->from_next;
		}
		if (ci->from_next) {
			ci->from_next->from_prev = ci->from_prev;
		}

		/*
		 * Remove connection from the "to" mapping connection list
		 */
		if (!ci->to_prev) {
			DEBUG_ASSERT(ci->mapping_to->to_connections == ci, "%p: to conn table bad\n", ci);
			ci->mapping_to->to_connections = ci->to_next;
		} else {
			ci->to_prev->to_next = ci->to_next;
		}
		if (ci->to_next) {
			ci->to_next->to_prev = ci->to_prev;
		}

		/*
		 * Remove connection from the "from" NAT mapping connection list
		 */
		if (!ci->from_nat_prev) {
			DEBUG_ASSERT(ci->mapping_nat_from->from_nat_connections == ci, "%p: nat from conn table bad\n", ci);
			ci->mapping_nat_from->from_nat_connections = ci->from_nat_next;
		} else {
			ci->from_nat_prev->from_nat_next = ci->from_nat_next;
		}
		if (ci->from_nat_next) {
			ci->from_nat_next->from_nat_prev = ci->from_nat_prev;
		}

		/*
		 * Remove connection from the "to" NAT mapping connection list
		 */
		if (!ci->to_nat_prev) {
			DEBUG_ASSERT(ci->mapping_nat_to->to_nat_connections == ci, "%p: nat to conn table bad\n", ci);
			ci->mapping_nat_to->to_nat_connections = ci->to_nat_next;
		} else {
			ci->to_nat_prev->to_nat_next = ci->to_nat_next;
		}
		if (ci->to_nat_next) {
			ci->to_nat_next->to_nat_prev = ci->to_nat_prev;
		}

		/*
		 * Remove connection from the "from" iface connection list
		 * GGG TODO Deprecated. Interface lists will be used instead.  To be deleted.
		 */
		iface_from = ci->from_node->iface;
		if (!ci->iface_from_prev) {
			DEBUG_ASSERT(iface_from->from_connections == ci, "%p: iface from conn table bad\n", ci);
			iface_from->from_connections = ci->iface_from_next;
		} else {
			ci->iface_from_prev->iface_from_next = ci->iface_from_next;
		}
		if (ci->iface_from_next) {
			ci->iface_from_next->iface_from_prev = ci->iface_from_prev;
		}

		/*
		 * Remove connection from the "to" iface connection list
		 * GGG TODO Deprecated. Interface lists will be used instead.  To be deleted.
		 */
		iface_to = ci->to_node->iface;
		if (!ci->iface_to_prev) {
			DEBUG_ASSERT(iface_to->to_connections == ci, "%p: to conn table bad\n", ci);
			iface_to->to_connections = ci->iface_to_next;
		} else {
			ci->iface_to_prev->iface_to_next = ci->iface_to_next;
		}
		if (ci->iface_to_next) {
			ci->iface_to_next->iface_to_prev = ci->iface_to_prev;
		}

		/*
		 * Remove connection from the "from" NAT iface connection list
		 * GGG TODO Deprecated. Interface lists will be used instead.  To be deleted.
		 */
		iface_nat_from = ci->from_nat_node->iface;
		if (!ci->iface_from_nat_prev) {
			DEBUG_ASSERT(iface_nat_from->from_nat_connections == ci, "%p: nat from conn table bad\n", ci);
			iface_nat_from->from_nat_connections = ci->iface_from_nat_next;
		} else {
			ci->iface_from_nat_prev->iface_from_nat_next = ci->iface_from_nat_next;
		}
		if (ci->iface_from_nat_next) {
			ci->iface_from_nat_next->iface_from_nat_prev = ci->iface_from_nat_prev;
		}

		/*
		 * Remove connection from the "to" NAT iface connection list
		 * GGG TODO Deprecated. Interface lists will be used instead.  To be deleted.
		 */
		iface_nat_to = ci->to_nat_node->iface;
		if (!ci->iface_to_nat_prev) {
			DEBUG_ASSERT(iface_nat_to->to_nat_connections == ci, "%p: nat to conn table bad\n", ci);
			iface_nat_to->to_nat_connections = ci->iface_to_nat_next;
		} else {
			ci->iface_to_nat_prev->iface_to_nat_next = ci->iface_to_nat_next;
		}
		if (ci->iface_to_nat_next) {
			ci->iface_to_nat_next->iface_to_nat_prev = ci->iface_to_nat_prev;
		}

		/*
		 * Remove connection from its "from node" node connection list
		 */
		if (!ci->node_from_prev) {
			DEBUG_ASSERT(ci->from_node->from_connections == ci, "%p: from node conn table bad, got: %p\n", ci, ci->from_node->from_connections);
			ci->from_node->from_connections = ci->node_from_next;
		} else {
			ci->node_from_prev->node_from_next = ci->node_from_next;
		}
		if (ci->node_from_next) {
			ci->node_from_next->node_from_prev = ci->node_from_prev;
		}
		ci->from_node->from_connections_count--;
		DEBUG_ASSERT(ci->from_node->from_connections_count >= 0, "%p: bad count\n", ci);

		/*
		 * Remove connection from its "to node" node connection list
		 */
		if (!ci->node_to_prev) {
			DEBUG_ASSERT(ci->to_node->to_connections == ci, "%p: to node conn table bad, got: %p\n", ci, ci->to_node->to_connections);
			ci->to_node->to_connections = ci->node_to_next;
		} else {
			ci->node_to_prev->node_to_next = ci->node_to_next;
		}
		if (ci->node_to_next) {
			ci->node_to_next->node_to_prev = ci->node_to_prev;
		}
		ci->to_node->to_connections_count--;
		DEBUG_ASSERT(ci->to_node->to_connections_count >= 0, "%p: bad count\n", ci);

		/*
		 * Remove connection from its "from nat node" node connection list
		 */
		if (!ci->node_from_nat_prev) {
			DEBUG_ASSERT(ci->from_nat_node->from_nat_connections == ci, "%p: from nat node conn table bad, got: %p\n", ci, ci->from_nat_node->from_nat_connections);
			ci->from_nat_node->from_nat_connections = ci->node_from_nat_next;
		} else {
			ci->node_from_nat_prev->node_from_nat_next = ci->node_from_nat_next;
		}
		if (ci->node_from_nat_next) {
			ci->node_from_nat_next->node_from_nat_prev = ci->node_from_nat_prev;
		}
		ci->from_nat_node->from_nat_connections_count--;
		DEBUG_ASSERT(ci->from_nat_node->from_nat_connections_count >= 0, "%p: bad count\n", ci);

		/*
		 * Remove connection from its "to nat node" node connection list
		 */
		if (!ci->node_to_nat_prev) {
			DEBUG_ASSERT(ci->to_nat_node->to_nat_connections == ci, "%p: to nat node conn table bad, got: %p\n", ci, ci->to_nat_node->to_nat_connections);
			ci->to_nat_node->to_nat_connections = ci->node_to_nat_next;
		} else {
			ci->node_to_nat_prev->node_to_nat_next = ci->node_to_nat_next;
		}
		if (ci->node_to_nat_next) {
			ci->node_to_nat_next->node_to_nat_prev = ci->node_to_nat_prev;
		}
		ci->to_nat_node->to_nat_connections_count--;
		DEBUG_ASSERT(ci->to_nat_node->to_nat_connections_count >= 0, "%p: bad count\n", ci);
#endif

		/*
		 * Update the counters in the mappings
		 */
		if (ci->protocol == IPPROTO_UDP) {
			ci->mapping_from->udp_from--;
			ci->mapping_to->udp_to--;
			ci->mapping_nat_from->udp_nat_from--;
			ci->mapping_nat_to->udp_nat_to--;
		} else if (ci->protocol == IPPROTO_TCP) {
			ci->mapping_from->tcp_from--;
			ci->mapping_to->tcp_to--;
			ci->mapping_nat_from->tcp_nat_from--;
			ci->mapping_nat_to->tcp_nat_to--;
		}

		ci->mapping_from->from--;
		ci->mapping_to->to--;
		ci->mapping_nat_from->nat_from--;
		ci->mapping_nat_to->nat_to--;

		/*
		 * Assert that the defunt timer has been detached
		 */
		DEBUG_ASSERT(ci->defunct_timer.group == ECM_DB_TIMER_GROUPS_MAX, "%p: unexpected timer group %d\n", ci, ci->defunct_timer.group);

		/*
		 * Decrement protocol counter stats
		 */
		ecm_db_connection_count_by_protocol[ci->protocol]--;
		DEBUG_ASSERT(ecm_db_connection_count_by_protocol[ci->protocol] >= 0, "%p: Invalid protocol count %d\n", ci, ecm_db_connection_count_by_protocol[ci->protocol]);

		spin_unlock_bh(&ecm_db_lock);

		/*
		 * Throw removed event to listeners
		 */
		DEBUG_TRACE("%p: Throw connection removed event\n", ci);
		li = ecm_db_listeners_get_and_ref_first();
		while (li) {
			struct ecm_db_listener_instance *lin;
			if (li->connection_removed) {
				li->connection_removed(li->arg, ci);
			}

			/*
			 * Get next listener
			 */
			lin = ecm_db_listener_get_and_ref_next(li);
			ecm_db_listener_deref(li);
			li = lin;
		}
	}

#ifdef ECM_DB_CTA_TRACK_ENABLE
	/*
	 * Unlink from the "assignments by classifier type" lists.
	 *
	 * This is done whether the connection is inserted into the database or not - this is because
	 * classifier assignments take place before adding into the db.
	 *
	 * NOTE: We know that the ci is not being iterated in any of these lists because otherwise
	 * ci would be being held as part of iteration and so we would not be here!
	 * Equally we know that if the assignments_by_type[] element is non-null then it must also be in the relevant list too.
	 *
	 * Default classifier is not in the classifier type assignement list, so we should start the loop index
	 * with the first assigned classifier type.
	 */
	spin_lock_bh(&ecm_db_lock);
	for (ca_type = ECM_CLASSIFIER_TYPE_DEFAULT + 1; ca_type < ECM_CLASSIFIER_TYPES; ++ca_type) {
		struct ecm_classifier_instance *cci = ci->assignments_by_type[ca_type];
		if (!cci) {
			/*
			 * No assignment of this type, so would not be in the classifier type assignments list
			 */
			continue;
		}
		_ecm_db_connection_classifier_unassign(ci, cci, ca_type);
	}
	spin_unlock_bh(&ecm_db_lock);
#endif

	/*
	 * Throw final event
	 */
	if (ci->final) {
		ci->final(ci->arg);
	}

	/*
	 * Release instances to the objects referenced by the connection
	 */
	while (ci->assignments) {
		struct ecm_classifier_instance *classi = ci->assignments;
		ci->assignments = classi->ca_next;
		classi->deref(classi);
	}

	if (ci->mapping_from) {
		ecm_db_mapping_deref(ci->mapping_from);
	}
	if (ci->mapping_to) {
		ecm_db_mapping_deref(ci->mapping_to);
	}
	if (ci->mapping_nat_from) {
		ecm_db_mapping_deref(ci->mapping_nat_from);
	}
	if (ci->mapping_nat_to) {
		ecm_db_mapping_deref(ci->mapping_nat_to);
	}
	if (ci->feci) {
		ci->feci->deref(ci->feci);
	}
	if (ci->from_node) {
		ecm_db_node_deref(ci->from_node);
	}
	if (ci->to_node) {
		ecm_db_node_deref(ci->to_node);
	}
	if (ci->from_nat_node) {
		ecm_db_node_deref(ci->from_nat_node);
	}
	if (ci->to_nat_node) {
		ecm_db_node_deref(ci->to_nat_node);
	}

	/*
	 * Remove references to the interfaces in our heirarchy lists
	 */
	for (i = ci->from_interface_first; i < ECM_DB_IFACE_HEIRARCHY_MAX; ++i) {
		DEBUG_TRACE("%p: from interface %d remove: %p\n", ci, i, ci->from_interfaces[i]);
		ecm_db_iface_deref(ci->from_interfaces[i]);
	}
	for (i = ci->to_interface_first; i < ECM_DB_IFACE_HEIRARCHY_MAX; ++i) {
		DEBUG_TRACE("%p: to interface %d remove: %p\n", ci, i, ci->to_interfaces[i]);
		ecm_db_iface_deref(ci->to_interfaces[i]);
	}
	for (i = ci->from_nat_interface_first; i < ECM_DB_IFACE_HEIRARCHY_MAX; ++i) {
		DEBUG_TRACE("%p: from nat interface %d remove: %p\n", ci, i, ci->from_nat_interfaces[i]);
		ecm_db_iface_deref(ci->from_nat_interfaces[i]);
	}
	for (i = ci->to_nat_interface_first; i < ECM_DB_IFACE_HEIRARCHY_MAX; ++i) {
		DEBUG_TRACE("%p: to nat interface %d remove: %p\n", ci, i, ci->to_nat_interfaces[i]);
		ecm_db_iface_deref(ci->to_nat_interfaces[i]);
	}

#ifdef ECM_MULTICAST_ENABLE
	/*
	 * Remove references to the multicast interfaces of this connection.
	 */
	ecm_db_multicast_connection_to_interfaces_clear(ci);
#endif
	/*
	 * We can now destroy the instance
	 */
	DEBUG_CLEAR_MAGIC(ci);
	kfree(ci);

	/*
	 * Decrease global connection count
	 */
	spin_lock_bh(&ecm_db_lock);
	ecm_db_connection_count--;
	DEBUG_ASSERT(ecm_db_connection_count >= 0, "%p: connection count wrap\n", ci);
	spin_unlock_bh(&ecm_db_lock);

	return 0;
}
EXPORT_SYMBOL(ecm_db_connection_deref);

/*
 * ecm_db_mapping_deref()
 *	Release ref to mapping, possibly removing it from the database and destroying it.
 */
int ecm_db_mapping_deref(struct ecm_db_mapping_instance *mi)
{
	DEBUG_CHECK_MAGIC(mi, ECM_DB_MAPPING_INSTANCE_MAGIC, "%p: magic failed\n", mi);

	spin_lock_bh(&ecm_db_lock);
	mi->refs--;
	DEBUG_TRACE("%p: mapping deref %d\n", mi, mi->refs);
	DEBUG_ASSERT(mi->refs >= 0, "%p: ref wrap\n", mi);

	if (mi->refs > 0) {
		int refs = mi->refs;
		spin_unlock_bh(&ecm_db_lock);
		return refs;
	}

	DEBUG_ASSERT(!mi->tcp_from && !mi->udp_from && !mi->from, "%p: from not zero: %d, %d, %d\n",
			mi, mi->tcp_from, mi->udp_from, mi->from);
	DEBUG_ASSERT(!mi->tcp_to && !mi->udp_to && !mi->to, "%p: to not zero: %d, %d, %d\n",
			mi, mi->tcp_to, mi->udp_to, mi->to);
	DEBUG_ASSERT(!mi->tcp_nat_from && !mi->udp_nat_from && !mi->nat_from, "%p: nat_from not zero: %d, %d, %d\n",
			mi, mi->tcp_nat_from, mi->udp_nat_from, mi->nat_from);
	DEBUG_ASSERT(!mi->tcp_nat_to && !mi->udp_nat_to && !mi->nat_to, "%p: nat_to not zero: %d, %d, %d\n",
			mi, mi->tcp_nat_to, mi->udp_nat_to, mi->nat_to);

#ifdef ECM_DB_XREF_ENABLE
	DEBUG_ASSERT(!mi->from_connections, "%p: from not null: %p\n", mi, mi->from_connections);
	DEBUG_ASSERT(!mi->to_connections, "%p: to not null: %p\n", mi, mi->to_connections);
	DEBUG_ASSERT(!mi->from_nat_connections, "%p: nat_from not null: %p\n", mi, mi->from_nat_connections);
	DEBUG_ASSERT(!mi->to_nat_connections, "%p: nat_to not null: %p\n", mi, mi->to_nat_connections);
#endif

	/*
	 * Remove from database if inserted
	 */
	if (!mi->flags & ECM_DB_MAPPING_FLAGS_INSERTED) {
		spin_unlock_bh(&ecm_db_lock);
	} else {
		struct ecm_db_listener_instance *li;

		/*
		 * Remove from the global list
		 */
		if (!mi->prev) {
			DEBUG_ASSERT(ecm_db_mappings == mi, "%p: mapping table bad\n", mi);
			ecm_db_mappings = mi->next;
		} else {
			mi->prev->next = mi->next;
		}
		if (mi->next) {
			mi->next->prev = mi->prev;
		}

		/*
		 * Unlink it from the mapping hash table
		 */
		if (!mi->hash_prev) {
			DEBUG_ASSERT(ecm_db_mapping_table[mi->hash_index] == mi, "%p: hash table bad\n", mi);
			ecm_db_mapping_table[mi->hash_index] = mi->hash_next;
		} else {
			mi->hash_prev->hash_next = mi->hash_next;
		}
		if (mi->hash_next) {
			mi->hash_next->hash_prev = mi->hash_prev;
		}
		mi->hash_next = NULL;
		mi->hash_prev = NULL;
		ecm_db_mapping_table_lengths[mi->hash_index]--;
		DEBUG_ASSERT(ecm_db_mapping_table_lengths[mi->hash_index] >= 0, "%p: invalid table len %d\n", mi, ecm_db_mapping_table_lengths[mi->hash_index]);

#ifdef ECM_DB_XREF_ENABLE
		/*
		 * Unlink it from the host mapping list
		 */
		if (!mi->mapping_prev) {
			DEBUG_ASSERT(mi->host->mappings == mi, "%p: mapping table bad\n", mi);
			mi->host->mappings = mi->mapping_next;
		} else {
			mi->mapping_prev->mapping_next = mi->mapping_next;
		}
		if (mi->mapping_next) {
			mi->mapping_next->mapping_prev = mi->mapping_prev;
		}
		mi->mapping_next = NULL;
		mi->mapping_prev = NULL;

		mi->host->mapping_count--;
#endif
		spin_unlock_bh(&ecm_db_lock);

		/*
		 * Throw removed event to listeners
		 */
		DEBUG_TRACE("%p: Throw mapping removed event\n", mi);
		li = ecm_db_listeners_get_and_ref_first();
		while (li) {
			struct ecm_db_listener_instance *lin;
			if (li->mapping_removed) {
				li->mapping_removed(li->arg, mi);
			}

			/*
			 * Get next listener
			 */
			lin = ecm_db_listener_get_and_ref_next(li);
			ecm_db_listener_deref(li);
			li = lin;
		}
	}

	/*
	 * Throw final event
	 */
	if (mi->final) {
		mi->final(mi->arg);
	}

	/*
	 * Now release the host instance if the mapping had one
	 */
	if (mi->host) {
		ecm_db_host_deref(mi->host);
	}

	/*
	 * We can now destroy the instance
	 */
	DEBUG_CLEAR_MAGIC(mi);
	kfree(mi);

	/*
	 * Decrease global mapping count
	 */
	spin_lock_bh(&ecm_db_lock);
	ecm_db_mapping_count--;
	DEBUG_ASSERT(ecm_db_mapping_count >= 0, "%p: mapping count wrap\n", mi);
	spin_unlock_bh(&ecm_db_lock);

	return 0;
}
EXPORT_SYMBOL(ecm_db_mapping_deref);

/*
 * ecm_db_host_deref()
 *	Release a ref to a host instance, possibly causing removal from the database and destruction of the instance
 */
int ecm_db_host_deref(struct ecm_db_host_instance *hi)
{
	DEBUG_CHECK_MAGIC(hi, ECM_DB_HOST_INSTANCE_MAGIC, "%p: magic failed\n", hi);

	spin_lock_bh(&ecm_db_lock);
	hi->refs--;
	DEBUG_TRACE("%p: host deref %d\n", hi, hi->refs);
	DEBUG_ASSERT(hi->refs >= 0, "%p: ref wrap\n", hi);

	if (hi->refs > 0) {
		int refs = hi->refs;
		spin_unlock_bh(&ecm_db_lock);
		return refs;
	}

#ifdef ECM_DB_XREF_ENABLE
	DEBUG_ASSERT((hi->mappings == NULL) && (hi->mapping_count == 0), "%p: mappings not null\n", hi);
#endif

	/*
	 * Remove from database if inserted
	 */
	if (!hi->flags & ECM_DB_HOST_FLAGS_INSERTED) {
		spin_unlock_bh(&ecm_db_lock);
	} else {
		struct ecm_db_listener_instance *li;

		/*
		 * Remove from the global list
		 */
		if (!hi->prev) {
			DEBUG_ASSERT(ecm_db_hosts == hi, "%p: host table bad\n", hi);
			ecm_db_hosts = hi->next;
		} else {
			hi->prev->next = hi->next;
		}
		if (hi->next) {
			hi->next->prev = hi->prev;
		}

		/*
		 * Unlink it from the host hash table
		 */
		if (!hi->hash_prev) {
			DEBUG_ASSERT(ecm_db_host_table[hi->hash_index] == hi, "%p: hash table bad\n", hi);
			ecm_db_host_table[hi->hash_index] = hi->hash_next;
		} else {
			hi->hash_prev->hash_next = hi->hash_next;
		}
		if (hi->hash_next) {
			hi->hash_next->hash_prev = hi->hash_prev;
		}
		hi->hash_next = NULL;
		hi->hash_prev = NULL;
		ecm_db_host_table_lengths[hi->hash_index]--;
		DEBUG_ASSERT(ecm_db_host_table_lengths[hi->hash_index] >= 0, "%p: invalid table len %d\n", hi, ecm_db_host_table_lengths[hi->hash_index]);

		spin_unlock_bh(&ecm_db_lock);

		/*
		 * Throw removed event to listeners
		 */
		DEBUG_TRACE("%p: Throw host removed event\n", hi);
		li = ecm_db_listeners_get_and_ref_first();
		while (li) {
			struct ecm_db_listener_instance *lin;
			if (li->host_removed) {
				li->host_removed(li->arg, hi);
			}

			/*
			 * Get next listener
			 */
			lin = ecm_db_listener_get_and_ref_next(li);
			ecm_db_listener_deref(li);
			li = lin;
		}
	}

	/*
	 * Throw final event
	 */
	if (hi->final) {
		hi->final(hi->arg);
	}

	/*
	 * We can now destroy the instance
	 */
	DEBUG_CLEAR_MAGIC(hi);
	kfree(hi);

	/*
	 * Decrease global host count
	 */
	spin_lock_bh(&ecm_db_lock);
	ecm_db_host_count--;
	DEBUG_ASSERT(ecm_db_host_count >= 0, "%p: host count wrap\n", hi);
	spin_unlock_bh(&ecm_db_lock);

	return 0;
}
EXPORT_SYMBOL(ecm_db_host_deref);

/*
 * ecm_db_node_deref()
 *	Deref a node.  Removing it on the last ref and destroying it.
 */
int ecm_db_node_deref(struct ecm_db_node_instance *ni)
{
	DEBUG_CHECK_MAGIC(ni, ECM_DB_NODE_INSTANCE_MAGIC, "%p: magic failed\n", ni);

	spin_lock_bh(&ecm_db_lock);
	ni->refs--;
	DEBUG_TRACE("%p: node deref %d\n", ni, ni->refs);
	DEBUG_ASSERT(ni->refs >= 0, "%p: ref wrap\n", ni);

	if (ni->refs > 0) {
		int refs = ni->refs;
		spin_unlock_bh(&ecm_db_lock);
		return refs;
	}

#ifdef ECM_DB_XREF_ENABLE
	DEBUG_ASSERT((ni->from_connections == NULL) && (ni->from_connections_count == 0), "%p: from_connections not null\n", ni);
	DEBUG_ASSERT((ni->to_connections == NULL) && (ni->to_connections_count == 0), "%p: to_connections not null\n", ni);
	DEBUG_ASSERT((ni->from_nat_connections == NULL) && (ni->from_nat_connections_count == 0), "%p: from_nat_connections not null\n", ni);
	DEBUG_ASSERT((ni->to_nat_connections == NULL) && (ni->to_nat_connections_count == 0), "%p: to_nat_connections not null\n", ni);
#endif

	/*
	 * Remove from database if inserted
	 */
	if (!ni->flags & ECM_DB_NODE_FLAGS_INSERTED) {
		spin_unlock_bh(&ecm_db_lock);
	} else {
		struct ecm_db_listener_instance *li;

		/*
		 * Remove from the global list
		 */
		if (!ni->prev) {
			DEBUG_ASSERT(ecm_db_nodes == ni, "%p: node table bad\n", ni);
			ecm_db_nodes = ni->next;
		} else {
			ni->prev->next = ni->next;
		}
		if (ni->next) {
			ni->next->prev = ni->prev;
		}

		/*
		 * Link out of hash table
		 */
		if (!ni->hash_prev) {
			DEBUG_ASSERT(ecm_db_node_table[ni->hash_index] == ni, "%p: hash table bad\n", ni);
			ecm_db_node_table[ni->hash_index] = ni->hash_next;
		} else {
			ni->hash_prev->hash_next = ni->hash_next;
		}
		if (ni->hash_next) {
			ni->hash_next->hash_prev = ni->hash_prev;
		}
		ni->hash_next = NULL;
		ni->hash_prev = NULL;
		ecm_db_node_table_lengths[ni->hash_index]--;
		DEBUG_ASSERT(ecm_db_node_table_lengths[ni->hash_index] >= 0, "%p: invalid table len %d\n", ni, ecm_db_node_table_lengths[ni->hash_index]);

#ifdef ECM_DB_XREF_ENABLE
		/*
		 * Unlink it from the iface node list
		 */
		if (!ni->node_prev) {
			DEBUG_ASSERT(ni->iface->nodes == ni, "%p: nodes table bad\n", ni);
			ni->iface->nodes = ni->node_next;
		} else {
			ni->node_prev->node_next = ni->node_next;
		}
		if (ni->node_next) {
			ni->node_next->node_prev = ni->node_prev;
		}
		ni->node_next = NULL;
		ni->node_prev = NULL;
		ni->iface->node_count--;
#endif

		spin_unlock_bh(&ecm_db_lock);

		/*
		 * Throw removed event to listeners
		 */
		DEBUG_TRACE("%p: Throw node removed event\n", ni);
		li = ecm_db_listeners_get_and_ref_first();
		while (li) {
			struct ecm_db_listener_instance *lin;
			if (li->node_removed) {
				li->node_removed(li->arg, ni);
			}

			/*
			 * Get next listener
			 */
			lin = ecm_db_listener_get_and_ref_next(li);
			ecm_db_listener_deref(li);
			li = lin;
		}
	}

	/*
	 * Throw final event
	 */
	if (ni->final) {
		ni->final(ni->arg);
	}

	/*
	 * Now release the iface instance if the node had one
	 */
	if (ni->iface) {
		ecm_db_iface_deref(ni->iface);
	}

	/*
	 * We can now destroy the instance
	 */
	DEBUG_CLEAR_MAGIC(ni);
	kfree(ni);

	/*
	 * Decrease global node count
	 */
	spin_lock_bh(&ecm_db_lock);
	ecm_db_node_count--;
	DEBUG_ASSERT(ecm_db_node_count >= 0, "%p: node count wrap\n", ni);
	spin_unlock_bh(&ecm_db_lock);

	return 0;
}
EXPORT_SYMBOL(ecm_db_node_deref);

/*
 * ecm_db_iface_deref()
 *	Deref a interface instance, removing it from the database on the last ref release
 */
int ecm_db_iface_deref(struct ecm_db_iface_instance *ii)
{
	DEBUG_CHECK_MAGIC(ii, ECM_DB_IFACE_INSTANCE_MAGIC, "%p: magic failed\n", ii);

	/*
	 * Decrement reference count
	 */
	spin_lock_bh(&ecm_db_lock);
	ii->refs--;
	DEBUG_TRACE("%p: iface deref %d\n", ii, ii->refs);
	DEBUG_ASSERT(ii->refs >= 0, "%p: ref wrap\n", ii);

	if (ii->refs > 0) {
		int refs = ii->refs;
		spin_unlock_bh(&ecm_db_lock);
		return refs;
	}

#ifdef ECM_DB_XREF_ENABLE
	DEBUG_ASSERT((ii->nodes == NULL) && (ii->node_count == 0), "%p: nodes not null\n", ii);
#endif

	/*
	 * Remove from database if inserted
	 */
	if (!ii->flags & ECM_DB_IFACE_FLAGS_INSERTED) {
		spin_unlock_bh(&ecm_db_lock);
	} else {
		struct ecm_db_listener_instance *li;

		/*
		 * Remove from the global list
		 */
		if (!ii->prev) {
			DEBUG_ASSERT(ecm_db_interfaces == ii, "%p: interface table bad\n", ii);
			ecm_db_interfaces = ii->next;
		} else {
			ii->prev->next = ii->next;
		}
		if (ii->next) {
			ii->next->prev = ii->prev;
		}

		/*
		 * Link out of hash table
		 */
		if (!ii->hash_prev) {
			DEBUG_ASSERT(ecm_db_iface_table[ii->hash_index] == ii, "%p: hash table bad got %p for hash index %u\n", ii, ecm_db_iface_table[ii->hash_index], ii->hash_index);
			ecm_db_iface_table[ii->hash_index] = ii->hash_next;
		} else {
			ii->hash_prev->hash_next = ii->hash_next;
		}
		if (ii->hash_next) {
			ii->hash_next->hash_prev = ii->hash_prev;
		}
		ii->hash_next = NULL;
		ii->hash_prev = NULL;
		ecm_db_iface_table_lengths[ii->hash_index]--;
		DEBUG_ASSERT(ecm_db_iface_table_lengths[ii->hash_index] >= 0, "%p: invalid table len %d\n", ii, ecm_db_iface_table_lengths[ii->hash_index]);

		/*
		 * Link out of interface identifier hash table
		 */
		if (!ii->iface_id_hash_prev) {
			DEBUG_ASSERT(ecm_db_iface_id_table[ii->iface_id_hash_index] == ii, "%p: hash table bad got %p for hash index %u\n", ii, ecm_db_iface_id_table[ii->iface_id_hash_index], ii->iface_id_hash_index);
			ecm_db_iface_id_table[ii->iface_id_hash_index] = ii->iface_id_hash_next;
		} else {
			ii->iface_id_hash_prev->iface_id_hash_next = ii->iface_id_hash_next;
		}
		if (ii->iface_id_hash_next) {
			ii->iface_id_hash_next->iface_id_hash_prev = ii->iface_id_hash_prev;
		}
		ii->iface_id_hash_next = NULL;
		ii->iface_id_hash_prev = NULL;
		ecm_db_iface_id_table_lengths[ii->iface_id_hash_index]--;
		DEBUG_ASSERT(ecm_db_iface_id_table_lengths[ii->iface_id_hash_index] >= 0, "%p: invalid table len %d\n", ii, ecm_db_iface_id_table_lengths[ii->iface_id_hash_index]);
		spin_unlock_bh(&ecm_db_lock);

		/*
		 * Throw removed event to listeners
		 */
		DEBUG_TRACE("%p: Throw iface removed event\n", ii);
		li = ecm_db_listeners_get_and_ref_first();
		while (li) {
			struct ecm_db_listener_instance *lin;
			if (li->iface_removed) {
				li->iface_removed(li->arg, ii);
			}

			/*
			 * Get next listener
			 */
			lin = ecm_db_listener_get_and_ref_next(li);
			ecm_db_listener_deref(li);
			li = lin;
		}
	}

	/*
	 * Throw final event
	 */
	if (ii->final) {
		ii->final(ii->arg);
	}

	/*
	 * We can now destroy the instance
	 */
	DEBUG_CLEAR_MAGIC(ii);
	kfree(ii);

	/*
	 * Decrease global interface count
	 */
	spin_lock_bh(&ecm_db_lock);
	ecm_db_iface_count--;
	DEBUG_ASSERT(ecm_db_iface_count >= 0, "%p: iface count wrap\n", ii);
	spin_unlock_bh(&ecm_db_lock);

	return 0;
}
EXPORT_SYMBOL(ecm_db_iface_deref);

/*
 * ecm_db_listener_deref()
 *	Release reference to listener.
 *
 * On final reference release listener shall be removed from the database.
 */
int ecm_db_listener_deref(struct ecm_db_listener_instance *li)
{
	struct ecm_db_listener_instance *cli;
	struct ecm_db_listener_instance **cli_prev;

	DEBUG_CHECK_MAGIC(li, ECM_DB_LISTENER_INSTANCE_MAGIC, "%p: magic failed", li);

	spin_lock_bh(&ecm_db_lock);
	li->refs--;
	DEBUG_ASSERT(li->refs >= 0, "%p: ref wrap\n", li);
	if (li->refs > 0) {
		int refs;
		refs = li->refs;
		spin_unlock_bh(&ecm_db_lock);
		return refs;
	}

	/*
	 * Instance is to be removed and destroyed.
	 * Link the listener out of the listener list.
	 */
	cli = ecm_db_listeners;
	cli_prev = &ecm_db_listeners;
	while (cli) {
		if (cli == li) {
			*cli_prev = cli->next;
			break;
		}
		cli_prev = &cli->next;
		cli = cli->next;
	}
	DEBUG_ASSERT(cli, "%p: not found\n", li);
	spin_unlock_bh(&ecm_db_lock);

	/*
	 * Invoke final callback
	 */
	if (li->final) {
		li->final(li->arg);
	}
	DEBUG_CLEAR_MAGIC(li);
	kfree(li);

	/*
	 * Decrease global listener count
	 */
	spin_lock_bh(&ecm_db_lock);
	ecm_db_listeners_count--;
	DEBUG_ASSERT(ecm_db_listeners_count >= 0, "%p: listener count wrap\n", li);
	spin_unlock_bh(&ecm_db_lock);

	return 0;
}
EXPORT_SYMBOL(ecm_db_listener_deref);

/*
 * ecm_db_connection_defunct_all()
 *	Make defunct ALL connections.
 *
 * This API is typically used in shutdown situations commanded by the user.
 * NOTE: Ensure all front ends are stopped to avoid further connections being created while this is running.
 */
void ecm_db_connection_defunct_all(void)
{
	struct ecm_db_connection_instance *ci;

	DEBUG_INFO("Defuncting all\n");

	/*
	 * Iterate all connections
	 */
	ci = ecm_db_connections_get_and_ref_first();
	while (ci) {
		struct ecm_db_connection_instance *cin;

		DEBUG_TRACE("%p: defunct\n", ci);
		ecm_db_connection_make_defunct(ci);

		cin = ecm_db_connection_get_and_ref_next(ci);
		ecm_db_connection_deref(ci);
		ci = cin;
	}
	DEBUG_INFO("Defuncting complete\n");
}
EXPORT_SYMBOL(ecm_db_connection_defunct_all);

/*
 * ecm_db_connection_generate_hash_index()
 * 	Calculate the hash index.
 *
 * Note: The hash we produce is symmetric - i.e. we can swap the "from" and "to"
 * details without generating a different hash index!
 */
static inline ecm_db_connection_hash_t ecm_db_connection_generate_hash_index(ip_addr_t host1_addr, uint32_t host1_port, ip_addr_t host2_addr, uint32_t host2_port, int protocol)
{
	uint32_t hah1;
	uint32_t hah2;
	uint32_t ht1;
	uint32_t hash_val;

	/*
	 * The hash function only uses both host 1 address/port, host 2 address/port
	 * and protocol fields.
	 */
	ECM_IP_ADDR_HASH(hah1, host1_addr);
	ECM_IP_ADDR_HASH(hah2, host2_addr);
	ht1 = (u32)hah1 + host1_port + hah2 + host2_port + (uint32_t)protocol;
	hash_val = (uint32_t)jhash_1word(ht1, ecm_db_jhash_rnd);
	return (ecm_db_connection_hash_t)(hash_val & (ECM_DB_CONNECTION_HASH_SLOTS - 1));
}

/*
 * ecm_db_connection_generate_serial_hash_index()
 * 	Calculate the serial hash index.
 */
static inline ecm_db_connection_serial_hash_t ecm_db_connection_generate_serial_hash_index(uint32_t serial)
{
	uint32_t hash_val;
	hash_val = (uint32_t)jhash_1word(serial, ecm_db_jhash_rnd);

	return (ecm_db_connection_serial_hash_t)(hash_val & (ECM_DB_CONNECTION_SERIAL_HASH_SLOTS - 1));
}

#ifdef ECM_MULTICAST_ENABLE
/*
 * ecm_db_multicast_generate_hash_index()
 * 	Calculate the hash index given a multicast group address.
 */
static inline ecm_db_multicast_tuple_instance_hash_t ecm_db_multicast_generate_hash_index(ip_addr_t address)
{
	uint32_t temp;
	uint32_t hash_val;

	if (ECM_IP_ADDR_IS_V4(address)){
		temp = (uint32_t)address[0];
	} else {
		temp = (uint32_t)address[3];
	}

	hash_val = (uint32_t)jhash_1word(temp, ecm_db_jhash_rnd);

	return (ecm_db_multicast_tuple_instance_hash_t)(hash_val & (ECM_DB_MULTICAST_TUPLE_INSTANCE_HASH_SLOTS - 1));
}
#endif

/*
 * ecm_db_mapping_generate_hash_index()
 * 	Calculate the hash index.
 */
static inline ecm_db_mapping_hash_t ecm_db_mapping_generate_hash_index(ip_addr_t address, uint32_t port)
{
	uint32_t tuple;
	uint32_t hash_val;

	ECM_IP_ADDR_HASH(tuple, address);
	hash_val = (uint32_t)jhash_2words(tuple, port, ecm_db_jhash_rnd);
	return (ecm_db_mapping_hash_t)(hash_val & (ECM_DB_MAPPING_HASH_SLOTS - 1));
}

/*
 * ecm_db_host_generate_hash_index()
 * 	Calculate the hash index.
 */
static inline ecm_db_host_hash_t ecm_db_host_generate_hash_index(ip_addr_t address)
{
	uint32_t tuple;
	uint32_t hash_val;

	ECM_IP_ADDR_HASH(tuple, address);
	hash_val = (uint32_t)jhash_1word(tuple, ecm_db_jhash_rnd);
	return (ecm_db_host_hash_t)(hash_val & (ECM_DB_HOST_HASH_SLOTS - 1));
}

/*
 * ecm_db_node_generate_hash_index()
 * 	Calculate the hash index.
 */
static inline ecm_db_node_hash_t ecm_db_node_generate_hash_index(uint8_t *address)
{
	uint32_t hash_val;

	hash_val = (uint32_t)jhash(address, 6, ecm_db_jhash_rnd);
	hash_val &= (ECM_DB_NODE_HASH_SLOTS - 1);

	return (ecm_db_node_hash_t)hash_val;
}

/*
 * ecm_db_iface_id_generate_hash_index()
 *	Calculate the hash index based on interface identifier.
 */
static inline ecm_db_iface_id_hash_t ecm_db_iface_id_generate_hash_index(int32_t interface_id)
{
	uint32_t hash_val;

	hash_val = (uint32_t)jhash_1word((uint32_t)interface_id, ecm_db_jhash_rnd);
	return (ecm_db_iface_id_hash_t)(hash_val & (ECM_DB_IFACE_ID_HASH_SLOTS - 1));
}

#ifdef ECM_INTERFACE_SIT_ENABLE
/*
 * ecm_db_iface_generate_hash_index_sit()
 * 	Calculate the hash index.
 */
static inline ecm_db_iface_hash_t ecm_db_iface_generate_hash_index_sit(ip_addr_t saddr, ip_addr_t daddr)
{
	uint32_t tuple1;
	uint32_t tuple2;
	uint32_t hash_val;

	ECM_IP_ADDR_HASH(tuple1, saddr);
	ECM_IP_ADDR_HASH(tuple2, daddr);
	hash_val = (uint32_t)jhash_2words(tuple1, tuple2, ecm_db_jhash_rnd);
	return (ecm_db_iface_hash_t)(hash_val & (ECM_DB_IFACE_HASH_SLOTS - 1));
}
#endif

#ifdef ECM_INTERFACE_TUNIPIP6_ENABLE
#ifdef ECM_IPV6_ENABLE
/*
 * ecm_db_iface_generate_hash_index_tunipip6()
 * 	Calculate the hash index.
 */
static inline ecm_db_iface_hash_t ecm_db_iface_generate_hash_index_tunipip6(ip_addr_t saddr, ip_addr_t daddr)
{
	uint32_t tuple1;
	uint32_t tuple2;
	uint32_t hash_val;

	ECM_IP_ADDR_HASH(tuple1, saddr);
	ECM_IP_ADDR_HASH(tuple2, daddr);
	hash_val = (uint32_t)jhash_2words(tuple1, tuple2, ecm_db_jhash_rnd);
	return (ecm_db_iface_hash_t)(hash_val & (ECM_DB_IFACE_HASH_SLOTS - 1));
}
#endif
#endif

/*
 * ecm_db_iface_generate_hash_index_ethernet()
 * 	Calculate the hash index.
 */
static inline ecm_db_iface_hash_t ecm_db_iface_generate_hash_index_ethernet(uint8_t *address)
{
	uint32_t hash_val;
	hash_val = (uint32_t)jhash(address, 6, ecm_db_jhash_rnd);
	return (ecm_db_iface_hash_t)(hash_val & (ECM_DB_IFACE_HASH_SLOTS - 1));
}

#ifdef ECM_INTERFACE_PPPOE_ENABLE
/*
 * ecm_db_iface_generate_hash_index_pppoe()
 * 	Calculate the hash index.
 */
static inline ecm_db_iface_hash_t ecm_db_iface_generate_hash_index_pppoe(uint16_t pppoe_session_id)
{
	uint32_t hash_val;
	hash_val = (uint32_t)jhash_1word((uint32_t)pppoe_session_id, ecm_db_jhash_rnd);
	return (ecm_db_iface_hash_t)(hash_val & (ECM_DB_IFACE_HASH_SLOTS - 1));
}
#endif

#ifdef ECM_INTERFACE_L2TPV2_ENABLE
/*
 * ecm_db_iface_generate_hash_index_pppol2tpv2()
 *	Calculate the hash index.
 */
static inline ecm_db_iface_hash_t ecm_db_iface_generate_hash_index_pppol2tpv2(uint32_t pppol2tpv2_tunnel_id, uint32_t pppol2tpv2_session_id)
{
	uint32_t hash_val;
	hash_val = (uint32_t)jhash_2words(pppol2tpv2_tunnel_id, pppol2tpv2_session_id, ecm_db_jhash_rnd);
	return (ecm_db_iface_hash_t)(hash_val & (ECM_DB_IFACE_HASH_SLOTS - 1));
}

#endif

#ifdef ECM_INTERFACE_PPTP_ENABLE
/*
 * ecm_db_iface_generate_hash_index_pptp()
 *	Calculate the hash index.
 */
static inline ecm_db_iface_hash_t ecm_db_iface_generate_hash_index_pptp(uint16_t pptp_src_call_id, uint16_t pptp_dst_call_id)
{
	uint32_t hash_val;
	hash_val = (uint32_t)jhash_2words(pptp_src_call_id, pptp_dst_call_id, ecm_db_jhash_rnd);
	return (ecm_db_iface_hash_t)(hash_val & (ECM_DB_IFACE_HASH_SLOTS - 1));
}
#endif

#ifdef ECM_INTERFACE_MAP_T_ENABLE
/*
 * ecm_db_iface_generate_hash_index_map_t()
 *	Calculate the hash index.
 */
static inline ecm_db_iface_hash_t ecm_db_iface_generate_hash_index_map_t(int if_index)
{
	uint32_t hash_val;
	hash_val = (uint32_t)jhash_1word(if_index, ecm_db_jhash_rnd);
	return (ecm_db_iface_hash_t)(hash_val & (ECM_DB_IFACE_HASH_SLOTS - 1));
}
#endif

/*
 * ecm_db_iface_generate_hash_index_unknown()
 * 	Calculate the hash index.
 */
static inline ecm_db_iface_hash_t ecm_db_iface_generate_hash_index_unknown(uint32_t os_specific_ident)
{
	uint32_t hash_val;
	hash_val = (uint32_t)jhash_1word(os_specific_ident, ecm_db_jhash_rnd);
	return (ecm_db_iface_hash_t)(hash_val & (ECM_DB_IFACE_HASH_SLOTS - 1));
}

/*
 * ecm_db_iface_generate_hash_index_loopback()
 * 	Calculate the hash index.
 */
static inline ecm_db_iface_hash_t ecm_db_iface_generate_hash_index_loopback(uint32_t os_specific_ident)
{
	uint32_t hash_val;
	hash_val = (uint32_t)jhash_1word(os_specific_ident, ecm_db_jhash_rnd);
	return (ecm_db_iface_hash_t)(hash_val & (ECM_DB_IFACE_HASH_SLOTS - 1));
}

#ifdef ECM_INTERFACE_IPSEC_ENABLE
/*
 * ecm_db_iface_generate_hash_index_ipsec_tunnel()
 * 	Calculate the hash index.
 * GGG TODO Flesh this out using actual tunnel endpoint keys
 */
static inline ecm_db_iface_hash_t ecm_db_iface_generate_hash_index_ipsec_tunnel(uint32_t os_specific_ident)
{
	uint32_t hash_val;
	hash_val = (uint32_t)jhash_1word(os_specific_ident, ecm_db_jhash_rnd);
	return (ecm_db_iface_hash_t)(hash_val & (ECM_DB_IFACE_HASH_SLOTS - 1));
}
#endif

/*
 * ecm_db_host_find_and_ref()
 *	Lookup and return a host reference if any
 */
struct ecm_db_host_instance *ecm_db_host_find_and_ref(ip_addr_t address)
{
	ecm_db_host_hash_t hash_index;
	struct ecm_db_host_instance *hi;

	DEBUG_TRACE("Lookup host with addr " ECM_IP_ADDR_OCTAL_FMT "\n", ECM_IP_ADDR_TO_OCTAL(address));

	/*
	 * Compute the hash chain index and prepare to walk the chain
	 */
	hash_index = ecm_db_host_generate_hash_index(address);

	/*
	 * Iterate the chain looking for a host with matching details
	 */
	spin_lock_bh(&ecm_db_lock);
	hi = ecm_db_host_table[hash_index];
	while (hi) {
		if (!ECM_IP_ADDR_MATCH(hi->address, address)) {
			hi = hi->hash_next;
			continue;
		}

		_ecm_db_host_ref(hi);
		spin_unlock_bh(&ecm_db_lock);
		DEBUG_TRACE("host found %p\n", hi);
		return hi;
	}
	spin_unlock_bh(&ecm_db_lock);
	DEBUG_TRACE("Host not found\n");
	return NULL;
}
EXPORT_SYMBOL(ecm_db_host_find_and_ref);

/*
 * ecm_db_node_is_mac_addr_equal()
 *	Compares the node's mac address with the given mac address.
 */
bool ecm_db_node_is_mac_addr_equal(struct ecm_db_node_instance *ni, uint8_t *address)
{
	DEBUG_CHECK_MAGIC(ni, ECM_DB_NODE_INSTANCE_MAGIC, "%p: magic failed", ni);

	if (ecm_mac_addr_equal(ni->address, address)) {
		return false;
	}

	return true;
}
EXPORT_SYMBOL(ecm_db_node_is_mac_addr_equal);

/*
 * ecm_db_node_find_and_ref()
 *	Lookup and return a node reference if any
 */
struct ecm_db_node_instance *ecm_db_node_find_and_ref(uint8_t *address, struct ecm_db_iface_instance *ii)
{
	ecm_db_node_hash_t hash_index;
	struct ecm_db_node_instance *ni;

	DEBUG_TRACE("Lookup node with addr %pMi and iface %p\n", address, ii);

	/*
	 * Compute the hash chain index and prepare to walk the chain
	 */
	hash_index = ecm_db_node_generate_hash_index(address);

	/*
	 * Iterate the chain looking for a host with matching details
	 */
	spin_lock_bh(&ecm_db_lock);
	ni = ecm_db_node_table[hash_index];
	while (ni) {
		if (memcmp(ni->address, address, ETH_ALEN)) {
			ni = ni->hash_next;
			continue;
		}

		if (ni->iface != ii) {
			ni = ni->hash_next;
			continue;
		}

		_ecm_db_node_ref(ni);
		spin_unlock_bh(&ecm_db_lock);
		DEBUG_TRACE("node found %p\n", ni);
		return ni;
	}
	spin_unlock_bh(&ecm_db_lock);
	DEBUG_TRACE("Node not found\n");
	return NULL;
}
EXPORT_SYMBOL(ecm_db_node_find_and_ref);

/*
 * ecm_db_node_chain_get_and_ref_first()
 *	Gets and refs the first node in the chain of that mac address.
 */
struct ecm_db_node_instance *ecm_db_node_chain_get_and_ref_first(uint8_t *address)
{
	ecm_db_node_hash_t hash_index;
	struct ecm_db_node_instance *ni;

	DEBUG_TRACE("Get the first node with addr %pMi in the chain\n", address);

	/*
	 * Compute the hash chain index.
	 */
	hash_index = ecm_db_node_generate_hash_index(address);

	spin_lock_bh(&ecm_db_lock);
	ni = ecm_db_node_table[hash_index];
	if (ni) {
		_ecm_db_node_ref(ni);
	}
	spin_unlock_bh(&ecm_db_lock);

	return ni;
}
EXPORT_SYMBOL(ecm_db_node_chain_get_and_ref_first);

/*
 * ecm_db_node_chain_get_and_ref_next()
 *	Gets and refs the next node in the chain..
 */
struct ecm_db_node_instance *ecm_db_node_chain_get_and_ref_next(struct ecm_db_node_instance *ni)
{
	struct ecm_db_node_instance *nin;
	DEBUG_CHECK_MAGIC(ni, ECM_DB_NODE_INSTANCE_MAGIC, "%p: magic failed", ni);

	spin_lock_bh(&ecm_db_lock);
	nin = ni->hash_next;
	if (nin) {
		_ecm_db_node_ref(nin);
	}
	spin_unlock_bh(&ecm_db_lock);
	return nin;
}
EXPORT_SYMBOL(ecm_db_node_chain_get_and_ref_next);

/*
 * ecm_db_iface_ethernet_address_get()
 *	Obtain the ethernet address for an ethernet interface
 */
void ecm_db_iface_ethernet_address_get(struct ecm_db_iface_instance *ii, uint8_t *address)
{
	DEBUG_CHECK_MAGIC(ii, ECM_DB_IFACE_INSTANCE_MAGIC, "%p: magic failed", ii);
	DEBUG_ASSERT(ii->type == ECM_DB_IFACE_TYPE_ETHERNET, "%p: Bad type, expected ethernet, actual: %d\n", ii, ii->type);
	spin_lock_bh(&ecm_db_lock);
	memcpy(address, ii->type_info.ethernet.address, sizeof(ii->type_info.ethernet.address));
	spin_unlock_bh(&ecm_db_lock);
}
EXPORT_SYMBOL(ecm_db_iface_ethernet_address_get);

/*
 * ecm_db_iface_bridge_address_get()
 *	Obtain the ethernet address for a bridge interface
 */
void ecm_db_iface_bridge_address_get(struct ecm_db_iface_instance *ii, uint8_t *address)
{
	DEBUG_CHECK_MAGIC(ii, ECM_DB_IFACE_INSTANCE_MAGIC, "%p: magic failed", ii);
	DEBUG_ASSERT(ii->type == ECM_DB_IFACE_TYPE_BRIDGE, "%p: Bad type, expected bridge, actual: %d\n", ii, ii->type);
	spin_lock_bh(&ecm_db_lock);
	memcpy(address, ii->type_info.bridge.address, sizeof(ii->type_info.bridge.address));
	spin_unlock_bh(&ecm_db_lock);
}
EXPORT_SYMBOL(ecm_db_iface_bridge_address_get);

/*
 * _ecm_db_iface_identifier_hash_table_insert_entry()
 *	Calculate the hash index based on updated interface_identifier, and
 *	re-insert into interface identifier chain.
 *
 *	Note: Must take ecm_db_lock before calling this.
 */
static void _ecm_db_iface_identifier_hash_table_insert_entry(struct ecm_db_iface_instance *ii, int32_t interface_identifier)
{
	ecm_db_iface_id_hash_t iface_id_hash_index;

	/*
	 * Compute hash chain for insertion
	 */
	iface_id_hash_index = ecm_db_iface_id_generate_hash_index(interface_identifier);
	ii->iface_id_hash_index = iface_id_hash_index;

	/*
	 * Insert into interface identifier chain
	 */
	ii->iface_id_hash_next = ecm_db_iface_id_table[iface_id_hash_index];
	if (ecm_db_iface_id_table[iface_id_hash_index]) {
		ecm_db_iface_id_table[iface_id_hash_index]->iface_id_hash_prev = ii;
	}

	ecm_db_iface_id_table[iface_id_hash_index] = ii;
	ecm_db_iface_id_table_lengths[iface_id_hash_index]++;
	DEBUG_ASSERT(ecm_db_iface_id_table_lengths[iface_id_hash_index] > 0, "%p: invalid iface id table len %d\n", ii, ecm_db_iface_id_table_lengths[iface_id_hash_index]);
}

/*
 * _ecm_db_iface_identifier_hash_table_remove_entry()
 * 	Remove an entry of a given interface instance from interface identifier chain.
 *
 *	Note: Must take ecm_db_lock before calling this.
 */
static void _ecm_db_iface_identifier_hash_table_remove_entry(struct ecm_db_iface_instance *ii)
{
	/*
	 * Remove from database if inserted
	 */
	if (!ii->flags & ECM_DB_IFACE_FLAGS_INSERTED) {
		return;
	}

	/*
	 * Link out of interface identifier hash table
	 */
	if (!ii->iface_id_hash_prev) {
		DEBUG_ASSERT(ecm_db_iface_id_table[ii->iface_id_hash_index] == ii, "%p: hash table bad got %p for hash index %u\n", ii, ecm_db_iface_id_table[ii->iface_id_hash_index], ii->iface_id_hash_index);
		ecm_db_iface_id_table[ii->iface_id_hash_index] = ii->iface_id_hash_next;
	} else {
		ii->iface_id_hash_prev->iface_id_hash_next = ii->iface_id_hash_next;
	}

	if (ii->iface_id_hash_next) {
		ii->iface_id_hash_next->iface_id_hash_prev = ii->iface_id_hash_prev;
	}

	ii->iface_id_hash_next = NULL;
	ii->iface_id_hash_prev = NULL;
	ecm_db_iface_id_table_lengths[ii->iface_id_hash_index]--;
	DEBUG_ASSERT(ecm_db_iface_id_table_lengths[ii->iface_id_hash_index] >= 0, "%p: invalid table len %d\n", ii, ecm_db_iface_id_table_lengths[ii->iface_id_hash_index]);
}

/*
 * ecm_db_iface_identifier_hash_table_entry_check_and_update()
 * 	Update the hash table entry of interface identifier hash table.
 * 	First remove the 'ii' from curent hash index position, re-calculate new hash and re-insert
 * 	the 'ii' at new hash index position into interface identifier hash table.
 */
void ecm_db_iface_identifier_hash_table_entry_check_and_update(struct ecm_db_iface_instance *ii, int32_t new_interface_identifier)
{
	DEBUG_CHECK_MAGIC(ii, ECM_DB_IFACE_INSTANCE_MAGIC, "%p: magic failed", ii);
	spin_lock_bh(&ecm_db_lock);
	if (ii->interface_identifier == new_interface_identifier) {
		spin_unlock_bh(&ecm_db_lock);
		return;
	}

	DEBUG_TRACE("%p: interface ifindex has changed Old %d, New %d \n", ii, ii->interface_identifier, new_interface_identifier);
	_ecm_db_iface_identifier_hash_table_remove_entry(ii);
	ii->interface_identifier = new_interface_identifier;
	_ecm_db_iface_identifier_hash_table_insert_entry(ii, new_interface_identifier);
	spin_unlock_bh(&ecm_db_lock);
}
EXPORT_SYMBOL(ecm_db_iface_identifier_hash_table_entry_check_and_update);

/*
 * ecm_db_iface_find_and_ref_by_interface_identifier()
 *	Return an interface based on a hlos interface identifier
 */
struct ecm_db_iface_instance *ecm_db_iface_find_and_ref_by_interface_identifier(int32_t interface_id)
{
	ecm_db_iface_id_hash_t hash_index;
	struct ecm_db_iface_instance *ii;

	DEBUG_TRACE("Lookup database iface with interface_id %d\n", interface_id);

	/*
	 * Compute the hash chain index and prepare to walk the chain
	 */
	hash_index = ecm_db_iface_id_generate_hash_index(interface_id);

	/*
	 * Iterate the chain looking for a host with matching details
	 */
	spin_lock_bh(&ecm_db_lock);
	ii = ecm_db_iface_id_table[hash_index];
	while (ii) {
		if (ii->interface_identifier == interface_id) {
			_ecm_db_iface_ref(ii);
			spin_unlock_bh(&ecm_db_lock);
			DEBUG_TRACE("iface found %p\n", ii);
			return ii;
		}

		/*
		 * Try next
		 */
		ii = ii->iface_id_hash_next;
	}
	spin_unlock_bh(&ecm_db_lock);
	DEBUG_TRACE("Iface not found\n");
	return NULL;
}
EXPORT_SYMBOL(ecm_db_iface_find_and_ref_by_interface_identifier);

/*
 * ecm_db_iface_ifidx_find_and_ref_ethernet()
 *	Return an interface based on a MAC address and interface hlos interface identifier
 */
struct ecm_db_iface_instance *ecm_db_iface_ifidx_find_and_ref_ethernet(uint8_t *address, int32_t ifidx)
{
	ecm_db_iface_hash_t hash_index;
	struct ecm_db_iface_instance *ii;

	DEBUG_TRACE("Lookup ethernet iface with addr %pM\n", address);

	/*
	 * Compute the hash chain index and prepare to walk the chain
	 */
	hash_index = ecm_db_iface_generate_hash_index_ethernet(address);

	/*
	 * Iterate the chain looking for a host with matching details
	 */
	spin_lock_bh(&ecm_db_lock);
	ii = ecm_db_iface_table[hash_index];
	while (ii) {
		if ((ii->type != ECM_DB_IFACE_TYPE_ETHERNET)
		    || memcmp(ii->type_info.ethernet.address, address, ETH_ALEN)
		    || ii->interface_identifier != ifidx) {
			ii = ii->hash_next;
			continue;
		}

		_ecm_db_iface_ref(ii);
		spin_unlock_bh(&ecm_db_lock);
		DEBUG_TRACE("iface found %p\n", ii);
		return ii;
	}
	spin_unlock_bh(&ecm_db_lock);
	DEBUG_TRACE("Iface not found\n");
	return NULL;
}
EXPORT_SYMBOL(ecm_db_iface_ifidx_find_and_ref_ethernet);

#ifdef ECM_INTERFACE_VLAN_ENABLE
/*
 * ecm_db_iface_vlan_info_get()
 *	Get vlan interface specific information
 */
void ecm_db_iface_vlan_info_get(struct ecm_db_iface_instance *ii, struct ecm_db_interface_info_vlan *vlan_info)
{
	DEBUG_CHECK_MAGIC(ii, ECM_DB_IFACE_INSTANCE_MAGIC, "%p: magic failed", ii);
	DEBUG_ASSERT(ii->type == ECM_DB_IFACE_TYPE_VLAN, "%p: Bad type, expected vlan, actual: %d\n", ii, ii->type);
	spin_lock_bh(&ecm_db_lock);
	memcpy(vlan_info->address, ii->type_info.vlan.address, sizeof(ii->type_info.vlan.address));
	vlan_info->vlan_tag = ii->type_info.vlan.vlan_tag;
	vlan_info->vlan_tpid = ii->type_info.vlan.vlan_tpid;
	spin_unlock_bh(&ecm_db_lock);
}
EXPORT_SYMBOL(ecm_db_iface_vlan_info_get);

/*
 * ecm_db_iface_find_and_ref_vlan()
 *	Lookup and return a iface reference if any
 */
struct ecm_db_iface_instance *ecm_db_iface_find_and_ref_vlan(uint8_t *address, uint16_t vlan_tag, uint16_t vlan_tpid)
{
	ecm_db_iface_hash_t hash_index;
	struct ecm_db_iface_instance *ii;

	DEBUG_TRACE("Lookup vlan iface with addr %pM, vlan tag: %x vlan tpid: %x\n", address, vlan_tag, vlan_tpid);

	/*
	 * Compute the hash chain index and prepare to walk the chain
	 */
	hash_index = ecm_db_iface_generate_hash_index_ethernet(address);

	/*
	 * Iterate the chain looking for a host with matching details
	 */
	spin_lock_bh(&ecm_db_lock);
	ii = ecm_db_iface_table[hash_index];
	while (ii) {
		if ((ii->type != ECM_DB_IFACE_TYPE_VLAN) || (ii->type_info.vlan.vlan_tag != vlan_tag)
				|| (ii->type_info.vlan.vlan_tpid != vlan_tpid)
				|| memcmp(ii->type_info.vlan.address, address, ETH_ALEN)) {
			ii = ii->hash_next;
			continue;
		}

		_ecm_db_iface_ref(ii);
		spin_unlock_bh(&ecm_db_lock);
		DEBUG_TRACE("iface found %p\n", ii);
		return ii;
	}
	spin_unlock_bh(&ecm_db_lock);
	DEBUG_TRACE("Iface not found\n");
	return NULL;
}
EXPORT_SYMBOL(ecm_db_iface_find_and_ref_vlan);
#endif

/*
 * ecm_db_iface_find_and_ref_bridge()
 *	Lookup and return a iface reference if any
 */
struct ecm_db_iface_instance *ecm_db_iface_find_and_ref_bridge(uint8_t *address)
{
	ecm_db_iface_hash_t hash_index;
	struct ecm_db_iface_instance *ii;

	DEBUG_TRACE("Lookup bridge iface with addr %pM\n", address);

	/*
	 * Compute the hash chain index and prepare to walk the chain
	 */
	hash_index = ecm_db_iface_generate_hash_index_ethernet(address);

	/*
	 * Iterate the chain looking for a host with matching details
	 */
	spin_lock_bh(&ecm_db_lock);
	ii = ecm_db_iface_table[hash_index];
	while (ii) {
		if ((ii->type != ECM_DB_IFACE_TYPE_BRIDGE) || memcmp(ii->type_info.bridge.address, address, ETH_ALEN)) {
			ii = ii->hash_next;
			continue;
		}

		_ecm_db_iface_ref(ii);
		spin_unlock_bh(&ecm_db_lock);
		DEBUG_TRACE("iface found %p\n", ii);
		return ii;
	}
	spin_unlock_bh(&ecm_db_lock);
	DEBUG_TRACE("Iface not found\n");
	return NULL;
}
EXPORT_SYMBOL(ecm_db_iface_find_and_ref_bridge);

#ifdef ECM_INTERFACE_BOND_ENABLE
/*
 * ecm_db_iface_find_and_ref_lag()
 *	Lookup and return a iface reference if any
 */
struct ecm_db_iface_instance *ecm_db_iface_find_and_ref_lag(uint8_t *address)
{
	ecm_db_iface_hash_t hash_index;
	struct ecm_db_iface_instance *ii;

	DEBUG_TRACE("Lookup lag iface with addr %pM\n", address);

	/*
	 * Compute the hash chain index and prepare to walk the chain
	 */
	hash_index = ecm_db_iface_generate_hash_index_ethernet(address);

	/*
	 * Iterate the chain looking for a host with matching details
	 */
	spin_lock_bh(&ecm_db_lock);
	ii = ecm_db_iface_table[hash_index];
	while (ii) {
		if ((ii->type != ECM_DB_IFACE_TYPE_LAG) || memcmp(ii->type_info.lag.address, address, ETH_ALEN)) {
			ii = ii->hash_next;
			continue;
		}

		_ecm_db_iface_ref(ii);
		spin_unlock_bh(&ecm_db_lock);
		DEBUG_TRACE("iface found %p\n", ii);
		return ii;
	}
	spin_unlock_bh(&ecm_db_lock);
	DEBUG_TRACE("Iface not found\n");
	return NULL;
}
EXPORT_SYMBOL(ecm_db_iface_find_and_ref_lag);
#endif

#ifdef ECM_INTERFACE_PPPOE_ENABLE
/*
 * ecm_db_iface_pppoe_session_info_get()
 *	Get pppoe interface specific information
 */
void ecm_db_iface_pppoe_session_info_get(struct ecm_db_iface_instance *ii, struct ecm_db_interface_info_pppoe *pppoe_info)
{
	DEBUG_CHECK_MAGIC(ii, ECM_DB_IFACE_INSTANCE_MAGIC, "%p: magic failed", ii);
	DEBUG_ASSERT(ii->type == ECM_DB_IFACE_TYPE_PPPOE, "%p: Bad type, expected pppoe, actual: %d\n", ii, ii->type);
	spin_lock_bh(&ecm_db_lock);
	memcpy(pppoe_info->remote_mac, ii->type_info.pppoe.remote_mac, sizeof(ii->type_info.pppoe.remote_mac));
	pppoe_info->pppoe_session_id = ii->type_info.pppoe.pppoe_session_id;
	spin_unlock_bh(&ecm_db_lock);
}

EXPORT_SYMBOL(ecm_db_iface_pppoe_session_info_get);

/*
 * ecm_db_iface_find_and_ref_pppoe()
 *	Lookup and return a iface reference if any
 */
struct ecm_db_iface_instance *ecm_db_iface_find_and_ref_pppoe(uint16_t pppoe_session_id, uint8_t *remote_mac)
{
	ecm_db_iface_hash_t hash_index;
	struct ecm_db_iface_instance *ii;

	DEBUG_TRACE("Lookup pppoe iface with addr %x\n", pppoe_session_id);

	/*
	 * Compute the hash chain index and prepare to walk the chain
	 */
	hash_index = ecm_db_iface_generate_hash_index_pppoe(pppoe_session_id);

	/*
	 * Iterate the chain looking for a host with matching details
	 */
	spin_lock_bh(&ecm_db_lock);
	ii = ecm_db_iface_table[hash_index];
	while (ii) {
		if ((ii->type != ECM_DB_IFACE_TYPE_PPPOE)
				|| (ii->type_info.pppoe.pppoe_session_id != pppoe_session_id)
				|| memcmp(ii->type_info.pppoe.remote_mac, remote_mac, ETH_ALEN)) {
			ii = ii->hash_next;
			continue;
		}

		_ecm_db_iface_ref(ii);
		spin_unlock_bh(&ecm_db_lock);
		DEBUG_TRACE("iface found %p\n", ii);
		return ii;
	}
	spin_unlock_bh(&ecm_db_lock);
	DEBUG_TRACE("Iface not found\n");
	return NULL;
}
EXPORT_SYMBOL(ecm_db_iface_find_and_ref_pppoe);
#endif

/*
 * ecm_db_iface_update_ae_interface_identifier()
 *	update ae_interface_identifier in iface instance.
 */
void ecm_db_iface_update_ae_interface_identifier(struct ecm_db_iface_instance *ii, int32_t ae_interface_identifier)
{
	DEBUG_CHECK_MAGIC(ii, ECM_DB_IFACE_INSTANCE_MAGIC, "%p: magic failed", ii);

	spin_lock_bh(&ecm_db_lock);
	if (ii->ae_interface_identifier == ae_interface_identifier) {
		spin_unlock_bh(&ecm_db_lock);
		return;
	}
	ii->ae_interface_identifier = ae_interface_identifier;
	spin_unlock_bh(&ecm_db_lock);
}
EXPORT_SYMBOL(ecm_db_iface_update_ae_interface_identifier);

#ifdef ECM_INTERFACE_L2TPV2_ENABLE
/*
 * ecm_db_iface_pppol2tpv2_session_info_get
 *	get l2tpv2 specific info
 */
void ecm_db_iface_pppol2tpv2_session_info_get(struct ecm_db_iface_instance *ii, struct ecm_db_interface_info_pppol2tpv2 *pppol2tpv2_info)
{
	DEBUG_CHECK_MAGIC(ii, ECM_DB_IFACE_INSTANCE_MAGIC, "%p: magic failed", ii);
	DEBUG_ASSERT(ii->type == ECM_DB_IFACE_TYPE_PPPOL2TPV2, "%p: Bad type, expected pppol2tpv2, actual: %d\n", ii, ii->type);
	spin_lock_bh(&ecm_db_lock);
	memcpy(pppol2tpv2_info, &ii->type_info.pppol2tpv2, sizeof(struct ecm_db_interface_info_pppol2tpv2));
	spin_unlock_bh(&ecm_db_lock);
}
EXPORT_SYMBOL(ecm_db_iface_pppol2tpv2_session_info_get);

/*
 * ecm_db_iface_find_and_ref_pppol2tpv2()
 *	Lookup and return a iface reference if any
 */
struct ecm_db_iface_instance *ecm_db_iface_find_and_ref_pppol2tpv2(uint32_t pppol2tpv2_tunnel_id, uint32_t pppol2tpv2_session_id)
{
	ecm_db_iface_hash_t hash_index;
	struct ecm_db_iface_instance *ii;

	/*
	 * Compute the hash chain index and prepare to walk the chain
	 */
	hash_index = ecm_db_iface_generate_hash_index_pppol2tpv2(pppol2tpv2_tunnel_id, pppol2tpv2_session_id);

	DEBUG_TRACE("Lookup pppol2tpv2 iface with local_tunnel_id = %d, local_session_id = %d, hash = 0x%x\n", pppol2tpv2_tunnel_id,
									pppol2tpv2_session_id, hash_index);

	/*
	 * Iterate the chain looking for a host with matching details
	 */
	spin_lock_bh(&ecm_db_lock);
	ii = ecm_db_iface_table[hash_index];

	while (ii) {
		if ((ii->type != ECM_DB_IFACE_TYPE_PPPOL2TPV2)
				|| (ii->type_info.pppol2tpv2.l2tp.session.session_id != pppol2tpv2_session_id)
				|| (ii->type_info.pppol2tpv2.l2tp.tunnel.tunnel_id != pppol2tpv2_tunnel_id)) {
			ii = ii->hash_next;
			continue;
		}

		_ecm_db_iface_ref(ii);
		spin_unlock_bh(&ecm_db_lock);
		DEBUG_TRACE("iface found %p\n", ii);
		return ii;
	}
	spin_unlock_bh(&ecm_db_lock);

	DEBUG_TRACE("Iface not found\n");
	return NULL;
}
EXPORT_SYMBOL(ecm_db_iface_find_and_ref_pppol2tpv2);

#endif

#ifdef ECM_INTERFACE_PPTP_ENABLE
/*
 * ecm_db_iface_pptp_session_info_get
 *	get pptp specific info
 */
void ecm_db_iface_pptp_session_info_get(struct ecm_db_iface_instance *ii, struct ecm_db_interface_info_pptp *pptp_info)
{
	DEBUG_CHECK_MAGIC(ii, ECM_DB_IFACE_INSTANCE_MAGIC, "%p: magic failed", ii);
	DEBUG_ASSERT(ii->type == ECM_DB_IFACE_TYPE_PPTP, "%p: Bad type, expected pptp, actual: %d\n", ii, ii->type);
	spin_lock_bh(&ecm_db_lock);
	memcpy(pptp_info, &ii->type_info.pptp, sizeof(struct ecm_db_interface_info_pptp));
	spin_unlock_bh(&ecm_db_lock);
}
EXPORT_SYMBOL(ecm_db_iface_pptp_session_info_get);

/*
 * ecm_db_iface_find_and_ref_pptp()
 *	Lookup and return a iface reference if any
 */
struct ecm_db_iface_instance *ecm_db_iface_find_and_ref_pptp(uint32_t pptp_src_call_id, uint32_t pptp_dst_call_id)
{
	ecm_db_iface_hash_t hash_index;
	struct ecm_db_iface_instance *ii;

	/*
	 * Compute the hash chain index and prepare to walk the chain
	 */
	hash_index = ecm_db_iface_generate_hash_index_pptp(pptp_src_call_id, pptp_dst_call_id);

	DEBUG_TRACE("Lookup pptp iface with local_call_id = %d, remote_call_id = %d, hash = 0x%x\n", pptp_src_call_id,
									pptp_dst_call_id, hash_index);

	/*
	 * Iterate the chain looking for a host with matching details
	 */
	spin_lock_bh(&ecm_db_lock);
	ii = ecm_db_iface_table[hash_index];

	while (ii) {
		if ((ii->type != ECM_DB_IFACE_TYPE_PPTP)
				|| (ii->type_info.pptp.src_call_id != pptp_src_call_id)
				|| (ii->type_info.pptp.dst_call_id != pptp_dst_call_id)) {
			ii = ii->hash_next;
			continue;
		}

		_ecm_db_iface_ref(ii);
		spin_unlock_bh(&ecm_db_lock);
		DEBUG_TRACE("iface found %p\n", ii);
		return ii;
	}
	spin_unlock_bh(&ecm_db_lock);

	DEBUG_TRACE("Iface not found\n");
	return NULL;
}
EXPORT_SYMBOL(ecm_db_iface_find_and_ref_pptp);
#endif

#ifdef ECM_INTERFACE_MAP_T_ENABLE
/*
 * ecm_db_iface_map_t_info_get
 *	get map_t specific info
 */
void ecm_db_iface_map_t_info_get(struct ecm_db_iface_instance *ii, struct ecm_db_interface_info_map_t *map_t_info)
{
	DEBUG_CHECK_MAGIC(ii, ECM_DB_IFACE_INSTANCE_MAGIC, "%p: magic failed", ii);
	DEBUG_ASSERT(ii->type == ECM_DB_IFACE_TYPE_MAP_T, "%p: Bad type, expected map_t, actual: %d\n", ii, ii->type);
	spin_lock_bh(&ecm_db_lock);
	memcpy(map_t_info, &ii->type_info.map_t, sizeof(struct ecm_db_interface_info_map_t));
	spin_unlock_bh(&ecm_db_lock);
}
EXPORT_SYMBOL(ecm_db_iface_map_t_info_get);

/*
 * ecm_db_iface_find_and_ref_map_t()
 *	Lookup and return a iface reference if any
 */
struct ecm_db_iface_instance *ecm_db_iface_find_and_ref_map_t(int if_index)
{
	ecm_db_iface_hash_t hash_index;
	struct ecm_db_iface_instance *ii;

	DEBUG_TRACE("Lookup map_t iface with if_index = %d\n", if_index);

	/*
	 * Compute the hash chain index and prepare to walk the chain
	 */
	hash_index = ecm_db_iface_generate_hash_index_map_t(if_index);

	/*
	 * Iterate the chain looking for a host with matching details
	 */
	spin_lock_bh(&ecm_db_lock);
	ii = ecm_db_iface_table[hash_index];

	while (ii) {
		if ((ii->type != ECM_DB_IFACE_TYPE_MAP_T)
				|| (ii->type_info.map_t.if_index != if_index)) {
			ii = ii->hash_next;
			continue;
		}

		_ecm_db_iface_ref(ii);
		spin_unlock_bh(&ecm_db_lock);
		DEBUG_TRACE("%p: iface found\n", ii);
		return ii;
	}
	spin_unlock_bh(&ecm_db_lock);

	DEBUG_TRACE("Iface not found\n");
	return NULL;
}
EXPORT_SYMBOL(ecm_db_iface_find_and_ref_map_t);

#endif

/*
 * ecm_db_iface_find_and_ref_unknown()
 *	Lookup and return a iface reference if any
 */
struct ecm_db_iface_instance *ecm_db_iface_find_and_ref_unknown(uint32_t os_specific_ident)
{
	ecm_db_iface_hash_t hash_index;
	struct ecm_db_iface_instance *ii;

	DEBUG_TRACE("Lookup unknown iface with addr %x (%u)\n", os_specific_ident, os_specific_ident);

	/*
	 * Compute the hash chain index and prepare to walk the chain
	 */
	hash_index = ecm_db_iface_generate_hash_index_unknown(os_specific_ident);

	/*
	 * Iterate the chain looking for a host with matching details
	 */
	spin_lock_bh(&ecm_db_lock);
	ii = ecm_db_iface_table[hash_index];
	while (ii) {
		if ((ii->type != ECM_DB_IFACE_TYPE_UNKNOWN) || (ii->type_info.unknown.os_specific_ident != os_specific_ident)) {
			ii = ii->hash_next;
			continue;
		}

		_ecm_db_iface_ref(ii);
		spin_unlock_bh(&ecm_db_lock);
		DEBUG_TRACE("iface found %p\n", ii);
		return ii;
	}
	spin_unlock_bh(&ecm_db_lock);
	DEBUG_TRACE("Iface not found\n");
	return NULL;
}
EXPORT_SYMBOL(ecm_db_iface_find_and_ref_unknown);

/*
 * ecm_db_iface_find_and_ref_loopback()
 *	Lookup and return a iface reference if any
 */
struct ecm_db_iface_instance *ecm_db_iface_find_and_ref_loopback(uint32_t os_specific_ident)
{
	ecm_db_iface_hash_t hash_index;
	struct ecm_db_iface_instance *ii;

	DEBUG_TRACE("Lookup loopback iface with addr %x (%u)\n", os_specific_ident, os_specific_ident);

	/*
	 * Compute the hash chain index and prepare to walk the chain
	 */
	hash_index = ecm_db_iface_generate_hash_index_loopback(os_specific_ident);

	/*
	 * Iterate the chain looking for a host with matching details
	 */
	spin_lock_bh(&ecm_db_lock);
	ii = ecm_db_iface_table[hash_index];
	while (ii) {
		if ((ii->type != ECM_DB_IFACE_TYPE_LOOPBACK) || (ii->type_info.loopback.os_specific_ident != os_specific_ident)) {
			ii = ii->hash_next;
			continue;
		}

		_ecm_db_iface_ref(ii);
		spin_unlock_bh(&ecm_db_lock);
		DEBUG_TRACE("iface found %p\n", ii);
		return ii;
	}
	spin_unlock_bh(&ecm_db_lock);
	DEBUG_TRACE("Iface not found\n");
	return NULL;
}
EXPORT_SYMBOL(ecm_db_iface_find_and_ref_loopback);

#ifdef ECM_INTERFACE_IPSEC_ENABLE
/*
 * ecm_db_iface_find_and_ref_ipsec_tunnel()
 *	Lookup and return a iface reference if any.
 * GGG TODO Flesh this out using tunnel endpoint keys
 */
struct ecm_db_iface_instance *ecm_db_iface_find_and_ref_ipsec_tunnel(uint32_t os_specific_ident)
{
	ecm_db_iface_hash_t hash_index;
	struct ecm_db_iface_instance *ii;

	DEBUG_TRACE("Lookup ipsec_tunnel iface with addr %x (%u)\n", os_specific_ident, os_specific_ident);

	/*
	 * Compute the hash chain index and prepare to walk the chain
	 */
	hash_index = ecm_db_iface_generate_hash_index_ipsec_tunnel(os_specific_ident);

	/*
	 * Iterate the chain looking for a host with matching details
	 */
	spin_lock_bh(&ecm_db_lock);
	ii = ecm_db_iface_table[hash_index];
	while (ii) {
		if ((ii->type != ECM_DB_IFACE_TYPE_IPSEC_TUNNEL) || (ii->type_info.ipsec_tunnel.os_specific_ident != os_specific_ident)) {
			ii = ii->hash_next;
			continue;
		}

		_ecm_db_iface_ref(ii);
		spin_unlock_bh(&ecm_db_lock);
		DEBUG_TRACE("iface found %p\n", ii);
		return ii;
	}
	spin_unlock_bh(&ecm_db_lock);
	DEBUG_TRACE("Iface not found\n");
	return NULL;
}
EXPORT_SYMBOL(ecm_db_iface_find_and_ref_ipsec_tunnel);
#endif

#ifdef ECM_INTERFACE_SIT_ENABLE
/*
 * ecm_db_iface_find_and_ref_sit()
 *	Lookup and return a iface reference if any
 */
struct ecm_db_iface_instance *ecm_db_iface_find_and_ref_sit(ip_addr_t saddr, ip_addr_t daddr, int32_t ae_interface_num)
{
	ecm_db_iface_hash_t hash_index;
	struct ecm_db_iface_instance *ii;

	DEBUG_TRACE("Lookup sit (6-in-4) iface with saddr: " ECM_IP_ADDR_OCTAL_FMT ", daddr: " ECM_IP_ADDR_OCTAL_FMT "\n",
			ECM_IP_ADDR_TO_OCTAL(saddr), ECM_IP_ADDR_TO_OCTAL(daddr));

	/*
	 * Compute the hash chain index and prepare to walk the chain
	 */
	hash_index = ecm_db_iface_generate_hash_index_sit(saddr, daddr);

	/*
	 * Iterate the chain looking for a host with matching details
	 */
	spin_lock_bh(&ecm_db_lock);
	ii = ecm_db_iface_table[hash_index];
	while (ii) {
		if ((ii->type != ECM_DB_IFACE_TYPE_SIT)
				|| !ECM_IP_ADDR_MATCH(ii->type_info.sit.saddr, saddr)
				|| !ECM_IP_ADDR_MATCH(ii->type_info.sit.daddr, daddr)
				|| (ii->ae_interface_identifier != ae_interface_num)) {
			ii = ii->hash_next;
			continue;
		}

		_ecm_db_iface_ref(ii);
		spin_unlock_bh(&ecm_db_lock);
		DEBUG_TRACE("iface found %p\n", ii);
		return ii;
	}
	spin_unlock_bh(&ecm_db_lock);
	DEBUG_TRACE("Iface not found\n");
	return NULL;
}
EXPORT_SYMBOL(ecm_db_iface_find_and_ref_sit);
#endif

#ifdef ECM_INTERFACE_TUNIPIP6_ENABLE
#ifdef ECM_IPV6_ENABLE
/*
 * ecm_db_iface_find_and_ref_tunipip6()
 *	Lookup and return a iface reference if any
 */
struct ecm_db_iface_instance *ecm_db_iface_find_and_ref_tunipip6(ip_addr_t saddr, ip_addr_t daddr)
{
	ecm_db_iface_hash_t hash_index;
	struct ecm_db_iface_instance *ii;

	DEBUG_TRACE("Lookup TUNIPIP6 iface with saddr: " ECM_IP_ADDR_OCTAL_FMT ", daddr: " ECM_IP_ADDR_OCTAL_FMT "\n",
			ECM_IP_ADDR_TO_OCTAL(saddr), ECM_IP_ADDR_TO_OCTAL(daddr));

	/*
	 * Compute the hash chain index and prepare to walk the chain
	 */
	hash_index = ecm_db_iface_generate_hash_index_tunipip6(saddr, daddr);

	/*
	 * Iterate the chain looking for a host with matching details
	 */
	spin_lock_bh(&ecm_db_lock);
	ii = ecm_db_iface_table[hash_index];
	while (ii) {
		if ((ii->type != ECM_DB_IFACE_TYPE_TUNIPIP6)
				|| !ECM_IP_ADDR_MATCH(ii->type_info.tunipip6.saddr, saddr)
				|| !ECM_IP_ADDR_MATCH(ii->type_info.tunipip6.daddr, daddr)) {
			ii = ii->hash_next;
			continue;
		}

		_ecm_db_iface_ref(ii);
		spin_unlock_bh(&ecm_db_lock);
		DEBUG_TRACE("iface found %p\n", ii);
		return ii;
	}
	spin_unlock_bh(&ecm_db_lock);
	DEBUG_TRACE("Iface not found\n");
	return NULL;
}
EXPORT_SYMBOL(ecm_db_iface_find_and_ref_tunipip6);
#endif
#endif

/*
 * ecm_db_mapping_find_and_ref()
 *	Lookup and return a mapping reference if any.
 *
 * NOTE: For non-port based protocols the ports are expected to be -(protocol)
 */
struct ecm_db_mapping_instance *ecm_db_mapping_find_and_ref(ip_addr_t address, int port)
{
	ecm_db_mapping_hash_t hash_index;
	struct ecm_db_mapping_instance *mi;

	DEBUG_TRACE("Lookup mapping with addr " ECM_IP_ADDR_OCTAL_FMT " and port %d\n", ECM_IP_ADDR_TO_OCTAL(address), port);

	/*
	 * Compute the hash chain index and prepare to walk the chain
	 */
	hash_index = ecm_db_mapping_generate_hash_index(address, port);

	/*
	 * Iterate the chain looking for a mapping with matching details
	 */
	spin_lock_bh(&ecm_db_lock);
	mi = ecm_db_mapping_table[hash_index];
	while (mi) {
		if (mi->port != port) {
			mi = mi->hash_next;
			continue;
		}

		if (!ECM_IP_ADDR_MATCH(mi->host->address, address)) {
			mi = mi->hash_next;
			continue;
		}

		_ecm_db_mapping_ref(mi);
		spin_unlock_bh(&ecm_db_lock);
		DEBUG_TRACE("Mapping found %p\n", mi);
		return mi;
	}
	spin_unlock_bh(&ecm_db_lock);
	DEBUG_TRACE("Mapping not found\n");
	return NULL;
}
EXPORT_SYMBOL(ecm_db_mapping_find_and_ref);

/*
 * ecm_db_connection_find_and_ref_chain()
 *	Given a hash chain index locate the connection
 */
static struct ecm_db_connection_instance *ecm_db_connection_find_and_ref_chain(ecm_db_connection_hash_t hash_index,
											ip_addr_t host1_addr, ip_addr_t host2_addr,
											int protocol, int host1_port, int host2_port)
{
	struct ecm_db_connection_instance *ci;

	/*
	 * Iterate the chain looking for a connection with matching details
	 */
	spin_lock_bh(&ecm_db_lock);
	ci = ecm_db_connection_table[hash_index];
	while (ci) {
		/*
		 * The use of unlikely() is liberally used because under fast-hit scenarios the connection would always be at the start of a chain
		 */
		if (unlikely(ci->protocol != protocol)) {
			goto try_next;
		}

		if (unlikely(!ECM_IP_ADDR_MATCH(host1_addr, ci->mapping_from->host->address))) {
			goto try_reverse;
		}

		if (unlikely(host1_port != ci->mapping_from->port)) {
			goto try_reverse;
		}

		if (unlikely(!ECM_IP_ADDR_MATCH(host2_addr, ci->mapping_to->host->address))) {
			goto try_reverse;
		}

		if (unlikely(host2_port != ci->mapping_to->port)) {
			goto try_reverse;
		}

		goto connection_found;

try_reverse:
		if (unlikely(!ECM_IP_ADDR_MATCH(host1_addr, ci->mapping_to->host->address))) {
			goto try_next;
		}

		if (unlikely(host1_port != ci->mapping_to->port)) {
			goto try_next;
		}

		if (unlikely(!ECM_IP_ADDR_MATCH(host2_addr, ci->mapping_from->host->address))) {
			goto try_next;
		}

		if (unlikely(host2_port != ci->mapping_from->port)) {
			goto try_next;
		}

		goto connection_found;

try_next:
		ci = ci->hash_next;
	}
	spin_unlock_bh(&ecm_db_lock);
	DEBUG_TRACE("Connection not found in hash chain\n");
	return NULL;

connection_found:
	_ecm_db_connection_ref(ci);
	spin_unlock_bh(&ecm_db_lock);
	DEBUG_TRACE("Connection found %p\n", ci);
	return ci;
}

/*
 * ecm_db_connection_find_and_ref()
 *	Locate a connection instance based on addressing, protocol and optional port information.
 *
 * NOTE: For non-port based protocols then ports are expected to be -(protocol).
 */
struct ecm_db_connection_instance *ecm_db_connection_find_and_ref(ip_addr_t host1_addr, ip_addr_t host2_addr, int protocol, int host1_port, int host2_port)
{
	ecm_db_connection_hash_t hash_index;

	DEBUG_TRACE("Lookup connection " ECM_IP_ADDR_OCTAL_FMT ":%d <> " ECM_IP_ADDR_OCTAL_FMT ":%d protocol %d\n", ECM_IP_ADDR_TO_OCTAL(host1_addr), host1_port, ECM_IP_ADDR_TO_OCTAL(host2_addr), host2_port, protocol);

	/*
	 * Compute the hash chain index and prepare to walk the chain
	 */
	hash_index = ecm_db_connection_generate_hash_index(host1_addr, host1_port, host2_addr, host2_port, protocol);
	return ecm_db_connection_find_and_ref_chain(hash_index, host1_addr, host2_addr, protocol, host1_port, host2_port);
}
EXPORT_SYMBOL(ecm_db_connection_find_and_ref);

/*
 * ecm_db_connection_serial_find_and_ref()
 *	Locate a connection instance based on serial if it still exists
 */
struct ecm_db_connection_instance *ecm_db_connection_serial_find_and_ref(uint32_t serial)
{
	ecm_db_connection_serial_hash_t serial_hash_index;
	struct ecm_db_connection_instance *ci;

	DEBUG_TRACE("Lookup connection serial: %u\n", serial);

	/*
	 * Compute the hash chain index and prepare to walk the chain
	 */
	serial_hash_index = ecm_db_connection_generate_serial_hash_index(serial);

	/*
	 * Iterate the chain looking for a connection with matching serial
	 */
	spin_lock_bh(&ecm_db_lock);
	ci = ecm_db_connection_serial_table[serial_hash_index];
	while (ci) {
		/*
		 * The use of likely() is used because under fast-hit scenarios the connection would always be at the start of a chain
		 */
		if (likely(ci->serial == serial)) {
			_ecm_db_connection_ref(ci);
			spin_unlock_bh(&ecm_db_lock);
			DEBUG_TRACE("Connection found %p\n", ci);
			return ci;
		}

		ci = ci->serial_hash_next;
	}
	spin_unlock_bh(&ecm_db_lock);
	DEBUG_TRACE("Connection not found\n");
	return NULL;
}
EXPORT_SYMBOL(ecm_db_connection_serial_find_and_ref);

/*
 * ecm_db_connection_node_to_get_and_ref()
 *	Return node reference
 */
struct ecm_db_node_instance *ecm_db_connection_node_to_get_and_ref(struct ecm_db_connection_instance *ci)
{
	struct ecm_db_node_instance *ni;

	DEBUG_CHECK_MAGIC(ci, ECM_DB_CONNECTION_INSTANCE_MAGIC, "%p: magic failed\n", ci);

	spin_lock_bh(&ecm_db_lock);
	ni = ci->to_node;
	DEBUG_CHECK_MAGIC(ni, ECM_DB_NODE_INSTANCE_MAGIC, "%p: magic failed\n", ni);
	_ecm_db_node_ref(ni);
	spin_unlock_bh(&ecm_db_lock);
	return ni;
}
EXPORT_SYMBOL(ecm_db_connection_node_to_get_and_ref);

/*
 * ecm_db_connection_node_from_get_and_ref()
 *	Return node reference
 */
struct ecm_db_node_instance *ecm_db_connection_node_from_get_and_ref(struct ecm_db_connection_instance *ci)
{
	struct ecm_db_node_instance *ni;

	DEBUG_CHECK_MAGIC(ci, ECM_DB_CONNECTION_INSTANCE_MAGIC, "%p: magic failed\n", ci);

	spin_lock_bh(&ecm_db_lock);
	ni = ci->from_node;
	_ecm_db_node_ref(ni);
	spin_unlock_bh(&ecm_db_lock);
	return ni;
}
EXPORT_SYMBOL(ecm_db_connection_node_from_get_and_ref);

#ifdef ECM_DB_XREF_ENABLE
/*
 * ecm_db_mapping_connections_from_get_and_ref_first()
 *	Return a reference to the first connection made from this mapping
 */
struct ecm_db_connection_instance *ecm_db_mapping_connections_from_get_and_ref_first(struct ecm_db_mapping_instance *mi)
{
	struct ecm_db_connection_instance *ci;

	DEBUG_CHECK_MAGIC(mi, ECM_DB_MAPPING_INSTANCE_MAGIC, "%p: magic failed", mi);

	spin_lock_bh(&ecm_db_lock);
	ci = mi->from_connections;
	if (ci) {
		_ecm_db_connection_ref(ci);
	}
	spin_unlock_bh(&ecm_db_lock);

	return ci;
}
EXPORT_SYMBOL(ecm_db_mapping_connections_from_get_and_ref_first);

/*
 * ecm_db_mapping_connections_to_get_and_ref_first()
 *	Return a reference to the first connection made to this mapping
 */
struct ecm_db_connection_instance *ecm_db_mapping_connections_to_get_and_ref_first(struct ecm_db_mapping_instance *mi)
{
	struct ecm_db_connection_instance *ci;

	DEBUG_CHECK_MAGIC(mi, ECM_DB_MAPPING_INSTANCE_MAGIC, "%p: magic failed", mi);

	spin_lock_bh(&ecm_db_lock);
	ci = mi->to_connections;
	if (ci) {
		_ecm_db_connection_ref(ci);
	}
	spin_unlock_bh(&ecm_db_lock);

	return ci;
}
EXPORT_SYMBOL(ecm_db_mapping_connections_to_get_and_ref_first);

/*
 * ecm_db_mapping_connections_nat_from_get_and_ref_first()
 *	Return a reference to the first NAT connection made from this mapping
 */
struct ecm_db_connection_instance *ecm_db_mapping_connections_nat_from_get_and_ref_first(struct ecm_db_mapping_instance *mi)
{
	struct ecm_db_connection_instance *ci;

	DEBUG_CHECK_MAGIC(mi, ECM_DB_MAPPING_INSTANCE_MAGIC, "%p: magic failed", mi);

	spin_lock_bh(&ecm_db_lock);
	ci = mi->from_nat_connections;
	if (ci) {
		_ecm_db_connection_ref(ci);
	}
	spin_unlock_bh(&ecm_db_lock);

	return ci;
}
EXPORT_SYMBOL(ecm_db_mapping_connections_nat_from_get_and_ref_first);

/*
 * ecm_db_mapping_connections_nat_to_get_and_ref_first()
 *	Return a reference to the first NAT connection made to this mapping
 */
struct ecm_db_connection_instance *ecm_db_mapping_connections_nat_to_get_and_ref_first(struct ecm_db_mapping_instance *mi)
{
	struct ecm_db_connection_instance *ci;

	DEBUG_CHECK_MAGIC(mi, ECM_DB_MAPPING_INSTANCE_MAGIC, "%p: magic failed", mi);

	spin_lock_bh(&ecm_db_lock);
	ci = mi->to_nat_connections;
	if (ci) {
		_ecm_db_connection_ref(ci);
	}
	spin_unlock_bh(&ecm_db_lock);

	return ci;
}
EXPORT_SYMBOL(ecm_db_mapping_connections_nat_to_get_and_ref_first);

/*
 * ecm_db_connection_mapping_from_get_and_ref_next()
 *	Return reference to next connection in from mapping chain
 */
struct ecm_db_connection_instance *ecm_db_connection_mapping_from_get_and_ref_next(struct ecm_db_connection_instance *ci)
{
	struct ecm_db_connection_instance *nci;

	DEBUG_CHECK_MAGIC(ci, ECM_DB_CONNECTION_INSTANCE_MAGIC, "%p: magic failed\n", ci);

	spin_lock_bh(&ecm_db_lock);
	nci = ci->from_next;
	if (nci) {
		_ecm_db_connection_ref(nci);
	}
	spin_unlock_bh(&ecm_db_lock);

	return nci;
}
EXPORT_SYMBOL(ecm_db_connection_mapping_from_get_and_ref_next);

/*
 * ecm_db_connection_mapping_to_get_and_ref_next()
 *	Return reference to next connection in to mapping chain
 */
struct ecm_db_connection_instance *ecm_db_connection_mapping_to_get_and_ref_next(struct ecm_db_connection_instance *ci)
{
	struct ecm_db_connection_instance *nci;

	DEBUG_CHECK_MAGIC(ci, ECM_DB_CONNECTION_INSTANCE_MAGIC, "%p: magic failed\n", ci);

	spin_lock_bh(&ecm_db_lock);
	nci = ci->to_next;
	if (nci) {
		_ecm_db_connection_ref(nci);
	}
	spin_unlock_bh(&ecm_db_lock);

	return nci;
}
EXPORT_SYMBOL(ecm_db_connection_mapping_to_get_and_ref_next);

/*
 * ecm_db_connection_mapping_nat_from_get_and_ref_next()
 *	Return reference to next connection in from NAT mapping chain
 */
struct ecm_db_connection_instance *ecm_db_connection_mapping_nat_from_get_and_ref_next(struct ecm_db_connection_instance *ci)
{
	struct ecm_db_connection_instance *nci;

	DEBUG_CHECK_MAGIC(ci, ECM_DB_CONNECTION_INSTANCE_MAGIC, "%p: magic failed\n", ci);

	spin_lock_bh(&ecm_db_lock);
	nci = ci->from_nat_next;
	if (nci) {
		_ecm_db_connection_ref(nci);
	}
	spin_unlock_bh(&ecm_db_lock);

	return nci;
}
EXPORT_SYMBOL(ecm_db_connection_mapping_nat_from_get_and_ref_next);

/*
 * ecm_db_connection_mapping_nat_to_get_and_ref_next()
 *	Return reference to next connection in to NAT mapping chain
 */
struct ecm_db_connection_instance *ecm_db_connection_mapping_nat_to_get_and_ref_next(struct ecm_db_connection_instance *ci)
{
	struct ecm_db_connection_instance *nci;

	DEBUG_CHECK_MAGIC(ci, ECM_DB_CONNECTION_INSTANCE_MAGIC, "%p: magic failed\n", ci);

	spin_lock_bh(&ecm_db_lock);
	nci = ci->to_nat_next;
	if (nci) {
		_ecm_db_connection_ref(nci);
	}
	spin_unlock_bh(&ecm_db_lock);

	return nci;
}
EXPORT_SYMBOL(ecm_db_connection_mapping_nat_to_get_and_ref_next);

/*
 * ecm_db_iface_connections_from_get_and_ref_first()
 *	Return a reference to the first connection made from this iface
 */
struct ecm_db_connection_instance *ecm_db_iface_connections_from_get_and_ref_first(struct ecm_db_iface_instance *ii)
{
	struct ecm_db_connection_instance *ci;

	DEBUG_CHECK_MAGIC(ii, ECM_DB_IFACE_INSTANCE_MAGIC, "%p: magic failed", ii);

	spin_lock_bh(&ecm_db_lock);
	ci = ii->from_connections;
	if (ci) {
		_ecm_db_connection_ref(ci);
	}
	spin_unlock_bh(&ecm_db_lock);

	return ci;
}
EXPORT_SYMBOL(ecm_db_iface_connections_from_get_and_ref_first);

/*
 * ecm_db_iface_connections_to_get_and_ref_first()
 *	Return a reference to the first connection made to this iface
 */
struct ecm_db_connection_instance *ecm_db_iface_connections_to_get_and_ref_first(struct ecm_db_iface_instance *ii)
{
	struct ecm_db_connection_instance *ci;

	DEBUG_CHECK_MAGIC(ii, ECM_DB_IFACE_INSTANCE_MAGIC, "%p: magic failed", ii);

	spin_lock_bh(&ecm_db_lock);
	ci = ii->to_connections;
	if (ci) {
		_ecm_db_connection_ref(ci);
	}
	spin_unlock_bh(&ecm_db_lock);

	return ci;
}
EXPORT_SYMBOL(ecm_db_iface_connections_to_get_and_ref_first);

/*
 * ecm_db_iface_connections_nat_from_get_and_ref_first()
 *	Return a reference to the first NAT connection made from this iface
 */
struct ecm_db_connection_instance *ecm_db_iface_connections_nat_from_get_and_ref_first(struct ecm_db_iface_instance *ii)
{
	struct ecm_db_connection_instance *ci;

	DEBUG_CHECK_MAGIC(ii, ECM_DB_IFACE_INSTANCE_MAGIC, "%p: magic failed", ii);

	spin_lock_bh(&ecm_db_lock);
	ci = ii->from_nat_connections;
	if (ci) {
		_ecm_db_connection_ref(ci);
	}
	spin_unlock_bh(&ecm_db_lock);

	return ci;
}
EXPORT_SYMBOL(ecm_db_iface_connections_nat_from_get_and_ref_first);

/*
 * ecm_db_iface_connections_nat_to_get_and_ref_first()
 *	Return a reference to the first NAT connection made to this iface
 */
struct ecm_db_connection_instance *ecm_db_iface_connections_nat_to_get_and_ref_first(struct ecm_db_iface_instance *ii)
{
	struct ecm_db_connection_instance *ci;

	DEBUG_CHECK_MAGIC(ii, ECM_DB_IFACE_INSTANCE_MAGIC, "%p: magic failed", ii);

	spin_lock_bh(&ecm_db_lock);
	ci = ii->to_nat_connections;
	if (ci) {
		_ecm_db_connection_ref(ci);
	}
	spin_unlock_bh(&ecm_db_lock);

	return ci;
}
EXPORT_SYMBOL(ecm_db_iface_connections_nat_to_get_and_ref_first);

/*
 * ecm_db_connection_iface_from_get_and_ref_next()
 *	Return reference to next connection in from iface chain
 */
struct ecm_db_connection_instance *ecm_db_connection_iface_from_get_and_ref_next(struct ecm_db_connection_instance *ci)
{
	struct ecm_db_connection_instance *nci;

	DEBUG_CHECK_MAGIC(ci, ECM_DB_CONNECTION_INSTANCE_MAGIC, "%p: magic failed\n", ci);

	spin_lock_bh(&ecm_db_lock);
	nci = ci->iface_from_next;
	if (nci) {
		_ecm_db_connection_ref(nci);
	}
	spin_unlock_bh(&ecm_db_lock);

	return nci;
}
EXPORT_SYMBOL(ecm_db_connection_iface_from_get_and_ref_next);

/*
 * ecm_db_connection_iface_to_get_and_ref_next()
 *	Return reference to next connection in to iface chain
 */
struct ecm_db_connection_instance *ecm_db_connection_iface_to_get_and_ref_next(struct ecm_db_connection_instance *ci)
{
	struct ecm_db_connection_instance *nci;

	DEBUG_CHECK_MAGIC(ci, ECM_DB_CONNECTION_INSTANCE_MAGIC, "%p: magic failed\n", ci);

	spin_lock_bh(&ecm_db_lock);
	nci = ci->iface_to_next;
	if (nci) {
		_ecm_db_connection_ref(nci);
	}
	spin_unlock_bh(&ecm_db_lock);

	return nci;
}
EXPORT_SYMBOL(ecm_db_connection_iface_to_get_and_ref_next);

/*
 * ecm_db_connection_iface_nat_from_get_and_ref_next()
 *	Return reference to next connection in from NAT iface chain
 */
struct ecm_db_connection_instance *ecm_db_connection_iface_nat_from_get_and_ref_next(struct ecm_db_connection_instance *ci)
{
	struct ecm_db_connection_instance *nci;

	DEBUG_CHECK_MAGIC(ci, ECM_DB_CONNECTION_INSTANCE_MAGIC, "%p: magic failed\n", ci);

	spin_lock_bh(&ecm_db_lock);
	nci = ci->iface_from_nat_next;
	if (nci) {
		_ecm_db_connection_ref(nci);
	}
	spin_unlock_bh(&ecm_db_lock);

	return nci;
}
EXPORT_SYMBOL(ecm_db_connection_iface_nat_from_get_and_ref_next);

/*
 * ecm_db_connection_iface_nat_to_get_and_ref_next()
 *	Return reference to next connection in to NAT iface chain
 */
struct ecm_db_connection_instance *ecm_db_connection_iface_nat_to_get_and_ref_next(struct ecm_db_connection_instance *ci)
{
	struct ecm_db_connection_instance *nci;

	DEBUG_CHECK_MAGIC(ci, ECM_DB_CONNECTION_INSTANCE_MAGIC, "%p: magic failed\n", ci);

	spin_lock_bh(&ecm_db_lock);
	nci = ci->iface_to_nat_next;
	if (nci) {
		_ecm_db_connection_ref(nci);
	}
	spin_unlock_bh(&ecm_db_lock);

	return nci;
}
EXPORT_SYMBOL(ecm_db_connection_iface_nat_to_get_and_ref_next);

/*
 * ecm_db_iface_nodes_get_and_ref_first()
 *	Return a reference to the first node made from this iface
 */
struct ecm_db_node_instance *ecm_db_iface_nodes_get_and_ref_first(struct ecm_db_iface_instance *ii)
{
	struct ecm_db_node_instance *ni;

	DEBUG_CHECK_MAGIC(ii, ECM_DB_IFACE_INSTANCE_MAGIC, "%p: magic failed", ii);

	spin_lock_bh(&ecm_db_lock);
	ni = ii->nodes;
	if (ni) {
		_ecm_db_node_ref(ni);
	}
	spin_unlock_bh(&ecm_db_lock);

	return ni;
}
EXPORT_SYMBOL(ecm_db_iface_nodes_get_and_ref_first);

/*
 * ecm_db_iface_node_count_get()
 *	Return the number of nodes to this iface
 */
int ecm_db_iface_node_count_get(struct ecm_db_iface_instance *ii)
{
	int count;

	DEBUG_CHECK_MAGIC(ii, ECM_DB_IFACE_INSTANCE_MAGIC, "%p: magic failed\n", ii);

	spin_lock_bh(&ecm_db_lock);
	count = ii->node_count;
	spin_unlock_bh(&ecm_db_lock);
	return count;
}
EXPORT_SYMBOL(ecm_db_iface_node_count_get);

/*
 * ecm_db_host_mapping_count_get()
 *	Return the number of mappings to this host
 */
int ecm_db_host_mapping_count_get(struct ecm_db_host_instance *hi)
{
	int count;

	DEBUG_CHECK_MAGIC(hi, ECM_DB_HOST_INSTANCE_MAGIC, "%p: magic failed\n", hi);

	spin_lock_bh(&ecm_db_lock);
	count = hi->mapping_count;
	spin_unlock_bh(&ecm_db_lock);
	return count;
}
EXPORT_SYMBOL(ecm_db_host_mapping_count_get);
#endif

/*
 * ecm_db_mapping_host_get_and_ref()
 */
struct ecm_db_host_instance *ecm_db_mapping_host_get_and_ref(struct ecm_db_mapping_instance *mi)
{
	DEBUG_CHECK_MAGIC(mi, ECM_DB_MAPPING_INSTANCE_MAGIC, "%p: magic failed\n", mi);

	spin_lock_bh(&ecm_db_lock);
	_ecm_db_host_ref(mi->host);
	spin_unlock_bh(&ecm_db_lock);
	return mi->host;
}
EXPORT_SYMBOL(ecm_db_mapping_host_get_and_ref);

/*
 * ecm_db_node_iface_get_and_ref()
 */
struct ecm_db_iface_instance *ecm_db_node_iface_get_and_ref(struct ecm_db_node_instance *ni)
{
	DEBUG_CHECK_MAGIC(ni, ECM_DB_NODE_INSTANCE_MAGIC, "%p: magic failed\n", ni);

	spin_lock_bh(&ecm_db_lock);
	_ecm_db_iface_ref(ni->iface);
	spin_unlock_bh(&ecm_db_lock);
	return ni->iface;
}
EXPORT_SYMBOL(ecm_db_node_iface_get_and_ref);

/*
 * ecm_db_mapping_connections_total_count_get()
 *	Return the total number of connections (NAT and non-NAT) this mapping has
 */
int ecm_db_mapping_connections_total_count_get(struct ecm_db_mapping_instance *mi)
{
	int count;

	DEBUG_CHECK_MAGIC(mi, ECM_DB_MAPPING_INSTANCE_MAGIC, "%p: magic failed\n", mi);

	spin_lock_bh(&ecm_db_lock);
	count = mi->from + mi->to + mi->nat_from + mi->nat_to;
	DEBUG_ASSERT(count >= 0, "%p: Count overflow from: %d, to: %d, nat_from: %d, nat_to: %d\n", mi, mi->from, mi->to, mi->nat_from, mi->nat_to);
	spin_unlock_bh(&ecm_db_lock);
	return count;
}
EXPORT_SYMBOL(ecm_db_mapping_connections_total_count_get);

/*
 * ecm_db_connection_mapping_from_get_and_ref()
 * 	Return a reference to the from mapping of the connection
 */
struct ecm_db_mapping_instance *ecm_db_connection_mapping_from_get_and_ref(struct ecm_db_connection_instance *ci)
{
	struct ecm_db_mapping_instance *mi;

	DEBUG_CHECK_MAGIC(ci, ECM_DB_CONNECTION_INSTANCE_MAGIC, "%p: magic failed\n", ci);

	spin_lock_bh(&ecm_db_lock);
	mi = ci->mapping_from;
	_ecm_db_mapping_ref(mi);
	spin_unlock_bh(&ecm_db_lock);
	return mi;
}
EXPORT_SYMBOL(ecm_db_connection_mapping_from_get_and_ref);

/*
 * ecm_db_connection_mapping_nat_from_get_and_ref()
 * 	Return a reference to the from NAT mapping of the connection
 */
struct ecm_db_mapping_instance *ecm_db_connection_mapping_nat_from_get_and_ref(struct ecm_db_connection_instance *ci)
{
	struct ecm_db_mapping_instance *mi;

	DEBUG_CHECK_MAGIC(ci, ECM_DB_CONNECTION_INSTANCE_MAGIC, "%p: magic failed\n", ci);

	spin_lock_bh(&ecm_db_lock);
	mi = ci->mapping_nat_from;
	_ecm_db_mapping_ref(mi);
	spin_unlock_bh(&ecm_db_lock);
	return mi;
}
EXPORT_SYMBOL(ecm_db_connection_mapping_nat_from_get_and_ref);

/*
 * ecm_db_connection_mapping_to_get_and_ref()
 * 	Return a reference to the from mapping of the connection
 */
struct ecm_db_mapping_instance *ecm_db_connection_mapping_to_get_and_ref(struct ecm_db_connection_instance *ci)
{
	struct ecm_db_mapping_instance *mi;

	DEBUG_CHECK_MAGIC(ci, ECM_DB_CONNECTION_INSTANCE_MAGIC, "%p: magic failed\n", ci);

	spin_lock_bh(&ecm_db_lock);
	mi = ci->mapping_to;
	_ecm_db_mapping_ref(mi);
	spin_unlock_bh(&ecm_db_lock);
	return mi;
}
EXPORT_SYMBOL(ecm_db_connection_mapping_to_get_and_ref);

/*
 * ecm_db_connection_mapping_to_nat_get_and_ref()
 * 	Return a reference to the from NAT mapping of the connection
 */
struct ecm_db_mapping_instance *ecm_db_connection_mapping_nat_to_get_and_ref(struct ecm_db_connection_instance *ci)
{
	struct ecm_db_mapping_instance *mi;

	DEBUG_CHECK_MAGIC(ci, ECM_DB_CONNECTION_INSTANCE_MAGIC, "%p: magic failed\n", ci);

	spin_lock_bh(&ecm_db_lock);
	mi = ci->mapping_nat_to;
	_ecm_db_mapping_ref(mi);
	spin_unlock_bh(&ecm_db_lock);
	return mi;
}
EXPORT_SYMBOL(ecm_db_connection_mapping_nat_to_get_and_ref);

/*
 * ecm_db_timer_groups_check()
 *	Check for expired group entries, returns the number that have expired
 */
static uint32_t ecm_db_timer_groups_check(uint32_t time_now)
{
	ecm_db_timer_group_t i;
	uint32_t expired = 0;

	DEBUG_TRACE("Timer groups check start %u\n", time_now);

	/*
	 * Examine all timer groups for expired entries.
	 */
	for (i = 0; i < ECM_DB_TIMER_GROUPS_MAX; ++i) {
		struct ecm_db_timer_group *timer_group;

		/*
		 * The group tail tracks the oldest entry so that is what we examine.
		 */
		timer_group = &ecm_db_timer_groups[i];
		spin_lock_bh(&ecm_db_lock);
		while (timer_group->tail) {
			struct ecm_db_timer_group_entry *tge;

			tge = timer_group->tail;
			if (tge->timeout > time_now) {
				/*
				 * Not expired - and no further will be as they are in order
				 */
				break;
			}

			/*
			 * Has expired - remove the entry from the list and invoke the callback
			 * NOTE: We know the entry is at the tail of the group
			 */
			if (tge->prev) {
				tge->prev->next = NULL;
			} else {
				/*
				 * First in the group
				 */
				DEBUG_ASSERT(timer_group->head == tge, "%p: bad head, expecting %p got %p\n", timer_group, tge, timer_group->head);
				timer_group->head = NULL;
			}
			timer_group->tail = tge->prev;
			tge->group = ECM_DB_TIMER_GROUPS_MAX;
			spin_unlock_bh(&ecm_db_lock);
			expired++;
			DEBUG_TRACE("%p: Expired\n", tge);
			tge->fn(tge->arg);
			spin_lock_bh(&ecm_db_lock);
		}
		spin_unlock_bh(&ecm_db_lock);
	}

	spin_lock_bh(&ecm_db_lock);
	time_now = ecm_db_time;
	spin_unlock_bh(&ecm_db_lock);
	DEBUG_TRACE("Timer groups check end %u, expired count %u\n", time_now, expired);
	return expired;
}

/*
 * ecm_db_connection_classifier_assign()
 *	Assign a classifier to the connection assigned classifier list.
 *
 * This adds the classifier in the ci->assignments list in ascending priority order according to the classifier type.
 * Only assigned classifiers are in this list, allowing fast retrival of current assignments, avoiding the need to skip over unassigned classifiers.
 * Because there is only one of each type of classifier the classifier is also recorded in an array, the position in which is its type value.
 * This allows fast lookup based on type too.
 * Further, the connection is recorded in the classifier type assignment array too, this permits iterating of all connections that are assigned to a TYPE of classifier.
 */
void ecm_db_connection_classifier_assign(struct ecm_db_connection_instance *ci, struct ecm_classifier_instance *new_ca)
{
	struct ecm_classifier_instance *ca;
	struct ecm_classifier_instance *ca_prev;
	ecm_classifier_type_t new_ca_type;
#ifdef ECM_DB_CTA_TRACK_ENABLE
	struct ecm_db_connection_classifier_type_assignment *ta;
	struct ecm_db_connection_classifier_type_assignment_list *tal;
#endif

	DEBUG_CHECK_MAGIC(ci, ECM_DB_CONNECTION_INSTANCE_MAGIC, "%p: magic failed\n", ci);

	/*
	 * Get the type (which is also used as the priority)
	 */
	new_ca_type = new_ca->type_get(new_ca);

	/*
	 * Connection holds ref to the classifier
	 */
	new_ca->ref(new_ca);

	/*
	 * Find place to insert the classifier
	 */
	spin_lock_bh(&ecm_db_lock);
	ca = ci->assignments;
	ca_prev = NULL;
	while (ca) {
		ecm_classifier_type_t ca_type;
		ca_type = ca->type_get(ca);

		/*
		 * If new ca is less important that the current assigned classifier insert here
		 */
		if (new_ca_type < ca_type) {
			break;
		}
		ca_prev = ca;
		ca = ca->ca_next;
	}

	/*
	 * Insert new_ca before ca and after ca_prev.
	 */
	new_ca->ca_prev = ca_prev;
	if (ca_prev) {
		ca_prev->ca_next = new_ca;
	} else {
		DEBUG_ASSERT(ci->assignments == ca, "%p: Bad assigmnment list, expecting: %p, got: %p\n", ci, ca, ci->assignments);
		ci->assignments = new_ca;
	}

	new_ca->ca_next = ca;
	if (ca) {
		ca->ca_prev = new_ca;
	}

	/*
	 * Insert based on type too
	 */
	DEBUG_ASSERT(ci->assignments_by_type[new_ca_type] == NULL, "%p: Only one of each type: %d may be registered, new: %p, existing, %p\n",
			ci, new_ca_type, new_ca, ci->assignments_by_type[new_ca_type]);
	ci->assignments_by_type[new_ca_type] = new_ca;

#ifdef ECM_DB_CTA_TRACK_ENABLE
	/*
	 * Default classifier will not be added to the classifier type assignment list.
	 * Only assigned classifiers can be added.
	 */
	if (new_ca_type == ECM_CLASSIFIER_TYPE_DEFAULT) {
		spin_unlock_bh(&ecm_db_lock);
		return;
	}

	/*
	 * Add the connection into the type assignment list too.
	 */
	ta = &ci->type_assignment[new_ca_type];
	if (ta->pending_unassign) {
		/*
		 * The connection is pending unassignment / removal from list, but since it has been
		 * re-assigned to the same type of classifier we can just clear the flag and avoid the removal.
		 * NOTE: pending_unassign is only ever true if the iteration count is non-zero i.e. iteration is in progress.
		 */
		DEBUG_CHECK_MAGIC(ta, ECM_DB_CLASSIFIER_TYPE_ASSIGNMENT_MAGIC, "%p: magic failed, ci: %p", ta, ci);
		DEBUG_ASSERT(ta->iteration_count != 0, "%p: Bad pending_unassign: type: %d, Iteration count zero\n", ci, new_ca_type);
		ta->pending_unassign = false;
		spin_unlock_bh(&ecm_db_lock);
		return;
	}

	/*
	 * iteration_count should be zero as there should not be a duplicate assignment of the same type.
	 * This is because if iteration_count was non-zero then pending_unassign should have been true.
	 */
	DEBUG_ASSERT(ta->iteration_count == 0, "%p: Type: %d, Iteration count not zero: %d\n", ci, new_ca_type, ta->iteration_count);

	/*
	 * Insert the connection into the classifier type assignment list, at the head
	 */
	tal = &ecm_db_connection_classifier_type_assignments[new_ca_type];
	ta->next = tal->type_assignments_list;
	ta->prev = NULL;

	/*
	 * If there is an existing head, it is no longer the head
	 */
	if (tal->type_assignments_list) {
		struct ecm_db_connection_classifier_type_assignment *talh;
		talh = &tal->type_assignments_list->type_assignment[new_ca_type];
		talh->prev = ci;
	}

	/*
	 * Set new head
	 */
	tal->type_assignments_list = ci;

	/*
	 * Set magic
	 */
	DEBUG_SET_MAGIC(ta, ECM_DB_CLASSIFIER_TYPE_ASSIGNMENT_MAGIC);

	/*
	 * Increment assignment count
	 */
	tal->type_assignment_count++;
	DEBUG_ASSERT(tal->type_assignment_count > 0, "Bad iteration count: %d\n", tal->type_assignment_count);
#endif
	spin_unlock_bh(&ecm_db_lock);
}
EXPORT_SYMBOL(ecm_db_connection_classifier_assign);

/*
 * ecm_db_connection_classifier_assignments_get_and_ref()
 *	Populate the given array with references to the currently assigned classifiers.
 *
 * This function returns the number of assignments starting from [0].
 * [0] is the lowest priority classifier, [return_val - 1] is the highest priority.
 * Release each classifier when you are done, for convenience use ecm_db_connection_assignments_release().
 *
 * NOTE: The array also contains the default classifier too which of course will always be at [0]
 *
 * WARNING: The array MUST be of size ECM_CLASSIFIER_TYPES.
 */
int ecm_db_connection_classifier_assignments_get_and_ref(struct ecm_db_connection_instance *ci, struct ecm_classifier_instance *assignments[])
{
	int aci_count;
	struct ecm_classifier_instance *aci;
	DEBUG_CHECK_MAGIC(ci, ECM_DB_CONNECTION_INSTANCE_MAGIC, "%p: magic failed\n", ci);

	aci_count = 0;
	spin_lock_bh(&ecm_db_lock);
	aci = ci->assignments;
	while (aci) {
		aci->ref(aci);
		assignments[aci_count++] = aci;
		aci = aci->ca_next;
	}
	spin_unlock_bh(&ecm_db_lock);
	DEBUG_ASSERT(aci_count >= 1, "%p: Must have at least default classifier!\n", ci);
	return aci_count;
}
EXPORT_SYMBOL(ecm_db_connection_classifier_assignments_get_and_ref);

/*
 * ecm_db_connection_assignments_release()
 * 	Release references to classifiers in the assignments array
 */
void ecm_db_connection_assignments_release(int assignment_count, struct ecm_classifier_instance *assignments[])
{
	int i;
	for (i = 0; i < assignment_count; ++i) {
		struct ecm_classifier_instance *aci = assignments[i];
		if (aci) {
			aci->deref(aci);
		}
	}
}
EXPORT_SYMBOL(ecm_db_connection_assignments_release);

/*
 * ecm_db_connection_assigned_classifier_find_and_ref()
 *	Return a ref to classifier of the requested type, if found
 */
struct ecm_classifier_instance *ecm_db_connection_assigned_classifier_find_and_ref(struct ecm_db_connection_instance *ci, ecm_classifier_type_t type)
{
	struct ecm_classifier_instance *ca;
	DEBUG_CHECK_MAGIC(ci, ECM_DB_CONNECTION_INSTANCE_MAGIC, "%p: magic failed\n", ci);
	spin_lock_bh(&ecm_db_lock);
	ca = ci->assignments_by_type[type];
	if (ca) {
		ca->ref(ca);
	}
	spin_unlock_bh(&ecm_db_lock);
	return ca;
}
EXPORT_SYMBOL(ecm_db_connection_assigned_classifier_find_and_ref);

/*
 * ecm_db_connection_classifier_unassign()
 *	Unassign a classifier
 *
 * The default classifier cannot be unassigned.
 */
void ecm_db_connection_classifier_unassign(struct ecm_db_connection_instance *ci, struct ecm_classifier_instance *cci)
{
	ecm_classifier_type_t ca_type;

	DEBUG_CHECK_MAGIC(ci, ECM_DB_CONNECTION_INSTANCE_MAGIC, "%p: magic failed\n", ci);

	/*
	 * Get the type
	 */
	ca_type = cci->type_get(cci);
	DEBUG_ASSERT(ca_type != ECM_CLASSIFIER_TYPE_DEFAULT, "%p: Cannot unassign default", ci);

	if (ca_type >= ECM_CLASSIFIER_TYPES) {
		DEBUG_WARN("%p: ca_type: %d is higher than the max classifier type number: %d\n", ci, ca_type, (ECM_CLASSIFIER_TYPES - 1));
		return;
	}

	DEBUG_TRACE("%p: Unassign type: %d, classifier: %p\n", ci, ca_type, cci);

	/*
	 * NOTE: It is possible that in SMP this classifier has already been unassigned.
	 */
	spin_lock_bh(&ecm_db_lock);
	if (ci->assignments_by_type[ca_type] == NULL) {
		spin_unlock_bh(&ecm_db_lock);
		DEBUG_TRACE("%p: Classifier type: %d already unassigned\n", ci, ca_type);
		return;
	}
	_ecm_db_connection_classifier_unassign(ci, cci, ca_type);
	spin_unlock_bh(&ecm_db_lock);
}
EXPORT_SYMBOL(ecm_db_connection_classifier_unassign);

#ifdef ECM_DB_CTA_TRACK_ENABLE
/*
 * ecm_db_connection_by_classifier_type_assignment_get_and_ref_first()
 *	Return a reference to the first connection for which a classifier of the given type is associated with
 *
 * WARNING: YOU MUST NOT USE ecm_db_connection_deref() to release the references taken using this API.
 * YOU MUST use ecm_db_connection_by_classifier_type_assignment_deref(), this ensures type assignment list integrity.
 */
struct ecm_db_connection_instance *ecm_db_connection_by_classifier_type_assignment_get_and_ref_first(ecm_classifier_type_t ca_type)
{
	struct ecm_db_connection_classifier_type_assignment_list *tal;
	struct ecm_db_connection_instance *ci;

	DEBUG_ASSERT(ca_type < ECM_CLASSIFIER_TYPES, "Bad type: %d\n", ca_type);

	DEBUG_TRACE("Get and ref first connection assigned with classifier type: %d\n", ca_type);

	tal = &ecm_db_connection_classifier_type_assignments[ca_type];
	spin_lock_bh(&ecm_db_lock);
	ci = tal->type_assignments_list;
	while (ci) {
		struct ecm_db_connection_classifier_type_assignment *ta;
		ta = &ci->type_assignment[ca_type];
		DEBUG_CHECK_MAGIC(ta, ECM_DB_CLASSIFIER_TYPE_ASSIGNMENT_MAGIC, "%p: magic failed, ci: %p", ta, ci);

		if (ta->pending_unassign) {
			DEBUG_TRACE("Skip %p, pending unassign for type: %d\n", ci, ca_type);
			ci = ta->next;
			continue;
		}

		/*
		 * Take reference to this connection.
		 * NOTE: Hold both the connection and the assignment entry so that when we unlock both the connection
		 * and the type assignment list entry maintains integrity.
		 */
		_ecm_db_connection_ref(ci);
		ta->iteration_count++;
		DEBUG_ASSERT(ta->iteration_count > 0, "Bad Iteration count: %d for type: %d, connection: %p\n", ta->iteration_count, ca_type, ci);
		spin_unlock_bh(&ecm_db_lock);
		return ci;
	}
	spin_unlock_bh(&ecm_db_lock);
	return NULL;
}
EXPORT_SYMBOL(ecm_db_connection_by_classifier_type_assignment_get_and_ref_first);

/*
 * ecm_db_connection_by_classifier_type_assignment_get_and_ref_next()
 *	Return a reference to the next connection for which a classifier of the given type is associated with.
 *
 * WARNING: YOU MUST NOT USE ecm_db_connection_deref() to release the references taken using this API.
 * YOU MUST use ecm_db_connection_by_classifier_type_assignment_deref(), this ensures type assignment list integrity.
 */
struct ecm_db_connection_instance *ecm_db_connection_by_classifier_type_assignment_get_and_ref_next(struct ecm_db_connection_instance *ci, ecm_classifier_type_t ca_type)
{
	struct ecm_db_connection_classifier_type_assignment *ta;
	struct ecm_db_connection_instance *cin;

	DEBUG_ASSERT(ca_type < ECM_CLASSIFIER_TYPES, "Bad type: %d\n", ca_type);
	DEBUG_CHECK_MAGIC(ci, ECM_DB_CONNECTION_INSTANCE_MAGIC, "%p: magic failed\n", ci);

	DEBUG_TRACE("Get and ref next connection assigned with classifier type: %d and ci: %p\n", ca_type, ci);

	spin_lock_bh(&ecm_db_lock);
	ta = &ci->type_assignment[ca_type];
	cin = ta->next;
	while (cin) {
		struct ecm_db_connection_classifier_type_assignment *tan;

		tan = &cin->type_assignment[ca_type];
		DEBUG_CHECK_MAGIC(tan, ECM_DB_CLASSIFIER_TYPE_ASSIGNMENT_MAGIC, "%p: magic failed, ci: %p", tan, cin);

		if (tan->pending_unassign) {
			DEBUG_TRACE("Skip %p, pending unassign for type: %d\n", cin, ca_type);
			cin = tan->next;
			continue;
		}

		/*
		 * Take reference to this connection.
		 * NOTE: Hold both the connection and the assignment entry so that when we unlock both the connection
		 * and the type assignment list entry maintains integrity.
		 */
		_ecm_db_connection_ref(cin);
		tan->iteration_count++;
		DEBUG_ASSERT(tan->iteration_count > 0, "Bad Iteration count: %d for type: %d, connection: %p\n", tan->iteration_count, ca_type, cin);
		spin_unlock_bh(&ecm_db_lock);
		return cin;
	}
	spin_unlock_bh(&ecm_db_lock);
	return NULL;
}
EXPORT_SYMBOL(ecm_db_connection_by_classifier_type_assignment_get_and_ref_next);

/*
 * ecm_db_connection_by_classifier_type_assignment_deref()
 *	Release a reference to a connection while iterating a classifier type assignment list
 */
void ecm_db_connection_by_classifier_type_assignment_deref(struct ecm_db_connection_instance *ci, ecm_classifier_type_t ca_type)
{
	struct ecm_db_connection_classifier_type_assignment_list *tal;
	struct ecm_db_connection_classifier_type_assignment *ta;

	DEBUG_ASSERT(ca_type < ECM_CLASSIFIER_TYPES, "Bad type: %d\n", ca_type);
	DEBUG_CHECK_MAGIC(ci, ECM_DB_CONNECTION_INSTANCE_MAGIC, "%p: magic failed\n", ci);

	tal = &ecm_db_connection_classifier_type_assignments[ca_type];

	/*
	 * Drop the iteration count
	 */
	spin_lock_bh(&ecm_db_lock);
	ta = &ci->type_assignment[ca_type];
	DEBUG_CHECK_MAGIC(ta, ECM_DB_CLASSIFIER_TYPE_ASSIGNMENT_MAGIC, "%p: magic failed, ci: %p", ta, ci);
	ta->iteration_count--;
	DEBUG_ASSERT(ta->iteration_count >= 0, "Bad Iteration count: %d for type: %d, connection: %p\n", ta->iteration_count, ca_type, ci);

	/*
	 * If there are no more iterations on-going and this is pending unassign then we can remove it from the assignments list
	 */
	if (ta->pending_unassign && (ta->iteration_count == 0)) {
		DEBUG_INFO("%p: Remove type assignment: %d\n", ci, ca_type);
		_ecm_db_classifier_type_assignment_remove(ci, ca_type);
	}
	spin_unlock_bh(&ecm_db_lock);
	ecm_db_connection_deref(ci);
}
EXPORT_SYMBOL(ecm_db_connection_by_classifier_type_assignment_deref);

/*
 * ecm_db_connection_make_defunct_by_assignment_type()
 *	Make defunct all connections that are currently assigned to a classifier of the given type
 */
void ecm_db_connection_make_defunct_by_assignment_type(ecm_classifier_type_t ca_type)
{
	struct ecm_db_connection_instance *ci;

	DEBUG_INFO("Make defunct all assigned to type: %d\n", ca_type);

	ci = ecm_db_connection_by_classifier_type_assignment_get_and_ref_first(ca_type);
	while (ci) {
		struct ecm_db_connection_instance *cin;

		DEBUG_TRACE("%p: Make defunct: %d\n", ci, ca_type);
		ecm_db_connection_make_defunct(ci);

		cin = ecm_db_connection_by_classifier_type_assignment_get_and_ref_next(ci, ca_type);
		ecm_db_connection_by_classifier_type_assignment_deref(ci, ca_type);
		ci = cin;
	}
}
EXPORT_SYMBOL(ecm_db_connection_make_defunct_by_assignment_type);

/*
 * ecm_db_connection_regenerate_by_assignment_type()
 *	Cause regeneration all connections that are currently assigned to a classifier of the given type
 */
void ecm_db_connection_regenerate_by_assignment_type(ecm_classifier_type_t ca_type)
{
	struct ecm_db_connection_instance *ci;

	DEBUG_INFO("Regenerate all assigned to type: %d\n", ca_type);

	ci = ecm_db_connection_by_classifier_type_assignment_get_and_ref_first(ca_type);
	while (ci) {
		struct ecm_db_connection_instance *cin;

		DEBUG_TRACE("%p: Re-generate: %d\n", ci, ca_type);
		ecm_db_connection_regenerate(ci);

		cin = ecm_db_connection_by_classifier_type_assignment_get_and_ref_next(ci, ca_type);
		ecm_db_connection_by_classifier_type_assignment_deref(ci, ca_type);
		ci = cin;
	}
}
EXPORT_SYMBOL(ecm_db_connection_regenerate_by_assignment_type);
#endif

/*
 * ecm_db_connection_from_interfaces_get_and_ref()
 *	Return the interface heirarchy from which this connection is established.
 *
 * 'interfaces' MUST be an array as large as ECM_DB_IFACE_HEIRARCHY_MAX.
 * Returns either ECM_DB_IFACE_HEIRARCHY_MAX if there are no interfaces / error.
 * Returns the index into the interfaces[] of the first interface (so "for (i = <ret val>, i < ECM_DB_IFACE_HEIRARCHY_MAX; ++i)" works)
 *
 * Each interface is referenced on return, be sure to release them individually or use ecm_db_connection_interfaces_deref() instead.
 */
int32_t ecm_db_connection_from_interfaces_get_and_ref(struct ecm_db_connection_instance *ci, struct ecm_db_iface_instance *interfaces[])
{
	int32_t n;
	int32_t i;
	DEBUG_CHECK_MAGIC(ci, ECM_DB_CONNECTION_INSTANCE_MAGIC, "%p: magic failed\n", ci);

	spin_lock_bh(&ecm_db_lock);
	n = ci->from_interface_first;
	for (i = n; i < ECM_DB_IFACE_HEIRARCHY_MAX; ++i) {
		interfaces[i] = ci->from_interfaces[i];
		_ecm_db_iface_ref(interfaces[i]);
	}
	spin_unlock_bh(&ecm_db_lock);
	return n;
}
EXPORT_SYMBOL(ecm_db_connection_from_interfaces_get_and_ref);

/*
 * ecm_db_connection_to_interfaces_get_and_ref()
 *	Return the interface heirarchy to which this connection is established.
 *
 * 'interfaces' MUST be an array as large as ECM_DB_IFACE_HEIRARCHY_MAX.
 * Returns either ECM_DB_IFACE_HEIRARCHY_MAX if there are no interfaces / error.
 * Returns the index into the interfaces[] of the first interface (so "for (i = <ret val>, i < ECM_DB_IFACE_HEIRARCHY_MAX; ++i)" works)
 *
 * Each interface is referenced on return, be sure to release them individually or use ecm_db_connection_interfaces_deref() instead.
 */
int32_t ecm_db_connection_to_interfaces_get_and_ref(struct ecm_db_connection_instance *ci, struct ecm_db_iface_instance *interfaces[])
{
	int32_t n;
	int32_t i;
	DEBUG_CHECK_MAGIC(ci, ECM_DB_CONNECTION_INSTANCE_MAGIC, "%p: magic failed\n", ci);

	spin_lock_bh(&ecm_db_lock);
	n = ci->to_interface_first;
	for (i = n; i < ECM_DB_IFACE_HEIRARCHY_MAX; ++i) {
		interfaces[i] = ci->to_interfaces[i];
		_ecm_db_iface_ref(interfaces[i]);
	}
	spin_unlock_bh(&ecm_db_lock);
	return n;
}
EXPORT_SYMBOL(ecm_db_connection_to_interfaces_get_and_ref);

/*
 * ecm_db_connection_from_nat_interfaces_get_and_ref()
 *	Return the interface heirarchy from (nat) which this connection is established.
 *
 * 'interfaces' MUST be an array as large as ECM_DB_IFACE_HEIRARCHY_MAX.
 * Returns either ECM_DB_IFACE_HEIRARCHY_MAX if there are no interfaces / error.
 * Returns the index into the interfaces[] of the first interface (so "for (i = <ret val>, i < ECM_DB_IFACE_HEIRARCHY_MAX; ++i)" works)
 *
 * Each interface is referenced on return, be sure to release them individually or use ecm_db_connection_interfaces_deref() instead.
 */
int32_t ecm_db_connection_from_nat_interfaces_get_and_ref(struct ecm_db_connection_instance *ci, struct ecm_db_iface_instance *interfaces[])
{
	int32_t n;
	int32_t i;
	DEBUG_CHECK_MAGIC(ci, ECM_DB_CONNECTION_INSTANCE_MAGIC, "%p: magic failed\n", ci);

	spin_lock_bh(&ecm_db_lock);
	n = ci->from_nat_interface_first;
	for (i = n; i < ECM_DB_IFACE_HEIRARCHY_MAX; ++i) {
		interfaces[i] = ci->from_nat_interfaces[i];
		_ecm_db_iface_ref(interfaces[i]);
	}
	spin_unlock_bh(&ecm_db_lock);
	return n;
}
EXPORT_SYMBOL(ecm_db_connection_from_nat_interfaces_get_and_ref);

/*
 * ecm_db_connection_to_nat_interfaces_get_and_ref()
 *	Return the interface heirarchy to (nat) which this connection is established.
 *
 * 'interfaces' MUST be an array as large as ECM_DB_IFACE_HEIRARCHY_MAX.
 * Returns either ECM_DB_IFACE_HEIRARCHY_MAX if there are no interfaces / error.
 * Returns the index into the interfaces[] of the first interface (so "for (i = <ret val>, i < ECM_DB_IFACE_HEIRARCHY_MAX; ++i)" works)
 *
 * Each interface is referenced on return, be sure to release them individually or use ecm_db_connection_interfaces_deref() instead.
 */
int32_t ecm_db_connection_to_nat_interfaces_get_and_ref(struct ecm_db_connection_instance *ci, struct ecm_db_iface_instance *interfaces[])
{
	int32_t n;
	int32_t i;
	DEBUG_CHECK_MAGIC(ci, ECM_DB_CONNECTION_INSTANCE_MAGIC, "%p: magic failed\n", ci);

	spin_lock_bh(&ecm_db_lock);
	n = ci->to_nat_interface_first;
	for (i = n; i < ECM_DB_IFACE_HEIRARCHY_MAX; ++i) {
		interfaces[i] = ci->to_nat_interfaces[i];
		_ecm_db_iface_ref(interfaces[i]);
	}
	spin_unlock_bh(&ecm_db_lock);
	return n;
}
EXPORT_SYMBOL(ecm_db_connection_to_nat_interfaces_get_and_ref);

/*
 * ecm_db_connection_interfaces_deref()
 *	Release all interfaces in the given interfaces heirarchy array.
 *
 * 'first' is the number returned by one of the ecm_db_connection_xx_interfaces_get_and_ref().
 * You should NOT have released any references to any of the interfaces in the array youself, this releases them all.
 */
void ecm_db_connection_interfaces_deref(struct ecm_db_iface_instance *interfaces[], int32_t first)
{
	int32_t i;
	DEBUG_ASSERT((first >= 0) && (first <= ECM_DB_IFACE_HEIRARCHY_MAX), "Bad first: %d\n", first);

	for (i = first; i < ECM_DB_IFACE_HEIRARCHY_MAX; ++i) {
		ecm_db_iface_deref(interfaces[i]);
	}
}
EXPORT_SYMBOL(ecm_db_connection_interfaces_deref);

#ifdef ECM_MULTICAST_ENABLE
/*
 * ecm_db_multicast_connection_to_interfaces_reset()
 *	Reset the 'to' interfaces heirarchy with a new set of destination interfaces for
 *	the multicast connection
 */
int ecm_db_multicast_connection_to_interfaces_reset(struct ecm_db_connection_instance *ci, struct ecm_db_iface_instance *interfaces, int32_t *new_first)
{
	struct ecm_db_iface_instance *ii_temp;
	struct ecm_db_iface_instance *ii_single;
	struct ecm_db_iface_instance **ifaces;
	struct ecm_db_iface_instance *ii_db;
	struct ecm_db_iface_instance *ii_db_single;
	struct ecm_db_iface_instance **ifaces_db;
	int32_t *nf_p;
	int32_t heirarchy_index;
	int32_t i;
	DEBUG_CHECK_MAGIC(ci, ECM_DB_CONNECTION_INSTANCE_MAGIC, "%p: magic failed\n", ci);

	/*
	 * First remove all old interface hierarchies if any hierarchy
	 * uphold in the ci->to_mcast_interfaces.
	 */
	ecm_db_multicast_connection_to_interfaces_clear(ci);

	ci->to_mcast_interfaces = (struct ecm_db_iface_instance *)kzalloc(ECM_DB_TO_MCAST_INTERFACES_SIZE, GFP_ATOMIC | __GFP_NOWARN);
	if (!ci->to_mcast_interfaces) {
		DEBUG_WARN("%p: Memory is not available for to_mcast_interfaces\n", ci);
		return -1;
	}

	/*
	 * Iterate the to interface list and add the new interface hierarchies
	 */
	spin_lock_bh(&ecm_db_lock);

	for (heirarchy_index = 0; heirarchy_index < ECM_DB_MULTICAST_IF_MAX; heirarchy_index++) {
		ii_temp = ecm_db_multicast_if_heirarchy_get(interfaces, heirarchy_index);
		nf_p = ecm_db_multicast_if_first_get_at_index(new_first, heirarchy_index);

		if (*nf_p == ECM_DB_IFACE_HEIRARCHY_MAX) {
			continue;
		}

		for (i = *nf_p; i < ECM_DB_IFACE_HEIRARCHY_MAX; ++i) {

			/*
			 * Store valid dest interface list into DB connection
			 */
			ii_single = ecm_db_multicast_if_instance_get_at_index(ii_temp, i);
			ifaces = (struct ecm_db_iface_instance **)ii_single;

			ii_db = ecm_db_multicast_if_heirarchy_get(ci->to_mcast_interfaces, heirarchy_index);
			ii_db_single = ecm_db_multicast_if_instance_get_at_index(ii_db, i);
			ifaces_db = (struct ecm_db_iface_instance **)ii_db_single;

			*ifaces_db = *ifaces;
			_ecm_db_iface_ref(*ifaces_db);
		}
	}

	/*
	 * Update the first indices
	 */
	for (heirarchy_index = 0; heirarchy_index < ECM_DB_MULTICAST_IF_MAX; heirarchy_index++) {
		nf_p = ecm_db_multicast_if_first_get_at_index(new_first, heirarchy_index);
		ci->to_mcast_interface_first[heirarchy_index] = *nf_p;
	}

	ci->to_mcast_interfaces_set = true;
	spin_unlock_bh(&ecm_db_lock);

	return 0;
}
EXPORT_SYMBOL(ecm_db_multicast_connection_to_interfaces_reset);

/*
 *  ecm_db_multicast_connection_to_interfaces_update()
 *  	Merge the latest valid multicast destination interfaces into DB Connection
 *  	instance. The new list holds the updated list of interfaces for the multicast
 *  	connection, due to JOIN updates.
 */
void ecm_db_multicast_connection_to_interfaces_update(struct ecm_db_connection_instance *ci,
			struct ecm_db_iface_instance *interfaces, int32_t *mc_join_first, int32_t *mc_join_valid_idx)
{
	struct ecm_db_iface_instance *ii_temp;
	struct ecm_db_iface_instance *ii_single;
	struct ecm_db_iface_instance **ifaces;
	struct ecm_db_iface_instance *ii_db;
	struct ecm_db_iface_instance *ii_db_single;
	struct ecm_db_iface_instance **ifaces_db;
	int32_t *join_first;
	int32_t *join_idx;
	int heirarchy_index;
	int32_t if_index;
	int32_t i;

	DEBUG_CHECK_MAGIC(ci, ECM_DB_CONNECTION_INSTANCE_MAGIC, "%p: magic failed\n", ci);

	/*
	 * Iterate the to interface list, adding in the new
	 */
	spin_lock_bh(&ecm_db_lock);
	for (heirarchy_index = 0, if_index = 0; heirarchy_index < ECM_DB_MULTICAST_IF_MAX; heirarchy_index++) {
		ii_temp = ecm_db_multicast_if_heirarchy_get(interfaces, if_index);
		join_first = ecm_db_multicast_if_first_get_at_index(mc_join_first, if_index);
		join_idx = ecm_db_multicast_if_num_get_at_index(mc_join_valid_idx, heirarchy_index);

		if (*join_idx == 0) {

			/*
		 	 * No update for the interface at this index
		 	 */
			continue;
		}

		/*
		 * This interface has joined the group. Add it to the list.
		 */
		if (*join_first == ECM_DB_IFACE_HEIRARCHY_MAX) {
			if_index++;
			continue;
		}

		ci->to_mcast_interface_first[heirarchy_index] = *join_first;
		for (i = *join_first; i < ECM_DB_IFACE_HEIRARCHY_MAX; ++i) {

			/*
			 * Store valid dest interface list into DB connection
			 */
			ii_single = ecm_db_multicast_if_instance_get_at_index(ii_temp, i);
			ifaces = (struct ecm_db_iface_instance **)ii_single;
			ii_db = ecm_db_multicast_if_heirarchy_get(ci->to_mcast_interfaces, heirarchy_index);
			ii_db_single = ecm_db_multicast_if_instance_get_at_index(ii_db, i);
			ifaces_db = (struct ecm_db_iface_instance **)ii_db_single;
			*ifaces_db = *ifaces;
			_ecm_db_iface_ref(*ifaces_db);
		}
		if_index++;
	}
	spin_unlock_bh(&ecm_db_lock);
	return;
}
EXPORT_SYMBOL(ecm_db_multicast_connection_to_interfaces_update);
#endif

/*
 * ecm_db_connection_from_interfaces_reset()
 *	Reset the from interfaces heirarchy with a new set of interfaces
 *
 * NOTE: This will mark the list as set even if you specify no list as a replacement.
 * This is deliberate - it's stating that there is no list :-)
 */
void ecm_db_connection_from_interfaces_reset(struct ecm_db_connection_instance *ci, struct ecm_db_iface_instance *interfaces[], int32_t new_first)
{
	struct ecm_db_iface_instance *old[ECM_DB_IFACE_HEIRARCHY_MAX];
	int32_t old_first;
	int32_t i;
	DEBUG_CHECK_MAGIC(ci, ECM_DB_CONNECTION_INSTANCE_MAGIC, "%p: magic failed\n", ci);

	/*
	 * Iterate the from interface list, removing the old and adding in the new
	 */
	spin_lock_bh(&ecm_db_lock);
	for (i = 0; i < ECM_DB_IFACE_HEIRARCHY_MAX; ++i) {
		/*
		 * Put any previous interface into the old list
		 */
		old[i] = ci->from_interfaces[i];
		ci->from_interfaces[i] = NULL;
		if (i < new_first) {
			continue;
		}
		ci->from_interfaces[i] = interfaces[i];
		_ecm_db_iface_ref(ci->from_interfaces[i]);
	}

	/*
	 * Get old first and update to new first
	 */
	old_first = ci->from_interface_first;
	ci->from_interface_first = new_first;
	ci->from_interface_set = true;
	spin_unlock_bh(&ecm_db_lock);

	/*
	 * Release old
	 */
	ecm_db_connection_interfaces_deref(old, old_first);
}
EXPORT_SYMBOL(ecm_db_connection_from_interfaces_reset);

/*
 * ecm_db_connection_to_interfaces_reset()
 *	Reset the to interfaces heirarchy with a new set of interfaces
 *
 * NOTE: This will mark the list as set even if you specify no list as a replacement.
 * This is deliberate - it's stating that there is no list :-)
 */
void ecm_db_connection_to_interfaces_reset(struct ecm_db_connection_instance *ci, struct ecm_db_iface_instance *interfaces[], int32_t new_first)
{
	struct ecm_db_iface_instance *old[ECM_DB_IFACE_HEIRARCHY_MAX];
	int32_t old_first;
	int32_t i;
	DEBUG_CHECK_MAGIC(ci, ECM_DB_CONNECTION_INSTANCE_MAGIC, "%p: magic failed\n", ci);

	/*
	 * Iterate the to interface list, removing the old and adding in the new
	 */
	spin_lock_bh(&ecm_db_lock);
	for (i = 0; i < ECM_DB_IFACE_HEIRARCHY_MAX; ++i) {
		/*
		 * Put any previous interface into the old list
		 */
		old[i] = ci->to_interfaces[i];
		ci->to_interfaces[i] = NULL;
		if (i < new_first) {
			continue;
		}
		ci->to_interfaces[i] = interfaces[i];
		_ecm_db_iface_ref(ci->to_interfaces[i]);
	}

	/*
	 * Get old first and update to new first
	 */
	old_first = ci->to_interface_first;
	ci->to_interface_first = new_first;
	ci->to_interface_set = true;
	spin_unlock_bh(&ecm_db_lock);

	/*
	 * Release old
	 */
	ecm_db_connection_interfaces_deref(old, old_first);
}
EXPORT_SYMBOL(ecm_db_connection_to_interfaces_reset);

/*
 * ecm_db_connection_from_nat_interfaces_reset()
 *	Reset the from NAT interfaces heirarchy with a new set of interfaces
 *
 * NOTE: This will mark the list as set even if you specify no list as a replacement.
 * This is deliberate - it's stating that there is no list :-)
 */
void ecm_db_connection_from_nat_interfaces_reset(struct ecm_db_connection_instance *ci, struct ecm_db_iface_instance *interfaces[], int32_t new_first)
{
	struct ecm_db_iface_instance *old[ECM_DB_IFACE_HEIRARCHY_MAX];
	int32_t old_first;
	int32_t i;
	DEBUG_CHECK_MAGIC(ci, ECM_DB_CONNECTION_INSTANCE_MAGIC, "%p: magic failed\n", ci);

	/*
	 * Iterate the from nat interface list, removing the old and adding in the new
	 */
	spin_lock_bh(&ecm_db_lock);
	for (i = 0; i < ECM_DB_IFACE_HEIRARCHY_MAX; ++i) {
		/*
		 * Put any previous interface into the old list
		 */
		old[i] = ci->from_nat_interfaces[i];
		ci->from_nat_interfaces[i] = NULL;
		if (i < new_first) {
			continue;
		}
		ci->from_nat_interfaces[i] = interfaces[i];
		_ecm_db_iface_ref(ci->from_nat_interfaces[i]);
	}

	/*
	 * Get old first and update to new first
	 */
	old_first = ci->from_nat_interface_first;
	ci->from_nat_interface_first = new_first;
	ci->from_nat_interface_set = true;
	spin_unlock_bh(&ecm_db_lock);

	/*
	 * Release old
	 */
	ecm_db_connection_interfaces_deref(old, old_first);
}
EXPORT_SYMBOL(ecm_db_connection_from_nat_interfaces_reset);

/*
 * ecm_db_connection_to_nat_interfaces_reset()
 *	Reset the to NAT interfaces heirarchy with a new set of interfaces.
 *
 * NOTE: This will mark the list as set even if you specify no list as a replacement.
 * This is deliberate - it's stating that there is no list :-)
 */
void ecm_db_connection_to_nat_interfaces_reset(struct ecm_db_connection_instance *ci, struct ecm_db_iface_instance *interfaces[], int32_t new_first)
{
	struct ecm_db_iface_instance *old[ECM_DB_IFACE_HEIRARCHY_MAX];
	int32_t old_first;
	int32_t i;
	DEBUG_CHECK_MAGIC(ci, ECM_DB_CONNECTION_INSTANCE_MAGIC, "%p: magic failed\n", ci);

	/*
	 * Iterate the to nat interface list, removing the old and adding in the new
	 */
	spin_lock_bh(&ecm_db_lock);
	for (i = 0; i < ECM_DB_IFACE_HEIRARCHY_MAX; ++i) {
		/*
		 * Put any previous interface into the old list
		 */
		old[i] = ci->to_nat_interfaces[i];
		ci->to_nat_interfaces[i] = NULL;
		if (i < new_first) {
			continue;
		}
		ci->to_nat_interfaces[i] = interfaces[i];
		_ecm_db_iface_ref(ci->to_nat_interfaces[i]);
	}

	/*
	 * Get old first and update to new first
	 */
	old_first = ci->to_nat_interface_first;
	ci->to_nat_interface_first = new_first;
	ci->to_nat_interface_set = true;
	spin_unlock_bh(&ecm_db_lock);

	/*
	 * Release old
	 */
	ecm_db_connection_interfaces_deref(old, old_first);
}
EXPORT_SYMBOL(ecm_db_connection_to_nat_interfaces_reset);

/*
 * ecm_db_connection_to_nat_interfaces_get_count()
 *	Return the number of interfaces in the list
 */
int32_t ecm_db_connection_to_nat_interfaces_get_count(struct ecm_db_connection_instance *ci)
{
	int32_t first;
	DEBUG_CHECK_MAGIC(ci, ECM_DB_CONNECTION_INSTANCE_MAGIC, "%p: magic failed\n", ci);
	spin_lock_bh(&ecm_db_lock);
	first = ci->to_nat_interface_first;
	spin_unlock_bh(&ecm_db_lock);
	return ECM_DB_IFACE_HEIRARCHY_MAX - first;
}
EXPORT_SYMBOL(ecm_db_connection_to_nat_interfaces_get_count);

/*
 * ecm_db_connection_from_nat_interfaces_get_count()
 *	Return the number of interfaces in the list
 */
int32_t ecm_db_connection_from_nat_interfaces_get_count(struct ecm_db_connection_instance *ci)
{
	int32_t first;
	DEBUG_CHECK_MAGIC(ci, ECM_DB_CONNECTION_INSTANCE_MAGIC, "%p: magic failed\n", ci);
	spin_lock_bh(&ecm_db_lock);
	first = ci->from_nat_interface_first;
	spin_unlock_bh(&ecm_db_lock);
	return ECM_DB_IFACE_HEIRARCHY_MAX - first;
}
EXPORT_SYMBOL(ecm_db_connection_from_nat_interfaces_get_count);

/*
 * ecm_db_connection_to_interfaces_get_count()
 *	Return the number of interfaces in the list
 */
int32_t ecm_db_connection_to_interfaces_get_count(struct ecm_db_connection_instance *ci)
{
	int32_t first;
	DEBUG_CHECK_MAGIC(ci, ECM_DB_CONNECTION_INSTANCE_MAGIC, "%p: magic failed\n", ci);
	spin_lock_bh(&ecm_db_lock);
	first = ci->to_interface_first;
	spin_unlock_bh(&ecm_db_lock);
	return ECM_DB_IFACE_HEIRARCHY_MAX - first;
}
EXPORT_SYMBOL(ecm_db_connection_to_interfaces_get_count);

/*
 * ecm_db_connection_from_interfaces_get_count()
 *	Return the number of interfaces in the list
 */
int32_t ecm_db_connection_from_interfaces_get_count(struct ecm_db_connection_instance *ci)
{
	int32_t first;
	DEBUG_CHECK_MAGIC(ci, ECM_DB_CONNECTION_INSTANCE_MAGIC, "%p: magic failed\n", ci);
	spin_lock_bh(&ecm_db_lock);
	first = ci->from_interface_first;
	spin_unlock_bh(&ecm_db_lock);
	return ECM_DB_IFACE_HEIRARCHY_MAX - first;
}
EXPORT_SYMBOL(ecm_db_connection_from_interfaces_get_count);

/*
 * ecm_db_connection_to_interfaces_set_check()
 *	Returns true if the interface list has been set - even if set to an empty list!
 */
bool ecm_db_connection_to_interfaces_set_check(struct ecm_db_connection_instance *ci)
{
	bool set;

	DEBUG_CHECK_MAGIC(ci, ECM_DB_CONNECTION_INSTANCE_MAGIC, "%p: magic failed\n", ci);
	spin_lock_bh(&ecm_db_lock);
	set = ci->to_interface_set;
	spin_unlock_bh(&ecm_db_lock);
	return set;
}
EXPORT_SYMBOL(ecm_db_connection_to_interfaces_set_check);

/*
 * ecm_db_connection_from_interfaces_set_check()
 *	Returns true if the interface list has been set - even if set to an empty list!
 */
bool ecm_db_connection_from_interfaces_set_check(struct ecm_db_connection_instance *ci)
{
	bool set;

	DEBUG_CHECK_MAGIC(ci, ECM_DB_CONNECTION_INSTANCE_MAGIC, "%p: magic failed\n", ci);
	spin_lock_bh(&ecm_db_lock);
	set = ci->from_interface_set;
	spin_unlock_bh(&ecm_db_lock);
	return set;
}
EXPORT_SYMBOL(ecm_db_connection_from_interfaces_set_check);

/*
 * ecm_db_connection_to_nat_interfaces_set_check()
 *	Returns true if the interface list has been set - even if set to an empty list!
 */
bool ecm_db_connection_to_nat_interfaces_set_check(struct ecm_db_connection_instance *ci)
{
	bool set;

	DEBUG_CHECK_MAGIC(ci, ECM_DB_CONNECTION_INSTANCE_MAGIC, "%p: magic failed\n", ci);
	spin_lock_bh(&ecm_db_lock);
	set = ci->to_nat_interface_set;
	spin_unlock_bh(&ecm_db_lock);
	return set;
}
EXPORT_SYMBOL(ecm_db_connection_to_nat_interfaces_set_check);

/*
 * ecm_db_connection_from_nat_interfaces_set_check()
 *	Returns true if the interface list has been set - even if set to an empty list!
 */
bool ecm_db_connection_from_nat_interfaces_set_check(struct ecm_db_connection_instance *ci)
{
	bool set;

	DEBUG_CHECK_MAGIC(ci, ECM_DB_CONNECTION_INSTANCE_MAGIC, "%p: magic failed\n", ci);
	spin_lock_bh(&ecm_db_lock);
	set = ci->from_nat_interface_set;
	spin_unlock_bh(&ecm_db_lock);
	return set;
}
EXPORT_SYMBOL(ecm_db_connection_from_nat_interfaces_set_check);

/*
 * ecm_db_connection_from_interfaces_clear()
 *	Clear down the interfaces list, marking the list as not set
 */
void ecm_db_connection_from_interfaces_clear(struct ecm_db_connection_instance *ci)
{
	struct ecm_db_iface_instance *discard[ECM_DB_IFACE_HEIRARCHY_MAX];
	int32_t discard_first;
	int32_t i;

	DEBUG_CHECK_MAGIC(ci, ECM_DB_CONNECTION_INSTANCE_MAGIC, "%p: magic failed\n", ci);

	spin_lock_bh(&ecm_db_lock);
	for (i = ci->from_interface_first; i < ECM_DB_IFACE_HEIRARCHY_MAX; ++i) {
		discard[i] = ci->from_interfaces[i];
	}

	discard_first = ci->from_interface_first;
	ci->from_interface_set = false;
	ci->from_interface_first = ECM_DB_IFACE_HEIRARCHY_MAX;
	spin_unlock_bh(&ecm_db_lock);

	/*
	 * Release previous
	 */
	ecm_db_connection_interfaces_deref(discard, discard_first);
}
EXPORT_SYMBOL(ecm_db_connection_from_interfaces_clear);

/*
 * ecm_db_connection_from_nat_interfaces_clear()
 *	Clear down the interfaces list, marking the list as not set
 */
void ecm_db_connection_from_nat_interfaces_clear(struct ecm_db_connection_instance *ci)
{
	struct ecm_db_iface_instance *discard[ECM_DB_IFACE_HEIRARCHY_MAX];
	int32_t discard_first;
	int32_t i;

	DEBUG_CHECK_MAGIC(ci, ECM_DB_CONNECTION_INSTANCE_MAGIC, "%p: magic failed\n", ci);

	spin_lock_bh(&ecm_db_lock);
	for (i = ci->from_nat_interface_first; i < ECM_DB_IFACE_HEIRARCHY_MAX; ++i) {
		discard[i] = ci->from_nat_interfaces[i];
	}

	discard_first = ci->from_nat_interface_first;
	ci->from_nat_interface_set = false;
	ci->from_nat_interface_first = ECM_DB_IFACE_HEIRARCHY_MAX;
	spin_unlock_bh(&ecm_db_lock);

	/*
	 * Release previous
	 */
	ecm_db_connection_interfaces_deref(discard, discard_first);
}
EXPORT_SYMBOL(ecm_db_connection_from_nat_interfaces_clear);

/*
 * ecm_db_connection_to_interfaces_clear()
 *	Clear down the interfaces list, marking the list as not set
 */
void ecm_db_connection_to_interfaces_clear(struct ecm_db_connection_instance *ci)
{
	struct ecm_db_iface_instance *discard[ECM_DB_IFACE_HEIRARCHY_MAX];
	int32_t discard_first;
	int32_t i;

	DEBUG_CHECK_MAGIC(ci, ECM_DB_CONNECTION_INSTANCE_MAGIC, "%p: magic failed\n", ci);

	spin_lock_bh(&ecm_db_lock);
	for (i = ci->to_interface_first; i < ECM_DB_IFACE_HEIRARCHY_MAX; ++i) {
		discard[i] = ci->to_interfaces[i];
	}

	discard_first = ci->to_interface_first;
	ci->to_interface_set = false;
	ci->to_interface_first = ECM_DB_IFACE_HEIRARCHY_MAX;
	spin_unlock_bh(&ecm_db_lock);

	/*
	 * Release previous
	 */
	ecm_db_connection_interfaces_deref(discard, discard_first);
}
EXPORT_SYMBOL(ecm_db_connection_to_interfaces_clear);

/*
 * ecm_db_connection_to_nat_interfaces_clear()
 *	Clear down the interfaces list, marking the list as not set
 */
void ecm_db_connection_to_nat_interfaces_clear(struct ecm_db_connection_instance *ci)
{
	struct ecm_db_iface_instance *discard[ECM_DB_IFACE_HEIRARCHY_MAX];
	int32_t discard_first;
	int32_t i;

	DEBUG_CHECK_MAGIC(ci, ECM_DB_CONNECTION_INSTANCE_MAGIC, "%p: magic failed\n", ci);

	spin_lock_bh(&ecm_db_lock);
	for (i = ci->to_nat_interface_first; i < ECM_DB_IFACE_HEIRARCHY_MAX; ++i) {
		discard[i] = ci->to_nat_interfaces[i];
	}

	discard_first = ci->to_nat_interface_first;
	ci->to_nat_interface_set = false;
	ci->to_nat_interface_first = ECM_DB_IFACE_HEIRARCHY_MAX;
	spin_unlock_bh(&ecm_db_lock);

	/*
	 * Release previous
	 */
	ecm_db_connection_interfaces_deref(discard, discard_first);
}
EXPORT_SYMBOL(ecm_db_connection_to_nat_interfaces_clear);

/*
 * ecm_db_front_end_instance_ref_and_set()
 *	Refs and sets the front end instance of connection.
 */
void ecm_db_front_end_instance_ref_and_set(struct ecm_db_connection_instance *ci, struct ecm_front_end_connection_instance *feci)
{
	DEBUG_CHECK_MAGIC(ci, ECM_DB_CONNECTION_INSTANCE_MAGIC, "%p: magic failed\n", ci);

	feci->ref(feci);
	ci->feci = feci;
}
EXPORT_SYMBOL(ecm_db_front_end_instance_ref_and_set);

/*
 * ecm_db_connection_add()
 *	Add the connection into the database.
 *
 * NOTE: The parameters are DIRECTIONAL in terms of which mapping established the connection.
 * NOTE: Dir confirms if this is an egressing or ingressing connection.  This applies to firewalling front ends mostly. If INGRESS then mapping_from is the WAN side.  If EGRESS then mapping_to is the WAN side.
 */
void ecm_db_connection_add(struct ecm_db_connection_instance *ci,
							struct ecm_db_mapping_instance *mapping_from, struct ecm_db_mapping_instance *mapping_to,
							struct ecm_db_mapping_instance *mapping_nat_from, struct ecm_db_mapping_instance *mapping_nat_to,
							struct ecm_db_node_instance *from_node, struct ecm_db_node_instance *to_node,
							struct ecm_db_node_instance *from_nat_node, struct ecm_db_node_instance *to_nat_node,
							int ip_version,
							int protocol, ecm_db_direction_t dir,
							ecm_db_connection_final_callback_t final,
							ecm_db_connection_defunct_callback_t defunct,
							ecm_db_timer_group_t tg, bool is_routed,
							void *arg)
{
	ecm_db_connection_hash_t hash_index;
	ecm_db_connection_serial_hash_t serial_hash_index;
	struct ecm_db_listener_instance *li;
#ifdef ECM_DB_XREF_ENABLE
	struct ecm_db_iface_instance *iface_from;
	struct ecm_db_iface_instance *iface_to;
	struct ecm_db_iface_instance *iface_nat_from;
	struct ecm_db_iface_instance *iface_nat_to;
#endif

	DEBUG_CHECK_MAGIC(ci, ECM_DB_CONNECTION_INSTANCE_MAGIC, "%p: magic failed\n", ci);
	DEBUG_CHECK_MAGIC(mapping_from, ECM_DB_MAPPING_INSTANCE_MAGIC, "%p: magic failed\n", mapping_from);
	DEBUG_CHECK_MAGIC(mapping_to, ECM_DB_MAPPING_INSTANCE_MAGIC, "%p: magic failed\n", mapping_to);
	DEBUG_CHECK_MAGIC(mapping_nat_from, ECM_DB_MAPPING_INSTANCE_MAGIC, "%p: magic failed\n", mapping_nat_from);
	DEBUG_CHECK_MAGIC(mapping_nat_to, ECM_DB_MAPPING_INSTANCE_MAGIC, "%p: magic failed\n", mapping_nat_to);
	DEBUG_CHECK_MAGIC(from_node, ECM_DB_NODE_INSTANCE_MAGIC, "%p: magic failed\n", from_node);
	DEBUG_CHECK_MAGIC(to_node, ECM_DB_NODE_INSTANCE_MAGIC, "%p: magic failed\n", to_node);
	DEBUG_CHECK_MAGIC(from_nat_node, ECM_DB_NODE_INSTANCE_MAGIC, "%p: magic failed\n", from_nat_node);
	DEBUG_CHECK_MAGIC(to_nat_node, ECM_DB_NODE_INSTANCE_MAGIC, "%p: magic failed\n", to_nat_node);
	DEBUG_ASSERT((protocol >= 0) && (protocol <= 255), "%p: invalid protocol number %d\n", ci, protocol);

	spin_lock_bh(&ecm_db_lock);
	DEBUG_ASSERT(!(ci->flags & ECM_DB_CONNECTION_FLAGS_INSERTED), "%p: inserted\n", ci);
	spin_unlock_bh(&ecm_db_lock);

	/*
	 * Record owner arg and callbacks
	 */
	ci->final = final;
	ci->defunct = defunct;
	ci->arg = arg;

#ifdef ECM_MULTICAST_ENABLE
	ci->ti = NULL;
#endif

	/*
	 * Ensure default classifier has been assigned this is a must to ensure minimum level of classification
	 */
	DEBUG_ASSERT(ci->assignments_by_type[ECM_CLASSIFIER_TYPE_DEFAULT], "%p: No default classifier assigned\n", ci);

	/*
	 * Connection takes references to the mappings
	 */
	ecm_db_mapping_ref(mapping_from);
	ecm_db_mapping_ref(mapping_to);
	ci->mapping_from = mapping_from;
	ci->mapping_to = mapping_to;

	ecm_db_mapping_ref(mapping_nat_from);
	ecm_db_mapping_ref(mapping_nat_to);
	ci->mapping_nat_from = mapping_nat_from;
	ci->mapping_nat_to = mapping_nat_to;

	/*
	 * Take references to the nodes
	 */
	ci->from_node = from_node;
	ecm_db_node_ref(from_node);
	ci->to_node = to_node;
	ecm_db_node_ref(to_node);

	ci->from_nat_node = from_nat_node;
	ecm_db_node_ref(from_nat_node);
	ci->to_nat_node = to_nat_node;
	ecm_db_node_ref(to_nat_node);

	/*
	 * Set the protocol and routed flag
	 */
	ci->ip_version = ip_version;
	ci->protocol = protocol;
	ci->is_routed = is_routed;

	/*
	 * Set direction of connection
	 */
	ci->direction = dir;

	/*
	 * Identify which hash chain this connection will go into
	 */
       	hash_index = ecm_db_connection_generate_hash_index(mapping_from->host->address, mapping_from->port, mapping_to->host->address, mapping_to->port, protocol);
	ci->hash_index = hash_index;

	/*
	 * Identify which serial hash chain this connection will go into
	 */
       	serial_hash_index = ecm_db_connection_generate_serial_hash_index(ci->serial);
	ci->serial_hash_index = serial_hash_index;

	/*
	 * Now we need to lock
	 */
	spin_lock_bh(&ecm_db_lock);

	/*
	 * Increment protocol counter stats
	 */
	ecm_db_connection_count_by_protocol[protocol]++;
	DEBUG_ASSERT(ecm_db_connection_count_by_protocol[protocol] > 0, "%p: Invalid protocol count %d\n", ci, ecm_db_connection_count_by_protocol[protocol]);

	/*
	 * Set time
	 */
	ci->time_added = ecm_db_time;

	/*
	 * Add connection into the global list
	 */
	ci->prev = NULL;
	ci->next = ecm_db_connections;
	if (ecm_db_connections) {
		ecm_db_connections->prev = ci;
	}
	ecm_db_connections = ci;

	/*
	 * Add this connection into the connections hash table
	 */
	ci->flags |= ECM_DB_CONNECTION_FLAGS_INSERTED;

	/*
	 * Insert connection into the connections hash table
	 */
	ci->hash_next = ecm_db_connection_table[hash_index];
	if (ecm_db_connection_table[hash_index]) {
		ecm_db_connection_table[hash_index]->hash_prev = ci;
	}
	ecm_db_connection_table[hash_index] = ci;
	ecm_db_connection_table_lengths[hash_index]++;
	DEBUG_ASSERT(ecm_db_connection_table_lengths[hash_index] > 0, "%p: invalid table len %d\n", ci, ecm_db_connection_table_lengths[hash_index]);

	/*
	 * Insert connection into the connections serial hash table
	 */
	ci->serial_hash_next = ecm_db_connection_serial_table[serial_hash_index];
	if (ecm_db_connection_serial_table[serial_hash_index]) {
		ecm_db_connection_serial_table[serial_hash_index]->serial_hash_prev = ci;
	}
	ecm_db_connection_serial_table[serial_hash_index] = ci;
	ecm_db_connection_serial_table_lengths[serial_hash_index]++;
	DEBUG_ASSERT(ecm_db_connection_serial_table_lengths[serial_hash_index] > 0, "%p: invalid table len %d\n", ci, ecm_db_connection_serial_table_lengths[serial_hash_index]);

#ifdef ECM_DB_XREF_ENABLE
	/*
	 * Add this connection into the FROM node
	 */
	ci->node_from_prev = NULL;
	ci->node_from_next = from_node->from_connections;
	if (from_node->from_connections) {
		from_node->from_connections->node_from_prev = ci;
	}
	from_node->from_connections = ci;
	from_node->from_connections_count++;
	DEBUG_ASSERT(from_node->from_connections_count > 0, "%p: invalid count\n", ci);

	/*
	 * Add this connection into the TO node
	 */
	ci->node_to_prev = NULL;
	ci->node_to_next = to_node->to_connections;
	if (to_node->to_connections) {
		to_node->to_connections->node_to_prev = ci;
	}
	to_node->to_connections = ci;
	to_node->to_connections_count++;
	DEBUG_ASSERT(to_node->to_connections_count > 0, "%p: invalid count\n", ci);

	/*
	 * Add this connection into the FROM NAT node
	 */
	ci->node_from_nat_prev = NULL;
	ci->node_from_nat_next = from_nat_node->from_nat_connections;
	if (from_nat_node->from_nat_connections) {
		from_nat_node->from_nat_connections->node_from_nat_prev = ci;
	}
	from_nat_node->from_nat_connections = ci;
	from_nat_node->from_nat_connections_count++;
	DEBUG_ASSERT(from_nat_node->from_nat_connections_count > 0, "%p: invalid count\n", ci);

	/*
	 * Add this connection into the TO NAT node
	 */
	ci->node_to_nat_prev = NULL;
	ci->node_to_nat_next = to_nat_node->to_nat_connections;
	if (to_nat_node->to_nat_connections) {
		to_nat_node->to_nat_connections->node_to_nat_prev = ci;
	}
	to_nat_node->to_nat_connections = ci;
	to_nat_node->to_nat_connections_count++;
	DEBUG_ASSERT(to_nat_node->to_nat_connections_count > 0, "%p: invalid count\n", ci);

	/*
	 * Add this connection into the FROM mapping
	 */
	ci->from_prev = NULL;
	ci->from_next = mapping_from->from_connections;
	if (mapping_from->from_connections) {
		mapping_from->from_connections->from_prev = ci;
	}
	mapping_from->from_connections = ci;

	/*
	 * Add this connection into the TO mapping
	 */
	ci->to_prev = NULL;
	ci->to_next = mapping_to->to_connections;
	if (mapping_to->to_connections) {
		mapping_to->to_connections->to_prev = ci;
	}
	mapping_to->to_connections = ci;

	/*
	 * Add this connection into the FROM NAT mapping
	 */
	ci->from_nat_prev = NULL;
	ci->from_nat_next = mapping_nat_from->from_nat_connections;
	if (mapping_nat_from->from_nat_connections) {
		mapping_nat_from->from_nat_connections->from_nat_prev = ci;
	}
	mapping_nat_from->from_nat_connections = ci;

	/*
	 * Add this connection into the TO NAT mapping
	 */
	ci->to_nat_prev = NULL;
	ci->to_nat_next = mapping_nat_to->to_nat_connections;
	if (mapping_nat_to->to_nat_connections) {
		mapping_nat_to->to_nat_connections->to_nat_prev = ci;
	}
	mapping_nat_to->to_nat_connections = ci;

	/*
	 * Add this connection into the FROM iface list of connections
	 * NOTE: There is no need to ref the iface because it will exist for as long as this connection exists
	 * due to the heirarchy of dependencies being kept by the database.
	 */
	iface_from = from_node->iface;
	ci->iface_from_prev = NULL;
	ci->iface_from_next = iface_from->from_connections;
	if (iface_from->from_connections) {
		iface_from->from_connections->iface_from_prev = ci;
	}
	iface_from->from_connections = ci;

	/*
	 * Add this connection into the TO iface list of connections
	 * NOTE: There is no need to ref the iface because it will exist for as long as this connection exists
	 * due to the heirarchy of dependencies being kept by the database.
	 */
	iface_to = to_node->iface;
	ci->iface_to_prev = NULL;
	ci->iface_to_next = iface_to->to_connections;
	if (iface_to->to_connections) {
		iface_to->to_connections->iface_to_prev = ci;
	}
	iface_to->to_connections = ci;

	/*
	 * Add this connection into the FROM NAT iface list of connections
	 * NOTE: There is no need to ref the iface because it will exist for as long as this connection exists
	 * due to the heirarchy of dependencies being kept by the database.
	 */
	iface_nat_from = from_nat_node->iface;
	ci->iface_from_nat_prev = NULL;
	ci->iface_from_nat_next = iface_nat_from->from_nat_connections;
	if (iface_nat_from->from_nat_connections) {
		iface_nat_from->from_nat_connections->iface_from_nat_prev = ci;
	}
	iface_nat_from->from_nat_connections = ci;

	/*
	 * Add this connection into the TO NAT iface list of connections
	 * NOTE: There is no need to ref the iface because it will exist for as long as this connection exists
	 * due to the heirarchy of dependencies being kept by the database.
	 */
	iface_nat_to = to_nat_node->iface;
	ci->iface_to_nat_prev = NULL;
	ci->iface_to_nat_next = iface_nat_to->to_nat_connections;
	if (iface_nat_to->to_nat_connections) {
		iface_nat_to->to_nat_connections->iface_to_nat_prev = ci;
	}
	iface_nat_to->to_nat_connections = ci;
#endif

	/*
	 * NOTE: The interface heirarchy lists are deliberately left empty - these are completed
	 * by the front end if it is appropriate to do so.
	 */

	/*
	 * Update the counters in the mapping
	 */
	if (protocol == IPPROTO_UDP) {
		mapping_from->udp_from++;
		mapping_to->udp_to++;
		mapping_nat_from->udp_nat_from++;
		mapping_nat_to->udp_nat_to++;
	} else if (protocol == IPPROTO_TCP) {
		mapping_from->tcp_from++;
		mapping_to->tcp_to++;
		mapping_nat_from->tcp_nat_from++;
		mapping_nat_to->tcp_nat_to++;
	}

	mapping_from->from++;
	mapping_to->to++;
	mapping_nat_from->nat_from++;
	mapping_nat_to->nat_to++;

	/*
	 * Set the generation number to match global
	 */
	ci->generation = ecm_db_connection_generation;

	spin_unlock_bh(&ecm_db_lock);

	/*
	 * Throw add event to the listeners
 	 */
	DEBUG_TRACE("%p: Throw connection added event\n", ci);
	li = ecm_db_listeners_get_and_ref_first();
	while (li) {
		struct ecm_db_listener_instance *lin;
		if (li->connection_added) {
			li->connection_added(li->arg, ci);
		}

		/*
		 * Get next listener
		 */
		lin = ecm_db_listener_get_and_ref_next(li);
		ecm_db_listener_deref(li);
		li = lin;
	}

	/*
	 * Set timer group. 'ref' the connection to ensure it persists for the timer.
	 */
	ecm_db_connection_ref(ci);
	ecm_db_timer_group_entry_set(&ci->defunct_timer, tg);
}
EXPORT_SYMBOL(ecm_db_connection_add);

/*
 * ecm_db_mapping_add()
 *	Add a mapping instance into the database
 *
 * NOTE: The mapping will take a reference to the host instance.
 */
void ecm_db_mapping_add(struct ecm_db_mapping_instance *mi, struct ecm_db_host_instance *hi, int port,
						ecm_db_mapping_final_callback_t final, void *arg)
{
	ecm_db_mapping_hash_t hash_index;
	struct ecm_db_listener_instance *li;

	spin_lock_bh(&ecm_db_lock);
	DEBUG_CHECK_MAGIC(mi, ECM_DB_MAPPING_INSTANCE_MAGIC, "%p: magic failed\n", mi);
	DEBUG_CHECK_MAGIC(hi, ECM_DB_HOST_INSTANCE_MAGIC, "%p: magic failed\n", hi);
	DEBUG_ASSERT(!(mi->flags & ECM_DB_MAPPING_FLAGS_INSERTED), "%p: inserted\n", mi);
	DEBUG_ASSERT((hi->flags & ECM_DB_HOST_FLAGS_INSERTED), "%p: not inserted\n", hi);
	DEBUG_ASSERT(!mi->tcp_from && !mi->tcp_to && !mi->udp_from && !mi->udp_to, "%p: protocol count errors\n", mi);
#ifdef ECM_DB_XREF_ENABLE
	DEBUG_ASSERT(mi->from_connections == NULL, "%p: connections not null\n", mi);
	DEBUG_ASSERT(mi->to_connections == NULL, "%p: connections not null\n", mi);
	DEBUG_ASSERT(!mi->from && !mi->to && !mi->nat_from && !mi->nat_to, "%p: connection count errors\n", mi);
#endif
	spin_unlock_bh(&ecm_db_lock);

	mi->arg = arg;
	mi->final = final;

       	/*
	 * Compute hash table position for insertion
	 */
	hash_index = ecm_db_mapping_generate_hash_index(hi->address, port);
	mi->hash_index = hash_index;

       	/*
	 * Record port
	 */
	mi->port = port;

	/*
	 * Mapping takes a ref to the host
	 */
	ecm_db_host_ref(hi);
	mi->host = hi;

	/*
	 * Set time
	 */
	spin_lock_bh(&ecm_db_lock);
	mi->time_added = ecm_db_time;

	/*
	 * Record the mapping is inserted
	 */
	mi->flags |= ECM_DB_MAPPING_FLAGS_INSERTED;

	/*
	 * Add into the global list
	 */
	mi->prev = NULL;
	mi->next = ecm_db_mappings;
	if (ecm_db_mappings) {
		ecm_db_mappings->prev = mi;
	}
	ecm_db_mappings = mi;

	/*
	 * Insert mapping into the mappings hash table
	 */
	mi->hash_next = ecm_db_mapping_table[hash_index];
	if (ecm_db_mapping_table[hash_index]) {
		ecm_db_mapping_table[hash_index]->hash_prev = mi;
	}
	ecm_db_mapping_table[hash_index] = mi;
	ecm_db_mapping_table_lengths[hash_index]++;
	DEBUG_ASSERT(ecm_db_mapping_table_lengths[hash_index] > 0, "%p: invalid table len %d\n", hi, ecm_db_mapping_table_lengths[hash_index]);

#ifdef ECM_DB_XREF_ENABLE
	/*
	 * Insert mapping into the host mapping list
	 */
	mi->mapping_prev = NULL;
	mi->mapping_next = hi->mappings;
	if (hi->mappings) {
		hi->mappings->mapping_prev = mi;
	}
	hi->mappings = mi;
	hi->mapping_count++;
#endif
	spin_unlock_bh(&ecm_db_lock);

	/*
	 * Throw add event to the listeners
 	 */
	DEBUG_TRACE("%p: Throw mapping added event\n", mi);
	li = ecm_db_listeners_get_and_ref_first();
	while (li) {
		struct ecm_db_listener_instance *lin;
		if (li->mapping_added) {
			li->mapping_added(li->arg, mi);
		}

		/*
		 * Get next listener
		 */
		lin = ecm_db_listener_get_and_ref_next(li);
		ecm_db_listener_deref(li);
		li = lin;
	}
}
EXPORT_SYMBOL(ecm_db_mapping_add);

/*
 * ecm_db_host_add()
 *	Add a host instance into the database
 */
void ecm_db_host_add(struct ecm_db_host_instance *hi, ip_addr_t address, bool on_link, ecm_db_host_final_callback_t final, void *arg)
{
	ecm_db_host_hash_t hash_index;
	struct ecm_db_listener_instance *li;

	spin_lock_bh(&ecm_db_lock);
	DEBUG_CHECK_MAGIC(hi, ECM_DB_HOST_INSTANCE_MAGIC, "%p: magic failed\n", hi);
	DEBUG_ASSERT(!(hi->flags & ECM_DB_HOST_FLAGS_INSERTED), "%p: inserted\n", hi);
#ifdef ECM_DB_XREF_ENABLE
	DEBUG_ASSERT((hi->mappings == NULL) && (hi->mapping_count == 0), "%p: mappings not null\n", hi);
#endif
	spin_unlock_bh(&ecm_db_lock);

	hi->arg = arg;
	hi->final = final;
	ECM_IP_ADDR_COPY(hi->address, address);
	hi->on_link = on_link;

       	/*
	 * Compute hash index into which host will be added
	 */
	hash_index = ecm_db_host_generate_hash_index(address);
	hi->hash_index = hash_index;

	/*
	 * Add into the global list
	 */
	spin_lock_bh(&ecm_db_lock);
	hi->flags |= ECM_DB_HOST_FLAGS_INSERTED;
	hi->prev = NULL;
	hi->next = ecm_db_hosts;
	if (ecm_db_hosts) {
		ecm_db_hosts->prev = hi;
	}
	ecm_db_hosts = hi;

	/*
	 * Add host into the hash table
	 */
	hi->hash_next = ecm_db_host_table[hash_index];
	if (ecm_db_host_table[hash_index]) {
		ecm_db_host_table[hash_index]->hash_prev = hi;
	}
	ecm_db_host_table[hash_index] = hi;
	ecm_db_host_table_lengths[hash_index]++;
	DEBUG_ASSERT(ecm_db_host_table_lengths[hash_index] > 0, "%p: invalid table len %d\n", hi, ecm_db_host_table_lengths[hash_index]);

	/*
	 * Set time of add
	 */
	hi->time_added = ecm_db_time;
	spin_unlock_bh(&ecm_db_lock);

	/*
	 * Throw add event to the listeners
 	 */
	DEBUG_TRACE("%p: Throw host added event\n", hi);
	li = ecm_db_listeners_get_and_ref_first();
	while (li) {
		struct ecm_db_listener_instance *lin;
		if (li->host_added) {
			li->host_added(li->arg, hi);
		}

		/*
		 * Get next listener
		 */
		lin = ecm_db_listener_get_and_ref_next(li);
		ecm_db_listener_deref(li);
		li = lin;
	}
}
EXPORT_SYMBOL(ecm_db_host_add);

/*
 * ecm_db_node_add()
 *	Add a node instance into the database
 */
void ecm_db_node_add(struct ecm_db_node_instance *ni, struct ecm_db_iface_instance *ii, uint8_t *address,
					ecm_db_node_final_callback_t final, void *arg)
{
	ecm_db_node_hash_t hash_index;
	struct ecm_db_listener_instance *li;

	spin_lock_bh(&ecm_db_lock);
	DEBUG_CHECK_MAGIC(ni, ECM_DB_NODE_INSTANCE_MAGIC, "%p: magic failed\n", ni);
	DEBUG_CHECK_MAGIC(ii, ECM_DB_IFACE_INSTANCE_MAGIC, "%p: magic failed\n", ii);
	DEBUG_ASSERT(address, "%p: address null\n", ni);
	DEBUG_ASSERT((ni->iface == NULL), "%p: iface not null\n", ni);
	DEBUG_ASSERT(!(ni->flags & ECM_DB_NODE_FLAGS_INSERTED), "%p: inserted\n", ni);
#ifdef ECM_DB_XREF_ENABLE
	DEBUG_ASSERT((ni->from_connections == NULL) && (ni->from_connections_count == 0), "%p: from_connections not null\n", ni);
	DEBUG_ASSERT((ni->to_connections == NULL) && (ni->to_connections_count == 0), "%p: to_connections not null\n", ni);
	DEBUG_ASSERT((ni->from_nat_connections == NULL) && (ni->from_nat_connections_count == 0), "%p: from_nat_connections not null\n", ni);
	DEBUG_ASSERT((ni->to_nat_connections == NULL) && (ni->to_nat_connections_count == 0), "%p: to_nat_connections not null\n", ni);
#endif
	spin_unlock_bh(&ecm_db_lock);

	memcpy(ni->address, address, ETH_ALEN);
	ni->arg = arg;
	ni->final = final;

	/*
	 * Compute hash chain for insertion
	 */
	hash_index = ecm_db_node_generate_hash_index(address);
	ni->hash_index = hash_index;

	/*
	 * Node takes a ref to the iface
	 */
	ecm_db_iface_ref(ii);
	ni->iface = ii;

	/*
	 * Add into the global list
	 */
	spin_lock_bh(&ecm_db_lock);
	ni->flags |= ECM_DB_NODE_FLAGS_INSERTED;
	ni->prev = NULL;
	ni->next = ecm_db_nodes;
	if (ecm_db_nodes) {
		ecm_db_nodes->prev = ni;
	}
	ecm_db_nodes = ni;

	/*
	 * Insert into the hash chain
	 */
	ni->hash_next = ecm_db_node_table[hash_index];
	if (ecm_db_node_table[hash_index]) {
		ecm_db_node_table[hash_index]->hash_prev = ni;
	}
	ecm_db_node_table[hash_index] = ni;
	ecm_db_node_table_lengths[hash_index]++;
	DEBUG_ASSERT(ecm_db_node_table_lengths[hash_index] > 0, "%p: invalid table len %d\n", ni, ecm_db_node_table_lengths[hash_index]);

	/*
	 * Set time of add
	 */
	ni->time_added = ecm_db_time;

#ifdef ECM_DB_XREF_ENABLE
	/*
	 * Insert node into the iface nodes list
	 */
	ni->node_prev = NULL;
	ni->node_next = ii->nodes;
	if (ii->nodes) {
		ii->nodes->node_prev = ni;
	}
	ii->nodes = ni;
	ii->node_count++;
#endif
	spin_unlock_bh(&ecm_db_lock);

	/*
	 * Throw add event to the listeners
 	 */
	DEBUG_TRACE("%p: Throw node added event\n", ni);
	li = ecm_db_listeners_get_and_ref_first();
	while (li) {
		struct ecm_db_listener_instance *lin;
		if (li->node_added) {
			li->node_added(li->arg, ni);
		}

		/*
		 * Get next listener
		 */
		lin = ecm_db_listener_get_and_ref_next(li);
		ecm_db_listener_deref(li);
		li = lin;
	}
}
EXPORT_SYMBOL(ecm_db_node_add);

/*
 * ecm_db_adv_stats_state_write()
 *	Write out advanced stats state
 */
static int ecm_db_adv_stats_state_write(struct ecm_state_file_instance *sfi,uint64_t from_data_total, uint64_t to_data_total,
				uint64_t from_packet_total, uint64_t to_packet_total, uint64_t from_data_total_dropped,
				uint64_t to_data_total_dropped, uint64_t from_packet_total_dropped, uint64_t to_packet_total_dropped)
{
	int result;

	if ((result = ecm_state_prefix_add(sfi, "adv_stats"))) {
		return result;
	}

	if ((result = ecm_state_write(sfi, "from_data_total", "%llu", from_data_total))) {
		return result;
	}
	if ((result = ecm_state_write(sfi, "to_data_total", "%llu", to_data_total))) {
		return result;
	}
	if ((result = ecm_state_write(sfi, "from_packet_total", "%llu", from_packet_total))) {
		return result;
	}
	if ((result = ecm_state_write(sfi, "to_packet_total", "%llu", to_packet_total))) {
		return result;
	}
	if ((result = ecm_state_write(sfi, "from_data_total_dropped", "%llu", from_data_total_dropped))) {
		return result;
	}
	if ((result = ecm_state_write(sfi, "to_data_total_dropped", "%llu", to_data_total_dropped))) {
		return result;
	}
	if ((result = ecm_state_write(sfi, "from_packet_total_dropped", "%llu", from_packet_total_dropped))) {
		return result;
	}
	if ((result = ecm_state_write(sfi, "to_packet_total_dropped", "%llu", to_packet_total_dropped))) {
		return result;
	}

	return ecm_state_prefix_remove(sfi);
}

#ifdef ECM_STATE_OUTPUT_ENABLE
/*
 * ecm_db_iface_state_get_base()
 *	Get the basic state for an interface object
 */
static int ecm_db_iface_state_get_base(struct ecm_db_iface_instance *ii, struct ecm_state_file_instance *sfi)
{
	int result;
#ifdef ECM_DB_XREF_ENABLE
	int node_count;
#endif
	uint32_t time_added;
	int32_t interface_identifier;
	int32_t ae_interface_identifier;
	char name[IFNAMSIZ];
	int32_t mtu;
	ecm_db_iface_type_t type;
#ifdef ECM_DB_ADVANCED_STATS_ENABLE
	uint64_t from_data_total;
	uint64_t to_data_total;
	uint64_t from_packet_total;
	uint64_t to_packet_total;
	uint64_t from_data_total_dropped;
	uint64_t to_data_total_dropped;
	uint64_t from_packet_total_dropped;
	uint64_t to_packet_total_dropped;
#endif

	DEBUG_CHECK_MAGIC(ii, ECM_DB_IFACE_INSTANCE_MAGIC, "%p: magic failed\n", ii);
	DEBUG_TRACE("%p: Open iface msg\n", ii);

	if ((result = ecm_state_prefix_add(sfi, "iface"))) {
		return result;
	}

#ifdef ECM_DB_XREF_ENABLE
	node_count = ecm_db_iface_node_count_get(ii);
#endif
	time_added = ii->time_added;
	type = ii->type;
	interface_identifier = ii->interface_identifier;
	ae_interface_identifier = ii->ae_interface_identifier;
	spin_lock_bh(&ecm_db_lock);
	strcpy(name, ii->name);
	mtu = ii->mtu;
	spin_unlock_bh(&ecm_db_lock);

#ifdef ECM_DB_ADVANCED_STATS_ENABLE
	ecm_db_iface_data_stats_get(ii, &from_data_total, &to_data_total,
			&from_packet_total, &to_packet_total,
			&from_data_total_dropped, &to_data_total_dropped,
			&from_packet_total_dropped, &to_packet_total_dropped);

	if ((result = ecm_db_adv_stats_state_write(sfi, from_data_total, to_data_total,
			from_packet_total, to_packet_total, from_data_total_dropped,
			to_data_total_dropped, from_packet_total_dropped,
			to_packet_total_dropped))) {
		return result;
	}
#endif

	if ((result = ecm_state_write(sfi, "type", "%d", type))) {
		return result;
	}

	if ((result = ecm_state_write(sfi, "name", "%s", name))) {
		return result;
	}

	if ((result = ecm_state_write(sfi, "time_added", "%u", time_added))) {
		return result;
	}

	if ((result = ecm_state_write(sfi, "mtu", "%d", mtu))) {
		return result;
	}

	if ((result = ecm_state_write(sfi, "interface_identifier", "%d", interface_identifier))) {
		return result;
	}

	if ((result = ecm_state_write(sfi, "ae_interface_identifier", "%d", ae_interface_identifier))) {
		return result;
	}

#ifdef ECM_DB_XREF_ENABLE
	if ((result = ecm_state_write(sfi, "nodes", "%d", node_count))) {
		return result;
	}
#endif

	return ecm_state_prefix_remove(sfi);
}

/*
 * ecm_db_iface_ethernet_state_get()
 * 	Return interface type specific state
 */
static int ecm_db_iface_ethernet_state_get(struct ecm_db_iface_instance *ii, struct ecm_state_file_instance *sfi)
{
	int result;
	uint8_t address[ETH_ALEN];

	DEBUG_CHECK_MAGIC(ii, ECM_DB_IFACE_INSTANCE_MAGIC, "%p: magic failed\n", ii);
	spin_lock_bh(&ecm_db_lock);
	memcpy(address, ii->type_info.ethernet.address, ETH_ALEN);
	spin_unlock_bh(&ecm_db_lock);

	if ((result = ecm_state_prefix_add(sfi, "ethernet"))) {
		return result;
	}

	if ((result = ecm_db_iface_state_get_base(ii, sfi))) {
		return result;
	}

	if ((result = ecm_state_write(sfi, "address", "%pM", address))) {
		return result;
	}

	return ecm_state_prefix_remove(sfi);
}

#ifdef ECM_INTERFACE_BOND_ENABLE
/*
 * ecm_db_iface_lag_state_get()
 * 	Return interface type specific state
 */
static int ecm_db_iface_lag_state_get(struct ecm_db_iface_instance *ii, struct ecm_state_file_instance *sfi)
{
	int result;
	uint8_t address[ETH_ALEN];

	DEBUG_CHECK_MAGIC(ii, ECM_DB_IFACE_INSTANCE_MAGIC, "%p: magic failed\n", ii);
	spin_lock_bh(&ecm_db_lock);
	memcpy(address, ii->type_info.lag.address, ETH_ALEN);
	spin_unlock_bh(&ecm_db_lock);

	if ((result = ecm_state_prefix_add(sfi, "lag"))) {
		return result;
	}
	if ((result = ecm_db_iface_state_get_base(ii, sfi))) {
		return result;
	}

	if ((result = ecm_state_write(sfi, "address", "%pM", address))) {
		return result;
	}

	return ecm_state_prefix_remove(sfi);
}
#endif

/*
 * ecm_db_iface_bridge_state_get()
 * 	Return interface type specific state
 */
static int ecm_db_iface_bridge_state_get(struct ecm_db_iface_instance *ii, struct ecm_state_file_instance *sfi)
{
	int result;
	uint8_t address[ETH_ALEN];

	DEBUG_CHECK_MAGIC(ii, ECM_DB_IFACE_INSTANCE_MAGIC, "%p: magic failed\n", ii);
	spin_lock_bh(&ecm_db_lock);
	memcpy(address, ii->type_info.bridge.address, ETH_ALEN);
	spin_unlock_bh(&ecm_db_lock);

	if ((result = ecm_state_prefix_add(sfi, "bridge"))) {
		return result;
	}
	if ((result = ecm_db_iface_state_get_base(ii, sfi))) {
		return result;
	}

	if ((result = ecm_state_write(sfi, "address", "%pM", address))) {
		return result;
	}

	return ecm_state_prefix_remove(sfi);
}

#ifdef ECM_INTERFACE_VLAN_ENABLE
/*
 * ecm_db_iface_vlan_state_get()
 * 	Return interface type specific state
 */
static int ecm_db_iface_vlan_state_get(struct ecm_db_iface_instance *ii, struct ecm_state_file_instance *sfi)
{
	int result;
	uint8_t address[ETH_ALEN];
	uint16_t vlan_tag;
	uint16_t vlan_tpid;

	DEBUG_CHECK_MAGIC(ii, ECM_DB_IFACE_INSTANCE_MAGIC, "%p: magic failed\n", ii);
	spin_lock_bh(&ecm_db_lock);
	memcpy(address, ii->type_info.vlan.address, ETH_ALEN);
	vlan_tag = ii->type_info.vlan.vlan_tag;
	vlan_tpid = ii->type_info.vlan.vlan_tpid;
	spin_unlock_bh(&ecm_db_lock);

	if ((result = ecm_state_prefix_add(sfi, "vlan"))) {
		return result;
	}
	if ((result = ecm_db_iface_state_get_base(ii, sfi))) {
		return result;
	}

	if ((result = ecm_state_write(sfi, "address", "%pM", address))) {
		return result;
	}
	if ((result = ecm_state_write(sfi, "tag", "%x", vlan_tag))) {
		return result;
	}
	if ((result = ecm_state_write(sfi, "tpid", "%x", vlan_tpid))) {
		return result;
	}

	return ecm_state_prefix_remove(sfi);
}
#endif

#ifdef ECM_INTERFACE_PPPOE_ENABLE
/*
 * ecm_db_iface_pppoe_state_get()
 * 	Return interface type specific state
 */
static int ecm_db_iface_pppoe_state_get(struct ecm_db_iface_instance *ii, struct ecm_state_file_instance *sfi)
{
	int result;
	uint16_t pppoe_session_id;
	uint8_t remote_mac[ETH_ALEN];

	DEBUG_CHECK_MAGIC(ii, ECM_DB_IFACE_INSTANCE_MAGIC, "%p: magic failed\n", ii);
	spin_lock_bh(&ecm_db_lock);
	pppoe_session_id = ii->type_info.pppoe.pppoe_session_id;
	memcpy(remote_mac, ii->type_info.pppoe.remote_mac, ETH_ALEN);
	spin_unlock_bh(&ecm_db_lock);

	if ((result = ecm_state_prefix_add(sfi, "pppoe"))) {
		return result;
	}
	if ((result = ecm_db_iface_state_get_base(ii, sfi))) {
		return result;
	}

	if ((result = ecm_state_write(sfi, "remote_max", "%pM", remote_mac))) {
		return result;
	}
	if ((result = ecm_state_write(sfi, "session_id", "%u", pppoe_session_id))) {
		return result;
	}

	return ecm_state_prefix_remove(sfi);
}
#endif

#ifdef ECM_INTERFACE_MAP_T_ENABLE
/*
 * ecm_db_iface_map_t_state_get()
 *	Return interface type specific state
 */
static int ecm_db_iface_map_t_state_get(struct ecm_db_iface_instance *ii, struct ecm_state_file_instance *sfi)
{
	int result;
	int32_t if_index;

	DEBUG_CHECK_MAGIC(ii, ECM_DB_IFACE_INSTANCE_MAGIC, "%p: magic failed\n", ii);
	spin_lock_bh(&ecm_db_lock);
	if_index = ii->type_info.map_t.if_index;
	spin_unlock_bh(&ecm_db_lock);

	if ((result = ecm_state_prefix_add(sfi, "map_t"))) {
		return result;
	}
	if ((result = ecm_db_iface_state_get_base(ii, sfi))) {
		return result;
	}

	if ((result = ecm_state_write(sfi, "if_index", "%d", if_index))) {
		return result;
	}

	return ecm_state_prefix_remove(sfi);
}
#endif

#ifdef ECM_INTERFACE_L2TPV2_ENABLE

/*
 * ecm_db_iface_pppol2tpv2_state_get()
 *	Return interface type specific state
 */
static int ecm_db_iface_pppol2tpv2_state_get(struct ecm_db_iface_instance *ii, struct ecm_state_file_instance *sfi)
{
	int result;
	struct ecm_db_interface_info_pppol2tpv2 type_info;

	DEBUG_CHECK_MAGIC(ii, ECM_DB_IFACE_INSTANCE_MAGIC, "%p: magic failed\n", ii);
	spin_lock_bh(&ecm_db_lock);
	memcpy(&type_info, &ii->type_info, sizeof(struct ecm_db_interface_info_pppol2tpv2));
	spin_unlock_bh(&ecm_db_lock);

	if ((result = ecm_state_prefix_add(sfi, "pppol2tpv2"))) {
		return result;
	}

	if ((result = ecm_db_iface_state_get_base(ii, sfi))) {
		return result;
	}

	if ((result = ecm_state_write(sfi, "local_tunnel_id", "%u", type_info.l2tp.tunnel.tunnel_id))) {
		return result;
	}

	if ((result = ecm_state_write(sfi, "local_session_id", "%u", type_info.l2tp.session.session_id))) {
		return result;
	}

	if ((result = ecm_state_write(sfi, "peer_tunnnel_id", "%u", type_info.l2tp.tunnel.peer_tunnel_id))) {
		return result;
	}

	if ((result = ecm_state_write(sfi, "peer_session_id", "%u", type_info.l2tp.session.peer_session_id))) {
		return result;
	}

	return ecm_state_prefix_remove(sfi);
}

#endif

#ifdef ECM_INTERFACE_PPTP_ENABLE
/*
 * ecm_db_iface_pptp_state_get()
 *	Return interface type specific state
 */
static int ecm_db_iface_pptp_state_get(struct ecm_db_iface_instance *ii, struct ecm_state_file_instance *sfi)
{
	int result;
	struct ecm_db_interface_info_pptp type_info;

	DEBUG_CHECK_MAGIC(ii, ECM_DB_IFACE_INSTANCE_MAGIC, "%p: magic failed\n", ii);
	spin_lock_bh(&ecm_db_lock);
	memcpy(&type_info, &ii->type_info, sizeof(struct ecm_db_interface_info_pptp));
	spin_unlock_bh(&ecm_db_lock);

	result = ecm_state_prefix_add(sfi, "pptp");
	if (result) {
		return result;
	}

	result = ecm_db_iface_state_get_base(ii, sfi);
	if (result) {
		return result;
	}

	result = ecm_state_write(sfi, "local_call_id", "%u", type_info.src_call_id);
	if (result) {
		return result;
	}

	result = ecm_state_write(sfi, "peer_call_id", "%u", type_info.dst_call_id);
	if (result) {
		return result;
	}

	return ecm_state_prefix_remove(sfi);
}
#endif

/*
 * ecm_db_iface_unknown_state_get()
 * 	Return interface type specific state
 */
static int ecm_db_iface_unknown_state_get(struct ecm_db_iface_instance *ii, struct ecm_state_file_instance *sfi)
{
	int result;
	uint32_t os_specific_ident;

	DEBUG_CHECK_MAGIC(ii, ECM_DB_IFACE_INSTANCE_MAGIC, "%p: magic failed\n", ii);
	spin_lock_bh(&ecm_db_lock);
	os_specific_ident = ii->type_info.unknown.os_specific_ident;
	spin_unlock_bh(&ecm_db_lock);

	if ((result = ecm_state_prefix_add(sfi, "pppoe"))) {
		return result;
	}
	if ((result = ecm_db_iface_state_get_base(ii, sfi))) {
		return result;
	}

	if ((result = ecm_state_write(sfi, "os_specific_ident", "%u", os_specific_ident))) {
		return result;
	}

	return ecm_state_prefix_remove(sfi);
}

/*
 * ecm_db_iface_loopback_state_get()
 * 	Return interface type specific state
 */
static int ecm_db_iface_loopback_state_get(struct ecm_db_iface_instance *ii, struct ecm_state_file_instance *sfi)
{
	int result;
	uint32_t os_specific_ident;

	DEBUG_CHECK_MAGIC(ii, ECM_DB_IFACE_INSTANCE_MAGIC, "%p: magic failed\n", ii);
	spin_lock_bh(&ecm_db_lock);
	os_specific_ident = ii->type_info.loopback.os_specific_ident;
	spin_unlock_bh(&ecm_db_lock);

	if ((result = ecm_state_prefix_add(sfi, "loopback"))) {
		return result;
	}
	if ((result = ecm_db_iface_state_get_base(ii, sfi))) {
		return result;
	}

	if ((result = ecm_state_write(sfi, "os_specific_ident", "%u", os_specific_ident))) {
		return result;
	}

	return ecm_state_prefix_remove(sfi);
}

#ifdef ECM_INTERFACE_IPSEC_ENABLE
/*
 * ecm_db_iface_ipsec_tunnel_state_get()
 * 	Return interface type specific state
 *
 * GGG TODO Output state on ipsec tunnel specific data
 */
static int ecm_db_iface_ipsec_tunnel_state_get(struct ecm_db_iface_instance *ii, struct ecm_state_file_instance *sfi)
{
	int result;
	uint32_t os_specific_ident;

	DEBUG_CHECK_MAGIC(ii, ECM_DB_IFACE_INSTANCE_MAGIC, "%p: magic failed\n", ii);
	spin_lock_bh(&ecm_db_lock);
	os_specific_ident = ii->type_info.ipsec_tunnel.os_specific_ident;
	spin_unlock_bh(&ecm_db_lock);

	if ((result = ecm_state_prefix_add(sfi, "ipsec"))) {
		return result;
	}
	if ((result = ecm_db_iface_state_get_base(ii, sfi))) {
		return result;
	}

	if ((result = ecm_state_write(sfi, "os_specific_ident", "%u", os_specific_ident))) {
		return result;
	}

	return ecm_state_prefix_remove(sfi);
}
#endif

#ifdef ECM_INTERFACE_TUNIPIP6_ENABLE
#ifdef ECM_IPV6_ENABLE
/*
 * ecm_db_iface_tunipip6_state_get()
 * 	Return interface type specific state
 */
static int ecm_db_iface_tunipip6_state_get(struct ecm_db_iface_instance *ii, struct ecm_state_file_instance *sfi)
{
	int result;
	uint32_t os_specific_ident;

	DEBUG_CHECK_MAGIC(ii, ECM_DB_IFACE_INSTANCE_MAGIC, "%p: magic failed\n", ii);
	spin_lock_bh(&ecm_db_lock);
	os_specific_ident = ii->type_info.ipsec_tunnel.os_specific_ident;
	spin_unlock_bh(&ecm_db_lock);

	if ((result = ecm_state_prefix_add(sfi, "tunipip6"))) {
		return result;
	}
	if ((result = ecm_db_iface_state_get_base(ii, sfi))) {
		return result;
	}

	if ((result = ecm_state_write(sfi, "os_specific_ident", "%u", os_specific_ident))) {
		return result;
	}

	return ecm_state_prefix_remove(sfi);
}
#endif
#endif

#ifdef ECM_INTERFACE_SIT_ENABLE
/*
 * ecm_db_iface_sit_state_get()
 * 	Return interface type specific state
 */
static int ecm_db_iface_sit_state_get(struct ecm_db_iface_instance *ii, struct ecm_state_file_instance *sfi)
{
	int result;
	uint32_t os_specific_ident;

	DEBUG_CHECK_MAGIC(ii, ECM_DB_IFACE_INSTANCE_MAGIC, "%p: magic failed\n", ii);
	spin_lock_bh(&ecm_db_lock);
	os_specific_ident = ii->type_info.ipsec_tunnel.os_specific_ident;
	spin_unlock_bh(&ecm_db_lock);

	if ((result = ecm_state_prefix_add(sfi, "sit"))) {
		return result;
	}
	if ((result = ecm_db_iface_state_get_base(ii, sfi))) {
		return result;
	}

	if ((result = ecm_state_write(sfi, "os_specific_ident", "%u", os_specific_ident))) {
		return result;
	}

	return ecm_state_prefix_remove(sfi);
}
#endif

/*
 * ecm_db_iface_state_get()
 *	Obtain state for the interface.
 *
 * State specific to the interface type will be returned.
 */
int ecm_db_iface_state_get(struct ecm_state_file_instance *sfi, struct ecm_db_iface_instance *ii)
{
	int result;

	DEBUG_CHECK_MAGIC(ii, ECM_DB_IFACE_INSTANCE_MAGIC, "%p: magic failed\n", ii);

	if ((result = ecm_state_prefix_add(sfi, "iface"))) {
		return result;
	}

	if ((result = ii->state_get(ii, sfi))) {
		return result;
	}

	return ecm_state_prefix_remove(sfi);

}
EXPORT_SYMBOL(ecm_db_iface_state_get);

/*
 * ecm_db_connection_heirarchy_state_get()
 *	Output state for an interface heirarchy list.
 */
static int ecm_db_connection_heirarchy_state_get(struct ecm_state_file_instance *sfi, struct ecm_db_iface_instance *interfaces[], int32_t first_interface)
{
	int result;
	int count;
	int i;
	int j;

	count = ECM_DB_IFACE_HEIRARCHY_MAX - first_interface;
	if ((result = ecm_state_write(sfi, "interface_count", "%d", count))) {
		return result;
	}

	/*
	 * Iterate the interface heirarchy list and output the information
	 */
	for (i = first_interface, j = 0; i < ECM_DB_IFACE_HEIRARCHY_MAX; ++i, ++j) {
		struct ecm_db_iface_instance *ii = interfaces[i];
		DEBUG_TRACE("Output interface @ %d: %p\n", i, ii);

		if ((result = ecm_state_prefix_index_add(sfi, j))) {
			return result;
		}
		result = ii->state_get(ii, sfi);
		if (result) {
			return result;
		}
		if ((result = ecm_state_prefix_remove(sfi))) {
			return result;
		}
	}

	return 0;
}

#ifdef ECM_MULTICAST_ENABLE
/*
 * ecm_db_multicast_to_interfaces_xml_state_get()
 * 	 Obtain XML state for the multicast destination interfaces list
 */
static int ecm_db_multicast_to_interfaces_xml_state_get(struct ecm_db_connection_instance *ci, struct ecm_state_file_instance *sfi)
{
	struct ecm_db_iface_instance *mc_ifaces;
	struct ecm_db_iface_instance *mc_ifaces_single[ECM_DB_IFACE_HEIRARCHY_MAX];
	struct ecm_db_iface_instance *ii_temp;
	int32_t *mc_ifaces_first;
	int32_t *ifaces_first;
	int32_t heirarchy_index;
	int ret;

	ret = ecm_db_multicast_connection_to_interfaces_get_and_ref_all(ci, &mc_ifaces, &mc_ifaces_first);
	if (ret == 0) {
		return ret;
	}

	for (heirarchy_index = 0; heirarchy_index < ECM_DB_MULTICAST_IF_MAX; heirarchy_index++) {

		ii_temp = ecm_db_multicast_if_heirarchy_get(mc_ifaces, heirarchy_index);
		ecm_db_multicast_copy_if_heirarchy(mc_ifaces_single, ii_temp);
		ifaces_first = ecm_db_multicast_if_first_get_at_index(mc_ifaces_first, heirarchy_index);

		if (ci->to_mcast_interface_first[heirarchy_index] < ECM_DB_IFACE_HEIRARCHY_MAX) {
			ret = ecm_db_connection_heirarchy_state_get(sfi, mc_ifaces_single, *ifaces_first);
			if (ret) {
				ecm_db_multicast_connection_to_interfaces_deref_all(mc_ifaces, mc_ifaces_first);
				return ret;
			}

		}
	}
	ecm_db_multicast_connection_to_interfaces_deref_all(mc_ifaces, mc_ifaces_first);

	return ret;
}
#endif

/*
 * ecm_db_connection_state_get()
 *	Prepare a connection message
 */
int ecm_db_connection_state_get(struct ecm_state_file_instance *sfi, struct ecm_db_connection_instance *ci)
{
	int result;
	long int expires_in;
	int sport;
	int sport_nat;
	char snode_address[ECM_MAC_ADDR_STR_BUFF_SIZE];
	char snode_address_nat[ECM_MAC_ADDR_STR_BUFF_SIZE];
	char sip_address[ECM_IP_ADDR_STR_BUFF_SIZE];
	char sip_address_nat[ECM_IP_ADDR_STR_BUFF_SIZE];
	char dnode_address[ECM_MAC_ADDR_STR_BUFF_SIZE];
	char dnode_address_nat[ECM_MAC_ADDR_STR_BUFF_SIZE];
	int dport;
	int dport_nat;
	char dip_address[ECM_IP_ADDR_STR_BUFF_SIZE];
	char dip_address_nat[ECM_IP_ADDR_STR_BUFF_SIZE];
	ecm_db_direction_t direction;
	int ip_version;
	int protocol;
	bool is_routed;
	uint32_t regen_success;
	uint32_t regen_fail;
	uint16_t regen_required;
	uint16_t regen_occurances;
	bool regen_in_progress;
	uint16_t generation;
	uint16_t global_generation;
	uint32_t time_added;
	uint32_t serial;
	uint64_t from_data_total;
	uint64_t to_data_total;
	uint64_t from_packet_total;
	uint64_t to_packet_total;
	uint64_t from_data_total_dropped;
	uint64_t to_data_total_dropped;
	uint64_t from_packet_total_dropped;
	uint64_t to_packet_total_dropped;
	struct ecm_db_host_instance *hi;
	struct ecm_db_node_instance *ni;
	int aci_index;
	int aci_count;
	ip_addr_t __attribute__((unused)) group_ip;
	struct ecm_front_end_connection_instance *feci;
	struct ecm_classifier_instance *assignments[ECM_CLASSIFIER_TYPES];
	int32_t first_interface;
	struct ecm_db_iface_instance *interfaces[ECM_DB_IFACE_HEIRARCHY_MAX];

	DEBUG_TRACE("Prep conn msg for %p\n", ci);

	/*
	 * Identify expiration
	 */
	spin_lock_bh(&ecm_db_lock);
	if (ci->defunct_timer.group == ECM_DB_TIMER_GROUPS_MAX) {
		expires_in = -1;
	} else {
		expires_in = (long int)(ci->defunct_timer.timeout - ecm_db_time);
		if (expires_in <= 0) {
			expires_in = 0;
		}
	}

	regen_success = ci->regen_success;
	regen_fail = ci->regen_fail;
	regen_required = ci->regen_required;
	regen_occurances = ci->regen_occurances;
	regen_in_progress = ci->regen_in_progress;
	generation = ci->generation;
	global_generation = ecm_db_connection_generation;

	spin_unlock_bh(&ecm_db_lock);

	/*
	 * Extract information from the connection for inclusion into the message
	 */
	sport = ci->mapping_from->port;
	sport_nat = ci->mapping_nat_from->port;
	dport = ci->mapping_to->port;
	dport_nat = ci->mapping_nat_to->port;

	hi = ci->mapping_to->host;
	ecm_ip_addr_to_string(dip_address, hi->address);
	ni = ci->to_node;
	snprintf(dnode_address, sizeof(dnode_address), "%pM", ni->address);
	hi = ci->mapping_nat_to->host;
	ecm_ip_addr_to_string(dip_address_nat, hi->address);

	hi = ci->mapping_from->host;
	ecm_ip_addr_to_string(sip_address, hi->address);
	ni = ci->from_node;
	snprintf(snode_address, sizeof(snode_address), "%pM", ni->address);
	hi = ci->mapping_nat_from->host;
	ecm_ip_addr_to_string(sip_address_nat, hi->address);

	ni = ci->to_nat_node;
	snprintf(dnode_address_nat, sizeof(dnode_address_nat), "%pM", ni->address);

	ni = ci->from_nat_node;
	snprintf(snode_address_nat, sizeof(snode_address_nat), "%pM", ni->address);

	direction = ci->direction;
	ip_version = ci->ip_version;
	protocol = ci->protocol;
	is_routed = ci->is_routed;
	time_added = ci->time_added;
	serial = ci->serial;
	ecm_db_connection_data_stats_get(ci, &from_data_total, &to_data_total,
			&from_packet_total, &to_packet_total,
			&from_data_total_dropped, &to_data_total_dropped,
			&from_packet_total_dropped, &to_packet_total_dropped);

	if ((result = ecm_state_prefix_add(sfi, "conn"))) {
		return result;
	}
	if ((result = ecm_state_prefix_index_add(sfi, serial))) {
		return result;
	}

	if ((result = ecm_state_write(sfi, "serial", "%u", serial))) {
		return result;
	}

	if ((result = ecm_state_write(sfi, "sip_address", "%s", sip_address))) {
		return result;
	}

	if ((result = ecm_state_write(sfi, "sip_address_nat", "%s", sip_address_nat))) {
		return result;
	}

	if ((result = ecm_state_write(sfi, "sport", "%d", sport))) {
		return result;
	}

	if ((result = ecm_state_write(sfi, "sport_nat", "%d", sport_nat))) {
		return result;
	}

	if ((result = ecm_state_write(sfi, "snode_address", "%s", snode_address))) {
		return result;
	}

	if ((result = ecm_state_write(sfi, "snode_address_nat", "%s", snode_address_nat))) {
		return result;
	}

	if ((result = ecm_state_write(sfi, "dip_address", "%s", dip_address))) {
		return result;
	}

	if ((result = ecm_state_write(sfi, "dip_address_nat", "%s", dip_address_nat))) {
		return result;
	}

	if ((result = ecm_state_write(sfi, "dport", "%d", dport))) {
		return result;
	}

	if ((result = ecm_state_write(sfi, "dport_nat", "%d", dport_nat))) {
		return result;
	}

	if ((result = ecm_state_write(sfi, "dnode_address", "%s", dnode_address))) {
		return result;
	}

	if ((result = ecm_state_write(sfi, "dnode_address_nat", "%s", dnode_address_nat))) {
		return result;
	}

	if ((result = ecm_state_write(sfi, "ip_version", "%d", ip_version))) {
		return result;
	}

	if ((result = ecm_state_write(sfi, "protocol", "%d", protocol))) {
		return result;
	}

	if ((result = ecm_state_write(sfi, "is_routed", "%d", is_routed))) {
		return result;
	}

	if ((result = ecm_state_write(sfi, "expires", "%ld", expires_in))) {
		return result;
	}

	if ((result = ecm_state_write(sfi, "direction", "%d", direction))) {
		return result;
	}

	if ((result = ecm_state_write(sfi, "time_added", "%u", time_added))) {
		return result;
	}

	if ((result = ecm_state_write(sfi, "regen_success", "%u", regen_success))) {
		return result;
	}
	if ((result = ecm_state_write(sfi, "regen_fail", "%u", regen_fail))) {
		return result;
	}
	if ((result = ecm_state_write(sfi, "regen_required", "%u", regen_required))) {
		return result;
	}
	if ((result = ecm_state_write(sfi, "regen_occurances", "%u", regen_occurances))) {
		return result;
	}
	if ((result = ecm_state_write(sfi, "regen_in_progress", "%u", regen_in_progress))) {
		return result;
	}
	if ((result = ecm_state_write(sfi, "generation", "%u/%u", generation, global_generation))) {
		return result;
	}

	/*
	 * NOTE: These advanced stats are not conditional compiled.
	 * Connections always contain these stats
	 */
	if ((result = ecm_db_adv_stats_state_write(sfi, from_data_total, to_data_total,
			from_packet_total, to_packet_total, from_data_total_dropped,
			to_data_total_dropped, from_packet_total_dropped,
			to_packet_total_dropped))) {
		return result;
	}

	if ((result = ecm_state_prefix_add(sfi, "from_interfaces"))) {
		return result;
	}
	first_interface = ecm_db_connection_from_interfaces_get_and_ref(ci, interfaces);
	result = ecm_db_connection_heirarchy_state_get(sfi, interfaces, first_interface);
	ecm_db_connection_interfaces_deref(interfaces, first_interface);
	if (result) {
		return result;
	}
	if ((result = ecm_state_prefix_remove(sfi))) {
		return result;
	}

#ifdef ECM_MULTICAST_ENABLE
	ecm_db_connection_to_address_get(ci, group_ip);
	if (ecm_ip_addr_is_multicast(group_ip)) {
		if ((result = ecm_state_prefix_add(sfi, "to_mc_interfaces"))) {
			return result;
		}

		if ((result = ecm_db_multicast_to_interfaces_xml_state_get(ci, sfi))) {
			return result;
		}

		if ((result = ecm_state_prefix_remove(sfi))) {
			return result;
		}
	}
	else {
		if ((result = ecm_state_prefix_add(sfi, "to_interfaces"))) {
			return result;
		}

		first_interface = ecm_db_connection_to_interfaces_get_and_ref(ci, interfaces);
		result = ecm_db_connection_heirarchy_state_get(sfi, interfaces, first_interface);
		ecm_db_connection_interfaces_deref(interfaces, first_interface);
		if (result) {
			return result;
		}

		if ((result = ecm_state_prefix_remove(sfi))) {
			return result;
		}
	}
#else
	if ((result = ecm_state_prefix_add(sfi, "to_interfaces"))) {
		return result;
	}
	first_interface = ecm_db_connection_to_interfaces_get_and_ref(ci, interfaces);
	result = ecm_db_connection_heirarchy_state_get(sfi, interfaces, first_interface);
	ecm_db_connection_interfaces_deref(interfaces, first_interface);
	if (result) {
		return result;
	}
	if ((result = ecm_state_prefix_remove(sfi))) {
		return result;
	}
#endif

	if ((result = ecm_state_prefix_add(sfi, "from_nat_interfaces"))) {
		return result;
	}
	first_interface = ecm_db_connection_from_nat_interfaces_get_and_ref(ci, interfaces);
	result = ecm_db_connection_heirarchy_state_get(sfi, interfaces, first_interface);
	ecm_db_connection_interfaces_deref(interfaces, first_interface);
	if (result) {
		return result;
	}
	if ((result = ecm_state_prefix_remove(sfi))) {
		return result;
	}

	if ((result = ecm_state_prefix_add(sfi, "to_nat_interfaces"))) {
		return result;
	}
	first_interface = ecm_db_connection_to_nat_interfaces_get_and_ref(ci, interfaces);
	result = ecm_db_connection_heirarchy_state_get(sfi, interfaces, first_interface);
	ecm_db_connection_interfaces_deref(interfaces, first_interface);
	if (result) {
		return result;
	}
	if ((result = ecm_state_prefix_remove(sfi))) {
		return result;
	}

	/*
	 * Output front end state
	 */
	feci = ecm_db_connection_front_end_get_and_ref(ci);
	result = feci->state_get(feci, sfi);
	feci->deref(feci);
	if (result) {
		return result;
	}

	if ((result = ecm_state_prefix_add(sfi, "classifiers"))) {
		return result;
	}

	/*
	 * Grab references to the assigned classifiers so we can produce state for them
	 */
	aci_count = ecm_db_connection_classifier_assignments_get_and_ref(ci, assignments);

	/*
	 * Iterate the assigned classifiers and provide a state record for each
	 */
	for (aci_index = 0; aci_index < aci_count; ++aci_index) {
		struct ecm_classifier_instance *aci;

		aci = assignments[aci_index];
		result = aci->state_get(aci, sfi);
		if (result) {
			ecm_db_connection_assignments_release(aci_count, assignments);
			return result;
		}
	}

	ecm_db_connection_assignments_release(aci_count, assignments);

	if ((result = ecm_state_prefix_remove(sfi))) {
		return result;
	}

	if ((result = ecm_state_prefix_remove(sfi))) {
		return result;
	}

	return ecm_state_prefix_remove(sfi);
}
EXPORT_SYMBOL(ecm_db_connection_state_get);

/*
 * ecm_db_mapping_state_get()
 *	Prepare a mapping message
 */
int ecm_db_mapping_state_get(struct ecm_state_file_instance *sfi, struct ecm_db_mapping_instance *mi)
{
	int result;
	int port;
	char address[ECM_IP_ADDR_STR_BUFF_SIZE];
	int tcp_from;
	int tcp_to;
	int udp_from;
	int udp_to;
	int from;
	int to;
	int tcp_nat_from;
	int tcp_nat_to;
	int udp_nat_from;
	int udp_nat_to;
	int nat_from;
	int nat_to;
	uint32_t time_added;
	struct ecm_db_host_instance *hi;
#ifdef ECM_DB_ADVANCED_STATS_ENABLE
	uint64_t from_data_total;
	uint64_t to_data_total;
	uint64_t from_packet_total;
	uint64_t to_packet_total;
	uint64_t from_data_total_dropped;
	uint64_t to_data_total_dropped;
	uint64_t from_packet_total_dropped;
	uint64_t to_packet_total_dropped;
#endif

	DEBUG_TRACE("Prep mapping msg for %p\n", mi);

	/*
	 * Create a small xml stats element for our mapping.
	 * Extract information from the mapping for inclusion into the message
	 */
	ecm_db_mapping_port_count_get(mi, &tcp_from, &tcp_to, &udp_from, &udp_to, &from, &to,
			&tcp_nat_from, &tcp_nat_to, &udp_nat_from, &udp_nat_to, &nat_from, &nat_to);
	port = mi->port;
	time_added = mi->time_added;
	hi = mi->host;
	ecm_ip_addr_to_string(address, hi->address);

#ifdef ECM_DB_ADVANCED_STATS_ENABLE
	ecm_db_mapping_data_stats_get(mi, &from_data_total, &to_data_total,
			&from_packet_total, &to_packet_total,
			&from_data_total_dropped, &to_data_total_dropped,
			&from_packet_total_dropped, &to_packet_total_dropped);
#endif

	if ((result = ecm_state_prefix_add(sfi, "mapping"))) {
		return result;
	}

	if ((result = ecm_state_write(sfi, "port", "%d", port))) {
		return result;
	}

	if ((result = ecm_state_write(sfi, "from", "%d", from))) {
		return result;
	}

	if ((result = ecm_state_write(sfi, "to", "%d", to))) {
		return result;
	}

	if ((result = ecm_state_write(sfi, "tcp_from", "%d", tcp_from))) {
		return result;
	}

	if ((result = ecm_state_write(sfi, "tcp_to", "%d", tcp_to))) {
		return result;
	}

	if ((result = ecm_state_write(sfi, "udp_from", "%d", udp_from))) {
		return result;
	}

	if ((result = ecm_state_write(sfi, "udp_to", "%d", udp_to))) {
		return result;
	}

	if ((result = ecm_state_write(sfi, "nat_from", "%d", nat_from))) {
		return result;
	}

	if ((result = ecm_state_write(sfi, "nat_to", "%d", nat_to))) {
		return result;
	}

	if ((result = ecm_state_write(sfi, "tcp_nat_from", "%d", tcp_nat_from))) {
		return result;
	}

	if ((result = ecm_state_write(sfi, "tcp_nat_to", "%d", tcp_nat_to))) {
		return result;
	}

	if ((result = ecm_state_write(sfi, "udp_nat_from", "%d", udp_nat_from))) {
		return result;
	}

	if ((result = ecm_state_write(sfi, "udp_nat_to", "%d", udp_nat_to))) {
		return result;
	}

	if ((result = ecm_state_write(sfi, "address", "%s", address))) {
		return result;
	}

	if ((result = ecm_state_write(sfi, "time_added", "%u", time_added))) {
		return result;
	}

#ifdef ECM_DB_ADVANCED_STATS_ENABLE
	if ((result = ecm_db_adv_stats_state_write(sfi, from_data_total, to_data_total,
			from_packet_total, to_packet_total, from_data_total_dropped,
			to_data_total_dropped, from_packet_total_dropped,
			to_packet_total_dropped))) {
		return result;
	}
#endif

	return ecm_state_prefix_remove(sfi);
}
EXPORT_SYMBOL(ecm_db_mapping_state_get);

/*
 * ecm_db_host_state_get()
 *	Prepare a host message
 */
int ecm_db_host_state_get(struct ecm_state_file_instance *sfi, struct ecm_db_host_instance *hi)
{
	int result;
	char address[ECM_IP_ADDR_STR_BUFF_SIZE];
#ifdef ECM_DB_XREF_ENABLE
	int mapping_count;
#endif
	uint32_t time_added;
	bool on_link;
#ifdef ECM_DB_ADVANCED_STATS_ENABLE
	uint64_t from_data_total;
	uint64_t to_data_total;
	uint64_t from_packet_total;
	uint64_t to_packet_total;
	uint64_t from_data_total_dropped;
	uint64_t to_data_total_dropped;
	uint64_t from_packet_total_dropped;
	uint64_t to_packet_total_dropped;
#endif

	DEBUG_TRACE("Prep host msg for %p\n", hi);

	/*
	 * Create a small xml stats element for our host.
	 * Extract information from the host for inclusion into the message
	 */
#ifdef ECM_DB_XREF_ENABLE
	mapping_count = ecm_db_host_mapping_count_get(hi);
#endif
	ecm_ip_addr_to_string(address, hi->address);
	time_added = hi->time_added;
	on_link = hi->on_link;

#ifdef ECM_DB_ADVANCED_STATS_ENABLE
	ecm_db_host_data_stats_get(hi, &from_data_total, &to_data_total,
			&from_packet_total, &to_packet_total,
			&from_data_total_dropped, &to_data_total_dropped,
			&from_packet_total_dropped, &to_packet_total_dropped);
#endif

	if ((result = ecm_state_prefix_add(sfi, "host"))) {
		return result;
	}

	if ((result = ecm_state_write(sfi, "address", "%s", address))) {
		return result;
	}
	if ((result = ecm_state_write(sfi, "time_added", "%u", time_added))) {
		return result;
	}
	if ((result = ecm_state_write(sfi, "on_link", "%d", on_link))) {
		return result;
	}

#ifdef ECM_DB_XREF_ENABLE
	if ((result = ecm_state_write(sfi, "mappings", "%d", mapping_count))) {
		return result;
	}
#endif

#ifdef ECM_DB_ADVANCED_STATS_ENABLE
	if ((result = ecm_db_adv_stats_state_write(sfi, from_data_total, to_data_total,
			from_packet_total, to_packet_total, from_data_total_dropped,
			to_data_total_dropped, from_packet_total_dropped,
			to_packet_total_dropped))) {
		return result;
	}
#endif

	return ecm_state_prefix_remove(sfi);
}
EXPORT_SYMBOL(ecm_db_host_state_get);

/*
 * ecm_db_node_state_get()
 *	Prepare a node message
 */
int ecm_db_node_state_get(struct ecm_state_file_instance *sfi, struct ecm_db_node_instance *ni)
{
	int result;
	char address[ECM_MAC_ADDR_STR_BUFF_SIZE];
#ifdef ECM_DB_XREF_ENABLE
	int from_connections_count;
	int to_connections_count;
	int from_nat_connections_count;
	int to_nat_connections_count;
#endif
	uint32_t time_added;
#ifdef ECM_DB_ADVANCED_STATS_ENABLE
	uint64_t from_data_total;
	uint64_t to_data_total;
	uint64_t from_packet_total;
	uint64_t to_packet_total;
	uint64_t from_data_total_dropped;
	uint64_t to_data_total_dropped;
	uint64_t from_packet_total_dropped;
	uint64_t to_packet_total_dropped;
#endif

	DEBUG_TRACE("Prep node msg for %p\n", ni);

	/*
	 * Create a small xml stats block for our managed node, like:
	 * <node address="" hosts="" time_added="" from_data_total="" to_data_total="" />
	 *
	 * Extract information from the node for inclusion into the message
	 */
#ifdef ECM_DB_XREF_ENABLE
	spin_lock_bh(&ecm_db_lock);
	from_connections_count = ni->from_connections_count;
	to_connections_count = ni->to_connections_count;
	from_nat_connections_count = ni->from_nat_connections_count;
	to_nat_connections_count = ni->to_nat_connections_count;
	spin_unlock_bh(&ecm_db_lock);
#endif
	time_added = ni->time_added;
	snprintf(address, sizeof(address), "%pM", ni->address);

#ifdef ECM_DB_ADVANCED_STATS_ENABLE
	ecm_db_node_data_stats_get(ni, &from_data_total, &to_data_total,
			&from_packet_total, &to_packet_total,
			&from_data_total_dropped, &to_data_total_dropped,
			&from_packet_total_dropped, &to_packet_total_dropped);

#endif

	if ((result = ecm_state_prefix_add(sfi, "node"))) {
		return result;
	}
	if ((result = ecm_state_write(sfi, "address", "%s", address))) {
		return result;
	}
	if ((result = ecm_state_write(sfi, "time_added", "%u", time_added))) {
		return result;
	}
#ifdef ECM_DB_XREF_ENABLE
	if ((result = ecm_state_write(sfi, "from_connections_count", "%d", from_connections_count))) {
		return result;
	}
	if ((result = ecm_state_write(sfi, "to_connections_count", "%d", to_connections_count))) {
		return result;
	}
	if ((result = ecm_state_write(sfi, "from_nat_connections_count", "%d", from_nat_connections_count))) {
		return result;
	}
	if ((result = ecm_state_write(sfi, "to_nat_connections_count", "%d", to_nat_connections_count))) {
		return result;
	}
#endif
#ifdef ECM_DB_ADVANCED_STATS_ENABLE
	if ((result = ecm_db_adv_stats_state_write(sfi, from_data_total, to_data_total,
			from_packet_total, to_packet_total, from_data_total_dropped,
			to_data_total_dropped, from_packet_total_dropped,
			to_packet_total_dropped))) {
		return result;
	}
#endif
	return ecm_state_prefix_remove(sfi);
}
EXPORT_SYMBOL(ecm_db_node_state_get);

/*
 * ecm_db_connection_hash_table_lengths_get()
 *	Return hash table length
 */
int ecm_db_connection_hash_table_lengths_get(int index)
{
	int length;

	DEBUG_ASSERT((index >= 0) && (index < ECM_DB_MAPPING_HASH_SLOTS), "Bad protocol: %d\n", index);
	spin_lock_bh(&ecm_db_lock);
	length = ecm_db_connection_table_lengths[index];
	spin_unlock_bh(&ecm_db_lock);
	return length;
}
EXPORT_SYMBOL(ecm_db_connection_hash_table_lengths_get);

/*
 * ecm_db_connection_hash_index_get_next()
 * Given a hash index, return the next one OR return -1 for no more hash indicies to return.
 */
int ecm_db_connection_hash_index_get_next(int index)
{
	index++;
	if (index >= ECM_DB_CONNECTION_SERIAL_HASH_SLOTS) {
		return -1;
	}
	return index;
}
EXPORT_SYMBOL(ecm_db_connection_hash_index_get_next);

/*
 * ecm_db_connection_hash_index_get_first()
 * Return first hash index
 */
int ecm_db_connection_hash_index_get_first(void)
{
	return 0;
}
EXPORT_SYMBOL(ecm_db_connection_hash_index_get_first);

/*
 * ecm_db_mapping_hash_table_lengths_get()
 *	Return hash table length
 */
int ecm_db_mapping_hash_table_lengths_get(int index)
{
	int length;

	DEBUG_ASSERT((index >= 0) && (index < ECM_DB_MAPPING_HASH_SLOTS), "Bad protocol: %d\n", index);
	spin_lock_bh(&ecm_db_lock);
	length = ecm_db_mapping_table_lengths[index];
	spin_unlock_bh(&ecm_db_lock);
	return length;
}
EXPORT_SYMBOL(ecm_db_mapping_hash_table_lengths_get);

/*
 * ecm_db_mapping_hash_index_get_next()
 * Given a hash index, return the next one OR return -1 for no more hash indicies to return.
 */
int ecm_db_mapping_hash_index_get_next(int index)
{
	index++;
	if (index >= ECM_DB_MAPPING_HASH_SLOTS) {
		return -1;
	}
	return index;
}
EXPORT_SYMBOL(ecm_db_mapping_hash_index_get_next);

/*
 * ecm_db_mapping_hash_index_get_first()
 * Return first hash index
 */
int ecm_db_mapping_hash_index_get_first(void)
{
	return 0;
}
EXPORT_SYMBOL(ecm_db_mapping_hash_index_get_first);

/*
 * ecm_db_host_hash_table_lengths_get()
 *	Return hash table length
 */
int ecm_db_host_hash_table_lengths_get(int index)
{
	int length;

	DEBUG_ASSERT((index >= 0) && (index < ECM_DB_HOST_HASH_SLOTS), "Bad protocol: %d\n", index);
	spin_lock_bh(&ecm_db_lock);
	length = ecm_db_host_table_lengths[index];
	spin_unlock_bh(&ecm_db_lock);
	return length;
}
EXPORT_SYMBOL(ecm_db_host_hash_table_lengths_get);

/*
 * ecm_db_host_hash_index_get_next()
 * Given a hash index, return the next one OR return -1 for no more hash indicies to return.
 */
int ecm_db_host_hash_index_get_next(int index)
{
	index++;
	if (index >= ECM_DB_HOST_HASH_SLOTS) {
		return -1;
	}
	return index;
}
EXPORT_SYMBOL(ecm_db_host_hash_index_get_next);

/*
 * ecm_db_host_hash_index_get_first()
 * Return first hash index
 */
int ecm_db_host_hash_index_get_first(void)
{
	return 0;
}
EXPORT_SYMBOL(ecm_db_host_hash_index_get_first);

/*
 * ecm_db_node_hash_table_lengths_get()
 *	Return hash table length
 */
int ecm_db_node_hash_table_lengths_get(int index)
{
	int length;

	DEBUG_ASSERT((index >= 0) && (index < ECM_DB_NODE_HASH_SLOTS), "Bad protocol: %d\n", index);
	spin_lock_bh(&ecm_db_lock);
	length = ecm_db_node_table_lengths[index];
	spin_unlock_bh(&ecm_db_lock);
	return length;
}
EXPORT_SYMBOL(ecm_db_node_hash_table_lengths_get);

/*
 * ecm_db_node_hash_index_get_next()
 * Given a hash index, return the next one OR return -1 for no more hash indicies to return.
 */
int ecm_db_node_hash_index_get_next(int index)
{
	index++;
	if (index >= ECM_DB_NODE_HASH_SLOTS) {
		return -1;
	}
	return index;
}
EXPORT_SYMBOL(ecm_db_node_hash_index_get_next);

/*
 * ecm_db_node_hash_index_get_first()
 * Return first hash index
 */
int ecm_db_node_hash_index_get_first(void)
{
	return 0;
}
EXPORT_SYMBOL(ecm_db_node_hash_index_get_first);

/*
 * ecm_db_iface_hash_table_lengths_get()
 *	Return hash table length
 */
int ecm_db_iface_hash_table_lengths_get(int index)
{
	int length;

	DEBUG_ASSERT((index >= 0) && (index < ECM_DB_IFACE_HASH_SLOTS), "Bad protocol: %d\n", index);
	spin_lock_bh(&ecm_db_lock);
	length = ecm_db_iface_table_lengths[index];
	spin_unlock_bh(&ecm_db_lock);
	return length;
}
EXPORT_SYMBOL(ecm_db_iface_hash_table_lengths_get);

/*
 * ecm_db_iface_hash_index_get_next()
 * Given a hash index, return the next one OR return -1 for no more hash indicies to return.
 */
int ecm_db_iface_hash_index_get_next(int index)
{
	index++;
	if (index >= ECM_DB_IFACE_HASH_SLOTS) {
		return -1;
	}
	return index;
}
EXPORT_SYMBOL(ecm_db_iface_hash_index_get_next);

/*
 * ecm_db_iface_hash_index_get_first()
 * Return first hash index
 */
int ecm_db_iface_hash_index_get_first(void)
{
	return 0;
}
EXPORT_SYMBOL(ecm_db_iface_hash_index_get_first);

/*
 * ecm_db_protocol_get_next()
 * Given a number, return the next one OR return -1 for no more protocol numbers to return.
 */
int ecm_db_protocol_get_next(int protocol)
{
	protocol++;
	if (protocol >= ECM_DB_PROTOCOL_COUNT) {
		return -1;
	}
	return protocol;
}
EXPORT_SYMBOL(ecm_db_protocol_get_next);

/*
 * ecm_db_protocol_get_first()
 * Return first protocol number
 */
int ecm_db_protocol_get_first(void)
{
	return 0;
}
EXPORT_SYMBOL(ecm_db_protocol_get_first);
#endif

/*
 * ecm_db_iface_add_ethernet()
 *	Add a iface instance into the database
 */
void ecm_db_iface_add_ethernet(struct ecm_db_iface_instance *ii, uint8_t *address, char *name, int32_t mtu,
					int32_t interface_identifier, int32_t ae_interface_identifier,
					ecm_db_iface_final_callback_t final, void *arg)
{
	ecm_db_iface_hash_t hash_index;
	ecm_db_iface_id_hash_t iface_id_hash_index;
	struct ecm_db_listener_instance *li;
	struct ecm_db_interface_info_ethernet *type_info;

	spin_lock_bh(&ecm_db_lock);
	DEBUG_CHECK_MAGIC(ii, ECM_DB_IFACE_INSTANCE_MAGIC, "%p: magic failed\n", ii);
	DEBUG_ASSERT(address, "%p: address null\n", ii);
#ifdef ECM_DB_XREF_ENABLE
	DEBUG_ASSERT((ii->nodes == NULL) && (ii->node_count == 0), "%p: nodes not null\n", ii);
#endif
	DEBUG_ASSERT(!(ii->flags & ECM_DB_IFACE_FLAGS_INSERTED), "%p: inserted\n", ii);
	DEBUG_ASSERT(name, "%p: no name given\n", ii);
	spin_unlock_bh(&ecm_db_lock);

	/*
	 * Record general info
	 */
	ii->type = ECM_DB_IFACE_TYPE_ETHERNET;
#ifdef ECM_STATE_OUTPUT_ENABLE
	ii->state_get = ecm_db_iface_ethernet_state_get;
#endif
	ii->arg = arg;
	ii->final = final;
	strcpy(ii->name, name);
	ii->mtu = mtu;
	ii->interface_identifier = interface_identifier;
	ii->ae_interface_identifier = ae_interface_identifier;

	/*
	 * Type specific info
	 */
	type_info = &ii->type_info.ethernet;
	memcpy(type_info->address, address, ETH_ALEN);

	/*
	 * Compute hash chain for insertion
	 */
	hash_index = ecm_db_iface_generate_hash_index_ethernet(address);
	ii->hash_index = hash_index;

	iface_id_hash_index = ecm_db_iface_id_generate_hash_index(interface_identifier);
	ii->iface_id_hash_index = iface_id_hash_index;

	/*
	 * Add into the global list
	 */
	spin_lock_bh(&ecm_db_lock);
	ii->flags |= ECM_DB_IFACE_FLAGS_INSERTED;
	ii->prev = NULL;
	ii->next = ecm_db_interfaces;
	if (ecm_db_interfaces) {
		ecm_db_interfaces->prev = ii;
	}
	ecm_db_interfaces = ii;

	/*
	 * Insert into chain
	 */
	ii->hash_next = ecm_db_iface_table[hash_index];
	if (ecm_db_iface_table[hash_index]) {
		ecm_db_iface_table[hash_index]->hash_prev = ii;
	}
	ecm_db_iface_table[hash_index] = ii;
	ecm_db_iface_table_lengths[hash_index]++;
	DEBUG_ASSERT(ecm_db_iface_table_lengths[hash_index] > 0, "%p: invalid table len %d\n", ii, ecm_db_iface_table_lengths[hash_index]);

	DEBUG_INFO("%p: interface inserted at hash index %u, hash prev is %p, type: %d\n", ii, ii->hash_index, ii->hash_prev, ii->type);

	/*
	 * Insert into interface identifier chain
	 */
	ii->iface_id_hash_next = ecm_db_iface_id_table[iface_id_hash_index];
	if (ecm_db_iface_id_table[iface_id_hash_index]) {
		ecm_db_iface_id_table[iface_id_hash_index]->iface_id_hash_prev = ii;
	}
	ecm_db_iface_id_table[iface_id_hash_index] = ii;
	ecm_db_iface_id_table_lengths[iface_id_hash_index]++;
	DEBUG_ASSERT(ecm_db_iface_id_table_lengths[iface_id_hash_index] > 0, "%p: invalid iface id table len %d\n", ii, ecm_db_iface_id_table_lengths[iface_id_hash_index]);

	/*
	 * Set time of addition
	 */
	ii->time_added = ecm_db_time;
	spin_unlock_bh(&ecm_db_lock);

	/*
	 * Throw add event to the listeners
 	 */
	DEBUG_TRACE("%p: Throw iface added event\n", ii);
	li = ecm_db_listeners_get_and_ref_first();
	while (li) {
		struct ecm_db_listener_instance *lin;
		if (li->iface_added) {
			li->iface_added(li->arg, ii);
		}

		/*
		 * Get next listener
		 */
		lin = ecm_db_listener_get_and_ref_next(li);
		ecm_db_listener_deref(li);
		li = lin;
	}
}
EXPORT_SYMBOL(ecm_db_iface_add_ethernet);

#ifdef ECM_INTERFACE_BOND_ENABLE
/*
 * ecm_db_iface_add_lag()
 *	Add a iface instance into the database
 */
void ecm_db_iface_add_lag(struct ecm_db_iface_instance *ii, uint8_t *address, char *name, int32_t mtu,
					int32_t interface_identifier, int32_t ae_interface_identifier,
					ecm_db_iface_final_callback_t final, void *arg)
{
	ecm_db_iface_hash_t hash_index;
	ecm_db_iface_id_hash_t iface_id_hash_index;
	struct ecm_db_listener_instance *li;
	struct ecm_db_interface_info_lag *type_info;

	spin_lock_bh(&ecm_db_lock);
	DEBUG_CHECK_MAGIC(ii, ECM_DB_IFACE_INSTANCE_MAGIC, "%p: magic failed\n", ii);
	DEBUG_ASSERT(address, "%p: address null\n", ii);
#ifdef ECM_DB_XREF_ENABLE
	DEBUG_ASSERT((ii->nodes == NULL) && (ii->node_count == 0), "%p: nodes not null\n", ii);
#endif
	DEBUG_ASSERT(!(ii->flags & ECM_DB_IFACE_FLAGS_INSERTED), "%p: inserted\n", ii);
	DEBUG_ASSERT(name, "%p: no name given\n", ii);
	spin_unlock_bh(&ecm_db_lock);

	/*
	 * Record general info
	 */
	ii->type = ECM_DB_IFACE_TYPE_LAG;
#ifdef ECM_STATE_OUTPUT_ENABLE
	ii->state_get = ecm_db_iface_lag_state_get;
#endif
	ii->arg = arg;
	ii->final = final;
	strcpy(ii->name, name);
	ii->mtu = mtu;
	ii->interface_identifier = interface_identifier;
	ii->ae_interface_identifier = ae_interface_identifier;

	/*
	 * Type specific info
	 */
	type_info = &ii->type_info.lag;
	memcpy(type_info->address, address, ETH_ALEN);

	/*
	 * Compute hash chain for insertion
	 */
	hash_index = ecm_db_iface_generate_hash_index_ethernet(address);
	ii->hash_index = hash_index;

	iface_id_hash_index = ecm_db_iface_id_generate_hash_index(interface_identifier);
	ii->iface_id_hash_index = iface_id_hash_index;

	/*
	 * Add into the global list
	 */
	spin_lock_bh(&ecm_db_lock);
	ii->flags |= ECM_DB_IFACE_FLAGS_INSERTED;
	ii->prev = NULL;
	ii->next = ecm_db_interfaces;
	if (ecm_db_interfaces) {
		ecm_db_interfaces->prev = ii;
	}
	ecm_db_interfaces = ii;

	/*
	 * Insert into chain
	 */
	ii->hash_next = ecm_db_iface_table[hash_index];
	if (ecm_db_iface_table[hash_index]) {
		ecm_db_iface_table[hash_index]->hash_prev = ii;
	}
	ecm_db_iface_table[hash_index] = ii;
	ecm_db_iface_table_lengths[hash_index]++;
	DEBUG_ASSERT(ecm_db_iface_table_lengths[hash_index] > 0, "%p: invalid table len %d\n", ii, ecm_db_iface_table_lengths[hash_index]);

	DEBUG_INFO("%p: interface inserted at hash index %u, hash prev is %p, type: %d\n", ii, ii->hash_index, ii->hash_prev, ii->type);

	/*
	 * Insert into interface identifier chain
	 */
	ii->iface_id_hash_next = ecm_db_iface_id_table[iface_id_hash_index];
	if (ecm_db_iface_id_table[iface_id_hash_index]) {
		ecm_db_iface_id_table[iface_id_hash_index]->iface_id_hash_prev = ii;
	}
	ecm_db_iface_id_table[iface_id_hash_index] = ii;
	ecm_db_iface_id_table_lengths[iface_id_hash_index]++;
	DEBUG_ASSERT(ecm_db_iface_id_table_lengths[iface_id_hash_index] > 0, "%p: invalid iface id table len %d\n", ii, ecm_db_iface_id_table_lengths[iface_id_hash_index]);

	/*
	 * Set time of addition
	 */
	ii->time_added = ecm_db_time;
	spin_unlock_bh(&ecm_db_lock);

	/*
	 * Throw add event to the listeners
 	 */
	DEBUG_TRACE("%p: Throw iface added event\n", ii);
	li = ecm_db_listeners_get_and_ref_first();
	while (li) {
		struct ecm_db_listener_instance *lin;
		if (li->iface_added) {
			li->iface_added(li->arg, ii);
		}

		/*
		 * Get next listener
		 */
		lin = ecm_db_listener_get_and_ref_next(li);
		ecm_db_listener_deref(li);
		li = lin;
	}
}
EXPORT_SYMBOL(ecm_db_iface_add_lag);
#endif

/*
 * ecm_db_iface_add_bridge()
 *	Add a iface instance into the database
 */
void ecm_db_iface_add_bridge(struct ecm_db_iface_instance *ii, uint8_t *address, char *name, int32_t mtu,
					int32_t interface_identifier, int32_t ae_interface_identifier,
					ecm_db_iface_final_callback_t final, void *arg)
{
	ecm_db_iface_hash_t hash_index;
	ecm_db_iface_id_hash_t iface_id_hash_index;
	struct ecm_db_listener_instance *li;
	struct ecm_db_interface_info_bridge *type_info;

	spin_lock_bh(&ecm_db_lock);
	DEBUG_CHECK_MAGIC(ii, ECM_DB_IFACE_INSTANCE_MAGIC, "%p: magic failed\n", ii);
	DEBUG_ASSERT(address, "%p: address null\n", ii);
#ifdef ECM_DB_XREF_ENABLE
	DEBUG_ASSERT((ii->nodes == NULL) && (ii->node_count == 0), "%p: nodes not null\n", ii);
#endif
	DEBUG_ASSERT(!(ii->flags & ECM_DB_IFACE_FLAGS_INSERTED), "%p: inserted\n", ii);
	DEBUG_ASSERT(name, "%p: no name given\n", ii);
	spin_unlock_bh(&ecm_db_lock);

	/*
	 * Record general info
	 */
	ii->type = ECM_DB_IFACE_TYPE_BRIDGE;
#ifdef ECM_STATE_OUTPUT_ENABLE
	ii->state_get = ecm_db_iface_bridge_state_get;
#endif
	ii->arg = arg;
	ii->final = final;
	strcpy(ii->name, name);
	ii->mtu = mtu;
	ii->interface_identifier = interface_identifier;
	ii->ae_interface_identifier = ae_interface_identifier;

	/*
	 * Type specific info
	 */
	type_info = &ii->type_info.bridge;
	memcpy(type_info->address, address, ETH_ALEN);

	/*
	 * Compute hash chain for insertion
	 */
	hash_index = ecm_db_iface_generate_hash_index_ethernet(address);
	ii->hash_index = hash_index;

	iface_id_hash_index = ecm_db_iface_id_generate_hash_index(interface_identifier);
	ii->iface_id_hash_index = iface_id_hash_index;

	/*
	 * Add into the global list
	 */
	spin_lock_bh(&ecm_db_lock);
	ii->flags |= ECM_DB_IFACE_FLAGS_INSERTED;
	ii->prev = NULL;
	ii->next = ecm_db_interfaces;
	if (ecm_db_interfaces) {
		ecm_db_interfaces->prev = ii;
	}
	ecm_db_interfaces = ii;

	/*
	 * Insert into chain
	 */
	ii->hash_next = ecm_db_iface_table[hash_index];
	if (ecm_db_iface_table[hash_index]) {
		ecm_db_iface_table[hash_index]->hash_prev = ii;
	}
	ecm_db_iface_table[hash_index] = ii;
	ecm_db_iface_table_lengths[hash_index]++;
	DEBUG_ASSERT(ecm_db_iface_table_lengths[hash_index] > 0, "%p: invalid table len %d\n", ii, ecm_db_iface_table_lengths[hash_index]);

	DEBUG_INFO("%p: interface inserted at hash index %u, hash prev is %p, type: %d\n", ii, ii->hash_index, ii->hash_prev, ii->type);

	/*
	 * Insert into interface identifier chain
	 */
	ii->iface_id_hash_next = ecm_db_iface_id_table[iface_id_hash_index];
	if (ecm_db_iface_id_table[iface_id_hash_index]) {
		ecm_db_iface_id_table[iface_id_hash_index]->iface_id_hash_prev = ii;
	}
	ecm_db_iface_id_table[iface_id_hash_index] = ii;
	ecm_db_iface_id_table_lengths[iface_id_hash_index]++;
	DEBUG_ASSERT(ecm_db_iface_id_table_lengths[iface_id_hash_index] > 0, "%p: invalid iface id table len %d\n", ii, ecm_db_iface_id_table_lengths[iface_id_hash_index]);

	/*
	 * Set time of addition
	 */
	ii->time_added = ecm_db_time;
	spin_unlock_bh(&ecm_db_lock);

	/*
	 * Throw add event to the listeners
 	 */
	DEBUG_TRACE("%p: Throw iface added event\n", ii);
	li = ecm_db_listeners_get_and_ref_first();
	while (li) {
		struct ecm_db_listener_instance *lin;
		if (li->iface_added) {
			li->iface_added(li->arg, ii);
		}

		/*
		 * Get next listener
		 */
		lin = ecm_db_listener_get_and_ref_next(li);
		ecm_db_listener_deref(li);
		li = lin;
	}
}
EXPORT_SYMBOL(ecm_db_iface_add_bridge);

#ifdef ECM_INTERFACE_VLAN_ENABLE
/*
 * ecm_db_iface_add_vlan()
 *	Add a iface instance into the database
 */
void ecm_db_iface_add_vlan(struct ecm_db_iface_instance *ii, uint8_t *address, uint16_t vlan_tag, uint16_t vlan_tpid, char *name, int32_t mtu,
					int32_t interface_identifier, int32_t ae_interface_identifier,
					ecm_db_iface_final_callback_t final, void *arg)
{
	ecm_db_iface_hash_t hash_index;
	ecm_db_iface_id_hash_t iface_id_hash_index;
	struct ecm_db_listener_instance *li;
	struct ecm_db_interface_info_vlan *type_info;

	spin_lock_bh(&ecm_db_lock);
	DEBUG_CHECK_MAGIC(ii, ECM_DB_IFACE_INSTANCE_MAGIC, "%p: magic failed\n", ii);
	DEBUG_ASSERT(address, "%p: address null\n", ii);
#ifdef ECM_DB_XREF_ENABLE
	DEBUG_ASSERT((ii->nodes == NULL) && (ii->node_count == 0), "%p: nodes not null\n", ii);
#endif
	DEBUG_ASSERT(!(ii->flags & ECM_DB_IFACE_FLAGS_INSERTED), "%p: inserted\n", ii);
	DEBUG_ASSERT(name, "%p: no name given\n", ii);
	spin_unlock_bh(&ecm_db_lock);

	/*
	 * Record general info
	 */
	ii->type = ECM_DB_IFACE_TYPE_VLAN;
#ifdef ECM_STATE_OUTPUT_ENABLE
	ii->state_get = ecm_db_iface_vlan_state_get;
#endif
	ii->arg = arg;
	ii->final = final;
	strcpy(ii->name, name);
	ii->mtu = mtu;
	ii->interface_identifier = interface_identifier;
	ii->ae_interface_identifier = ae_interface_identifier;

	/*
	 * Type specific info
	 */
	type_info = &ii->type_info.vlan;
	type_info->vlan_tag = vlan_tag;
	type_info->vlan_tpid = vlan_tpid;
	memcpy(type_info->address, address, ETH_ALEN);

	/*
	 * Compute hash chain for insertion
	 */
	hash_index = ecm_db_iface_generate_hash_index_ethernet(address);
	ii->hash_index = hash_index;

	iface_id_hash_index = ecm_db_iface_id_generate_hash_index(interface_identifier);
	ii->iface_id_hash_index = iface_id_hash_index;

	/*
	 * Add into the global list
	 */
	spin_lock_bh(&ecm_db_lock);
	ii->flags |= ECM_DB_IFACE_FLAGS_INSERTED;
	ii->prev = NULL;
	ii->next = ecm_db_interfaces;
	if (ecm_db_interfaces) {
		ecm_db_interfaces->prev = ii;
	}
	ecm_db_interfaces = ii;

	/*
	 * Insert into chain
	 */
	ii->hash_next = ecm_db_iface_table[hash_index];
	if (ecm_db_iface_table[hash_index]) {
		ecm_db_iface_table[hash_index]->hash_prev = ii;
	}
	ecm_db_iface_table[hash_index] = ii;
	ecm_db_iface_table_lengths[hash_index]++;
	DEBUG_ASSERT(ecm_db_iface_table_lengths[hash_index] > 0, "%p: invalid table len %d\n", ii, ecm_db_iface_table_lengths[hash_index]);

	DEBUG_INFO("%p: interface inserted at hash index %u, hash prev is %p, type: %d\n", ii, ii->hash_index, ii->hash_prev, ii->type);

	/*
	 * Insert into interface identifier chain
	 */
	ii->iface_id_hash_next = ecm_db_iface_id_table[iface_id_hash_index];
	if (ecm_db_iface_id_table[iface_id_hash_index]) {
		ecm_db_iface_id_table[iface_id_hash_index]->iface_id_hash_prev = ii;
	}
	ecm_db_iface_id_table[iface_id_hash_index] = ii;
	ecm_db_iface_id_table_lengths[iface_id_hash_index]++;
	DEBUG_ASSERT(ecm_db_iface_id_table_lengths[iface_id_hash_index] > 0, "%p: invalid iface id table len %d\n", ii, ecm_db_iface_id_table_lengths[iface_id_hash_index]);

	/*
	 * Set time of addition
	 */
	ii->time_added = ecm_db_time;
	spin_unlock_bh(&ecm_db_lock);

	/*
	 * Throw add event to the listeners
 	 */
	DEBUG_TRACE("%p: Throw iface added event\n", ii);
	li = ecm_db_listeners_get_and_ref_first();
	while (li) {
		struct ecm_db_listener_instance *lin;
		if (li->iface_added) {
			li->iface_added(li->arg, ii);
		}

		/*
		 * Get next listener
		 */
		lin = ecm_db_listener_get_and_ref_next(li);
		ecm_db_listener_deref(li);
		li = lin;
	}
}
EXPORT_SYMBOL(ecm_db_iface_add_vlan);
#endif

#ifdef ECM_INTERFACE_MAP_T_ENABLE
/*
 * ecm_db_iface_add_map_t()
 *	Add a iface instance into the database
 */
void ecm_db_iface_add_map_t(struct ecm_db_iface_instance *ii, struct ecm_db_interface_info_map_t *map_t_info,
					char *name, int32_t mtu, int32_t interface_identifier,
					int32_t ae_interface_identifier, ecm_db_iface_final_callback_t final,
					void *arg)
{
	ecm_db_iface_hash_t hash_index;
	ecm_db_iface_id_hash_t iface_id_hash_index;
	struct ecm_db_listener_instance *li;
	struct ecm_db_interface_info_map_t *type_info;

	spin_lock_bh(&ecm_db_lock);
	DEBUG_CHECK_MAGIC(ii, ECM_DB_IFACE_INSTANCE_MAGIC, "%p: magic failed\n", ii);
#ifdef ECM_DB_XREF_ENABLE
	DEBUG_ASSERT((ii->nodes == NULL) && (ii->node_count == 0), "%p: nodes not null\n", ii);
#endif
	DEBUG_ASSERT(!(ii->flags & ECM_DB_IFACE_FLAGS_INSERTED), "%p: inserted\n", ii);
	DEBUG_ASSERT(name, "%p: no name given\n", ii);
	spin_unlock_bh(&ecm_db_lock);

	/*
	 * Record general info
	 */
	ii->type = ECM_DB_IFACE_TYPE_MAP_T;
#ifdef ECM_STATE_OUTPUT_ENABLE
	ii->state_get = ecm_db_iface_map_t_state_get;
#endif
	ii->arg = arg;
	ii->final = final;
	strlcpy(ii->name, name, IFNAMSIZ);
	ii->mtu = mtu;
	ii->interface_identifier = interface_identifier;
	ii->ae_interface_identifier = ae_interface_identifier;

	/*
	 * Type specific info
	 */
	type_info = &ii->type_info.map_t;
	memcpy(type_info, map_t_info, sizeof(struct ecm_db_interface_info_map_t));

	/*
	 * Compute hash chain for insertion
	 */
	hash_index = ecm_db_iface_generate_hash_index_map_t(type_info->if_index);
	ii->hash_index = hash_index;

	iface_id_hash_index = ecm_db_iface_id_generate_hash_index(interface_identifier);
	ii->iface_id_hash_index = iface_id_hash_index;
	/*
	 * Add into the global list
	 */
	spin_lock_bh(&ecm_db_lock);
	ii->flags |= ECM_DB_IFACE_FLAGS_INSERTED;
	ii->prev = NULL;
	ii->next = ecm_db_interfaces;
	if (ecm_db_interfaces) {
		ecm_db_interfaces->prev = ii;
	}
	ecm_db_interfaces = ii;

	/*
	 * Insert into chain
	 */
	ii->hash_next = ecm_db_iface_table[hash_index];
	if (ecm_db_iface_table[hash_index]) {
		ecm_db_iface_table[hash_index]->hash_prev = ii;
	}
	ecm_db_iface_table[hash_index] = ii;
	ecm_db_iface_table_lengths[hash_index]++;
	DEBUG_ASSERT(ecm_db_iface_table_lengths[hash_index] > 0, "%p: invalid table len %d\n", ii, ecm_db_iface_table_lengths[hash_index]);

	DEBUG_INFO("%p: interface inserted at hash index %u, hash prev is %p, type: %d\n", ii, ii->hash_index, ii->hash_prev, ii->type);

	/*
	 * Insert into interface identifier chain
	 */
	ii->iface_id_hash_next = ecm_db_iface_id_table[iface_id_hash_index];
	if (ecm_db_iface_id_table[iface_id_hash_index]) {
		ecm_db_iface_id_table[iface_id_hash_index]->iface_id_hash_prev = ii;
	}
	ecm_db_iface_id_table[iface_id_hash_index] = ii;
	ecm_db_iface_id_table_lengths[iface_id_hash_index]++;
	DEBUG_ASSERT(ecm_db_iface_id_table_lengths[iface_id_hash_index] > 0, "%p: invalid iface id table len %d\n", ii, ecm_db_iface_id_table_lengths[iface_id_hash_index]);

	/*
	 * Set time of addition
	 */
	ii->time_added = ecm_db_time;
	spin_unlock_bh(&ecm_db_lock);

	/*
	 * Throw add event to the listeners
	 */
	DEBUG_TRACE("%p: Throw iface added event\n", ii);
	li = ecm_db_listeners_get_and_ref_first();
	while (li) {
		struct ecm_db_listener_instance *lin;
		if (li->iface_added) {
			li->iface_added(li->arg, ii);
		}

		/*
		 * Get next listener
		 */
		lin = ecm_db_listener_get_and_ref_next(li);
		ecm_db_listener_deref(li);
		li = lin;
	}
}
EXPORT_SYMBOL(ecm_db_iface_add_map_t);
#endif

#ifdef ECM_INTERFACE_PPPOE_ENABLE
/*
 * ecm_db_iface_add_pppoe()
 *	Add a iface instance into the database
 */
void ecm_db_iface_add_pppoe(struct ecm_db_iface_instance *ii, uint16_t pppoe_session_id, uint8_t *remote_mac,
					char *name, int32_t mtu, int32_t interface_identifier,
					int32_t ae_interface_identifier, ecm_db_iface_final_callback_t final,
					void *arg)
{
	ecm_db_iface_hash_t hash_index;
	ecm_db_iface_id_hash_t iface_id_hash_index;
	struct ecm_db_listener_instance *li;
	struct ecm_db_interface_info_pppoe *type_info;

	spin_lock_bh(&ecm_db_lock);
	DEBUG_CHECK_MAGIC(ii, ECM_DB_IFACE_INSTANCE_MAGIC, "%p: magic failed\n", ii);
#ifdef ECM_DB_XREF_ENABLE
	DEBUG_ASSERT((ii->nodes == NULL) && (ii->node_count == 0), "%p: nodes not null\n", ii);
#endif
	DEBUG_ASSERT(!(ii->flags & ECM_DB_IFACE_FLAGS_INSERTED), "%p: inserted\n", ii);
	DEBUG_ASSERT(name, "%p: no name given\n", ii);
	spin_unlock_bh(&ecm_db_lock);

	/*
	 * Record general info
	 */
	ii->type = ECM_DB_IFACE_TYPE_PPPOE;
#ifdef ECM_STATE_OUTPUT_ENABLE
	ii->state_get = ecm_db_iface_pppoe_state_get;
#endif
	ii->arg = arg;
	ii->final = final;
	strcpy(ii->name, name);
	ii->mtu = mtu;
	ii->interface_identifier = interface_identifier;
	ii->ae_interface_identifier = ae_interface_identifier;

	/*
	 * Type specific info
	 */
	type_info = &ii->type_info.pppoe;
	type_info->pppoe_session_id = pppoe_session_id;
	memcpy(type_info->remote_mac, remote_mac, ETH_ALEN);

	/*
	 * Compute hash chain for insertion
	 */
	hash_index = ecm_db_iface_generate_hash_index_pppoe(pppoe_session_id);
	ii->hash_index = hash_index;

	iface_id_hash_index = ecm_db_iface_id_generate_hash_index(interface_identifier);
	ii->iface_id_hash_index = iface_id_hash_index;

	/*
	 * Add into the global list
	 */
	spin_lock_bh(&ecm_db_lock);
	ii->flags |= ECM_DB_IFACE_FLAGS_INSERTED;
	ii->prev = NULL;
	ii->next = ecm_db_interfaces;
	if (ecm_db_interfaces) {
		ecm_db_interfaces->prev = ii;
	}
	ecm_db_interfaces = ii;

	/*
	 * Insert into chain
	 */
	ii->hash_next = ecm_db_iface_table[hash_index];
	if (ecm_db_iface_table[hash_index]) {
		ecm_db_iface_table[hash_index]->hash_prev = ii;
	}
	ecm_db_iface_table[hash_index] = ii;
	ecm_db_iface_table_lengths[hash_index]++;
	DEBUG_ASSERT(ecm_db_iface_table_lengths[hash_index] > 0, "%p: invalid table len %d\n", ii, ecm_db_iface_table_lengths[hash_index]);

	DEBUG_INFO("%p: interface inserted at hash index %u, hash prev is %p, type: %d\n", ii, ii->hash_index, ii->hash_prev, ii->type);

	/*
	 * Insert into interface identifier chain
	 */
	ii->iface_id_hash_next = ecm_db_iface_id_table[iface_id_hash_index];
	if (ecm_db_iface_id_table[iface_id_hash_index]) {
		ecm_db_iface_id_table[iface_id_hash_index]->iface_id_hash_prev = ii;
	}
	ecm_db_iface_id_table[iface_id_hash_index] = ii;
	ecm_db_iface_id_table_lengths[iface_id_hash_index]++;
	DEBUG_ASSERT(ecm_db_iface_id_table_lengths[iface_id_hash_index] > 0, "%p: invalid iface id table len %d\n", ii, ecm_db_iface_id_table_lengths[iface_id_hash_index]);

	/*
	 * Set time of addition
	 */
	ii->time_added = ecm_db_time;
	spin_unlock_bh(&ecm_db_lock);

	/*
	 * Throw add event to the listeners
 	 */
	DEBUG_TRACE("%p: Throw iface added event\n", ii);
	li = ecm_db_listeners_get_and_ref_first();
	while (li) {
		struct ecm_db_listener_instance *lin;
		if (li->iface_added) {
			li->iface_added(li->arg, ii);
		}

		/*
		 * Get next listener
		 */
		lin = ecm_db_listener_get_and_ref_next(li);
		ecm_db_listener_deref(li);
		li = lin;
	}
}
EXPORT_SYMBOL(ecm_db_iface_add_pppoe);
#endif

#ifdef ECM_INTERFACE_L2TPV2_ENABLE
/*
 * ecm_db_iface_add_pppol2tpv2()
 *	Add a iface instance into the database
 */
void ecm_db_iface_add_pppol2tpv2(struct ecm_db_iface_instance *ii, struct ecm_db_interface_info_pppol2tpv2 *pppol2tpv2_info,
					char *name, int32_t mtu, int32_t interface_identifier,
					int32_t ae_interface_identifier, ecm_db_iface_final_callback_t final,
					void *arg)
{
	ecm_db_iface_hash_t hash_index;
	ecm_db_iface_id_hash_t iface_id_hash_index;
	struct ecm_db_listener_instance *li;
	struct ecm_db_interface_info_pppol2tpv2 *type_info;

	spin_lock_bh(&ecm_db_lock);
	DEBUG_CHECK_MAGIC(ii, ECM_DB_IFACE_INSTANCE_MAGIC, "%p: magic failed\n", ii);
#ifdef ECM_DB_XREF_ENABLE
	DEBUG_ASSERT((ii->nodes == NULL) && (ii->node_count == 0), "%p: nodes not null\n", ii);
#endif
	DEBUG_ASSERT(!(ii->flags & ECM_DB_IFACE_FLAGS_INSERTED), "%p: inserted\n", ii);
	DEBUG_ASSERT(name, "%p: no name given\n", ii);
	spin_unlock_bh(&ecm_db_lock);

	/*
	 * Record general info
	 */
	ii->type = ECM_DB_IFACE_TYPE_PPPOL2TPV2;
#ifdef ECM_STATE_OUTPUT_ENABLE
	ii->state_get = ecm_db_iface_pppol2tpv2_state_get;
#endif
	ii->arg = arg;
	ii->final = final;
	strlcpy(ii->name, name, IFNAMSIZ);
	ii->mtu = mtu;
	ii->interface_identifier = interface_identifier;
	ii->ae_interface_identifier = ae_interface_identifier;

	/*
	 * Type specific info
	 */
	type_info = &ii->type_info.pppol2tpv2;
	memcpy(type_info, pppol2tpv2_info, sizeof(struct ecm_db_interface_info_pppol2tpv2));

	/*
	 * Compute hash chain for insertion
	 */
	hash_index = ecm_db_iface_generate_hash_index_pppol2tpv2(type_info->l2tp.tunnel.tunnel_id,
							  type_info->l2tp.session.session_id);
	ii->hash_index = hash_index;

	iface_id_hash_index = ecm_db_iface_id_generate_hash_index(interface_identifier);
	ii->iface_id_hash_index = iface_id_hash_index;
	/*
	 * Add into the global list
	 */
	spin_lock_bh(&ecm_db_lock);
	ii->flags |= ECM_DB_IFACE_FLAGS_INSERTED;
	ii->prev = NULL;
	ii->next = ecm_db_interfaces;
	if (ecm_db_interfaces) {
		ecm_db_interfaces->prev = ii;
	}
	ecm_db_interfaces = ii;

	/*
	 * Insert into chain
	 */
	ii->hash_next = ecm_db_iface_table[hash_index];
	if (ecm_db_iface_table[hash_index]) {
		ecm_db_iface_table[hash_index]->hash_prev = ii;
	}
	ecm_db_iface_table[hash_index] = ii;
	ecm_db_iface_table_lengths[hash_index]++;
	DEBUG_ASSERT(ecm_db_iface_table_lengths[hash_index] > 0, "%p: invalid table len %d\n", ii, ecm_db_iface_table_lengths[hash_index]);

	DEBUG_INFO("%p: interface inserted at hash index %u, hash prev is %p, type: %d\n", ii, ii->hash_index, ii->hash_prev, ii->type);

	/*
	 * Insert into interface identifier chain
	 */
	ii->iface_id_hash_next = ecm_db_iface_id_table[iface_id_hash_index];
	if (ecm_db_iface_id_table[iface_id_hash_index]) {
		ecm_db_iface_id_table[iface_id_hash_index]->iface_id_hash_prev = ii;
	}
	ecm_db_iface_id_table[iface_id_hash_index] = ii;
	ecm_db_iface_id_table_lengths[iface_id_hash_index]++;
	DEBUG_ASSERT(ecm_db_iface_id_table_lengths[iface_id_hash_index] > 0, "%p: invalid iface id table len %d\n", ii, ecm_db_iface_id_table_lengths[iface_id_hash_index]);

	/*
	 * Set time of addition
	 */
	ii->time_added = ecm_db_time;
	spin_unlock_bh(&ecm_db_lock);

	/*
	 * Throw add event to the listeners
	 */
	DEBUG_TRACE("%p: Throw iface added event\n", ii);
	li = ecm_db_listeners_get_and_ref_first();
	while (li) {
		struct ecm_db_listener_instance *lin;
		if (li->iface_added) {
			li->iface_added(li->arg, ii);
		}

		/*
		 * Get next listener
		 */
		lin = ecm_db_listener_get_and_ref_next(li);
		ecm_db_listener_deref(li);
		li = lin;
	}
}
EXPORT_SYMBOL(ecm_db_iface_add_pppol2tpv2);

#endif

#ifdef ECM_INTERFACE_PPTP_ENABLE
/*
 * ecm_db_iface_add_pptp()
 *	Add a iface instance into the database
 */
void ecm_db_iface_add_pptp(struct ecm_db_iface_instance *ii, struct ecm_db_interface_info_pptp *pptp_info,
					char *name, int32_t mtu, int32_t interface_identifier,
					int32_t ae_interface_identifier, ecm_db_iface_final_callback_t final,
					void *arg)
{
	ecm_db_iface_hash_t hash_index;
	ecm_db_iface_id_hash_t iface_id_hash_index;
	struct ecm_db_listener_instance *li;
	struct ecm_db_interface_info_pptp *type_info;

	DEBUG_CHECK_MAGIC(ii, ECM_DB_IFACE_INSTANCE_MAGIC, "%p: magic failed\n", ii);
	spin_lock_bh(&ecm_db_lock);
#ifdef ECM_DB_XREF_ENABLE
	DEBUG_ASSERT((ii->nodes == NULL) && (ii->node_count == 0), "%p: nodes not null\n", ii);
#endif
	DEBUG_ASSERT(!(ii->flags & ECM_DB_IFACE_FLAGS_INSERTED), "%p: inserted\n", ii);
	DEBUG_ASSERT(name, "%p: no name given\n", ii);
	spin_unlock_bh(&ecm_db_lock);

	/*
	 * Record general info
	 */
	ii->type = ECM_DB_IFACE_TYPE_PPTP;
#ifdef ECM_STATE_OUTPUT_ENABLE
	ii->state_get = ecm_db_iface_pptp_state_get;
#endif
	ii->arg = arg;
	ii->final = final;
	strlcpy(ii->name, name, IFNAMSIZ);
	ii->mtu = mtu;
	ii->interface_identifier = interface_identifier;
	ii->ae_interface_identifier = ae_interface_identifier;

	/*
	 * Type specific info
	 */
	type_info = &ii->type_info.pptp;
	memcpy(type_info, pptp_info, sizeof(struct ecm_db_interface_info_pptp));

	/*
	 * Compute hash chain for insertion
	 */
	hash_index = ecm_db_iface_generate_hash_index_pptp(type_info->src_call_id,
							  type_info->dst_call_id);
	ii->hash_index = hash_index;

	iface_id_hash_index = ecm_db_iface_id_generate_hash_index(interface_identifier);
	ii->iface_id_hash_index = iface_id_hash_index;
	/*
	 * Add into the global list
	 */
	spin_lock_bh(&ecm_db_lock);
	ii->flags |= ECM_DB_IFACE_FLAGS_INSERTED;
	ii->prev = NULL;
	ii->next = ecm_db_interfaces;
	if (ecm_db_interfaces) {
		ecm_db_interfaces->prev = ii;
	}
	ecm_db_interfaces = ii;

	/*
	 * Insert into chain
	 */
	ii->hash_next = ecm_db_iface_table[hash_index];
	if (ecm_db_iface_table[hash_index]) {
		ecm_db_iface_table[hash_index]->hash_prev = ii;
	}
	ecm_db_iface_table[hash_index] = ii;
	ecm_db_iface_table_lengths[hash_index]++;
	DEBUG_ASSERT(ecm_db_iface_table_lengths[hash_index] > 0, "%p: invalid table len %d\n", ii, ecm_db_iface_table_lengths[hash_index]);

	DEBUG_INFO("%p: interface inserted at hash index %u, hash prev is %p, type: %d\n", ii, ii->hash_index, ii->hash_prev, ii->type);

	/*
	 * Insert into interface identifier chain
	 */
	ii->iface_id_hash_next = ecm_db_iface_id_table[iface_id_hash_index];
	if (ecm_db_iface_id_table[iface_id_hash_index]) {
		ecm_db_iface_id_table[iface_id_hash_index]->iface_id_hash_prev = ii;
	}
	ecm_db_iface_id_table[iface_id_hash_index] = ii;
	ecm_db_iface_id_table_lengths[iface_id_hash_index]++;
	DEBUG_ASSERT(ecm_db_iface_id_table_lengths[iface_id_hash_index] > 0, "%p: invalid iface id table len %d\n", ii, ecm_db_iface_id_table_lengths[iface_id_hash_index]);

	/*
	 * Set time of addition
	 */
	ii->time_added = ecm_db_time;
	spin_unlock_bh(&ecm_db_lock);

	/*
	 * Throw add event to the listeners
	 */
	DEBUG_TRACE("%p: Throw iface added event\n", ii);
	li = ecm_db_listeners_get_and_ref_first();
	while (li) {
		struct ecm_db_listener_instance *lin;
		if (li->iface_added) {
			li->iface_added(li->arg, ii);
		}

		/*
		 * Get next listener
		 */
		lin = ecm_db_listener_get_and_ref_next(li);
		ecm_db_listener_deref(li);
		li = lin;
	}
}
EXPORT_SYMBOL(ecm_db_iface_add_pptp);
#endif

/*
 * ecm_db_iface_add_unknown()
 *	Add a iface instance into the database
 */
void ecm_db_iface_add_unknown(struct ecm_db_iface_instance *ii, uint32_t os_specific_ident, char *name, int32_t mtu,
					int32_t interface_identifier, int32_t ae_interface_identifier,
					ecm_db_iface_final_callback_t final, void *arg)
{
	ecm_db_iface_hash_t hash_index;
	ecm_db_iface_id_hash_t iface_id_hash_index;
	struct ecm_db_listener_instance *li;
	struct ecm_db_interface_info_unknown *type_info;

	spin_lock_bh(&ecm_db_lock);
	DEBUG_CHECK_MAGIC(ii, ECM_DB_IFACE_INSTANCE_MAGIC, "%p: magic failed\n", ii);
#ifdef ECM_DB_XREF_ENABLE
	DEBUG_ASSERT((ii->nodes == NULL) && (ii->node_count == 0), "%p: nodes not null\n", ii);
#endif
	DEBUG_ASSERT(!(ii->flags & ECM_DB_IFACE_FLAGS_INSERTED), "%p: inserted\n", ii);
	DEBUG_ASSERT(name, "%p: no name given\n", ii);
	spin_unlock_bh(&ecm_db_lock);

	/*
	 * Record general info
	 */
	ii->type = ECM_DB_IFACE_TYPE_UNKNOWN;
#ifdef ECM_STATE_OUTPUT_ENABLE
	ii->state_get = ecm_db_iface_unknown_state_get;
#endif
	ii->arg = arg;
	ii->final = final;
	strcpy(ii->name, name);
	ii->mtu = mtu;
	ii->interface_identifier = interface_identifier;
	ii->ae_interface_identifier = ae_interface_identifier;

	/*
	 * Type specific info
	 */
	type_info = &ii->type_info.unknown;
	type_info->os_specific_ident = os_specific_ident;

	/*
	 * Compute hash chain for insertion
	 */
	hash_index = ecm_db_iface_generate_hash_index_unknown(os_specific_ident);
	ii->hash_index = hash_index;

	iface_id_hash_index = ecm_db_iface_id_generate_hash_index(interface_identifier);
	ii->iface_id_hash_index = iface_id_hash_index;

	/*
	 * Add into the global list
	 */
	spin_lock_bh(&ecm_db_lock);
	ii->flags |= ECM_DB_IFACE_FLAGS_INSERTED;
	ii->prev = NULL;
	ii->next = ecm_db_interfaces;
	if (ecm_db_interfaces) {
		ecm_db_interfaces->prev = ii;
	}
	ecm_db_interfaces = ii;

	/*
	 * Insert into chain
	 */
	ii->hash_next = ecm_db_iface_table[hash_index];
	if (ecm_db_iface_table[hash_index]) {
		ecm_db_iface_table[hash_index]->hash_prev = ii;
	}
	ecm_db_iface_table[hash_index] = ii;
	ecm_db_iface_table_lengths[hash_index]++;
	DEBUG_ASSERT(ecm_db_iface_table_lengths[hash_index] > 0, "%p: invalid table len %d\n", ii, ecm_db_iface_table_lengths[hash_index]);

	DEBUG_INFO("%p: interface inserted at hash index %u, hash prev is %p, type: %d\n", ii, ii->hash_index, ii->hash_prev, ii->type);

	/*
	 * Insert into interface identifier chain
	 */
	ii->iface_id_hash_next = ecm_db_iface_id_table[iface_id_hash_index];
	if (ecm_db_iface_id_table[iface_id_hash_index]) {
		ecm_db_iface_id_table[iface_id_hash_index]->iface_id_hash_prev = ii;
	}
	ecm_db_iface_id_table[iface_id_hash_index] = ii;
	ecm_db_iface_id_table_lengths[iface_id_hash_index]++;
	DEBUG_ASSERT(ecm_db_iface_id_table_lengths[iface_id_hash_index] > 0, "%p: invalid iface id table len %d\n", ii, ecm_db_iface_id_table_lengths[iface_id_hash_index]);

	/*
	 * Set time of addition
	 */
	ii->time_added = ecm_db_time;
	spin_unlock_bh(&ecm_db_lock);

	/*
	 * Throw add event to the listeners
 	 */
	DEBUG_TRACE("%p: Throw iface added event\n", ii);
	li = ecm_db_listeners_get_and_ref_first();
	while (li) {
		struct ecm_db_listener_instance *lin;
		if (li->iface_added) {
			li->iface_added(li->arg, ii);
		}

		/*
		 * Get next listener
		 */
		lin = ecm_db_listener_get_and_ref_next(li);
		ecm_db_listener_deref(li);
		li = lin;
	}
}
EXPORT_SYMBOL(ecm_db_iface_add_unknown);

/*
 * ecm_db_iface_add_loopback()
 *	Add a iface instance into the database
 */
void ecm_db_iface_add_loopback(struct ecm_db_iface_instance *ii, uint32_t os_specific_ident, char *name, int32_t mtu,
					int32_t interface_identifier, int32_t ae_interface_identifier,
					ecm_db_iface_final_callback_t final, void *arg)
{
	ecm_db_iface_hash_t hash_index;
	ecm_db_iface_id_hash_t iface_id_hash_index;
	struct ecm_db_listener_instance *li;
	struct ecm_db_interface_info_loopback *type_info;

	spin_lock_bh(&ecm_db_lock);
	DEBUG_CHECK_MAGIC(ii, ECM_DB_IFACE_INSTANCE_MAGIC, "%p: magic failed\n", ii);
#ifdef ECM_DB_XREF_ENABLE
	DEBUG_ASSERT((ii->nodes == NULL) && (ii->node_count == 0), "%p: nodes not null\n", ii);
#endif
	DEBUG_ASSERT(!(ii->flags & ECM_DB_IFACE_FLAGS_INSERTED), "%p: inserted\n", ii);
	DEBUG_ASSERT(name, "%p: no name given\n", ii);
	spin_unlock_bh(&ecm_db_lock);

	/*
	 * Record general info
	 */
	ii->type = ECM_DB_IFACE_TYPE_LOOPBACK;
#ifdef ECM_STATE_OUTPUT_ENABLE
	ii->state_get = ecm_db_iface_loopback_state_get;
#endif
	ii->arg = arg;
	ii->final = final;
	strcpy(ii->name, name);
	ii->mtu = mtu;
	ii->interface_identifier = interface_identifier;
	ii->ae_interface_identifier = ae_interface_identifier;

	/*
	 * Type specific info
	 */
	type_info = &ii->type_info.loopback;
	type_info->os_specific_ident = os_specific_ident;

	/*
	 * Compute hash chain for insertion
	 */
	hash_index = ecm_db_iface_generate_hash_index_loopback(os_specific_ident);
	ii->hash_index = hash_index;

	iface_id_hash_index = ecm_db_iface_id_generate_hash_index(interface_identifier);
	ii->iface_id_hash_index = iface_id_hash_index;

	/*
	 * Add into the global list
	 */
	spin_lock_bh(&ecm_db_lock);
	ii->flags |= ECM_DB_IFACE_FLAGS_INSERTED;
	ii->prev = NULL;
	ii->next = ecm_db_interfaces;
	if (ecm_db_interfaces) {
		ecm_db_interfaces->prev = ii;
	}
	ecm_db_interfaces = ii;

	/*
	 * Insert into chain
	 */
	ii->hash_next = ecm_db_iface_table[hash_index];
	if (ecm_db_iface_table[hash_index]) {
		ecm_db_iface_table[hash_index]->hash_prev = ii;
	}
	ecm_db_iface_table[hash_index] = ii;
	ecm_db_iface_table_lengths[hash_index]++;
	DEBUG_ASSERT(ecm_db_iface_table_lengths[hash_index] > 0, "%p: invalid table len %d\n", ii, ecm_db_iface_table_lengths[hash_index]);

	DEBUG_INFO("%p: interface inserted at hash index %u, hash prev is %p, type: %d\n", ii, ii->hash_index, ii->hash_prev, ii->type);

	/*
	 * Insert into interface identifier chain
	 */
	ii->iface_id_hash_next = ecm_db_iface_id_table[iface_id_hash_index];
	if (ecm_db_iface_id_table[iface_id_hash_index]) {
		ecm_db_iface_id_table[iface_id_hash_index]->iface_id_hash_prev = ii;
	}
	ecm_db_iface_id_table[iface_id_hash_index] = ii;
	ecm_db_iface_id_table_lengths[iface_id_hash_index]++;
	DEBUG_ASSERT(ecm_db_iface_id_table_lengths[iface_id_hash_index] > 0, "%p: invalid iface id table len %d\n", ii, ecm_db_iface_id_table_lengths[iface_id_hash_index]);

	/*
	 * Set time of addition
	 */
	ii->time_added = ecm_db_time;
	spin_unlock_bh(&ecm_db_lock);

	/*
	 * Throw add event to the listeners
 	 */
	DEBUG_TRACE("%p: Throw iface added event\n", ii);
	li = ecm_db_listeners_get_and_ref_first();
	while (li) {
		struct ecm_db_listener_instance *lin;
		if (li->iface_added) {
			li->iface_added(li->arg, ii);
		}

		/*
		 * Get next listener
		 */
		lin = ecm_db_listener_get_and_ref_next(li);
		ecm_db_listener_deref(li);
		li = lin;
	}
}
EXPORT_SYMBOL(ecm_db_iface_add_loopback);

#ifdef ECM_INTERFACE_SIT_ENABLE
/*
 * ecm_db_iface_sit_daddr_is_null()
 *	The sit addr is null or not
 */
bool ecm_db_iface_sit_daddr_is_null(struct ecm_db_iface_instance *ii)
{
	return ii->type_info.sit.daddr[0] == 0;
}
EXPORT_SYMBOL(ecm_db_iface_sit_daddr_is_null);

/*
 * ecm_db_iface_add_sit()
 *	Add a iface instance into the database
 */
void ecm_db_iface_add_sit(struct ecm_db_iface_instance *ii, struct ecm_db_interface_info_sit *type_info, char *name, int32_t mtu,
					int32_t interface_identifier, int32_t ae_interface_identifier,
					ecm_db_iface_final_callback_t final, void *arg)
{
	ecm_db_iface_hash_t hash_index;
	ecm_db_iface_id_hash_t iface_id_hash_index;
	struct ecm_db_listener_instance *li;

	spin_lock_bh(&ecm_db_lock);
	DEBUG_CHECK_MAGIC(ii, ECM_DB_IFACE_INSTANCE_MAGIC, "%p: magic failed\n", ii);
#ifdef ECM_DB_XREF_ENABLE
	DEBUG_ASSERT((ii->nodes == NULL) && (ii->node_count == 0), "%p: nodes not null\n", ii);
#endif
	DEBUG_ASSERT(!(ii->flags & ECM_DB_IFACE_FLAGS_INSERTED), "%p: inserted\n", ii);
	DEBUG_ASSERT(name, "%p: no name given\n", ii);
	spin_unlock_bh(&ecm_db_lock);

	/*
	 * Record general info
	 */
	ii->type = ECM_DB_IFACE_TYPE_SIT;
#ifdef ECM_STATE_OUTPUT_ENABLE
	ii->state_get = ecm_db_iface_sit_state_get;
#endif
	ii->arg = arg;
	ii->final = final;
	strcpy(ii->name, name);
	ii->mtu = mtu;
	ii->interface_identifier = interface_identifier;
	ii->ae_interface_identifier = ae_interface_identifier;

	/*
	 * Type specific info to be copied
	 */
	ii->type_info.sit = *type_info;

	/*
	 * Compute hash chain for insertion
	 */
	hash_index = ecm_db_iface_generate_hash_index_sit(type_info->saddr, type_info->daddr);
	ii->hash_index = hash_index;

	iface_id_hash_index = ecm_db_iface_id_generate_hash_index(interface_identifier);
	ii->iface_id_hash_index = iface_id_hash_index;

	/*
	 * Add into the global list
	 */
	spin_lock_bh(&ecm_db_lock);
	ii->flags |= ECM_DB_IFACE_FLAGS_INSERTED;
	ii->prev = NULL;
	ii->next = ecm_db_interfaces;
	if (ecm_db_interfaces) {
		ecm_db_interfaces->prev = ii;
	}
	ecm_db_interfaces = ii;

	/*
	 * Insert into chain
	 */
	ii->hash_next = ecm_db_iface_table[hash_index];
	if (ecm_db_iface_table[hash_index]) {
		ecm_db_iface_table[hash_index]->hash_prev = ii;
	}
	ecm_db_iface_table[hash_index] = ii;
	ecm_db_iface_table_lengths[hash_index]++;
	DEBUG_ASSERT(ecm_db_iface_table_lengths[hash_index] > 0, "%p: invalid table len %d\n", ii, ecm_db_iface_table_lengths[hash_index]);

	DEBUG_INFO("%p: interface inserted at hash index %u, hash prev is %p, type: %d\n", ii, ii->hash_index, ii->hash_prev, ii->type);

	/*
	 * Insert into interface identifier chain
	 */
	ii->iface_id_hash_next = ecm_db_iface_id_table[iface_id_hash_index];
	if (ecm_db_iface_id_table[iface_id_hash_index]) {
		ecm_db_iface_id_table[iface_id_hash_index]->iface_id_hash_prev = ii;
	}
	ecm_db_iface_id_table[iface_id_hash_index] = ii;
	ecm_db_iface_id_table_lengths[iface_id_hash_index]++;
	DEBUG_ASSERT(ecm_db_iface_id_table_lengths[iface_id_hash_index] > 0, "%p: invalid iface id table len %d\n", ii, ecm_db_iface_id_table_lengths[iface_id_hash_index]);

	/*
	 * Set time of addition
	 */
	ii->time_added = ecm_db_time;
	spin_unlock_bh(&ecm_db_lock);

	/*
	 * Throw add event to the listeners
 	 */
	DEBUG_TRACE("%p: Throw iface added event\n", ii);
	li = ecm_db_listeners_get_and_ref_first();
	while (li) {
		struct ecm_db_listener_instance *lin;
		if (li->iface_added) {
			li->iface_added(li->arg, ii);
		}

		/*
		 * Get next listener
		 */
		lin = ecm_db_listener_get_and_ref_next(li);
		ecm_db_listener_deref(li);
		li = lin;
	}
}
EXPORT_SYMBOL(ecm_db_iface_add_sit);
#endif

#ifdef ECM_INTERFACE_TUNIPIP6_ENABLE
#ifdef ECM_IPV6_ENABLE
/*
 * ecm_db_iface_add_tunipip6()
 *	Add a iface instance into the database
 */
void ecm_db_iface_add_tunipip6(struct ecm_db_iface_instance *ii, struct ecm_db_interface_info_tunipip6 *type_info, char *name, int32_t mtu,
					int32_t interface_identifier, int32_t ae_interface_identifier,
					ecm_db_iface_final_callback_t final, void *arg)
{
	ecm_db_iface_hash_t hash_index;
	ecm_db_iface_id_hash_t iface_id_hash_index;
	struct ecm_db_listener_instance *li;

	spin_lock_bh(&ecm_db_lock);
	DEBUG_CHECK_MAGIC(ii, ECM_DB_IFACE_INSTANCE_MAGIC, "%p: magic failed\n", ii);
#ifdef ECM_DB_XREF_ENABLE
	DEBUG_ASSERT((ii->nodes == NULL) && (ii->node_count == 0), "%p: nodes not null\n", ii);
#endif
	DEBUG_ASSERT(!(ii->flags & ECM_DB_IFACE_FLAGS_INSERTED), "%p: inserted\n", ii);
	DEBUG_ASSERT(name, "%p: no name given\n", ii);
	spin_unlock_bh(&ecm_db_lock);

	/*
	 * Record general info
	 */
	ii->type = ECM_DB_IFACE_TYPE_TUNIPIP6;
#ifdef ECM_STATE_OUTPUT_ENABLE
	ii->state_get = ecm_db_iface_tunipip6_state_get;
#endif
	ii->arg = arg;
	ii->final = final;
	strcpy(ii->name, name);
	ii->mtu = mtu;
	ii->interface_identifier = interface_identifier;
	ii->ae_interface_identifier = ae_interface_identifier;

	/*
	 * Type specific info to be copied
	 */
	ii->type_info.tunipip6 = *type_info;

	/*
	 * Compute hash chain for insertion
	 */
	hash_index = ecm_db_iface_generate_hash_index_tunipip6(type_info->saddr, type_info->daddr);
	ii->hash_index = hash_index;

	iface_id_hash_index = ecm_db_iface_id_generate_hash_index(interface_identifier);
	ii->iface_id_hash_index = iface_id_hash_index;

	/*
	 * Add into the global list
	 */
	spin_lock_bh(&ecm_db_lock);
	ii->flags |= ECM_DB_IFACE_FLAGS_INSERTED;
	ii->prev = NULL;
	ii->next = ecm_db_interfaces;
	if (ecm_db_interfaces) {
		ecm_db_interfaces->prev = ii;
	}
	ecm_db_interfaces = ii;

	/*
	 * Insert into chain
	 */
	ii->hash_next = ecm_db_iface_table[hash_index];
	if (ecm_db_iface_table[hash_index]) {
		ecm_db_iface_table[hash_index]->hash_prev = ii;
	}
	ecm_db_iface_table[hash_index] = ii;
	ecm_db_iface_table_lengths[hash_index]++;
	DEBUG_ASSERT(ecm_db_iface_table_lengths[hash_index] > 0, "%p: invalid table len %d\n", ii, ecm_db_iface_table_lengths[hash_index]);

	DEBUG_INFO("%p: interface inserted at hash index %u, hash prev is %p, type: %d\n", ii, ii->hash_index, ii->hash_prev, ii->type);

	/*
	 * Insert into interface identifier chain
	 */
	ii->iface_id_hash_next = ecm_db_iface_id_table[iface_id_hash_index];
	if (ecm_db_iface_id_table[iface_id_hash_index]) {
		ecm_db_iface_id_table[iface_id_hash_index]->iface_id_hash_prev = ii;
	}
	ecm_db_iface_id_table[iface_id_hash_index] = ii;
	ecm_db_iface_id_table_lengths[iface_id_hash_index]++;
	DEBUG_ASSERT(ecm_db_iface_id_table_lengths[iface_id_hash_index] > 0, "%p: invalid iface id table len %d\n", ii, ecm_db_iface_id_table_lengths[iface_id_hash_index]);

	/*
	 * Set time of addition
	 */
	ii->time_added = ecm_db_time;
	spin_unlock_bh(&ecm_db_lock);

	/*
	 * Throw add event to the listeners
 	 */
	DEBUG_TRACE("%p: Throw iface added event\n", ii);
	li = ecm_db_listeners_get_and_ref_first();
	while (li) {
		struct ecm_db_listener_instance *lin;
		if (li->iface_added) {
			li->iface_added(li->arg, ii);
		}

		/*
		 * Get next listener
		 */
		lin = ecm_db_listener_get_and_ref_next(li);
		ecm_db_listener_deref(li);
		li = lin;
	}
}
EXPORT_SYMBOL(ecm_db_iface_add_tunipip6);
#endif
#endif

#ifdef ECM_INTERFACE_IPSEC_ENABLE
/*
 * ecm_db_iface_add_ipsec_tunnel()
 *	Add a iface instance into the database
 *
 * GGG TODO This needs to take ipsec tunnel endpoint information etc. something very appropriate for ipsec tunnels, anyhow.
 */
void ecm_db_iface_add_ipsec_tunnel(struct ecm_db_iface_instance *ii, uint32_t os_specific_ident, char *name, int32_t mtu,
					int32_t interface_identifier, int32_t ae_interface_identifier,
					ecm_db_iface_final_callback_t final, void *arg)
{
	ecm_db_iface_hash_t hash_index;
	ecm_db_iface_id_hash_t iface_id_hash_index;
	struct ecm_db_listener_instance *li;
	struct ecm_db_interface_info_ipsec_tunnel *type_info;

	spin_lock_bh(&ecm_db_lock);
	DEBUG_CHECK_MAGIC(ii, ECM_DB_IFACE_INSTANCE_MAGIC, "%p: magic failed\n", ii);
#ifdef ECM_DB_XREF_ENABLE
	DEBUG_ASSERT((ii->nodes == NULL) && (ii->node_count == 0), "%p: nodes not null\n", ii);
#endif
	DEBUG_ASSERT(!(ii->flags & ECM_DB_IFACE_FLAGS_INSERTED), "%p: inserted\n", ii);
	DEBUG_ASSERT(name, "%p: no name given\n", ii);
	spin_unlock_bh(&ecm_db_lock);

	/*
	 * Record general info
	 */
	ii->type = ECM_DB_IFACE_TYPE_IPSEC_TUNNEL;
#ifdef ECM_STATE_OUTPUT_ENABLE
	ii->state_get = ecm_db_iface_ipsec_tunnel_state_get;
#endif
	ii->arg = arg;
	ii->final = final;
	strcpy(ii->name, name);
	ii->mtu = mtu;
	ii->interface_identifier = interface_identifier;
	ii->ae_interface_identifier = ae_interface_identifier;

	/*
	 * Type specific info
	 */
	type_info = &ii->type_info.ipsec_tunnel;
	type_info->os_specific_ident = os_specific_ident;

	/*
	 * Compute hash chain for insertion
	 */
	hash_index = ecm_db_iface_generate_hash_index_ipsec_tunnel(os_specific_ident);
	ii->hash_index = hash_index;

	iface_id_hash_index = ecm_db_iface_id_generate_hash_index(interface_identifier);
	ii->iface_id_hash_index = iface_id_hash_index;

	/*
	 * Add into the global list
	 */
	spin_lock_bh(&ecm_db_lock);
	ii->flags |= ECM_DB_IFACE_FLAGS_INSERTED;
	ii->prev = NULL;
	ii->next = ecm_db_interfaces;
	if (ecm_db_interfaces) {
		ecm_db_interfaces->prev = ii;
	}
	ecm_db_interfaces = ii;

	/*
	 * Insert into chain
	 */
	ii->hash_next = ecm_db_iface_table[hash_index];
	if (ecm_db_iface_table[hash_index]) {
		ecm_db_iface_table[hash_index]->hash_prev = ii;
	}
	ecm_db_iface_table[hash_index] = ii;
	ecm_db_iface_table_lengths[hash_index]++;
	DEBUG_ASSERT(ecm_db_iface_table_lengths[hash_index] > 0, "%p: invalid table len %d\n", ii, ecm_db_iface_table_lengths[hash_index]);

	DEBUG_INFO("%p: interface inserted at hash index %u, hash prev is %p, type: %d\n", ii, ii->hash_index, ii->hash_prev, ii->type);

	/*
	 * Insert into interface identifier chain
	 */
	ii->iface_id_hash_next = ecm_db_iface_id_table[iface_id_hash_index];
	if (ecm_db_iface_id_table[iface_id_hash_index]) {
		ecm_db_iface_id_table[iface_id_hash_index]->iface_id_hash_prev = ii;
	}
	ecm_db_iface_id_table[iface_id_hash_index] = ii;
	ecm_db_iface_id_table_lengths[iface_id_hash_index]++;
	DEBUG_ASSERT(ecm_db_iface_id_table_lengths[iface_id_hash_index] > 0, "%p: invalid iface id table len %d\n", ii, ecm_db_iface_id_table_lengths[iface_id_hash_index]);

	/*
	 * Set time of addition
	 */
	ii->time_added = ecm_db_time;
	spin_unlock_bh(&ecm_db_lock);

	/*
	 * Throw add event to the listeners
 	 */
	DEBUG_TRACE("%p: Throw iface added event\n", ii);
	li = ecm_db_listeners_get_and_ref_first();
	while (li) {
		struct ecm_db_listener_instance *lin;
		if (li->iface_added) {
			li->iface_added(li->arg, ii);
		}

		/*
		 * Get next listener
		 */
		lin = ecm_db_listener_get_and_ref_next(li);
		ecm_db_listener_deref(li);
		li = lin;
	}
}
EXPORT_SYMBOL(ecm_db_iface_add_ipsec_tunnel);
#endif

/*
 * ecm_db_listener_add()
 *	Add a listener instance into the database.
 */
void ecm_db_listener_add(struct ecm_db_listener_instance *li,
							ecm_db_iface_listener_added_callback_t iface_added,
							ecm_db_iface_listener_removed_callback_t iface_removed,
							ecm_db_node_listener_added_callback_t node_added,
							ecm_db_node_listener_removed_callback_t node_removed,
							ecm_db_host_listener_added_callback_t host_added,
							ecm_db_host_listener_removed_callback_t host_removed,
							ecm_db_mapping_listener_added_callback_t mapping_added,
							ecm_db_mapping_listener_removed_callback_t mapping_removed,
							ecm_db_connection_listener_added_callback_t connection_added,
							ecm_db_connection_listener_removed_callback_t connection_removed,
							ecm_db_listener_final_callback_t final,
							void *arg)
{
	spin_lock_bh(&ecm_db_lock);
	DEBUG_CHECK_MAGIC(li, ECM_DB_LISTENER_INSTANCE_MAGIC, "%p: magic failed\n", li);
	DEBUG_ASSERT(!(li->flags & ECM_DB_LISTENER_FLAGS_INSERTED), "%p: inserted\n", li);
	spin_unlock_bh(&ecm_db_lock);

	li->arg = arg;
	li->final = final;
	li->iface_added = iface_added;
	li->iface_removed = iface_removed;
	li->node_added = node_added;
	li->node_removed = node_removed;
	li->host_added = host_added;
	li->host_removed = host_removed;
	li->mapping_added = mapping_added;
	li->mapping_removed = mapping_removed;
	li->connection_added = connection_added;
	li->connection_removed = connection_removed;

	/*
	 * Add instance into listener list
	 */
	spin_lock_bh(&ecm_db_lock);
	li->flags |= ECM_DB_LISTENER_FLAGS_INSERTED;
	li->next = ecm_db_listeners;
	ecm_db_listeners = li;
	spin_unlock_bh(&ecm_db_lock);
}
EXPORT_SYMBOL(ecm_db_listener_add);

/*
 * ecm_db_connection_alloc()
 *	Allocate a connection instance
 */
struct ecm_db_connection_instance *ecm_db_connection_alloc(void)
{
	struct ecm_db_connection_instance *ci;
	int __attribute__((unused)) i;
	unsigned int conn_count;

	/*
	 * If we have exceeded the conntrack connection limit then do not allocate new instance.
	 */
	conn_count = (unsigned int)ecm_db_connection_count_get();
	if (conn_count >= nf_conntrack_max) {
		DEBUG_WARN("ECM Connection count limit reached: db: %u, ct: %u\n", conn_count, nf_conntrack_max);
		return NULL;
	}

	/*
	 * Allocate the connection
	 */
	ci = (struct ecm_db_connection_instance *)kzalloc(sizeof(struct ecm_db_connection_instance), GFP_ATOMIC | __GFP_NOWARN);
	if (!ci) {
		DEBUG_WARN("Connection alloc failed\n");
		return NULL;
	}

	/*
	 * Initialise the defunct timer entry
	 */
	ecm_db_timer_group_entry_init(&ci->defunct_timer, ecm_db_connection_defunct_callback, ci);

	/*
	 * Refs is 1 for the creator of the connection
	 */
	ci->refs = 1;
	DEBUG_SET_MAGIC(ci, ECM_DB_CONNECTION_INSTANCE_MAGIC);

	/*
	 * Initialise the interfaces from/to lists.
	 * Interfaces are added from end of array.
	 */
	ci->from_interface_first = ECM_DB_IFACE_HEIRARCHY_MAX;
	ci->to_interface_first = ECM_DB_IFACE_HEIRARCHY_MAX;
	ci->from_nat_interface_first = ECM_DB_IFACE_HEIRARCHY_MAX;
	ci->to_nat_interface_first = ECM_DB_IFACE_HEIRARCHY_MAX;

#ifdef ECM_MULTICAST_ENABLE
	for (i = 0; i < ECM_DB_MULTICAST_IF_MAX; ++i) {
		ci->to_mcast_interface_first[i] = ECM_DB_IFACE_HEIRARCHY_MAX;
	}
#endif
	/*
	 * If the master thread is terminating then we cannot create new instances
	 */
	spin_lock_bh(&ecm_db_lock);
	if (ecm_db_terminate_pending) {
		spin_unlock_bh(&ecm_db_lock);
		DEBUG_WARN("Thread terminating\n");
		kfree(ci);
		return NULL;
	}

	/*
	 * Assign runtime unique serial
	 */
	ci->serial = ecm_db_connection_serial++;

	ecm_db_connection_count++;
	DEBUG_ASSERT(ecm_db_connection_count > 0, "%p: connection count wrap\n", ci);
	spin_unlock_bh(&ecm_db_lock);

	DEBUG_TRACE("Connection created %p\n", ci);
	return ci;
}
EXPORT_SYMBOL(ecm_db_connection_alloc);

/*
 * ecm_db_mapping_alloc()
 *	Allocate a mapping instance
 */
struct ecm_db_mapping_instance *ecm_db_mapping_alloc(void)
{
	struct ecm_db_mapping_instance *mi;

	mi = (struct ecm_db_mapping_instance *)kzalloc(sizeof(struct ecm_db_mapping_instance), GFP_ATOMIC | __GFP_NOWARN);
	if (!mi) {
		DEBUG_WARN("Alloc failed\n");
		return NULL;
	}

	mi->refs = 1;
	DEBUG_SET_MAGIC(mi, ECM_DB_MAPPING_INSTANCE_MAGIC);

	/*
	 * Alloc operation must be atomic to ensure thread and module can be held
	 */
	spin_lock_bh(&ecm_db_lock);

	/*
	 * If the event processing thread is terminating then we cannot create new instances
	 */
	if (ecm_db_terminate_pending) {
		spin_unlock_bh(&ecm_db_lock);
		DEBUG_WARN("Thread terminating\n");
		kfree(mi);
		return NULL;
	}

	ecm_db_mapping_count++;
	spin_unlock_bh(&ecm_db_lock);

	DEBUG_TRACE("Mapping created %p\n", mi);
	return mi;
}
EXPORT_SYMBOL(ecm_db_mapping_alloc);

/*
 * ecm_db_host_alloc()
 *	Allocate a host instance
 */
struct ecm_db_host_instance *ecm_db_host_alloc(void)
{
	struct ecm_db_host_instance *hi;
	hi = (struct ecm_db_host_instance *)kzalloc(sizeof(struct ecm_db_host_instance), GFP_ATOMIC | __GFP_NOWARN);
	if (!hi) {
		DEBUG_WARN("Alloc failed\n");
		return NULL;
	}

	hi->refs = 1;
	DEBUG_SET_MAGIC(hi, ECM_DB_HOST_INSTANCE_MAGIC);

	/*
	 * Alloc operation must be atomic to ensure thread and module can be held
	 */
	spin_lock_bh(&ecm_db_lock);

	/*
	 * If the event processing thread is terminating then we cannot create new instances
	 */
	if (ecm_db_terminate_pending) {
		spin_unlock_bh(&ecm_db_lock);
		DEBUG_WARN("Thread terminating\n");
		kfree(hi);
		return NULL;
	}

	ecm_db_host_count++;
	spin_unlock_bh(&ecm_db_lock);

	DEBUG_TRACE("Host created %p\n", hi);
	return hi;
}
EXPORT_SYMBOL(ecm_db_host_alloc);

/*
 * ecm_db_node_alloc()
 *	Allocate a node instance
 */
struct ecm_db_node_instance *ecm_db_node_alloc(void)
{
	struct ecm_db_node_instance *ni;

	ni = (struct ecm_db_node_instance *)kzalloc(sizeof(struct ecm_db_node_instance), GFP_ATOMIC | __GFP_NOWARN);
	if (!ni) {
		DEBUG_WARN("Alloc failed\n");
		return NULL;
	}

	ni->refs = 1;
	DEBUG_SET_MAGIC(ni, ECM_DB_NODE_INSTANCE_MAGIC);

	/*
	 * Alloc operation must be atomic to ensure thread and module can be held
	 */
	spin_lock_bh(&ecm_db_lock);

	/*
	 * If the event processing thread is terminating then we cannot create new instances
	 */
	if (ecm_db_terminate_pending) {
		spin_unlock_bh(&ecm_db_lock);
		DEBUG_WARN("Thread terminating\n");
		kfree(ni);
		return NULL;
	}

	ecm_db_node_count++;
	spin_unlock_bh(&ecm_db_lock);

	DEBUG_TRACE("Node created %p\n", ni);
	return ni;
}
EXPORT_SYMBOL(ecm_db_node_alloc);

/*
 * ecm_db_iface_alloc()
 *	Allocate a iface instance
 */
struct ecm_db_iface_instance *ecm_db_iface_alloc(void)
{
	struct ecm_db_iface_instance *ii;

	ii = (struct ecm_db_iface_instance *)kzalloc(sizeof(struct ecm_db_iface_instance), GFP_ATOMIC | __GFP_NOWARN);
	if (!ii) {
		DEBUG_WARN("Alloc failed\n");
		return NULL;
	}

	ii->refs = 1;
	DEBUG_SET_MAGIC(ii, ECM_DB_IFACE_INSTANCE_MAGIC);

	/*
	 * Alloc operation must be atomic to ensure thread and module can be held
	 */
	spin_lock_bh(&ecm_db_lock);

	/*
	 * If the event processing thread is terminating then we cannot create new instances
	 */
	if (ecm_db_terminate_pending) {
		spin_unlock_bh(&ecm_db_lock);
		DEBUG_WARN("Thread terminating\n");
		kfree(ii);
		return NULL;
	}

	ecm_db_iface_count++;
	spin_unlock_bh(&ecm_db_lock);

	DEBUG_TRACE("iface created %p\n", ii);
	return ii;
}
EXPORT_SYMBOL(ecm_db_iface_alloc);

/*
 * ecm_db_listener_alloc()
 *	Allocate a listener instance
 */
struct ecm_db_listener_instance *ecm_db_listener_alloc(void)
{
	struct ecm_db_listener_instance *li;

	li = (struct ecm_db_listener_instance *)kzalloc(sizeof(struct ecm_db_listener_instance), GFP_ATOMIC | __GFP_NOWARN);
	if (!li) {
		DEBUG_WARN("Alloc failed\n");
		return NULL;
	}

	li->refs = 1;
	DEBUG_SET_MAGIC(li, ECM_DB_LISTENER_INSTANCE_MAGIC);

	/*
	 * Alloc operation must be atomic to ensure thread and module can be held
	 */
	spin_lock_bh(&ecm_db_lock);

	/*
	 * If the event processing thread is terminating then we cannot create new instances
	 */
	if (ecm_db_terminate_pending) {
		spin_unlock_bh(&ecm_db_lock);
		DEBUG_WARN("Thread terminating\n");
		kfree(li);
		return NULL;
	}

	ecm_db_listeners_count++;
	DEBUG_ASSERT(ecm_db_listeners_count > 0, "%p: listener count wrap\n", li);
	spin_unlock_bh(&ecm_db_lock);

	DEBUG_TRACE("Listener created %p\n", li);
	return li;
}
EXPORT_SYMBOL(ecm_db_listener_alloc);

#ifdef ECM_MULTICAST_ENABLE
/*
 *  _ecm_db_multicast_tuple_instance_ref()
 * 	Increment tuple reference count by one
 */
static void _ecm_db_multicast_tuple_instance_ref(struct ecm_db_multicast_tuple_instance *ti)
{
	DEBUG_CHECK_MAGIC(ti, ECM_DB_MULTICAST_INSTANCE_MAGIC, "%p: magic failed", ti);
	ti->refs++;
	DEBUG_TRACE("%p: ti ref %d\n", ti, ti->refs);
	DEBUG_ASSERT(ti->refs > 0, "%p: ref wrap\n", ti)
}

/*
 * ecm_db_multicast_alloc_connection()
 * 	Allocate memory for the connection structure.
 */
struct ecm_db_multicast_tuple_instance *ecm_db_multicast_tuple_instance_alloc(ip_addr_t origin, ip_addr_t group, uint16_t src_port, uint16_t dst_port)
{
	struct ecm_db_multicast_tuple_instance *ti;
	ti = (struct ecm_db_multicast_tuple_instance *)kzalloc(sizeof(struct ecm_db_multicast_tuple_instance), GFP_ATOMIC | __GFP_NOWARN);
	if (!ti) {
		DEBUG_WARN("ti: Alloc failed\n");
		return NULL;
	}
	ti->src_port = src_port;
	ti->dst_port = dst_port;
	ECM_IP_ADDR_COPY(ti->src_ip, origin);
	ECM_IP_ADDR_COPY(ti->grp_ip, group);
	ti->proto = IPPROTO_UDP;
	ti->hash_index = ecm_db_multicast_generate_hash_index(group);
	ti->flags = 0;
	ti->refs = 1;
	ti->next = NULL;
	ti->prev = NULL;
	DEBUG_SET_MAGIC(ti, ECM_DB_MULTICAST_INSTANCE_MAGIC);

	return ti;
}
EXPORT_SYMBOL(ecm_db_multicast_tuple_instance_alloc);

/*
 * ecm_db_multicast_connection_find_and_ref()
 * 	Called by MFC event update to fetch connection from the table
 * 	This function takes a ref count for both tuple_instance and 'ci'
 *	Call ecm_db_multicast_connection_deref function for deref both
 *	'ti' and 'ci'
 */
struct ecm_db_multicast_tuple_instance *ecm_db_multicast_connection_find_and_ref(ip_addr_t origin, ip_addr_t group)
{
	ecm_db_multicast_tuple_instance_hash_t hash_index;
	struct ecm_db_multicast_tuple_instance *ti;

	/*
	 * Compute the hash chain index
	 */
	hash_index = ecm_db_multicast_generate_hash_index(group);

	spin_lock_bh(&ecm_db_lock);
	ti = ecm_db_multicast_tuple_instance_table[hash_index];

	/*
	 * Traverse through the list and find the ti
	 */
	while (ti) {
		if (!(ECM_IP_ADDR_MATCH(ti->src_ip, origin) && ECM_IP_ADDR_MATCH(ti->grp_ip, group))) {
			ti = ti->next;
			continue;
		}

		_ecm_db_multicast_tuple_instance_ref(ti);
		_ecm_db_connection_ref(ti->ci);
		spin_unlock_bh(&ecm_db_lock);
		DEBUG_TRACE("multicast tuple instance found %p\n", ti);
		return ti;
	}

	spin_unlock_bh(&ecm_db_lock);
	DEBUG_TRACE("multicast tuple instance not found\n");
	return NULL;
}
EXPORT_SYMBOL(ecm_db_multicast_connection_find_and_ref);

/*
 * ecm_db_multicast_tuple_instance_deref()
 * 	Deref the reference count or
 * 	Free the tuple_instance struct, when the multicast connection dies
 */
int ecm_db_multicast_tuple_instance_deref(struct ecm_db_multicast_tuple_instance *ti)
{
	int refs;
	spin_lock_bh(&ecm_db_lock);
	refs = _ecm_db_multicast_tuple_instance_deref(ti);
	spin_unlock_bh(&ecm_db_lock);
	return refs;
}
EXPORT_SYMBOL(ecm_db_multicast_tuple_instance_deref);

/*
 * ecm_db_multicast_connection_deref()
 * 	Deref both 'ti' and 'ci'
 * 	call this function after ecm_db_multicast_connection_find_and_ref()
 */
void ecm_db_multicast_connection_deref(struct ecm_db_multicast_tuple_instance *ti)
{
	struct ecm_db_connection_instance *ci;
	DEBUG_CHECK_MAGIC(ti, ECM_DB_MULTICAST_INSTANCE_MAGIC, "%p: magic failed", ti);

	ci = ti->ci;
	ecm_db_multicast_tuple_instance_deref(ti);
	ecm_db_connection_deref(ci);

}
EXPORT_SYMBOL(ecm_db_multicast_connection_deref);

/*
 * ecm_db_multicast_tuple_instance_add()
 * 	Add the tuple instance into the hash table. Also, attach the tuple instance
 * 	with connection instance.
 *
 * 	Note: This function takes a reference count and caller has to also call
 * 	ecm_db_multicast_tuple_instance_deref() after this function.
 */
void ecm_db_multicast_tuple_instance_add(struct ecm_db_multicast_tuple_instance *ti, struct ecm_db_connection_instance *ci)
{
	DEBUG_CHECK_MAGIC(ti, ECM_DB_MULTICAST_INSTANCE_MAGIC, "%p: magic failed", ti);

	spin_lock_bh(&ecm_db_lock);
	DEBUG_ASSERT(!(ti->flags & ECM_DB_MULTICAST_TUPLE_INSTANCE_FLAGS_INSERTED), "%p: inserted\n", ti);

	/*
	 * Attach the multicast tuple instance with the connection instance
	 */
	ci->ti = ti;
	ti->ci = ci;

	/*
	 * Take a local reference to ti
	 */
	_ecm_db_multicast_tuple_instance_ref(ti);
	ti->next = ecm_db_multicast_tuple_instance_table[ti->hash_index];
	if (ecm_db_multicast_tuple_instance_table[ti->hash_index]) {
		ecm_db_multicast_tuple_instance_table[ti->hash_index]->prev = ti;
	}

	ecm_db_multicast_tuple_instance_table[ti->hash_index] = ti;

	ti->flags |= ECM_DB_MULTICAST_TUPLE_INSTANCE_FLAGS_INSERTED;
	spin_unlock_bh(&ecm_db_lock);

}
EXPORT_SYMBOL(ecm_db_multicast_tuple_instance_add);

/*
 * ecm_db_multicast_connection_get_and_ref_first()
 * 	Return the first tuple instance from the table when given a group
 * 	Also take a ref count for 'ci', once done call ecm_db_multicast_connection_deref()
 * 	to deref both 'ti' and 'ci'
 */
struct ecm_db_multicast_tuple_instance *ecm_db_multicast_connection_get_and_ref_first(ip_addr_t group)
{
	ecm_db_multicast_tuple_instance_hash_t hash_index;
	struct ecm_db_multicast_tuple_instance *ti;

	hash_index = ecm_db_multicast_generate_hash_index(group);

	spin_lock_bh(&ecm_db_lock);
	ti = ecm_db_multicast_tuple_instance_table[hash_index];
	if (ti) {
		_ecm_db_multicast_tuple_instance_ref(ti);
		_ecm_db_connection_ref(ti->ci);
	}
	spin_unlock_bh(&ecm_db_lock);

	return ti;
}
EXPORT_SYMBOL(ecm_db_multicast_connection_get_and_ref_first);

/*
 * ecm_db_multicast_connection_get_and_ref_next()
 * 	Return the next tuple instance node and
 * 	take a ref count for 'ci', once done call ecm_db_multicast_connection_deref()
 * 	to deref both 'ti' and 'ci'
 */
struct ecm_db_multicast_tuple_instance *ecm_db_multicast_connection_get_and_ref_next(struct ecm_db_multicast_tuple_instance *ti)
{
	struct ecm_db_multicast_tuple_instance *tin;
	DEBUG_CHECK_MAGIC(ti, ECM_DB_MULTICAST_INSTANCE_MAGIC, "%p: magic failed", ti);
	spin_lock_bh(&ecm_db_lock);
	tin = ti->next;
	if (tin) {
		_ecm_db_multicast_tuple_instance_ref(tin);
		_ecm_db_connection_ref(tin->ci);
	}
	spin_unlock_bh(&ecm_db_lock);
	return tin;
}
EXPORT_SYMBOL(ecm_db_multicast_connection_get_and_ref_next);

/*
 * ecm_db_multicast_tuple_instance_source_ip_get()
 * 	This function return the source IP for a connection object
 */
void ecm_db_multicast_tuple_instance_source_ip_get(struct ecm_db_multicast_tuple_instance *ti, ip_addr_t origin)
{
	DEBUG_CHECK_MAGIC(ti, ECM_DB_MULTICAST_INSTANCE_MAGIC, "%p: magic failed", ti);
	ECM_IP_ADDR_COPY(origin, ti->src_ip);
}
EXPORT_SYMBOL(ecm_db_multicast_tuple_instance_source_ip_get);

/*
 * ecm_db_multicast_tuple_instance_group_ip_get()
 * 	This function return the group IP for a connection object
 */
void ecm_db_multicast_tuple_instance_group_ip_get(struct ecm_db_multicast_tuple_instance *ti, ip_addr_t group)
{
	DEBUG_CHECK_MAGIC(ti, ECM_DB_MULTICAST_INSTANCE_MAGIC, "%p: magic failed", ti);
	ECM_IP_ADDR_COPY(group, ti->grp_ip);
}
EXPORT_SYMBOL(ecm_db_multicast_tuple_instance_group_ip_get);

/*
 * ecm_db_multicast_tuple_instance_flags_get()
 * 	Return flags related to Multicast connection
 */
uint32_t ecm_db_multicast_tuple_instance_flags_get(struct ecm_db_multicast_tuple_instance *ti)
{
	uint32_t flags;

	DEBUG_CHECK_MAGIC(ti, ECM_DB_MULTICAST_INSTANCE_MAGIC, "%p: magic failed\n", ti);
	spin_lock_bh(&ecm_db_lock);
	flags = ti->flags;
	spin_unlock_bh(&ecm_db_lock);
	return flags;
}
EXPORT_SYMBOL(ecm_db_multicast_tuple_instance_flags_get);

/*
 * ecm_db_multicast_tuple_instance_flags_set()
 * 	Set the multicast connection flags
 */
void ecm_db_multicast_tuple_instance_flags_set(struct ecm_db_multicast_tuple_instance *ti, uint32_t flags)
{
	DEBUG_CHECK_MAGIC(ti, ECM_DB_MULTICAST_INSTANCE_MAGIC, "%p: magic failed\n", ti);

	spin_lock_bh(&ecm_db_lock);
	ti->flags |= flags;
	spin_unlock_bh(&ecm_db_lock);
}
EXPORT_SYMBOL(ecm_db_multicast_tuple_instance_flags_set);

/*
 * ecm_db_multicast_tuple_instance_flags_clear()
 * 	Clear the multicast connection flags
 */
void ecm_db_multicast_tuple_instance_flags_clear(struct ecm_db_multicast_tuple_instance *ti, uint32_t flags)
{
	DEBUG_CHECK_MAGIC(ti, ECM_DB_MULTICAST_INSTANCE_MAGIC, "%p: magic failed\n", ti);

	spin_lock_bh(&ecm_db_lock);
	ti->flags &= ~flags;
	spin_unlock_bh(&ecm_db_lock);
}
EXPORT_SYMBOL(ecm_db_multicast_tuple_instance_flags_clear);

/*
 * ecm_db_multicast_connection_to_interfaces_get_and_ref_all()
 *	Return the list of multicast destination interface heirarchies to which this connection is established.
 *	The function returns the heirarchies using the 'interface' pointer passed to it. It also returns the first
 *	index in the interface heirarchy for each of the heirarchies using the 'ifaces_first' pointer.
 *
 * NOTE: This function allocates the memory for the destination interface heirachy. This memory is expected to be
 * freed only by making a call to ecm_db_multicast_connection_interfaces_deref_all().
 *
 * The size of the buffer allocated for the heirarchies and pointed to by 'interfaces' is as large as
 * sizeof(struct ecm_db_iface_instance *) * ECM_DB_MULTICAST_IF_MAX * ECM_DB_IFACE_HEIRARCHY_MAX.
 * Returns the number of interface heirarchies in the list as a return value.
 *
 * Each interface is referenced on return, be sure to release them using ecm_db_multicast_connection_interfaces_deref_all().
 */
int32_t ecm_db_multicast_connection_to_interfaces_get_and_ref_all(struct ecm_db_connection_instance *ci,
						struct ecm_db_iface_instance **interfaces, int32_t **ifaces_first)
{
	struct ecm_db_iface_instance *heirarchy_base;
	struct ecm_db_iface_instance *heirarchy_temp;
	struct ecm_db_iface_instance *ii_single;
	struct ecm_db_iface_instance **ifaces;
	struct ecm_db_iface_instance *ii_db;
	struct ecm_db_iface_instance *ii_db_single;
	struct ecm_db_iface_instance **ifaces_db;
	int32_t *ii_first_base;
	int32_t *ii_first;
	int32_t heirarchy_index;
	int32_t ii_index;
	int32_t if_count = 0;

	DEBUG_CHECK_MAGIC(ci, ECM_DB_CONNECTION_INSTANCE_MAGIC, "%p: magic failed\n", ci);

	heirarchy_base = (struct ecm_db_iface_instance *)kzalloc(ECM_DB_TO_MCAST_INTERFACES_SIZE, GFP_ATOMIC | __GFP_NOWARN);
	if (!heirarchy_base) {
		DEBUG_WARN("%p: No memory for interface hierarchies \n", ci);
		return if_count;
	}

	ii_first_base = (int32_t *)kzalloc(sizeof(int32_t *) * ECM_DB_MULTICAST_IF_MAX, GFP_ATOMIC | __GFP_NOWARN);
	if (!ii_first_base) {
		DEBUG_WARN("%p: No memory for first interface \n", ci);
		kfree(heirarchy_base);
		return if_count;
	}

	spin_lock_bh(&ecm_db_lock);
	if (!ci->to_mcast_interfaces_set) {
		spin_unlock_bh(&ecm_db_lock);
		kfree(ii_first_base);
		kfree(heirarchy_base);
		return if_count;
	}

	for (heirarchy_index = 0; heirarchy_index < ECM_DB_MULTICAST_IF_MAX; heirarchy_index++) {

		heirarchy_temp = ecm_db_multicast_if_heirarchy_get(heirarchy_base, heirarchy_index);

		if (ci->to_mcast_interface_first[heirarchy_index] < ECM_DB_IFACE_HEIRARCHY_MAX) {
			if_count++;
		}

		for (ii_index = ci->to_mcast_interface_first[heirarchy_index]; ii_index < ECM_DB_IFACE_HEIRARCHY_MAX; ++ii_index) {
			ii_db = ecm_db_multicast_if_heirarchy_get(ci->to_mcast_interfaces, heirarchy_index);
			ii_db_single = ecm_db_multicast_if_instance_get_at_index(ii_db, ii_index);
			ifaces_db = (struct ecm_db_iface_instance **)ii_db_single;

			/*
			 * Take a reference count
			 */
			_ecm_db_iface_ref(*ifaces_db);

			ii_single = ecm_db_multicast_if_instance_get_at_index(heirarchy_temp, ii_index);
			ifaces = (struct ecm_db_iface_instance **)ii_single;
			*ifaces = *ifaces_db;
		}

		ii_first = ecm_db_multicast_if_first_get_at_index(ii_first_base, heirarchy_index);
		*ii_first = ci->to_mcast_interface_first[heirarchy_index];
	}

	*interfaces = heirarchy_base;
	*ifaces_first = ii_first_base;

	spin_unlock_bh(&ecm_db_lock);
	return if_count;
}
EXPORT_SYMBOL(ecm_db_multicast_connection_to_interfaces_get_and_ref_all);

/*
 * ecm_db_multicast_connection_to_interfaces_set_check()
 *	Returns true if the multicast destination interfaces list has been set.
 */
bool ecm_db_multicast_connection_to_interfaces_set_check(struct ecm_db_connection_instance *ci)
{
	bool set;

	DEBUG_CHECK_MAGIC(ci, ECM_DB_CONNECTION_INSTANCE_MAGIC, "%p: magic failed\n", ci);
	spin_lock_bh(&ecm_db_lock);
	set = ci->to_mcast_interfaces_set;
	spin_unlock_bh(&ecm_db_lock);
	return set;
}
EXPORT_SYMBOL(ecm_db_multicast_connection_to_interfaces_set_check);

/*
 * ecm_db_multicast_connection_to_interfaces_set_clear()
 *	Clear the to_mcast_interfaces_set flag if the multicast destination interfaces list has been freed.
 */
static void  _ecm_db_multicast_connection_to_interfaces_set_clear(struct ecm_db_connection_instance *ci)
{
	DEBUG_CHECK_MAGIC(ci, ECM_DB_CONNECTION_INSTANCE_MAGIC, "%p: magic failed\n", ci);
	ci->to_mcast_interfaces_set = false;
}

/*
 * ecm_db_multicast_connection_get_from_tuple()
 * 	Return the connection instance
 */
struct ecm_db_connection_instance *ecm_db_multicast_connection_get_from_tuple(struct ecm_db_multicast_tuple_instance *ti)
{
	DEBUG_CHECK_MAGIC(ti, ECM_DB_MULTICAST_INSTANCE_MAGIC, "%p: magic failed", ti);
	DEBUG_ASSERT(ti->ci, "%p: Bad multicast connection instance \n", ti);

	return ti->ci;
}
EXPORT_SYMBOL(ecm_db_multicast_connection_get_from_tuple);

/*
 * ecm_db_multicast_connection_to_interfaces_deref_all()
 * 	Deref all destination multicast interface heirarchies at once
 */
void ecm_db_multicast_connection_to_interfaces_deref_all(struct ecm_db_iface_instance *interfaces, int32_t *ifaces_first)
{
	struct ecm_db_iface_instance *ifaces_single;
	struct ecm_db_iface_instance *ii_temp[ECM_DB_IFACE_HEIRARCHY_MAX];
	int32_t *to_first;
	int heirarchy_index;
	DEBUG_ASSERT(interfaces, "Bad memory, multicast interfaces list has been already freed\n");
	DEBUG_ASSERT(ifaces_first, "Bad memory, multicast interfaces first has been already freed\n");

	for (heirarchy_index = 0; heirarchy_index < ECM_DB_MULTICAST_IF_MAX; heirarchy_index++) {
		to_first = ecm_db_multicast_if_first_get_at_index(ifaces_first, heirarchy_index);
		if (*to_first < ECM_DB_IFACE_HEIRARCHY_MAX) {
			ifaces_single = ecm_db_multicast_if_heirarchy_get(interfaces, heirarchy_index);
			ecm_db_multicast_copy_if_heirarchy(ii_temp, ifaces_single);
			ecm_db_connection_interfaces_deref(ii_temp, *to_first);
		}
	}

	/*
	 * Free the temporary memory allocated by ecm_db_multicast_connection_to_interfaces_get_and_ref_all()
	 */
	kfree(interfaces);
	kfree(ifaces_first);

}
EXPORT_SYMBOL(ecm_db_multicast_connection_to_interfaces_deref_all);

/*
 * _ecm_db_multicast_connection_to_interface_first_is_valid()
 * 	Check if destnation interfaces first list uphold a valid interface
 * 	first or all entries have discarded.
 */
static bool _ecm_db_multicast_connection_to_interface_first_is_valid(int32_t ifaces_first[])
{
	int heirarchy_index;

	for (heirarchy_index = 0; heirarchy_index < ECM_DB_MULTICAST_IF_MAX; heirarchy_index++) {
		if (ifaces_first[heirarchy_index] < ECM_DB_IFACE_HEIRARCHY_MAX) {
			return true;
		}
	}

	return false;
}

/*
 * ecm_db_multicast_connection_to_interfaces_clear_at_index()
 * 	Dereference and clear a interface heirarchy at 'index' position
 */
void ecm_db_multicast_connection_to_interfaces_clear_at_index(struct ecm_db_connection_instance *ci, uint32_t index)
{
	struct ecm_db_iface_instance *discard[ECM_DB_IFACE_HEIRARCHY_MAX];
	struct ecm_db_iface_instance *ifaces_db_single;
	int32_t discard_first;

	DEBUG_CHECK_MAGIC(ci, ECM_DB_CONNECTION_INSTANCE_MAGIC, "%p: magic failed\n", ci);

	/*
	 * Invalid Index Value
	 */
	DEBUG_ASSERT((index < ECM_DB_MULTICAST_IF_MAX), "%p: Invalid index for multicast interface heirarchies list %u\n", ci, index);

	spin_lock_bh(&ecm_db_lock);
	if (ci->to_mcast_interface_first[index] == ECM_DB_IFACE_HEIRARCHY_MAX) {
		spin_unlock_bh(&ecm_db_lock);
		return;
	}

	ifaces_db_single = ecm_db_multicast_if_heirarchy_get(ci->to_mcast_interfaces, index);
	ecm_db_multicast_copy_if_heirarchy(discard, ifaces_db_single);

	discard_first = ci->to_mcast_interface_first[index];
	ci->to_mcast_interface_first[index] = ECM_DB_IFACE_HEIRARCHY_MAX;

	/*
	 * If this is the only valid interface hierarchy left in the list of destination
	 * interface hierarchies then clear the ci->to_mcast_interfaces_set flag here before
	 * deleting this.
	 */
	if (!_ecm_db_multicast_connection_to_interface_first_is_valid(ci->to_mcast_interface_first)) {
		ci->to_mcast_interfaces_set = false;
	}

	spin_unlock_bh(&ecm_db_lock);

	ecm_db_connection_interfaces_deref(discard, discard_first);
}
EXPORT_SYMBOL(ecm_db_multicast_connection_to_interfaces_clear_at_index);

/*
 * ecm_db_multicast_connection_to_interfaces_clear()
 * 	Deref and clear all destination multicast interface heirarchies
 */
void ecm_db_multicast_connection_to_interfaces_clear(struct ecm_db_connection_instance *ci)
{
	int heirarchy_index;
	DEBUG_CHECK_MAGIC(ci, ECM_DB_CONNECTION_INSTANCE_MAGIC, "%p: magic failed\n", ci);

	spin_lock_bh(&ecm_db_lock);
	if (!ci->to_mcast_interfaces) {
		spin_unlock_bh(&ecm_db_lock);
		return;
	}

	_ecm_db_multicast_connection_to_interfaces_set_clear(ci);
	spin_unlock_bh(&ecm_db_lock);

	for (heirarchy_index = 0; heirarchy_index < ECM_DB_MULTICAST_IF_MAX; heirarchy_index++) {
		ecm_db_multicast_connection_to_interfaces_clear_at_index(ci, heirarchy_index);
	}

	kfree(ci->to_mcast_interfaces);
	ci->to_mcast_interfaces = NULL;
}
EXPORT_SYMBOL(ecm_db_multicast_connection_to_interfaces_clear);
#endif

/*
 * ecm_db_time_get()
 *	Return database time, in seconds since the database started.
 */
uint32_t ecm_db_time_get(void)
{
	uint32_t time_now;
	spin_lock_bh(&ecm_db_lock);
	time_now = ecm_db_time;
	spin_unlock_bh(&ecm_db_lock);
	return time_now;
}
EXPORT_SYMBOL(ecm_db_time_get);

/*
 * ecm_db_get_defunct_all()
 *	Reading this file returns the accumulated total of all objects
 */
static ssize_t ecm_db_get_defunct_all(struct file *file,
					char __user *user_buf,
					size_t sz, loff_t *ppos)
{
	int ret;
	int num;
	char *buf;

	buf = kmalloc(PAGE_SIZE, GFP_KERNEL);
	if (!buf) {
		return -ENOMEM;
	}

	/*
	 * Operate under our locks
	 */
	spin_lock_bh(&ecm_db_lock);
	num = ecm_db_connection_count + ecm_db_mapping_count + ecm_db_host_count
			+ ecm_db_node_count + ecm_db_iface_count;
	spin_unlock_bh(&ecm_db_lock);

	ret = snprintf(buf, (ssize_t)PAGE_SIZE, "%d\n", num);
	if (ret < 0) {
		kfree(buf);
		return ret;
	}

	ret = simple_read_from_buffer(user_buf, sz, ppos, buf, ret);
	kfree(buf);
	return ret;
}

/*
 * ecm_db_set_defunct_all()
 */
static ssize_t ecm_db_set_defunct_all(struct file *file,
					const char __user *user_buf,
					size_t sz, loff_t *ppos)
{
	ecm_db_connection_defunct_all();
	return sz;
}

/*
 * File operations for defunct_all.
 */
static struct file_operations ecm_db_defunct_all_fops = {
	.read = ecm_db_get_defunct_all,
	.write = ecm_db_set_defunct_all,
};

/*
 * ecm_db_get_connection_counts_simple()
 *	Return total of connections for each simple protocol (tcp, udp, other).  Primarily for use by the luci-bwc service.
 */
static ssize_t ecm_db_get_connection_counts_simple(struct file *file,
						char __user *user_buf,
						size_t sz, loff_t *ppos)
{
	int tcp_count;
	int udp_count;
	int other_count;
	int total_count;
	int ret;
	char *buf;

	buf = kmalloc(PAGE_SIZE, GFP_KERNEL);
	if (!buf) {
		return -ENOMEM;
	}

	/*
	 * Get snapshot of the protocol counts
	 */
	spin_lock_bh(&ecm_db_lock);
	tcp_count = ecm_db_connection_count_by_protocol[IPPROTO_TCP];
	udp_count = ecm_db_connection_count_by_protocol[IPPROTO_UDP];
	total_count = ecm_db_connection_count;
	other_count = total_count - (tcp_count + udp_count);
	spin_unlock_bh(&ecm_db_lock);

	ret = snprintf(buf, (ssize_t)PAGE_SIZE, "tcp %d udp %d other %d total %d\n", tcp_count, udp_count, other_count, total_count);
	if (ret < 0) {
		kfree(buf);
		return -EFAULT;
	}

	ret = simple_read_from_buffer(user_buf, sz, ppos, buf, ret);
	kfree(buf);
	return ret;
}

/*
 * File operations for simple connection counts.
 */
static struct file_operations ecm_db_connection_count_simple_fops = {
	.read = ecm_db_get_connection_counts_simple,
};

/*
 * ecm_db_timer_callback()
 *	Manage expiration of connections
 * NOTE: This is softirq context
 */
static void ecm_db_timer_callback(unsigned long data)
{
	uint32_t timer;

	/*
	 * Increment timer.
	 */
	spin_lock_bh(&ecm_db_lock);
	timer = ++ecm_db_time;
	spin_unlock_bh(&ecm_db_lock);
	DEBUG_TRACE("Garbage timer tick %d\n", timer);

	/*
	 * Check timer groups
	 */
	ecm_db_timer_groups_check(timer);

	/*
	 * Set the timer for the next second
	 */
	ecm_db_timer.expires += HZ;
	if (ecm_db_timer.expires <= jiffies) {
		DEBUG_WARN("losing time %lu, jiffies = %lu\n", ecm_db_timer.expires, jiffies);
		ecm_db_timer.expires = jiffies + HZ;
	}
	add_timer(&ecm_db_timer);
}
#ifdef ECM_DB_XREF_ENABLE
/*
 * ecm_db_node_from_connections_get_and_ref_first()
 *	Obtain a ref to the first connection instance of "from list" of node, if any
 */
static inline struct ecm_db_connection_instance *ecm_db_node_from_connections_get_and_ref_first(struct ecm_db_node_instance *node)
{
	struct ecm_db_connection_instance *ci;
	DEBUG_CHECK_MAGIC(node, ECM_DB_NODE_INSTANCE_MAGIC, "%p: magic failed", node);
	spin_lock_bh(&ecm_db_lock);
	ci = node->from_connections;
	if (ci) {
		_ecm_db_connection_ref(ci);
	}
	spin_unlock_bh(&ecm_db_lock);
	return ci;
}

/*
 * ecm_db_node_from_connection_get_and_ref_next()
 *	Return the next connection in the "from list" of given a connection
 */
static inline struct ecm_db_connection_instance *ecm_db_node_from_connection_get_and_ref_next(struct ecm_db_connection_instance *ci)
{
	struct ecm_db_connection_instance *cin;
	DEBUG_CHECK_MAGIC(ci, ECM_DB_CONNECTION_INSTANCE_MAGIC, "%p: magic failed", ci);
	spin_lock_bh(&ecm_db_lock);
	cin = ci->node_from_next;
	if (cin) {
		_ecm_db_connection_ref(cin);
	}
	spin_unlock_bh(&ecm_db_lock);
	return cin;
}

/*
 * ecm_db_node_to_connections_get_and_ref_first()
 *	Obtain a ref to the first connection instance of a "to list" of node, if any
 */
static inline struct ecm_db_connection_instance *ecm_db_node_to_connections_get_and_ref_first(struct ecm_db_node_instance *node)
{
	struct ecm_db_connection_instance *ci;
	DEBUG_CHECK_MAGIC(node, ECM_DB_NODE_INSTANCE_MAGIC, "%p: magic failed", node);
	spin_lock_bh(&ecm_db_lock);
	ci = node->to_connections;
	if (ci) {
		_ecm_db_connection_ref(ci);
	}
	spin_unlock_bh(&ecm_db_lock);
	return ci;
}

/*
 * ecm_db_node_to_connection_get_and_ref_next()
 *	Return the next connection in the "to list" of given a connection
 */
static inline struct ecm_db_connection_instance *ecm_db_node_to_connection_get_and_ref_next(struct ecm_db_connection_instance *ci)
{
	struct ecm_db_connection_instance *cin;
	DEBUG_CHECK_MAGIC(ci, ECM_DB_CONNECTION_INSTANCE_MAGIC, "%p: magic failed", ci);
	spin_lock_bh(&ecm_db_lock);
	cin = ci->node_to_next;
	if (cin) {
		_ecm_db_connection_ref(cin);
	}
	spin_unlock_bh(&ecm_db_lock);
	return cin;
}

/*
 * ecm_db_node_from_nat_connections_get_and_ref_first()
 *	Obtain a ref to the first connection instance of a "from_nat list" of node, if any
 */
static inline struct ecm_db_connection_instance *ecm_db_node_from_nat_connections_get_and_ref_first(struct ecm_db_node_instance *node)
{
	struct ecm_db_connection_instance *ci;
	DEBUG_CHECK_MAGIC(node, ECM_DB_NODE_INSTANCE_MAGIC, "%p: magic failed", node);
	spin_lock_bh(&ecm_db_lock);
	ci = node->from_nat_connections;
	if (ci) {
		_ecm_db_connection_ref(ci);
	}
	spin_unlock_bh(&ecm_db_lock);
	return ci;
}

/*
 * ecm_db_node_from_nat_connection_get_and_ref_next()
 *	Return the next connection in the "from nat list" of given a connection
 */
static inline struct ecm_db_connection_instance *ecm_db_node_from_nat_connection_get_and_ref_next(struct ecm_db_connection_instance *ci)
{
	struct ecm_db_connection_instance *cin;
	DEBUG_CHECK_MAGIC(ci, ECM_DB_CONNECTION_INSTANCE_MAGIC, "%p: magic failed", ci);
	spin_lock_bh(&ecm_db_lock);
	cin = ci->node_from_nat_next;
	if (cin) {
		_ecm_db_connection_ref(cin);
	}
	spin_unlock_bh(&ecm_db_lock);
	return cin;
}

/*
 * ecm_db_node_to_nat_connections_get_and_ref_first()
 *	Obtain a ref to the first connection instance of a "to_nat list" of node, if any
 */
static inline struct ecm_db_connection_instance *ecm_db_node_to_nat_connections_get_and_ref_first(struct ecm_db_node_instance *node)
{
	struct ecm_db_connection_instance *ci;
	DEBUG_CHECK_MAGIC(node, ECM_DB_NODE_INSTANCE_MAGIC, "%p: magic failed", node);
	spin_lock_bh(&ecm_db_lock);
	ci = node->to_nat_connections;
	if (ci) {
		_ecm_db_connection_ref(ci);
	}
	spin_unlock_bh(&ecm_db_lock);
	return ci;
}

/*
 * ecm_db_node_to_nat_connection_get_and_ref_next()
 *	Return the next connection in the "to nat list" of given a connection
 */
static inline struct ecm_db_connection_instance *ecm_db_node_to_nat_connection_get_and_ref_next(struct ecm_db_connection_instance *ci)
{
	struct ecm_db_connection_instance *cin;
	DEBUG_CHECK_MAGIC(ci, ECM_DB_CONNECTION_INSTANCE_MAGIC, "%p: magic failed", ci);
	spin_lock_bh(&ecm_db_lock);
	cin = ci->node_to_nat_next;
	if (cin) {
		_ecm_db_connection_ref(cin);
	}
	spin_unlock_bh(&ecm_db_lock);
	return cin;
}

/*
 * ecm_db_should_keep_connection()
 *	check if any classifier believes this connection should
 *	be kept
 */
static bool ecm_db_should_keep_connection(
	struct ecm_db_connection_instance *ci, uint8_t *mac)
{
	bool should_keep_connection = false;
	int assignment_count;
	int aci_index;
	struct ecm_classifier_instance *assignments[ECM_CLASSIFIER_TYPES];

	assignment_count =
		ecm_db_connection_classifier_assignments_get_and_ref(ci, assignments);
	for (aci_index = 0; aci_index < assignment_count; ++aci_index) {
		struct ecm_classifier_instance *aci;
		aci = assignments[aci_index];
		if (aci->should_keep_connection &&
			aci->should_keep_connection(aci, mac)) {
			should_keep_connection = true;
			break;
		}
	}
	ecm_db_connection_assignments_release(assignment_count, assignments);

	return should_keep_connection;
}

/*
 * ecm_db_traverse_node_from_connection_list_and_defunct()
 *	traverse from_list of a node and calls ecm_db_connection_make_defunct()
 *	for each entry
 */
void ecm_db_traverse_node_from_connection_list_and_defunct(
	struct ecm_db_node_instance *node)
{
	struct ecm_db_connection_instance *ci = NULL;

	/*
	 * Iterate all from connections
	 */
	ci = ecm_db_node_from_connections_get_and_ref_first(node);
	while (ci) {
		struct ecm_db_connection_instance *cin;

		if (!ecm_db_should_keep_connection(ci, node->address)) {
			DEBUG_TRACE("%p: defunct %d\n", ci, ci->serial);
			ecm_db_connection_make_defunct(ci);
		} else {
			DEBUG_TRACE("%p: keeping connection %d\n", ci, ci->serial);
		}

		cin = ecm_db_node_from_connection_get_and_ref_next(ci);
		ecm_db_connection_deref(ci);
		ci = cin;
	}
	DEBUG_INFO("%p: Defuncting from node connection list complete\n", node);
}

/*
 * ecm_db_traverse_node_to_connection_list_and_defunct()
 *	traverse to_list of a node and calls ecm_db_connection_make_defunct()
 *	for each entry
 */
void ecm_db_traverse_node_to_connection_list_and_defunct(
	struct ecm_db_node_instance *node)
{
	struct ecm_db_connection_instance *ci = NULL;

	/*
	 * Iterate all to connections
	 */
	ci = ecm_db_node_to_connections_get_and_ref_first(node);
	while (ci) {
		struct ecm_db_connection_instance *cin;

		if (!ecm_db_should_keep_connection(ci, node->address)) {
			DEBUG_TRACE("%p: defunct %d\n", ci, ci->serial);
			ecm_db_connection_make_defunct(ci);
		} else {
			DEBUG_TRACE("%p: keeping connection %d\n", ci, ci->serial);
		}

		cin = ecm_db_node_to_connection_get_and_ref_next(ci);
		ecm_db_connection_deref(ci);
		ci = cin;
	}
	DEBUG_INFO("%p: Defuncting to node connection list complete\n", node);
}

/*
 * ecm_db_traverse_node_from_nat_connection_list_and_defunct()
 *	traverse from_nat_list of a node and calls ecm_db_connection_make_defunct()
 *	for each entry
 */
void ecm_db_traverse_node_from_nat_connection_list_and_defunct(
	struct ecm_db_node_instance *node)
{
	struct ecm_db_connection_instance *ci = NULL;

	/*
	 * Iterate all from nat connections
	 */
	ci = ecm_db_node_from_nat_connections_get_and_ref_first(node);
	while (ci) {
		struct ecm_db_connection_instance *cin;

		if (!ecm_db_should_keep_connection(ci, node->address)) {
			DEBUG_TRACE("%p: defunct %d\n", ci, ci->serial);
			ecm_db_connection_make_defunct(ci);
		} else {
			DEBUG_TRACE("%p: keeping connection %d\n", ci, ci->serial);
		}

		cin = ecm_db_node_from_nat_connection_get_and_ref_next(ci);
		ecm_db_connection_deref(ci);
		ci = cin;
	}
	DEBUG_INFO("%p: Defuncting from_nat node connection list complete\n", node);
}

/*
 * ecm_db_traverse_node_to_nat_connection_list_and_defunct()
 *	traverse to_nat_list of a node and calls ecm_db_connection_make_defunct()
 *	for each entry
 */
void ecm_db_traverse_node_to_nat_connection_list_and_defunct(
	struct ecm_db_node_instance *node)
{
	struct ecm_db_connection_instance *ci = NULL;

	/*
	 * Iterate all to nat connections
	 */
	ci = ecm_db_node_to_nat_connections_get_and_ref_first(node);
	while (ci) {
		struct ecm_db_connection_instance *cin;

		if (!ecm_db_should_keep_connection(ci, node->address)) {
			DEBUG_TRACE("%p: defunct %d\n", ci, ci->serial);
			ecm_db_connection_make_defunct(ci);
		} else {
			DEBUG_TRACE("%p: keeping connection %d\n", ci, ci->serial);
		}

		cin = ecm_db_node_to_nat_connection_get_and_ref_next(ci);
		ecm_db_connection_deref(ci);
		ci = cin;
	}
	DEBUG_INFO("%p: Defuncting to_nat node connection list complete\n", node);
}
#endif

/*
 * ecm_db_connection_ipv6_from_ct_get_and_ref()
 *	Return, if any, a connection given a ct
 */
struct ecm_db_connection_instance *ecm_db_connection_ipv6_from_ct_get_and_ref(struct nf_conn *ct)
{
	struct nf_conntrack_tuple orig_tuple;
	struct nf_conntrack_tuple reply_tuple;
	ip_addr_t host1_addr;
	ip_addr_t host2_addr;
	int host1_port;
	int host2_port;
	int protocol;

	/*
	 * Look up the associated connection for this conntrack connection
	 */
	orig_tuple = ct->tuplehash[IP_CT_DIR_ORIGINAL].tuple;
	reply_tuple = ct->tuplehash[IP_CT_DIR_REPLY].tuple;
	ECM_NIN6_ADDR_TO_IP_ADDR(host1_addr, orig_tuple.src.u3.in6);
	ECM_NIN6_ADDR_TO_IP_ADDR(host2_addr, reply_tuple.src.u3.in6);
	protocol = orig_tuple.dst.protonum;
	switch (protocol) {
	case IPPROTO_TCP:
		host1_port = ntohs(orig_tuple.src.u.tcp.port);
		host2_port = ntohs(reply_tuple.src.u.tcp.port);
		break;
	case IPPROTO_UDP:
		host1_port = ntohs(orig_tuple.src.u.udp.port);
		host2_port = ntohs(reply_tuple.src.u.udp.port);
		break;
	case IPPROTO_IPIP:
	case IPPROTO_GRE:
		host1_port = 0;
		host2_port = 0;
		break;
	default:
		host1_port = -protocol;
		host2_port = -protocol;
	}

	DEBUG_TRACE("%p: lookup src: " ECM_IP_ADDR_OCTAL_FMT ":%d, "
		    "dest: " ECM_IP_ADDR_OCTAL_FMT ":%d, "
		    "protocol %d\n",
		    ct,
		    ECM_IP_ADDR_TO_OCTAL(host1_addr),
		    host1_port,
		    ECM_IP_ADDR_TO_OCTAL(host2_addr),
		    host2_port,
		    protocol);

	return ecm_db_connection_find_and_ref(host1_addr,
					      host2_addr,
					      protocol,
					      host1_port,
					      host2_port);
}

/*
 * ecm_db_connection_ipv4_from_ct_get_and_ref()
 *	Return, if any, a connection given a ct
 */
struct ecm_db_connection_instance *ecm_db_connection_ipv4_from_ct_get_and_ref(struct nf_conn *ct)
{
	struct nf_conntrack_tuple orig_tuple;
	struct nf_conntrack_tuple reply_tuple;
	ip_addr_t host1_addr;
	ip_addr_t host2_addr;
	int host1_port;
	int host2_port;
	int protocol;

	/*
	 * Look up the associated connection for this conntrack connection
	 */
	orig_tuple = ct->tuplehash[IP_CT_DIR_ORIGINAL].tuple;
	reply_tuple = ct->tuplehash[IP_CT_DIR_REPLY].tuple;
	ECM_NIN4_ADDR_TO_IP_ADDR(host1_addr, orig_tuple.src.u3.ip);
	ECM_NIN4_ADDR_TO_IP_ADDR(host2_addr, reply_tuple.src.u3.ip);
	protocol = orig_tuple.dst.protonum;
	switch (protocol) {
	case IPPROTO_TCP:
		host1_port = ntohs(orig_tuple.src.u.tcp.port);
		host2_port = ntohs(reply_tuple.src.u.tcp.port);
		break;
	case IPPROTO_UDP:
		host1_port = ntohs(orig_tuple.src.u.udp.port);
		host2_port = ntohs(reply_tuple.src.u.udp.port);
		break;
	case IPPROTO_IPV6:
	case IPPROTO_ESP:
	case IPPROTO_GRE:
		host1_port = 0;
		host2_port = 0;
		break;
	default:
		host1_port = -protocol;
		host2_port = -protocol;
	}

	DEBUG_TRACE("%p: lookup src: " ECM_IP_ADDR_DOT_FMT ":%d, "
		    "dest: " ECM_IP_ADDR_DOT_FMT ":%d, "
		    "protocol %d\n",
		    ct,
		    ECM_IP_ADDR_TO_DOT(host1_addr),
		    host1_port,
		    ECM_IP_ADDR_TO_DOT(host2_addr),
		    host2_port,
		    protocol);

	return ecm_db_connection_find_and_ref(host1_addr,
					      host2_addr,
					      protocol,
					      host1_port,
					      host2_port);
}

/*
 * ecm_db_iproute_connection_cmp_and_kill()
 *     This is the "iterate" function passed to the nf_ct_iterate_cleanup()
 *     function.
 */
static int ecm_db_iproute_connection_cmp_and_kill(struct nf_conn *i, void *data)
{
	struct ecm_db_connection_instance *ci;

	if (nf_ct_l3num(i) != AF_INET) {
		return 0;
	}

	/*
	 * Go through the conntarck entries and if they are found in ECM db,
	 * let the netfilter conntrack kill it..
	 */
	ci = ecm_db_connection_ipv4_from_ct_get_and_ref(i);
	if (ci) {
		ecm_db_connection_deref(ci);
		return 1;
	}

	return 0;
}

/*
 * ecm_db_iproute_table_update_event()
 *	This is a call back for "routing table update event for IPv4"
 */
static int ecm_db_iproute_table_update_event(struct notifier_block *nb,
					       unsigned long event,
					       void *ptr)
{
	DEBUG_TRACE("iproute table update event\n");

#if (LINUX_VERSION_CODE <= KERNEL_VERSION(3, 11, 0))
	nf_ct_iterate_cleanup(&init_net, ecm_db_iproute_connection_cmp_and_kill, 0);
#else
	nf_ct_iterate_cleanup(&init_net, ecm_db_iproute_connection_cmp_and_kill, 0, 0, 0);
#endif
	return NOTIFY_DONE;
}

static struct notifier_block ecm_db_iproute_table_update_nb = {
	.notifier_call = ecm_db_iproute_table_update_event,
};

/*
 * ecm_db_ip6route_connection_cmp_and_kill()
 *     This is the "iterate" function passed to the nf_ct_iterate_cleanup()
 *     function.
 */
static int ecm_db_ip6route_connection_cmp_and_kill(struct nf_conn *i, void *data)
{
	struct ecm_db_connection_instance *ci;

	if (nf_ct_l3num(i) != AF_INET6) {
		return 0;
	}

	/*
	 * Go through the conntarck entries and if they are found in ECM db,
	 * let the netfilter conntrack kill it..
	 */
	ci = ecm_db_connection_ipv6_from_ct_get_and_ref(i);
	if (ci) {
		ecm_db_connection_deref(ci);
		return 1;
	}

	return 0;
}

/*
 * ecm_db_ip6route_table_iterate_cleanup_work()
 *	Clean up work function for IPv6 route change event.
 */
static void ecm_db_ip6route_table_iterate_cleanup_work(struct work_struct *work)
{
	DEBUG_TRACE("ip6route table iterate cleanup work\n");

#if (LINUX_VERSION_CODE <= KERNEL_VERSION(3, 11, 0))
	nf_ct_iterate_cleanup(&init_net, ecm_db_ip6route_connection_cmp_and_kill, 0);
#else
	nf_ct_iterate_cleanup(&init_net, ecm_db_ip6route_connection_cmp_and_kill, 0, 0, 0);
#endif
	kfree(work);
	atomic_dec(&ecm_db_ip6route_work_count);
}

/*
 * ecm_db_ip6route_table_update_event()
 *	This is a callback for "routing table update event for IPv6"
 *
 * ipv6 route change notifier is an atomic notifier, i.e. we cannot
 * schedule.
 *
 * Unfortunately, nf_ct_iterate_cleanup can run for a long
 * time if there are lots of conntracks and the system
 * handles high softirq load, so it frequently calls cond_resched
 * while iterating the conntrack table.
 *
 * So we defer nf_ct_iterate_cleanup walk to the system workqueue.
 */
static int ecm_db_ip6route_table_update_event(struct notifier_block *nb,
					       unsigned long event,
					       void *ptr)
{
	struct work_struct *work;

	DEBUG_TRACE("ip6route table update event\n");

	if (atomic_read(&ecm_db_ip6route_work_count) >= ECM_DB_IP6ROUTE_MAX_WORK_COUNT)
		return NOTIFY_DONE;


	work = kmalloc(sizeof(*work), GFP_ATOMIC);
	if (work) {
		atomic_inc(&ecm_db_ip6route_work_count);

		INIT_WORK(work, ecm_db_ip6route_table_iterate_cleanup_work);
		schedule_work(work);
	}

	return NOTIFY_DONE;
}

static struct notifier_block ecm_db_ip6route_table_update_nb = {
	.notifier_call = ecm_db_ip6route_table_update_event,
};

/*
 * ecm_db_init()
 */
int ecm_db_init(struct dentry *dentry)
{
	DEBUG_INFO("ECM Module init\n");

	ecm_db_dentry = debugfs_create_dir("ecm_db", dentry);
	if (!ecm_db_dentry) {
		DEBUG_ERROR("Failed to create ecm db directory in debugfs\n");
		return -1;
	}

	/*
	 * Get a random seed for jhash()
	 */
	get_random_bytes(&ecm_db_jhash_rnd, sizeof(ecm_db_jhash_rnd));
	printk(KERN_INFO "ECM database jhash random seed: 0x%x\n", ecm_db_jhash_rnd);

	if (!debugfs_create_u32("connection_count", S_IRUGO, ecm_db_dentry,
					(u32 *)&ecm_db_connection_count)) {
		DEBUG_ERROR("Failed to create ecm db connection count file in debugfs\n");
		goto init_cleanup;
	}

	if (!debugfs_create_u32("host_count", S_IRUGO, ecm_db_dentry,
					(u32 *)&ecm_db_host_count)) {
		DEBUG_ERROR("Failed to create ecm db host count file in debugfs\n");
		goto init_cleanup;
	}

	if (!debugfs_create_u32("mapping_count", S_IRUGO, ecm_db_dentry,
					(u32 *)&ecm_db_mapping_count)) {
		DEBUG_ERROR("Failed to create ecm db mapping count file in debugfs\n");
		goto init_cleanup;
	}

	if (!debugfs_create_u32("node_count", S_IRUGO, ecm_db_dentry,
					(u32 *)&ecm_db_node_count)) {
		DEBUG_ERROR("Failed to create ecm db node count file in debugfs\n");
		goto init_cleanup;
	}

	if (!debugfs_create_u32("iface_count", S_IRUGO, ecm_db_dentry,
					(u32 *)&ecm_db_iface_count)) {
		DEBUG_ERROR("Failed to create ecm db iface count file in debugfs\n");
		goto init_cleanup;
	}

	if (!debugfs_create_file("defunct_all", S_IRUGO | S_IWUSR, ecm_db_dentry,
					NULL, &ecm_db_defunct_all_fops)) {
		DEBUG_ERROR("Failed to create ecm db defunct_all file in debugfs\n");
		goto init_cleanup;
	}

	if (!debugfs_create_file("connection_count_simple", S_IRUGO, ecm_db_dentry,
					NULL, &ecm_db_connection_count_simple_fops)) {
		DEBUG_ERROR("Failed to create ecm db connection count simple file in debugfs\n");
		goto init_cleanup;
	}

	ecm_db_connection_table = vzalloc(sizeof(struct ecm_db_connection_instance *) * ECM_DB_CONNECTION_HASH_SLOTS);
	if (!ecm_db_connection_table) {
		DEBUG_ERROR("Failed to allocate virtual memory for ecm_db_connection_table\n");
		goto init_cleanup;
	}

	ecm_db_connection_table_lengths = vzalloc(sizeof(int) * ECM_DB_CONNECTION_HASH_SLOTS);
	if (!ecm_db_connection_table_lengths) {
		DEBUG_ERROR("Failed to allocate virtual memory for ecm_db_connection_table_lengths\n");
		goto init_cleanup_1;
	}

	ecm_db_connection_serial_table = vzalloc(sizeof(struct ecm_db_connection_instance *) * ECM_DB_CONNECTION_SERIAL_HASH_SLOTS);
	if (!ecm_db_connection_serial_table) {
		DEBUG_ERROR("Failed to allocate virtual memory for ecm_db_connection_serial_table\n");
		goto init_cleanup_2;
	}

	ecm_db_connection_serial_table_lengths = vzalloc(sizeof(int) * ECM_DB_CONNECTION_SERIAL_HASH_SLOTS);
	if (!ecm_db_connection_serial_table_lengths) {
		DEBUG_ERROR("Failed to allocate virtual memory for ecm_db_connection_serial_table_lengths\n");
		goto init_cleanup_3;
	}

	ecm_db_mapping_table = vzalloc(sizeof(struct ecm_db_mapping_instance *) * ECM_DB_MAPPING_HASH_SLOTS);
	if (!ecm_db_mapping_table) {
		DEBUG_ERROR("Failed to allocate virtual memory for ecm_db_mapping_table\n");
		goto init_cleanup_4;
	}

	ecm_db_mapping_table_lengths = vzalloc(sizeof(int) * ECM_DB_MAPPING_HASH_SLOTS);
	if (!ecm_db_mapping_table_lengths) {
		DEBUG_ERROR("Failed to allocate virtual memory for ecm_db_mapping_table_lengths\n");
		goto init_cleanup_5;
	}

	ecm_db_host_table = vzalloc(sizeof(struct ecm_db_host_instance *) * ECM_DB_HOST_HASH_SLOTS);
	if (!ecm_db_host_table) {
		DEBUG_ERROR("Failed to allocate virtual memory for ecm_db_host_table\n");
		goto init_cleanup_6;
	}

	ecm_db_host_table_lengths = vzalloc(sizeof(int) * ECM_DB_HOST_HASH_SLOTS);
	if (!ecm_db_host_table_lengths) {
		DEBUG_ERROR("Failed to allocate virtual memory for ecm_db_host_table_lengths\n");
		goto init_cleanup_7;
	}

	ecm_db_node_table = vzalloc(sizeof(struct ecm_db_node_instance *) * ECM_DB_NODE_HASH_SLOTS);
	if (!ecm_db_node_table) {
		DEBUG_ERROR("Failed to allocate virtual memory for ecm_db_node_table\n");
		goto init_cleanup_8;
	}

	ecm_db_node_table_lengths = vzalloc(sizeof(int) * ECM_DB_NODE_HASH_SLOTS);
	if (!ecm_db_node_table_lengths) {
		DEBUG_ERROR("Failed to allocate virtual memory for ecm_db_node_table_lengths\n");
		goto init_cleanup_9;
	}

	/*
	 * Set a timer to manage cleanup of expired connections
	 */
	init_timer(&ecm_db_timer);
	ecm_db_timer.function = ecm_db_timer_callback;
	ecm_db_timer.data = 0;
	ecm_db_timer.expires = jiffies + HZ;
	add_timer(&ecm_db_timer);

	/*
	 * Initialise timer groups with time values
	 */
	ecm_db_timer_groups[ECM_DB_TIMER_GROUPS_CLASSIFIER_DETERMINE_GENERIC_TIMEOUT].time = ECM_DB_CLASSIFIER_DETERMINE_GENERIC_TIMEOUT;
	ecm_db_timer_groups[ECM_DB_TIMER_GROUPS_CLASSIFIER_DETERMINE_GENERIC_TIMEOUT].tg = ECM_DB_TIMER_GROUPS_CLASSIFIER_DETERMINE_GENERIC_TIMEOUT;
	ecm_db_timer_groups[ECM_DB_TIMER_GROUPS_CONNECTION_GENERIC_TIMEOUT].time = ECM_DB_CONNECTION_GENERIC_TIMEOUT;
	ecm_db_timer_groups[ECM_DB_TIMER_GROUPS_CONNECTION_GENERIC_TIMEOUT].tg = ECM_DB_TIMER_GROUPS_CONNECTION_GENERIC_TIMEOUT;
	ecm_db_timer_groups[ECM_DB_TIMER_GROUPS_CONNECTION_IGMP_TIMEOUT].time = ECM_DB_CONNECTION_IGMP_TIMEOUT;
	ecm_db_timer_groups[ECM_DB_TIMER_GROUPS_CONNECTION_IGMP_TIMEOUT].tg = ECM_DB_TIMER_GROUPS_CONNECTION_IGMP_TIMEOUT;
	ecm_db_timer_groups[ECM_DB_TIMER_GROUPS_CONNECTION_UDP_GENERIC_TIMEOUT].time = ECM_DB_CONNECTION_UDP_TIMEOUT;
	ecm_db_timer_groups[ECM_DB_TIMER_GROUPS_CONNECTION_UDP_GENERIC_TIMEOUT].tg = ECM_DB_TIMER_GROUPS_CONNECTION_UDP_GENERIC_TIMEOUT;
	ecm_db_timer_groups[ECM_DB_TIMER_GROUPS_CONNECTION_UDP_WKP_TIMEOUT].time = ECM_DB_CONNECTION_UDP_TIMEOUT;
	ecm_db_timer_groups[ECM_DB_TIMER_GROUPS_CONNECTION_UDP_WKP_TIMEOUT].tg = ECM_DB_TIMER_GROUPS_CONNECTION_UDP_WKP_TIMEOUT;
	ecm_db_timer_groups[ECM_DB_TIMER_GROUPS_CONNECTION_ICMP_TIMEOUT].time = ECM_DB_CONNECTION_ICMP_TIMEOUT;
	ecm_db_timer_groups[ECM_DB_TIMER_GROUPS_CONNECTION_ICMP_TIMEOUT].tg = ECM_DB_TIMER_GROUPS_CONNECTION_ICMP_TIMEOUT;
	ecm_db_timer_groups[ECM_DB_TIMER_GROUPS_CONNECTION_TCP_SHORT_TIMEOUT].time = ECM_DB_CONNECTION_TCP_SHORT_TIMEOUT;
	ecm_db_timer_groups[ECM_DB_TIMER_GROUPS_CONNECTION_TCP_SHORT_TIMEOUT].tg = ECM_DB_TIMER_GROUPS_CONNECTION_TCP_SHORT_TIMEOUT;
	ecm_db_timer_groups[ECM_DB_TIMER_GROUPS_CONNECTION_TCP_RESET_TIMEOUT].time = ECM_DB_CONNECTION_TCP_RST_TIMEOUT;
	ecm_db_timer_groups[ECM_DB_TIMER_GROUPS_CONNECTION_TCP_RESET_TIMEOUT].tg = ECM_DB_TIMER_GROUPS_CONNECTION_TCP_RESET_TIMEOUT;
	ecm_db_timer_groups[ECM_DB_TIMER_GROUPS_CONNECTION_TCP_LONG_TIMEOUT].time = ECM_DB_CONNECTION_TCP_LONG_TIMEOUT;
	ecm_db_timer_groups[ECM_DB_TIMER_GROUPS_CONNECTION_TCP_LONG_TIMEOUT].tg = ECM_DB_TIMER_GROUPS_CONNECTION_TCP_LONG_TIMEOUT;
	ecm_db_timer_groups[ECM_DB_TIMER_GROUPS_CONNECTION_PPTP_DATA_TIMEOUT].time = ECM_DB_CONNECTION_PPTP_DATA_TIMEOUT;
	ecm_db_timer_groups[ECM_DB_TIMER_GROUPS_CONNECTION_PPTP_DATA_TIMEOUT].tg = ECM_DB_TIMER_GROUPS_CONNECTION_PPTP_DATA_TIMEOUT;
	ecm_db_timer_groups[ECM_DB_TIMER_GROUPS_CONNECTION_RTCP_TIMEOUT].time = ECM_DB_CONNECTION_RTCP_TIMEOUT;
	ecm_db_timer_groups[ECM_DB_TIMER_GROUPS_CONNECTION_RTCP_TIMEOUT].tg = ECM_DB_TIMER_GROUPS_CONNECTION_RTCP_TIMEOUT;
	ecm_db_timer_groups[ECM_DB_TIMER_GROUPS_CONNECTION_RTSP_TIMEOUT].time = ECM_DB_CONNECTION_TCP_LONG_TIMEOUT;
	ecm_db_timer_groups[ECM_DB_TIMER_GROUPS_CONNECTION_RTSP_TIMEOUT].tg = ECM_DB_TIMER_GROUPS_CONNECTION_RTSP_TIMEOUT;
	ecm_db_timer_groups[ECM_DB_TIMER_GROUPS_CONNECTION_RTSP_FAST_TIMEOUT].time = ECM_DB_CONNECTION_RTSP_FAST_TIMEOUT;
	ecm_db_timer_groups[ECM_DB_TIMER_GROUPS_CONNECTION_RTSP_FAST_TIMEOUT].tg = ECM_DB_TIMER_GROUPS_CONNECTION_RTSP_FAST_TIMEOUT;
	ecm_db_timer_groups[ECM_DB_TIMER_GROUPS_CONNECTION_RTSP_SLOW_TIMEOUT].time = ECM_DB_CONNECTION_RTSP_SLOW_TIMEOUT;
	ecm_db_timer_groups[ECM_DB_TIMER_GROUPS_CONNECTION_RTSP_SLOW_TIMEOUT].tg = ECM_DB_TIMER_GROUPS_CONNECTION_RTSP_SLOW_TIMEOUT;
	ecm_db_timer_groups[ECM_DB_TIMER_GROUPS_CONNECTION_DNS_TIMEOUT].time = ECM_DB_CONNECTION_DNS_TIMEOUT;
	ecm_db_timer_groups[ECM_DB_TIMER_GROUPS_CONNECTION_DNS_TIMEOUT].tg = ECM_DB_TIMER_GROUPS_CONNECTION_DNS_TIMEOUT;
	ecm_db_timer_groups[ECM_DB_TIMER_GROUPS_CONNECTION_FTP_TIMEOUT].time = ECM_DB_CONNECTION_FTP_TIMEOUT;
	ecm_db_timer_groups[ECM_DB_TIMER_GROUPS_CONNECTION_FTP_TIMEOUT].tg = ECM_DB_TIMER_GROUPS_CONNECTION_FTP_TIMEOUT;
	ecm_db_timer_groups[ECM_DB_TIMER_GROUPS_CONNECTION_BITTORRENT_TIMEOUT].time = ECM_DB_CONNECTION_BITTORRENT_TIMEOUT;
	ecm_db_timer_groups[ECM_DB_TIMER_GROUPS_CONNECTION_BITTORRENT_TIMEOUT].tg = ECM_DB_TIMER_GROUPS_CONNECTION_BITTORRENT_TIMEOUT;

	/*
	 * H323 timeout value is 8 hours (8h * 60m * 60s == 28800 seconds).
	 */
	ecm_db_timer_groups[ECM_DB_TIMER_GROUPS_CONNECTION_H323_TIMEOUT].time = ECM_DB_CONNECTION_H323_TIMEOUT;
	ecm_db_timer_groups[ECM_DB_TIMER_GROUPS_CONNECTION_H323_TIMEOUT].tg = ECM_DB_TIMER_GROUPS_CONNECTION_H323_TIMEOUT;

	/*
	 * IKE Timeout (seconds) = 15 hours
	 */
	ecm_db_timer_groups[ECM_DB_TIMER_GROUPS_CONNECTION_IKE_TIMEOUT].time = ECM_DB_CONNECTION_IKE_TIMEOUT;
	ecm_db_timer_groups[ECM_DB_TIMER_GROUPS_CONNECTION_IKE_TIMEOUT].tg = ECM_DB_TIMER_GROUPS_CONNECTION_IKE_TIMEOUT;

	ecm_db_timer_groups[ECM_DB_TIMER_GROUPS_CONNECTION_ESP_TIMEOUT].time = ECM_DB_CONNECTION_ESP_TIMEOUT;
	ecm_db_timer_groups[ECM_DB_TIMER_GROUPS_CONNECTION_ESP_TIMEOUT].tg = ECM_DB_TIMER_GROUPS_CONNECTION_ESP_TIMEOUT;
	ecm_db_timer_groups[ECM_DB_TIMER_GROUPS_CONNECTION_ESP_PENDING_TIMEOUT].time = ECM_DB_CONNECTION_ESP_PENDING_TIMEOUT;
	ecm_db_timer_groups[ECM_DB_TIMER_GROUPS_CONNECTION_ESP_PENDING_TIMEOUT].tg = ECM_DB_TIMER_GROUPS_CONNECTION_ESP_PENDING_TIMEOUT;

	ecm_db_timer_groups[ECM_DB_TIMER_GROUPS_CONNECTION_SDP_TIMEOUT].time = ECM_DB_CONNECTION_SDP_TIMEOUT;
	ecm_db_timer_groups[ECM_DB_TIMER_GROUPS_CONNECTION_SDP_TIMEOUT].tg = ECM_DB_TIMER_GROUPS_CONNECTION_SDP_TIMEOUT;
	ecm_db_timer_groups[ECM_DB_TIMER_GROUPS_CONNECTION_SIP_TIMEOUT].time = ECM_DB_CONNECTION_SIP_TIMEOUT;
	ecm_db_timer_groups[ECM_DB_TIMER_GROUPS_CONNECTION_SIP_TIMEOUT].tg = ECM_DB_TIMER_GROUPS_CONNECTION_SIP_TIMEOUT;

	/*
	 * Defunct re-try timeout (5 seconds)
	 */
	ecm_db_timer_groups[ECM_DB_TIMER_GROUPS_CONNECTION_DEFUNCT_RETRY_TIMEOUT].time = ECM_DB_CONNECTION_DEFUNCT_RETRY_TIMEOUT;
	ecm_db_timer_groups[ECM_DB_TIMER_GROUPS_CONNECTION_DEFUNCT_RETRY_TIMEOUT].tg = ECM_DB_TIMER_GROUPS_CONNECTION_DEFUNCT_RETRY_TIMEOUT;

	/*
	 * Reset connection by protocol counters
	 */
	memset(ecm_db_connection_count_by_protocol, 0, sizeof(ecm_db_connection_count_by_protocol));

#ifdef ECM_DB_CTA_TRACK_ENABLE
	/*
	 * Reset classifier type assignment lists
	 */
	memset(ecm_db_connection_classifier_type_assignments, 0, sizeof(ecm_db_connection_classifier_type_assignments));
#endif
	/*
	 * register for route table modification events
	 */
	ip_rt_register_notifier(&ecm_db_iproute_table_update_nb);
	rt6_register_notifier(&ecm_db_ip6route_table_update_nb);

	return 0;

init_cleanup_9:
	vfree(ecm_db_node_table);
init_cleanup_8:
	vfree(ecm_db_host_table_lengths);
init_cleanup_7:
	vfree(ecm_db_host_table);
init_cleanup_6:
	vfree(ecm_db_mapping_table_lengths);
init_cleanup_5:
	vfree(ecm_db_mapping_table);
init_cleanup_4:
	vfree(ecm_db_connection_serial_table_lengths);
init_cleanup_3:
	vfree(ecm_db_connection_serial_table);
init_cleanup_2:
	vfree(ecm_db_connection_table_lengths);
init_cleanup_1:
	vfree(ecm_db_connection_table);
init_cleanup:
	debugfs_remove_recursive(ecm_db_dentry);
	return -1;
}
EXPORT_SYMBOL(ecm_db_init);

/*
 * ecm_db_exit()
 */
void ecm_db_exit(void)
{
	DEBUG_INFO("ECM DB Module exit\n");

	spin_lock_bh(&ecm_db_lock);
	ecm_db_terminate_pending = true;
	spin_unlock_bh(&ecm_db_lock);

	ecm_db_connection_defunct_all();

	/*
	 * Destroy garbage timer
	 * Timer must be cancelled outside of holding db lock - if the
	 * timer callback runs on another CPU we would deadlock
	 * as we would wait for the callback to finish and it would wait
	 * indefinately for the lock to be released!
	 */
	del_timer_sync(&ecm_db_timer);

	/*
	 * Free the tables.
	 */
	vfree(ecm_db_node_table);
	vfree(ecm_db_host_table_lengths);
	vfree(ecm_db_host_table);
	vfree(ecm_db_mapping_table_lengths);
	vfree(ecm_db_mapping_table);
	vfree(ecm_db_connection_serial_table_lengths);
	vfree(ecm_db_connection_serial_table);
	vfree(ecm_db_connection_table_lengths);
	vfree(ecm_db_connection_table);

	/*
	 * Remove the debugfs files recursively.
	 */
	if (ecm_db_dentry) {
		debugfs_remove_recursive(ecm_db_dentry);
	}

	/*
	 * unregister for route table update events
	 */
	ip_rt_unregister_notifier(&ecm_db_iproute_table_update_nb);
	rt6_unregister_notifier(&ecm_db_ip6route_table_update_nb);
}
EXPORT_SYMBOL(ecm_db_exit);
