#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>

#define TAILLETAB 100

struct PoulDonnees
{
	int poul;
	int temps;
	struct PoulDonnees *next;
};

void libererTransitions(struct lTransitions **listePouls)
{
		free(listePouls[0]);
}

// Crée une transition avec un character et un état final
// c  - caractère de la transition
// e2 - état suivant après la lecture du caractère c
struct PoulDonnees *creerTransition(int poul, int temps)
{
	struct PoulDonnees *t = NULL;
	//allouer la transition et assigner les valeurs
	t = malloc(sizeof(struct PoulDonnees));
	t->poul = poul;
	t->temps = temps;
	t->next = NULL;

	return t;
}

// Ajout une transition dans l'automate. La transition sera rajoutée par la tête de la liste
// e1  - etat initial de la transition. L'état correspond à l'indice du tableau 'automate'
// t - transition
void ajouterTransition(struct PoulDonnees **listePouls, struct PoulDonnees *t)
{
	//ajouter la transition par la tête de liste dans le tableau automate à l'index 'e1'. ATTENTION a maintenir l'intégralité de la liste chaînée	
	t->next = listePouls[0];
	listePouls[0] = t;
}

void lireFichier(struct PoulDonnees **listePouls)
{
	FILE *f = NULL; // représente un fichier en C
	int poul, temps; // e1 etat initial d'une transition et e2 état final d'une transition
	char tab[TAILLETAB]; // Chaîne de caractères qui nous servira pour la lecture ligne par ligne du fichier (~buffer de lecture)
	struct PoulDonnees *t = NULL; // Pointeur vers une transition

	// Ouverture du du fichier
	f = fopen("./dataPouls.csv", "r");

	// Vérifier si le fichier a bien été ouvert. Sinon, envoyer une erreur et sortir du programme
	if (!f)
	{
		printf("Le fichier dataPouls.csv n'a pas pu etre lu !");
		fclose(f);
		exit(1);
	}

	// Lecture de toutes les transitions de l'automate - Lit ligne par ligne jusqu'à la fin du fichier
	while (fgets(tab, TAILLETAB, f) != NULL)
	{
		//Récupérer dans les variables e1, c et e2 les valeurs lues dans le fichier et qui ont été stockées dans tab à l'aide de la fonction sscanf()
		sscanf(tab, "%d %d", &poul, &temps);

		//Créer une transition avec c et e2 (faire appel à des fonctions déjà définies dans ce même fichier)
		t = creerTransition(poul, temps);

		//Ajouter la transition créée dans l'automate en utilisant e1 comme indice du tableau 'automate' (faire appel à des fonctions déjà définies dans ce même fichier)
		ajouterTransition(listePouls, t);
	}

	// Fermer le fichier
	fclose(f);
}

void affichage_csv(struct PoulDonnees **listePouls)
{

}

void tri_bulles(struct PoulDonnees **listePouls, struct PoulDonnees **poulsTries, int sens)
{
}

struct PoulDonnees recherche(int maxOrMin, struct PoulDonnees **poulsTries)
{
	return struct PoulDonnees;
}

int menu()
{

}

int main()
{
	struct PoulDonnees *listePouls[1];
	struct PoulDonnees *poulsTries[1];
	listePouls[0] = NULL;
	tri_bulles(listePouls, poulsTries);
	lireFichier(listePouls);
	libererTransitions(listePouls);
	_getch();
	return 0;
}

