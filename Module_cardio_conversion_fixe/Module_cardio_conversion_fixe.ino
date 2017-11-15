#include "cardio.h"


// the setup function runs once when you press reset or power the board
void setup() {
	Serial.begin(9600);
	pinMode(A0, INPUT);

}

// the loop function runs over and over again until power down or reset
void loop() {
	int time;
	time = millis();

	// Correspond � un petit "r�chauffement" du convertisseur
	// analogique-num�rique, cela semble am�liorer les r�sultats
	while ((millis() - time)<1000) {
		analogRead(0);
	}

	recupDonnees(); // r�cup�ration des donn�es du capteur
}
