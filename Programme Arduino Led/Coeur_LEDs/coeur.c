#include "coeur.h"

void allLEDs()
{
	while (A0 == 1)			//tant que le battement est lu
	{
		for (int i = 0; i < 10; i++)
		{
			digitalWrite(tab[i] , HIGH);
		}
	}
	while (A0 == 0)
	{
		for (int i = 0; i < 10; i++)
		{
			digitalWrite(tab[i] , LOW);
		}
	}
}

void uneLEDsurX(int x)
{
	return void 1L();
}

void LEDX(int x)
{
}

void chenille(int x)
{
}
