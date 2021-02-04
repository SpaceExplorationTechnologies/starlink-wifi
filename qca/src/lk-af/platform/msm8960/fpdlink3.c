/* Copyright (c) 2012-2014, The Linux Foundation. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *  * Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *  * Redistributions in binary form must reproduce the above
 *    copyright notice, this list of conditions and the following
 *    disclaimer in the documentation and/or other materials provided
 *    with the distribution.
 *  * Neither the name of The Linux Foundation. nor the names of its
 *    contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
 * BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
 * OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
 * IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
#include <stdint.h>
#include <err.h>
#include <gsbi.h>
#include <i2c_qup.h>
#include <debug.h>
#include <platform/timer.h>
#include <platform/gpio.h>
#include <reg.h>
#include <platform/iomap.h>

#define UH927Q_I2C_ADDRESS		0x0C
#define UH928Q_I2C_ADDRESS		0x2C
#define MXT_I2C_ADDRESS			0x5B
#define SX1509_I2C_ADDRESS		0x3E
#define EEPROM_I2C_ADDRESS		0x50

#define IDS_REG_ADDR			0xF0
#define UH927Q_RESET			0x01
#define UH927Q_GEN_CONF			0x03
#define UH927Q_DES_ID			0x06
#define UH927Q_SLAVE0_ID		0x07
#define UH927Q_SLAVE0_AL		0x08
#define UH927Q_SLAVE1_ID		0x70
#define UH927Q_SLAVE1_AL		0x77
#define UH927Q_SLAVE2_ID		0x71
#define UH927Q_SLAVE2_AL		0x78
#define UH927Q_STATUS			0x0C
#define UH927Q_GEN_CTRL			0x13
#define UH927Q_HDCP_DBG			0xC0
#define UH927Q_HDCP_STS			0xC4
#define UH927Q_HDCP_ICR			0xC6
#define UH927Q_HDCP_ISR			0xC7
#define UH927Q_IND_STS 			0xD0

/* ds90uh927q register value */
#define SETUP_BCC			0xDA
#define MAPSEL_MSB_RXIN3		0x40
#define ENABLE_DEV_INT			0x21

/* ds90uh928q register offset */
#define UH928Q_GPIO0			0x1D
#define UH928Q_GPIO12			0x1E
#define UH928Q_GPIO3			0x1F

/* ds90uh928q register value */
#define EN_OUTPUT_HI			0x09
#define EN_OUTPUT_LOW			0x01
#define EN_INPUT			0x03

/* sx1509 register offset */
#define REG_INPUTDISABLE_A		0x01
#define REG_PULLUP_A			0x07
#define REG_OPENDRAIN_A			0x0B
#define REG_DIR_B			0x0E
#define REG_DIR_A			0x0F
#define REG_DATA_B			0x10
#define REG_DATA_A			0x11
#define REG_INTERRUPTMASK_A 		0x13
#define REG_SENSEHIGH_A			0x16
#define REG_EVENTSTATUS_A		0x1B
#define REG_CLOCK			0x1E
#define REG_MISC			0x1F
#define REG_LEDDRIVEREN_A 		0X21
#define	REG_TON4			0x35
#define	REG_ION4			0x36
#define	REG_OFF4			0x37
#define REG_TRISE4			0x38
#define REG_TFALL4			0x39
#define REG_RESET			0x7D
#define REG_INTERRUPTSOURCE_B		0x18
#define REG_INTERRUPTSOURCE_A		0x19

static struct qup_i2c_dev *dev;

static void fpdlink3_read_reg(uint8_t addr, uint8_t reg, int len, uint8_t *buf)
{
	if (dev) {
		struct i2c_msg rd_buf[] = {
			{addr, I2C_M_WR, 1, &reg},
			{addr, I2C_M_RD, len, buf}
		};

		int err = qup_i2c_xfer(dev, rd_buf, 2);
		if (err < 0) {
			dprintf(INFO, "Read reg %x failed\n", reg);
			return;
		}
	} else
		dprintf(INFO, "fpdlink3_read_reg: qup_i2c_init() failed\n");
}

static void fpdlink3_write_reg(uint8_t addr, uint8_t reg, uint8_t val)
{
	if (dev) {
		unsigned char buf[2] = {reg, val};
		struct i2c_msg msg_buf[] = {
			{addr, I2C_M_WR, 2, buf},
		};

		int err = qup_i2c_xfer(dev, msg_buf, 1);
		if (err < 0) {
			dprintf(INFO, "Write reg %x failed\n", reg);
			return;
		}
	} else
		dprintf(INFO, "fpdlink3_read_reg: qup_i2c_init() failed\n");
}

static int fpdlink3_read_device_id(struct qup_i2c_dev *dev, uint16_t addr)
{
	unsigned char buf[6] = {0, 0, 0, 0, 0, 0};

	fpdlink3_read_reg(addr, IDS_REG_ADDR, 6, buf);
	if (*buf != 0){
		dprintf(INFO, "device id %s\n", buf);
		return NO_ERROR;
	} else
		dprintf(INFO, "read device id failed\n");

	return 0;
}

static void fpdlink3_conf_bit(uint16_t addr, uint8_t reg, uint8_t mask, bool setbit)
{
	if (dev) {
		unsigned char buf[2] = {reg, 0};
		struct i2c_msg rd_buf[] = {
				{addr, I2C_M_WR, 1, buf},
				{addr, I2C_M_RD, 1, &buf[1]}
		};
		struct i2c_msg msg_buf[] = {
			{addr, I2C_M_WR, 2, buf},
		};

		/*
		 * read default setting first
		 */
		int err = qup_i2c_xfer(dev, rd_buf, 2);
		if (err < 0) {
			dprintf(INFO, "Read reg %x failed\n", reg);
			return;
		}

		if (setbit) {
			/*
			 * set the bit
			 */
			buf[1] |= mask;
			dprintf(INFO, "fpdlink3_conf_bit set %x\n", buf[1]);
		} else {
			/*
			 * clear the bit
			 */
			buf[1] &= ~mask;
			dprintf(INFO, "fpdlink3_conf_bit clr %x\n", buf[1]);
		}

		err = qup_i2c_xfer(dev, msg_buf, 1);
		if (err < 0) {
			dprintf(INFO, "Write reg %x failed\n", reg);
			return;
		}
	}
}

static int fpdlink3_uh927q_init(struct qup_i2c_dev *dev)
{
	int err = fpdlink3_read_device_id(dev, UH927Q_I2C_ADDRESS);
	if (err != NO_ERROR) {
		dprintf(INFO, "fpdlink3_read_device_id for uh927 failed\n");
		return err;
	}

	/*
	 * clear bit 0x13[5] to make sure LSBs on RxIN3±
	 */
	fpdlink3_conf_bit(UH927Q_I2C_ADDRESS, UH927Q_GEN_CTRL, 1 << 5, false);

	/*
	 * enable Map Select by register bit 0x13[5]
	 */
	fpdlink3_conf_bit(UH927Q_I2C_ADDRESS, UH927Q_GEN_CTRL, 1 << 6, true);

	return NO_ERROR;
}

static void fpdlink3_reset_sx1509(void)
{
	dprintf(INFO, "reset io expander of fpdlink III\n");
	if (dev) {
		unsigned char buf[2] = {REG_RESET, 0x12};
		struct i2c_msg msg_buf[] = {
		   {SX1509_I2C_ADDRESS, I2C_M_WR, 2, buf},
		};

		int err = qup_i2c_xfer(dev, msg_buf, 1);
		if (err < 0) {
			dprintf(INFO, "Write reg %x failed\n", REG_RESET);
			return;
		}

		buf[1] = 0x34;
		err = qup_i2c_xfer(dev, msg_buf, 1);
		if (err < 0) {
			dprintf(INFO, "Write reg %x failed\n", REG_RESET);
			return;
		}
	}
}

static void fpdlink3_detect_sx1509(void)
{
	dprintf(INFO, "configuring io expander of fpdlink III\n");
	if (dev) {
		unsigned char val = 0;

		/*
		 * reset the device first
		 */
		fpdlink3_reset_sx1509();
		udelay(1000);
		fpdlink3_write_reg(SX1509_I2C_ADDRESS, REG_DIR_A, 0xA5);
		udelay(10);
		fpdlink3_read_reg(SX1509_I2C_ADDRESS, REG_DIR_A, 1, &val);
		fpdlink3_reset_sx1509();
	}
}

static int clear_sx1509_int(void)
{
	dprintf(INFO, "clear_sx1509_int\n");
	if (dev) {
		unsigned char val = 0;

		/*
		 * clear interrupt in bank A
		 */
		fpdlink3_write_reg(SX1509_I2C_ADDRESS, REG_INTERRUPTSOURCE_A, 0xFF);
		/*
		 * clear interrupt in bank B
		 */
		fpdlink3_write_reg(SX1509_I2C_ADDRESS, REG_INTERRUPTSOURCE_B, 0xFF);
		/*
		 * read data in back A
		 */
		fpdlink3_read_reg(SX1509_I2C_ADDRESS, REG_DATA_A, 1, &val);
		dprintf(INFO, "read REG_DATA_A return %x\n", val);
		/*
		 * read data in back B
		 */
		fpdlink3_read_reg(SX1509_I2C_ADDRESS, REG_DATA_B, 1, &val);
		dprintf(INFO, "read REG_DATA_B return %x\n", val);
	}

	return NO_ERROR;
}

static int fpdlink3_config_sx1509(void)
{
	dprintf(INFO, "configuring io expander of fpdlink III\n");
	if (dev) {
		unsigned char mask_7 = 0x80;
		unsigned char mask_8 = 0x01;

		fpdlink3_detect_sx1509();
		udelay(1000);
		/*
		 * set ts_attn_n I/O 8 to output high
		 */
		fpdlink3_conf_bit(SX1509_I2C_ADDRESS, REG_DIR_B, mask_8, false);
		fpdlink3_conf_bit(SX1509_I2C_ADDRESS, REG_DATA_B, mask_8, true);
		/*
		 * config I/O 7 to input -> set bit 7 to 1
		 */
		fpdlink3_conf_bit(SX1509_I2C_ADDRESS, REG_DIR_A, mask_7, true);

		/*
		 * config I/O 2, 3, 7 to pull up -> set bits 7 to 1
		 */
		fpdlink3_conf_bit(SX1509_I2C_ADDRESS, REG_PULLUP_A, mask_7, true);

		/*
		 * config I/O 7 to 0 to make interrupt pass through -> clr bits 7 to 0
		 */
		fpdlink3_conf_bit(SX1509_I2C_ADDRESS, REG_INTERRUPTMASK_A, mask_7, false);

		/*
		 * set interrupt sense falling for I/O 7 (TS_RDY 3V3)
		 */
		fpdlink3_write_reg(SX1509_I2C_ADDRESS, REG_SENSEHIGH_A, mask_7);

		fpdlink3_write_reg(SX1509_I2C_ADDRESS, REG_MISC, 0x10);

		/*
		 * clear interrupt
		 */
		int err = clear_sx1509_int();
		if (err) {
			dprintf(INFO, "clear sx1509 INT failed\n");
			return err;
		}
	} else {
		dprintf(INFO, "fpdlink3_config_sx15x: qup_i2c_init() failed\n");
	}
	return NO_ERROR;
}

static int fpdlink3_config_uh928q(void)
{
	dprintf(INFO, "configuring deserializer of fpdlink III\n");
	if (dev) {
		int err = fpdlink3_read_device_id(dev, UH928Q_I2C_ADDRESS);
		if ( err != NO_ERROR) {
			dprintf(INFO, "fpdlink3_read_device_id for uh928 failed\n");
			return err;
		}

		udelay(100);
		fpdlink3_config_sx1509();
		udelay(100);
		/*
		 * config GPIO0 to output high for TS_MODE_LEN_3V3
		 * 0x20 defaul read only for device id
		 */
		fpdlink3_write_reg(UH928Q_I2C_ADDRESS, UH928Q_GPIO0, (EN_OUTPUT_HI | 0x20));

		/*
		 * config GPIO1 to input for TS_RDY_3V3 This is the TS interrupt
		 * config GPIO2 to output low for CDP_BACKLIGHT_EN_N
		 */
		fpdlink3_write_reg(UH928Q_I2C_ADDRESS, UH928Q_GPIO12, (EN_INPUT | (EN_OUTPUT_LOW << 4)));

		/*
		 * config GPIO3 to output low then high for TS_RESET_N_3V3
		 */
		fpdlink3_write_reg(UH928Q_I2C_ADDRESS, UH928Q_GPIO3, EN_OUTPUT_LOW);
		udelay(100);
		fpdlink3_write_reg(UH928Q_I2C_ADDRESS, UH928Q_GPIO3, EN_OUTPUT_HI);
	} else
		dprintf(INFO, "fpdlink3_config_uh928q: qup_i2c_init() failed\n");

	return NO_ERROR;
}

static int clear_u927_int(void)
{
	dprintf(INFO, "clear_u927_int\n");
	if (dev) {
		unsigned char buf = 0x0;
		fpdlink3_read_reg(UH927Q_I2C_ADDRESS, UH927Q_HDCP_ICR, 1, &buf);
		dprintf(INFO, "fpdlink3 uh927 icr 0%x\n", buf);
		buf = 0x0;
		fpdlink3_read_reg(UH927Q_I2C_ADDRESS, UH927Q_HDCP_ISR, 1, &buf);
		dprintf(INFO, "fpdlink3 uh927 isr 0%x\n", buf);
		buf = 0x0;
		fpdlink3_read_reg(UH927Q_I2C_ADDRESS, UH927Q_HDCP_ISR, 1, &buf);
		dprintf(INFO, "fpdlink3 verify isr 0%x\n", buf);
	}

	return NO_ERROR;
}

int fpdlink3_config_slave(void)
{
	dprintf(INFO, "configuring serializer of fpdlink III\n");
	if (dev) {
		unsigned char buf = 0x0;
		/*
		 * Set BCC channel
		 */
		fpdlink3_write_reg(UH927Q_I2C_ADDRESS, UH927Q_GEN_CONF, SETUP_BCC);

		/*
		 * Set remote io expander I2C slave alias ID (8bit)
		 */
		fpdlink3_write_reg(UH927Q_I2C_ADDRESS, UH927Q_SLAVE0_AL, (SX1509_I2C_ADDRESS << 1));
		/*
		 * Set remote io expander I2C slave ID (8bit)
		 */
		fpdlink3_write_reg(UH927Q_I2C_ADDRESS, UH927Q_SLAVE0_ID, (SX1509_I2C_ADDRESS << 1));

		/*
		 * Set remote touch I2C slave alias ID (8bit)
		 */
		fpdlink3_write_reg(UH927Q_I2C_ADDRESS, UH927Q_SLAVE1_AL, (MXT_I2C_ADDRESS << 1));
		/*
		 * Set remote touch I2C slave ID (8bit)
		 */
		fpdlink3_write_reg(UH927Q_I2C_ADDRESS, UH927Q_SLAVE1_ID, (MXT_I2C_ADDRESS << 1));

		/*
		 * Set remote EEPROM slave alias ID (8bit)
		 */
		fpdlink3_write_reg(UH927Q_I2C_ADDRESS, UH927Q_SLAVE2_AL, (EEPROM_I2C_ADDRESS << 1));
		/*
		`* Set remote EEPROM I2C slave ID (8bit)
		 */
		fpdlink3_write_reg(UH927Q_I2C_ADDRESS, UH927Q_SLAVE2_ID, (EEPROM_I2C_ADDRESS << 1));

		/*
		 * enable interrupt
		 */
		fpdlink3_write_reg(UH927Q_I2C_ADDRESS, UH927Q_HDCP_ICR, ENABLE_DEV_INT);

		/*
		 * read status
		 */
		fpdlink3_read_reg(UH927Q_I2C_ADDRESS, UH927Q_STATUS, 1, &buf);
		if (buf & 0x01) {
			dprintf(INFO, "fpdlink3 cable link is detected\n");
			if (fpdlink3_config_uh928q() == NO_ERROR) {
				clear_u927_int();
				udelay(100);
			}
		} else {
			dprintf(INFO, "fpdlink3 cable link is not detected\n");
			return -1;
		}
	} else
		dprintf(INFO, "fpdlink3_config_slave: qup_i2c_init() failed\n");

	return NO_ERROR;
}

int fpdlink3_init(void)
{
	dprintf(INFO, "init serializer of fpdlink III\n");

	dev = qup_i2c_init(GSBI_ID_1, 100, 24000);
	if(!dev)
		dprintf(INFO, "qup_i2c_init() failed\n");

	return NO_ERROR;
}

