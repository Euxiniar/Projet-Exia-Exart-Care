#include "menu.h"

void showMenu(int *modeAffichage, int *nbLedsAllumees, int *ledAllumee)
{
	printf("Bonjour\nChoisissez les parametres d'affichage de vos Leds :"
		"\nTapez 0 pour un clignotement au rythme du coeur"
		"\nTapez 1 pour choisir d'allumer une Led sur X"
		"\nTapez 2 pour allumer une Led que vous choisirez"
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
		break;
	case 3:
		while (*nbLedsAllumees < 0)
		{
			printf("\nTapez une valeur comprise entre 1 et 5 : ");
			scanf("%d", nbLedsAllumees);
			if (*nbLedsAllumees < 1 || *nbLedsAllumees > 5)
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