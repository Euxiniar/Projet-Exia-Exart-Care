/*
Name:		menu.h
Created:	14/11/2017
Author:	Thomas
*/

#pragma once

#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>
#include "action.h"

// Fonction affichant le menu et gerant les appels des fonctions
void showMenu(struct PoulsDonnees listePoul[], int *tailleTab);
