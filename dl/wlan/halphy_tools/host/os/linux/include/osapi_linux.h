//------------------------------------------------------------------------------
// This file contains the definitions of the basic atheros data types.
// It is used to map the data types in atheros files to a platform specific
// type.
// Copyright (c) 2004-2010 Atheros Communications Inc.
// All rights reserved.
//
// $ATH_LICENSE_HOSTSDK0_C$
//
// Author(s): ="Atheros"
//------------------------------------------------------------------------------
/*
 *  Copyright (c) 2014 Qualcomm Atheros, Inc.  All rights reserved. 
 *
 *  Qualcomm is a trademark of Qualcomm Technologies Incorporated, registered in the United
 *  States and other countries.  All Qualcomm Technologies Incorporated trademarks are used with
 *  permission.  Atheros is a trademark of Qualcomm Atheros, Inc., registered in
 *  the United States and other countries.  Other products and brand names may be
 *  trademarks or registered trademarks of their respective owners. 
 */

#ifndef _OSAPI_LINUX_H_
#define _OSAPI_LINUX_H_

#ifdef __KERNEL__

#include <linux/version.h>
#if LINUX_VERSION_CODE < KERNEL_VERSION(2,6,17)
#include <linux/config.h>
#elif LINUX_VERSION_CODE < KERNEL_VERSION(2,6,33)
#include <linux/autoconf.h>
#else
#include <generated/autoconf.h>
#endif
#include <linux/types.h>
#include <linux/kernel.h>
#include <linux/string.h>
#include <linux/skbuff.h>
#include <linux/netdevice.h>
#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,0)
#include <linux/jiffies.h>
#endif
#include <linux/timer.h>
#include <linux/delay.h>
#include <linux/wait.h>
#if LINUX_VERSION_CODE < KERNEL_VERSION(2,6,26)
#include <asm/semaphore.h>
#else
#include <linux/semaphore.h>
#endif
#ifdef KERNEL_2_4
#include <asm/arch/irq.h>
#include <asm/irq.h>
#endif

#include <linux/cache.h>
//#include <linux/kthread.h>
#include "a_types.h"

#ifdef __GNUC__
#define __ATTRIB_PACK           __attribute__ ((packed))
#define __ATTRIB_PRINTF         __attribute__ ((format (printf, 1, 2)))
#define __ATTRIB_NORETURN       __attribute__ ((noreturn))
#else /* Not GCC */
#define __ATTRIB_PACK
#define __ATTRIB_PRINTF
#define __ATTRIB_NORETURN
#endif /* End __GNUC__ */

#define PREPACK
#define POSTPACK                __attribute__ ((packed))
//#define POSTPACK                __attribute__ ((packed))__ATTRIB_PACK

/*
 * Endianes macros
 */
#define A_BE2CPU8(x)       ntohb(x)
#define A_BE2CPU16(x)      ntohs(x)
#define A_BE2CPU32(x)      ntohl(x)

#define A_LE2CPU8(x)       (x)
#define A_LE2CPU16(x)      (x)
#define A_LE2CPU32(x)      (x)

#define A_CPU2BE8(x)       htonb(x)
#define A_CPU2BE16(x)      htons(x)
#define A_CPU2BE32(x)      htonl(x)

#define A_MEMCPY(dst, src, len)         memcpy((A_UINT8 *)(dst), (src), (len))
#define A_MEMZERO(addr, len)            memset(addr, 0, len)
#define A_MEMSET(addr, value, size)     memset((addr), (value), (size))
#define A_MEMCMP(addr1, addr2, len)     memcmp((addr1), (addr2), (len))

#ifdef AR6K_ALLOC_DEBUG
#define a_meminfo_add(p, s)  __a_meminfo_add(p, s, __func__, __LINE)
#define a_mem_trace(ptr) __a_mem_trace(ptr, __func__, __LINE__)
void __a_mem_trace(void *ptr, const char *func, int lineno);
void __a_meminfo_add(void *ptr, size_t msize, const char *func, int lineno);
void  a_meminfo_del(void *ptr);
void* a_mem_alloc(size_t msize, int type, const char *func, int lineno);
void a_mem_free(void *ptr);
void a_meminfo_report(int clear);
#define A_MALLOC(size)                  a_mem_alloc((size), GFP_KERNEL, __func__, __LINE__)
#define A_MALLOC_NOWAIT(size)           a_mem_alloc((size), GFP_ATOMIC, __func__, __LINE__)
#define A_FREE(addr)                    a_mem_free(addr)
#define A_NETIF_RX(skb)                 do { a_meminfo_del(skb);  netif_rx(skb); } while (0)
#define A_NETIF_RX_NI(skb)              do { a_meminfo_del(skb);  netif_rx_ni(skb); } while (0)
#else
#define a_meminfo_report(_c)
#define A_MALLOC(size)                  kmalloc((size), GFP_KERNEL)
#define A_MALLOC_NOWAIT(size)           kmalloc((size), GFP_ATOMIC)
#define a_mem_trace(ptr)
#define A_FREE(addr)                    kfree(addr)
#define A_NETIF_RX(skb)                 netif_rx(skb)
#define A_NETIF_RX_NI(skb)              netif_rx_ni(skb)
#endif

#define OS_DMA_MALLOC(size)             kmalloc((size), GFP_ATOMIC)
#define OS_DMA_FREE(addr)               kfree(addr)

#define A_VMALLOC(size)                  vmalloc((size))
#define A_VFREE(addr)                    vfree(addr)
#if defined(ANDROID_ENV) && defined(CONFIG_ANDROID_LOGGER)
extern unsigned int enablelogcat;
extern int android_logger_lv(void* module, int mask);
enum logidx { LOG_MAIN_IDX = 0 };
extern int logger_write(const enum logidx idx, 
                const unsigned char prio,
                const char __kernel * const tag,
                const char __kernel * const fmt,
                ...);
#define A_ANDROID_PRINTF(mask, module, tags, args...) do {  \
    if (enablelogcat) \
        logger_write(LOG_MAIN_IDX, android_logger_lv(module, mask), tags, args); \
    else \
        printk(KERN_ALERT args); \
} while (0)
#ifdef DEBUG
#define A_LOGGER_MODULE_NAME(x) #x
#define A_LOGGER(mask, mod, args...) \
    A_ANDROID_PRINTF(mask, &GET_ATH_MODULE_DEBUG_VAR_NAME(mod), "ar6k_" A_LOGGER_MODULE_NAME(mod), args);
#endif 
#define A_PRINTF(args...) A_ANDROID_PRINTF(ATH_DEBUG_INFO, NULL, "ar6k_driver", args)
#else
#define A_LOGGER(mask, mod, args...)    printk(KERN_ALERT args)
#define A_PRINTF(args...)               printk(KERN_ALERT args)
#endif /* ANDROID */
#define A_PRINTF_LOG(args...)           printk(args)
#define A_SNPRINTF(buf, len, args...)	snprintf (buf, len, args)

/* Mutual Exclusion */
typedef spinlock_t                      A_MUTEX_T;
#define A_MUTEX_INIT(mutex)             spin_lock_init(mutex)
#define A_MUTEX_LOCK(mutex)             spin_lock_bh(mutex)
#define A_MUTEX_UNLOCK(mutex)           spin_unlock_bh(mutex)
#define A_IS_MUTEX_VALID(mutex)         TRUE  /* okay to return true, since A_MUTEX_DELETE does nothing */
#define A_MUTEX_DELETE(mutex)           /* spin locks are not kernel resources so nothing to free.. */

/* Get current time in ms adding a constant offset (in ms) */
#define A_GET_MS(offset)    \
	(((jiffies / HZ) * 1000) + (offset))

/*
 * Timer Functions
 */
#define A_MDELAY(msecs)                 mdelay(msecs)
#if LINUX_VERSION_CODE < KERNEL_VERSION(2,6,30)
#define A_MSLEEP(msecs)                                                    \
{                                                                          \
    set_current_state(TASK_INTERRUPTIBLE);                                 \
    if (!kthread_should_stop()) { schedule_timeout((HZ*(msecs)) / 1000); } \
    set_current_state(TASK_RUNNING);                                       \
}
#else
#define A_MSLEEP(msecs)                                                    \
{                                                                          \
    set_current_state(TASK_INTERRUPTIBLE);                                 \
    schedule_timeout((HZ * (msecs)) / 1000);                               \
    set_current_state(TASK_RUNNING);                                       \
}
#endif

typedef struct timer_list               A_TIMER;

#define A_INIT_TIMER(pTimer, pFunction, pArg) do {              \
    init_timer(pTimer);                                         \
    (pTimer)->function = (pFunction);                           \
    (pTimer)->data   = (unsigned long)(pArg);                   \
} while (0)

/*
 * Start a Timer that elapses after 'periodMSec' milli-seconds
 * Support is provided for a one-shot timer. The 'repeatFlag' is
 * ignored.
 */
#define A_TIMEOUT_MS(pTimer, periodMSec, repeatFlag) do {                   \
    if (repeatFlag) {                                                       \
        printk("\n" __FILE__ ":%d: Timer Repeat requested\n",__LINE__);     \
        panic("Timer Repeat");                                              \
    }                                                                       \
    mod_timer((pTimer), jiffies + HZ * (periodMSec) / 1000);                \
} while (0)

/*
 * Cancel the Timer. 
 */
#define A_UNTIMEOUT(pTimer) do {                                \
    del_timer((pTimer));                                        \
} while (0)

#define A_DELETE_TIMER(pTimer) do {                             \
} while (0)

/*
 * Wait Queue related functions
 */
typedef wait_queue_head_t               A_WAITQUEUE_HEAD;
#define A_INIT_WAITQUEUE_HEAD(head)     init_waitqueue_head(head)
#ifndef wait_event_interruptible_timeout
#define __wait_event_interruptible_timeout(wq, condition, ret)          \
do {                                                                    \
        wait_queue_t __wait;                                            \
        init_waitqueue_entry(&__wait, current);                         \
                                                                        \
        add_wait_queue(&wq, &__wait);                                   \
        for (;;) {                                                      \
                set_current_state(TASK_INTERRUPTIBLE);                  \
                if (condition)                                          \
                        break;                                          \
                if (!signal_pending(current)) {                         \
                        ret = schedule_timeout(ret);                    \
                        if (!ret)                                       \
                                break;                                  \
                        continue;                                       \
                }                                                       \
                ret = -ERESTARTSYS;                                     \
                break;                                                  \
        }                                                               \
        current->state = TASK_RUNNING;                                  \
        remove_wait_queue(&wq, &__wait);                                \
} while (0)

#define wait_event_interruptible_timeout(wq, condition, timeout)        \
({                                                                      \
        long __ret = timeout;                                           \
        if (!(condition))                                               \
                __wait_event_interruptible_timeout(wq, condition, __ret); \
        __ret;                                                          \
})
#endif /* wait_event_interruptible_timeout */

#define A_WAIT_EVENT_INTERRUPTIBLE_TIMEOUT(head, condition, timeout) do { \
    wait_event_interruptible_timeout(head, condition, timeout); \
} while (0)

#define A_WAKE_UP(head)                 wake_up(head)

#ifdef DEBUG
#ifdef A_SIMOS_DEVHOST
extern unsigned int panic_on_assert;
#define A_ASSERT(expr)  \
    if (!(expr)) {   \
        printk(KERN_ALERT"Debug Assert Caught, File %s, Line: %d, Test:%s \n",__FILE__, __LINE__,#expr); \
        if (panic_on_assert) panic(#expr);                                                               \
    }
#else
#define A_ASSERT(expr)  \
    if (!(expr)) {   \
        printk(KERN_ALERT "Debug Assert Caught, File %s, Line: %d, Test:%s \n",__FILE__, __LINE__,#expr); \
    }
#endif
#else
#define A_ASSERT(expr)
#endif /* DEBUG */

#ifdef ANDROID_ENV
struct firmware;
int android_request_firmware(const struct firmware **firmware_p, const char *filename,
                     struct device *device);
void android_release_firmware(const struct firmware *firmware);
#define A_REQUEST_FIRMWARE(_ppf, _pfile, _dev) android_request_firmware(_ppf, _pfile, _dev)
#define A_RELEASE_FIRMWARE(_pf) android_release_firmware(_pf)
#else
#define A_REQUEST_FIRMWARE(_ppf, _pfile, _dev) request_firmware(_ppf, _pfile, _dev)
#define A_RELEASE_FIRMWARE(_pf) release_firmware(_pf)
#endif 

/*
 * Initialization of the network buffer subsystem
 */
#define A_NETBUF_INIT()

/*
 * Network buffer queue support
 */
typedef struct sk_buff_head A_NETBUF_QUEUE_T;

#define A_NETBUF_QUEUE_INIT(q)  \
    a_netbuf_queue_init(q)

#define A_NETBUF_ENQUEUE(q, pkt) \
    a_netbuf_enqueue((q), (pkt))
#define A_NETBUF_PREQUEUE(q, pkt) \
    a_netbuf_prequeue((q), (pkt))
#define A_NETBUF_DEQUEUE(q) \
    (a_netbuf_dequeue(q))
#define A_NETBUF_QUEUE_SIZE(q)  \
    a_netbuf_queue_size(q)
#define A_NETBUF_QUEUE_EMPTY(q) \
    a_netbuf_queue_empty(q)

/*
 * Network buffer support
 */
#ifdef AR6K_ALLOC_DEBUG
#define A_NETBUF_ALLOC(size) \
    a_netbuf_alloc(size, __func__, __LINE__)
#define A_NETBUF_ALLOC_RAW(size) \
    a_netbuf_alloc_raw(size, __func__, __LINE__)
#define A_NETBUF_MANAGE(bufPtr) \
    a_netbuf_manage(bufPtr, __func__, __LINE__)  
#define A_NETBUF_UNMANAGE(bufPtr) \
    a_netbuf_unmanage(bufPtr)      
#else
#define A_NETBUF_ALLOC(size) \
    a_netbuf_alloc(size)
#define A_NETBUF_ALLOC_RAW(size) \
    a_netbuf_alloc_raw(size)
#define A_NETBUF_MANAGE(bufPtr)    
#define A_NETBUF_UNMANAGE(bufPtr)
#endif /* AR6K_ALLOC_DEBUG */
#define A_NETBUF_FREE(bufPtr) \
    a_netbuf_free(bufPtr)
#define A_NETBUF_DATA(bufPtr) \
    a_netbuf_to_data(bufPtr)
#define A_NETBUF_LEN(bufPtr) \
    a_netbuf_to_len(bufPtr)
#define A_NETBUF_PUSH(bufPtr, len) \
    a_netbuf_push(bufPtr, len)
#define A_NETBUF_PUT(bufPtr, len) \
    a_netbuf_put(bufPtr, len)
#define A_NETBUF_TRIM(bufPtr,len) \
    a_netbuf_trim(bufPtr, len)
#define A_NETBUF_PULL(bufPtr, len) \
    a_netbuf_pull(bufPtr, len)
#define A_NETBUF_HEADROOM(bufPtr)\
    a_netbuf_headroom(bufPtr)
#define A_NETBUF_SETLEN(bufPtr,len) \
    a_netbuf_setlen(bufPtr, len)

/* Add data to end of a buffer  */
#define A_NETBUF_PUT_DATA(bufPtr, srcPtr,  len) \
    a_netbuf_put_data(bufPtr, srcPtr, len) 

/* Add data to start of the  buffer */
#define A_NETBUF_PUSH_DATA(bufPtr, srcPtr,  len) \
    a_netbuf_push_data(bufPtr, srcPtr, len) 

/* Remove data at start of the buffer */
#define A_NETBUF_PULL_DATA(bufPtr, dstPtr, len) \
    a_netbuf_pull_data(bufPtr, dstPtr, len) 

/* Remove data from the end of the buffer */
#define A_NETBUF_TRIM_DATA(bufPtr, dstPtr, len) \
    a_netbuf_trim_data(bufPtr, dstPtr, len) 

/* View data as "size" contiguous bytes of type "t" */
#define A_NETBUF_VIEW_DATA(bufPtr, t, size) \
    (t )( ((struct skbuf *)(bufPtr))->data)

/* return the beginning of the headroom for the buffer */
#define A_NETBUF_HEAD(bufPtr) \
        ((((struct sk_buff *)(bufPtr))->head))
    
/* return the n-th fragmentation of the netbuf, beginning from 0 */
static inline A_STATUS
A_NETBUF_NTH_FRAG(void *nbuf, int n, void *buf, int *len)
{
    A_STATUS ret;

    A_ASSERT(nbuf);

    if (n == 0) {
        *(u_int32_t *)buf = (u_int32_t)((struct sk_buff *)nbuf)->data;
        *len = ((struct sk_buff *)nbuf)->len;
        ret = A_OK;
    } else {
        /* Assume only 1 fragmentation is possible for Linux now */
        ret = A_ERROR;
    }

    return ret;
}
    
/*
 * OS specific network buffer access routines
 */
#ifdef AR6K_ALLOC_DEBUG
void *a_netbuf_alloc(int size, const char *func, int lineno);
void *a_netbuf_alloc_raw(int size, const char *func, int lineno);
void a_netbuf_manage(void *bufPtr, const char *func, int lineno);
void a_netbuf_unmanage(void *bufPtr);
#else
void *a_netbuf_alloc(int size);
void *a_netbuf_alloc_raw(int size);
#endif
void a_netbuf_free(void *bufPtr);
void *a_netbuf_to_data(void *bufPtr);
A_UINT32 a_netbuf_to_len(void *bufPtr);
A_STATUS a_netbuf_push(void *bufPtr, A_INT32 len);
A_STATUS a_netbuf_push_data(void *bufPtr, char *srcPtr, A_INT32 len);
A_STATUS a_netbuf_put(void *bufPtr, A_INT32 len);
A_STATUS a_netbuf_put_data(void *bufPtr, char *srcPtr, A_INT32 len);
A_STATUS a_netbuf_pull(void *bufPtr, A_INT32 len);
A_STATUS a_netbuf_pull_data(void *bufPtr, char *dstPtr, A_INT32 len);
A_STATUS a_netbuf_trim(void *bufPtr, A_INT32 len);
A_STATUS a_netbuf_trim_data(void *bufPtr, char *dstPtr, A_INT32 len);
A_STATUS a_netbuf_setlen(void *bufPtr, A_INT32 len);
A_INT32 a_netbuf_headroom(void *bufPtr);
void a_netbuf_enqueue(A_NETBUF_QUEUE_T *q, void *pkt);
void a_netbuf_prequeue(A_NETBUF_QUEUE_T *q, void *pkt);
void *a_netbuf_dequeue(A_NETBUF_QUEUE_T *q);
int a_netbuf_queue_size(A_NETBUF_QUEUE_T *q);
int a_netbuf_queue_empty(A_NETBUF_QUEUE_T *q);
int a_netbuf_queue_empty(A_NETBUF_QUEUE_T *q);
void a_netbuf_queue_init(A_NETBUF_QUEUE_T *q);

/*
 * Kernel v.s User space functions
 */
A_UINT32 a_copy_to_user(void *to, const void *from, A_UINT32 n);
A_UINT32 a_copy_from_user(void *to, const void *from, A_UINT32 n);

/* In linux, WLAN Rx and Tx run in different contexts, so no need to check
 * for any commands/data queued for WLAN */
#define A_CHECK_DRV_TX()   
             
#define A_GET_CACHE_LINE_BYTES()    L1_CACHE_BYTES

#define A_CACHE_LINE_PAD            128

static inline void *A_ALIGN_TO_CACHE_LINE(void *ptr) {   
    return (void *)L1_CACHE_ALIGN((unsigned long)ptr);
}
   
typedef void __iomem *A_target_id_t;
extern void WAR_CE_SRC_RING_WRITE_IDX_SET(A_target_id_t, u_int32_t, unsigned int);
extern void WAR_PCI_WRITE32(char *addr, u32 offset, u32 value);
#ifdef QCA_PARTNER_PLATFORM

#include "ath_carr_pltfrm.h"

#else
#ifndef __ubicom32__
#define A_PCI_READ32(addr)         ioread32((void __iomem *)addr)
#if 0
#define A_PCI_WRITE32(addr, value) \
do { \
        iowrite32((u32)(value), (void __iomem *)(addr)); \
        ioread32((void __iomem *)(addr)); \
} while(0)
#else
#define A_PCI_WRITE32(addr, value) iowrite32((u32)(value), (void __iomem *)(addr))
#endif
#else
extern unsigned int ubi32_pci_read_u32(const volatile void *addr);
extern  void ubi32_pci_write_u32(unsigned int val, const volatile void *addr);
#define A_PCI_WRITE32(addr, value) do {	\
        ubi32_pci_write_u32((u32)(value), (void __iomem *)(addr)); \
} while(0)
#define  A_PCI_READ32(addr)                       \
        ubi32_pci_read_u32((void __iomem *)addr)
#endif
#endif /* QCA_PARTNER_PLATFORM */

typedef struct semaphore A_SEMA;
#define	A_SEMA_INIT(_sem, _val) sema_init((_sem), (_val))
static __inline__
void A_SEMA_WAKEUP(void *osdev, A_SEMA *sem)
{
    up(sem);
}
static __inline__
bool A_SEMA_SLEEP(void *osdev, A_SEMA *sem)
{
    return down_timeout(sem, HZ);
}


typedef struct ieee80211_cb wbuf_context;
#define wbuf_get_cb(skb)   ((skb)->cb)
/*
 * The following definitions are only relevant for low-latency systems,
 * where the MAC HW can directly access the host SW's buffers.
 */
#if defined(CONFIG_AR9888_SUPPORT) || defined(CONFIG_AR6320_SUPPORT) || defined(CONFIG_AR900B_SUPPORT) || defined(CONFIG_QCA9984_SUPPORT)|| defined(CONFIG_QCA9888_SUPPORT)

#ifndef A_MALLOC_CONSISTENT
  #ifndef A_SIMOS_DEVHOST
    #define A_MALLOC_CONSISTENT(dev, nbytes, dev_addr_ptr) \
        dma_alloc_coherent((dev), (nbytes), (dev_addr_ptr), 0)

  #else
    #define A_MALLOC_CONSISTENT(dev, nbytes, dev_addr_ptr) \
        (((*(dev_addr_ptr) = A_MALLOC(nbytes)) == NULL) ? \
            NULL : *(dev_addr_ptr))
  #endif
#endif /* A_MALLOC_CONSISTENT */

#ifndef A_FREE_CONSISTENT
  #ifndef A_SIMOS_DEVHOST
    #define A_FREE_CONSISTENT(dev, nbytes, addr, dev_addr) \
        dma_free_coherent((dev), (nbytes), (addr), (dev_addr))
  #else
    #define A_FREE_CONSISTENT(dev, nbytes, addr, dev_addr) A_FREE(addr)
  #endif
#endif /* A_FREE_CONSISTENT */

#ifndef A_DMA_MAP
  #ifndef A_SIMOS_DEVHOST
    #define A_DMA_MAP dma_map_single
  #else
    #define A_DMA_MAP(dev, addr, nbytes, dir) (addr)
  #endif
#endif /* A_DMA_MAP */

#ifndef A_DMA_MAP_ERR
  #ifndef A_SIMOS_DEVHOST
    #if LINUX_VERSION_CODE < KERNEL_VERSION(2,6,27)
      #define A_DMA_MAP_ERR(dev, addr) dma_mapping_error((addr))
    #else
      #define A_DMA_MAP_ERR(dev, addr) dma_mapping_error((dev), (addr))
    #endif
  #else
    #define A_DMA_MAP_ERR(dev, dev_addr) 0 /* no error */
  #endif
#endif /* A_DMA_MAP_ERR */

#ifndef A_DMA_UNMAP
  #ifndef A_SIMOS_DEVHOST
    #define A_DMA_UNMAP dma_unmap_single
  #else
    #define A_DMA_UNMAP(dev, addr, nbytes, dir)
  #endif
#endif /* A_DMA_UNMAP */

#define A_IOREMAP(addr, len) ioremap(addr, len)
#define A_IOUNMAP(addr) iounmap(addr)

#else
  /*
   * High-latency: DMA mapping is not applicable, but provide dummy
   * versions of the DMA macros, just so the code that calls these
   * macros can be the same for low vs. high-latency.
   *
   * FIX THIS: this code is supposed to be for high-latency, but it is
   * actually for "not Peregrine", which is not quite the same thing,
   * since Hera also supports PCIe.
   */
  #define A_DMA_MAP(dev, addr, nbytes, dir) (addr)
  #define A_DMA_MAP_ERR(dev, dev_addr) 0 /* no error */
  #define A_DMA_UNMAP(dev, addr, nbytes, dir)
  #define A_IOREMAP(addr, len)
  #define A_IOUNMAP(addr)
#endif /* CONFIG_AR9888_SUPPORT || CONFIG_AR6320_SUPPORT || CONFIG_AR900B_SUPPORT */

#else /* __KERNEL__ */

#ifdef __GNUC__
#define __ATTRIB_PACK           __attribute__ ((packed))
#define __ATTRIB_PRINTF         __attribute__ ((format (printf, 1, 2)))
#define __ATTRIB_NORETURN       __attribute__ ((noreturn))
#ifndef INLINE
#define INLINE                  __inline__
#endif
#else /* Not GCC */
#define __ATTRIB_PACK
#define __ATTRIB_PRINTF
#define __ATTRIB_NORETURN
#ifndef INLINE
#define INLINE                  __inline
#endif
#endif /* End __GNUC__ */

#define PREPACK
#define POSTPACK                __ATTRIB_PACK

#define A_MEMCPY(dst, src, len)         memcpy((dst), (src), (len))
#define A_MEMSET(addr, value, size)     memset((addr), (value), (size))
#define A_MEMZERO(addr, len)            memset((addr), 0, (len))
#define A_MEMCMP(addr1, addr2, len)     memcmp((addr1), (addr2), (len))
#define A_MALLOC(size)                  malloc(size)
#define A_FREE(addr)                    free(addr)


#ifdef ANDROID
#ifndef err
#include <errno.h>
#define err(_s, args...) do { \
    fprintf(stderr, "%s: line %d ", __FILE__, __LINE__); \
    fprintf(stderr, args); fprintf(stderr, ": %d\n", errno); \
    exit(_s); } while (0)
#endif
#else
#include <err.h>
#endif

#endif /* __KERNEL__ */

#endif /* _OSAPI_LINUX_H_ */
