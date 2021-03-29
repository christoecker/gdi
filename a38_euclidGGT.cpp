#include <stdio.h>

// Euclidischer Algorithmus zur Ermittlung des ggt
int ggt(int a, int b) {
	if (a == b) {
		return a;				// Abbruch der Rekursion
	}
	else if (a > b) {
		return ggt(a - b, b);	// Rekursion
	}
	else {
		return ggt(a, b - a);	// Rekursion
	}
}

int main() {
	int a, b;
	
	// Testausgabe
	printf("Bitte zwei ganze Zahlen eingeben:\n");
	scanf_s("%i%i", &a, &b);
	printf("\nDer groesste gemeinsame Teiler von %i und %i ist %i.\n", a, b, ggt(a, b));
}