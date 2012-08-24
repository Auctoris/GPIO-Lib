#include "gpio.h"
#include <unistd.h>

int main()
{
	int pins[2]={4,21};
	int i;

	for (i=0;i<(sizeof(pins) / sizeof(int));i++)
		if (setGPIO_Out(pins[i]))
			return -1;

	for (i=0;i<10;i++)
	{
		if (GPIO_Write(pins[0],0))
			return 1;
		if (GPIO_Write(pins[1],1))
			return 1;
		sleep(1);
		if (GPIO_Write(pins[0],1))
			return 1;
		if (GPIO_Write(pins[1],0))
			return 1;
		sleep(1);
	}
	
	for (i=0;i<(sizeof(pins) / sizeof(int));i++)
		if (unsetGPIO(pins[i]))
			return 2;
	
	return 0;
}
