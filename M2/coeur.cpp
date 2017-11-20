/*
Name:        coeur.c
Created:    14/11/2017
Author:    Maxime
*/


#include "coeur.h"

void allLEDs(int *tab)
{	
	while (analogRead(0) >= SEUIL)			//si la carte est passée devant le capteur
	{
		for (int i = 0; i < 10; i++)
		{
			digitalWrite(tab[i],HIGH);		//allume toute les LEDs
		}
	}
	while (analogRead(0) < SEUIL)           //après que la carte soit passée
	{
		for (int i = 0; i <10 ; i++)		//éteint toutes les LEDs
		{
			digitalWrite(tab[i], LOW);
		}
	}
}

void uneLEDsurX(int *tab)
{
	while (analogRead(0) >= SEUIL)           //quand un battement est detecté
	{
		for (int i = 0; i < 10; i += nbLedsAllumees)	//allume une LED sur nbLedsAllumees
		{
			digitalWrite(tab[i], HIGH);
		}
	}
	while (analogRead(0) < SEUIL)           //après la detection
	{
		for (int i = 0; i < 10; i += nbLedsAllumees)		//éteint les LEDs allumées
		{
			digitalWrite(tab[i], LOW);
		}
	}
}

void LEDX(int *tab)
{
	while (analogRead(0) > SEUIL)
	{
		digitalWrite(tab[ledAllumee], HIGH);		//allume une seule LED
	}
	while (analogRead(0) < SEUIL)
	{
		digitalWrite(tab[ledAllumee], LOW);
	}
}

void chenille(int *tab)
{
	int i = 0;
	while (modeAffichage == 3)
	{
		while (analogRead(0) < SEUIL) {}		//attend la detection d'une carte

		if (i >= 10)			//reset le tableau a zéro quand on arrive au bout pour continuer de faire 
		{						//tourner la chenille quand elle a fini de faire le tour
			i -= 10;
		}
		if (i < nbLedsAllumees)		//pour les premières LEDs, les allume et éteint les dernières
		{
			digitalWrite(tab[i], HIGH);
			digitalWrite(tab[i + 10 - nbLedsAllumees], LOW);

		}
		else if (i < 10)			//pour les autres, allume une LED et éteint la dernière LED de la chenille
		{
			digitalWrite(tab[i], HIGH);
			digitalWrite(tab[i - nbLedsAllumees], LOW);
		}

		while (analogRead(0) > SEUIL) {}	//attend la fin du front montant
		while (analogRead(0) < SEUIL) {}	//permet de réduire les fluctuations
		while (analogRead(0) > SEUIL) {}
		i++;
	}
}