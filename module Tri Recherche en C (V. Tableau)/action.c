#include "action.h"

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

void affichage_listePoul(struct PoulDonnees listePouls[], int tailleTab)
{
	for (int i = 0; i < tailleTab; i++)
	{
		printf("%d;%d\n", listePouls[i].poul, listePouls[i].temps);
	}
}

void triABulle(struct PoulDonnees listePouls[], int *permute, int caseSelect)
{
	struct PoulDonnees temp;
	temp = listePouls[caseSelect - 1];
	listePouls[caseSelect - 1] = listePouls[caseSelect];
	listePouls[caseSelect] = temp;
	*permute = 1;
}

void triageCroissant(struct PoulDonnees listePouls[], int tailleTab, int poulOuTemps)
{
	int permute, j = 0;


	do
	{
		permute = 0;
		if (poulOuTemps == 0 || poulOuTemps == 1)
		{
			for (int i = 1; i < tailleTab - j; i++)
			{
				if (poulOuTemps == 0)
				{
					if (listePouls[i - 1].poul > listePouls[i].poul)
					{
						triABulle(listePouls, &permute, i);
					}
				}
				else if (poulOuTemps == 1)
				{
					if (listePouls[i - 1].temps > listePouls[i].temps)
					{
						triABulle(listePouls, &permute, i);
					}
				}
			}
		}
		else
		{
			printf("\nLa valeur que vous avez entre n'est pas valide !\n");
		}
		j++;
	} while (permute);
}

void triageDecroissant(struct PoulDonnees listePouls[], int tailleTab, int poulOuTemps)
{
	int permute, j = 0;
	do
	{
		permute = 0;
		if (poulOuTemps == 0 || poulOuTemps == 1)
		{
			for (int i = 1; i < tailleTab - j; i++)
			{
				if (poulOuTemps == 0)
				{
					if (listePouls[i - 1].poul < listePouls[i].poul)
					{
						triABulle(listePouls, &permute, i);
					}
				}
				else if (poulOuTemps == 1)
				{
					if (listePouls[i - 1].temps < listePouls[i].temps)
					{
						triABulle(listePouls, &permute, i);
					}
				}
			}
		}
		else
		{
			printf("\nLa valeur que vous avez entre n'est pas valide !\n");
		}
		j++;
	} while (permute);
}