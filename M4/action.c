/*
Name:		Coeur_LEDs.ino
Created:	14/11/2017
Author:	Charles
*/

#include "action.h"

void lireFichier(struct PoulDonnees listePouls[])
{
	FILE *f = NULL;
	int poul, temps;
	char tab[TAILLETAB];

	//ouverture du fichier
	f = fopen("./Battements.csv", "r");

	if (!f)
	{
		printf("Le fichier dataPouls.csv n'a pas pu etre lu !");
		fclose(f);
		exit(1);
	}

	//tant qu'on est pas arrivé au bout du fichier, on lit ligne par ligne
	while (fgets(tab, TAILLETAB, f) != NULL)
	{
		static int i = 0;

		//on stock le poul et le temps dans des variables tampons
		sscanf(tab, "%d ;%d", &poul, &temps);

		//puis on le stock dans le tableau de strucutures
		if (tab[0] != '\n')
		{
			listePouls[i].poul = poul;
			listePouls[i].temps = temps;
		}
		i++;
	}
	fclose(f);
}

int getTailleListePouls(struct PoulDonnees listePouls[])
{
	int i = 0;
	//tant que les valeurs de la structure select du pouls ne sont pas négatives, c'est que la structure est pleine
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
						//on inverse l'élément select avec l'élément précédent
						triABulle(listePouls, &permute, i);
					}
				}
				else if (poulOuTemps == 1)
				{
					if (listePouls[i - 1].temps < listePouls[i].temps)
					{
						//on inverse l'élément select avec l'élément précédent
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
	//on s'assure que le tableau de copie est vide
	clearTabPoulDonnees(tabQuiALaCopie);
	*tailleTab = getTailleListePouls(listePoulsToCopy);

	//on copie chaque élément dans le nouveau tableau
	for (int i = 0; i < *tailleTab; i++)
	{
		tabQuiALaCopie[i] = listePoulsToCopy[i];
	}
}

void clearTabPoulDonnees(struct PoulDonnees listePouls[])
{
	int i = 0;
	//on met tous les éléments à -1
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
	//le tableau passé en paramètre ne va plus contenir que les éléments du buf
	//on efface donc le tableau
	clearTabPoulDonnees(listePouls);
	//puis on le remplit à nouveau
	copyTabPoulDonnees(buf, tailleTab, listePouls);
	//on update la taille du tableau
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
		//on remplit  le buffer des données comrpises entre le temps min et le temps max
		if (listePouls[i].temps >= tempsMin && listePouls[i].temps <= tempsMax)
		{
			buf[y] = listePouls[i];
			y++;
		}
	}
	tailleBuf = getTailleListePouls(buf);

	//la somme correspond à la somme des pouls tous les éléments du buffer
	for (int i = 0; i < tailleBuf; i++)
	{
		sum += buf[i].poul;
	}
	//la moyenne des pouls correspond à la somme des pouls divisée par le nombre d'éléments.
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
		//si le poul max est inférieur au poul sélectionné, on le modifie
		max = (max < listePouls[i].poul ? listePouls[i].poul : max);
		//si le poul min est supérieur au poul sélectionné, on le modifie
		min = (min > listePouls[i].poul ? listePouls[i].poul : min);
	}
	printf("Le poul maximum est : %d, le poul minimum est : %d", min, max);
}

