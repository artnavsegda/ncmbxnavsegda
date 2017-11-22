#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <errno.h>
#include <ncurses.h>
#include <modbus/modbus.h>

modbus_t *mb;

void gameover(void)
{
	endwin();
	modbus_close(mb);
	modbus_free(mb);
}

int main(int argc, char *argv[])
{
	uint16_t tab_reg[10];
	if (argc == 1)
	{
		printf("name serial port\n");
		exit(1);
	}
	mb = modbus_new_rtu(argv[1], 9600, 'N', 8, 1);
	modbus_set_slave(mb, 50);
	modbus_rtu_set_serial_mode(mb, MODBUS_RTU_RS232);
	if (modbus_connect(mb) == -1)
	{
		printf("Connection failed: %s\n", modbus_strerror(errno));
		modbus_free(mb);
		exit(1);
	}
	initscr();
	noecho();
	curs_set(FALSE);
	keypad(stdscr, TRUE);
	atexit(gameover);

	while(1)
	{
		if (modbus_read_registers(mb, 360, 2, tab_reg) == -1)
		{
			clear();
			mvprintw(10,10,"Cannot read: %s", modbus_strerror(errno));
		}
		else
		{
			clear();
			mvprintw(10,10,"%f",modbus_get_float(&tab_reg[0]));
		}
		refresh();
		sleep(1);
	}

	endwin();
	return 0;
}

