/*
Name:		cardio.cpp
Created:	14/11/2017
Author:	Anatole
*/

#include <Arduino.h>
#include "cardio.h"
#define calcultime 5000
#define valeurSeuil 650

void envoidonnees(int tempsPrecedent, int tempsDetection)
{
	Serial.print((1000.0 * 60.0) / (tempsDetection - tempsPrecedent), 0); // conversion des donnees du capteur en frequence cardiaque
	Serial.print(";");
	Serial.print(tempsDetection - tempsPrecedent); // affichage du temps écoulé
}

/*--------------------------------------------------------------------------------------*/

void calculPouls(int valeurActuelle, int *valeurPrecedente, int *tempsPrecedent)
{
	int tempsDetection;
	if (valeurActuelle > valeurSeuil) {  // on est dans la zone max
		if (*valeurPrecedente <= valeurSeuil) {  // est-ce qu'on vient d'y entrer?
			tempsDetection = millis(); // le temps de Detection est à millis
			if (tempsDetection > (*tempsPrecedent + 200)) {  // ce n'est pas seulement une erreur de précision ?
				envoidonnees(*tempsPrecedent, tempsDetection);
				*tempsPrecedent = tempsDetection; // pour pouvoir acquérir la prochaine valeur
			}
		}
	}

	*valeurPrecedente = valeurActuelle; // pour pouvoir acquérir la prochaine valeur
}

/*--------------------------------------------------------------------------------------*/

void recupDonnees()
{
	int time;
	time = millis();
	int valeurPrecedente=0;
	int tempsPrecedent = 0;

	while ((millis() - time)< calcultime)  // la durée de mesure est de X secondes
	{
		int valeurActuelle = analogRead(A0); //on lit la valeur
		calculPouls(valeurActuelle, &valeurPrecedente, &tempsPrecedent); // calcul du pouls à partir de la valeur
	}
}
/*--------------------------------------------------------------------------------------*/