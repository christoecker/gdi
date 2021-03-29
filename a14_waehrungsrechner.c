#include <stdio.h>

// Programm "Waehrungsrechner"
int main() {
	float kurs, betragEUR;

	// Aufforderung zur Eingabe des Wechselkurses
	printf("Bitte geben Sie den Wechselkurs EUR -> $ an.\n");
	printf("Wert eines EUR in $: ");
	scanf_s("%f", &kurs);  
	/*
	Achtung: Moegliche Fehleingaben des Benutzers werden hier nicht
	abgefangen!
	*/

	// Aufforderung zur Eingabe des EUR-Betrags
	printf("Geben Sie den Geldbetrag in EUR ein: ");
	scanf_s("%f", &betragEUR);

	// Ausgabe Wert in $
	printf("%.2f EUR entsprechen aktuell %.2f $.\n", betragEUR, kurs*betragEUR);
}