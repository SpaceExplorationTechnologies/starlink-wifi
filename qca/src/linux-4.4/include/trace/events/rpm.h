
#undef TRACE_SYSTEM
#define TRACE_SYSTEM rpm

#if !defined(_TRACE_RUNTIME_POWER_H) || defined(TRACE_HEADER_MULTI_READ)
#define _TRACE_RUNTIME_POWER_H

#include <linux/ktime.h>
#include <linux/tracepoint.h>

struct device;

TRACE_EVENT(rpm_smd_ack_recvd,

	TP_PROTO(unsigned int irq, unsigned int msg_id, int errno),

	TP_ARGS(irq, msg_id, errno),

	TP_STRUCT__entry(
		__field(int, irq)
		__field(int, msg_id)
		__field(int, errno)
	),

	TP_fast_assign(
		__entry->irq = irq;
		__entry->msg_id = msg_id;
		__entry->errno = errno;
	),

	TP_printk("ctx:%s msg_id:%d errno:%08x",
		__entry->irq ? "noslp" : "sleep",
		__entry->msg_id,
		__entry->errno)
);

TRACE_EVENT(rpm_smd_interrupt_notify,

	TP_PROTO(char *dummy),

	TP_ARGS(dummy),

	TP_STRUCT__entry(
		__field(char *, dummy)
	),

	TP_fast_assign(
		__entry->dummy = dummy;
	),

	TP_printk("%s", __entry->dummy)
);

/*
 * The rpm_internal events are used for tracing some important
 * runtime pm internal functions.
 */
DECLARE_EVENT_CLASS(rpm_internal,

	TP_PROTO(struct device *dev, int flags),

	TP_ARGS(dev, flags),

	TP_STRUCT__entry(
		__string(       name,		dev_name(dev)	)
		__field(        int,            flags           )
		__field(        int ,   	usage_count	)
		__field(        int ,   	disable_depth   )
		__field(        int ,   	runtime_auto	)
		__field(        int ,   	request_pending	)
		__field(        int ,   	irq_safe	)
		__field(        int ,   	child_count 	)
	),

	TP_fast_assign(
		__assign_str(name, dev_name(dev));
		__entry->flags = flags;
		__entry->usage_count = atomic_read(
			&dev->power.usage_count);
		__entry->disable_depth = dev->power.disable_depth;
		__entry->runtime_auto = dev->power.runtime_auto;
		__entry->request_pending = dev->power.request_pending;
		__entry->irq_safe = dev->power.irq_safe;
		__entry->child_count = atomic_read(
			&dev->power.child_count);
	),

	TP_printk("%s flags-%x cnt-%-2d dep-%-2d auto-%-1d p-%-1d"
			" irq-%-1d child-%d",
			__get_str(name), __entry->flags,
			__entry->usage_count,
			__entry->disable_depth,
			__entry->runtime_auto,
			__entry->request_pending,
			__entry->irq_safe,
			__entry->child_count
		 )
);
DEFINE_EVENT(rpm_internal, rpm_suspend,

	TP_PROTO(struct device *dev, int flags),

	TP_ARGS(dev, flags)
);
DEFINE_EVENT(rpm_internal, rpm_resume,

	TP_PROTO(struct device *dev, int flags),

	TP_ARGS(dev, flags)
);
DEFINE_EVENT(rpm_internal, rpm_idle,

	TP_PROTO(struct device *dev, int flags),

	TP_ARGS(dev, flags)
);

DECLARE_EVENT_CLASS(rpm_send_msg,

	TP_PROTO(unsigned int msg_id, unsigned int rsc_type,
		unsigned int rsc_id),

	TP_ARGS(msg_id, rsc_type, rsc_id),

	TP_STRUCT__entry(
		__field(u32, msg_id)
		__field(u32, rsc_type)
		__field(u32, rsc_id)
		__array(char, name, 5)
	),

	TP_fast_assign(
		__entry->msg_id = msg_id;
		__entry->name[4] = 0;
		__entry->rsc_type = rsc_type;
		__entry->rsc_id = rsc_id;
		memcpy(__entry->name, &rsc_type, sizeof(uint32_t));

	),

	TP_printk("msg_id:%d, rsc_type:0x%08x(%s), rsc_id:0x%08x",
			__entry->msg_id,
			__entry->rsc_type, __entry->name,
			__entry->rsc_id)
);
DEFINE_EVENT(rpm_send_msg, rpm_smd_sleep_set,
	TP_PROTO(unsigned int msg_id, unsigned int rsc_type,
		unsigned int rsc_id),
	TP_ARGS(msg_id, rsc_type, rsc_id)
);

DEFINE_EVENT(rpm_send_msg, rpm_smd_send_sleep_set,
	TP_PROTO(unsigned int msg_id, unsigned int rsc_type,
		unsigned int rsc_id),
	TP_ARGS(msg_id, rsc_type, rsc_id)
);

DEFINE_EVENT(rpm_send_msg, rpm_smd_send_active_set,
	TP_PROTO(unsigned int msg_id, unsigned int rsc_type,
		unsigned int rsc_id),
	TP_ARGS(msg_id, rsc_type, rsc_id)
);

TRACE_EVENT(rpm_return_int,
	TP_PROTO(struct device *dev, unsigned long ip, int ret),
	TP_ARGS(dev, ip, ret),

	TP_STRUCT__entry(
		__string(       name,		dev_name(dev))
		__field(	unsigned long,		ip	)
		__field(	int,			ret	)
	),

	TP_fast_assign(
		__assign_str(name, dev_name(dev));
		__entry->ip = ip;
		__entry->ret = ret;
	),

	TP_printk("%pS:%s ret=%d", (void *)__entry->ip, __get_str(name),
		__entry->ret)
);

#endif /* _TRACE_RUNTIME_POWER_H */

/* This part must be outside protection */
#include <trace/define_trace.h>
