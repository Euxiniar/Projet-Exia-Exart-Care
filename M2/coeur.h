/*
Name:		coeur.h
Created:	14/11/2017
Author:	Maxime
*/

#pragma once
#include "param.h"
#include <Arduino.h>

#define SEUIL 800	//valeur envoy�e par A0 quand un pouls est d�tect�


void allLEDs(int *tab);
void uneLEDsurX(int *tab);
void LEDX(int *tab);
void chenille(int *tab);