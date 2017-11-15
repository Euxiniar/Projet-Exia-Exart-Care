/*
 Name:		Coeur_LEDs.ino
 Created:	14/11/2017 15:49:16
 Author:	Maxime
*/

#include "coeur.h"

int tab[10] = { 0,1,2,3,4,5,6,7,8,9 };
// the setup function runs once when you press reset or power the board
void setup() {
	for (int i = 0; i < 10; i++)
	{
		pinMode(tab[i], OUTPUT);
	}
}

// the loop function runs over and over again until power down or reset
void loop() 
{
	int param = modeAffichage;
	switch (param)
	{
	case 0: allLEDs(); break;
	case 1: uneLEDsurX(nbLedsAllumees); break;
	case 2: LEDX(LedsAllumees); break;
	case 3: chenille(nbLedsAllumees); break;
	default: break;
	}
}
