#include <conio.h>
#include <stdio.h>

void showMenu(int *modeAffichage, int *nbLedsAllumees, int *ledAllumee)
{
	printf("Bonjour\nChoisissez mes parametres d'affichage de vos Leds :"
		"\nTapez 0 pour un clignotement au rythme du coeur"
		"\nTapez 1 pour choisir d'allumer une Led sur X"
		"\nTapez 2 pour choisir d'allumer une Led que vous choisirez"
		"\nTapez 3 Pour allumer les Leds en mode chenille\n");
	scanf("%d", modeAffichage);
	switch (*modeAffichage)
	{
	case 1:
		while (*nbLedsAllumees < 0)
		{
			printf("\nTapez une valeur comprise entre 1 et 10 : ");
			scanf("%d", nbLedsAllumees);
			if (*nbLedsAllumees < 1 || *nbLedsAllumees > 10)
			{
				printf("\nVous n'avez pas entre une valeur comprise entre 1 et 10 !\n");
				*nbLedsAllumees = -1;
			}
		}
		break;
	case 2:
		while (*ledAllumee < 0)
		{
			printf("\nChoisissez la Led a allumer, comprise entre 0 et 9 : \n");
			scanf("%d", ledAllumee);
			if (*ledAllumee < 0 || *ledAllumee > 9)
			{
				printf("\nVous avez entre une valeur inferieur a 0 ou superieure a 9 !\n");
				*ledAllumee = -1;
			}
		}
	case 3:
		while (*nbLedsAllumees < 0)
		{
			printf("\nTapez une valeur comprise entre 1 et 3 : ");
			scanf("%d", nbLedsAllumees);
			if (*nbLedsAllumees < 1 || *nbLedsAllumees > 3)
			{
				printf("\nVous n'avez pas entre une valeur comprise entre 1 et 10 !\n");
				*nbLedsAllumees = -1;
			}
		}
		break;
	default:
		break;
	}
}

void generateHeader(int *modeAffichage, int *nbLedsAllummees, int *ledAllumee)
{
	FILE *fout = NULL; 
	fout = fopen("../../Programme Arduino Led/Coeur_LEDs/param.h", "w");
	fprintf(fout, "#pragma once\n\n");
	switch (*modeAffichage)
	{
	case 0:
		fprintf(fout, "int modeAffichage = %d;\n", *modeAffichage);
		break;
	case 1:
		fprintf(fout, "int modeAffichage = %d;\nint nbLedsAllumees = %d;\n", *modeAffichage, *nbLedsAllummees);
		break;
	case 2:
		fprintf(fout, "int modeAffichage = %d;\nint ledAllumee = %d;\n", *modeAffichage, *ledAllumee);
		break;
	case 3:
		fprintf(fout, "int modeAffichage = %d;\nint nbLedsAllumees = %d;\n", *modeAffichage, *nbLedsAllummees);
		break;
	default:
		break;
	}
}

int main()
{
	int modeAffichage = -1;
	int nbLedsAllumees = -1;
	int ledAllumee = -1;
	showMenu(&modeAffichage, &nbLedsAllumees, &ledAllumee);
	generateHeader(&modeAffichage, &nbLedsAllumees, &ledAllumee);
	_getch();
	return 0;
}