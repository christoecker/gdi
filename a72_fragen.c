#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Definieren die maximale Zeilenlänge einer Frage oder Antwort
#define LEN 100
// Maximale Anzahl Fragen/Antworten
#define NUMQA 20

// Da Frage und Antwort immer zusammen gespeichert werden,
// macht es Sinn dieses Paar in einer Struktur abzulegen
typedef struct{
	char question[LEN];
	char answer[LEN];
}QandA;	// Der neue Datentyp heißt QandA

// Funktion wird benötigt, um den Zeilenumbruch in den
// eingelesenen Zeilen aus der Datei zu entfernen
void replLinebreak(char* str) {
	size_t p = strlen(str);
	// Vorletzte Zeichen mit '\0' überschreiben
	str[p - 1] = '\0';
}

int main() {
	FILE* pFragen;
	char readBfr[LEN];
	QandA katalog[NUMQA];

	// ----- Einlesen der Fragen und Antworten aus der Datei
	// 1. Schritt: Öffnen der Datei Fragen.txt
	pFragen = fopen("fragen.txt", "r");		// Nur lesend öffnen

	if (pFragen != NULL) {		// das Öffnen war also erfolgreich
		int i = 0;
		char* fgets_Output;
		while (1) {
			// 2.1 Frage einlesen
			fgets_Output = fgets(readBfr, LEN, pFragen);
			if (fgets_Output == NULL)
				break;
			replLinebreak(readBfr);
			strcpy(katalog[i].question, readBfr);
			// 2.2 Antwort einlesen
			fgets_Output = fgets(readBfr, LEN, pFragen);
			if (fgets_Output == NULL)
				break;
			replLinebreak(readBfr);
			strcpy(katalog[i++].answer, readBfr);

			if (i == NUMQA)
				break;		// Es können max. NUMQA Fragen/Antworten eingelesen werden
		}
		printf("INFO: Es wurden %i Fragen/Antworten eingelesen.\n\n", i);
		// 3. Schritt: Datei wurde eingelesen und kann geschlossen werden.
		fclose(pFragen);	

		// 4. Schritt Fragen und Antworten ausgeben
		printf("Ausgabe der Fragen/Antworten:\n\n");
		for (int k = 0; k < i; k++) {
			printf("-- %i. Frage und Antwort --\n", k+1);
			printf("Q: %s\n", katalog[k].question);
			printf("A: %s\n\n", katalog[k].answer);
		}
	}
	else {
		printf("Die Datei konnte leider nicht geöffnet werden.");
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}