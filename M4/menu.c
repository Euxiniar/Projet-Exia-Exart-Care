/*
Name:		menu.c
Created:	14/11/2017
Author:	Thomas
*/

#include "menu.h"

void showMenu(struct PoulDonnees listePouls[], int *tailleTab)
{
	// Creation des variables locales
	int choix;
	int poulOuTemps;
	int temps;
	int tempsMin;
	int tempsMax;
	double poulMoyen;

	// Affichage du menu a l'utilisateur
	printf("Bienvenue\n");
	printf("Tapez 0 pour afficher les donnees dans l'ordre du fichier .csv\n");
	printf("Tapez 1 pour afficher les donnees dans l'ordre croissant\n");
	printf("Tapez 2 pour afficher les donnees dans l'ordre decroissant\n");
	printf("Tapez 3 pour afficher les donnees pour un temps particulier\n");
	printf("Tapez 4 pour afficher la moyenne de pouls dans une plage de temps donnee\n");
	printf("Tapez 5 pour afficher le nombre de lignes de donnees actuellement en memoire\n");
	printf("Tapez 6 pour rechercher et afficher les maximum et minimum de pouls : \n");
	printf("Tapez 7 pour afficher la date et l'heure de creation du fichier : \n");
	printf("Tapez un autre chiffre pour quitter\n");

	// Recuperation du choix de l'utilisateur
	scanf("%d", &choix);

	// Traitement du choix de l'utilisateur
	switch (choix)
	{
	case 0: 
		affichage_listePouls(listePouls, tailleTab);
		break;
	case 1:
		printf("Tapez 0 pour classer les pouls en ordre croissant\n");
		printf("Tapez 1 pour classer les temps en ordre croissant\n");
		scanf("%d", &poulOuTemps);
		(poulOuTemps == 0 || poulOuTemps == 1 ? triCroissant(listePouls, tailleTab, poulOuTemps) : (*tailleTab = -1));
		affichage_listePouls(listePouls, tailleTab);
		break;
	case 2:
		printf("Tapez 0 pour classer les pouls en ordre decroissant\n");
		printf("Tapez 1 pour classer les temps en ordre decroissant\n");
		scanf("%d", &poulOuTemps);
		(poulOuTemps == 0 || poulOuTemps == 1 ? triDecroissant(listePouls, tailleTab, poulOuTemps) : (*tailleTab = -1));
		affichage_listePouls(listePouls, tailleTab);
		break;
	case 3:
		printf("Tapez le temps pour lequel vous voulez les donnees\n");
		scanf("%d", &temps);
		recherchePoulsSelonTemps(listePouls, tailleTab, temps);
		affichage_listePouls(listePouls, tailleTab);
		break;
	case 4:
		printf("Tapez le temps minimum\n");
		scanf("%d", &tempsMin);
		printf("Tapez le temps maximum\n");
		scanf("%d", &tempsMax);
		getMoyennePoulsSelonTemps(listePouls, tailleTab, tempsMin, tempsMax, &poulMoyen);
		printf("Le poul moyen correspond a %.2f \n", poulMoyen);
		break;
	case 5:
		printf("Il y a actuellement %d donnees dans la RAM\n", *tailleTab);
		break;
	case 6:
		showMaxAndMin(listePouls, tailleTab);
		break;
	case 7:
		affichage_date();
		break;
	default:
		printf("Au revoir\n");
		break;
	}
}
