#include <zephyr/kernel.h>

#include <zephyr/logging/log.h>
LOG_MODULE_REGISTER(main, CONFIG_APP_LOG_LEVEL);

int main(void)
{
    while (1) {

		printk("Zephyr Example Application %s\n", "lifcl40evn_app_demo");
		k_sleep(K_MSEC(1000));
	}

	return 0;
}
