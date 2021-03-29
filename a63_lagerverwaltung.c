#include <stdio.h>
#include <stdlib.h>

#include "a63_lager.h"

int main() {
	VER;		// Ausgabe der Version
	// Lagerplaetze anlegen
	int lager[SIZE] = { 0 };

	// Auf den Plaetzen 3, 5, 8 und 14 werden Waren eingelagert
	einlagern(lager, 3);
	einlagern(lager, 5);
	einlagern(lager, 8);
	einlagern(lager, 14);
	zeigeLager(lager);

	// Aus Platz 8 und 14 wird ausgelagert
	auslagern(lager, 8);
	auslagern(lager, 14);
	zeigeLager(lager);

	// Erneutes Auslagern von Platz 8 fuehrt zu Fehlermeldung
	// in der Pro-Version, da Platz 8 leer ist
	auslagern(lager, 8);
	// Versuch des EInlagern in Platz 3 fuehrt zu Fehlermeldung
	// in der Pro-Version, da Platz 3 bereits belegt ist
	einlagern(lager, 3);

	return 0;
}