obj-$(CONFIG_QCOM_GSBI)	+=	qcom_gsbi.o
obj-$(CONFIG_QCOM_PM)	+=	spm.o
obj-$(CONFIG_QCOM_SMD) +=	smd.o
obj-$(CONFIG_QCOM_SMD_RPM)	+= smd-rpm.o
obj-$(CONFIG_QCOM_SMEM) +=	smem.o
obj-$(CONFIG_QCOM_SMEM_STATE) += smem_state.o
obj-$(CONFIG_QCOM_SMP2P)	+= smp2p.o
obj-$(CONFIG_MSM_SMEM)	+=	msm_smem.o
obj-$(CONFIG_MSM_GLINK)	+=	glink.o glink_debugfs.o glink_ssr.o
obj-$(CONFIG_MSM_GLINK_LOOPBACK_SERVER)	+=	glink_loopback_server.o
obj-$(CONFIG_MSM_GLINK_SMEM_NATIVE_XPRT)+=	glink_smem_native_xprt.o
obj-$(CONFIG_MSM_GLINK_PKT)	+=	msm_glink_pkt.o
obj-$(CONFIG_MSM_IPC_ROUTER_GLINK_XPRT)	+=	ipc_router_glink_xprt.o
obj-$(CONFIG_IPC_ROUTER)	+=	ipc_router/
obj-$(CONFIG_MSM_QMI_INTERFACE)	+=	qmi_interface.o
obj-$(CONFIG_MSM_RPM_GLINK)	+=	rpm-glink.o
obj-$(CONFIG_MSM_RPM_LOG)	+=	rpm_log.o
obj-$(CONFIG_QCOM_RESTART_REASON) += restart_reason.o
obj-$(CONFIG_MSM_IPC_ROUTER_MHI_XPRT) += ipc_router_mhi_xprt.o

obj-$(CONFIG_MSM_TEST_QMI_CLIENT) += qmi_test.o
qmi_test-y += kernel_test_service_v01.o test_qmi_client.o

ifdef CONFIG_QCOM_SCM
obj-$(CONFIG_ARM64) += cpu_ops.o cpu_pwr_ctl.o
endif
obj-$(CONFIG_IPQ_TCSR)	+=	ipq_tcsr.o

obj-$(CONFIG_QCOM_CACHE_DUMP) += cache_dump.o
obj-$(CONFIG_QCOM_MEMORY_DUMP_V2) += memory_dump_v2.o

ifdef CONFIG_IPQ_SUBSYSTEM_RESTART
	obj-y += subsystem_notif.o
	obj-y += subsystem_restart.o
	obj-y += ramdump.o
	obj-$(CONFIG_IPQ_SUBSYSTEM_RESTART_TEST) += testssr.o
endif

obj-$(CONFIG_QCOM_TZ_LOG) += tz_log.o
