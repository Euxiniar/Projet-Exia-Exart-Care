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
		pinMode(tab[i], OUTPUT);		//définition des pins des LEDs en Output
	}
	pinMode(A0, INPUT);				//définition de A0 en Input pour lire signal du capteur
	
}

// the loop function runs over and over again until power down or reset
void loop()
{
	switch (modeAffichage)			//en fonction de la variable modifié dans param.h lance le mode correspondant
	{
	case 0: allLEDs(tab); break;
	case 1: uneLEDsurX(tab); break;
	case 2: LEDX(tab); break;
	case 3: chenille(tab); break;
	default: break;
	}
}
