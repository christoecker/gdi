#include <stdio.h>
#include <stdlib.h>

int umlaut(int zeichen) {
	switch (zeichen) {
	case 228:
	case 196:
	case 246:
	case 214:
	case 252:
	case 220:	return 1;
	default: return 0;
	}
}

int main() {
	// Umstellung der Zeichenkodierung bewirkt, dass
	// auch deutsche Umlaute in der Konsole
	// dargestellt und im Programm verarbeitet werden 
	// koennen.
	system("chcp 1252"); system("cls");

	unsigned char z;
	printf("Zeichen eingeben:\n");
	z = getchar();

	printf("Das Zeichen %c ist %s Umlaut.\n", z, umlaut(z) ? "ein" : "kein");
}
