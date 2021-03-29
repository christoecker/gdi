#include <stdio.h>

// Funktion berechnet rekursiv Kapitalwert
double kapitalwert(double k, double z, int t) {
	if (t == 0)
		return k;		// Abbruch der Rekursion
	else
		return kapitalwert(k, z, t-1)*(1+z); // Rekursion
}

int main() {
	double k = 0.0, z = 0.0;	// Kapital k, Zins z
	int t = 0;					// Jahre t

	// Testausgabe
	printf("Bitte Kapital in EUR, Zinssatz in %% und Jahre eingeben:\n");
	scanf_s("%lf%lf%i", &k, &z, &t);
	printf("Der Kapitalwert nach %i Jahren betraegt %.2f EUR.\n", t, kapitalwert(k, z, t));
}