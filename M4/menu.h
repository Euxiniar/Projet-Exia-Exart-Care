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

//Fonction qui affiche le menu et qui gère l'appel des fonctions
void showMenu(struct PoulDonnees listePoul[], int *tailleTab);
