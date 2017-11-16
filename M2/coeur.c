/*
Name:		coeur.c
Created:	14/11/2017
Author:	Maxime
*/

#include <Arduino.h>


void allLEDs(int *tab)
{
	while (A0 == 1)			//tant que le battement est lu
	{
		for (int i = 0; i < 10; i++)
		{
			digitalWrite(tab[i] , HIGH);
		}
		delay(500);
	}
	while (A0 == 0)
	{
		for (int i = 0; i < 10; i++)
		{
			digitalWrite(tab[i] , LOW);
		}
		delay(500);
	}
}

void uneLEDsurX(int x, int *tab)
{

	for (int i = 0; A0 == 1 && i < 10; i += x )
	{
		digitalWrite(tab[i], HIGH);
	}
	delay(500);
	for (int i = 0; A0 == 0 && i < 10; i += x)
	{
		digitalWrite(tab[i], LOW);
	}
	delay(500);
}

void LEDX(int x, int *tab)
{
	while (A0 == 0)
	{
		digitalWrite(tab[x], HIGH);
	}
	while (A0 == 1)
	{
		digitalWrite(tab[x], LOW);
	}
}

void chenille(int x, int *tab)
{
	for (int i = 0; i < x; i++)
	{
		while (A0 != 1);
		while (A0 == 1)
		{
			digitalWrite(tab[i], HIGH);
			digitalWrite(tab[i + 10 - x], LOW);
		}
	}

	for (int i = x; i < 10; i++)
	{
		while (A0 != 1);
		while (A0 == 1)
		{
			digitalWrite(tab[i - x], LOW);
			digitalWrite(tab[i], HIGH);
		}
	}
}
