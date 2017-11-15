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
	triCroissant(listePoulsCopy, &tailleListePouls, 0);
	affichage_listePoul(listePoulsCopy, &tailleListePouls);
	printf("\n");

	copyTabPoulDonnees(listePouls, &tailleListePouls, listePoulsCopy);
	triCroissant(listePoulsCopy, &tailleListePouls, 1);
	affichage_listePoul(listePoulsCopy, &tailleListePouls);
	printf("\n");

	copyTabPoulDonnees(listePouls, &tailleListePouls, listePoulsCopy);
	triDecroissant(listePoulsCopy, &tailleListePouls, 0);
	affichage_listePoul(listePoulsCopy, &tailleListePouls);
	printf("\n");

	copyTabPoulDonnees(listePouls, &tailleListePouls, listePoulsCopy);
	triDecroissant(listePoulsCopy, &tailleListePouls, 1);
	affichage_listePoul(listePoulsCopy, &tailleListePouls);
	printf("\n");

	double poulMoyen = 0;
	copyTabPoulDonnees(listePouls, &tailleListePouls, listePoulsCopy);
	getMoyennePoulsSelonTemps(listePoulsCopy, &tailleListePouls, 0, 20, &poulMoyen);
	printf("\n");

	copyTabPoulDonnees(listePouls, &tailleListePouls, listePoulsCopy);
	showMaxAndMin(listePoulsCopy, &tailleListePouls);
	_getch();
	return 0;
}