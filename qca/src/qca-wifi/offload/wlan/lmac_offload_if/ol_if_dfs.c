/*
 * Copyright (c) 2017 Qualcomm Innovation Center, Inc.
 *
 * All Rights Reserved.
 * Confidential and Proprietary - Qualcomm Innovation Center, Inc.
 *
 * Copyright (c) 2011, Atheros Communications Inc.
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

/*
 * LMAC offload interface functions for UMAC - for power and performance offload model
 */

#if ATH_SUPPORT_DFS

#include "ol_if_athvar.h"

#include "qdf_mem.h"   /* qdf_mem_malloc,free */
#include "qdf_lock.h"  /* qdf_spinlock_* */
#include "qdf_types.h" /* qdf_vprint */

#include "ath_dfs_structs.h"
#include "dfs_interface.h"

#include "ol_if_dfs.h"

#include "ol_regdomain.h"

#if ATH_PERF_PWR_OFFLOAD

/*
 * ic_dfs_attach - called by lmac/dfs/ to fetch the configuration
 * parameters.
 */
static int
ol_if_dfs_attach(struct ieee80211com *ic, void *ptr, void *radar_info)
{
	struct ath_dfs_caps *pCap = (struct ath_dfs_caps *) ptr;
	struct ol_ath_softc_net80211 *scn;
	scn = OL_ATH_SOFTC_NET80211(ic);

	qdf_print(KERN_INFO"%s: called; ptr=%pK, radar_info=%pK\n",
	    __func__,
	    ptr,
	    radar_info);

	pCap->ath_dfs_combined_rssi_ok = 0;
	pCap->ath_dfs_ext_chan_ok = 0;
	pCap->ath_dfs_use_enhancement = 0;
	pCap->ath_strong_signal_diversiry = 0; /* XXX? */
	pCap->ath_fastdiv_val = 0; /* XXX? */

	pCap->ath_chip_is_bb_tlv       = 1;
	pCap->ath_chip_is_over_sampled = 0;
	pCap->ath_chip_is_ht160        = 0;
        /*
            Disable check for strong OOB radar as this
            has side effect (IR 095628, 094131
            Set the capability to off (0) by default.
            We will turn this on once we have resolved
            issue with the fix
        */

	pCap->ath_chip_is_false_detect = 0;
        switch (scn->target_type) {
            case TARGET_TYPE_AR900B:
                break;

            case TARGET_TYPE_IPQ4019:
                pCap->ath_chip_is_false_detect = 0;
                break;

            case TARGET_TYPE_AR9888:
                /* Peregrine is over sampled */
	        pCap->ath_chip_is_over_sampled = 1;
                break;

            case TARGET_TYPE_QCA9984:
	    case TARGET_TYPE_QCA9888:
                /* Cascade and Besra supports 160MHz channel */
	        pCap->ath_chip_is_ht160 = 1;
            default:
                break;
        }
	/* XXX radar_info? */

	return(0);
}

/*
 * ic_dfs_detach - called by lmac/dfs to detach (?)
 */
static int
ol_if_dfs_detach(struct ieee80211com *ic)
{

	qdf_print("%s: called\n", __func__);
	return (0);	/* XXX error? */
}

/*
 * ic_dfs_attached
 */
static int
ol_if_dfs_attached(struct ieee80211com *ic)
{

#if	ATH_SUPPORT_DFS
	if (ic->ic_dfs) {
		return (1);
	} else {
		/* XXX why is it called here? */
		dfs_attach(ic);
		return (1);
	}
#else
	return (0);
#endif	/* ATH_SUPPORT_DFS */
}

/*
 * ic_dfs_enable - enable DFS
 *
 * For offload solutions, radar PHY errors will be enabled by the target
 * firmware when DFS is requested for the current channel.
 */
static int
ol_if_dfs_enable(struct ieee80211com *ic, int *is_fastclk, void *pe)
{

	qdf_print(KERN_DEBUG"%s: called\n", __func__);

	/*
	 * XXX For peregrine, treat fastclk as the "oversampling" mode.
	 *     It's on by default.  This may change at some point, so
	 *     we should really query the firmware to find out what
	 *     the current configuration is.
	 */
	(* is_fastclk) = 1;

//	ol_ath_phyerr_enable(ic);
      //ieee80211_dfs_cac_start(ic);
	return (0);
}

/*
 * ic_dfs_disable
 */
static int
ol_if_dfs_disable(struct ieee80211com *ic, int no_cac)
{
	qdf_print(KERN_DEBUG"%s: called\n", __func__);

	//ol_ath_phyerr_disable(ic);
	//dfs_radar_disable(ic);
	return (0);
}

/*
 * ic_dfs_get_thresholds
 */
static int
ol_if_dfs_get_thresholds(struct ieee80211com *ic,
    void *pe)
{
	/*
	 * XXX for now, the hardware has no API for fetching
	 * the radar parameters.
	 */
	struct ath_dfs_phyerr_param *param = (struct ath_dfs_phyerr_param *)pe;
	OS_MEMZERO(param, sizeof(*param));
	return(0);
}

/*
 * ic_get_ext_busy
 */
static int
ol_if_dfs_get_ext_busy(struct ieee80211com *ic)
{

	return (0);	/* XXX */
}

/*
 * ic_get_mib_cycle_counts_pct
 */
static int
ol_if_dfs_get_mib_cycle_counts_pct(struct ieee80211com *ic,
    u_int32_t *rxc_pcnt, u_int32_t *rxf_pcnt, u_int32_t *txf_pcnt)
{

	return (0);
}

/*
 * ic_dfs_control - dfs_control
 */

/*
 * ic_dfs_notify_radar - ieee80211_mark_dfs
 */

/*
 * ic_find_channel - ieee80211_find_channel
 */

/*
 * ic_dfs_unmark_radar - ieee80211_unmark_radar
 */

/*
 * (ic_get_ctl_by_country ?)
 */
#if 0
static u_int8_t
ol_if_get_ctl_by_country(struct ieee80211com *ic, u_int8_t *country,
    bool is2G)
{
	struct ath_softc_net80211 *scn = ATH_SOFTC_NET80211(ic);

	return (scn->sc_ops->get_ctl_by_country(scn->sc_dev, country, is2G));
}
#endif

/*
 * ic_dfs_isdfsregdomain
 */
static u_int16_t
ol_if_dfs_isdfsregdomain(struct ieee80211com *ic)
{
#if	ATH_SUPPORT_DFS
	return (dfs_isdfsregdomain(ic));
#else
	return (0);
#endif	/* ATH_SUPPORT_DFS */
}

static u_int16_t
ol_if_dfs_usenol(struct ieee80211com *ic)
{
#if	ATH_SUPPORT_DFS
	return(dfs_usenol(ic));
#else
	return (0);
#endif	/* ATH_SUPPORT_DFS */
}

/*
 * XXX this doesn't belong here, but the DFS code requires that it exists.
 * Please figure out how to fix this!
 */
static u_int64_t
ol_if_get_tsf64(struct ieee80211com *ic)
{
	/* XXX TBD */
	return (0);
}

/*
 * Update the channel list with the given NOL list.
 *
 * Since the NOL can contain entries which may match multiple
 * channels, we need to walk the channel list to ensure that
 * we correctly update _all_ channel entries in question.
 */
static void
ol_if_dfs_clist_update(struct ieee80211com *ic, int cmd,
    struct dfs_nol_chan_entry *nollist, int nentries)
{
	struct ieee80211_ath_channel *ichan;
	int i, j;
	int nol_found = 0;

	qdf_print("%s: called, cmd=%d, nollist=%pK, nentries=%d\n",
	    __func__, cmd, nollist, nentries);

	/* XXX for now, only handle DFS_NOL_CLIST_CMD_UPDATE. */
	if (cmd != DFS_NOL_CLIST_CMD_UPDATE) {
		qdf_print("%s: cmd=%d, not handled!\n", __func__, cmd);
		return;
	}

	ieee80211_enumerate_channels(ichan, ic, i) {
		/* XXX break into a shared function */
		nol_found = 0;
		for (j = 0; j < nentries; j++) {
			if (ieee80211_check_channel_overlap(ic, ichan,
			    nollist[j].nol_chfreq, nollist[j].nol_chwidth)) {
				nol_found = 1;
				/*
				 * XXX break here for now; but later on when
				 * we're keeping a NOL timer per umac channel,
				 * we'll want to walk _all_ the NOL entries
				 * to find the maximum NOL time we need; then
				 * potentially update the NOL time for that
				 * umac channel.
				 */
				break;
			}
		}

#if 0
		/*
		 * Dump out state transitions for now!
		 */
		if (nol_found && (! IEEE80211_IS_CHAN_RADAR(ichan)))
			qdf_print("%s: radar found = ichan=%pK, freq=%d, "
			    "vht freq1=%d, flags=0x%x\n",
			    __func__,
			    ichan,
			    ichan->ic_freq,
			    ieee80211_ieee2mhz(ichan->ic_vhtop_ch_freq_seg1,
			        ichan->ic_flags),
			    ichan->ic_flags);
		else if ((! nol_found) && IEEE80211_IS_CHAN_RADAR(ichan))
			qdf_print("%s: NOL clear = ichan=%pK, freq=%d, "
			    "vht freq1=%d, flags=0x%x\n",
			    __func__,
			    ichan,
			    ichan->ic_freq,
			    ieee80211_ieee2mhz(ichan->ic_vhtop_ch_freq_seg1,
			        ichan->ic_flags),
			    ichan->ic_flags);
#endif
		/*
		 * Now that we know whether there's a NOL entry overlapping
		 * this channel, let's set or clear the bits appropriately.
		 */
		if (nol_found) {
			IEEE80211_CHAN_SET_RADAR(ichan);
#if ATH_SUPPORT_DFS && ATH_SUPPORT_STA_DFS
			if(ic->ic_opmode == IEEE80211_M_STA &&
			(ieee80211com_has_cap_ext(ic,IEEE80211_CEXT_STADFS))) {
				/* The history information is permanent.
				* Do not clear the channel radar
				* history if "not_found" is false.
				*/
				IEEE80211_CHAN_SET_HISTORY_RADAR(ichan);
			}
#endif
		} else {
			IEEE80211_CHAN_CLR_RADAR(ichan);
		}
	}
    /*
     * Notify upper layer about the radar update event.
     * This may not be the right place to notify, but the NOL list
     * here is more accurate.
     */
    OSIF_RADIO_DELIVER_EVENT_RADAR_DETECTED(ic);
    ic->ic_flags |= IEEE80211_F_DFS_CHANSWITCH_PENDING;
}

/*
 * Extract the pulse parameters of the signal detected
 * as radar and send an indication to FW.
 */

int ol_ath_send_wmi_radar_found_to_fw(struct ieee80211com *ic,
        struct dfs_radar_found_params *radar_params)
{
    struct ol_ath_softc_net80211 *scn = OL_ATH_SOFTC_NET80211(ic);

    ic->ic_sent_wmi_dfs_radar_found = 1;

    return wmi_unified_radar_found_indication_to_fw_cmd(scn->wmi_handle,
            radar_params);
}

/*
 * Initiate a series of actions based on whether the radar detection
 * was  a failure (status = 1) or a success (spoof test [status=0] or
 * real radar [status =2]).
 */

void dfs_action_on_fw_radar_status_check(struct ieee80211com *ic,
        int dfs_status_check)
{
#define DFS_SET_USENOL 5
    struct ieee80211_dfs_state *dfs_state = &ic->ic_dfs_state;
    u_int error_flag = 0;
    int no_chans_avail = 0;
    int usenol = 1;

    qdf_print("%s: DFS Status Code =%d\n", __func__, dfs_status_check);
    OS_CANCEL_TIMER(&dfs_state->ath_dfs_fw_status_wait_timer);
    ic->ic_host_dfs_status_wait_timer_running = 0;

    switch (dfs_status_check)
    {
        case WMI_HOST_DFS_STATUS_CHECK_PASSED:
            {
                if (ic->ic_sent_wmi_dfs_radar_found) {
                    /* Received a status response from FW much before
                     * Host Timer expiry. spoof_chan ptr = cur_chan ptr
                     * indicates this. Re-start CAC and indicate spoof
                     * test done. Indication is to allow usenol = 0 from hereon.
                     */
                    ic->ic_spoof_test_done = 1;
                    if (ic->ic_radar_found_chan != NULL &&
                            ic->ic_radar_found_chan == ic->ic_curchan) {
                        /* IEEE80211_CHANCHANGE_MARKRADAR_SET flag is set in
                         * dfs_process_radar_event after radar_found.The flag
                         * is cleared after marking chan as radar & triggering
                         * a chan change.For this case,there is no chan change
                         * required. So clearing the flag here. If not done,
                         * any further chan change will be blocked.
                         */
                        IEEE80211_CHANCHANGE_MARKRADAR_CLEAR(ic);
                        qdf_print("%s:Restarting CAC on current channel:%d\n",
                                __func__, ic->ic_curchan->ic_ieee);
                        OS_CANCEL_TIMER(&dfs_state->cac_timer);
                        ieee80211_dfs_cac_start(ic);
                    } else {
                        /* Received a status response from FW after Host
                         * Timer expiry,indicated by different spoof_chan and
                         * cur_chan pointers.spoof_chan and cur_chan pointers
                         * have differed due to dfs_action (adding to NOL and
                         * chanchange triggered at the timer expiry. As spoof
                         * test is a success, removing the spoof chan that was
                         * added to NOL.
                         */
                        qdf_print("%s:Delayed Status: 0 received.."
                                "Removing from NOL\n",__func__);
                        ic->ic_dfs_remove_spoof_chan_from_nol(ic);
                    }
                } else {
                    error_flag = 1;
                }
                break;
            }

        case WMI_HOST_DFS_STATUS_CHECK_FAILED:
            {
                /* Spoof Test Failed. Rebuild ic channel list with non-DFS chans
                 * and restart all the vaps.
                 */
                qdf_print("%s: Spoof Check Failed, sent_radar_found: %d\n",__func__,ic->ic_sent_wmi_dfs_radar_found);
                /* Clear the flag to allow further chan change. This
                 * case also does not call dfs_action_on_radar_found.
                 */
                IEEE80211_CHANCHANGE_MARKRADAR_CLEAR(ic);
                /* This ic flag is to remember dfs check failed so that further
                 * channel changes does not choose DFS channels.
                 */
                ic->ic_spoof_dfs_check_failed = 1;
                if (ic->ic_tst_choose_random_chan == 0) {
                    qdf_print("%s:Building non-DFS channel list \n",__func__);
                    no_chans_avail = ic->ic_rebuild_chan_list_with_non_dfs_channels(ic);
                }
                ic->ic_restart_vaps_with_non_dfs_chan(ic,no_chans_avail);
                break;
            }

        case WMI_HOST_DFS_STATUS_CHECK_HW_RADAR:
            {
                if (ic->ic_sent_wmi_dfs_radar_found) {
                    if(ic->ic_radar_found_chan == ic->ic_curchan) {
                        qdf_print(" %s:Real radar action\n",__func__);
                        if (ic->ic_tst_disable_chanchange_post_radar_detect == 1) {
                            usenol = 0;
                            qdf_print("%s:Disabling channel change\n",__func__);
                            ic->ic_dfs_control(ic,DFS_SET_USENOL,&usenol,
                                    sizeof(u_int32_t),NULL,NULL);
                        }
                        ic->ic_dfs_action_on_radar_found(ic);
                    } else {
                        qdf_print("%s: DFS Action taken on host timer expiry!\n",__func__);
                    /* Else of this case, no action is needed as dfs_action
                     * would have been done at timer expiry itself.
                     */}
                } else {
                    error_flag = 1;
                }
                break;
            }
        default:
            qdf_print("%d..Status event mismatch, Ignoring it \n",
                    dfs_status_check);
    }
    ic->ic_sent_wmi_dfs_radar_found = 0;
    ic->ic_radar_found_chan = NULL;
    if (error_flag == 1) {
        qdf_print(" %s:Received a response from FW when Host"
                "has not sent any indication.. Discarding it\n",__func__);
    }
}

int
ol_ath_wmi_dfs_status_check_event_handler(ol_scn_t sc, u_int8_t *data,
        u_int16_t datalen)
{
    struct ol_ath_softc_net80211 *scn = (struct ol_ath_softc_net80211 *)sc;
    struct ieee80211com  *ic = &scn->sc_ic;
    u_int32_t dfs_status_check;

    if (wmi_extract_dfs_status_from_fw(scn->wmi_handle, data,
                &dfs_status_check)) {
        qdf_print("Failed to extract status response from FW\n");
        return -1;
    }
    dfs_action_on_fw_radar_status_check(ic, dfs_status_check);
    return 0;
}
/*
 * ol_if_dfs_attach() - attach DFS methods to the umac state.
 */
extern int dfs_disable;
void
ol_if_dfs_setup(struct ieee80211com *ic)
{

	qdf_print(KERN_DEBUG"%s: called \n", __func__);

	/* DFS pattern matching hooks */
	ic->ic_dfs_attach = ol_if_dfs_attach;
	ic->ic_dfs_detach = ol_if_dfs_detach;
	ic->ic_dfs_attached = ol_if_dfs_attached;
	ic->ic_dfs_enable = ol_if_dfs_enable;
	ic->ic_dfs_disable = ol_if_dfs_disable;
	ic->ic_dfs_get_thresholds = ol_if_dfs_get_thresholds;
	ic->ic_dfs_control = dfs_control;	/* Direct ref to module */
	//ic->ic_get_ctl_by_country = ol_if_get_ctl_by_country;
	ic->ic_dfs_chan_in_nol = dfs_chan_in_nol;

	/* NOL related hooks */
	ic->ic_dfs_isdfsregdomain = ol_if_dfs_isdfsregdomain;
	ic->ic_dfs_usenol = ol_if_dfs_usenol;
	ic->ic_dfs_getnol = dfs_getnol;
#if ATH_SUPPORT_DFS && ATH_SUPPORT_STA_DFS
	ic->ic_dfs_print_nolhistory = ieee80211_print_nolhistory;
	ic->ic_dfs_clear_nolhistory = ieee80211_clear_nolhistory;
#endif
	ic->ic_dfs_clist_update = ol_if_dfs_clist_update;

	/*
	 * Hooks from lmac/dfs/ back -into- the umac and shared DFS code
	 * (currently umac/if_lmac/if_ath_dfs.c)
	 */
	ic->ic_dfs_notify_radar = ieee80211_mark_dfs;
	ic->ic_channel_notify_to_app = ieee80211_channel_notify_to_app;
#if ATH_SUPPORT_ETSI_CAC_DFS
	ic->ic_dfs_notify_etsi_precac_radar = ieee80211_mark_etsi_precac_dfs;
#endif

#if ATH_SUPPORT_ZERO_CAC_DFS
	ic->ic_dfs_print_precaclists = ieee80211_print_precaclists;
	ic->ic_dfs_reset_precaclist = ieee80211_reset_precaclists;
	ic->ic_dfs_notify_precac_radar = ieee80211_mark_precac_dfs;
	ic->ic_dfs_cancel_precac_timer = ieee80211_dfs_cancel_precac_timer;
	ic->ic_dfs_is_precac_timer_running = ieee80211_is_precac_timer_running;
	ic->ic_dfs_find_precac_secondary_vht80_chan = ieee80211_dfs_find_precac_secondary_vht80_chan;
	ic->ic_get_nol_timeout = dfs_get_nol_timeout;
#endif
	ic->ic_dfs_send_rcsa  = ieee80211_send_rcsa;
	ic->ic_dfs_rx_rcsa   = dfs_rx_rcsa;
	ic->ic_dfs_cancel_waitfor_csa_timer  = dfs_cancel_waitfor_csa_timer;
	ic->ic_dfs_unmark_radar = ieee80211_unmark_radar;
	ic->ic_start_csa = ieee80211_start_csa;
	ic->ic_bringup_ap_vaps = ieee80211_bringup_ap_vaps;
	ic->ic_random_channel = ieee80211_random_channel;

	/* Hardware facing hooks */
	ic->ic_get_ext_busy = ol_if_dfs_get_ext_busy;
	ic->ic_get_mib_cycle_counts_pct = ol_if_dfs_get_mib_cycle_counts_pct;
	ic->ic_get_TSF64 = ol_if_get_tsf64;

	ic->ic_dfs_state.ignore_dfs = dfs_disable;

	ic->ic_wmi_radar_found_indication_to_fw = ol_ath_send_wmi_radar_found_to_fw;
	ic->ic_dfs_remove_spoof_chan_from_nol = dfs_remove_spoof_chan_from_nol;
	ic->ic_restart_vaps_with_non_dfs_chan =
		ieee80211_restart_vaps_with_non_dfs_channels;
	ic->ic_rebuild_chan_list_with_non_dfs_channels =
		ieee80211_rebuild_ic_chan_list_with_non_dfs_channels;
#if QCA_DFS_NOL_VAP_RESTART
        ic->ic_bringup_ap_vaps_after_nol = ieee80211_bringup_ap_vaps_after_nol;
#endif

	/* Initial DFS pattern matching attach */
	dfs_attach(ic);
}

void
ol_if_dfs_teardown(struct ieee80211com *ic)
{
    qdf_print(KERN_INFO"%s: called \n", __func__);
	dfs_detach(ic);
}

/* The following are for FCC Bin 1-4 pulses */
struct dfs_pulse dfs_fcc_radars[] = {
    // FCC TYPE 1
    // {18,  1,  325, 1930, 0,  6,  7,  0,  1, 18,  0, 3,  0}, // 518 to 3066
    {18,  1,  700, 700, 0,  4,  5,  0,  1, 18,  0, 3,  1, 5, 0, 0},
    {18,  1,  350, 350, 0,  4,  5,  0,  1, 18,  0, 3,  0, 5, 0, 0},

    // FCC TYPE 6
    // {9,   1, 3003, 3003, 1,  7,  5,  0,  1, 18,  0, 0,  1}, // 333 +/- 7 us
    {9,   1, 3003, 3003, 1,  7,  5,  0,  1, 18,  0, 0,  1, 1000, 0, 1},
    // FCC TYPE 2
    {23, 5, 4347, 6666, 0,  4, 11,  0,  7, 22,  0, 3,  0, 5, 0, 2},
    // FCC TYPE 3
    {18, 10, 2000, 5000, 0,  4,  8,  6, 13, 22,  0, 3, 0, 5, 0, 5},

    // FCC TYPE 4
    {16, 15, 2000, 5000, 0,  4,  7, 11, 23, 22,  0, 3, 0, 5, 0, 11},

    {57, 1, 1066, 1930, 0, 4,  20,  0,  1, 22,  0, 3,  0, 5, 0, 21}, // 518us to 938us pulses (min 56 pulses)

    {27, 1,  500, 1066, 0, 4,  13,  0,  1, 22,  0, 3,  0, 5, 0, 22}, // 938us to 2000 pulses (min 26 pulses)
    {18, 1,  325,  500, 0, 4,  9,   0,  1, 22,  0, 3,  0, 5, 0, 23}, //  2000 to 3067us pulses (min 17 pulses)
};

struct dfs_pulse dfs_mkk4_radars[] = {
    /* following two filters are specific to Japan/MKK4 */
//    {18,  1,  720,  720, 1,  6,  6,  0,  1, 18,  0, 3, 17}, // 1389 +/- 6 us
//    {18,  4,  250,  250, 1, 10,  5,  1,  6, 18,  0, 3, 18}, // 4000 +/- 6 us
//    {18,  5,  260,  260, 1, 10,  6,  1,  6, 18,  0, 3, 19}, // 3846 +/- 7 us

    /* following filters are common to both FCC and JAPAN */
    {18,  1,  720,  720, 0,  4,  6,  0,  1, 18,  0, 3, 0, 5, 0, 17}, // 1389 +/- 6 us
    {18,  4,  250,  250, 0,  4,  5,  1,  6, 18,  0, 3, 0, 5, 0, 18}, // 4000 +/- 6 us
    {18,  5,  260,  260, 0,  4,  6,  1,  6, 18,  0, 3, 1, 5, 0, 19}, // 3846 +/- 7 us

    // FCC TYPE 1
    // {18,  1,  325, 1930, 0,  6,  7,  0,  1, 18,  0, 3,  0}, // 518 to 3066
    {18,  1,  700, 700, 0,  4,  5,  0,  1, 18,  0, 3,  1, 5, 0, 0},
    {18,  1,  350, 350, 0,  4,  5,  0,  1, 18,  0, 3,  0, 5, 0, 0},

    // FCC TYPE 6
    // {9,   1, 3003, 3003, 1,  7,  5,  0,  1, 18,  0, 0,  1}, // 333 +/- 7 us
    {9,   1, 3003, 3003, 1,  7,  5,  0,  1, 18,  0, 0, 1,  1000, 0, 1},

    // FCC TYPE 2
   {23, 5, 4347, 6666, 0,  4, 11,  0,  7, 22,  0, 3,  0, 5, 0, 2},

    // FCC TYPE 3
    {18, 10, 2000, 5000, 0,  4,  8,  6, 13, 22,  0, 3, 0, 5, 0, 5},

    // FCC TYPE 4
    {16, 15, 2000, 5000, 0,  4,  7, 11, 23, 22,  0, 3, 0, 5, 0, 11},
};

struct dfs_bin5pulse dfs_fcc_bin5pulses[] = {
        {5, 28, 105, 12, 22, 5},
};

struct dfs_bin5pulse dfs_jpn_bin5pulses[] = {
        {5, 28, 105, 12, 22, 5},
};

/*
  WAR : IR 42631
  Beeliner 2 is tested at -65dbm as opposed to -62 dbm.
  For FCC/JPN chirping pulses, HW reports RSSI value that is lower by 2dbm when
  we enable noise floor claibration. This is specially true for frequencies that
  are greater than center frequency and in VHT80 mode.
*/

struct dfs_bin5pulse dfs_fcc_bin5pulses_ar900b[] = {
        {5, 28, 105, 12, 12, 5},
};

struct dfs_bin5pulse dfs_jpn_bin5pulses_ar900b[] = {
        {5, 28, 105, 12, 20, 5},
};

/*
  WAR : IR 83400
  Cascade is tested at -65dbm as opposed to -62 dbm.
  For FCC/JPN chirping pulses, HW reports RSSI value that is significantly lower
  at left edge especially in HT80_80 mode. Also, duration may be significantly low.
  This can result in false detection and we may have to raise the threshold
*/

struct dfs_bin5pulse dfs_fcc_bin5pulses_qca9984[] = {
        {5, 20, 105, 12, 20, 0},
};

struct dfs_bin5pulse dfs_jpn_bin5pulses_qca9984[] = {
        {5, 20, 105, 12, 20, 0},
};

struct dfs_pulse dfs_etsi_radars[] = {

    /* EN 302 502 frequency hopping pulse */
    /* PRF 3000, 1us duration, 9 pulses per burst */
    {9,   1, 3000, 3000, 1,  4,  5,  0,  1, 18,  0, 0, 1,  1000, 0, 40},
    /* PRF 4500, 20us duration, 9 pulses per burst */
    {9,  20, 4500, 4500, 1,  4,  5, 19, 21, 18,  0, 0, 1,  1000, 0, 41},

    /* TYPE staggered pulse */
    /* 0.8-2us, 2-3 bursts,300-400 PRF, 10 pulses each */
    {30,  2,  300,  400, 2, 30,  3,  0,  5, 15, 0,   0, 1, 5, 0, 31},   /* Type 5*/
    /* 0.8-2us, 2-3 bursts, 400-1200 PRF, 15 pulses each */
    {30,  2,  400, 1200, 2, 30,  7,  0,  5, 15, 0,   0, 0, 5, 0, 32},   /* Type 6 */
    /* constant PRF based */
    /* 0.8-5us, 200  300 PRF, 10 pulses */
    {10, 5,   200,  400, 0,  4,  5,  0,  8, 15, 0,   0, 2, 5, 0, 33},   /* Type 1 */
    {10, 5,   400,  600, 0,  4,  5,  0,  8, 15, 0,   0, 2, 5, 0, 37},   /* Type 1 */
    {10, 5,   600,  800, 0,  4,  5,  0,  8, 15, 0,   0, 2, 5, 0, 38},   /* Type 1 */
    {10, 5,   800, 1000, 0,  4,  5,  0,  8, 15, 0,   0, 2, 5, 0, 39},   /* Type 1 */
//  {10, 5,   200, 1000, 0,  6,  5,  0,  8, 15, 0,   0, 2, 5, 33},

    /* 0.8-15us, 200-1600 PRF, 15 pulses */
    {15, 15,  200, 1600, 0,  4, 8,  0, 18, 24, 0,   0, 0, 5, 0, 34},    /* Type 2 */

    /* 0.8-15us, 2300-4000 PRF, 25 pulses*/
    {25, 15, 2300, 4000, 0,  4, 10, 0, 18, 24, 0,   0, 0, 5, 0, 35},   /* Type 3 */

    /* 20-30us, 2000-4000 PRF, 20 pulses*/
    {20, 30, 2000, 4000, 0,  4, 6, 19, 33, 24, 0,   0, 0, 24,  1, 36},    /* Type 4 */
};

struct dfs_pulse dfs_china_radars[] = {

    /* TYPE staggered pulse */
    /* 0.8-2us, 2-3 bursts,300-400 PRF, 12 pulses each */
    {36,  2,  300,  400, 2, 30,  3,  0,  5, 15, 0,   0, 1, 51},   /* Type 5*/
    /* 0.8-2us, 2-3 bursts, 400-1200 PRF, 16 pulses each */
    {48,  2,  400, 1200, 2, 30,  7,  0,  5, 15, 0,   0, 0, 52},   /* Type 6 */

    /* constant PRF based */
    /* 0.5-5us, 200  1000 PRF, 12 pulses */
    {12, 5,   200,  400, 0, 24,  5,  0,  8, 15, 0,   0, 2, 53},   /* Type 1 */
    {12, 5,   400,  600, 0, 24,  5,  0,  8, 15, 0,   0, 2, 57},   /* Type 1 */
    {12, 5,   600,  800, 0, 24,  5,  0,  8, 15, 0,   0, 2, 58},   /* Type 1 */
    {12, 5,   800, 1000, 0, 24,  5,  0,  8, 15, 0,   0, 2, 59},   /* Type 1 */
//  {10, 5,   200, 1000, 0, 24,  5,  0,  8, 15, 0,   0, 2, 33},

    /* 0.5-15us, 200-1600 PRF, 16 pulses */
    {16, 15,  200, 1600, 0, 24, 8,  0, 18, 24, 0,   0, 0, 54},    /* Type 2 */

    /* 0.5-30us, 2300-4000 PRF, 24 pulses*/
    {24, 15, 2300, 4000,  0, 24, 10, 0, 33, 24, 0,   0, 0, 55},   /* Type 3 */

    /* 20-30us, 2000-4000 PRF, 20 pulses*/
    {20, 30, 2000, 4000, 0, 24, 6, 19, 33, 24, 0,   0, 0, 56},    /* Type 4 */

    /* 1us, 1000 PRF, 20 pulses */
    {20,  1, 1000, 1000, 0,  6,  6,  0,  1, 18,  0, 3, 0, 50},    /* 1000 us PRI */
};
struct dfs_pulse dfs_korea_radars[] = {
    {18,  1,  700, 700,  0, 4,  5,  0,  1, 18,  0, 3,  1, 5, 0, 40}, /* Korea Type 1 */
    {10,  1, 1800, 1800, 0, 4,  4,  0,  1, 18,  0, 3,  1, 5, 0, 41}, /* Korea Type 2 */
    {70,  1,  330, 330,  0, 4, 20,  0,  2, 18,  0, 3,  1, 5, 0, 42}, /* Korea Type 3 */
    {3,   1, 3003, 3003, 1, 7,  2,  0,  1, 18,  0, 0, 1,  1000, 0, 43}, /* Korea Type 4 */
    //{3,   1, 3003, 3003, 1, 7,  2,  0,  1, 18,  0, 0, 1,  43}, /* Korea Type 4 */
};

#define RSSI_THERSH_AR900B 15
/*
 * This is called during a channel change or regulatory domain
 * reset; in order to fetch the new configuration information and
 * program the DFS pattern matching module.
 *
 * Eventually this should be split into "fetch config" (which can
 * happen at regdomain selection time) and "configure DFS" (which
 * can happen at channel config time) so as to minimise overheads
 * when doing channel changes.  However, this'll do for now.
 */

static inline bool is_valid_5_8GHz_channel(int curfreq)
{
    if((curfreq >= 5745) && (curfreq <= 5865))
        return true;
    else
        return false;
}

void
ol_if_dfs_configure(struct ieee80211com *ic)
{
#define  ETSI_LEGACY_PULSE_ARR_OFFSET 2
	struct ath_dfs_radar_tab_info rinfo;
	int dfsdomain = DFS_FCC_DOMAIN;
	struct ol_ath_softc_net80211 *scn;
	struct ol_regdmn *ol_regdmn_handle;
	int i;
	int curfreq=ic->ic_curchan->ic_freq;

	qdf_print(KERN_DEBUG"%s: called\n", __func__);

	/* Fetch current radar patterns from the lmac */
	OS_MEMZERO(&rinfo, sizeof(rinfo));

	/*
	 * Look up the current DFS regulatory domain and decide
	 * which radar pulses to use.
	 */
	/* XXX TODO: turn this into a function! */
	scn = OL_ATH_SOFTC_NET80211(ic);
	ol_regdmn_handle = scn->ol_regdmn_handle;
	dfsdomain = ol_regdmn_handle->ol_regdmn_dfsDomain;


	switch (dfsdomain) {
		case DFS_FCC_DOMAIN:
			qdf_print(KERN_INFO"%s: FCC domain\n", __func__);
			rinfo.dfsdomain = DFS_FCC_DOMAIN;
			    rinfo.dfs_radars = dfs_fcc_radars;
			    rinfo.numradars = ARRAY_LENGTH(dfs_fcc_radars);

                            if (scn->target_type == TARGET_TYPE_AR900B || scn->target_type == TARGET_TYPE_IPQ4019) {
			        rinfo.b5pulses = dfs_fcc_bin5pulses_ar900b;
			        rinfo.numb5radars = ARRAY_LENGTH(dfs_fcc_bin5pulses_ar900b);
                            } else if (scn->target_type == TARGET_TYPE_QCA9984 || scn->target_type == TARGET_TYPE_QCA9888) {
			        rinfo.b5pulses = dfs_fcc_bin5pulses_qca9984;
			        rinfo.numb5radars = ARRAY_LENGTH(dfs_fcc_bin5pulses_qca9984);
                            }else {
			        rinfo.b5pulses = dfs_fcc_bin5pulses;
			        rinfo.numb5radars = ARRAY_LENGTH(dfs_fcc_bin5pulses);
                            }
                 
			break;
		case DFS_ETSI_DOMAIN:
			qdf_print("%s: ETSI domain\n", __func__);
			rinfo.dfsdomain = DFS_ETSI_DOMAIN;

			if((ol_regdmn_handle->ol_regdmn_current_rd == ETSI11_WORLD ||
                ol_regdmn_handle->ol_regdmn_current_rd == ETSI12_WORLD ||
                ol_regdmn_handle->ol_regdmn_current_rd == ETSI13_WORLD ||
                ol_regdmn_handle->ol_regdmn_current_rd == ETSI14_WORLD) &&
                            is_valid_5_8GHz_channel(curfreq)){
				rinfo.dfs_radars = dfs_etsi_radars;
				rinfo.numradars = ARRAY_LENGTH(dfs_etsi_radars);
			} else {
				uint8_t offset = ETSI_LEGACY_PULSE_ARR_OFFSET;
				rinfo.dfs_radars =&dfs_etsi_radars[offset];
				rinfo.numradars = ARRAY_LENGTH(dfs_etsi_radars) - offset;
			}


			rinfo.b5pulses = NULL;
			rinfo.numb5radars = 0;
			break;
		case DFS_MKK4_DOMAIN:
			qdf_print("%s: MKK4 domain\n", __func__);
			rinfo.dfsdomain = DFS_MKK4_DOMAIN;
			rinfo.dfs_radars = dfs_mkk4_radars;
			rinfo.numradars = ARRAY_LENGTH(dfs_mkk4_radars);

                        if (scn->target_type == TARGET_TYPE_AR900B || scn->target_type == TARGET_TYPE_IPQ4019) {
			    rinfo.b5pulses = dfs_jpn_bin5pulses_ar900b;
			    rinfo.numb5radars = ARRAY_LENGTH(dfs_jpn_bin5pulses_ar900b);
                        } else if (scn->target_type == TARGET_TYPE_QCA9984 || scn->target_type == TARGET_TYPE_QCA9888) {
			    rinfo.b5pulses = dfs_jpn_bin5pulses_qca9984;
			    rinfo.numb5radars = ARRAY_LENGTH(dfs_jpn_bin5pulses_qca9984);
                        } else {
			    rinfo.b5pulses = dfs_jpn_bin5pulses;
			    rinfo.numb5radars = ARRAY_LENGTH(dfs_jpn_bin5pulses);
                        }
			break;
		case DFS_CN_DOMAIN:
			qdf_print("%s: CN domain\n", __func__);
			rinfo.dfsdomain = DFS_CN_DOMAIN;
			rinfo.dfs_radars = dfs_china_radars;
			rinfo.numradars = ARRAY_LENGTH(dfs_china_radars);
			rinfo.b5pulses = NULL;
			rinfo.numb5radars = 0;
			break;
		case DFS_KR_DOMAIN:
			qdf_print("%s: KR domain\n", __func__);
			rinfo.dfsdomain = DFS_KR_DOMAIN;
			rinfo.dfs_radars = dfs_korea_radars;
			rinfo.numradars = ARRAY_LENGTH(dfs_korea_radars);
			rinfo.b5pulses = NULL;
			rinfo.numb5radars = 0;
			break;
		default:
			qdf_print("%s: UNINIT domain\n", __func__);
			rinfo.dfsdomain = DFS_UNINIT_DOMAIN;
			rinfo.dfs_radars = NULL;
			rinfo.numradars = 0;
			rinfo.b5pulses = NULL;
			rinfo.numb5radars = 0;
			return;
	}

        if (scn->target_type == TARGET_TYPE_AR900B || 
            scn->target_type == TARGET_TYPE_IPQ4019 ||
            scn->target_type == TARGET_TYPE_QCA9984 ||
	    scn->target_type == TARGET_TYPE_QCA9888) {
        /* Beeliner WAR: lower RSSI threshold to improve detection of
           certian radar types
        */
        /* Cascade WAR:
                Cascade can report lower RSSI near the channel boundary then expected.
                It can also report significantly low RSSI at center (as low as 16) at
                center. So we are lowering threshold for all types of radar for
                Cascade.
                This may increase the possibility of false radar detection.
                IR -- 083703, 083398, 083387
        */

                for (i = 0; i < rinfo.numradars; i++) {
                        rinfo.dfs_radars[i].rp_rssithresh = RSSI_THERSH_AR900B;
                }

        }


	/* XXX dfs_defaultparams */

	/*
	 * Set the regulatory domain, radar pulse table and enable
	 * radar events if required.
	 */
	dfs_radar_enable(ic, &rinfo, 0);
}

#endif /* ATH_PERF_PWR_OFFLOAD */

#else /* ATH_SUPPORT_DFS */
void
ol_if_dfs_configure(struct ieee80211com *ic)
{
    return;
}

#endif /* ATH_SUPPORT_DFS */
