#include "gpio.h"
#include <unistd.h>

int main()
{
	int pins[2]={4,21};
	int i;

	for (i=0;i<(sizeof(pins) / sizeof(int));i++)
		setGPIO_Out(pins[i]);

	for (i=0;i<10;i++)
	{
		GPIO_Write(pins[0],0);
		GPIO_Write(pins[1],1);
		sleep(1);
		GPIO_Write(pins[0],1);
		GPIO_Write(pins[1],0);
		sleep(1);
	}
	
	for (i=0;i<(sizeof(pins) / sizeof(int));i++)
		unsetGPIO(pins[i]);
	
	return 0;
}
