#include <stdio.h>

// Definition des Makros steuert die Sprache
// #define LANG_EN

// Einbinden der eigenen Header-Datei
#include "a64_circle.h"

int main() {
	float inpR;		// speichert Benutzereingabe

	// Textausgabe anhaengig von Sprachwahl
	printf(MSG_INP);
	scanf_s("%f", &inpR);

	// Textausgabe anhaengig von Sprachwahl
	//Flaecheninhalt wird in Makro berechnet
	printf(MSG_OUT, inpR, getA(inpR));
	
	return 0;
}