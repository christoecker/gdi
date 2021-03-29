#include <stdio.h>

// Funktion berechnet die Potenz x^n (mit n in R)
double potenz(double x, int n) {
	int nIsNeg = 0;		// Merker fuer den Fall, dass n < 0 ist
	double r = 1.0;		// Ergebnisvariable

	if (n < 0) {
		nIsNeg = 1;		// Merker wird gesetzt
		n = -n;			// Betrag von n bilden
	}

	// Berechnung von x^n
	for (int i = 1; i <= n; i++) {
		r = r * x;
	}

	if (nIsNeg)
		return 1 / r;	// Rueckgabe, falls n < 0  
	else
		return r;		// Rueckgabe fuer n >= 0
}

int main() {
	double x_inp;		// Variable fuer die Basis
	int n_inp;			// Variable fuer die Potenz

	// Benutzereingabe
	printf("Bitte geben Sie x und n ein.\n");
	scanf_s("%lf%i", &x_inp, &n_inp);
	// Achtung: Zum Einlesen einer Variablen vom Typ double muss
	// die Formatierung %lf verwendet werden.

	// Testausgabe
	printf("\nErgebnis der Berechnung:\n");
	printf("%.2f^%i = %.4f\n", x_inp, n_inp, potenz(x_inp, n_inp));
}