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
#ifndef __GENERAL_OS_SERVICE_H
#define __GENERAL_OS_SERVICE_H

#include <stdint.h>
#include <stdbool.h>

#define GENL_OS_SERVICE_PRIVATE_DATA_SIZE 64

#define GENL_OS_SERVICE_FD_FLAGS_READ (1<<0)
#define GENL_OS_SERVICE_FD_FLAGS_WRITE (1<<1)

#define GENL_OS_SERVICE_FD_EVENTS_READ (1<<0)
#define GENL_OS_SERVICE_FD_EVENTS_WRITE (1<<1)

struct genl_os_service_fd;

typedef void (*genl_os_service_fd_handler)(struct genl_os_service_fd *fd, unsigned int events);

struct genl_os_service_private
{
	uint8_t private[GENL_OS_SERVICE_PRIVATE_DATA_SIZE];		/*OS specific data, used by wrapper*/
};

struct genl_os_service_fd
{
	genl_os_service_fd_handler cb;					/*callback for file descriptor*/
	void *arg;							/*argument for above callback*/
	int fd;								/*file descriptor*/
	unsigned int fd_flags;						/*call 'cb' when file descriptor is able to read or write*/

	struct genl_os_service_private private_data;
};

struct genl_os_service_timer;

typedef void (*general_os_service_timer_handler)(struct genl_os_service_timer *timer);

struct genl_os_service_timer
{
	general_os_service_timer_handler cb;				/*callback for timer*/
	void *arg;							/*argument for above callback*/
	int msecs;							/*delay of timer*/
	bool pending;							/*timer is started when true*/

	struct genl_os_service_private private_data;
};

struct genl_os_service_task;

typedef void (*general_os_service_task_handler)(struct genl_os_service_task *task, int ret);

struct genl_os_service_task
{
	general_os_service_task_handler cb;				/*call this callback when task completed*/
	void *arg;							/*argument for above callback*/
	int pid;							/*pid of task*/

	struct genl_os_service_private private_data;
};

struct genl_os_service {
	/*
	 * fd_add : listen on a file descriptor for reading or writing
	 * fd: file descriptor
	 * flags: call 'cb' when file descriptor is able to read or write
	 * return value: successful or fail
	 */
	int (*fd_add)(struct genl_os_service_fd *fd, unsigned int flags);
	/*
	 * fd_del : cancel to listen on file descriptor
	 * fd: file descriptor
	 * return value: successful or fail
	 */
	int (*fd_del)(struct genl_os_service_fd *fd);
	/*
	 * timer_set : start a timer
	 * timer: timer
	 * msecs: delay of timer, in unit of millisecond
	 * return value: successful or fail
	 */
	int (*timer_set)(struct genl_os_service_timer *timer, int msecs);
	/*
	 * timer_cancel : cancel a timer
	 * timer: timer
	 * return value: successful or fail
	 */
	int (*timer_cancel)(struct genl_os_service_timer *timer);
	/*
	 * task_add : wait for a task to complete, then execute corresponding handler
	 * task: task descriptor
	 * return value: successful or fail
	 */
	int (*task_add)(struct genl_os_service_task *task);
	/*
	 * task_del : cancel to wait for a task
	 * task: task descriptor
	 * return value: successful or fail
	 */
	int (*task_del)(struct genl_os_service_task *task);
};

enum {
	DBG_LEVEL_CRIT,
	DBG_LEVEL_WARNING,
	DBG_LEVEL_NOTICE,
	DBG_LEVEL_INFO,
	DBG_LEVEL_DEBUG,
	DBG_LEVEL_MAX
};

enum {
	DBG_MOD_CONFIG,
	DBG_MOD_STATUS,
	DBG_MOD_LACP,
	DBG_MOD_LACP_FSM,
	DBG_MOD_LACP_PKT,
	DBG_MOD_GENL_DEVICE,
	DBG_MOD_WRAPPER,
	DBG_MOD_MAX
};

extern unsigned int debug_mask[DBG_MOD_MAX];

#ifdef DEBUG
#define DPRINTF(format, ...) fprintf(stderr, "%s(%d): " format "\n", __func__, __LINE__, ## __VA_ARGS__)
#define DP(module, level, format, ...) do { \
		if (debug_mask[DBG_MOD_ ## module] >= (DBG_LEVEL_ ## level)) \
				DPRINTF(format, ##__VA_ARGS__); \
	} while (0)
#else
#define DPRINTF(format, ...) no_debug(0, 0, format, ## __VA_ARGS__)
#define DP(module, level, format, ...) no_debug(module, DBG_LEVEL_ ## level, format, ## __VA_ARGS__)
#endif

static inline void no_debug(int module, int level, const char *fmt, ...)
{
}

#endif /*__GENERAL_OS_SERVICE_H*/
