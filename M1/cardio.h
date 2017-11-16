/*
Name:		cardio.h
Created:	14/11/2017
Author:	Anatole
*/

#pragma once
//Permet l'envoi de données au port série de l'arduino, qui serons ensuite lues dans le module processing
//tempsPrecedent : il s'agit du temps d'enregistrement de la valeur précédente
//tempsDetection : il s'agit du temps d'enregistrement de la valeur actuelle
void envoidonnees(int tempsPrecedent, int tempsDetection);


//Calcul le pouls en fonction des valeurs lues par le capteur
//valeurActuelle : en paramètre - il s'agit de la valeur lue par le capteur 
//valeurPrecedente : en référence - il s'agit de la valeur anciennement lue par le capteur
//tempsPrecedent : en référence - il s'agit du temps d'enregistrement de la valeur précédente
void calculPouls(int valeurActuelle, int *valeurPrecedente, int *tempsPrecedent);


//permet de récuperer les donnees du capteur et d'activer la fonction calculPouls pendant une durée définie (calcultime)
void recupDonnees();