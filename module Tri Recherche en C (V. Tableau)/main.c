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
};

void lireFichier(struct PoulDonnees listePouls[])
{
	FILE *f = NULL; 
	int poul, temps; 
	char tab[TAILLETAB]; 

								
	f = fopen("./Battements.csv", "r");

	if (!f)
	{
		printf("Le fichier dataPouls.csv n'a pas pu etre lu !");
		fclose(f);
		exit(1);
	}

	while (fgets(tab, TAILLETAB, f) != NULL)
	{
		static int i = 0;

		sscanf(tab, "%d ;%d", &poul, &temps);

		listePouls[i].poul = poul;
		listePouls[i].temps = temps;
		i++;
	}
	fclose(f);
}

int getTailleListePouls(struct PoulDonnees listePouls[])
{
	int i = 0;
	while (listePouls[i].poul >= 0)
	{
		i++;
	}
	return i;
}

void affichage_csv(struct PoulDonnees listePouls[], int tailleTab)
{
	for(int i = 0; i < tailleTab; i++)
	{
		printf("%d;%d\n", listePouls[i].poul, listePouls[i].temps);
	}
}

void triageCroissant(struct PoulDonnees listePouls[], int tailleTab, int poulOuTemps)
{
	//int donneeDeTriage = (poulOuTemps == 0 ? 0 : (poulOuTemps == 1 ? 1 : -1));
	int permute, j = 0;
	struct PoulDonnees temp;

	do
	{
		permute = 0;
		for (int i = 0; i < tailleTab - j; i++)
		{
			if (listePouls[i - 1].poul > listePouls[i].poul)
			{
				temp = listePouls[i - 1];
				listePouls[i - 1] = listePouls[i];
				listePouls[i] = temp;
				permute = 1;
			}
		}
		j++;
	} while (permute);
}

int main()
{
	struct PoulDonnees listePouls[TAILLETAB];
	
	struct PoulDonnees poulsTries[TAILLETAB];
	int maxOrMin = 0;
	lireFichier(listePouls);
	int tailleListePouls = getTailleListePouls(listePouls);
//	affichage_csv(listePouls, tailleListePouls);
	triageCroissant(listePouls, tailleListePouls, 2);
	affichage_csv(listePouls, tailleListePouls);
	_getch();
	return 0;
}