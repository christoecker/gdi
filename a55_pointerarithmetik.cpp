#include <stdio.h>
#define N 8

/*
	Funktion setzt jedes p-te Element
	des Arrays M auf 0
*/
void clearE(int* M, int p) {
	if (p > 0) {
		int mrk = p-1;
		while (mrk < N*N) {	// max. N*N Elemente
			*(M + mrk) = 0;
			mrk += p;		// Pointer inkrementieren
		}
	}
}

int main() {
	int matrix[N][N];

	// Array initialisieren
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			matrix[i][j] = (1+i*N)+j;
		}
	}

	// Achtung: hier muss explizit die 
	// Adresse des ersten Elements uebergeben werden.
	// clearE(matrix, 2) wuerde nicht funktionieren, 
	// da es nicht zur Definition der Funktion 
	// clearE(int* M, int p) passt.
	clearE(&matrix[0][0], 2);

	// Ausgabe des Arrays
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			printf("%4i", matrix[i][j]);
		}
		printf("\n");
	}
}