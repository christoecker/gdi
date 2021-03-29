#include <stdio.h>

int main() {
	int iarr[] = { 2, 4, 6, 0, 1, 4, 1, 3, 5, 7 };
	double darr[] = { 3.311, 4.1, 5.0, 6.87, 9.99 };
	char str[] = "Hallo Welt";

	printf("Laenge des Arrays iarr: %i.\n", sizeof(iarr) / sizeof(iarr[0]));
	printf("Laenge des Arrays darr: %i.\n", sizeof(darr) / sizeof(darr[0]));
	printf("Laenge des Strings: %i.\n", sizeof(str) / sizeof(str[0]));

	/* Es istzu beachten, dass das letzte Zeichen eines Strings immer ein sog.
	   Stringende-Zeichen (\0) ist. Will man in einem String nur die Anzahl der
	   darstellbaren Zeichen ermitteln, muss man bei obiger Berechnung das 
	   Ergebnis um den Wert 1 dekrementieren.
	*/

	return 0;
}


