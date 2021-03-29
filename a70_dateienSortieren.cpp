/* HINWEIS: Fuer diese Aufgabe muessen Sie sich zunaechst zwei Ordner "Dateien_AtoL" und "Dateien_MtoZ" in dem
Verzeichnis anlegen, in dem Ihr Projekt liegt.
*/

#include <stdio.h>
#include <string.h>

void main() {
	FILE *file_ptr = NULL;				// Pointer auf FILE-Objekt (Initialisiert mit NULL)
	char readIn[80];				// String zum Speichern des eingegebenen Dateinamens
	char move2AtoL[15] = "Dateien_AtoL\\";		// String mit Verzeichnisname fuer Dateien A - L
	char move2MtoZ[15] = "Dateien_MtoZ\\";		// String mit Verzeichnisname fuer Dateien M - Z

	printf("Bitte geben Sie einen Dateinamen ein:\n");
	gets_s(readIn);					// Erste Benutzereingabe einlesen

	while (strlen(readIn) > 0) {			// Die Benutzereingabe wird analysiert, ob die Laenger > 0 ist, andernfalls wird die Schleife nicht durchlaufen 
		if (readIn[0] >= 65 && readIn[0] <= 76 || readIn[0] >= 97 && readIn[0] <= 108) {	// Wenn das erste Zeichen des eingegebenen Strings einem ASCII-Code zwischen 65 (A) und 76 (L) oder zwischen 97 (a) und 108 (l) entspricht, wird die Datei in den Ordner "Dateien_AtoL" verschoben das erste Zeichen ist ein Buchstabe A-L
			file_ptr = fopen(readIn, "w");	// Zunaechst wird die Datei im aktuellen Verzeichnis erstellt...
			fclose(file_ptr);		// ... dann geschlossen ...
			char newFileName[30] = "";
			strcat(newFileName, move2AtoL);	// Kopiert den Verzeichnisnamen in den String newFileName und ...
			strcat(newFileName, readIn);	// ... fuegt den Dateinamen an das Verzeichnis an	
			rename(readIn, newFileName);	// ... und schliesslich mit der Funktion rename in das neue Verzeichnis verschoben
		}
		else if (readIn[0] >= 77 && readIn[0] <= 90 || readIn[0] >= 109 && readIn[0] <= 122) {   // Wenn das erste Zeichen des eingegebenen Strings einem ASCII-Code zwischen 77 (M) und 90 (Z) oder zwischen 109 (m) und 122 (z) entspricht, wird die Datei in den Ordner "Dateien_MtoZ" verschoben
			file_ptr = fopen(readIn, "w");	// siehe oben...
			fclose(file_ptr);
			char newFileName[30] = "";
			strcat(newFileName, move2MtoZ);
			strcat(newFileName, readIn);
			rename(readIn, newFileName);
		}
		else {
			// ungueltiger Dateiname (ungueltig nur im Sinne der Aufgabenstellung)
			printf("Ungueltiger Dateiname.\n");
		}
		printf("Bitte geben Sie einen Dateinamen ein:\n"); // ein neuer Dateiname soll eingegeben werden
		gets_s(readIn);
	}

}