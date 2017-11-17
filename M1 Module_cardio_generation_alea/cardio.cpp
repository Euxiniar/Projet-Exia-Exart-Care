#include "cardio.h"

#define calcultime 10000
#define valeurSeuil 650

int valeurPrecedente;
int tempsPrecedent;
int tempsDetection;
int alternance = 0;



/*--------------------------------------------------------------------------------------*/

void envoidonnees(int tempsDetection)
{
	Serial.print((1000.0 * 60.0) / (tempsDetection - tempsPrecedent), 0); // 1 pulsation en (tempsDetection - tempsPrecedent) milli-secondes 
	Serial.print(";");													  // --> [1 * 1000 (en secondes) * 60 (en minutes)] / [temps 1 pulsation]
	Serial.print(tempsDetection - tempsPrecedent);						  // --> nombre de pulsations en une minute
}

/*--------------------------------------------------------------------------------------*/

int generateAlea()
{
	int limite = random(3000, 5000); //permet de ne pas avoir tout le temps le même pouls
	if (alternance < limite) // nous somme dans la zone minimale
	{
		alternance++;
		return(300);
	}
	else if (alternance >= limite && alternance < 10000) // nous sommes dans la zone maximale
	{
		alternance++;
		return(700);
	}
	else // nous revenons à la zone minimale
	{
		alternance = 0;
	}
}

/*--------------------------------------------------------------------------------------*/

int calculPouls(int valeurActuelle)
{
	if (valeurActuelle > valeurSeuil) {  // on est dans la zone max
		if (valeurPrecedente <= valeurSeuil) {  // est-ce qu'on vient d'y entrer?
			tempsDetection = millis(); // le temps de Detection est au temps actuel
			if (tempsDetection > (tempsPrecedent + 300)) {  // ce n'est pas seulement une erreur de précision ?
				envoidonnees(tempsDetection);
				tempsPrecedent = tempsDetection; // pour pouvoir acquérir la prochaine valeur
			}
		}
	}
	valeurPrecedente = valeurActuelle; // pour pouvoir acquérir la prochaine valeur
}

/*--------------------------------------------------------------------------------------*/

void recupDonnees(int valeurActuelle)
{
	int time;
	time = millis();

	while ((millis() - time)< calcultime)  // la durée de mesure est de X secondes
	{
		valeurActuelle = generateAlea(); //on lit la valeur
		calculPouls(valeurActuelle); // calcul du pouls à partir de la valeur
	}
}
/*--------------------------------------------------------------------------------------*/