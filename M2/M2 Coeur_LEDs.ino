/*
 Name:		M2 Coeur_LEDs.ino
 Created:	14/11/2017
 Author:	Maxime
*/

#include "coeur.h"

int tab[10] = { 2,3,4,5,6,7,8,9,10,11 };
// the setup function runs once when you press reset or power the board
void setup() {
	for (int i = 0; i < 10; i++)
	{
		pinMode(tab[i], OUTPUT);
	}
	pinMode(A0, INPUT);
}

// the loop function runs over and over again until power down or reset
void loop()
{
	switch (modeAffichage)
	{
	case 0: allLEDs(tab); break;
	case 1: uneLEDsurX(tab); break;
	case 2: LEDX(tab); break;
	case 3: chenille(tab); break;
	default: break;
	}
}
