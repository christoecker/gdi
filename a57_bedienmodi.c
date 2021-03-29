#include <stdio.h>
#include <stdlib.h> // fuer Loeschen der Ausgabe

// Definition der Bedienmodi
enum modus {frei, vor_Ort, manuell, remote};

int main() {
	modus bedienung = frei;		// Deklaration und Initialisierung der Variablen
					// die den aktuellen Bedienmodus anzeigt
	int wahl;			// Fuer die Benutzereingabe

	do {
		printf("Der aktuelle Bedienmodus ist ");
		// Abfrage des aktuellen Bedienmodus in einem switch-case
		switch (bedienung) {	
		case frei: printf("Frei.\n");
			printf("Bitte waehlen Sie einen Bedienmodus:\n");
			printf("(1) Vor Ort\n(2) Manuell\n(3) Remote\n");

			scanf_s("%i", &wahl); rewind(stdin);		// Benutzereingabe
			switch (wahl) {
				// Bei gueltiger Eingabe wird bedienung die Eingabe wahl zugeordnet
				// Achtung: Die Variable wahl muss hier in den Datentyp modus gecastet werden.
			case 1: case 2: case 3: bedienung = (modus)wahl;
			}
			break;
		case vor_Ort: printf("Vor Ort.\n");
			printf("Wollen Sie den Bedienmodus freigeben?\n");
			printf("(0) Frei\n(1) im Modus Vor Ort bleiben\n");
			
			scanf_s("%i", &wahl); rewind(stdin); 
			switch (wahl) {
			case 0: case 1: bedienung = (modus)wahl;
			}
			break;
		case manuell: printf("Manuell.\n");
			printf("Wollen Sie den Bedienmodus freigeben?\n");
			printf("(0) Frei\n(2) im Modus Manuell bleiben\n");
			
			scanf_s("%i", &wahl); rewind(stdin); 
			switch (wahl) {
			case 0: case 2: bedienung = (modus)wahl;
			}
			break;
		case remote: printf("Remote.\n");
			printf("Wollen Sie den Bedienmodus freigeben?\n");
			printf("(0) Frei\n(3) im Modus Remotet bleiben\n");
			
			scanf_s("%i", &wahl); rewind(stdin); 
			switch (wahl) {
			case 0: case 3: bedienung = (modus)wahl;
			}
			break;
		}
		system("cls");		// Loesche Ausgabe
		// Bei jeder anderen EIngabe als 0, 1, 2 oder 3 wird das
		// Programm beendet.
	} while (wahl == 0 || wahl == 1 || wahl == 2 || wahl == 3);
}