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


void lireFichier(struct PoulDonnees listePouls[]);
int getTailleListePouls(struct PoulDonnees listePouls[]);
void affichage_listePoul(struct PoulDonnees listePouls[], int *tailleTab);
void triABulle(struct PoulDonnees listePouls[], int *permute, int caseSelect);
void triCroissant(struct PoulDonnees listePouls[], int *tailleTab, int poulOuTemps);
void triDecroissant(struct PoulDonnees listePouls[], int *tailleTab, int poulOuTemps);
void copyTabPoulDonnees(struct PoulDonnees listePoulsToCopy[], int *tailleTab, struct PoulDonnees tabQuiALaCopie[]);
void clearTabPoulDonnees(struct PoulDonnees listePouls[]);
void recherchePoulsSelonTemps(struct PoulDonnees listePouls[], int *tailleTab, int temps);
void getMoyennePoulsSelonTemps(struct PoulDonnees listePouls[], int *tailleTab, int tempsMin, int tempsMax, double *poulMoyen);
void showMaxAndMin(struct PoulDonnees listePouls[], int *tailleTab);
