#include <stdio.h>

int* dez2bin(int dezZahl) {
	static int binArray[7];	// Speichert die Binaerzahl

	// Falls Dez-Zahl ausserhalb des zulaessigen
	// Wertebereichs ist, liefere den NULL-Zeiger
	// zurueck
	if (dezZahl < 0 || dezZahl > 127)
		return NULL;

	// Berechnung der bin-Zahl gem. Horner Schema
	for (int i = 6; i >= 0; i--) {
		binArray[i] = dezZahl % 2;
		dezZahl /= 2;
	}
	return binArray;
}

int* getParity(int* binArray) {
	static int arrWParity[8];
	int numOfOnes = 0;
	for (int i = 0; i < 7; i++) {
		// Kopieren des binaer-Arrays
		arrWParity[i] = binArray[i];
		if (binArray[i])
			numOfOnes++; // Zaehlen der Einsen
	}

	// Falls die Anzahl der Einsen ungerade ist
	// wird das Paritaetsbit auf 1 gesetzt, andernfalls
	// auf 0. Damit wird sichergestellt, dass im Binaerwort
	// immer eine gerade Anzahl von Einsen vorhanden ist.
	if (numOfOnes % 2) 
		arrWParity[7] = 1;
	else
		arrWParity[7] = 0;

	return arrWParity;
}

int main() {
	int dezInp;
	// Benutzereingabe
	printf("Bitte geben Sie eine Dezimalzahl im Beriech von 0 bis 127 ein:\n");
	scanf_s("%i", &dezInp);
	// Geschachtelter Funktionsaufruf...
	int* binOutwP = getParity(dez2bin(dezInp));
	// ... haette auch nacheinander gemacht werden koennen:
	// int* binOut = dez2bin(dezInp);
	// int* binOutwP = getParity(binOut);

	printf("Ausgabe der Binaerzahl mit Paritaetsbit an letzter Stelle:\n");
	for (int i = 0; i < 8; i++) {
		printf("%i", *(binOutwP + i));
	}
	printf("_(2)\n");
	return 0;
}