#include <stdio.h>

int main() {
	char fileName[80];
	int charCnt = 0;
	printf("Bitte geben Sie den vollstaendigen Dateinamen (ggf. mit Pfad) ein:\n");
	gets_s(fileName);	// Dateinamen einlesen
	// Testausgabe des Dateinamens
	printf("Sie moechten die Datei %s oeffnen...\n", fileName);

	FILE *filePtr = fopen(fileName, "r");	// Oeffnen der Datei
	if (filePtr != NULL) {	// Oeffnen war erfolgreich
		printf("Die Datei existiert:\n");
		// Ausgabe der ersten 100 Zeichen der Datei
		while (!feof(filePtr) && charCnt < 100) {
			putchar(fgetc(filePtr));
			charCnt++;
		}
		if (charCnt == 100)
			printf("...\n");	// Andeuten, dass die Datei laenger ist
	}
	else {
		// Die Datei existiert nicht (oder kann nicht geoeffnet werden)
		printf("Sorry... Die Datei existiert leider nicht.\n");
	}
	return 0;
}