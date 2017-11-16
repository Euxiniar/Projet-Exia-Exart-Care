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
	showMenu(listePoulsCopy, &tailleListePouls);
	_getch();
	return 0;
}