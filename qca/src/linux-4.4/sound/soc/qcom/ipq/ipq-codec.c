/*
 * Copyright (c) 2015-2016, The Linux Foundation. All rights reserved.
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
 *
 */

#include <linux/module.h>
#include <linux/init.h>
#include <sound/soc.h>
#include <sound/pcm.h>
#include <sound/soc.h>
#include <sound/soc-dai.h>
#include <sound/control.h>
#include <linux/platform_device.h>
#include <linux/spi/spi.h>
#include <linux/i2c.h>
#include <linux/gpio.h>
#include <linux/delay.h>
#include <linux/regmap.h>
#include <sound/initval.h>
#include <sound/core.h>
#include <sound/pcm.h>
#include <sound/pcm_params.h>
#include <linux/of_device.h>

#include "ipq-adss.h"
#include "ipq-codec.h"

struct audio_hw_params audio_params;
static struct regmap *akd4613_regmap;

static const u8 akd4613_reg[AK4613_MAX_REG] = {
	0x0F, 0x07, 0x3F, 0x20, 0x20, 0x55, 0x05, 0x07,
	0x0F, 0x07, 0x3F, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};

uint8_t ipq_compare_hw_params(struct audio_hw_params *curr_params)
{
	if ((curr_params->bit_width == audio_params.bit_width) &&
		(curr_params->freq == audio_params.freq) &&
		(curr_params->channels == audio_params.channels))
		return 0;
	else
		return -EINVAL;
}

/* DFS : Sampling Speed
 *
 * DFS1	DFS0		Sampling Speed Mode (fs)
 * 0	0	Normal Speed Mode	32kHz~48kHz (default)
 * 0	1	Double Speed Mode	64kHz~96kHz
 * 1	0	Quad Speed Mode	128kHz~192kHz
 * 1	1	N/A			-
 */

static int ipq_codec_i2c_set_dfs(struct snd_soc_codec *codec, int mode)
{
	uint32_t reg;

	if (mode > QUAD_SPEED) {
		pr_err("%s: %d: Invalid DFS mode", __func__, __LINE__);
		return -EINVAL;
	}

	reg = snd_soc_read(codec, AKD4613_04_CTRL2);

	reg &= ~(AKD4613_DFS_MASK);
	reg |= AKD4613_DFS(mode);

	snd_soc_write(codec, AKD4613_04_CTRL2, reg);

	return 0;
}

/* CKS : Master Clock Input Frequency Select
 *
 * CKS1	CKS0	Normal Speed	Double Speed	Quad Speed
 * 0	0	256fs		256fs		128fs
 * 0	1	384fs		256fs		128fs
 * 1	0	512fs		256fs		128fs (default)
 * 1	1	512fs		256fs		128fs
 */

static int ipq_codec_i2c_set_cks(struct snd_soc_codec *codec,
					int config, int mode)
{
	uint32_t cks_val;
	uint32_t reg;

	if (mode == NORMAL_SPEED) {
		if (config == FS_256)
			cks_val = 0;
		else if (config == FS_384)
			cks_val = 1;
		else if (config == FS_512)
			cks_val = 2;
		else
			cks_val = -EINVAL;
	} else if (mode == DOUBLE_SPEED) {
		if (config == FS_256)
			cks_val = 2;
		else
			cks_val = -EINVAL;
	} else if (mode == QUAD_SPEED) {
		if (config == FS_128)
			cks_val = 2;
		else
			cks_val = -EINVAL;
	} else {
		pr_err("%s: %d: Invalid DFS mode", __func__, __LINE__);
		return -EINVAL;
	}

	if (cks_val < 0) {
		pr_err("%s: %d: Invalid CKS config", __func__, __LINE__);
		return cks_val;
	}

	reg = snd_soc_read(codec, AKD4613_04_CTRL2);

	reg &= ~(AKD4613_CKS_MASK);
	reg |= AKD4613_CKS(cks_val);

	snd_soc_write(codec, AKD4613_04_CTRL2, reg);

	return 0;
}

static int ipq_codec_i2c_set_tdm_mode(struct snd_soc_codec *codec,
						int tdm_mode)
{
	uint32_t reg;

	if (tdm_mode >= TDM_MAX) {
		pr_err("%s: %d: Invalid DFS mode", __func__, __LINE__);
		return -EINVAL;
	}

	reg = snd_soc_read(codec, AKD4613_03_CTRL1);

	reg &= ~(AKD4613_TDM_MODE_MASK);
	reg |= AKD4613_TDM_MODE(tdm_mode);

	snd_soc_write(codec, AKD4613_03_CTRL1, reg);

	return 0;
}

static int ipq_codec_i2c_set_dif(struct snd_soc_codec *codec,
						int dif_val)
{
	uint32_t reg;

	reg = snd_soc_read(codec, AKD4613_03_CTRL1);

	reg &= ~(AKD4613_DIF_MASK);
	reg |= AKD4613_DIF(dif_val);

	snd_soc_write(codec, AKD4613_03_CTRL1, reg);

	return 0;
}

static void ipq_codec_i2c_write_defaults(struct snd_soc_codec *codec)
{
	int i;

	for (i = 0; i < AK4613_MAX_REG; i++)
		snd_soc_write(codec, i, akd4613_reg[i]);
	udelay(10);
}

static int ipq_codec_audio_startup(struct snd_pcm_substream *substream,
					struct snd_soc_dai *dai)
{
	struct snd_soc_codec *codec;

	codec = dai->codec;

	/* I2S and TDM cannot co-exist. CPU DAI startup would
	 * have already checked this case, by this time.
	 */
	if (!dai->active)
		ipq_codec_i2c_write_defaults(codec);

	return 0;
}

static int ipq_codec_audio_hw_params(struct snd_pcm_substream *substream,
					struct snd_pcm_hw_params *params,
					struct snd_soc_dai *dai)
{
	struct snd_soc_codec *codec;
	int samp_rate = params_rate(params);
	u32 bit_width = params_format(params);
	int channels = params_channels(params);
	int bit_act;
	int dfs, cks, tdm_mode, dif;
	uint32_t intf = dai->driver->id;
	struct audio_hw_params curr_params;

	bit_act = ipq_get_act_bit_width(bit_width);
	if (bit_act == __BIT_INVAL)
		return -EINVAL;

	curr_params.freq = samp_rate;
	curr_params.channels = channels;
	curr_params.bit_width = bit_act;

	codec = dai->codec;

	/*
	 * Since CLKS in the codec are shared by I2S TX and RX channels,
	 * Rx and Tx when used simulatneoulsy will have to use the same channel,
	 * sampling frequency and bit widths. So compare the settings and then
	 * update the codec settings.
	 */

	if (dai->active > 1) {
		if (ipq_compare_hw_params(&curr_params)) {
			/* Playback and capture settings do not match */
			pr_err("\nPlayback & capture settings do not match\n");
			return -EINVAL;
		}
		/* Settings match, codec settings are already done*/
		return 0;
	}

	audio_params.freq = samp_rate;
	audio_params.channels = channels;
	audio_params.bit_width = bit_act;

	if (intf == I2S) {
		/* default values */
		dfs = NORMAL_SPEED;
		cks = FS_512;
		tdm_mode = STEREO;
		dif = DIF_I2S_MODE;
	} else if (intf == TDM) {
		/* Codec settings for 8 channels */
		dfs = DOUBLE_SPEED;
		cks = FS_256;
		tdm_mode = TDM_256;
		dif = DIF_LR_MODE3;
	} else {
		pr_err("\n%s Invalid interface\n", __func__);
		return -EINVAL;
	}

	ipq_codec_i2c_set_dfs(codec, dfs);
	ipq_codec_i2c_set_cks(codec, cks, dfs);
	ipq_codec_i2c_set_tdm_mode(codec, tdm_mode);
	ipq_codec_i2c_set_dif(codec, dif);
	udelay(10);

	return 0;
}

static int ipq_codec_audio_prepare(struct snd_pcm_substream *substream,
					struct snd_soc_dai *dai)
{
	dev_dbg(dai->dev, "%s:%d\n", __func__, __LINE__);
	return 0;
}

static void ipq_codec_audio_shutdown(struct snd_pcm_substream *substream,
					struct snd_soc_dai *dai)
{
	dev_dbg(dai->dev, "%s:%d\n", __func__, __LINE__);
}

static struct snd_soc_dai_ops ipq_codec_audio_ops = {
	.startup	= ipq_codec_audio_startup,
	.hw_params	= ipq_codec_audio_hw_params,
	.prepare	= ipq_codec_audio_prepare,
	.shutdown	= ipq_codec_audio_shutdown,
};

static struct snd_soc_dai_driver ipq4019_codec_dais[] = {
	{
		.name = "qca-i2s-codec-dai",
		.playback = {
			.stream_name = "qca-i2s-playback",
			.channels_min = CH_STEREO,
			.channels_max = CH_STEREO,
			.rates = RATE_16000_96000,
			.formats = SNDRV_PCM_FMTBIT_S16 |
				SNDRV_PCM_FMTBIT_S32,
		},
		.capture = {
			.stream_name = "qca-i2s-capture",
			.channels_min = CH_STEREO,
			.channels_max = CH_STEREO,
			.rates = RATE_16000_96000,
			.formats = SNDRV_PCM_FMTBIT_S16 |
				SNDRV_PCM_FMTBIT_S32,
		},
		.ops = &ipq_codec_audio_ops,
		.id = I2S,
	},
	{
		.name = "qca-tdm-codec-dai",
		.playback = {
			.stream_name = "qca-tdm-playback",
			.channels_min = CH_STEREO,
			.channels_max = CH_7_1,
			.rates = RATE_16000_96000,
			.formats = SNDRV_PCM_FMTBIT_S16 |
				SNDRV_PCM_FMTBIT_S32,
		},
		.capture = {
			.stream_name = "qca-tdm-capture",
			.channels_min = CH_STEREO,
			.channels_max = CH_7_1,
			.rates = RATE_16000_96000,
			.formats = SNDRV_PCM_FMTBIT_S16 |
				SNDRV_PCM_FMTBIT_S32,
		},
		.ops = &ipq_codec_audio_ops,
		.id = TDM,
	},
	{
		.name = "qca-i2s1-codec-dai",
		.playback = {
			.stream_name = "qca-i2s1-playback",
			.channels_min = CH_STEREO,
			.channels_max = CH_STEREO,
			.rates = RATE_16000_96000,
			.formats = SNDRV_PCM_FMTBIT_S16 |
				SNDRV_PCM_FMTBIT_S32,
		},
	},
	{
		.name = "qca-i2s2-codec-dai",
		.playback = {
			.stream_name = "qca-i2s2-playback",
			.channels_min = CH_STEREO,
			.channels_max = CH_STEREO,
			.rates = RATE_16000_96000,
			.formats = SNDRV_PCM_FMTBIT_S16 |
				SNDRV_PCM_FMTBIT_S32,
		},
	},
	{
		.name = "qca-spdif-codec-dai",
		.playback = {
			.stream_name = "qca-spdif-playback",
			.channels_min = CH_STEREO,
			.channels_max = CH_STEREO,
			.rates = RATE_16000_96000,
			.formats = SNDRV_PCM_FMTBIT_S16 |
				SNDRV_PCM_FMTBIT_S24_3,
		},
		.capture = {
			.stream_name = "qca-spdif-capture",
			.channels_min = CH_STEREO,
			.channels_max = CH_STEREO,
			.rates = RATE_16000_96000,
			.formats = SNDRV_PCM_FMTBIT_S16 |
				SNDRV_PCM_FMTBIT_S24_3,
		},
	},
};

static struct snd_soc_dai_driver ipq8074_codec_dais[] = {
	{
		.name = "qca-i2s-codec-dai",
		.playback = {
			.stream_name = "qca-i2s-playback",
			.channels_min = CH_STEREO,
			.channels_max = CH_STEREO,
			.rates = RATE_16000_96000,
			.formats = SNDRV_PCM_FMTBIT_S16 |
				SNDRV_PCM_FMTBIT_S32,
		},
		.capture = {
			.stream_name = "qca-i2s-capture",
			.channels_min = CH_STEREO,
			.channels_max = CH_STEREO,
			.rates = RATE_16000_96000,
			.formats = SNDRV_PCM_FMTBIT_S16 |
				SNDRV_PCM_FMTBIT_S32,
		},
		.ops = &ipq_codec_audio_ops,
		.id = I2S,
	},
	{
		.name = "qca-tdm-codec-dai",
		.playback = {
			.stream_name = "qca-tdm-playback",
			.channels_min = CH_STEREO,
			.channels_max = CH_7_1,
			.rates = RATE_16000_96000,
			.formats = SNDRV_PCM_FMTBIT_S16 |
				SNDRV_PCM_FMTBIT_S32,
		},
		.capture = {
			.stream_name = "qca-tdm-capture",
			.channels_min = CH_STEREO,
			.channels_max = CH_7_1,
			.rates = RATE_16000_96000,
			.formats = SNDRV_PCM_FMTBIT_S16 |
				SNDRV_PCM_FMTBIT_S32,
		},
		.ops = &ipq_codec_audio_ops,
		.id = TDM,
	},
};

static int ipq_info(struct snd_kcontrol *kcontrol,
			struct snd_ctl_elem_info *uinfo)
{
	return -ENOTSUPP;
}

static const struct snd_kcontrol_new vol_ctrl  = {
	.iface = SNDRV_CTL_ELEM_IFACE_MIXER,
	.name = "playback volume",
	.access = (SNDRV_CTL_ELEM_ACCESS_TLV_READ |
		SNDRV_CTL_ELEM_ACCESS_READWRITE),
	.info = ipq_info,
};

static const struct regmap_config akd4613_regmap_config = {
	.reg_bits = 8,
	.val_bits = 8,
	.max_register = AK4613_MAX_REG,
	.cache_type = REGCACHE_RBTREE,
};

static int ipq_codec_probe(struct snd_soc_codec *codec)
{
	snd_soc_codec_init_regmap(codec, akd4613_regmap);
	return 0;
}

static int ipq_codec_remove(struct snd_soc_codec *codec)
{
	snd_soc_codec_exit_regmap(codec);
	return 0;
}

static const struct snd_soc_codec_driver ipq_codec = {
	.probe = ipq_codec_probe,
	.remove = ipq_codec_remove,
	.num_controls = 0,
	.reg_cache_size = ARRAY_SIZE(akd4613_reg),
	.reg_word_size = sizeof(u8),
	.reg_cache_default = akd4613_reg,
};

static const struct of_device_id ipq_codec_of_match[] = {
	{ .compatible = "qca,ipq4019-codec", .data = (void *)IPQ4019  },
	{ .compatible = "qca,ipq8074-codec", .data = (void *)IPQ8074  },
	{ /* Sentinel */ }
};
MODULE_DEVICE_TABLE(of, ipq_codec_of_match);

static int ipq_codec_i2c_probe(struct i2c_client *i2c,
					const struct i2c_device_id *id)
{
	struct device *dev = &i2c->dev;
	int ret;
	const struct of_device_id *match;
	enum ipq_hw_type ipq_hw;

	match = of_match_device(ipq_codec_of_match, dev);
	if (!match)
		return -ENODEV;

	ipq_hw = (enum ipq_hw_type)match->data;

	akd4613_regmap = devm_regmap_init_i2c(i2c, &akd4613_regmap_config);

	if (IS_ERR(akd4613_regmap)) {
		ret = PTR_ERR(akd4613_regmap);
		dev_err(&i2c->dev, "Failed to allocate register map: %d\n",
			ret);
		return ret;
	}

	dev_info(&i2c->dev, "i2c regmap done\n");

	if (ipq_hw == IPQ4019)
		ret = snd_soc_register_codec(&i2c->dev,
				&ipq_codec, ipq4019_codec_dais,
				ARRAY_SIZE(ipq4019_codec_dais));
	else
		ret = snd_soc_register_codec(&i2c->dev,
				&ipq_codec, ipq8074_codec_dais,
				ARRAY_SIZE(ipq8074_codec_dais));

	if (ret < 0)
		dev_err(&i2c->dev, "snd_soc_register_codec failed (%d)\n", ret);

	return ret;
}

static int ipq_codec_i2c_remove(struct i2c_client *client)
{
	snd_soc_unregister_codec(&client->dev);
	return 0;
}

static const struct i2c_device_id ipq_codec_i2c_id[] = {
	{ "qca_codec", 0 },
	{ }
};
MODULE_DEVICE_TABLE(i2c, ipq_codec_i2c_id);

static struct i2c_driver ipq_codec_i2c_driver = {
	.driver = {
		.name = "qca_codec",
		.owner = THIS_MODULE,
		.of_match_table = ipq_codec_of_match,
	},
	.probe = ipq_codec_i2c_probe,
	.remove = ipq_codec_i2c_remove,
	.id_table = ipq_codec_i2c_id,
};

static int ipq_codec_init(void)
{
	int ret;

	ret = i2c_add_driver(&ipq_codec_i2c_driver);
	if (ret < 0)
		pr_err("%s: %d: Failed to add I2C driver", __func__, __LINE__);

	return ret;
}
module_init(ipq_codec_init);

static void ipq_codec_exit(void)
{
	i2c_del_driver(&ipq_codec_i2c_driver);
}
module_exit(ipq_codec_exit);

MODULE_LICENSE("Dual BSD/GPL");
MODULE_DESCRIPTION("IPQ Codec Driver");
