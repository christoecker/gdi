#include <stdio.h>
#include <math.h>

// Funktionsprototypen
float absVal(float);
float absValComplex(float, float);

int main() {
	float f_inp, f_real, f_imag;

	// Test des ersten Teils der Aufgabe
	printf("Bitte geben Sie eine Gleitkommazahl ein:\n");
	scanf_s("%f", &f_inp);
	printf("Der Betrag der Zahl ist %f.\n", absVal(f_inp));

	// Test des zweiten Teils der Aufgabe
	printf("Bitte geben Sie Real- und Imaginaerteil einer komplexen Zahl ein:\n");
	scanf_s("%f%f", &f_real, &f_imag);
	printf("Betrag der komplexen Zahl %.1f + j(%.1f) = %.1f\n.", f_real, f_imag, absValComplex(f_real, f_imag));
}

// Berechnung des Betrags einer reellen Zahl
float absVal(float inp) {
	if (inp < 0)
		return -inp;
	else
		return inp;
}

// Berechnung des Betrags einer komplexen Zahl
float absValComplex(float real, float imag) {
	// Die Verwendung der Funktion sqrt erfordert die Einbindung der
	// math.h Bibliothek
	return (sqrt(real*real + imag * imag));
}