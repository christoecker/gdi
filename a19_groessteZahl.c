#include <stdio.h>

int main() {
	int zahl1, zahl2, zahl3;
	int maxZahl, minZahl;

	printf("Bitte geben Sie nacheinander drei Zahlen ein: \n");
	scanf_s("%i %i %i", &zahl1, &zahl2, &zahl3);

	/*
		In dieser Loesung wird der ternaere Operator geschachtelt 
		verwendet. Auch wenn das programmiertechnisch korrekt ist, 
		ist diese Variante aufgrund ihrer schlechten Lesbarkeit 
		nicht zu empfehlen.
	*/
	maxZahl = zahl1 > zahl2 ? (zahl1 > zahl3 ? zahl1 : zahl3) : (zahl2 > zahl3 ? zahl2 : zahl3);
	printf("Die groesste Zahl ist %i.\n", maxZahl);

	/*
		Wenn das Minimum der eingegebenen zahlen gesucht ist, koennte
		man z.B. einfach die Vergleichsoperatoren umdrehen.
	*/
	minZahl = zahl1 < zahl2 ? (zahl1 < zahl3 ? zahl1 : zahl3) : (zahl2 < zahl3 ? zahl2 : zahl3);
	printf("Die kleinste Zahl ist %i.\n", minZahl);
}