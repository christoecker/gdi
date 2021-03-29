#include <stdio.h>
#include <stdlib.h>

int main() {
	int aLen = 3, upscale = 3, i = 0;
	int *arrPtr = (int*)malloc(aLen * sizeof(int));
	char userInp = 'j';

	do{
		printf("Bitte Zahl eingeben:\n");
		rewind(stdin);  scanf_s("%i", &arrPtr[i++]);
		if (i == aLen) {
			printf("Wollen Sie den Speicher erweitern?\n"); 
			rewind(stdin); scanf_s("%c", &userInp);
			if (userInp == 'j') {
				aLen += upscale;
				// Reservierten Speicher erweitern
				arrPtr = (int*)realloc(arrPtr, aLen*sizeof(int));
			}
		}
	} while (userInp == 'j');

	// Ausgabe, falls kein neuer Speicher benoetigt wird.
	printf("Ihre Eingaben:\n");
	for (int i = 0; i < aLen; i++) {
		printf("%i ", arrPtr[i]);
	}
	printf("\n");

	free(arrPtr);	// Reservierten Speicher wieder freigeben
	return 0;
}