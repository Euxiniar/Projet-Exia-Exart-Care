/*
Name:        coeur.c
Created:    14/11/2017
Author:    Maxime
*/


#include "coeur.h"

void allLEDs(int *tab)
{
	while (Serial.read() != NULL)            //tant que le battement est lu
	{
		for (int i = 0; i < 10; i++)    //allume toutes les LEDs
		{
			digitalWrite(tab[i], HIGH);
		}
	}
	while (Serial.read() == NULL)
	{
		for (int i = 0; i < 10; i++)
		{
			digitalWrite(tab[i], LOW);
		}
	}
}

void uneLEDsurX(int *tab)
{

	for (int i = 0; Serial.read() != NULL && i < 10; i += nbLedsAllumees)
	{
		digitalWrite(tab[i], HIGH);
	}
	for (int i = 0; Serial.read() == NULL && i < 10; i += nbLedsAllumees)
	{
		digitalWrite(tab[i], LOW);
	}
}

void LEDX(int *tab)
{
	while (Serial.read() != NULL)
	{
		digitalWrite(tab[ledAllumee], HIGH);
	}
	while (Serial.read() == NULL)
	{
		digitalWrite(tab[ledAllumee], LOW);
	}
}

void chenille(int *tab)
{
	for (int i = 0; i < nbLedsAllumees; i++)
	{
		while (Serial.read() == NULL);
		while (Serial.read() != NULL)
		{
			digitalWrite(tab[i], HIGH);
			digitalWrite(tab[i + 10 - nbLedsAllumees], LOW);
		}
	}

	for (int i = nbLedsAllumees; i < 10; i++)
	{
		while (A0 != 1);
		while (A0 == 1)
		{
			digitalWrite(tab[i - nbLedsAllumees], LOW);
			digitalWrite(tab[i], HIGH);
		}
	}
}