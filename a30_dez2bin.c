#include <stdio.h>

int main() {
	int n, n_mem, i = 0;
	int b0 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0, b5 = 0, b6 = 0, b7 = 0;

	// Die Benutzereingabe wird solange verlangt, bis der vorgegebene
	// Wertebereich eingehalten wird.
	do {
		printf("Bitte eine Dezimalzahl (0 .. 255) eingeben: ");
		scanf_s("%i", &n);
	} while (n < 0 || n > 255);

	n_mem = n;	// n wird gespeichert, da es im Folgenden veraendert wird.
				/*
				In dieser Loesung muss jede Stelle der Binaerzahl gespeichert
				werden, da die Ziffern der Binaerzahl vom LSB bis zum MSB
				berechnet werden und spaeter in umgekehrter Reihenfolge
				ausgegeben werden sollen. Mit dem gegenwaertigen Wissen
				muessen dafuer 8 Variablen angelegt werden. Dieses Vorgehen
				ist selbstverstaendlich umstaendlich und C bietet fuer solche
				Probleme andere und effizientere Moeglichkeiten, die in den
				folgenden Terminen besprochen werden.
				*/
	while(n>0){
		i++;
		switch (i) {
		case 1: b0 = n % 2; n /= 2; break;
		case 2: b1 = n % 2; n /= 2; break;
		case 3: b2 = n % 2; n /= 2; break;
		case 4: b3 = n % 2; n /= 2; break;
		case 5: b4 = n % 2; n /= 2; break;
		case 6: b5 = n % 2; n /= 2; break;
		case 7: b6 = n % 2; n /= 2; break;
		case 8: b7 = n % 2; n /= 2; break;
		}
	}

	//Ausgabe
	printf("%i_(dez) = %i%i%i%i%i%i%i%i_(bin).\n", n_mem, b7, b6, b5, b4, b3, b2, b1, b0);

	// Hier wird der Vorteil der Implementierung mit einer while-Schleife
	// gegenueber einer for-Schleife dokumentiert. Bei verwendung einer
	// for-Schleife werden immer 8 Durchlaeufe benoetigt, wohingegen
	// die Anzahl der Durchlaeufe mit einer while-Schleife von der
	// Eingabe abhaengen.
	printf("\nDie Berechnung erfolgte in %i Durchlaeufen.\n", i);
}
