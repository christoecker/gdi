#include <stdio.h>
#include <stdlib.h>

// Funktion zum Aufbau des Menus
int menu(int mode) {
	// Items fuer die Nummerierung
	char item1 = '1', item2 = '2', item3 = '3';
	int userInp;		// Benutzereingabe	
	int falseInp = 0;	// Flag zur Ueberpruefung der Eingabe

	if (mode) {			// Veraenderung der Darstellung
		item1 = 'a';
		item2 = 'b';
		item3 = 'c';
	}
	system("cls");		// Ausgabe loeschen und Menu aufbauen
	printf("Auswahlmenu\n------------------------\n");
	printf("(%c) Menupunkt A\n", item1);
	printf("(%c) Menupunkt B\n", item2);
	printf("(%c) Menupunkt C\n", item3);

	// Warten auf Benutzereingabe + Ueberpruefung der Eingabe
	printf("\nBitte treffen Sie eine Auswahl:\n");
	do {
		scanf_s("%i", &userInp);
		if (userInp != 1 && userInp != 2 && userInp != 3) {
			// Wiederhole die Eingabe, bis die Eingabe gueltig ist.
			falseInp = 1;	// Flag gibt falsche Eingabe an
			printf("Ungueltige Eingabe. Bitte wiederholen:\n");
		}
		else {
			falseInp = 0;		// Eingabe ist korrekt
		}
	} while (falseInp);
	
	return userInp;
}


int main() {
	int auswahl;
	// Testausgabe
	auswahl = menu(1);	// Aufbau des Menus mit Angabe der Darstellung
	system("cls");
	printf("Die Auswahl ist %i.\n", auswahl);
}