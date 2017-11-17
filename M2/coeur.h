/*
Name:		coeur.h
Created:	14/11/2017
Author:	Maxime
*/

#pragma once
#include "param.h"
#include <Arduino.h>

#define SEUIL 800	//valeur envoyée par A0 quand un pouls est détecté


void allLEDs(int *tab);
void uneLEDsurX(int *tab);
void LEDX(int *tab);
void chenille(int *tab);