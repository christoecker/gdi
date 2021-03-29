#include <stdio.h>

void myStrCpy(char* strIn, char* cpy) {
	int i = 0;
	do {
		*(cpy + i) = *(strIn + i);
		i++;
	} while (*(strIn + i) != '\0');
}

int main() {
	char str1[100] = "Praxisintegriertes Verbundstudium";
	char str2[100] = "";

	printf("Vor Aufruf von myStrCpy():\n");
	printf("String 1: %s\n", str1);
	printf("String 2: %s\n", str2);

	myStrCpy(str1, str2);

	printf("\nNach Aufruf von myStrCpy():\n");
	printf("String 1: %s\n", str1);
	printf("String 2: %s\n", str2);
	return 0;
}