#include <stdio.h>

// Programm "Benzinverbrauch"
int main() {
	float verbrauch, km, verbPro100km;

	printf("Bitte geben Sie die gefahrenen km ein: ");
	scanf_s("%f", &km);
	printf("Bitte geben Sie den Benzinverbrauch in l an: ");
	scanf_s("%f", &verbrauch);

	// Berechnung und Ausgabe des Benzinverbrauchs pro 100 km
	verbPro100km = verbrauch / km * 100;
	printf("Der Benzinverbrauch betraegt %.2f l pro 100 km.\n", verbPro100km);
}