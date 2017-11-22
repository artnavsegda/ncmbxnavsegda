#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <ncurses.h>
#include <modbus/modbus.h>

int main(int argc, char *argv[])
{
	if (argc == 1)
	{
		printf("name serial port\n");
		exit(1);
	}
	modbus_t *mb = modbus_new_rtu(argv[1], 9600, 'N', 8, 1);
	modbus_set_slave(mb, 50);
	modbus_rtu_set_serial_mode(mb, MODBUS_RTU_RS232);
	if (modbus_connect(mb) == -1)
	{
		printf("Connection failed: %s\n", modbus_strerror(errno));
		modbus_free(mb);
		exit(1);
	}
	return 0;
}

