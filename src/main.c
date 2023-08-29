#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/devicetree.h>
#include <zephyr/logging/log.h>
#include <zephyr/drivers/uart.h>
#include <zephyr/shell/shell.h>
#include <zephyr/drivers/i2c.h>

LOG_MODULE_REGISTER(app);

static int cmd_si5351a(const struct shell *sh, size_t argc, char **argv)
{
	const struct i2c_dt_spec spec = I2C_DT_SPEC_GET(DT_NODELABEL(si5351a));
	uint8_t buf[32];
	int ret;

	ARG_UNUSED(argc);
	ARG_UNUSED(argv);

	ret = i2c_burst_read_dt(&spec, 0x00, buf, sizeof(buf));
	if (ret < 0) {
		shell_error(sh, "Unable to read Si5351A registers over I2C");
		return -EIO;
	}

	shell_print(sh, "i2c_values starting from 0x0:");
	shell_hexdump(sh, buf, sizeof(buf));

	return 0;
}
SHELL_CMD_ARG_REGISTER(si5351a, NULL, "Si5351A debug toolbox", cmd_si5351a, 1, 0);

int main(void)
{
	const struct device *dev;
	uint32_t dtr = 0;

	dev = DEVICE_DT_GET(DT_CHOSEN(zephyr_shell_uart));
	if (!device_is_ready(dev)) {
		return 0;
	}

	while (!dtr) {
		uart_line_ctrl_get(dev, UART_LINE_CTRL_DTR, &dtr);
		k_sleep(K_MSEC(100));
	}
	return 0;
}
