#include <zephyr/kernel.h>
#include <zephyr/drivers/sensor.h>
#include <app_version.h>

#include <zephyr/logging/log.h>
LOG_MODULE_REGISTER(main, CONFIG_APP_LOG_LEVEL);

int main(void)
{
	int ret;
	const struct device *sensor;

    while (1) {

		printk("Zephyr Example Application %s\n", APP_VERSION_STRING);
		k_sleep(K_MSEC(1000));
	}

	return 0;
}
