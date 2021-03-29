#include <stdio.h>

#define _USE_MATH_DEFINES  // Damit definierte Konstanten
						   // verwendet werden koennen.
#include <math.h>

// Programm "Kreisdurchmesser"
int main() {
	float U;

	printf("Bitte geben Sie den Kreisumfang an: ");
	scanf_s("%f", &U);

	printf("1. Berechnung mit haendisch eingegebenem Pi:\n");
	printf("Der Durchmesser betraegt d = %f.\n", U / 3.14);

	/*
		Es gibt eine alternative Moeglichkeit zur Berechnung.
		Diese verwendet die in der Header-Datei "math.h definierte
		Konstante M_PI. 
	*/

	printf("2. Berechnung mit definiertem Pi:\n");
	printf("Der Durchmesser betraegt d = %f.\n", U / M_PI);
}