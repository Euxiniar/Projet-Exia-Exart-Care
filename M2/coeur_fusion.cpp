/*
Name:        coeur.c
Created:    14/11/2017
Author:    Maxime
*/


#include "coeur.h"

void allLEDs(int *tab)
{

	while (valeurActuelle > 500)			//si la carte est passée devant le capteur
	{
		for (int i = 0; i < 10; i++)
		{
			digitalWrite(tab[i], HIGH);		//allume toute les LEDs
		}
	}
	while (valeurActuelle < 500)           //après que la carte soit passée
	{
		for (int i = 0; i <10; i++)		//éteint toutes les LEDs
		{
			digitalWrite(tab[i], LOW);
		}
	}
}

void uneLEDsurX(int *tab)
{

	while (valeurActuelle > 500)           //quand un battement est detecté
	{
		for (int i = 0; i < 10; i += nbLedsAllumees)	//allume une LED sur nbLedsAllumees
		{
			digitalWrite(tab[i], LOW);
		}
	}
	while (valeurActuelle < 500)           //après la detection
	{
		for (int i = 0; i < 10; i += nbLedsAllumees)		//éteint les LEDs allumées
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