/*
 * Copyright (c) 2014 - 2018, The Linux Foundation. All rights reserved.
 *
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
 */

#include <linux/platform_device.h>
#include <linux/if_vlan.h>
#include <linux/kernel.h>
#include <asm/atomic.h>
#include "ess_edma.h"
#include "edma.h"

extern struct net_device *edma_netdev[EDMA_MAX_PORTID_SUPPORTED];
extern u32 edma_disable_queue_stop;

bool edma_stp_rstp;
u16 edma_ath_eth_type;
extern u8 edma_dscp2ac_tbl[EDMA_PRECEDENCE_MAX];
extern u8 edma_per_prec_stats_enable;
extern u32 edma_iad_stats_enable;

/* edma_skb_priority_offset()
 *	get edma skb priority
 */
static unsigned int edma_skb_priority_offset(struct sk_buff *skb)
{
	return (skb->priority >> 2) & 1;
}

/* edma_alloc_tx_ring()
 *	Allocate Tx descriptors ring
 */
static int edma_alloc_tx_ring(struct edma_common_info *edma_cinfo,
			      struct edma_tx_desc_ring *etdr)
{
	struct platform_device *pdev = edma_cinfo->pdev;
	u16 sw_size = sizeof(struct edma_sw_desc) * etdr->count;

	/* Initialize ring */
	etdr->size = sizeof(struct edma_tx_desc) * etdr->count;
	etdr->sw_next_to_fill = 0;
	etdr->sw_next_to_clean = 0;

	/* Allocate SW descriptors */
	etdr->sw_desc = vzalloc(sw_size);
	if (!etdr->sw_desc) {
		dev_err(&pdev->dev, "buffer alloc of tx ring failed=%p", etdr);
		return -ENOMEM;
	}

	/* Allocate HW descriptors */
	etdr->hw_desc = dma_alloc_coherent(&pdev->dev, etdr->size, &etdr->dma,
					  GFP_KERNEL);
	if (!etdr->hw_desc) {
		dev_err(&pdev->dev, "descriptor allocation for tx ring failed");
		vfree(etdr->sw_desc);
		etdr->sw_desc = NULL;
		return -ENOMEM;
	}

	return 0;
}

/* edma_free_tx_ring()
 *	Free tx rings allocated by edma_alloc_tx_rings
 */
static void edma_free_tx_ring(struct edma_common_info *edma_cinfo,
			      struct edma_tx_desc_ring *etdr)
{
	struct platform_device *pdev = edma_cinfo->pdev;

	if (likely(etdr->hw_desc)) {
		dma_free_coherent(&pdev->dev, etdr->size, etdr->hw_desc,
				 etdr->dma);

		vfree(etdr->sw_desc);
		etdr->sw_desc = NULL;
	}
}

/* edma_alloc_rx_ring()
 *	allocate rx descriptor ring
 */
static int edma_alloc_rx_ring(struct edma_common_info *edma_cinfo,
			     struct edma_rfd_desc_ring *erxd)
{
	struct platform_device *pdev = edma_cinfo->pdev;
	u16 sw_size = sizeof(struct edma_sw_desc) * erxd->count;

	erxd->size = sizeof(struct edma_sw_desc) * erxd->count;
	erxd->sw_next_to_fill = 0;
	erxd->sw_next_to_clean = 0;

	/* Allocate SW descriptors */
	erxd->sw_desc = vzalloc(sw_size);
	if (!erxd->sw_desc)
		return -ENOMEM;

	/* Alloc HW descriptors */
	erxd->hw_desc = dma_alloc_coherent(&pdev->dev, erxd->size, &erxd->dma,
			GFP_KERNEL);
	if (!erxd->hw_desc) {
		vfree(erxd->sw_desc);
		erxd->sw_desc = NULL;
		return -ENOMEM;
	}

	/* Initialize pending fill */
	erxd->pending_fill = 0;

	return 0;
}

/* edma_free_rx_ring()
 *	Free rx ring allocated by alloc_rx_ring
 */
static void edma_free_rx_ring(struct edma_common_info *edma_cinfo,
			     struct edma_rfd_desc_ring *erxd)
{
	struct platform_device *pdev = edma_cinfo->pdev;

	if (likely(erxd->hw_desc)) {
		dma_free_coherent(&pdev->dev, erxd->size, erxd->hw_desc,
				 erxd->dma);

		vfree(erxd->sw_desc);
		erxd->sw_desc = NULL;
	}
}

/* edma_configure_tx()
 *	Configure transmission control data
 */
static void edma_configure_tx(struct edma_common_info *edma_cinfo)
{
	u32 txq_ctrl_data;

	txq_ctrl_data = (EDMA_TPD_BURST << EDMA_TXQ_NUM_TPD_BURST_SHIFT);
	txq_ctrl_data |= EDMA_TXQ_CTRL_TPD_BURST_EN;
	txq_ctrl_data |= (EDMA_TXF_BURST << EDMA_TXQ_TXF_BURST_NUM_SHIFT);
	edma_write_reg(EDMA_REG_TXQ_CTRL, txq_ctrl_data);
}

/* edma_configure_rx()
 *	configure reception control data
 */
static void edma_configure_rx(struct edma_common_info *edma_cinfo)
{
	struct edma_hw *hw = &edma_cinfo->hw;
	u32 rss_type, rx_desc1, rxq_ctrl_data;

	/* Set RSS type */
	rss_type = hw->rss_type;
	edma_write_reg(EDMA_REG_RSS_TYPE, rss_type);

	/* Set RFD burst number */
	rx_desc1 = (EDMA_RFD_BURST << EDMA_RXQ_RFD_BURST_NUM_SHIFT);

	/* Set RFD prefetch threshold */
	rx_desc1 |= (EDMA_RFD_THR << EDMA_RXQ_RFD_PF_THRESH_SHIFT);

	/* Set RFD in host ring low threshold to generte interrupt */
	rx_desc1 |= (EDMA_RFD_LTHR << EDMA_RXQ_RFD_LOW_THRESH_SHIFT);
	edma_write_reg(EDMA_REG_RX_DESC1, rx_desc1);

	/* Set Rx FIFO threshold to start to DMA data to host */
	rxq_ctrl_data = EDMA_FIFO_THRESH_128_BYTE;

	/* Set RX remove vlan bit */
	rxq_ctrl_data |= EDMA_RXQ_CTRL_RMV_VLAN;

	edma_write_reg(EDMA_REG_RXQ_CTRL, rxq_ctrl_data);
}

/* edma_alloc_rx_buf()
 *	does skb allocation for the received packets.
 */
static int edma_alloc_rx_buf(struct edma_common_info
			     *edma_cinfo,
			     struct edma_rfd_desc_ring *erdr,
			     int cleaned_count, int queue_id)
{
	struct platform_device *pdev = edma_cinfo->pdev;
	struct edma_rx_free_desc *rx_desc;
	struct edma_sw_desc *sw_desc;
	struct sk_buff *skb;
	unsigned int i;
	u16 prod_idx, length;
	u32 reg_data;

	if (cleaned_count > erdr->count) {
		dev_err(&pdev->dev, "Incorrect cleaned_count %d",
		       cleaned_count);
		return -1;
	}

	i = erdr->sw_next_to_fill;

	while (cleaned_count) {
		sw_desc = &erdr->sw_desc[i];
		length = edma_cinfo->rx_head_buffer_len;

		if (sw_desc->flags & EDMA_SW_DESC_FLAG_SKB_REUSE) {
			skb = sw_desc->skb;

			/* Clear REUSE flag */
			sw_desc->flags &= ~EDMA_SW_DESC_FLAG_SKB_REUSE;
		} else {
			/* alloc skb */
			skb = netdev_alloc_skb(edma_netdev[0], length);
			if (!skb) {
				/* Better luck next round */
				sw_desc->flags = 0;
				break;
			}
		}

		if (!edma_cinfo->page_mode) {
			sw_desc->dma = dma_map_single(&pdev->dev, skb->data,
							length, DMA_FROM_DEVICE);
				if (dma_mapping_error(&pdev->dev, sw_desc->dma)) {
					WARN_ONCE(0, "EDMA DMA mapping failed for linear address %x", sw_desc->dma);
					sw_desc->flags = 0;
					sw_desc->skb = NULL;
					dev_kfree_skb_any(skb);
					break;
				}

				/*
				 * We should not exit from here with REUSE flag set
				 * This is to avoid re-using same sk_buff for next
				 * time around
				 */
				sw_desc->flags = EDMA_SW_DESC_FLAG_SKB_HEAD;
				sw_desc->length = length;
		} else {
			struct page *pg = alloc_page(GFP_ATOMIC);

			if (!pg) {
				sw_desc->flags = 0;
				sw_desc->skb = NULL;
				dev_kfree_skb_any(skb);
				break;
			}

			sw_desc->dma = dma_map_page(&pdev->dev, pg, 0,
						   edma_cinfo->rx_page_buffer_len,
						   DMA_FROM_DEVICE);
			if (dma_mapping_error(&pdev->dev, sw_desc->dma)) {
				WARN_ONCE(0, "EDMA DMA mapping failed for page address %x", sw_desc->dma);
				sw_desc->flags = 0;
				sw_desc->skb = NULL;
				__free_page(pg);
				dev_kfree_skb_any(skb);
				break;
			}

			skb_fill_page_desc(skb, 0, pg, 0,
					   edma_cinfo->rx_page_buffer_len);
			sw_desc->flags = EDMA_SW_DESC_FLAG_SKB_FRAG;
			sw_desc->length = edma_cinfo->rx_page_buffer_len;
		}

		/* Update the buffer info */
		sw_desc->skb = skb;
		rx_desc = (&(erdr->hw_desc)[i]);
		rx_desc->buffer_addr = cpu_to_le64(sw_desc->dma);
		if (++i == erdr->count)
			i = 0;
		cleaned_count--;
	}

	erdr->sw_next_to_fill = i;

	if (i == 0)
		prod_idx = erdr->count - 1;
	else
		prod_idx = i - 1;

	/* Update the producer index */
	edma_read_reg(EDMA_REG_RFD_IDX_Q(queue_id), &reg_data);
	reg_data &= ~EDMA_RFD_PROD_IDX_BITS;
	reg_data |= prod_idx;
	edma_write_reg(EDMA_REG_RFD_IDX_Q(queue_id), reg_data);

	/* If we couldn't allocate all the buffers,
	 * we increment the alloc failure counters
	 */
	if (cleaned_count)
		edma_cinfo->edma_ethstats.rx_alloc_fail_ctr++;

	return cleaned_count;
}

/* edma_init_desc()
 *	update descriptor ring size, buffer and producer/consumer index
 */
static void edma_init_desc(struct edma_common_info *edma_cinfo)
{
	struct edma_rfd_desc_ring *rfd_ring;
	struct edma_tx_desc_ring *etdr;
	int i = 0, j = 0;
	u32 data = 0;
	u16 hw_cons_idx = 0;

	/* Set the base address of every TPD ring. */
	for (i = 0; i < edma_cinfo->num_tx_queues; i++) {
		etdr = edma_cinfo->tpd_ring[i];

		/* Update descriptor ring base address */
		edma_write_reg(EDMA_REG_TPD_BASE_ADDR_Q(i), (u32)etdr->dma);
		edma_read_reg(EDMA_REG_TPD_IDX_Q(i), &data);

		/* Calculate hardware consumer index */
		hw_cons_idx = (data >> EDMA_TPD_CONS_IDX_SHIFT) & 0xffff;
		etdr->sw_next_to_fill = hw_cons_idx;
		etdr->sw_next_to_clean = hw_cons_idx;
		data &= ~(EDMA_TPD_PROD_IDX_MASK << EDMA_TPD_PROD_IDX_SHIFT);
		data |= hw_cons_idx;

		/* update producer index */
		edma_write_reg(EDMA_REG_TPD_IDX_Q(i), data);

		/* update SW consumer index register */
		edma_write_reg(EDMA_REG_TX_SW_CONS_IDX_Q(i), hw_cons_idx);

		/* Set TPD ring size */
		edma_write_reg(EDMA_REG_TPD_RING_SIZE,
			       edma_cinfo->tx_ring_count &
				    EDMA_TPD_RING_SIZE_MASK);
	}

	for (i = 0, j = 0; i < edma_cinfo->num_rx_queues; i++) {
		rfd_ring = edma_cinfo->rfd_ring[j];
		/* Update Receive Free descriptor ring base address */
		edma_write_reg(EDMA_REG_RFD_BASE_ADDR_Q(j),
			      (u32)(rfd_ring->dma));
		j += ((edma_cinfo->num_rx_queues == 4) ? 2 : 1);
	}

	data = edma_cinfo->rx_head_buffer_len;
	if (edma_cinfo->page_mode)
		data = edma_cinfo->rx_page_buffer_len;

	data &= EDMA_RX_BUF_SIZE_MASK;
	data <<= EDMA_RX_BUF_SIZE_SHIFT;

	/* Update RFD ring size and RX buffer size */
	data |= (edma_cinfo->rx_ring_count & EDMA_RFD_RING_SIZE_MASK)
		<< EDMA_RFD_RING_SIZE_SHIFT;

	edma_write_reg(EDMA_REG_RX_DESC0, data);

	/* Disable TX FIFO low watermark and high watermark */
	edma_write_reg(EDMA_REG_TXF_WATER_MARK, 0);

	/* Load all of base address above */
	edma_read_reg(EDMA_REG_TX_SRAM_PART, &data);
	data |= 1 << EDMA_LOAD_PTR_SHIFT;
	edma_write_reg(EDMA_REG_TX_SRAM_PART, data);
}

/* edma_receive_checksum
 *	Api to check checksum on receive packets
 */
static void edma_receive_checksum(struct edma_rx_return_desc *rd,
				 struct sk_buff *skb)
{
	skb_checksum_none_assert(skb);

	/* check the RRD IP/L4 checksum bit to see if
	 * its set, which in turn indicates checksum
	 * failure.
	 */
	if (rd->rrd6 & EDMA_RRD_CSUM_FAIL_MASK)
		return;

	/*
	 * We disable checksum verification only if
	 * we have a TCP/UDP packet
	 */
	if (rd->rrd7 & (EDMA_RRD_L4OFFSET_MASK << EDMA_RRD_L4OFFSET_SHIFT))
		skb->ip_summed = CHECKSUM_UNNECESSARY;
}

/* edma_clean_rfd()
 *	clean up rx resourcers on error
 */
static void edma_clean_rfd(struct platform_device *pdev,
			  struct edma_rfd_desc_ring *erdr,
			  u16 index,
			  int pos)
{
	struct edma_rx_free_desc *rx_desc = &(erdr->hw_desc[index]);
	struct edma_sw_desc *sw_desc = &erdr->sw_desc[index];

	/* Unmap non-first RFD positions in packet */
	if (pos) {
		if (likely(sw_desc->flags & EDMA_SW_DESC_FLAG_SKB_HEAD))
			dma_unmap_single(&pdev->dev, sw_desc->dma,
					sw_desc->length, DMA_FROM_DEVICE);
		else
			dma_unmap_page(&pdev->dev, sw_desc->dma,
				      sw_desc->length, DMA_FROM_DEVICE);
	}

	if (sw_desc->skb) {
		dev_kfree_skb_any(sw_desc->skb);
		sw_desc->skb = NULL;
	}

	sw_desc->flags = 0;
	memset(rx_desc, 0, sizeof(struct edma_rx_free_desc));
}

/* edma_rx_complete_stp_rstp()
 *	Complete Rx processing for STP RSTP packets
 */
static void edma_rx_complete_stp_rstp(struct sk_buff *skb, int port_id, struct edma_rx_return_desc *rd)
{
	int i;
	u32 priority;
	u16 port_type;
	u8 mac_addr[EDMA_ETH_HDR_LEN];

	port_type = (rd->rrd1 >> EDMA_RRD_PORT_TYPE_SHIFT)
				& EDMA_RRD_PORT_TYPE_MASK;
	/* if port type is 0x4, then only proceed with
	 * other stp/rstp calculation
	 */
	if (port_type == EDMA_RX_ATH_HDR_RSTP_PORT_TYPE) {
		u8 bpdu_mac[6] = {0x01, 0x80, 0xc2, 0x00, 0x00, 0x00};

		/* calculate the frame priority */
		priority = (rd->rrd1 >> EDMA_RRD_PRIORITY_SHIFT)
			& EDMA_RRD_PRIORITY_MASK;

		for (i = 0; i < EDMA_ETH_HDR_LEN; i++)
			mac_addr[i] = skb->data[i];

		/* Check if destination mac addr is bpdu addr */
		if (!memcmp(mac_addr, bpdu_mac, 6)) {
			/* destination mac address is BPDU
			 * destination mac address, then add
			 * atheros header to the packet.
			 */
			u16 athr_hdr = (EDMA_RX_ATH_HDR_VERSION << EDMA_RX_ATH_HDR_VERSION_SHIFT) |
				(priority << EDMA_RX_ATH_HDR_PRIORITY_SHIFT) |
				(EDMA_RX_ATH_HDR_RSTP_PORT_TYPE << EDMA_RX_ATH_PORT_TYPE_SHIFT) | port_id;
			skb_push(skb, 4);
			memcpy(skb->data, mac_addr, EDMA_ETH_HDR_LEN);
			*(uint16_t *)&skb->data[12] = htons(edma_ath_eth_type);
			*(uint16_t *)&skb->data[14] = htons(athr_hdr);
		}
	}
}

/* edma_rx_complete_fraglist()
 *	Complete Rx processing for fraglist skbs
 */
static int edma_rx_complete_fraglist(struct sk_buff *skb, u16 num_rfds, u16 length, u32 sw_next_to_clean,
				    struct edma_rfd_desc_ring *erdr, struct edma_common_info *edma_cinfo)
{
	struct platform_device *pdev = edma_cinfo->pdev;
	struct edma_hw *hw = &edma_cinfo->hw;
	struct sk_buff *skb_temp;
	struct edma_sw_desc *sw_desc;
	int i;
	u16 size_remaining;

	skb->data_len = 0;
	skb->tail += (hw->rx_head_buff_size - 16);
	skb->len = skb->truesize = length;
	size_remaining = length - (hw->rx_head_buff_size - 16);

	/* clean-up all related sw_descs */
	for (i = 1; i < num_rfds; i++) {
		struct sk_buff *skb_prev;

		sw_desc = &erdr->sw_desc[sw_next_to_clean];
		skb_temp = sw_desc->skb;

		dma_unmap_single(&pdev->dev, sw_desc->dma,
			sw_desc->length, DMA_FROM_DEVICE);

		if (size_remaining < hw->rx_head_buff_size)
			skb_put(skb_temp, size_remaining);
		else
			skb_put(skb_temp, hw->rx_head_buff_size);

		 /* If we are processing the first rfd, we link
		 * skb->frag_list to the skb corresponding to the
		 * first RFD
		 */
		if (i == 1)
			skb_shinfo(skb)->frag_list = skb_temp;
		else
			skb_prev->next = skb_temp;
		skb_prev = skb_temp;
		skb_temp->next = NULL;

		skb->data_len += skb_temp->len;
		size_remaining -= skb_temp->len;

		/* Increment SW index */
		sw_next_to_clean = (sw_next_to_clean + 1) & (erdr->count - 1);
	}

	return sw_next_to_clean;
}

/* edma_rx_complete_paged()
 *	Complete Rx processing for paged skbs
 */
static int edma_rx_complete_paged(struct sk_buff *skb, u16 num_rfds,
				 u16 length, u32 sw_next_to_clean,
				struct edma_rfd_desc_ring *erdr,
				struct edma_common_info *edma_cinfo)
{
	struct platform_device *pdev = edma_cinfo->pdev;
	struct sk_buff *skb_temp;
	struct edma_sw_desc *sw_desc;
	int i;
	u16 size_remaining;

	skb_frag_t *frag = &skb_shinfo(skb)->frags[0];

	/* Setup skbuff fields */
	skb->len = length;

	if (likely(num_rfds <= 1)) {
		skb->data_len = length;
		skb->truesize += edma_cinfo->rx_page_buffer_len;
		skb_fill_page_desc(skb, 0, skb_frag_page(frag),
				  16, length);
	} else {
		frag->size -= 16;
		skb->data_len = frag->size;
		skb->truesize += edma_cinfo->rx_page_buffer_len;
		size_remaining = length - frag->size;

		skb_fill_page_desc(skb, 0, skb_frag_page(frag),
				16, frag->size);

		/* clean-up all related sw_descs */
		for (i = 1; i < num_rfds; i++) {
			sw_desc = &erdr->sw_desc[sw_next_to_clean];
			skb_temp = sw_desc->skb;
			frag = &skb_shinfo(skb_temp)->frags[0];
			dma_unmap_page(&pdev->dev, sw_desc->dma,
				      sw_desc->length, DMA_FROM_DEVICE);

			if (size_remaining < edma_cinfo->rx_page_buffer_len)
				frag->size = size_remaining;

			skb_fill_page_desc(skb, i, skb_frag_page(frag),
					  0, frag->size);

			/* We used frag pages from skb_temp in skb */
			skb_shinfo(skb_temp)->nr_frags = 0;
			dev_kfree_skb_any(skb_temp);

			skb->data_len += frag->size;
			skb->truesize += edma_cinfo->rx_page_buffer_len;
			size_remaining -= frag->size;

			/* Increment SW index */
			sw_next_to_clean = (sw_next_to_clean + 1) & (erdr->count - 1);
		}
	}

	return sw_next_to_clean;
}

/*
 * edma_rx_complete()
 *	Main api called from the poll function to process rx packets.
 */
static u16 edma_rx_complete(struct edma_common_info *edma_cinfo,
			    int *work_done, int work_to_do, int queue_id,
			    struct napi_struct *napi)
{
	struct platform_device *pdev = edma_cinfo->pdev;
	struct edma_rfd_desc_ring *erdr = edma_cinfo->rfd_ring[queue_id];
	u16 hash_type, rrd[8], cleaned_count = 0, length = 0, num_rfds = 1,
	    sw_next_to_clean, hw_next_to_clean = 0, vlan = 0, ret_count = 0;
	u32 data = 0;
	u16 count = erdr->count, rfd_avail;
	u8 queue_to_rxid[8] = {0, 0, 1, 1, 2, 2, 3, 3};

	cleaned_count = erdr->pending_fill;
	sw_next_to_clean = erdr->sw_next_to_clean;

	edma_read_reg(EDMA_REG_RFD_IDX_Q(queue_id), &data);
	hw_next_to_clean = (data >> EDMA_RFD_CONS_IDX_SHIFT) &
			EDMA_RFD_CONS_IDX_MASK;

	do {
		while (sw_next_to_clean != hw_next_to_clean) {
			struct net_device *netdev;
			struct edma_adapter *adapter;
			struct edma_sw_desc *sw_desc;
			struct sk_buff *skb;
			struct edma_rx_return_desc *rd;
			u8 *vaddr;
			int port_id, i, drop_count = 0;
			u32 priority;

			if (!work_to_do)
				break;

			sw_desc = &erdr->sw_desc[sw_next_to_clean];
			skb = sw_desc->skb;

			/* Get RRD */
			if (!edma_cinfo->page_mode) {
				dma_unmap_single(&pdev->dev, sw_desc->dma,
						sw_desc->length, DMA_FROM_DEVICE);
				rd = (struct edma_rx_return_desc *)skb->data;

			} else {
				dma_unmap_page(&pdev->dev, sw_desc->dma,
					      sw_desc->length, DMA_FROM_DEVICE);
				vaddr = kmap_atomic(skb_frag_page(&skb_shinfo(skb)->frags[0]));
				memcpy((uint8_t *)&rrd[0], vaddr, 16);
				rd = (struct edma_rx_return_desc *)rrd;
				kunmap_atomic(vaddr);
			}

			/* Check if RRD is valid */
			if (!(rd->rrd7 & EDMA_RRD_DESC_VALID)) {
				dev_err(&pdev->dev, "Incorrect RRD DESC valid bit set");
				edma_clean_rfd(pdev, erdr, sw_next_to_clean, 0);
				sw_next_to_clean = (sw_next_to_clean + 1) &
						   (erdr->count - 1);
				cleaned_count++;
				continue;
			}

			/* Get the number of RFDs from RRD */
			num_rfds = rd->rrd1 & EDMA_RRD_NUM_RFD_MASK;

			/* Get Rx port ID from switch */
			port_id = (rd->rrd1 >> EDMA_PORT_ID_SHIFT) & EDMA_PORT_ID_MASK;
			if ((!port_id) || (port_id > EDMA_MAX_PORTID_SUPPORTED)) {
				if (net_ratelimit()) {
					dev_err(&pdev->dev, "Incorrect RRD source port bit set");
					dev_err(&pdev->dev,
						"RRD Dump\n rrd0:%x rrd1: %x rrd2: %x rrd3: %x rrd4: %x rrd5: %x rrd6: %x rrd7: %x",
						rd->rrd0, rd->rrd1, rd->rrd2, rd->rrd3, rd->rrd4, rd->rrd5, rd->rrd6, rd->rrd7);
					dev_err(&pdev->dev, "Num_rfds: %d, src_port: %d, pkt_size: %d, cvlan_tag: %d\n",
						num_rfds, rd->rrd1 & EDMA_RRD_SRC_PORT_NUM_MASK,
						rd->rrd6 & EDMA_RRD_PKT_SIZE_MASK, rd->rrd7 & EDMA_RRD_CVLAN);
				}
				for (i = 0; i < num_rfds; i++) {
					edma_clean_rfd(pdev, erdr, sw_next_to_clean, i);
					sw_next_to_clean = (sw_next_to_clean + 1) & (erdr->count - 1);
				}

				cleaned_count += num_rfds;
				continue;
			}

			netdev = edma_cinfo->portid_netdev_lookup_tbl[port_id];
			if (!netdev) {
				dev_err(&pdev->dev, "Invalid netdev");
				for (i = 0; i < num_rfds; i++) {
					edma_clean_rfd(pdev, erdr, sw_next_to_clean, i);
					sw_next_to_clean = (sw_next_to_clean + 1) & (erdr->count - 1);
				}

				cleaned_count += num_rfds;
				continue;
			}
			adapter = netdev_priv(netdev);

			/* This code is added to handle a usecase where high
			 * priority stream and a low priority stream are
			 * received simultaneously on DUT. The problem occurs
			 * if one of the  Rx rings is full and the corresponding
			 * core is busy with other stuff. This causes ESS CPU
			 * port to backpressure all incoming traffic including
			 * high priority one. We monitor free descriptor count
			 * on each CPU and whenever it reaches threshold (< 80),
			 * we drop all low priority traffic and let only high
			 * priotiy traffic pass through. We can hence avoid
			 * ESS CPU port to send backpressure on high priroity
			 * stream.
			 */
			priority = (rd->rrd1 >> EDMA_RRD_PRIORITY_SHIFT)
				& EDMA_RRD_PRIORITY_MASK;
			if (likely((priority <= edma_cinfo->rx_low_priority) && !edma_cinfo->page_mode && (num_rfds <= 1))) {
				rfd_avail = (count + sw_next_to_clean - hw_next_to_clean - 1) & (count - 1);
				if (rfd_avail < EDMA_RFD_AVAIL_THR) {
					sw_desc->flags |= EDMA_SW_DESC_FLAG_SKB_REUSE;
					sw_next_to_clean = (sw_next_to_clean + 1) & (erdr->count - 1);
					adapter->stats.rx_dropped++;
					cleaned_count++;
					drop_count++;
					if (drop_count == 3) {
						work_to_do--;
						(*work_done)++;
						drop_count = 0;
					}
					if (cleaned_count == EDMA_RX_BUFFER_WRITE) {
						/* If buffer clean count reaches 16, we replenish HW buffers. */
						ret_count = edma_alloc_rx_buf(edma_cinfo, erdr, cleaned_count, queue_id);
						edma_write_reg(EDMA_REG_RX_SW_CONS_IDX_Q(queue_id),
							      sw_next_to_clean);
						cleaned_count = ret_count;
						erdr->pending_fill = ret_count;
					}
					continue;
				}
			}

			work_to_do--;
			(*work_done)++;

			/* Increment SW index */
			sw_next_to_clean = (sw_next_to_clean + 1) &
					   (erdr->count - 1);

			/* Get the packet size and allocate buffer */
			length = rd->rrd6 & EDMA_RRD_PKT_SIZE_MASK;

			if (edma_cinfo->page_mode) {
				/* paged skb */
				sw_next_to_clean = edma_rx_complete_paged(skb, num_rfds, length,
									 sw_next_to_clean,
									 erdr, edma_cinfo);
				if (!pskb_may_pull(skb, ETH_HLEN)) {
					cleaned_count += num_rfds;
					dev_kfree_skb_any(skb);
					continue;
				}
			} else {
				/* single or fraglist skb */

				/* Addition of 16 bytes is required, as in the packet
				 * first 16 bytes are rrd descriptors, so actual data
				 * starts from an offset of 16.
				 */
				skb_reserve(skb, 16);
				if (likely((num_rfds <= 1) || !edma_cinfo->fraglist_mode))
					skb_put(skb, length);
				else
					sw_next_to_clean = edma_rx_complete_fraglist(skb, num_rfds, length,
										    sw_next_to_clean,
										    erdr, edma_cinfo);
			}

			cleaned_count += num_rfds;

			if (edma_stp_rstp)
				edma_rx_complete_stp_rstp(skb, port_id, rd);

			skb->protocol = eth_type_trans(skb, netdev);

			/* Record Rx queue for RFS/RPS and fill flow hash from HW */
			skb_record_rx_queue(skb, queue_to_rxid[queue_id]);
			if (netdev->features & NETIF_F_RXHASH) {
				hash_type = (rd->rrd5 >> EDMA_HASH_TYPE_SHIFT);
				if ((hash_type > EDMA_HASH_TYPE_START) && (hash_type < EDMA_HASH_TYPE_END))
					skb_set_hash(skb, rd->rrd2, PKT_HASH_TYPE_L4);
			}

#ifdef CONFIG_NF_FLOW_COOKIE
			skb->flow_cookie = rd->rrd3 & EDMA_RRD_FLOW_COOKIE_MASK;
#endif
			edma_receive_checksum(rd, skb);

			/* Process VLAN HW acceleration indication provided by HW */
			if (adapter->default_vlan_tag != rd->rrd4) {
				vlan = rd->rrd4;
				if (likely(rd->rrd7 & EDMA_RRD_CVLAN))
					__vlan_hwaccel_put_tag(skb, htons(ETH_P_8021Q), vlan);
				else if (rd->rrd1 & EDMA_RRD_SVLAN)
					__vlan_hwaccel_put_tag(skb, htons(ETH_P_8021AD), vlan);
			}

			/* Update rx statistics */
			adapter->stats.rx_packets++;
			adapter->stats.rx_bytes += length;

			/* Check if we reached refill threshold */
			if (cleaned_count == EDMA_RX_BUFFER_WRITE) {
				ret_count = edma_alloc_rx_buf(edma_cinfo, erdr, cleaned_count, queue_id);
				edma_write_reg(EDMA_REG_RX_SW_CONS_IDX_Q(queue_id),
					      sw_next_to_clean);
				cleaned_count = ret_count;
				erdr->pending_fill = ret_count;
			}

			/*
			 * We increment per-precedence counters for the rx packets
			 */
			if (edma_per_prec_stats_enable) {
				atomic_inc(&edma_cinfo->edma_ethstats.rx_prec[priority]);
				edma_cinfo->edma_ethstats.rx_ac[edma_dscp2ac_tbl[priority]]++;

				if (edma_iad_stats_enable) {
					if (edma_dscp2ac_tbl[priority] == EDMA_AC_VI)
						edma_iad_process_flow(edma_cinfo, skb, EDMA_INGRESS_DIR, priority);
				}
			}

			/* At this point skb should go to stack */
			napi_gro_receive(napi, skb);
		}

		/* Check if we still have NAPI budget */
		if (!work_to_do)
			break;

		/* Read index once again since we still have NAPI budget */
		edma_read_reg(EDMA_REG_RFD_IDX_Q(queue_id), &data);
		hw_next_to_clean = (data >> EDMA_RFD_CONS_IDX_SHIFT) &
			EDMA_RFD_CONS_IDX_MASK;
	} while (hw_next_to_clean != sw_next_to_clean);

	erdr->sw_next_to_clean = sw_next_to_clean;

	/* Refill here in case refill threshold wasn't reached */
	if (likely(cleaned_count)) {
		ret_count = edma_alloc_rx_buf(edma_cinfo, erdr, cleaned_count, queue_id);
		erdr->pending_fill = ret_count;
		if (ret_count) {
			if(net_ratelimit())
				dev_dbg(&pdev->dev, "Edma not getting memory for descriptors.\n");
		}

		edma_write_reg(EDMA_REG_RX_SW_CONS_IDX_Q(queue_id),
			      erdr->sw_next_to_clean);
	}

	return erdr->pending_fill;
}

/* edma_delete_rfs_filter()
 *	Remove RFS filter from switch
 */
static int edma_delete_rfs_filter(struct edma_adapter *adapter,
				 struct edma_rfs_filter_node *filter_node)
{
	int res = -1;

	if (likely(adapter->set_rfs_rule))
		res = (*adapter->set_rfs_rule)(adapter->netdev,
#if (LINUX_VERSION_CODE <= KERNEL_VERSION(3, 18, 21))
				filter_node->keys.src,
				filter_node->keys.dst, filter_node->keys.port16[0],
				filter_node->keys.port16[1],
				filter_node->keys.ip_proto,
#else
				filter_node->keys.addrs.v4addrs.src,
				filter_node->keys.addrs.v4addrs.dst, filter_node->keys.ports.src,
				filter_node->keys.ports.dst,
				filter_node->keys.basic.ip_proto,
#endif
				filter_node->rq_id,
				0);

	return res;
}

/* edma_add_rfs_filter()
 *	Add RFS filter to switch
 */
static int edma_add_rfs_filter(struct edma_adapter *adapter,
			      struct flow_keys *keys, u16 rq,
			      struct edma_rfs_filter_node *filter_node)
{
	int res = -1;

#if (LINUX_VERSION_CODE <= KERNEL_VERSION(3, 18, 21))
	filter_node->keys.src = keys->src;
	filter_node->keys.dst = keys->dst;
	filter_node->keys.ports = keys->ports;
	filter_node->keys.ip_proto = keys->ip_proto;
#else
	filter_node->keys.addrs.v4addrs.src = keys->addrs.v4addrs.src;
	filter_node->keys.addrs.v4addrs.dst = keys->addrs.v4addrs.dst;
	filter_node->keys.ports.ports = keys->ports.ports;
	filter_node->keys.basic.ip_proto = keys->basic.ip_proto;
#endif

	/* Call callback registered by ESS driver */
	if (likely(adapter->set_rfs_rule))
#if (LINUX_VERSION_CODE <= KERNEL_VERSION(3, 18, 21))
		res = (*adapter->set_rfs_rule)(adapter->netdev, keys->src,
		      keys->dst, keys->port16[0], keys->port16[1],
		      keys->ip_proto, rq, 1);
#else
		res = (*adapter->set_rfs_rule)(adapter->netdev, keys->addrs.v4addrs.src,
		      keys->addrs.v4addrs.dst, keys->ports.src, keys->ports.dst,
		      keys->basic.ip_proto, rq, 1);
#endif

	return res;
}

/* edma_rfs_key_search()
 *	Look for existing RFS entry
 */
static struct edma_rfs_filter_node *edma_rfs_key_search(struct hlist_head *h,
						       struct flow_keys *key)
{
	struct edma_rfs_filter_node *p;

	hlist_for_each_entry(p, h, node)
#if (LINUX_VERSION_CODE <= KERNEL_VERSION(3, 18, 21))
		if (p->keys.src == key->src &&
			p->keys.dst == key->dst &&
			p->keys.ports == key->ports &&
			p->keys.ip_proto == key->ip_proto)
#else
		if (p->keys.addrs.v4addrs.src == key->addrs.v4addrs.src &&
		   p->keys.addrs.v4addrs.dst == key->addrs.v4addrs.dst &&
		   p->keys.ports.ports == key->ports.ports &&
		   p->keys.basic.ip_proto == key->basic.ip_proto)
#endif
				return p;
	return NULL;
}

/* edma_initialise_rfs_flow_table()
 *	Initialise EDMA RFS flow table
 */
static void edma_initialise_rfs_flow_table(struct edma_adapter *adapter)
{
	int i;

	spin_lock_init(&adapter->rfs.rfs_ftab_lock);

	/* Initialize EDMA flow hash table */
	for (i = 0; i < EDMA_RFS_FLOW_ENTRIES; i++)
		INIT_HLIST_HEAD(&adapter->rfs.hlist_head[i]);

	adapter->rfs.max_num_filter = EDMA_RFS_FLOW_ENTRIES;
	adapter->rfs.filter_available = adapter->rfs.max_num_filter;
	adapter->rfs.hashtoclean = 0;

	/* Add timer to get periodic RFS updates from OS */
	init_timer(&adapter->rfs.expire_rfs);
	adapter->rfs.expire_rfs.function = edma_flow_may_expire;
	adapter->rfs.expire_rfs.data = (unsigned long)adapter;
	mod_timer(&adapter->rfs.expire_rfs, jiffies + HZ/4);
}

/* edma_free_rfs_flow_table()
 *	Free EDMA RFS flow table
 */
static void edma_free_rfs_flow_table(struct edma_adapter *adapter)
{
	int i;

	/* Remove sync timer */
	del_timer_sync(&adapter->rfs.expire_rfs);
	spin_lock_bh(&adapter->rfs.rfs_ftab_lock);

	/* Free EDMA RFS table entries */
	adapter->rfs.filter_available = 0;

	/* Clean-up EDMA flow hash table */
	for (i = 0; i < EDMA_RFS_FLOW_ENTRIES; i++) {
		struct hlist_head *hhead;
		struct hlist_node *tmp;
		struct edma_rfs_filter_node *filter_node;
		int res;

		hhead = &adapter->rfs.hlist_head[i];
		hlist_for_each_entry_safe(filter_node, tmp, hhead, node) {
			res = edma_delete_rfs_filter(adapter, filter_node);
			if (res < 0)
				dev_warn(&adapter->netdev->dev,
					"EDMA going down but RFS entry %d not allowed to be flushed by Switch",
					filter_node->flow_id);
			hlist_del(&filter_node->node);
			kfree(filter_node);
		}
	}
	spin_unlock_bh(&adapter->rfs.rfs_ftab_lock);
}

/* edma_tx_unmap_and_free()
 *	clean TX buffer
 */
static inline void edma_tx_unmap_and_free(struct platform_device *pdev,
					 struct edma_sw_desc *sw_desc)
{
	struct sk_buff *skb = sw_desc->skb;

	if (likely((sw_desc->flags & EDMA_SW_DESC_FLAG_SKB_HEAD) ||
		  (sw_desc->flags & EDMA_SW_DESC_FLAG_SKB_FRAGLIST)))
		/* unmap_single for skb head area */
		dma_unmap_single(&pdev->dev, sw_desc->dma,
				sw_desc->length, DMA_TO_DEVICE);
	else if (sw_desc->flags & EDMA_SW_DESC_FLAG_SKB_FRAG)
		/* unmap page for paged fragments */
		dma_unmap_page(&pdev->dev, sw_desc->dma,
				sw_desc->length, DMA_TO_DEVICE);

	if (likely(sw_desc->flags & EDMA_SW_DESC_FLAG_LAST))
		dev_kfree_skb_any(skb);

	sw_desc->flags = 0;
}

/* edma_tx_complete()
 *	Used to clean tx queues and update hardware and consumer index
 */
static void edma_tx_complete(struct edma_common_info *edma_cinfo, int queue_id)
{
	struct edma_tx_desc_ring *etdr = edma_cinfo->tpd_ring[queue_id];
	struct edma_sw_desc *sw_desc;
	struct platform_device *pdev = edma_cinfo->pdev;
	int i;

	u16 sw_next_to_clean = etdr->sw_next_to_clean;
	u16 hw_next_to_clean;
	u32 data = 0;

	edma_read_reg(EDMA_REG_TPD_IDX_Q(queue_id), &data);
	hw_next_to_clean = (data >> EDMA_TPD_CONS_IDX_SHIFT) & EDMA_TPD_CONS_IDX_MASK;

	/* clean the buffer here */
	while (sw_next_to_clean != hw_next_to_clean) {
		sw_desc = &etdr->sw_desc[sw_next_to_clean];
		edma_tx_unmap_and_free(pdev, sw_desc);
		sw_next_to_clean = (sw_next_to_clean + 1) & (etdr->count - 1);
	}

	etdr->sw_next_to_clean = sw_next_to_clean;

	/* update the TPD consumer index register */
	edma_write_reg(EDMA_REG_TX_SW_CONS_IDX_Q(queue_id), sw_next_to_clean);

	/* Wake the queue if queue is stopped and netdev link is up */
	for (i = 0; i < EDMA_MAX_NETDEV_PER_QUEUE && etdr->nq[i] ; i++) {
		if (netif_tx_queue_stopped(etdr->nq[i])) {
			if ((etdr->netdev[i]) && netif_carrier_ok(etdr->netdev[i]))
				netif_tx_wake_queue(etdr->nq[i]);
		}
	}
}

/* edma_get_tx_buffer()
 *	Get sw_desc corresponding to the TPD
 */
static struct edma_sw_desc *edma_get_tx_buffer(struct edma_common_info *edma_cinfo,
					       struct edma_tx_desc *tpd, int queue_id)
{
	struct edma_tx_desc_ring *etdr = edma_cinfo->tpd_ring[queue_id];

	return &etdr->sw_desc[tpd - (struct edma_tx_desc *)etdr->hw_desc];
}

/* edma_get_next_tpd()
 *	Return a TPD descriptor for transfer
 */
static struct edma_tx_desc *edma_get_next_tpd(struct edma_common_info *edma_cinfo,
					     int queue_id)
{
	struct edma_tx_desc_ring *etdr = edma_cinfo->tpd_ring[queue_id];
	u16 sw_next_to_fill = etdr->sw_next_to_fill;
	struct edma_tx_desc *tpd_desc =
		(&((struct edma_tx_desc *)(etdr->hw_desc))[sw_next_to_fill]);

	etdr->sw_next_to_fill = (etdr->sw_next_to_fill + 1) & (etdr->count - 1);

	return tpd_desc;
}

/* edma_tpd_available()
 *	Check number of free TPDs
 */
static inline u16 edma_tpd_available(struct edma_common_info *edma_cinfo,
				    int queue_id)
{
	struct edma_tx_desc_ring *etdr = edma_cinfo->tpd_ring[queue_id];

	u16 sw_next_to_fill;
	u16 sw_next_to_clean;
	u16 count = 0;

	sw_next_to_clean = etdr->sw_next_to_clean;
	sw_next_to_fill = etdr->sw_next_to_fill;

	if (likely(sw_next_to_clean <= sw_next_to_fill))
		count = etdr->count;

	return count + sw_next_to_clean - sw_next_to_fill - 1;
}

/* edma_tx_queue_get()
 *	Get the starting number of  the queue
 */
static inline int edma_tx_queue_get(struct edma_adapter *adapter,
				   struct sk_buff *skb, int txq_id)
{
	/* skb->priority is used as an index to skb priority table
	 * and based on packet priority, correspong queue is assigned.
	 */
	return adapter->tx_start_offset[txq_id] + edma_skb_priority_offset(skb);
}

/* edma_tx_update_hw_idx()
 *	update the producer index for the ring transmitted
 */
static void edma_tx_update_hw_idx(struct edma_common_info *edma_cinfo,
				struct sk_buff *skb, int queue_id)
{
	struct edma_tx_desc_ring *etdr = edma_cinfo->tpd_ring[queue_id];
	u32 tpd_idx_data;

	/* Read and update the producer index */
	edma_read_reg(EDMA_REG_TPD_IDX_Q(queue_id), &tpd_idx_data);
	tpd_idx_data &= ~EDMA_TPD_PROD_IDX_BITS;
	tpd_idx_data |= (etdr->sw_next_to_fill & EDMA_TPD_PROD_IDX_MASK)
		<< EDMA_TPD_PROD_IDX_SHIFT;

	edma_write_reg(EDMA_REG_TPD_IDX_Q(queue_id), tpd_idx_data);
}

/* edma_rollback_tx()
 *	Function to retrieve tx resources in case of error
 */
static void edma_rollback_tx(struct edma_adapter *adapter,
			    struct edma_tx_desc *start_tpd, int queue_id)
{
	struct edma_tx_desc_ring *etdr = adapter->edma_cinfo->tpd_ring[queue_id];
	struct edma_sw_desc *sw_desc;
	struct edma_tx_desc *tpd = NULL;
	u16 start_index, index;

	start_index = start_tpd - (struct edma_tx_desc *)(etdr->hw_desc);

	index = start_index;
	while (index != etdr->sw_next_to_fill) {
		tpd = (&((struct edma_tx_desc *)(etdr->hw_desc))[index]);
		sw_desc = &etdr->sw_desc[index];
		edma_tx_unmap_and_free(adapter->pdev, sw_desc);
		memset(tpd, 0, sizeof(struct edma_tx_desc));
		if (++index == etdr->count)
			index = 0;
	}
	etdr->sw_next_to_fill = start_index;
}

/* edma_get_v4_precedence()
 *	Function to retrieve precedence for IPv4
 */
static inline int edma_get_v4_precedence(struct sk_buff *skb, int nh_offset, u8 *precedence)
{
	const struct iphdr *iph;
	struct iphdr iph_hdr;

	iph = skb_header_pointer(skb, nh_offset, sizeof(iph_hdr), &iph_hdr);

	if (!iph || iph->ihl < 5)
		return -1;

	*precedence = iph->tos >> EDMA_DSCP_PREC_SHIFT;

	return 0;
}

/* edma_get_v6_precedence()
 *	Function to retrieve precedence for IPv6
 */
static inline int edma_get_v6_precedence(struct sk_buff *skb, int nh_offset, u8 *precedence)
{
	const struct ipv6hdr *iph;
	struct ipv6hdr iph_hdr;

	iph = skb_header_pointer(skb, nh_offset, sizeof(iph_hdr), &iph_hdr);

	if (!iph)
		return -1;

	*precedence = iph->priority >> EDMA_DSCP6_PREC_SHIFT;

	return 0;
}

/* edma_get_skb_precedence()
 *	Function to retrieve precedence from skb
 */
static int edma_get_skb_precedence(struct sk_buff *skb, u8 *precedence)
{
	int nhoff = skb_network_offset(skb);
	__be16 proto = skb->protocol;
	int ret;
	struct pppoeh_proto *pppoeh, ppp_hdr;

	switch(proto) {
		case __constant_htons(ETH_P_IP): {
			ret = edma_get_v4_precedence(skb, nhoff, precedence);
			if (ret)
				return -1;
			break;
		}
		case __constant_htons(ETH_P_IPV6): {
			ret = edma_get_v6_precedence(skb, nhoff, precedence);
			if (ret)
				return -1;
			break;
		}
		case __constant_htons(ETH_P_PPP_SES): {
			pppoeh = skb_header_pointer(skb, nhoff, sizeof(ppp_hdr), &ppp_hdr);
			if (!pppoeh)
				return -1;

			proto = pppoeh->proto;
			nhoff += PPPOE_SES_HLEN;
			switch (proto) {
				case __constant_htons(PPP_IP): {
					ret = edma_get_v4_precedence(skb, nhoff, precedence);
					if (ret)
						return -1;
					break;
				}
				case __constant_htons(PPP_IPV6): {
					ret = edma_get_v6_precedence(skb, nhoff, precedence);
					if (ret)
						return -1;
					break;
				}
				default:
					return -1;
			}
			break;
		}
		default:
			return -1;
	}

	return 0;
}

/* edma_tx_map_and_fill()
 *	gets called from edma_xmit_frame
 *
 * This is where the dma of the buffer to be transmitted
 * gets mapped
 */
static int edma_tx_map_and_fill(struct edma_common_info *edma_cinfo,
				struct edma_adapter *adapter,
				struct sk_buff *skb, int queue_id,
				unsigned int flags_transmit,
				u16 from_cpu, u16 dp_bitmap,
				bool packet_is_rstp, int nr_frags)
{
	struct edma_sw_desc *sw_desc = NULL;
	struct platform_device *pdev = edma_cinfo->pdev;
	struct edma_tx_desc *tpd = NULL;
	struct edma_tx_desc *start_tpd = NULL;
	struct sk_buff *iter_skb;
	int i;
	u32 word1 = 0, word3 = 0, lso_word1 = 0, svlan_tag = 0;
	u16 buf_len, lso_desc_len = 0;

	if (skb_is_gso(skb)) {
		/* TODO: What additional checks need to be performed here */
		if (skb_shinfo(skb)->gso_type & SKB_GSO_TCPV4) {
			lso_word1 |= EDMA_TPD_IPV4_EN;
			ip_hdr(skb)->check = 0;
			tcp_hdr(skb)->check = ~csum_tcpudp_magic(ip_hdr(skb)->saddr,
				ip_hdr(skb)->daddr, 0, IPPROTO_TCP, 0);
		} else if (skb_shinfo(skb)->gso_type & SKB_GSO_TCPV6) {
			lso_word1 |= EDMA_TPD_LSO_V2_EN;
			ipv6_hdr(skb)->payload_len = 0;
			tcp_hdr(skb)->check = ~csum_ipv6_magic(&ipv6_hdr(skb)->saddr,
				&ipv6_hdr(skb)->daddr, 0, IPPROTO_TCP, 0);
		} else
			return -EINVAL;

		lso_word1 |= EDMA_TPD_LSO_EN | ((skb_shinfo(skb)->gso_size & EDMA_TPD_MSS_MASK) << EDMA_TPD_MSS_SHIFT) |
				(skb_transport_offset(skb) << EDMA_TPD_HDR_SHIFT);
	} else if (flags_transmit & EDMA_HW_CHECKSUM) {
			u8 css, cso;
			cso = skb_checksum_start_offset(skb);
			css = cso + skb->csum_offset;

			word1 |= (EDMA_TPD_CUSTOM_CSUM_EN);
			word1 |= (cso >> 1) << EDMA_TPD_HDR_SHIFT;
			word1 |= ((css >> 1) << EDMA_TPD_CUSTOM_CSUM_SHIFT);
	}

	if (skb->protocol == htons(ETH_P_PPP_SES))
		word1 |= EDMA_TPD_PPPOE_EN;

	if (flags_transmit & EDMA_VLAN_TX_TAG_INSERT_FLAG) {
		switch (skb->vlan_proto) {
		case htons(ETH_P_8021Q):
			word3 |= (1 << EDMA_TX_INS_CVLAN);
#if (LINUX_VERSION_CODE <= KERNEL_VERSION(3, 18, 21))
			word3 |= vlan_tx_tag_get(skb) << EDMA_TX_CVLAN_TAG_SHIFT;
#else
			word3 |= skb_vlan_tag_get(skb) << EDMA_TX_CVLAN_TAG_SHIFT;
#endif
			break;
		case htons(ETH_P_8021AD):
			word1 |= (1 << EDMA_TX_INS_SVLAN);
#if (LINUX_VERSION_CODE <= KERNEL_VERSION(3, 18, 21))
			svlan_tag = vlan_tx_tag_get(skb) << EDMA_TX_SVLAN_TAG_SHIFT;
#else
			svlan_tag = skb_vlan_tag_get(skb) << EDMA_TX_SVLAN_TAG_SHIFT;
#endif
			break;
		default:
			dev_err(&pdev->dev, "no ctag or stag present\n");
			goto vlan_tag_error;
		}
	} else if (flags_transmit & EDMA_VLAN_TX_TAG_INSERT_DEFAULT_FLAG) {
		word3 |= (1 << EDMA_TX_INS_CVLAN);
		word3 |= (adapter->default_vlan_tag) << EDMA_TX_CVLAN_TAG_SHIFT;
	}

	if (packet_is_rstp) {
		word3 |= dp_bitmap << EDMA_TPD_PORT_BITMAP_SHIFT;
		word3 |= from_cpu << EDMA_TPD_FROM_CPU_SHIFT;
	} else {
		word3 |= adapter->dp_bitmap << EDMA_TPD_PORT_BITMAP_SHIFT;
	}

	buf_len = skb_headlen(skb);

	if (lso_word1) {
		if (lso_word1 & EDMA_TPD_LSO_V2_EN) {

			/* IPv6 LSOv2 descriptor */
			start_tpd = tpd = edma_get_next_tpd(edma_cinfo, queue_id);
			sw_desc = edma_get_tx_buffer(edma_cinfo, tpd, queue_id);
			sw_desc->flags |= EDMA_SW_DESC_FLAG_SKB_NONE;

			/* LSOv2 descriptor overrides addr field to pass length */
			tpd->addr = cpu_to_le16(skb->len);
			tpd->svlan_tag = svlan_tag;
			tpd->word1 = word1 | lso_word1;
			tpd->word3 = word3;
		}

		tpd = edma_get_next_tpd(edma_cinfo, queue_id);
		if (!start_tpd)
			start_tpd = tpd;
		sw_desc = edma_get_tx_buffer(edma_cinfo, tpd, queue_id);

		/* The last buffer info contain the skb address,
		 * so skb will be freed after unmap
		 */
		sw_desc->length = lso_desc_len;
		sw_desc->flags |= EDMA_SW_DESC_FLAG_SKB_HEAD;

		sw_desc->dma = dma_map_single(&adapter->pdev->dev,
					skb->data, buf_len, DMA_TO_DEVICE);
		if (dma_mapping_error(&pdev->dev, sw_desc->dma))
			goto dma_error;

		tpd->addr = cpu_to_le32(sw_desc->dma);
		tpd->len  = cpu_to_le16(buf_len);

		tpd->svlan_tag = svlan_tag;
		tpd->word1 = word1 | lso_word1;
		tpd->word3 = word3;

		/* The last buffer info contain the skb address,
		 * so it will be freed after unmap
		 */
		sw_desc->length = lso_desc_len;
		sw_desc->flags |= EDMA_SW_DESC_FLAG_SKB_HEAD;

		buf_len = 0;
	}

	if (likely(buf_len)) {

		/* TODO Do not dequeue descriptor if there is a potential error */
		tpd = edma_get_next_tpd(edma_cinfo, queue_id);

		if (!start_tpd)
			start_tpd = tpd;

		sw_desc = edma_get_tx_buffer(edma_cinfo, tpd, queue_id);

		/* The last buffer info contain the skb address,
		 * so it will be free after unmap
		 */
		sw_desc->length = buf_len;
		sw_desc->flags |= EDMA_SW_DESC_FLAG_SKB_HEAD;
		sw_desc->dma = dma_map_single(&adapter->pdev->dev,
			skb->data, buf_len, DMA_TO_DEVICE);
		if (dma_mapping_error(&pdev->dev, sw_desc->dma))
			goto dma_error;

		tpd->addr = cpu_to_le32(sw_desc->dma);
		tpd->len  = cpu_to_le16(buf_len);

		tpd->svlan_tag = svlan_tag;
		tpd->word1 = word1 | lso_word1;
		tpd->word3 = word3;
	}

	i = 0;

	/* Walk through paged frags for head skb */
	while (nr_frags--) {
		skb_frag_t *frag = &skb_shinfo(skb)->frags[i];
		buf_len = skb_frag_size(frag);
		tpd = edma_get_next_tpd(edma_cinfo, queue_id);
		sw_desc = edma_get_tx_buffer(edma_cinfo, tpd, queue_id);
		sw_desc->length = buf_len;
		sw_desc->flags |= EDMA_SW_DESC_FLAG_SKB_FRAG;

		sw_desc->dma = skb_frag_dma_map(&pdev->dev, frag, 0, buf_len, DMA_TO_DEVICE);

		if (dma_mapping_error(NULL, sw_desc->dma))
			goto dma_error;

		tpd->addr = cpu_to_le32(sw_desc->dma);
		tpd->len  = cpu_to_le16(buf_len);

		tpd->svlan_tag = svlan_tag;
		tpd->word1 = word1 | lso_word1;
		tpd->word3 = word3;
		i++;
	}

	/* Walk through all fraglist skbs */
	skb_walk_frags(skb, iter_skb) {
		buf_len = iter_skb->len;
		tpd = edma_get_next_tpd(edma_cinfo, queue_id);
		sw_desc = edma_get_tx_buffer(edma_cinfo, tpd, queue_id);
		sw_desc->length = buf_len;
		sw_desc->dma =  dma_map_single(&adapter->pdev->dev,
				iter_skb->data, buf_len, DMA_TO_DEVICE);

		if (dma_mapping_error(NULL, sw_desc->dma))
			goto dma_error;

		tpd->addr = cpu_to_le32(sw_desc->dma);
		tpd->len  = cpu_to_le16(buf_len);
		tpd->svlan_tag = svlan_tag;
		tpd->word1 = word1 | lso_word1;
		tpd->word3 = word3;
		sw_desc->flags |= EDMA_SW_DESC_FLAG_SKB_FRAGLIST;

		i = 0;

		nr_frags = skb_shinfo(iter_skb)->nr_frags;

		/* Walk through paged frags for this fraglist skb */
		while (nr_frags--) {
			skb_frag_t *frag = &skb_shinfo(iter_skb)->frags[i];
			buf_len = skb_frag_size(frag);
			tpd = edma_get_next_tpd(edma_cinfo, queue_id);
			sw_desc = edma_get_tx_buffer(edma_cinfo, tpd, queue_id);
			sw_desc->length = buf_len;
			sw_desc->flags |= EDMA_SW_DESC_FLAG_SKB_FRAG;

			sw_desc->dma = skb_frag_dma_map(&pdev->dev, frag,
					0, buf_len, DMA_TO_DEVICE);
			if (dma_mapping_error(NULL, sw_desc->dma))
				goto dma_error;

			tpd->addr = cpu_to_le32(sw_desc->dma);
			tpd->len  = cpu_to_le16(buf_len);
			tpd->svlan_tag = svlan_tag;
			tpd->word1 = word1 | lso_word1;
			tpd->word3 = word3;
			i++;
		}
	}

	/* If sysctl support for per-precedence stats are enabled */
	if (edma_per_prec_stats_enable) {
		uint8_t precedence = 0;

		if(!edma_get_skb_precedence(skb, &precedence)) {
			/* Increment per-precedence counters for tx packets
			 * and set the precedence in the TPD.
			 */
			atomic_inc(&edma_cinfo->edma_ethstats.tx_prec[precedence]);
			edma_cinfo->edma_ethstats.tx_ac[edma_dscp2ac_tbl[precedence]]++;
			if (tpd)
				tpd->word3 |= precedence << EDMA_TPD_PRIO_SHIFT;
		}

		/* If sysctl support for IAD stats are enabled */
		if (edma_iad_stats_enable) {
			if (edma_dscp2ac_tbl[precedence] == EDMA_AC_VI)
				edma_iad_process_flow(edma_cinfo, skb, EDMA_EGRESS_DIR, precedence);
		}
	}

	/* If tpd or sw_desc is still unitiialized then we need to return */
	if ((!tpd) || (!sw_desc))
		return -EINVAL;

	tpd->word1 |= 1 << EDMA_TPD_EOP_SHIFT;

	sw_desc->skb = skb;
	sw_desc->flags |= EDMA_SW_DESC_FLAG_LAST;

	return 0;

dma_error:
	edma_rollback_tx(adapter, start_tpd, queue_id);
	dev_err(&pdev->dev, "TX DMA map failed\n");
vlan_tag_error:
	return -ENOMEM;
}

/* edma_check_link()
 *	check Link status
 */
static int edma_check_link(struct edma_adapter *adapter)
{
	struct phy_device *phydev = adapter->phydev;

	if (!(adapter->poll_required))
		return __EDMA_LINKUP;

	if (phydev->link)
		return __EDMA_LINKUP;

	return __EDMA_LINKDOWN;
}

/* edma_adjust_link()
 *	check for edma link status
 */
void edma_adjust_link(struct net_device *netdev)
{
	int status;
	struct edma_adapter *adapter = netdev_priv(netdev);
	struct phy_device *phydev = adapter->phydev;

	if (!test_bit(__EDMA_UP, &adapter->state_flags))
		return;

	status = edma_check_link(adapter);

	if (status == __EDMA_LINKUP && adapter->link_state == __EDMA_LINKDOWN) {
		dev_info(&adapter->pdev->dev, "%s: GMAC Link is up with phy_speed=%d\n", netdev->name, phydev->speed);
		adapter->link_state = __EDMA_LINKUP;
		netif_carrier_on(netdev);
		if (netif_running(netdev))
			netif_tx_wake_all_queues(netdev);
	} else if (status == __EDMA_LINKDOWN && adapter->link_state == __EDMA_LINKUP) {
		dev_info(&adapter->pdev->dev, "%s: GMAC Link is down\n", netdev->name);
		adapter->link_state = __EDMA_LINKDOWN;
		netif_carrier_off(netdev);
		netif_tx_stop_all_queues(netdev);
	}
}

/* edma_get_stats64()
 *	Statistics api used to retreive the tx/rx statistics
 */
struct rtnl_link_stats64 *edma_get_stats64(struct net_device *netdev,
				     struct rtnl_link_stats64 *stats)
{
	struct edma_adapter *adapter = netdev_priv(netdev);

	memcpy(stats, &adapter->stats, sizeof(*stats));

	return stats;
}

/* edma_xmit()
 *	Main api to be called by the core for packet transmission
 */
netdev_tx_t edma_xmit(struct sk_buff *skb,
		     struct net_device *net_dev)
{
	struct edma_adapter *adapter = netdev_priv(net_dev);
	struct edma_common_info *edma_cinfo = adapter->edma_cinfo;
	struct edma_tx_desc_ring *etdr;
	u16 from_cpu = 0, dp_bitmap = 0, txq_id;
	int ret, nr_frags_first = 0, num_tpds_needed = 1, queue_id = 0;
	unsigned int flags_transmit = 0;
	bool packet_is_rstp = false;
	struct netdev_queue *nq = NULL;

	if (skb_shinfo(skb)->nr_frags) {
		nr_frags_first = skb_shinfo(skb)->nr_frags;

		/* It is unlikely below check hits, BUG_ON */
		BUG_ON(nr_frags_first > MAX_SKB_FRAGS);

		num_tpds_needed += nr_frags_first;
	}

	if (skb_has_frag_list(skb)) {
		struct sk_buff *iter_skb;

		/* Walk through fraglist skbs making a note of nr_frags */
		skb_walk_frags(skb, iter_skb) {
			unsigned char nr_frags = skb_shinfo(iter_skb)->nr_frags;

			/* It is unlikely below check hits, BUG_ON */
			BUG_ON(nr_frags > MAX_SKB_FRAGS);

			/* One TPD for skb->data and more for nr_frags */
			num_tpds_needed += (1 + nr_frags);
		}
	}

	if (edma_stp_rstp) {
		u16 ath_hdr, ath_eth_type;
		u8 mac_addr[EDMA_ETH_HDR_LEN];
		ath_eth_type = ntohs(*(uint16_t *)&skb->data[12]);
		if (ath_eth_type == edma_ath_eth_type) {
			packet_is_rstp = true;
			ath_hdr = htons(*(uint16_t *)&skb->data[14]);
			dp_bitmap = ath_hdr & EDMA_TX_ATH_HDR_PORT_BITMAP_MASK;
			from_cpu = (ath_hdr & EDMA_TX_ATH_HDR_FROM_CPU_MASK) >> EDMA_TX_ATH_HDR_FROM_CPU_SHIFT;
			memcpy(mac_addr, skb->data, EDMA_ETH_HDR_LEN);

			skb_pull(skb, 4);

			memcpy(skb->data, mac_addr, EDMA_ETH_HDR_LEN);
		}
	}

	/* this will be one of the 4 TX queues exposed to linux kernel */
	txq_id = skb_get_queue_mapping(skb);
	queue_id = edma_tx_queue_get(adapter, skb, txq_id);
	etdr = edma_cinfo->tpd_ring[queue_id];
	nq = netdev_get_tx_queue(net_dev, txq_id);

	local_bh_disable();
	/* Tx is not handled in bottom half context. Hence, we need to protect
	 * Tx from tasks and bottom half
	 */

	if (num_tpds_needed > edma_tpd_available(edma_cinfo, queue_id)) {
		if (edma_disable_queue_stop) {
			local_bh_enable();
			dev_dbg(&net_dev->dev, "Packet dropped as queue is full");
			dev_kfree_skb_any(skb);
			adapter->stats.tx_errors++;
			return NETDEV_TX_OK;
		}

		/* not enough descriptor, just stop queue */
		netif_tx_stop_queue(nq);
		local_bh_enable();
		dev_dbg(&net_dev->dev, "Not enough descriptors available");
		edma_cinfo->edma_ethstats.tx_desc_error++;
		return NETDEV_TX_BUSY;
	}

	/* Check and mark VLAN tag offload */
#if (LINUX_VERSION_CODE <= KERNEL_VERSION(3, 18, 21))
	if (vlan_tx_tag_present(skb))
#else
	if (skb_vlan_tag_present(skb))
#endif
		flags_transmit |= EDMA_VLAN_TX_TAG_INSERT_FLAG;
	else if (adapter->default_vlan_tag)
		flags_transmit |= EDMA_VLAN_TX_TAG_INSERT_DEFAULT_FLAG;

	/* Check and mark checksum offload */
	if (likely(skb->ip_summed == CHECKSUM_PARTIAL))
		flags_transmit |= EDMA_HW_CHECKSUM;

	/* Map and fill descriptor for Tx */
	ret = edma_tx_map_and_fill(edma_cinfo, adapter, skb, queue_id,
		flags_transmit, from_cpu, dp_bitmap,
		packet_is_rstp, nr_frags_first);
	if (ret) {
		dev_kfree_skb_any(skb);
		adapter->stats.tx_errors++;
		goto netdev_okay;
	}

	/* Update SW producer index */
	edma_tx_update_hw_idx(edma_cinfo, skb, queue_id);

	/* update tx statistics */
	adapter->stats.tx_packets++;
	adapter->stats.tx_bytes += skb->len;

netdev_okay:
	local_bh_enable();
	return NETDEV_TX_OK;
}

/*
 * edma_flow_may_expire()
 *	Timer function called periodically to delete the node
 */
void edma_flow_may_expire(unsigned long data)
{
	struct edma_adapter *adapter = (struct edma_adapter *)data;
	int j;

	spin_lock_bh(&adapter->rfs.rfs_ftab_lock);
	for (j = 0; j < EDMA_RFS_EXPIRE_COUNT_PER_CALL; j++) {
		struct hlist_head *hhead;
		struct hlist_node *tmp;
		struct edma_rfs_filter_node *n;
		bool res;

		hhead = &adapter->rfs.hlist_head[adapter->rfs.hashtoclean++];
		hlist_for_each_entry_safe(n, tmp, hhead, node) {
			res = rps_may_expire_flow(adapter->netdev, n->rq_id,
					n->flow_id, n->filter_id);
			if (res) {
				res = edma_delete_rfs_filter(adapter, n);
				if (res < 0)
					dev_dbg(&adapter->netdev->dev,
							"RFS entry %d not allowed to be flushed by Switch",
							n->flow_id);
				else {
					hlist_del(&n->node);
					kfree(n);
					adapter->rfs.filter_available++;
				}
			}
		}
	}

	adapter->rfs.hashtoclean = adapter->rfs.hashtoclean & (EDMA_RFS_FLOW_ENTRIES - 1);
	spin_unlock_bh(&adapter->rfs.rfs_ftab_lock);
	mod_timer(&adapter->rfs.expire_rfs, jiffies + HZ/4);
}

/* edma_rx_flow_steer()
 *	Called by core to to steer the flow to CPU
 */
int edma_rx_flow_steer(struct net_device *dev, const struct sk_buff *skb,
			u16 rxq, u32 flow_id)
{
	struct flow_keys keys;
	struct edma_rfs_filter_node *filter_node;
	struct edma_adapter *adapter = netdev_priv(dev);
	u16 hash_tblid;
	int res;

	if (skb->protocol == htons(ETH_P_IPV6)) {
		res = -EPROTONOSUPPORT;
		goto no_protocol_err;
	}

	/* Dissect flow parameters
	 * We only support IPv4 + TCP/UDP
	 */
#if (LINUX_VERSION_CODE <= KERNEL_VERSION(3, 18, 21))
	res = skb_flow_dissect(skb, &keys);
	if (!((keys.ip_proto == IPPROTO_TCP) || (keys.ip_proto == IPPROTO_UDP))) {
#else
	res = skb_flow_dissect_flow_keys(skb, &keys, 0);
	if (!((keys.basic.ip_proto == IPPROTO_TCP) || (keys.basic.ip_proto == IPPROTO_UDP))) {
#endif
		res = -EPROTONOSUPPORT;
		goto no_protocol_err;
	}

	/* Check if table entry exists */
	hash_tblid = skb_get_hash_raw(skb) & EDMA_RFS_FLOW_ENTRIES_MASK;

	spin_lock_bh(&adapter->rfs.rfs_ftab_lock);
	filter_node = edma_rfs_key_search(&adapter->rfs.hlist_head[hash_tblid], &keys);

	if (filter_node) {
		if (rxq == filter_node->rq_id) {
			res = -EEXIST;
			goto out;
		} else {
			res = edma_delete_rfs_filter(adapter, filter_node);
			if (res < 0)
				dev_warn(&adapter->netdev->dev,
						"Cannot steer flow %d to different queue",
						filter_node->flow_id);
			else {
				adapter->rfs.filter_available++;
				res = edma_add_rfs_filter(adapter, &keys, rxq, filter_node);
				if (res < 0) {
					dev_warn(&adapter->netdev->dev,
							"Cannot steer flow %d to different queue",
							filter_node->flow_id);
				} else {
					adapter->rfs.filter_available--;
					filter_node->rq_id = rxq;
					filter_node->filter_id = res;
				}
			}
		}
	} else {
		if (adapter->rfs.filter_available == 0) {
			res = -EBUSY;
			goto out;
		}

		filter_node = kmalloc(sizeof(*filter_node), GFP_ATOMIC);
		if (!filter_node) {
			res = -ENOMEM;
			goto out;
		}

		res = edma_add_rfs_filter(adapter, &keys, rxq, filter_node);
		if (res < 0) {
			kfree(filter_node);
			goto out;
		}

		adapter->rfs.filter_available--;
		filter_node->rq_id = rxq;
		filter_node->filter_id = res;
		filter_node->flow_id = flow_id;
		filter_node->keys = keys;
		INIT_HLIST_NODE(&filter_node->node);
		hlist_add_head(&filter_node->node, &adapter->rfs.hlist_head[hash_tblid]);
	}

out:
	spin_unlock_bh(&adapter->rfs.rfs_ftab_lock);
no_protocol_err:
	return res;
}

#ifdef CONFIG_RFS_ACCEL
/* edma_register_rfs_filter()
 *	Add RFS filter callback
 */
int edma_register_rfs_filter(struct net_device *netdev,
			    set_rfs_filter_callback_t set_filter)
{
	struct edma_adapter *adapter = netdev_priv(netdev);

	spin_lock_bh(&adapter->rfs.rfs_ftab_lock);

	if (adapter->set_rfs_rule) {
		spin_unlock_bh(&adapter->rfs.rfs_ftab_lock);
		return -1;
	}

	adapter->set_rfs_rule = set_filter;
	spin_unlock_bh(&adapter->rfs.rfs_ftab_lock);

	return 0;
}
#endif

/* edma_select_xps_queue()
 *	Called by Linux TX stack to populate Linux TX queue
 */
u16 edma_select_xps_queue(struct net_device *dev, struct sk_buff *skb,
				void *accel_priv, select_queue_fallback_t fallback)
{
#if (LINUX_VERSION_CODE <= KERNEL_VERSION(3, 18, 21))
	return smp_processor_id();
#else
	int cpu = get_cpu();
	put_cpu();

	return cpu;
#endif
}

/* edma_alloc_tx_rings()
 *	Allocate rx rings
 */
int edma_alloc_tx_rings(struct edma_common_info *edma_cinfo)
{
	struct platform_device *pdev = edma_cinfo->pdev;
	int i, err = 0;

	for (i = 0; i < edma_cinfo->num_tx_queues; i++) {
		err = edma_alloc_tx_ring(edma_cinfo, edma_cinfo->tpd_ring[i]);
		if (err) {
			dev_err(&pdev->dev, "Tx Queue alloc %u failed\n", i);
			return err;
		}
	}

	return 0;
}

/* edma_free_tx_rings()
 *	Free tx rings
 */
void edma_free_tx_rings(struct edma_common_info *edma_cinfo)
{
	int i;

	for (i = 0; i < edma_cinfo->num_tx_queues; i++)
		edma_free_tx_ring(edma_cinfo, edma_cinfo->tpd_ring[i]);
}

/* edma_free_tx_resources()
 *	Free buffers associated with tx rings
 */
void edma_free_tx_resources(struct edma_common_info *edma_cinfo)
{
	struct edma_tx_desc_ring *etdr;
	struct edma_sw_desc *sw_desc;
	struct platform_device *pdev = edma_cinfo->pdev;
	int i, j;

	for (i = 0; i < edma_cinfo->num_tx_queues; i++) {
		etdr = edma_cinfo->tpd_ring[i];
		for (j = 0; j < edma_cinfo->tx_ring_count; j++) {
			sw_desc = &etdr->sw_desc[j];
			if (sw_desc->flags & (EDMA_SW_DESC_FLAG_SKB_HEAD |
				EDMA_SW_DESC_FLAG_SKB_FRAG | EDMA_SW_DESC_FLAG_SKB_FRAGLIST))
				edma_tx_unmap_and_free(pdev, sw_desc);
		}
	}
}

/* edma_alloc_rx_rings()
 *	Allocate rx rings
 */
int edma_alloc_rx_rings(struct edma_common_info *edma_cinfo)
{
	struct platform_device *pdev = edma_cinfo->pdev;
	int i, j, err = 0;

	for (i = 0, j = 0; i < edma_cinfo->num_rx_queues; i++) {
		err = edma_alloc_rx_ring(edma_cinfo, edma_cinfo->rfd_ring[j]);
		if (err) {
			dev_err(&pdev->dev, "Rx Queue alloc%u failed\n", i);
			return err;
		}
		j += ((edma_cinfo->num_rx_queues == 4) ? 2 : 1);
	}

	return 0;
}

/* edma_free_rx_rings()
 *	free rx rings
 */
void edma_free_rx_rings(struct edma_common_info *edma_cinfo)
{
	int i, j;

	for (i = 0, j = 0; i < edma_cinfo->num_rx_queues; i++) {
		edma_free_rx_ring(edma_cinfo, edma_cinfo->rfd_ring[j]);
		j += ((edma_cinfo->num_rx_queues == 4) ? 2 : 1);
	}
}

/* edma_free_queues()
 *	Free the queues allocaated
 */
void edma_free_queues(struct edma_common_info *edma_cinfo)
{
	int i , j;

	for (i = 0; i < edma_cinfo->num_tx_queues; i++) {
		if (edma_cinfo->tpd_ring[i])
			kfree(edma_cinfo->tpd_ring[i]);
		edma_cinfo->tpd_ring[i] = NULL;
	}

	for (i = 0, j = 0; i < edma_cinfo->num_rx_queues; i++) {
		if (edma_cinfo->rfd_ring[j])
			kfree(edma_cinfo->rfd_ring[j]);
		edma_cinfo->rfd_ring[j] = NULL;
		j += ((edma_cinfo->num_rx_queues == 4) ? 2 : 1);
	}

	edma_cinfo->num_rx_queues = 0;
	edma_cinfo->num_tx_queues = 0;

	return;
}

/* edma_free_rx_resources()
 *	Free buffers associated with tx rings
 */
void edma_free_rx_resources(struct edma_common_info *edma_cinfo)
{
	struct edma_rfd_desc_ring *erdr;
	struct platform_device *pdev = edma_cinfo->pdev;
	int i, j, k;

	for (i = 0, k = 0; i < edma_cinfo->num_rx_queues; i++) {
		erdr = edma_cinfo->rfd_ring[k];
		for (j = 0; j < edma_cinfo->rx_ring_count; j++) {
			/* unmap all descriptors while cleaning */
			edma_clean_rfd(pdev, erdr, j, 1);
		}
		k += ((edma_cinfo->num_rx_queues == 4) ? 2 : 1);

	}
}

/* edma_alloc_queues_tx()
 *	Allocate memory for all rings
 */
int edma_alloc_queues_tx(struct edma_common_info *edma_cinfo)
{
	int i;

	for (i = 0; i < edma_cinfo->num_tx_queues; i++) {
		struct edma_tx_desc_ring *etdr;
		etdr = kzalloc(sizeof(struct edma_tx_desc_ring), GFP_KERNEL);
		if (!etdr)
			goto err;
		etdr->count = edma_cinfo->tx_ring_count;
		edma_cinfo->tpd_ring[i] = etdr;
	}

	return 0;
err:
	edma_free_queues(edma_cinfo);
	return -1;
}

/* edma_alloc_queues_rx()
 *	Allocate memory for all rings
 */
int edma_alloc_queues_rx(struct edma_common_info *edma_cinfo)
{
	int i, j;

	for (i = 0, j = 0; i < edma_cinfo->num_rx_queues; i++) {
		struct edma_rfd_desc_ring *rfd_ring;
		rfd_ring = kzalloc(sizeof(struct edma_rfd_desc_ring),
				GFP_KERNEL);
		if (!rfd_ring)
			goto err;
		rfd_ring->count = edma_cinfo->rx_ring_count;
		edma_cinfo->rfd_ring[j] = rfd_ring;
		j += ((edma_cinfo->num_rx_queues == 4) ? 2 : 1);
	}
	return 0;
err:
	edma_free_queues(edma_cinfo);
	return -1;
}

/* edma_clear_irq_status()
 *	Clear interrupt status
 */
void edma_clear_irq_status(void)
{
	edma_write_reg(EDMA_REG_RX_ISR, 0xff);
	edma_write_reg(EDMA_REG_TX_ISR, 0xffff);
	edma_write_reg(EDMA_REG_MISC_ISR, 0x1fff);
	edma_write_reg(EDMA_REG_WOL_ISR, 0x1);
};

/* edma_configure()
 *	Configure skb, edma interrupts and control register.
 */
int edma_configure(struct edma_common_info *edma_cinfo)
{
	struct edma_hw *hw = &edma_cinfo->hw;
	u32 intr_modrt_data;
	u32 intr_ctrl_data = 0;
	int i, j, ret_count;

	edma_read_reg(EDMA_REG_INTR_CTRL, &intr_ctrl_data);
	intr_ctrl_data &= ~(1 << EDMA_INTR_SW_IDX_W_TYP_SHIFT);
	intr_ctrl_data |= hw->intr_sw_idx_w << EDMA_INTR_SW_IDX_W_TYP_SHIFT;
	edma_write_reg(EDMA_REG_INTR_CTRL, intr_ctrl_data);

	edma_clear_irq_status();

	/* Clear any WOL status */
	edma_write_reg(EDMA_REG_WOL_CTRL, 0);
	intr_modrt_data = (EDMA_TX_IMT << EDMA_IRQ_MODRT_TX_TIMER_SHIFT);
	intr_modrt_data |= (EDMA_RX_IMT << EDMA_IRQ_MODRT_RX_TIMER_SHIFT);
	edma_write_reg(EDMA_REG_IRQ_MODRT_TIMER_INIT, intr_modrt_data);
	edma_configure_tx(edma_cinfo);
	edma_configure_rx(edma_cinfo);

	/* Allocate the RX buffer */
	for (i = 0, j = 0; i < edma_cinfo->num_rx_queues; i++) {
		struct edma_rfd_desc_ring *ring = edma_cinfo->rfd_ring[j];
		ret_count = edma_alloc_rx_buf(edma_cinfo, ring, ring->count, j);
		if (ret_count)
			dev_dbg(&edma_cinfo->pdev->dev, "not all rx buffers allocated\n");
		ring->pending_fill = ret_count;
		j += ((edma_cinfo->num_rx_queues == 4) ? 2 : 1);
	}

	/* Configure descriptor Ring */
	edma_init_desc(edma_cinfo);
	return 0;
}

/* edma_irq_enable()
 *	Enable default interrupt generation settings
 */
void edma_irq_enable(struct edma_common_info *edma_cinfo)
{
	struct edma_hw *hw = &edma_cinfo->hw;
	int i, j;

	edma_write_reg(EDMA_REG_RX_ISR, 0xff);
	for (i = 0, j = 0; i < edma_cinfo->num_rx_queues; i++) {
		edma_write_reg(EDMA_REG_RX_INT_MASK_Q(j), hw->rx_intr_mask);
		j += ((edma_cinfo->num_rx_queues == 4) ? 2 : 1);
	}
	edma_write_reg(EDMA_REG_TX_ISR, 0xffff);
	for (i = 0; i < edma_cinfo->num_tx_queues; i++)
		edma_write_reg(EDMA_REG_TX_INT_MASK_Q(i), hw->tx_intr_mask);
}

/* edma_irq_disable()
 *	Disable Interrupt
 */
void edma_irq_disable(struct edma_common_info *edma_cinfo)
{
	int i;

	for (i = 0; i < EDMA_MAX_RECEIVE_QUEUE; i++)
		edma_write_reg(EDMA_REG_RX_INT_MASK_Q(i), 0x0);

	for (i = 0; i < EDMA_MAX_TRANSMIT_QUEUE; i++)
		edma_write_reg(EDMA_REG_TX_INT_MASK_Q(i), 0x0);
	edma_write_reg(EDMA_REG_MISC_IMR, 0);
	edma_write_reg(EDMA_REG_WOL_IMR, 0);
}

/* edma_free_irqs()
 *	Free All IRQs
 */
void edma_free_irqs(struct edma_adapter *adapter)
{
	struct edma_common_info *edma_cinfo = adapter->edma_cinfo;
	int i, j;
	int k = ((edma_cinfo->num_rx_queues == 4) ? 1 : 2);

	for (i = 0; i < CONFIG_NR_CPUS; i++) {
		for (j = edma_cinfo->edma_percpu_info[i].tx_comp_start; j < (edma_cinfo->edma_percpu_info[i].tx_comp_start + 4); j++)
			free_irq(edma_cinfo->tx_irq[j], &edma_cinfo->edma_percpu_info[i]);

		for (j = edma_cinfo->edma_percpu_info[i].rx_start; j < (edma_cinfo->edma_percpu_info[i].rx_start + k); j++)
			free_irq(edma_cinfo->rx_irq[j], &edma_cinfo->edma_percpu_info[i]);
	}
}

/* edma_enable_rx_ctrl()
 *	Enable RX queue control
 */
void edma_enable_rx_ctrl(struct edma_hw *hw)
{
	u32 data;

	edma_read_reg(EDMA_REG_RXQ_CTRL, &data);
	data |= EDMA_RXQ_CTRL_EN;
	edma_write_reg(EDMA_REG_RXQ_CTRL, data);
}


/* edma_enable_tx_ctrl()
 *	Enable TX queue control
 */
void edma_enable_tx_ctrl(struct edma_hw *hw)
{
	u32 data;

	edma_read_reg(EDMA_REG_TXQ_CTRL, &data);
	data |= EDMA_TXQ_CTRL_TXQ_EN;
	edma_write_reg(EDMA_REG_TXQ_CTRL, data);
}

/* edma_stop_rx_tx()
 *	Disable RX/TQ Queue control
 */
void edma_stop_rx_tx(struct edma_hw *hw)
{
	u32 data;

	edma_read_reg(EDMA_REG_RXQ_CTRL, &data);
	data &= ~EDMA_RXQ_CTRL_EN;
	edma_write_reg(EDMA_REG_RXQ_CTRL, data);
	edma_read_reg(EDMA_REG_TXQ_CTRL, &data);
	data &= ~EDMA_TXQ_CTRL_TXQ_EN;
	edma_write_reg(EDMA_REG_TXQ_CTRL, data);
}

/* edma_reset()
 *	Reset the EDMA
 */
int edma_reset(struct edma_common_info *edma_cinfo)
{
	struct edma_hw *hw = &edma_cinfo->hw;

	edma_irq_disable(edma_cinfo);

	edma_clear_irq_status();

	edma_stop_rx_tx(hw);

	return 0;
}

/* edma_fill_netdev()
 *	Fill netdev for each etdr
 */
int edma_fill_netdev(struct edma_common_info *edma_cinfo, int queue_id,
		    int dev, int txq_id)
{
	struct edma_tx_desc_ring *etdr;
	int i = 0;

	etdr = edma_cinfo->tpd_ring[queue_id];

	while (etdr->netdev[i])
		i++;

	if (i >= EDMA_MAX_NETDEV_PER_QUEUE)
		return -1;

	/* Populate the netdev associated with the tpd ring */
	etdr->netdev[i] = edma_netdev[dev];
	etdr->nq[i] = netdev_get_tx_queue(edma_netdev[dev], txq_id);

	return 0;
}

/* edma_change_mtu()
 *	change the MTU of the NIC.
 */
int edma_change_mtu(struct net_device *netdev, int new_mtu)
{
	struct edma_adapter *adapter = netdev_priv(netdev);
	struct edma_common_info *edma_cinfo = adapter->edma_cinfo;
	int old_mtu = netdev->mtu;
	int max_frame_size = new_mtu + ETH_HLEN + ETH_FCS_LEN + (2 * VLAN_HLEN);

	if ((max_frame_size < ETH_ZLEN + ETH_FCS_LEN) ||
		(max_frame_size > EDMA_MAX_JUMBO_FRAME_SIZE)) {
			dev_err(&edma_cinfo->pdev->dev, "MTU setting not correct\n");
			return -EINVAL;
	}

	/* set MTU */
	if (old_mtu != new_mtu) {
		netdev->mtu = new_mtu;
		netdev_update_features(netdev);
	}

	return 0;
}

/* edma_set_mac()
 *	Change the Ethernet Address of the NIC
 */
int edma_set_mac_addr(struct net_device *netdev, void *p)
{
	struct sockaddr *addr = p;

	if (!is_valid_ether_addr(addr->sa_data))
		return -EINVAL;

	if (netif_running(netdev))
		return -EBUSY;

	memcpy(netdev->dev_addr, addr->sa_data, netdev->addr_len);
	return 0;
}

/* edma_set_stp_rstp()
 *	set stp/rstp
 */
void edma_set_stp_rstp(bool rstp)
{
	edma_stp_rstp = rstp;
}

/* edma_assign_ath_hdr_type()
 *	assign atheros header eth type
 */
void edma_assign_ath_hdr_type(int eth_type)
{
	edma_ath_eth_type = eth_type & EDMA_ETH_TYPE_MASK;
}

/* edma_get_default_vlan_tag()
 *	Used by other modules to get the default vlan tag
 */
int edma_get_default_vlan_tag(struct net_device *netdev)
{
	struct edma_adapter *adapter = netdev_priv(netdev);

	if (adapter->default_vlan_tag)
		return adapter->default_vlan_tag;

	return 0;
}

/* edma_open()
 *	gets called when netdevice is up, start the queue.
 */
int edma_open(struct net_device *netdev)
{
	struct edma_adapter *adapter = netdev_priv(netdev);
	struct platform_device *pdev = adapter->edma_cinfo->pdev;
	struct edma_common_info *edma_cinfo = adapter->edma_cinfo;

	edma_initialise_rfs_flow_table(adapter);

	/* We enable irq only in first edma_open call.
	 * We do this to make sure we do not receive
	 * packets before affinities are set in the
	 * qca-edma script
	 */
	if (!edma_cinfo->is_first_open_done) {
		/* Enable all 16 tx and 8 rx irq mask */
		edma_irq_enable(edma_cinfo);
		edma_cinfo->is_first_open_done = true;
	}

	netif_tx_start_all_queues(netdev);
	set_bit(__EDMA_UP, &adapter->state_flags);

	/* if Link polling is enabled, in our case enabled for WAN, then
	 * do a phy start, else always set link as UP
	 */
	mutex_lock(&adapter->poll_mutex);
	if (adapter->poll_required) {
		if (!IS_ERR(adapter->phydev)) {
			phy_start(adapter->phydev);
			phy_start_aneg(adapter->phydev);
			adapter->link_state = __EDMA_LINKDOWN;
		} else {
			dev_dbg(&pdev->dev, "Invalid PHY device for a link polled interface\n");
		}
	} else {
		adapter->link_state = __EDMA_LINKUP;
		netif_carrier_on(netdev);
	}
	mutex_unlock(&adapter->poll_mutex);

	return 0;
}


/* edma_close()
 *	gets called when netdevice is down, stops the queue.
 */
int edma_close(struct net_device *netdev)
{
	struct edma_adapter *adapter = netdev_priv(netdev);

	edma_free_rfs_flow_table(adapter);
	netif_carrier_off(netdev);
	netif_tx_stop_all_queues(netdev);

	mutex_lock(&adapter->poll_mutex);
	if (adapter->poll_required) {
		if (!IS_ERR(adapter->phydev))
			phy_stop(adapter->phydev);
	}
	mutex_unlock(&adapter->poll_mutex);

	adapter->link_state = __EDMA_LINKDOWN;

	/* Set GMAC state to UP before link state is checked
	 */
	clear_bit(__EDMA_UP, &adapter->state_flags);

	return 0;
}

/* edma_poll
 *	polling function that gets called when the napi gets scheduled.
 *
 * Main sequence of task performed in this api
 * is clear irq status -> clear_tx_irq -> clean_rx_irq->
 * enable interrupts.
 */
int edma_poll(struct napi_struct *napi, int budget)
{
	struct edma_per_cpu_queues_info *edma_percpu_info = container_of(napi,
		struct edma_per_cpu_queues_info, napi);
	struct edma_common_info *edma_cinfo = edma_percpu_info->edma_cinfo;
	u32 reg_data;
	u32 shadow_rx_status, shadow_tx_status;
	int queue_id;
	int i, work_done = 0;
	u16 rx_pending_fill;

	/* Store the Rx/Tx status by ANDing it with
	 * appropriate CPU RX?TX mask
	 */
	edma_read_reg(EDMA_REG_RX_ISR, &reg_data);
	edma_percpu_info->rx_status |= reg_data & edma_percpu_info->rx_mask;
	shadow_rx_status = edma_percpu_info->rx_status;
	edma_read_reg(EDMA_REG_TX_ISR, &reg_data);
	edma_percpu_info->tx_status |= reg_data & edma_percpu_info->tx_mask;
	shadow_tx_status = edma_percpu_info->tx_status;

	/* Every core will have a start, which will be computed
	 * in probe and stored in edma_percpu_info->tx_start variable.
	 * We will shift the status bit by tx_start to obtain
	 * status bits for the core on which the current processing
	 * is happening. Since, there are 4 tx queues per core,
	 * we will run the loop till we get the correct queue to clear.
	 */
	while (edma_percpu_info->tx_status) {
		queue_id = ffs(edma_percpu_info->tx_status) - 1;
		edma_tx_complete(edma_cinfo, queue_id);
		edma_percpu_info->tx_status &= ~(1 << queue_id);
	}

	/* Every core will have a start, which will be computed
	 * in probe and stored in edma_percpu_info->tx_start variable.
	 * We will shift the status bit by tx_start to obtain
	 * status bits for the core on which the current processing
	 * is happening. Since, there are 4 tx queues per core, we
	 * will run the loop till we get the correct queue to clear.
	 */
	while (edma_percpu_info->rx_status) {
		queue_id = ffs(edma_percpu_info->rx_status) - 1;
		rx_pending_fill = edma_rx_complete(edma_cinfo, &work_done,
					budget, queue_id, napi);

		if (likely(work_done < budget)) {
			 if (rx_pending_fill) {
				work_done = budget;
				break;
			}

			edma_percpu_info->rx_status &= ~(1 << queue_id);
		}
		else
			break;
	}

	/* Clear the status register, to avoid the interrupts to
	 * reoccur.This clearing of interrupt status register is
	 * done here as writing to status register only takes place
	 * once the  producer/consumer index has been updated to
	 * reflect that the packet transmission/reception went fine.
	 */
	edma_write_reg(EDMA_REG_RX_ISR, shadow_rx_status);
	edma_write_reg(EDMA_REG_TX_ISR, shadow_tx_status);

	/* If budget not fully consumed, exit the polling mode */
	if (likely(work_done < budget)) {
		napi_complete(napi);

		/* re-enable the interrupts */
		for (i = 0; i < edma_cinfo->num_rxq_per_core; i++)
			edma_write_reg(EDMA_REG_RX_INT_MASK_Q(edma_percpu_info->rx_start + i), 0x1);
		for (i = 0; i < edma_cinfo->num_txq_per_core; i++)
			edma_write_reg(EDMA_REG_TX_INT_MASK_Q(edma_percpu_info->tx_comp_start + i), 0x1);
	}

	return work_done;
}

/* edma interrupt()
 *	interrupt handler
 */
irqreturn_t edma_interrupt(int irq, void *dev)
{
	struct edma_per_cpu_queues_info *edma_percpu_info = (struct edma_per_cpu_queues_info *) dev;
	struct edma_common_info *edma_cinfo = edma_percpu_info->edma_cinfo;
	int i;

	/* Unmask the TX/RX interrupt register */
	for (i = 0; i < edma_cinfo->num_rxq_per_core; i++)
		edma_write_reg(EDMA_REG_RX_INT_MASK_Q(edma_percpu_info->rx_start + i), 0x0);

	for (i = 0; i < edma_cinfo->num_txq_per_core; i++)
		edma_write_reg(EDMA_REG_TX_INT_MASK_Q(edma_percpu_info->tx_comp_start + i), 0x0);

	napi_schedule(&edma_percpu_info->napi);

	return IRQ_HANDLED;
}
