#include "gpio.h"
#include <unistd.h>

int main()
{
	int pins[2]={4,21};
	int i;
	int c;
	int j;

	for (i=0;i<(sizeof(pins) / sizeof(int));i++)
		if (setGPIO_Out(pins[i]))
			return -1;

	for (i=0;i<10;i++)
		for (c=0;c<(sizeof(pins) / sizeof(int));c++)
			for (j=0;j<(sizeof(pins) / sizeof(int));j++)
			{
					if (c==j)
						if (GPIO_Write(pins[j],1))
							return 1;
					else
						if (GPIO_Write(pins[j],0))
							return 1;

					sleep(1);
			}
	
	for (i=0;i<(sizeof(pins) / sizeof(int));i++)
		if (unsetGPIO(pins[i]))
			return 2;
	
	return 0;
}
