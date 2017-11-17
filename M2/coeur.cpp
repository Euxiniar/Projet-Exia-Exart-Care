/*
Name:        coeur.c
Created:    14/11/2017
Author:    Maxime
*/


#include "coeur.h"

void allLEDs(int *tab)
{
	
	while (analogRead(0) <= CALIBRATION);
	{
		for (int i = 0; i < 10; i++)
		{
			digitalWrite(tab[i], LOW);
		}
	}
	while (analogRead(0) > CALIBRATION)           //tant que le battement est lu
	{
		for (int i = 0; i <10 ; i++)    //allume toutes les LEDs
		{
			digitalWrite(tab[i], HIGH);
		}
	}

}

void uneLEDsurX(int *tab)
{

	while (analogRead(0) <= CALIBRATION)           //tant que le battement est lu
	{
		for (int i = 0; i < 10; i += nbLedsAllumees)
		{
			digitalWrite(tab[i], LOW);
		}
	}
	while (analogRead(0) > CALIBRATION)           //tant que le battement est lu
	{
		for (int i = 0; i < 10; i += nbLedsAllumees)
		{
			digitalWrite(tab[i], HIGH);
		}
	}
	
}

void LEDX(int *tab)
{
	while (analogRead(0) > CALIBRATION)
	{
		digitalWrite(tab[ledAllumee], HIGH);
	}
	while (analogRead(0) < CALIBRATION)
	{
		digitalWrite(tab[ledAllumee], LOW);
	}
}

void chenille(int *tab)
{
	int i = 0;
	while (modeAffichage == 3)
	{
		while (analogRead(0) < CALIBRATION);
		if (analogRead(0) > CALIBRATION)
		{
			if (i < nbLedsAllumees)
			{
				digitalWrite(tab[i], HIGH);
				digitalWrite(tab[i + 10 - nbLedsAllumees], LOW);
			}
			else if (i <= 10)
			{
				digitalWrite(tab[i - nbLedsAllumees], LOW);
				digitalWrite(tab[i], HIGH);
			}
			else if (i > 10)
				i -= 10;
		}
		
		i++;
	}
	
}