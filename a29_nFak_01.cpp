#include <stdio.h>

int main() {
	int n, f = 1;

	printf("Bitte geben Sie einen Wert fuer n ein: ");
	scanf_s("%i", &n);

	// Berechnung von n! = n * n-1 * n-2 * ... * 2 * 1
	for (int i = n; i > 0; i--) {
		f *= i;
	}

	// Ausgabe von n!
	printf("%i! = %i.\n", n, f);
}