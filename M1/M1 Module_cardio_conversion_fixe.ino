/*
Name:		Module_cardio_conversion_fixe.ino
Created:	14/11/2017
Author:	Anatole
*/

#include "cardio.h"


// the setup function runs once when you press reset or power the board
void setup() {
	Serial.begin(115200);
	pinMode(A0, INPUT);
}

// the loop function runs over and over again until power down or reset
void loop() {
	int time;
	time = millis();

	// Correspond a un petit "rechauffement" du convertisseur
	// analogique-numerique, cela semble ameliorer les resultats
	while ((millis() - time)<1000) {
		analogRead(0);
	}

	recupDonnees(); // r�cup�ration des donn�es du capteur
}
