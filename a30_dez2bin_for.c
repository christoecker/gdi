#include <stdio.h>

int main() {
	int n, n_mem;
	int a0, a1, a2, a3, a4, a5, a6, a7;

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
	for (int i = 1; i <= 8; i++) {
		switch (i) {
		case 1: a0 = n % 2; n /= 2; break;
		case 2: a1 = n % 2; n /= 2; break;
		case 3: a2 = n % 2; n /= 2; break;
		case 4: a3 = n % 2; n /= 2; break;
		case 5: a4 = n % 2; n /= 2; break;
		case 6: a5 = n % 2; n /= 2; break;
		case 7: a6 = n % 2; n /= 2; break;
		case 8: a7 = n % 2; break;
		}
	}

	//Ausgabe
	printf("%i_(dez) = %i%i%i%i%i%i%i%i_(bin).\n", n_mem, a7, a6, a5, a4, a3, a2, a1, a0);
}