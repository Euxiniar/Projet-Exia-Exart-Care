/*
Name:		generationCode.c
Created:	14/11/2017
Author:	Charles
*/

#include "generationCode.h"

void generateHeader(int *modeAffichage, int *nbLedsAllummees, int *ledAllumee)
{
	FILE *fout = NULL;
	printf("En cours de generation...\n");
	fout = fopen("../M2/param.h", "w");
	fprintf(fout, "#pragma once\n\n");
	fprintf(fout, "#define modeAffichage %d\n#define nbLedsAllumees %d\n#define ledAllumee %d\n", *modeAffichage, *nbLedsAllummees, *ledAllumee);
	printf("Succes !");
}
