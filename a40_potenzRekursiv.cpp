#include <stdio.h>

// Funktion berechnet rekursiv die Potenz x^n (mit n in R+)
// ACHTUNG: Funktioniert nur fuer n >= 0
double potenz(double x, int n) {
	if (n == 0)
		return 1;			// Abbruch der Rekursion
	else
		return x * potenz(x, n - 1);	// Rekursion
}

int main() {
	double x_inp;		// Variable fuer die Basis
	int n_inp;			// Variable fuer die Potenz

						// Benutzereingabe
	printf("Bitte geben Sie x und n ein.\n");
	scanf_s("%lf%i", &x_inp, &n_inp);
	// Achtung: Zum Einlesen einer Variablen vom Typ double muss
	// die Formatierung %lf verwendet werden.

	// Testausgabe: Da die rekursive berechnung der Potenz nur fuer
	// n >= 0 funktioniert, muss eine "Nachbearbeitung" des Ergebnisses
	// ausserhalb der Funktion erfolgen (siehe unten).
	printf("\nErgebnis der Berechnung:\n");
	if(n_inp < 0)
		printf("%.2f^%i = %.4f\n", x_inp, n_inp, 1/potenz(x_inp, -n_inp));
	else
		printf("%.2f^%i = %.4f\n", x_inp, n_inp, potenz(x_inp, n_inp));
}