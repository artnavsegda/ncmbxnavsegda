#include <ncurses.h>
#include <modbus/modbus.h>

int main(int argc, char *argv[])
{
	if (argc == 1)
	{
		printf("name serial port\n");
		exit(1);
	}
	return 0;
}

