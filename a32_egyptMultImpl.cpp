#include <stdio.h>

int main() {
	int P = 0, a, b;
	int a_bfr, b_bfr;

	printf("Bitte geben Sie nacheinander zwei Zahlen fur die Multiplikation ein: \n");
	scanf_s("%i %i", &a, &b);
	a_bfr = a;		// Zwischenspeichern der eingegebenen Zahlen
	b_bfr = b;

	do {
		if (a % 2 == 0) {	// a ist gerade
			a /= 2;
		}
		else {				// a ist ungerade
			P += b;
			a = (a - 1) / 2;
		}
		b *= 2;
	} while (a != 0);

	printf("Ergebnis nach dem Algorithmus des Aegyptischen Multiplizierens von %i * %i = %i.\n", a_bfr, b_bfr, P);
	printf("Testausgabe mit *-Operator: %i * %i = %i.\n", a_bfr, a_bfr, a_bfr*b_bfr);
}