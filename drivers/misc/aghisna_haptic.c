/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * Copyright (C) 2022 ZyCromerZ
 * Copyright (C) 2023 RooGhz
 *
 * Inspired from lyb display
 *
 */

#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <misc/aghisna_haptic.h>

bool __read_mostly haptic_qti_miui = false;
module_param(haptic_qti_miui, bool, 0644);

static int __init read_haptic_miui(char *s)
{
    int status;
	if (s)
		status = simple_strtoul(s, NULL, 0);

	if ( status > 0 ) {
		haptic_qti_miui = true;
	} else {
		haptic_qti_miui = false;
	}
	return 1;
}
__setup("aghisna.hapticm=", read_haptic_miui);

bool __read_mostly haptic_qti_oss = false;
module_param(haptic_qti_oss, bool, 0644);

static int __init read_haptic_oss(char *s)
{
    int status;
	if (s)
		status = simple_strtoul(s, NULL, 0);

	if ( status > 0 ) {
		haptic_qti_oss = true;
	} else {
		haptic_qti_oss = false;
	}
	return 1;
}
__setup("aghisna.haptico=", read_haptic_oss);

static int __init prepare_driver_init(void) {
 printk(KERN_INFO "aghisna haptic initialized");
 return 0;
}
static void __exit prepare_driver_exit(void) {
 printk(KERN_INFO "aghisna haptic exit");
}

module_init(prepare_driver_init);
module_exit(prepare_driver_exit);
