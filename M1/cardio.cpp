#include <Arduino.h>
#include "cardio.h"
#define calcultime 5000
#define valeurSeuil 650

void envoidonnees(int tempsPrecedent, int tempsDetection)
{
	Serial.print((1000.0 * 60.0) / (tempsDetection - tempsPrecedent), 0); // conversion des donnees du capteur en frequence cardiaque
	Serial.print(";");
	Serial.print(tempsDetection); // affichage du temps �coul�
	Serial.print("\n");
}

/*--------------------------------------------------------------------------------------*/

void calculPouls(int valeurActuelle, int *valeurPrecedente, int *tempsPrecedent)
{
	int tempsDetection;
	if (valeurActuelle > valeurSeuil) {  // on est dans la zone max
		if (*valeurPrecedente <= valeurSeuil) {  // est-ce qu'on vient d'y entrer?
			tempsDetection = millis(); // le temps de Detection est � millis
			if (tempsDetection > (*tempsPrecedent + 200)) {  // ce n'est pas seulement une erreur de pr�cision ?
				envoidonnees(*tempsPrecedent, tempsDetection);
				*tempsPrecedent = tempsDetection; // pour pouvoir acqu�rir la prochaine valeur
			}
		}
	}

	*valeurPrecedente = valeurActuelle; // pour pouvoir acqu�rir la prochaine valeur
}

/*--------------------------------------------------------------------------------------*/

void recupDonnees()
{
	int time;
	time = millis();
	int valeurPrecedente=0;
	int tempsPrecedent = 0;

	while ((millis() - time)< calcultime)  // la dur�e de mesure est de X secondes
	{
		int valeurActuelle = analogRead(0); //on lit la valeur
		calculPouls(valeurActuelle, &valeurPrecedente, &tempsPrecedent); // calcul du pouls � partir de la valeur
	}
}
/*--------------------------------------------------------------------------------------*/