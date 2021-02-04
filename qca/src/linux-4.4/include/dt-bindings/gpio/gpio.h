/*
 * This header provides constants for most GPIO bindings.
 *
 * Most GPIO bindings include a flags cell as part of the GPIO specifier.
 * In most cases, the format of the flags cell uses the standard values
 * defined in this header.
 */

#ifndef _DT_BINDINGS_GPIO_GPIO_H
#define _DT_BINDINGS_GPIO_GPIO_H

/* Bit 0 express polarity */
#define GPIO_ACTIVE_HIGH 0
#define GPIO_ACTIVE_LOW 1

/* Bit 1 express single-endedness */
#define GPIO_PUSH_PULL 0
#define GPIO_SINGLE_ENDED 2

/*
 * Open Drain/Collector is the combination of single-ended active low,
 * Open Source/Emitter is the combination of single-ended active high.
 */
#define GPIO_OPEN_DRAIN (GPIO_SINGLE_ENDED | GPIO_ACTIVE_LOW)
#define GPIO_OPEN_SOURCE (GPIO_SINGLE_ENDED | GPIO_ACTIVE_HIGH)

#define DRV_TYPE_D		0
#define DRV_TYPE_C		1
#define DRV_TYPE_B		3
#define DRV_TYPE_A		7

#define DRV_CAP_HIGH	0
#define DRV_CAP_HALF	1
#define DRV_CAP_QUARTER	2

#define RES_10_KOHM	0
#define RES_1_5_KOHM	1
#define RES_35_KOHM	2
#define RES_20_KOHM	3

#endif
