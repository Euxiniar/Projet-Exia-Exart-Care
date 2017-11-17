/*
 Name:		Sketch1.ino
 Created:	17/11/2017 11:08:14
 Author:	anato
*/

#include "cardio.h"
int premiereFois = 1;

// the setup function runs once when you press reset or power the board
void setup() {
	Serial.begin(115200);
}

// the loop function runs over and over again until power down or reset
void loop() {

	int valeurActuelle;

	if (premiereFois == 1) // permet de ne pas rentrer dans une boucle infinie, mais de faire la mesure une seule fois.
	{
		recupDonnees(valeurActuelle); // récupération des données du capteur
		premiereFois++;
	}
}