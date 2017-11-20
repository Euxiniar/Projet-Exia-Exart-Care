/*
Name:		action.c
Created:	14/11/2017
Author:	Charles
*/

#include "action.h"

void lireFichier(struct PoulsDonnees listePouls[])
{
	FILE *f = NULL;
	int pouls, temps;
	char tab[TAILLETAB];

	// Ouverture du fichier
	f = fopen("./Battements.csv", "r");

	if (!f)
	{
		printf("Le fichier dataPouls.csv n'a pas pu etre lu !");
		fclose(f);
		exit(1);
	}

	// Lecture ligne par ligne tant que on est pas a la fin du fichier
	while (fgets(tab, TAILLETAB, f) != NULL)
	{
		static int i = 0;

		// Stockage du pouls dans des variables tampons
		sscanf(tab, "%d ;%d", &pouls, &temps);

		// Puis stockage dans le tableau de structure
		if (tab[0] != '\n')
		{
			listePouls[i].pouls = pouls;
			listePouls[i].temps = temps;
		}
		i++;
	}
	fclose(f);
}

int getTailleTabPouls(struct PoulsDonnees listePouls[])
{
	int i = 0;
	// Tant que les valeurs de la structure select du pouls ne sont pas negatives, c'est que la structure est pleine
	while (listePouls[i].pouls >= 0)
	{
		i++;
	}
	return i;
}

void affichage_listePouls(struct PoulsDonnees listePouls[], int *tailleTab)
{
	for (int i = 0; i < *tailleTab; i++)
	{
		printf("Poul : %d, Temps : %d\n", listePouls[i].pouls, listePouls[i].temps);
	}
}

void affichage_date()
{
	FILE *f = NULL;
	char tab[TAILLETAB];

	// Ouverture du fichier
	f = fopen("./Date.csv", "r");

	if (!f)
	{
		printf("Le fichier dataPouls.csv n'a pas pu etre lu !");
		fclose(f);
		exit(1);
	}

	// Lecture de la premiere ligne du fichier
	fgets(tab, TAILLETAB, f);
	fclose(f);
	printf("La date de mesure a ete enregistree le %s", tab);
}

void triABulles(struct PoulsDonnees listePouls[], int *permute, int caseSelect)
{
	struct PoulsDonnees temp;
	temp = listePouls[caseSelect - 1];
	listePouls[caseSelect - 1] = listePouls[caseSelect];
	listePouls[caseSelect] = temp;
	*permute = 1;
}

void triCroissant(struct PoulsDonnees listePouls[], int *tailleTab, int poulOuTemps)
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
					if (listePouls[i - 1].pouls > listePouls[i].pouls)
					{
						triABulles(listePouls, &permute, i);
					}
				}
				else if (poulOuTemps == 1)
				{
					if (listePouls[i - 1].temps > listePouls[i].temps)
					{
						triABulles(listePouls, &permute, i);
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

void triDecroissant(struct PoulsDonnees listePouls[], int *tailleTab, int poulOuTemps)
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
					if (listePouls[i - 1].pouls < listePouls[i].pouls)
					{
						// Inversement de l'element avec le precedent
						triABulles(listePouls, &permute, i);
					}
				}
				else if (poulOuTemps == 1)
				{
					if (listePouls[i - 1].temps < listePouls[i].temps)
					{
						// Inversement de l'element avec le precedent
						triABulles(listePouls, &permute, i);
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

void copyTabPoulDonnees(struct PoulsDonnees listePoulsToCopy[], int *tailleTab, struct PoulsDonnees tabQuiALaCopie[])
{
	// Permet de vider le tableau et lui redonner la bonne taille
	clearTabPoulDonnees(tabQuiALaCopie);
	*tailleTab = getTailleTabPouls(listePoulsToCopy);

	// Copie de chaque element dans le nouveau tableau
	for (int i = 0; i < *tailleTab; i++)
	{
		tabQuiALaCopie[i] = listePoulsToCopy[i];
	}
}

void clearTabPoulDonnees(struct PoulsDonnees listePouls[])
{
	int i = 0;
	// Definition de tous les elemnts a -1
	while (listePouls[i].pouls >= 0)
	{
		listePouls[i].pouls = -1;
		listePouls[i].temps = -1;
		i++;
	}
}

void recherchePoulsSelonTemps(struct PoulsDonnees listePouls[], int *tailleTab, int temps)
{
	struct PoulsDonnees buf[TAILLETAB];
	
	int y = 0;
	for (int i = 0; i < *tailleTab; i++)
	{
		if (listePouls[i].temps == temps)
		{
			buf[y] = listePouls[i];
			y++;
		}
	}
	// Le tableau passe en parametre ne contient plus que les elements du buffer
	// Nouveau remplissage du tableau
	copyTabPoulDonnees(buf, tailleTab, listePouls);
	// Mise a jour de la taille du tableau
	*tailleTab = getTailleTabPouls(listePouls);
}

void getMoyennePoulsSelonTemps(struct PoulsDonnees listePouls[], int * tailleTab, int tempsMin, int tempsMax, double *poulMoyen)
{
	struct PoulsDonnees buf[TAILLETAB];
	int tailleBuf = 0;
	int sum = 0;

	int y = 0;
	for (int i = 0; i < *tailleTab; i++)
	{
		// Remplissage du buffer par les donnees comprises entre le temps minimum et le temps maximum
		if (listePouls[i].temps >= tempsMin && listePouls[i].temps <= tempsMax)
		{
			buf[y] = listePouls[i];
			y++;
		}
	}
	tailleBuf = getTailleTabPouls(buf);

	// Calcul de la somme des pouls dans le buffer
	for (int i = 0; i < tailleBuf; i++)
	{
		sum += buf[i].pouls;
	}
	// Calcul de la somme des pouls divisee par le nombre d'elements
	*poulMoyen = (double)sum / (double)tailleBuf;
}

void showMaxAndMin(struct PoulsDonnees listePouls[], int * tailleTab)
{
	int min, max;
	if (*tailleTab > 0)
	{
		max = listePouls[0].pouls;
		min = listePouls[0].pouls;
	}
	for (int i = 0; i < *tailleTab; i++)
	{
		// Modification du poul si le poul max est inferieur au poul selectionne
		max = (max < listePouls[i].pouls ? listePouls[i].pouls : max);
		// Modification du poul si le poul min est superieur au poul selectionne
		min = (min > listePouls[i].pouls ? listePouls[i].pouls : min);
	}
	printf("Le poul minimum est : %d, le poul maximum est : %d", min, max);
}

