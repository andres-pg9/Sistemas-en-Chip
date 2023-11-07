#include <stdlib.h>
#include <stdio.h>
#define LED_ADDR 0x00011020 //espacio de memoria leds
int main(void){
	volatile int *led = (int*)(LED_ADDR); //asignacion del puntero al espacio de memoria
	int count=0; //contador que carga el valor en el LED
	while (1){
		Delay (1000000);
		count++;
		if (count==256)	{
			count = 0;
		}
		*(led) = count;
		printf("El numero es: %d \n ", count);
	}
	return 0;
}

void Delay (int _Tiempo){
	int i = 0;
	while (i<_Tiempo){
		i++;
	}
}
