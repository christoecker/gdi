#include <stdio.h>

void getData(int *data) {
	printf("Bitte 4 Messwerte eingeben:\n");
	for (int i = 0; i < 4; i++) {
		rewind(stdin);		// Eingabepuffer leeren
		scanf_s("%i", (data + i));
		/*
			Beachte: die Anweisung "data + i" inkrementiert
			den Pointer, d.h. data + 0 adressiert das 0.
			Element des Arrays, data + 1 das 1. Element usw.
			Die Benutzereingaben werden direkt in das Array
			geschrieben.
		*/
	}
}

int main() {
	int dataBfr[4];

	getData(dataBfr);

	// Testausgabe
	for (int i = 0; i < 4; i++) {
		printf("%i. Messwert: %i\n", i+1, dataBfr[i]);
	}
	return 0;
}