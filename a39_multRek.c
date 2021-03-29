#include <stdio.h>

// Funktion berechnet rekursiv a*b
double multRek(double a, double b) {
	if (b == 1)
		return a;
	else
		return a + multRek(a, b - 1);
}

int main() {
	double a = 0.0, b = 0.0;	// Variablen fuer Benutzereingaben
	
	printf("Bitte geben Sie zwei Zahlen ein, die multipliziert werden sollen:\n");
	scanf_s("%lf%lf", &a, &b);
	printf("\n %.2f * %.2f = %.4f.\n", a, b, multRek(a, b));
}