//#include "coeur.h"
#include<Arduino.h>

void allLEDs(int *tab)
{
	//while (A0 == 1)			//tant que le battement est lu
	//{
		for (int i = 0; i < 10; i++)
		{
			digitalWrite(tab[i] , HIGH);
		}
		delay(500);
	//}
	//while (A0 == 0)
	//{
		for (int i = 0; i < 10; i++)
		{
			digitalWrite(tab[i] , LOW);
		}
		delay(500);
	//}
}

void uneLEDsurX(int x)
{
	int i = 0;
	while (A0 == 1)
	{
		digitalWrite(i, HIGH);
	}
}

void LEDX(int x)
{
}

void chenille(int x)
{
}
