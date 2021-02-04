/*
 * Driver for Aquantia PHY
 *
 * Author: Shaohui Xie <Shaohui.Xie@freescale.com>
 *
 * Copyright (c) 2018 The Linux Foundation. All rights reserved.
 * Copyright 2015 Freescale Semiconductor, Inc.
 *
 * This file is licensed under the terms of the GNU General Public License
 * version 2.  This program is licensed "as is" without any warranty of any
 * kind, whether express or implied.
 */

#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/delay.h>
#include <linux/mii.h>
#include <linux/ethtool.h>
#include <linux/phy.h>
#include <linux/mdio.h>
#include <linux/debugfs.h>

#define PHY_ID_AQ1202	0x03a1b445
#define PHY_ID_AQ2104	0x03a1b460
#define PHY_ID_AQR105	0x03a1b4a2
#define PHY_ID_AQR405	0x03a1b4b0
#define PHY_ID_AQR107	0x03a1b4e2
#define PHY_ID_AQR108	0x03a1b4f2
#define PHY_ID_AQR109	0x03a1b502
#define PHY_ID_AQR111	0x03a1b610
#define PHY_ID_AQR111B0	0x03a1b612
#define PHY_ID_AQR112	0x03a1b660

#define AQ_PHY_MAX_VALID_MMD_REG		0xff01
#define AQ_PHY_MAX_INVALID_MMD_REG		0xffff
#define AQ_PHY_MIN_VALID_REG		0x10000
#define AQ_PHY_MAX_VALID_REG		0x1f0000

#define AQ_PHY_REG_GLOBAL_CTRL_1	0x0000
#define AQ_PHY_REG_GLOBAL_ALARMS_1	0xcc00
#define AQ_PHY_REG_GLOBAL_INTR_STANDARD_MASK	0xff00
#define AQ_PHY_REG_GLOBAL_INTR_VENDOR_MASK	0xff01
#define AQ_PHY_REG_USX_TRANSMIT	0xc441
#define AQ_PHY_REG_AUTONEG_VENDOR_STATUS	0xc800
#define AQ_PHY_REG_AUTONEG_TRANSMIT_INTR_MASK	0xd401
#define AQ_PHY_REG_AUTONEG_TRANSMIT_ALARMS_1	0xcc01

#define AQ_PHY_SOFTRESET_COMPLETED	0x0040
#define AQ_PHY_SOFTRESET	0x8000
#define AQ_PHY_AUTONEG_ENABLE	0x1000
#define AQ_PHY_AUTONEG_RESTART	0x200
#define AQ_PHY_USX_AUTONEG_ENABLE	0x8
#define AQ_PHY_AUTO_AND_ALARMS_INTR_MASK	0x1001
#define AQ_PHY_CONNECT_SPEED	0x7
#define AQ_PHY_SPEED_10M	0x0
#define AQ_PHY_SPEED_100M	0x1
#define AQ_PHY_SPEED_1000M	0x2
#define AQ_PHY_SPEED_10000M	0x3
#define AQ_PHY_SPEED_2500M	0x4
#define AQ_PHY_SPEED_5000M	0x5

#define AQ_PHY_REG_ADVERT	0x10
#define AQ_PHY_ADVERT_PAUSE	0x400
#define AQ_PHY_ADVERT_ASYM_PAUSE	0x800

#define PHY_AQUANTIA_FEATURES	(SUPPORTED_10000baseT_Full | \
				 SUPPORTED_1000baseT_Full | \
				 SUPPORTED_100baseT_Full | \
				 SUPPORTED_Pause | \
				 SUPPORTED_Asym_Pause | \
				 PHY_DEFAULT_FEATURES)

/* Driver private data structure */
struct aq_priv {
	struct phy_device *phydev;	/* Pointer to PHY device */
	struct dentry *top_dentry;	/* Top dentry for AQ107 PHY Driver */
	struct dentry *write_dentry;	/* write-reg file dentry */
	struct dentry *read_dentry;	/* read-reg file dentry */
	u32 phy_addr;		/* AQ107 PHY Address */
	u32 reg_addr;		/* register address */
	u16 reg_val;		/* register value */

};

/* Check for a valid range of PHY register address */
static bool aquantia_phy_check_valid_reg(unsigned int reg_addr)
{
	bool ret = false;
	u8 mmd;

	if (reg_addr < AQ_PHY_MIN_VALID_REG)
		return false;

	if ((reg_addr & AQ_PHY_MAX_INVALID_MMD_REG) > AQ_PHY_MAX_VALID_MMD_REG)
		return false;

	mmd = (reg_addr & AQ_PHY_MAX_VALID_REG) >> 16;

	switch (mmd) {
	case MDIO_MMD_PMAPMD:
	case MDIO_MMD_PCS:
	case MDIO_MMD_PHYXS:
	case MDIO_MMD_AN:
	case MDIO_MMD_C22EXT:
	case MDIO_MMD_VEND1:
		ret = true;
		break;
	default:
		ret = false;
	}

	return ret;
}

static ssize_t aquantia_phy_read_reg_get(struct file *fp,
					 char __user *ubuf, size_t sz,
					 loff_t *ppos)
{
	struct aq_priv *priv = (struct aq_priv *)fp->private_data;
	char lbuf[40];
	int bytes_read;

	if (!priv)
		return -EFAULT;

	snprintf(lbuf, sizeof(lbuf), "phy%x(0x%x): 0x%x\n",
		 priv->phy_addr, priv->reg_addr, priv->reg_val);

	bytes_read = simple_read_from_buffer(ubuf, sz, ppos,
					     lbuf, strlen(lbuf));

	return bytes_read;
}

static ssize_t aquantia_phy_read_reg_set(struct file *fp,
					 const char __user *ubuf,
					 size_t sz, loff_t *ppos)
{
	struct aq_priv *priv = (struct aq_priv *)fp->private_data;
	char lbuf[32];
	size_t lbuf_size;
	char *options = lbuf;
	char *this_opt;
	unsigned int reg_addr, phy_addr;
	bool is_reabable = false;

	if (!priv)
		return -EFAULT;

	lbuf_size = min(sz, (sizeof(lbuf) - 1));

	if (copy_from_user(lbuf, ubuf, lbuf_size))
		return -EFAULT;

	lbuf[lbuf_size] = 0;

	this_opt = strsep(&options, " ");
	if (!this_opt)
		goto fail;

	kstrtouint(this_opt, 0, &phy_addr);
	if ((options - lbuf) >= (lbuf_size - 1))
		goto fail;

	this_opt = strsep(&options, " ");
	if (!this_opt)
		goto fail;

	kstrtouint(this_opt, 0, &reg_addr);

	is_reabable = aquantia_phy_check_valid_reg(reg_addr);
	if (is_reabable) {
		priv->phy_addr = (uint32_t)phy_addr;
		priv->reg_addr = (uint32_t)reg_addr;
		reg_addr = MII_ADDR_C45 | reg_addr;
		priv->reg_val = phy_read(priv->phydev, reg_addr);
	} else {
		goto fail;
	}

	return lbuf_size;

fail:
	return -EINVAL;
}

static ssize_t aquantia_phy_write_reg_set(struct file *fp,
					  const char __user *ubuf,
					  size_t sz,
					  loff_t *ppos)
{
	struct aq_priv *priv = (struct aq_priv *)fp->private_data;
	char lbuf[32];
	size_t lbuf_size;
	char *options = lbuf;
	char *this_opt;
	unsigned int phy_addr = 0;
	unsigned int reg_addr = 0;
	unsigned int reg_value = 0;
	bool is_writeable = false;
	u32 check_16bit_boundary = 0xffff0000;

	if (!priv)
		return -EFAULT;

	lbuf_size = min(sz, (sizeof(lbuf) - 1));

	if (copy_from_user(lbuf, ubuf, lbuf_size))
		return -EFAULT;

	lbuf[lbuf_size] = 0;

	this_opt = strsep(&options, " ");
	if (!this_opt)
		goto fail;

	kstrtouint(this_opt, 0, &phy_addr);
	if ((options - lbuf) >= (lbuf_size - 1))
		goto fail;

	this_opt = strsep(&options, " ");
	if (!this_opt)
		goto fail;

	kstrtouint(this_opt, 0, &reg_addr);
	if ((options - lbuf) >= (lbuf_size - 1))
		goto fail;

	this_opt = strsep(&options, " ");
	if (!this_opt)
		goto fail;

	kstrtouint(this_opt, 0, &reg_value);

	if (phy_addr > 7)
		goto fail;

	 /* Check 16BIT register value boundary */
	if (check_16bit_boundary & reg_value)
		goto fail;

	 /* Check for a valid Range of register and write into Phy dev */
	is_writeable = aquantia_phy_check_valid_reg(reg_addr);
	if (is_writeable) {
		reg_addr = MII_ADDR_C45 | reg_addr;
		phy_write(priv->phydev, reg_addr, reg_value);

	} else {
		goto fail;
	}

	return lbuf_size;

fail:
	return -EINVAL;
}

static const struct file_operations aquantia_phy_read_reg_ops = {
	.open = simple_open,
	.read = aquantia_phy_read_reg_get,
	.write = aquantia_phy_read_reg_set,
	.llseek = no_llseek,
};

static const struct file_operations aquantia_phy_write_reg_ops = {
	.open = simple_open,
	.write = aquantia_phy_write_reg_set,
	.llseek = no_llseek,
};

/* Create debug-fs aq-phy dir and files */
static int aquantia_phy_init_debugfs_entries(struct aq_priv *priv)
{
	char name[16];

	snprintf(name, 16, "aquantia-phy-%d", priv->phydev->addr);
	priv->top_dentry = debugfs_create_dir(name, NULL);
	if (!priv->top_dentry)
		return -1;

	priv->write_dentry = debugfs_create_file("phy-write-reg", 0600,
						 priv->top_dentry,
						 priv,
						 &aquantia_phy_write_reg_ops);
	if (!priv->write_dentry) {
		debugfs_remove_recursive(priv->top_dentry);
		return -1;
	}

	priv->read_dentry = debugfs_create_file("phy-read-reg", 0600,
						priv->top_dentry,
						priv,
						&aquantia_phy_read_reg_ops);
	if (!priv->read_dentry) {
		debugfs_remove_recursive(priv->top_dentry);
		return -1;
	}

	priv->phy_addr = 0;
	priv->reg_addr = 0;
	priv->reg_val = 0;

	return 0;
}

static int aquantia_soft_reset(struct phy_device *phydev)
{
	return 0;
}

static int aquantia_r107_reg_init(struct phy_device *phydev)
{
	int reg, err;

	reg = phy_read_mmd(phydev, MDIO_MMD_PHYXS, AQ_PHY_REG_USX_TRANSMIT);

	err = phy_write_mmd(phydev, MDIO_MMD_PHYXS, AQ_PHY_REG_USX_TRANSMIT,
			    reg | AQ_PHY_USX_AUTONEG_ENABLE);
	if (err < 0)
		return err;

	return 0;
}

static int aquantia_config_init(struct phy_device *phydev)
{
	phydev->speed = SPEED_UNKNOWN;
	phydev->link = PHY_NOLINK;
	phydev->duplex = DUPLEX_FULL;
	phydev->autoneg = AUTONEG_ENABLE;
	phydev->supported = PHY_AQUANTIA_FEATURES;
	phydev->advertising = ADVERTISED_10000baseT_Full |
				ADVERTISED_1000baseT_Full |
				ADVERTISED_100baseT_Full |
				ADVERTISED_Pause |
				ADVERTISED_Asym_Pause;

	aquantia_r107_reg_init(phydev);

	return 0;
}

static int aquantia_config_advert(struct phy_device *phydev)
{
	u32 advertise;
	int reg;

	advertise = phydev->advertising & phydev->supported;
	reg = phy_read_mmd(phydev, MDIO_MMD_AN, AQ_PHY_REG_ADVERT);

	if (advertise & ADVERTISED_Pause)
		reg |= AQ_PHY_ADVERT_PAUSE;
	else
		reg &= ~AQ_PHY_ADVERT_PAUSE;

	if (advertise & ADVERTISED_Asym_Pause)
		reg |= AQ_PHY_ADVERT_ASYM_PAUSE;
	else
		reg &= ~AQ_PHY_ADVERT_ASYM_PAUSE;

	return phy_write_mmd(phydev, MDIO_MMD_AN, AQ_PHY_REG_ADVERT, reg);
}

static int aquantia_config_aneg(struct phy_device *phydev)
{
	int reg, err;

	err = aquantia_config_advert(phydev);
	if (err < 0)
		return err;

	reg = phy_read_mmd(phydev, MDIO_MMD_AN, MII_BMCR);

	err = phy_write_mmd(phydev, MDIO_MMD_AN, MII_BMCR,
			    reg | AQ_PHY_AUTONEG_ENABLE |
			    AQ_PHY_AUTONEG_RESTART);
	if (err < 0)
		return err;

	return 0;
}

static int aquantia_aneg_done(struct phy_device *phydev)
{
	int reg;

	reg = phy_read_mmd(phydev, MDIO_MMD_AN, MDIO_STAT1);
	return (reg < 0) ? reg : (reg & BMSR_ANEGCOMPLETE);
}

static int aquantia_config_intr(struct phy_device *phydev)
{
	int err;

	if (phydev->interrupts == PHY_INTERRUPT_ENABLED) {
		err = phy_write_mmd(phydev, MDIO_MMD_AN,
				    AQ_PHY_REG_AUTONEG_TRANSMIT_INTR_MASK, 1);
		if (err < 0)
			return err;

		err = phy_write_mmd(phydev, MDIO_MMD_VEND1,
				    AQ_PHY_REG_GLOBAL_INTR_STANDARD_MASK, 1);
		if (err < 0)
			return err;

		err = phy_write_mmd(phydev, MDIO_MMD_VEND1,
				    AQ_PHY_REG_GLOBAL_INTR_VENDOR_MASK,
				    AQ_PHY_AUTO_AND_ALARMS_INTR_MASK);
	} else {
		err = phy_write_mmd(phydev, MDIO_MMD_AN,
				    AQ_PHY_REG_AUTONEG_TRANSMIT_INTR_MASK, 0);
		if (err < 0)
			return err;

		err = phy_write_mmd(phydev, MDIO_MMD_VEND1,
				    AQ_PHY_REG_GLOBAL_INTR_STANDARD_MASK, 0);
		if (err < 0)
			return err;

		err = phy_write_mmd(phydev, MDIO_MMD_VEND1,
				    AQ_PHY_REG_GLOBAL_INTR_VENDOR_MASK, 0);
	}

	return err;
}

static int aquantia_ack_interrupt(struct phy_device *phydev)
{
	int reg;

	reg = phy_read_mmd(phydev, MDIO_MMD_AN,
			   AQ_PHY_REG_AUTONEG_TRANSMIT_ALARMS_1);
	return (reg < 0) ? reg : 0;
}

static int aquantia_read_status(struct phy_device *phydev)
{
	int reg;

	reg = phy_read_mmd(phydev, MDIO_MMD_AN, MDIO_STAT1);
	reg = phy_read_mmd(phydev, MDIO_MMD_AN, MDIO_STAT1);
	if (reg & MDIO_STAT1_LSTATUS)
		phydev->link = 1;
	else
		phydev->link = 0;

	reg = phy_read_mmd(phydev, MDIO_MMD_AN,
			   AQ_PHY_REG_AUTONEG_VENDOR_STATUS);
	mdelay(10);
	reg = phy_read_mmd(phydev, MDIO_MMD_AN,
			   AQ_PHY_REG_AUTONEG_VENDOR_STATUS);

	switch ((reg >> 1) & AQ_PHY_CONNECT_SPEED) {
	case AQ_PHY_SPEED_100M:
		phydev->speed = SPEED_100;
		break;
	case AQ_PHY_SPEED_1000M:
		phydev->speed = SPEED_1000;
		break;
	case AQ_PHY_SPEED_10000M:
		phydev->speed = SPEED_10000;
		break;
	case AQ_PHY_SPEED_2500M:
		phydev->speed = SPEED_2500;
		break;
	case AQ_PHY_SPEED_5000M:
		phydev->speed = SPEED_5000;
		break;
	}
	phydev->duplex = DUPLEX_FULL & reg;

	return 0;
}

static int aquantia_update_link(struct phy_device *phydev)
{
	int reg;

	reg = phy_read_mmd(phydev, MDIO_MMD_AN, MDIO_STAT1);
	reg = phy_read_mmd(phydev, MDIO_MMD_AN, MDIO_STAT1);
	if (reg & MDIO_STAT1_LSTATUS)
		phydev->link = 1;
	else
		phydev->link = 0;

	return 0;
}

static int aquantia_match_phy_device(struct phy_device *phydev)
{
	return phydev->c45_ids.device_ids[4] == PHY_ID_AQR107;
}

/* PHY driver probe function */
static int
aquantia_phy_probe(struct phy_device *phydev)
{
	struct aq_priv *priv;
	int ret;

	/* Initialize the debug-fs entries */
	priv = vzalloc(sizeof(*priv));

	if (!priv)
		return -1;

	priv->phydev = phydev;
	ret = aquantia_phy_init_debugfs_entries(priv);

	if (ret < 0) {
		vfree(priv);
		return ret;
	}
	return 0;
}

static struct phy_driver aquantia_driver[] = {
{
	.phy_id		= PHY_ID_AQ1202,
	.phy_id_mask	= 0xfffffff0,
	.name		= "Aquantia AQ1202",
	.features	= PHY_AQUANTIA_FEATURES,
	.flags		= PHY_HAS_INTERRUPT,
	.aneg_done	= aquantia_aneg_done,
	.config_aneg    = aquantia_config_aneg,
	.config_intr	= aquantia_config_intr,
	.ack_interrupt	= aquantia_ack_interrupt,
	.read_status	= aquantia_read_status,
	.driver		= { .owner = THIS_MODULE,},
},
{
	.phy_id		= PHY_ID_AQ2104,
	.phy_id_mask	= 0xfffffff0,
	.name		= "Aquantia AQ2104",
	.features	= PHY_AQUANTIA_FEATURES,
	.flags		= PHY_HAS_INTERRUPT,
	.aneg_done	= aquantia_aneg_done,
	.config_aneg    = aquantia_config_aneg,
	.config_intr	= aquantia_config_intr,
	.ack_interrupt	= aquantia_ack_interrupt,
	.read_status	= aquantia_read_status,
	.driver		= { .owner = THIS_MODULE,},
},
{
	.phy_id		= PHY_ID_AQR105,
	.phy_id_mask	= 0xfffffff0,
	.name		= "Aquantia AQR105",
	.features	= PHY_AQUANTIA_FEATURES,
	.flags		= PHY_HAS_INTERRUPT,
	.aneg_done	= aquantia_aneg_done,
	.config_aneg    = aquantia_config_aneg,
	.config_intr	= aquantia_config_intr,
	.ack_interrupt	= aquantia_ack_interrupt,
	.read_status	= aquantia_read_status,
	.driver		= { .owner = THIS_MODULE,},
},
{
	.phy_id		= PHY_ID_AQR405,
	.phy_id_mask	= 0xfffffff0,
	.name		= "Aquantia AQR405",
	.features	= PHY_AQUANTIA_FEATURES,
	.flags		= PHY_HAS_INTERRUPT,
	.aneg_done	= aquantia_aneg_done,
	.config_aneg    = aquantia_config_aneg,
	.config_intr	= aquantia_config_intr,
	.ack_interrupt	= aquantia_ack_interrupt,
	.read_status	= aquantia_read_status,
	.driver		= { .owner = THIS_MODULE,},
},
{
	.phy_id		= PHY_ID_AQR107,
	.phy_id_mask	= 0xfffffff0,
	.name		= "Aquantia AQR107",
	.features	= PHY_AQUANTIA_FEATURES,
	.flags		= PHY_HAS_INTERRUPT,
	.probe		= aquantia_phy_probe,
	.soft_reset	= aquantia_soft_reset,
	.config_init	= aquantia_config_init,
	.aneg_done	= aquantia_aneg_done,
	.config_aneg	= aquantia_config_aneg,
	.config_intr	= aquantia_config_intr,
	.ack_interrupt	= aquantia_ack_interrupt,
	.read_status	= aquantia_read_status,
	.update_link	= aquantia_update_link,
	.match_phy_device	= aquantia_match_phy_device,
	.driver		= { .owner = THIS_MODULE,},
},
{
	.phy_id		= PHY_ID_AQR108,
	.phy_id_mask	= 0xfffffff0,
	.name		= "Aquantia AQR108",
	.features	= PHY_AQUANTIA_FEATURES,
	.flags		= PHY_HAS_INTERRUPT,
	.probe		= aquantia_phy_probe,
	.soft_reset	= aquantia_soft_reset,
	.config_init	= aquantia_config_init,
	.aneg_done	= aquantia_aneg_done,
	.config_aneg	= aquantia_config_aneg,
	.config_intr	= aquantia_config_intr,
	.ack_interrupt	= aquantia_ack_interrupt,
	.read_status	= aquantia_read_status,
	.update_link	= aquantia_update_link,
	.driver		= { .owner = THIS_MODULE,},
},
{
	.phy_id		= PHY_ID_AQR109,
	.phy_id_mask	= 0xfffffff0,
	.name		= "Aquantia AQR109",
	.features	= PHY_AQUANTIA_FEATURES,
	.flags		= PHY_HAS_INTERRUPT,
	.probe		= aquantia_phy_probe,
	.soft_reset	= aquantia_soft_reset,
	.config_init	= aquantia_config_init,
	.aneg_done	= aquantia_aneg_done,
	.config_aneg	= aquantia_config_aneg,
	.config_intr	= aquantia_config_intr,
	.ack_interrupt	= aquantia_ack_interrupt,
	.read_status	= aquantia_read_status,
	.update_link	= aquantia_update_link,
	.driver		= { .owner = THIS_MODULE,},
},
{
	.phy_id		= PHY_ID_AQR111,
	.phy_id_mask	= 0xfffffff0,
	.name		= "Aquantia AQR111",
	.features	= PHY_AQUANTIA_FEATURES,
	.flags		= PHY_HAS_INTERRUPT,
	.probe		= aquantia_phy_probe,
	.soft_reset	= aquantia_soft_reset,
	.config_init	= aquantia_config_init,
	.aneg_done	= aquantia_aneg_done,
	.config_aneg	= aquantia_config_aneg,
	.config_intr	= aquantia_config_intr,
	.ack_interrupt	= aquantia_ack_interrupt,
	.read_status	= aquantia_read_status,
	.update_link	= aquantia_update_link,
	.driver		= { .owner = THIS_MODULE,},
},
{
	.phy_id         = PHY_ID_AQR111B0,
	.phy_id_mask    = 0xfffffff0,
	.name           = "Aquantia AQR111B0",
	.features       = PHY_AQUANTIA_FEATURES,
	.flags          = PHY_HAS_INTERRUPT,
	.probe          = aquantia_phy_probe,
	.soft_reset     = aquantia_soft_reset,
	.config_init    = aquantia_config_init,
	.aneg_done      = aquantia_aneg_done,
	.config_aneg    = aquantia_config_aneg,
	.config_intr    = aquantia_config_intr,
	.ack_interrupt  = aquantia_ack_interrupt,
	.read_status    = aquantia_read_status,
	.update_link    = aquantia_update_link,
	.driver         = { .owner = THIS_MODULE,},
},
{
	.phy_id		= PHY_ID_AQR112,
	.phy_id_mask	= 0xfffffff0,
	.name		= "Aquantia AQR112",
	.features	= PHY_AQUANTIA_FEATURES,
	.flags		= PHY_HAS_INTERRUPT,
	.probe		= aquantia_phy_probe,
	.soft_reset = aquantia_soft_reset,
	.config_init	= aquantia_config_init,
	.aneg_done	= aquantia_aneg_done,
	.config_aneg	= aquantia_config_aneg,
	.config_intr	= aquantia_config_intr,
	.ack_interrupt	= aquantia_ack_interrupt,
	.read_status	= aquantia_read_status,
	.update_link	= aquantia_update_link,
	.driver		= { .owner = THIS_MODULE,},
},
};

module_phy_driver(aquantia_driver);

static struct mdio_device_id __maybe_unused aquantia_tbl[] = {
	{ PHY_ID_AQ1202, 0xfffffff0 },
	{ PHY_ID_AQ2104, 0xfffffff0 },
	{ PHY_ID_AQR105, 0xfffffff0 },
	{ PHY_ID_AQR405, 0xfffffff0 },
	{ PHY_ID_AQR107, 0xfffffff0 },
	{ PHY_ID_AQR108, 0xfffffff0 },
	{ PHY_ID_AQR109, 0xfffffff0 },
	{ PHY_ID_AQR111, 0xfffffff0 },
	{ PHY_ID_AQR111B0, 0xfffffff0 },
	{ PHY_ID_AQR112, 0xfffffff0 },
	{ }
};

MODULE_DEVICE_TABLE(mdio, aquantia_tbl);

MODULE_DESCRIPTION("Aquantia PHY driver");
MODULE_AUTHOR("Shaohui Xie <Shaohui.Xie@freescale.com>");
MODULE_LICENSE("GPL v2");
