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
	struct PoulDonnees *last;
};

void libererDonneesPoul(struct PoulDonnees **listePouls)
{
		free(listePouls[0]);
}

// Cr�e une transition avec un character et un �tat final
// c  - caract�re de la transition
// e2 - �tat suivant apr�s la lecture du caract�re c
struct PoulDonnees *creerDonneePoul(int poul, int temps)
{
	struct PoulDonnees *t = NULL;
	//allouer la transition et assigner les valeurs
	t = malloc(sizeof(struct PoulDonnees));
	t->poul = poul;
	t->temps = temps;
	t->next = NULL;

	return t;
}

// Ajout une transition dans l'automate. La transition sera rajout�e par la t�te de la liste
// e1  - etat initial de la transition. L'�tat correspond � l'indice du tableau 'automate'
// t - transition
void ajouterDonneePoul(struct PoulDonnees **listePouls, struct PoulDonnees *donneePoul)
{
	if (listePouls[0] == NULL)
	{
		listePouls[0] = donneePoul;
		listePouls[0]->last = donneePoul;
	}
	else
	{
		listePouls[0]->last->next = donneePoul;
		listePouls[0]->last = donneePoul;
	}
}

void lireFichier(struct PoulDonnees **listePouls)
{
	FILE *f = NULL; // repr�sente un fichier en C
	int poul, temps; // e1 etat initial d'une transition et e2 �tat final d'une transition
	char tab[TAILLETAB]; // Cha�ne de caract�res qui nous servira pour la lecture ligne par ligne du fichier (~buffer de lecture)
	struct PoulDonnees *t = NULL; // Pointeur vers une transition

	// Ouverture du du fichier
	f = fopen("./dataPouls.csv", "r");

	// V�rifier si le fichier a bien �t� ouvert. Sinon, envoyer une erreur et sortir du programme
	if (!f)
	{
		printf("Le fichier dataPouls.csv n'a pas pu etre lu !");
		fclose(f);
		exit(1);
	}

	// Lecture de toutes les transitions de l'automate - Lit ligne par ligne jusqu'� la fin du fichier
	while (fgets(tab, TAILLETAB, f) != NULL)
	{
		//R�cup�rer dans les variables e1, c et e2 les valeurs lues dans le fichier et qui ont �t� stock�es dans tab � l'aide de la fonction sscanf()
		sscanf(tab, "%d ;%d", &poul, &temps);

		//Cr�er une transition avec c et e2 (faire appel � des fonctions d�j� d�finies dans ce m�me fichier)
		t = creerDonneePoul(poul, temps);

		//Ajouter la transition cr��e dans l'automate en utilisant e1 comme indice du tableau 'automate' (faire appel � des fonctions d�j� d�finies dans ce m�me fichier)
		ajouterDonneePoul(listePouls, t);
	}

	// Fermer le fichier
	fclose(f);
}

void affichage_csv(struct PoulDonnees *listePouls)
{
	struct PoulDonnees *buf = listePouls;
	while (buf != NULL)
	{
		printf("%d %d\n", buf->poul, buf->temps);
		buf = listePouls->next;
		listePouls = listePouls->next;
	}
}

void tri_bulles(struct PoulDonnees *listePouls, struct PoulDonnees **poulsTries, int sens)
{
}

struct PoulDonnees recherche(int maxOrMin, struct PoulDonnees **poulsTries)
{
	return *poulsTries[0];
}

int menu()
{
	return 0;
}

int main()
{
	struct PoulDonnees *listePouls[1];
	struct PoulDonnees *poulsTries[1];
	int maxOrMin = 0;
	listePouls[0] = NULL;
	poulsTries[0] = NULL;
	lireFichier(listePouls);
	affichage_csv(listePouls[0]);
	libererDonneesPoul(listePouls);
	_getch();
	return 0;
}

