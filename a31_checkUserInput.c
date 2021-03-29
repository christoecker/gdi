#include <stdio.h>

int main() {
	int userInp, repeatFlag = 0;
	// Die Variable repeatFlag wird benoetigt, falls der Benutzer eine falsche Eingabe macht.

	// Aufforderung zur Benutzereingabe
	printf("Bitte geben Sie eine negative ganze Zahl ein: ");
	do {
		// Die if-Anweisung wird im ersten Durchlauf nicht ausgefuehrt, da repeatFlag mit 0 
		// initialisiert wurde.
		if (repeatFlag) {
			printf("Ihre Eingabe war nicht korrekt. Bitte geben Sie eine negative ganze Zahl ein: ");
		}
		scanf_s("%i", &userInp);	// Benutzereingabe
		repeatFlag = 1;				// repeatFlag wird auf 1 gesetzt, damit im naechsten Durchlauf ggf.
									// die obige if-Anweisung ausgefuehrt wird.
	} while (userInp >= 0);			// Pruefen der Eingabe

	printf("Sie haben die Zahl %i eingegeben.\n", userInp);
}