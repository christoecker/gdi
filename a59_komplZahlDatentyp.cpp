#include <stdio.h>

// Definition des Datentyps fuer eine komplexe Zahl
typedef struct {
	float real;
	float imag;
}complex;

// Funktion zum Addieren komplexer Zahlen
void addComplex(complex z1, complex z2, complex* erg) {
	erg->real = z1.real + z2.real;
	// Alternativ: (*erg).real = z1.real + z2.real;
	erg->imag = z1.imag + z2.imag;
}

// Funktion zum Subtrahieren komplexer Zahlen
void subtrComplex(complex z1, complex z2, complex* erg) {
	erg->real = z1.real - z2.real;
	erg->imag = z1.imag - z2.imag;
}

int main() {
	complex z1, z2, resSum, resSubtr;

	// Initialisierung der komplexen Zahlen
	z1.real = 1.5; z1.imag = 2.2;
	z2.real = 0.7; z2.imag = 1.1;

	addComplex(z1, z2, &resSum);
	subtrComplex(z1, z2, &resSubtr);

	// Testausgaben
	printf("(%.1f + j%.1f) + (%.1f + j%.1f) = %.1f + j%.1f\n", z1.real, z1.imag, z2.real, z2.imag, resSum.real, resSum.imag);
	printf("(%.1f + j%.1f) - (%.1f + j%.1f) = %.1f + j%.1f\n", z1.real, z1.imag, z2.real, z2.imag, resSubtr.real, resSubtr.imag);
	return 0;
}