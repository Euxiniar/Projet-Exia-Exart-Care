#include "generationCode.h"

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
