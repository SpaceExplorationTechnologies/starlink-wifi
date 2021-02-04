/*
 * Copyright (c) 2013, The Linux Foundation. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 and
 * only version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#ifndef _AG7240_PHY_H
#define _AG7240_PHY_H

#define ag7240_phy_setup(unit) do { \
    athrs26_phy_setup(unit); \
} while (0);

#define ag7240_phy_link(unit,link,fdx,speed) do { \
    link = athrs26_phy_is_up(unit); \
} while (0);

#define ag7240_phy_duplex(unit,duplex) do { \
    duplex =  athrs26_phy_is_fdx (unit); \
} while (0);

#define ag7240_phy_speed(unit,speed) do { \
        speed = athrs26_phy_speed (unit); \
} while (0);

#endif /*_AG7240_PHY_H*/
