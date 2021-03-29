#include <stdio.h>

// Programm "Messwertumrechnung"
int main() {
	int messwert;
	float prozWert;

	printf("Simulation des Messwerts. Bitte Wert eingeben: ");
	scanf_s("%i", &messwert);

	// Berechnung und Ausgabe des Werts skaliert auf den Bereich 0..100 %
	prozWert = messwert * 100 / 1023;
	/*
		Achtung: Die Reihenfolge der Berechnungsschritte ist hier
		entscheidend. Wuerde man
			prozWert = messwert / 1023 * 100;
		berechnen, waere das Ergebnis 0 fuer alle Werte ausser 
		den messwert 1023, da zunaechst der int-Wert durch
		1023 dividiert wird und das Ergebnis auf einen ganzzahligen
		Wert gerundet wird.
	*/
	printf("Der Messwert %i entspricht %.1f %%\n", messwert, prozWert);
}