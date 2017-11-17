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
	struct PoulDonnees listePouls[TAILLETAB];
	struct PoulDonnees listePoulsCopy[TAILLETAB];
	int maxOrMin = 0;
	lireFichier(listePouls);
	int tailleListePouls = getTailleListePouls(listePouls);

	copyTabPoulDonnees(listePouls, &tailleListePouls, listePoulsCopy);
	showMenu(listePoulsCopy, &tailleListePouls);
	_getch();
	return 0;
}