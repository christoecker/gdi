#include <stdio.h>
#include <stdlib.h>

// Definition eines Aufzaehlungstyps, hier BOOL
typedef enum {FALSCH, FALSE=0, WAHR, TRUE=1} BOOL;
typedef enum {phaseRot, phaseGelb, phaseGruen, phaseRotGelb} state;

// Funktion zur Ausgabe der Ampellichter
void showAmpel(BOOL ampel[3]) {
	printf("Rot   = %i\n", ampel[0]);
	printf("Gelb  = %i\n", ampel[1]);
	printf("Gruen = %i\n", ampel[2]);
}

int main() {
	BOOL Ampel[3];	// Rot, gelb, gruen
	state Strg = phaseRot;
	char inp;

	// Initialisierung Ampel
	Ampel[0] = TRUE;
	Ampel[1] = FALSE;
	Ampel[2] = FALSE;

	showAmpel(Ampel);

	// Steuerungsalgorithmus
	do {
		switch (Strg) {
		case phaseRot:
			Ampel[0] = TRUE;
			Ampel[1] = FALSE;
			Ampel[2] = FALSE;
			system("cls");			// Loesche Bildschirm
			showAmpel(Ampel);		// Ausgabe der Ampelbeleuchtung
			inp = getchar();		// Warten auf Eingabe
			rewind(stdin);			// Loesche Eingabepuffer
			if (inp == ' ')
				Strg = phaseRotGelb;  // Definition des naechsten Zustands
			break;
		case phaseGelb:
			Ampel[0] = FALSE;
			Ampel[1] = TRUE;
			Ampel[2] = FALSE;
			system("cls");			// Loesche Bildschirm
			showAmpel(Ampel);		// Ausgabe der Ampelbeleuchtung
			inp = getchar();		// Warten auf Eingabe
			rewind(stdin);			// Loesche Eingabepuffer
			if (inp == ' ')
				Strg = phaseRot;  // Definition des naechsten Zustands
			break;
		case phaseGruen:
			Ampel[0] = FALSE;
			Ampel[1] = FALSE;
			Ampel[2] = TRUE;
			system("cls");			// Loesche Bildschirm
			showAmpel(Ampel);		// Ausgabe der Ampelbeleuchtung
			inp = getchar();		// Warten auf Eingabe
			rewind(stdin);			// Loesche Eingabepuffer
			if (inp == ' ')
				Strg = phaseGelb;  // Definition des naechsten Zustands
			break;
		case phaseRotGelb:
			Ampel[0] = TRUE;
			Ampel[1] = TRUE;
			Ampel[2] = FALSE;
			system("cls");			// Loesche Bildschirm
			showAmpel(Ampel);		// Ausgabe der Ampelbeleuchtung
			inp = getchar();		// Warten auf Eingabe
			rewind(stdin);			// Loesche Eingabepuffer
			if (inp == ' ')
				Strg = phaseGruen;  // Definition des naechsten Zustands
			break;
		}
	} while (inp == ' ');

	return 0;
}