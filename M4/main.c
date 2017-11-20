/*
Name:		main.c
Created:	14/11/2017
Author:	Charles et Thomas
*/

#include "menu.h"
#include "action.h"

// Definiton des tableaux de structures et acquisition de leur taille
int main()
{
	struct PoulsDonnees listePouls[TAILLETAB];
	struct PoulsDonnees listePoulsCopy[TAILLETAB];
	int maxOrMin = 0;
	lireFichier(listePouls);
	int tailleListePouls = getTailleTabPouls(listePouls);

	copyTabPoulDonnees(listePouls, &tailleListePouls, listePoulsCopy);
	showMenu(listePoulsCopy, &tailleListePouls);
	_getch();
	return 0;
}