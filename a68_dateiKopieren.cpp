#include <stdio.h>
#include <string.h>

void main() {
	FILE *file_read = NULL;			// FILE-Pointer (soll auf die Datei zeigen, die lesend geoeffnet wird)
	FILE *file_write = NULL;		// FILE-Pointer (soll auf die Kopie-Datei zeigen, die schreibend geoeffnet wird)
	char readIn[80] = "";
	char readFile[80] = "";			// String, in dem der Name derjenigen Datei zusammengefuegt wird, die lesend geoeffnet wird
									// Beispiel: Benutzereingabe ist "test" -> in readFile soll dann "test.txt" gespeichert werden.
	char copyFile[80] = "";			// String, in dem der Name derjenigen Datei zusammengefuegt wird, die die Kopie der ersten Datei ist
									// Beispiel: Benutzereingabe ist "test" -> in copyFile soll dann "test - Kopie.txt" gespeichert werden.
	char copyChar;					// Wird zum Kopieren der Datei benoetigt (siehe Zeile 32)

	printf("Bitte geben Sie den Namen der txt-Datei ein, die kopiert werden soll (ohne Dateiendung): \n");
	gets_s(readIn);							// Liest den vom Benutzer eingegebenen Dateinamen aus (ohne ".txt")

	strcat(readFile, readIn);				// Kopiert die eingabe in den String readFile
	strcat(readFile, ".txt");				// in readFile steht jetzt "<Eingabe>.txt" (vollstaendiger Dateiname)
	printf("Die Datei, die Sie kopieren moechten: %s\n", readFile);		// Testausgabe des Dateinamens

	file_read = fopen(readFile, "r");		// oeffnet die Datei, die zu kopieren ist
	// Test, ob die Datei geoeffnet werden konnte
	// Zunaechst wird jetzt der Dateiname "<Eingabe> - Kopie.txt" erstellt
	if (file_read != NULL) {	
		// Kopiert die Eingabe in den String copyFile
		strcpy(copyFile, readIn);	
		// Dateiname fuer die Kopie.
		strcat(copyFile, " - Kopie.txt");	 
		// Testausgabe des Dateinamens "<Eingabe> - Kopie.txt"
		printf("Name der Kopie: %s\n", copyFile);		

		file_write = fopen(copyFile, "w");	// Erstellt die Kopie-Datei 
		if (file_write != NULL) {			// Test, ob die Datei schreibend geoeffnet werden konnte (s.o.)
			// Durchlaufe die while-Schleife so lange, wie das Ende der Datei
			// aus der Inhalt gelesen wird, nicht erreicht ist.
			while (!feof(file_read)) {	
				// Speicher das naechste eingelesene Zeichen in copyChar
				copyChar = fgetc(file_read);		
				// Schreibt das eingelesene Zeichen in die Kopie-Datei
				fprintf(file_write, "%c", copyChar);	
			}
			fclose(file_read);				// Schliesse beiden Dateien
			fclose(file_write);
			printf("Die Datei %s.txt wurde kopiert.\n", readIn);
		}
	}

}