#include <stdio.h>
#include <stdlib.h>
#include "a63_lager.h"

void einlagern(int L[], int p) {
	if (p >= 0 && p < SIZE) {
#ifdef PROVERSION
		if (L[p] == 1)
			printf("Achtung: Der Lagerplatz %i ist bereits belegt.\n", p);
#endif
		L[p] = 1;
	}
}

void auslagern(int L[], int p) {
	if (p >= 0 && p < SIZE) {
#ifdef PROVERSION
		if (L[p] == 0)
			printf("Achtung: Der Lagerplatz %i ist frei. Es kann nichts ausgelagert werden\n", p);
#endif
		L[p] = 0;
	}
}

void zeigeLager(int L[]) {
	system("cls");
	printf("Lagerplatz    Status\n");
	printf("--------------------\n");
	for (int i = 0; i < SIZE; i++) {
		printf("     %2i       ", i);
		L[i] == 0 ? printf("frei\n") : printf("belegt\n");
	}
}