/*
Name:        coeur.c
Created:    14/11/2017
Author:    Maxime
*/


#include "coeur.h"

void allLEDs(int *tab)
{

	while (valeurActuelle > 500)			//si la carte est pass�e devant le capteur
	{
		for (int i = 0; i < 10; i++)
		{
			digitalWrite(tab[i], HIGH);		//allume toute les LEDs
		}
	}
	while (valeurActuelle < 500)           //apr�s que la carte soit pass�e
	{
		for (int i = 0; i <10; i++)		//�teint toutes les LEDs
		{
			digitalWrite(tab[i], LOW);
		}
	}
}

void uneLEDsurX(int *tab)
{

	while (valeurActuelle > 500)           //quand un battement est detect�
	{
		for (int i = 0; i < 10; i += nbLedsAllumees)	//allume une LED sur nbLedsAllumees
		{
			digitalWrite(tab[i], LOW);
		}
	}
	while (valeurActuelle < 500)           //apr�s la detection
	{
		for (int i = 0; i < 10; i += nbLedsAllumees)		//�teint les LEDs allum�es
		{
			digitalWrite(tab[i], HIGH);
		}
	}

}

void LEDX(int *tab)
{
	while (valeurActuelle > 500)
	{
		digitalWrite(tab[ledAllumee], HIGH);
	}
	while (valeurActuelle < 500)
	{
		digitalWrite(tab[ledAllumee], LOW);
	}

}

void chenille(int *tab, int *i)
{
	while (valeurActuelle < 500) {}

	if (i >= 10)
	{
		i -= 10;
	}
	if (i < nbLedsAllumees)
	{
		digitalWrite(tab[i], HIGH);
		digitalWrite(tab[i + 10 - nbLedsAllumees], LOW);

	}
	else if (i < 10)
	{
		digitalWrite(tab[i], HIGH);
		digitalWrite(tab[i - nbLedsAllumees], LOW);
	}

	while (valeurActuelle > 500) {}
	i++;
	}
}