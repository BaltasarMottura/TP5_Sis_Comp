#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/device.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Grupo X");
MODULE_DESCRIPTION("Primer CDD");

static int __init driver_init(void)
{
    printk(KERN_INFO "driver: modulo cargado\n");
    return 0;
}

static void __exit driver_exit(void)
{
    printk(KERN_INFO "driver: modulo descargado\n");
}

module_init(driver_init);
module_exit(driver_exit);