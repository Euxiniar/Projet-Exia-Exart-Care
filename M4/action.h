/*
Name:		action.h
Created:	14/11/2017
Author:	Charles
*/

#pragma once

#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>

#define TAILLETAB 100

struct PoulsDonnees
{
	int pouls;
	int temps;
};

// Fonction qui lit le fichier
void lireFichier(struct PoulsDonnees listePouls[]);
// Fonction qui permet d'avoir le nombre d'elements d'un tableau de donnees liees au poul
int getTailleTabPouls(struct PoulsDonnees listePouls[]);
// Affiche les donnees d'un tableau de poul
void affichage_listePouls(struct PoulsDonnees listePouls[], int *tailleTab);
// Fonction qui inverse deux elements dans un tableau de pouls
void triABulles(struct PoulsDonnees listePouls[], int *permute, int caseSelect);
// Fonction qui effectue un tri croissant selon le poul et selon le temps
void triCroissant(struct PoulsDonnees listePouls[], int *tailleTab, int poulOuTemps);
// Fonction qui effectue un tri decroissant selon le poul et selon le temps
void triDecroissant(struct PoulsDonnees listePouls[], int *tailleTab, int poulOuTemps);
// Fonction qui copie un tableau de pouls dans un second tableau de pouls
void copyTabPoulDonnees(struct PoulsDonnees listePoulsToCopy[], int *tailleTab, struct PoulsDonnees tabQuiALaCopie[]);
// Fonction qui efface un tableau de pouls (qui mets les valeurs a -1)
void clearTabPoulDonnees(struct PoulsDonnees listePouls[]);
// Fonction qui recherche des pouls selon un temps demande)
void recherchePoulsSelonTemps(struct PoulsDonnees listePouls[], int *tailleTab, int temps);
// Fonction qui permet d'avoir une moyenne de pouls dans une tranche de temps
void getMoyennePoulsSelonTemps(struct PoulsDonnees listePouls[], 
	int *tailleTab, int tempsMin, 
	int tempsMax, double *poulMoyen);
// Fonction qui permet de voir le poul minimum et maximum d'un tableau de pouls
void showMaxAndMin(struct PoulsDonnees listePouls[], int *tailleTab);
//Fonction qui affiche la date de creation du fichier
void affichage_date();
