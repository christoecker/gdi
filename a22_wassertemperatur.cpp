#include <stdio.h>

int main() {
	float tempInp;

	// Benutzereingabe abfragen
	printf("Bitte geben Sie eine Temperatur ein:\n");
	scanf_s("%f", &tempInp);

	// Variante 1: if-else-Anweisungen
	if (tempInp > 0 && tempInp < 100)
		printf("Das Wasser ist fluessig.\n");
	else if (tempInp <= 0)
		printf("Das Wasser ist gefroren.\n");
	else
		printf("Das Wasser ist gasfoermig.\n");

	// Variante 2: switch-case-Anweisung
	/*
		Wenn es darum geht, Wertebereiche zu ueberpruefen, 
		eignet sich die switch-case-Anweisung nicht. In 
		dem hier behandelten Fall muesste jede moegliche
		Eingabe im case-Block behandelt werden. Zudem sind
		als Argument im switch-statement nur int-Werte erlaubt.
		Eine moegliche Loesung waere, in einer if-else-
		Anweisung die Temperaturbereiche zu indentifizieren
		und dann die Ausgabe im sitch-case-Block zu machen.
		Dieser Weg hat aber gegenueber Variante 1 keine Vorteile.
	*/
	int switch_ctrl = -1;

	printf("\n");
	if (tempInp > 0 && tempInp < 100)
		switch_ctrl = 0;
	else if (tempInp <= 0)
		switch_ctrl = 1;

	switch (switch_ctrl) {
	case 0: printf("Das Wasser ist fluessig.\n"); break;
	case 1: printf("Das Wasser ist gefroren.\n"); break;
	default: printf("Das Wasser ist gasfoermig.\n");
	}
}