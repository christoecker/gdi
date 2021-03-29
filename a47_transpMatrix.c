#include <stdio.h>

#define zeilen 3
#define spalten 4

/*
Bei der hier verwendeten Funktionsdefinition wird die
Groesse des Arrays direkt angegeben. Damit muss das uebergebene
Array genau die festgelegte Groesse haben.
*/
void transpose(int M[zeilen][spalten], int T[spalten][zeilen]) {
	for (int i = 0; i < zeilen; i++) {
		for (int j = 0; j < spalten; j++) {
			T[j][i] = M[i][j];
		}
	}
}

int main() {
	int M[zeilen][spalten];
	int T[spalten][zeilen];

	// Initialisierung der Matrix in einer geschaltelten for-Schleife
	for (int i = 0; i < zeilen; i++) {
		for (int j = 0; j < spalten; j++) {
			M[i][j] = i * (spalten)+j + 1;
		}
	}
	// Testausgabe
	printf("Die eingegebene Matrix:\n");
	for (int i = 0; i < zeilen; i++) {
		for (int j = 0; j < spalten; j++) {
			printf("%3i%", M[i][j]);
		}
		printf("\n");
	}

	// Transponieren der Matrix
	transpose(M, T);
	printf("Die transponierte Matrix:\n");
	for (int i = 0; i < spalten; i++) {
		for (int j = 0; j < zeilen; j++) {
			printf("%3i%", T[i][j]);
		}
		printf("\n");
	}
}