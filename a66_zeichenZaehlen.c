#include <stdio.h>

int main() {
	FILE *file_ptr = NULL;	// Pointer auf ein FILE-Objekt 
													// deklarieren und mit NULL
													// initialisieren. Mit dieser
													// Initialisierung hat der 
													// Pointer einen definierten Wert.
	char readIn;						// Variable wird zur Ausgabe der
													// Zeichen aus der eingelesenen
													// Datei benoetigt
	int cntALL = 0;		// Zaehlvariable fuer alle Zeichen
	char countChar;		// Speichert das Zeichen, dessen Haeufigkeit 
										// im Text gezaehlt werden soll
	int cntS = 0;		  // Zaehlvariable fuer ein spezielles 		
										// Zeichen

	printf("Welches Zeichen soll gezaehlt werden?\n");
	scanf_s("%c", &countChar);

	file_ptr = fopen("test.abc", "r");	// Datei lesend oeffnen
	if (file_ptr != NULL) {		// Wenn das Oeffnen der Datei 
													  // erfolgreich war, hat der 
														// Pointer NICHT den Wert NULL
		printf("\n Textausgabe: \n\n");
		while (!feof(file_ptr)) {	// wiederhole solange, wie NICHT 
															// das Dateiende erreicht ist
			readIn = fgetc(file_ptr); // Liest das naechste Zeichen 
																// der Datei ein
			putchar(readIn);	  		// Gibt das eingelesene Zeichen 
															// in der Konsole aus

			cntALL++;
			if (readIn == countChar) {
				cntS++;
			}
		}
		printf("\n\nDer Text hat insgesamt %i Zeichen.\n", cntALL);
		printf("Das Zeichen '%c' ist %i Mal vorgekommen.\n\n", countChar, cntS);
		fclose(file_ptr);				// Schliesst die Datei
	}
	else {
		printf("Datei konnte nicht geoeffnet werden.\n");
	}
	return 0;
}