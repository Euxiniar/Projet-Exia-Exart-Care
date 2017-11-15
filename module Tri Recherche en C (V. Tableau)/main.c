#include "menu.h"
#include "action.h"

int main()
{
	struct PoulDonnees listePouls[TAILLETAB];
	
	int maxOrMin = 0;
	lireFichier(listePouls);
	int tailleListePouls = getTailleListePouls(listePouls);
	triageDecroissant(listePouls, tailleListePouls, 0);
	affichage_listePoul(listePouls, tailleListePouls);
	_getch();
	return 0;
}