#include <stdio.h>

// Funktion zum Sortieren eines Arrays
void bubbleSort(int A[], int len) {
	for (int i = 1; i < len; i++) {
		for (int j = 0; j < len - i; j++) {
			if (A[j] > A[j + 1]) {
				//Vertausche die Elemente
				int temp = A[j];
				A[j] = A[j + 1];
				A[j + 1] = temp;
			}
		}
	}
}

// Funktion fuer die Ausgabe des Arrays
void printArr(int A[], int len) {
	for (int i = 0; i < len-1; i++) {
		printf("%i, ", A[i]);
	}
	printf("%i\n", A[len - 1]);
}

int main() {
	// Testdaten
	int myArr[10] = { 0, 4, 1, 9, 8, 5, 6, 2, 7, 3 };

	// Testausgabe
	printf("Das unsortierte Array:\n");
	printArr(myArr, 10);
	bubbleSort(myArr, 10);
	printf("Das sortierte Array:\n");
	printArr(myArr, 10);
	return 0;
}