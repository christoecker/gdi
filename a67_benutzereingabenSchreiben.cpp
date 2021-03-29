#include <stdio.h>
#include <string.h>

int main() {
	FILE *file_ptr = NULL;		// Pointer auf ein FILE-Objekt 
														// (wird mit NULL initialisiert)
	char readIn[80];					// String (zur Speicherung der 
														// Eingabe ueber die Tastatur)

	// Datei schreibend oeffnen (wird erstellt, falls sie noch nicht 
	// existiert)
	file_ptr = fopen("eingabe.txt", "w");	

	if (file_ptr != NULL) {
		gets_s(readIn);							 // Liest einen String von der 
																 // Tastatur ein
		while (strlen(readIn) > 0) { // wiederhole solange, bis
																 // der ueber die Tastatur 
																 // eingelesene String die 
																 // Laenge 0 hat (leere Eingabe)
			fprintf(file_ptr, "%s\n", readIn);	// Liest das naechste 
																 // Zeichen der Datei ein
			gets_s(readIn);					   // Gibt das eingelesene 
																 // Zeichen in der Konsole aus
		}
		fprintf(file_ptr, "Eingabe abgeschlossen.\n");
		fclose(file_ptr);						 // schliesst die Datei
	}
	else {
		printf("Datei konnte nicht geoeffnet werden.\n");
	}
	return 0;
}