/*
 Name:		Coeur_LEDs.ino
 Created:	14/11/2017 15:49:16
 Author:	Maxime
*/

#include "coeur.c"
#include "param.h"

int tab[10] = { 2,3,4,5,6,7,8,9,10,11 };
// the setup function runs once when you press reset or power the board
void setup() {
	for (int i = 0; i < 10; i++)
	{
		pinMode(tab[i], OUTPUT);
	}
	pinMode(A0, OUTPUT);
}

// the loop function runs over and over again until power down or reset
void loop()
{
	
	int param = modeAffichage;
	switch (param)
	{
	case 0: allLEDs(tab); break;
	case 1: uneLEDsurX(nbLedsAllumees, tab); break;
	case 2: LEDX(ledAllumee, tab); break;
	case 3: chenille(nbLedsAllumees , tab); break;
	default: break;
	}/*
	int x = 3;
	for (int i = 0; i < x; i++)
	{
	digitalWrite(tab[i], HIGH);
	digitalWrite(tab[i + 10 - x], LOW);
	delay(500);
	}

	for (int i = x; i < 10; i++)
	{
		digitalWrite(tab[i - x], LOW);
		digitalWrite(tab[i], HIGH);
		delay(500);
	}*/
}
