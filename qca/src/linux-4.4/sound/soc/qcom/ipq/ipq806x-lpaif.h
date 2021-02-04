/* Copyright (c) 2010-2011,2013,2017, The Linux Foundation. All rights reserved.
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

#ifndef IPQ_LPA_IF_H
#define IPQ_LPA_IF_H

#define MAX_LPAIF_CHANNELS 9

#define IPQ_LPAIF_PHYS		0x28100000
#define IPQ_LPAIF_END		0x2810ffff

#define LPAIF_PCM(x)		(0x0004 + (0x4 * x))

#define LPA_IF_CODEC_SPK	0x0
#define LPA_IF_CODEC_MIC	0x1
#define LPA_IF_SEC_SPK		0x2
#define LPA_IF_SEC_MIC		0x3
#define LPA_IF_MI2S		0x4

#define LPA_IF_LB		(1 << 15)
#define LPA_IF_SPK_EN		(1 << 14)

#define LPA_IF_SPK_MODE_MASK	0x3C00
#define LPA_IF_SPK_MODE		10
#define LPA_IF_SPK_MODE_NONE	(0 << 10)
#define LPA_IF_SPK_MODE_SD0	(1 << 10)
#define LPA_IF_SPK_MODE_SD1	(2 << 10)
#define LPA_IF_SPK_MODE_SD2	(3 << 10)
#define LPA_IF_SPK_MODE_SD3	(4 << 10)
#define LPA_IF_SPK_MODE_QUAD01	(5 << 10)
#define LPA_IF_SPK_MODE_QUAD23	(6 << 10)
#define LPA_IF_SPK_MODE_6CH	(7 << 10)
#define LPA_IF_SPK_MODE_8CH	(8 << 10)


#define LPA_IF_SPK_MONO		(1 << 9)
#define LPA_IF_MIC_EN		(1 << 8)
#define LPA_IF_MIC_MODE_MASK	0xf0
#define LPA_IF_MIC_MODE_NONE	(0 << 4)
#define LPA_IF_MIC_MODE_SD0	(1 << 4)
#define LPA_IF_MIC_MODE_SD1	(2 << 4)
#define LPA_IF_MIC_MODE_SD2	(3 << 4)
#define LPA_IF_MIC_MODE_SD3	(4 << 4)
#define LPA_IF_MIC_MODE_QD01	(5 << 4)
#define LPA_IF_MIC_MODE_QD23	(6 << 4)
#define LPA_IF_MIC_MODE_6CH	(7 << 4)
#define LPA_IF_MIC_MODE_8CH	(8 << 4)
#define LPA_IF_MIC_MODE_MONO	(1 << 3)

#define LPA_IF_WS		(1 << 2)

#define LPA_IF_BIT_MASK		(0x3)
#define LPA_IF_BIT_RATE16	(0 << 0)
#define LPA_IF_BIT_RATE24	(1 << 0)
#define LPA_IF_BIT_RATE32	(2 << 0)


/* LPA_IF_INTERRUPT_CTRL */

#define BANK_OFFSET			0x1000
#define DMA_IRQ_BASE			0x3000
#define DMA_IRQ_INDEX(x)		(BANK_OFFSET * x)
#define DMA_IRQ_ADDR(irq, addr)		(DMA_IRQ_BASE  \
						+ DMA_IRQ_INDEX(irq) + addr)

#define LPAIF_IRQ_EN(x)			DMA_IRQ_ADDR(x, 0x00)
#define LPAIF_IRQ_STAT(x)		DMA_IRQ_ADDR(x, 0x04)
#define LPAIF_IRQ_RAW_STAT(x)		DMA_IRQ_ADDR(x, 0x08)
#define LPAIF_IRQ_CLEAR(x)		DMA_IRQ_ADDR(x, 0x0c)
#define LPAIF_IRQ_FORCE(x)		DMA_IRQ_ADDR(x, 0x10)
#define PER_CH(x)			(1 << (3 * x))
#define UNDER_CH(x)			(2 << (3 * x))
#define ERR_CH(x)			(4 << (3 * x))

#define LPA_IF_FRAME_REF	(1 << 27)
#define LPA_IF_ERR_CH8		(1 << 26)
#define LPA_IF_OVR_CH8		(1 << 25)
#define LPA_IF_PER_CH8		(1 << 24)
#define LPA_IF_ERR_CH7		(1 << 23)
#define LPA_IF_OVR_CH7		(1 << 22)
#define LPA_IF_PER_CH7		(1 << 21)
#define LPA_IF_ERR_CH6		(1 << 20)
#define LPA_IF_OVR_CH6		(1 << 19)
#define LPA_IF_PER_CH6		(1 << 18)
#define LPA_IF_ERR_CH5		(1 << 17)
#define LPA_IF_OVR_CH5		(1 << 16)
#define LPA_IF_PER_CH5		(1 << 15)
#define LPA_IF_ERR_CH4		(1 << 14)
#define LPA_IF_UNDR_CH4		(1 << 13)
#define LPA_IF_PER_CH4		(1 << 12)
#define LPA_IF_ERR_CH3		(1 << 11)
#define LPA_IF_UNDR_CH3		(1 << 10)
#define LPA_IF_PER_CH3		(1 << 9)
#define LPA_IF_ERR_CH2		(1 << 8)
#define LPA_IF_UNDR_CH2		(1 << 7)
#define LPA_IF_PER_CH2		(1 << 6)
#define LPA_IF_ERR_CH1		(1 << 5)
#define LPA_IF_UNDR_CH1		(1 << 4)
#define LPA_IF_PER_CH1		(1 << 3)
#define LPA_IF_ERR_CH0		(1 << 2)
#define LPA_IF_UNDR_CH0		(1 << 1)
#define LPA_IF_PER_CH0		(1 << 0)

/* DMA CTRL */
#define LPA_IF_DMACTL_CH0	0x28107000
#define LPA_IF_DMACTL_CH1	0x28108000
#define LPA_IF_DMACTL_CH2	0x28109000
#define LPA_IF_DMACTL_CH3	0x2810a000
#define LPA_IF_DMACTL_CH4	0x2810b000
#define LPA_IF_DMACTL_CH5	0x2810c000
#define LPA_IF_DMACTL_CH6	0x2810d000
#define LPA_IF_DMACTL_CH7	0x2810e000
#define LPA_IF_DMACTL_CH8	0x2810f000

#define LPA_IF_DMACTL(x)		(0x6000 + (0x1000*x))
#define LPAIF_MI2S_CTL_OFFSET(x)	(0x0010 + (0x4 * x))

#define LPA_IF_DMACTL_BURST_EN			(1 << 11)
#define LPA_IF_DMACTL_WPSCNT_MASK		(0x700)
#define LPA_IF_DMACTL_WPSCNT_MONO		(0 << 8)
#define LPA_IF_DMACTL_WPSCNT_STEREO		(1 << 8)
#define LPA_IF_DMACTL_WPSCNT_STEREO_2CH		(0 << 8)
#define LPA_IF_DMACTL_WPSCNT_3CH		(2 << 8)
#define LPA_IF_DMACTL_WPSCNT_4CH		(3 << 8)
#define LPA_IF_DMACTL_WPSCNT_5CH		(4 << 8)
#define LPA_IF_DMACTL_WPSCNT_6CH		(5 << 8)
#define LPA_IF_DMACTL_WPSCNT_7CH		(6 << 8)
#define LPA_IF_DMACTL_WPSCNT_8CH		(7 << 8)

#define LPA_IF_DMACTL_AUDIO_INTF_MASK		(0xF0)
#define LPA_IF_DMACTL_AUDIO_INTF_NONE		(0 << 4)
#define LPA_IF_DMACTL_AUDIO_INTF_CODEC		(1 << 4)
#define LPA_IF_DMACTL_AUDIO_INTF_PCM		(2 << 4)
#define LPA_IF_DMACTL_AUDIO_INTF_SEC_I2S	(3 << 4)
#define LPA_IF_DMACTL_AUDIO_INTF_MI2S		(4 << 4)
#define LPA_IF_DMACTL_AUDIO_INTF_HDMI		(5 << 4)
#define LPA_IF_DMACTL_AUDIO_INTF_MIXOUT		(6 << 4)
#define LPA_IF_DMACTL_AUDIO_INTF_LB1		(7 << 4)
#define LPA_IF_DMACTL_AUDIO_INTF_LB2		(8 << 4)

#define LPA_IF_DMACTL_FIFO_WM_1			(0 << 1)
#define LPA_IF_DMACTL_FIFO_WM_2			(1 << 1)
#define LPA_IF_DMACTL_FIFO_WM_3			(2 << 1)
#define LPA_IF_DMACTL_FIFO_WM_4			(3 << 1)
#define LPA_IF_DMACTL_FIFO_WM_5			(4 << 1)
#define LPA_IF_DMACTL_FIFO_WM_6			(5 << 1)
#define LPA_IF_DMACTL_FIFO_WM_7			(6 << 1)
#define LPA_IF_DMACTL_FIFO_WM_8			(7 << 1)

#define LPA_IF_DMACTL_ENABLE			(1 << 0)

#define LPA_IF_DMA_BASE_ADDR(x)			(0x6004 + (0x1000 * x))
#define LPA_IF_DMA_BUFF_LEN(x)			(0x6008 + (0x1000 * x))
#define LPA_IF_DMA_CURR_ADDR(x)			(0x600c + (0x1000 * x))
#define LPA_IF_DMA_PER_LEN(x)			(0x6010 + (0x1000 * x))
#define LPA_IF_DMA_PER_CNT(x)			(0x6014 + (0x1000 * x))
#define LPA_IF_DMA_FRM(x)			(0x6018 + (0x1000 * x))

#define DMA_DONE		0x0
#define DMA_ERR			1


/* PCM CTRL */
#define LPA_IF_PCM_0		0x0
#define LPA_IF_PCM_CTL_8_BITS	(0 << 15)
#define LPA_IF_PCM_CTL_16_BITS	(1 << 15)
#define LPA_IF_PCM_CTL_32_BITS	(2 << 15)
#define LPA_IF_PCM_CTL_64_BITS	(3 << 15)
#define LPA_IF_PCM_CTL_128_BITS	(4 << 15)
#define LPA_IF_PCM_CTL_256_BITS	(5 << 15)

#define LPA_IF_PCM_CTL_LO	(1 << 14)
#define LPA_IF_PCM_SYNC_SRC_INT	(1 << 13)
#define LPA_IF_PCM_AUX_MODE	(1 << 12)
#define LPA_IF_PCM_RPCM_WIDTH	(1 << 11)
#define LPA_IF_PCM_TPCM_WIDTH	(1 << 10)
#define LPA_IF_RPCM_SLOT_MASK	(0x03E0)
#define LPA_IF_TPCM_SLOT_MASK	(0x001F)
#define LPA_IF_PCM_RATE_MASK	(7 << 15)

#define LPA_IF_PCM_RPCM_SLOT(x)	(x << 5)
#define LPA_IF_PCM_TPCM_SLOT(x)	(x << 0)

/* AK 2.0 specific CTL register */
#define LPA_IF_PCM_SLOT_CTL0		0x0004
#define LPA_IF_PCM_RPCM_SLOT1(x)	((x) << 0)
#define LPA_IF_PCM_RPCM_SLOT2(x)	((x) << 5)
#define LPA_IF_PCM_RPCM_SLOT3(x)	((x) << 10)
#define LPA_IF_PCM_TPCM_SLOT1(x)	((x) << 15)
#define LPA_IF_PCM_RPCM_SLOT1_MASK	0x1F
#define LPA_IF_PCM_RPCM_SLOT2_MASK	0x3E0
#define LPA_IF_PCM_RPCM_SLOT3_MASK	0x7C00
#define LPA_IF_PCM_TPCM_SLOT1_MASK	0xF8000
#define LPA_IF_PCM_SLOT2_CTL0		0x0018
#define LPA_IF_PCM_TPCM_SLOT2(x)	((x) << 0)
#define LPA_IF_PCM_TPCM_SLOT3(x)	((x) << 5)
#define LPA_IF_PCM_TPCM_SLOT_COUNT(x)	((x) << 10)
#define LPA_IF_PCM_RPCM_SLOT_COUNT(x)	((x) << 12)
#define LPA_IF_PCM_EN_ALL_SLOTS		(1 << 14)
#define LPA_IF_PCM_TPCM_SLOT2_MASK	0x1F
#define LPA_IF_PCM_TPCM_SLOT3_MASK	0x3E0
#define LPA_IF_PCM_TPCM_SLOT_COUNT_MASK	0xC00
#define LPA_IF_PCM_RPCM_SLOT_COUNT_MASK	0x3000
#define LPA_IF_PCM_MAX_ACT_SLOT		0x4
#define LPA_IF_PCM_DEFAULT_SLOT_COUNT	1

#define __BIT_8		8
#define __BIT_16	16
#define __BIT_24	24
#define __BIT_32	32
#define __BIT_INVAL	-1

#define __BIT_DIV_8	8
#define __BIT_DIV_4	4
#define __BIT_DIV_2	2
#define __BIT_DIV_1	1
#define __BIT_DIV_INVAL	-1

/*
 * LPASS CLK specific, temporary, we need to put this
 * in a separate LPASS specific clock header file
 */
#define LCC_PCM_NS_ARES		(1 << 13)
#define LPAIF_PCM_ASSERT	(1)
#define LPAIF_PCM_DEASSERT	(0)

enum mi2s_samp_freq {
	FREQ_8000 = 8000,
	FREQ_11025 = 11025,
	FREQ_16000 = 16000,
	FREQ_22050 = 22050,
	FREQ_32000 = 32000,
	FREQ_44100 = 44100,
	FREQ_48000 = 48000,
	FREQ_64000 = 64000,
	FREQ_88200 = 88200,
	FREQ_96000 = 96000,
	FREQ_176400 = 176400,
	FREQ_192000 = 192000,
};

enum pcm_rates {
	PCM_RATE_8000 = 8000,
	PCM_RATE_16000 = 16000,
};

enum LPA_IF_TPCM_SLOT {
	LPA_IF_TPCM_SLOT0 = 0,
	LPA_IF_TPCM_SLOT1,
	LPA_IF_TPCM_SLOT2,
	LPA_IF_TPCM_SLOT3,
	LPA_IF_TPCM_MAX_SLOT = 4,
};

enum LPA_IF_RPCM_SLOT {
	LPA_IF_RPCM_SLOT0 = 0,
	LPA_IF_RPCM_SLOT1,
	LPA_IF_RPCM_SLOT2,
	LPA_IF_RPCM_SLOT3,
	LPA_IF_RPCM_MAX_SLOT = 4,
};

struct dai_dma_params {
	u8 *buffer;
	uint32_t src_start;
	uint32_t bus_id;
	int buffer_size;
	int period_size;
	int channels;
};

enum {
	DAI_SPKR = 0,
	DAI_MIC,
	DAI_MI2S,
	DAI_SEC_SPKR,
	DAI_SEC_MIC,
};

struct ipq_lpaif_dai_baseinfo {
	void __iomem *base;
	int irq;
};

struct mi2s_hw_params {
	uint8_t channels;
	uint32_t freq;
	uint8_t bit_width;
};

struct dai_drv {
	unsigned char *buffer;
	unsigned int buffer_phys;
	int channels;
	irqreturn_t (*callback)(int intrsrc, void *private_data);
	void *private_data;
	int in_use;
	unsigned int buffer_len;
	unsigned int period_len;
	unsigned int master_mode;
};

extern struct ipq_lpaif_dai_baseinfo dai_info;

extern void ipq_lpaif_register_dma_irq_handler(int dma_ch,
	irqreturn_t (*callback)(int intrSrc, void *private_data),
	void *private_data);
extern void ipq_lpaif_unregister_dma_irq_handler(int dma_ch);
extern int ipq_lpaif_dai_stop(uint32_t dma_ch);
extern uint8_t ipq_lpaif_irq_disable(uint8_t dma_ch);
extern uint8_t ipq_lpaif_mi2s_disable(void);
extern int ipq_lpaif_pcm_stop(uint32_t dma_ch);
extern void ipq_cfg_pcm_reset(uint8_t);
extern void ipq_cfg_pcm_sync_src(uint8_t);
extern void ipq_cfg_pcm_slot(uint8_t, uint8_t);
extern void ipq_cfg_pcm_width(uint8_t bit_width, uint8_t dir);
extern void ipq_cfg_pcm_rate(uint32_t rate);
extern int ipq_cfg_mi2s_hwparams_bit_width(uint32_t bit_width, uint32_t off);
extern int ipq_cfg_mi2s_capture_hwparams_channels(uint32_t channels,
				uint32_t off, uint32_t bit_width);
extern int ipq_cfg_mi2s_playback_hwparams_channels(uint32_t channels,
				uint32_t off, uint32_t bit_width);
extern uint8_t ipq_lpaif_dma_stop(uint8_t dma_ch);
extern uint8_t ipq_lpaif_dma_start(uint8_t dma_ch);
extern void ipq_cfg_i2s_spkr(uint8_t enable, uint32_t mode, uint32_t off);
extern void ipq_cfg_i2s_mic(uint8_t enable, uint32_t off);
extern void ipq_pcm_start(void);
extern void ipq_pcm_stop(void);
extern int ipq_lpaif_cfg_dma(uint32_t dma_ch, struct dai_dma_params *params,
					uint32_t bit_width, bool enable_intr);
extern int ipq_pcm_int_enable(uint8_t dma_ch);
extern int ipq_pcm_int_disable(uint8_t dma_ch);
extern void ipq_lpaif_disable_dma(uint32_t dma_ch);
extern int ipq_lpaif_dai_config_dma(uint32_t dma_ch);
extern void ipq_cfg_pcm_aux_mode(uint8_t mode);
extern void ipq_cfg_mi2s_disable(uint32_t off);
extern int ipq_cfg_pcm_rx_active_slot(uint32_t slot, uint32_t val);
extern int ipq_cfg_pcm_tx_active_slot(uint32_t slot, uint32_t val);
extern int ipq_cfg_pcm_active_slot_count(uint8_t slot_count, uint8_t dir);

#endif /* _IPQ_LPA_IF_H */
