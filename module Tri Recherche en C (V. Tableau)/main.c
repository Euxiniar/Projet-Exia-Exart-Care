#include "menu.h"
#include "action.h"

int main()
{
	struct PoulDonnees listePouls[TAILLETAB];
	struct PoulDonnees listePoulsCopy[TAILLETAB];
	int maxOrMin = 0;
	lireFichier(listePouls);
	int tailleListePouls = getTailleListePouls(listePouls);

	copyTabPoulDonnees(listePouls, &tailleListePouls, listePoulsCopy);
	recherchePoulsSelonTemps(listePoulsCopy, &tailleListePouls, 50);
	affichage_listePoul(listePoulsCopy, &tailleListePouls);
	printf("\n");

	copyTabPoulDonnees(listePouls, &tailleListePouls, listePoulsCopy);
	triageCroissant(listePoulsCopy, &tailleListePouls, 0);
	affichage_listePoul(listePoulsCopy, &tailleListePouls);
	printf("\n");

	copyTabPoulDonnees(listePouls, &tailleListePouls, listePoulsCopy);
	triageCroissant(listePoulsCopy, &tailleListePouls, 1);
	affichage_listePoul(listePoulsCopy, &tailleListePouls);
	printf("\n");

	copyTabPoulDonnees(listePouls, &tailleListePouls, listePoulsCopy);
	triageDecroissant(listePoulsCopy, &tailleListePouls, 0);
	affichage_listePoul(listePoulsCopy, &tailleListePouls);
	printf("\n");

	copyTabPoulDonnees(listePouls, &tailleListePouls, listePoulsCopy);
	triageDecroissant(listePoulsCopy, &tailleListePouls, 1);
	affichage_listePoul(listePoulsCopy, &tailleListePouls);
	printf("\n");

	_getch();
	return 0;
}