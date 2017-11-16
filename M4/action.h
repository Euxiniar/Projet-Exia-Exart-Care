#pragma once

#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>

#define TAILLETAB 100

struct PoulDonnees
{
	int poul;
	int temps;
};

//fonction qui lit le fichier
void lireFichier(struct PoulDonnees listePouls[]);
//fonction qui permet d'avoir le nombre d'�lements d'un tableau de donn�es li�es au poul
int getTailleListePouls(struct PoulDonnees listePouls[]);
//Affiche les donn�es d'un tableau de poul
void affichage_listePoul(struct PoulDonnees listePouls[], int *tailleTab);
//fonction qui inverse deux �l�ments dans un tableau de pouls
void triABulle(struct PoulDonnees listePouls[], int *permute, int caseSelect);
//fonction qui effectue un tri croissant selon le poul, et selon le temps
void triCroissant(struct PoulDonnees listePouls[], int *tailleTab, int poulOuTemps);
//fonction qui effectue un tri d�croissant selon le poul, et selon le temps
void triDecroissant(struct PoulDonnees listePouls[], int *tailleTab, int poulOuTemps);
//fonction qui copie un tableau de pouls dans un second tableau de pouls
void copyTabPoulDonnees(struct PoulDonnees listePoulsToCopy[], int *tailleTab, struct PoulDonnees tabQuiALaCopie[]);
//fonction qui efface un tableau de pouls (qui mets les valeurs � -1)
void clearTabPoulDonnees(struct PoulDonnees listePouls[]);
//fonction qui recherche des pouls selon un temps demand�)
void recherchePoulsSelonTemps(struct PoulDonnees listePouls[], int *tailleTab, int temps);
//fonction qui permet d'avoir une moyenne de pouls dans une tranche de temps
void getMoyennePoulsSelonTemps(struct PoulDonnees listePouls[], int *tailleTab, int tempsMin, int tempsMax, double *poulMoyen);
//fonction qui permet de voir le poul minimum et maximum d'un tableau de pouls
void showMaxAndMin(struct PoulDonnees listePouls[], int *tailleTab);
