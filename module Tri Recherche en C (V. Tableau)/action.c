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

void affichage_listePoul(struct PoulDonnees listePouls[], int *tailleTab)
{
	for (int i = 0; i < *tailleTab; i++)
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

void triCroissant(struct PoulDonnees listePouls[], int *tailleTab, int poulOuTemps)
{
	int permute, j = 0;

	do
	{
		permute = 0;
		if (poulOuTemps == 0 || poulOuTemps == 1)
		{
			for (int i = 1; i < *tailleTab - j; i++)
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

void triDecroissant(struct PoulDonnees listePouls[], int *tailleTab, int poulOuTemps)
{
	int permute, j = 0;
	do
	{
		permute = 0;
		if (poulOuTemps == 0 || poulOuTemps == 1)
		{
			for (int i = 1; i < *tailleTab - j; i++)
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

void copyTabPoulDonnees(struct PoulDonnees listePoulsToCopy[], int *tailleTab, struct PoulDonnees tabQuiALaCopie[])
{
	clearTabPoulDonnees(tabQuiALaCopie);
	*tailleTab = getTailleListePouls(listePoulsToCopy);

	for (int i = 0; i < *tailleTab; i++)
	{
		tabQuiALaCopie[i] = listePoulsToCopy[i];
	}
}

void clearTabPoulDonnees(struct PoulDonnees listePouls[])
{
	int i = 0;
	while (listePouls[i].poul >= 0)
	{
		listePouls[i].poul = -1;
		listePouls[i].temps = -1;
		i++;
	}
}

void recherchePoulsSelonTemps(struct PoulDonnees listePouls[], int *tailleTab, int temps)
{
	struct PoulDonnees buf[TAILLETAB];
	
	int y = 0;
	for (int i = 0; i < *tailleTab; i++)
	{
		if (listePouls[i].temps == temps)
		{
			buf[y] = listePouls[i];
			y++;
		}
	}
	clearTabPoulDonnees(listePouls);
	copyTabPoulDonnees(buf, tailleTab, listePouls);
	*tailleTab = getTailleListePouls(listePouls);
}

void getMoyennePoulsSelonTemps(struct PoulDonnees listePouls[], int * tailleTab, int tempsMin, int tempsMax, double *poulMoyen)
{
	struct PoulDonnees buf[TAILLETAB];
	int tailleBuf = 0;
	int sum = 0;

	int y = 0;
	for (int i = 0; i < *tailleTab; i++)
	{
		if (listePouls[i].temps >= tempsMin && listePouls[i].temps <= tempsMax)
		{
			buf[y] = listePouls[i];
			y++;
		}
	}
	tailleBuf = getTailleListePouls(buf);
	for (int i = 0; i < tailleBuf; i++)
	{
		sum += buf[i].poul;
	}
	*poulMoyen = (double)sum / (double)tailleBuf;
}

void showMaxAndMin(struct PoulDonnees listePouls[], int * tailleTab)
{
	
	int min, max;
	if (*tailleTab > 0)
	{
		max = listePouls[0].poul;
		min = listePouls[0].poul;
	}
	for (int i = 0; i < *tailleTab; i++)
	{
		max = (max < listePouls[i].poul ? listePouls[i].poul : max);
		min = (min > listePouls[i].poul ? listePouls[i].poul : min);
	}
	printf("%d %d", min, max);
}

