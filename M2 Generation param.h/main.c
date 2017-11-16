/*
Name:		Coeur_LEDs.ino
Created:	14/11/2017
Author:	Charles
*/

#include <conio.h>
#include "menu.h"
#include "generationCode.h"

int main()
{
	int modeAffichage = -1;
	int nbLedsAllumees = -1;
	int ledAllumee = -1;
	showMenu(&modeAffichage, &nbLedsAllumees, &ledAllumee);
	generateHeader(&modeAffichage, &nbLedsAllumees, &ledAllumee);
	_getch();
	return 0;
}