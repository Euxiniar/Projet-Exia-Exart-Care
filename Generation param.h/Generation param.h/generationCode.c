#include "generationCode.h"

void generateHeader(int *modeAffichage, int *nbLedsAllummees, int *ledAllumee)
{
	FILE *fout = NULL;
	fout = fopen("../../Programme Arduino Led/Coeur_LEDs/param.h", "w");
	fprintf(fout, "#pragma once\n\n");
	fprintf(fout, "int modeAffichage = %d;\nint nbLedsAllumees = %d;int ledAllumee = %d;\n", *modeAffichage, *nbLedsAllummees, *ledAllumee);

}
