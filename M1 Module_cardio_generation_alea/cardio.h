/*
Name:		cardio.h
Created:	14/11/2017
Author:	Anatole
*/

#pragma once
#include <Arduino.h>

//Permet l'envoi de donn�es au port s�rie de l'arduino, qui serons ensuite lues dans le module processing
//tempsPrecedent : il s'agit du temps d'enregistrement de la valeur pr�c�dente
//tempsDetection : il s'agit du temps d'enregistrement de la valeur actuelle
void envoidonnees(int tempsPrecedent, int tempsDetection);


//Calcul le pouls en fonction des valeurs lues par le capteur
//valeurActuelle : en param�tre - il s'agit de la valeur lue par le capteur 
//valeurPrecedente : en r�f�rence - il s'agit de la valeur anciennement lue par le capteur
//tempsPrecedent : en r�f�rence - il s'agit du temps d'enregistrement de la valeur pr�c�dente
void calculPouls(int valeurActuelle, int *valeurPrecedente, int *tempsPrecedent);


//permet de r�cuperer les donnees du capteur et d'activer la fonction calculPouls pendant une dur�e d�finie (calcultime)
void recupDonnees(int valeurActuelle);

//Permet de simuler des valeurs de pouls en l'absence des donn�es du capteur
int simulationPouls();