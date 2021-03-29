#include <stdio.h>

int checkEq(int arr1[], int arr2[], int len1, int len2) {
	if (len1 != len2) {
		return -2;			// Rueckgabe bei unterschiedlicher Laenge
	}
	for (int i = 0; i < len1; i++) {
		if (arr1[i] != arr2[i])
			return i;		// Rueckgabe der Stelle, an der sich beide
							// Arrays unterscheiden
	}
	return -1;				// Ruckgabe bei Gleichheit
}

int main() {
	// Definition von Testfaellen
	int a[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int b[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int c[10] = { 1, 2, 3, 4, 6, 5, 7, 8, 9, 10 };
	int d[11] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 };
	int lenA = sizeof(a) / sizeof(a[0]);
	int lenB = sizeof(b) / sizeof(b[0]);
	int lenC = sizeof(c) / sizeof(c[0]);
	int lenD = sizeof(d) / sizeof(d[0]);

	printf("Vergleich zweier Arrays:\n");
	switch (int i = checkEq(a, d, lenA, lenD)) {
	case -2: printf("Die Arrays haben unterschiedliche Laenge.\n"); break;
	case -1: printf("Beide Arrays sind gleich.\n"); break;
	default: printf("Die Arrays unterschieden sich in der %i. Stelle.\n", i);
	}
	return 0;
}


