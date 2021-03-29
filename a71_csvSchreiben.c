#include <stdio.h>

int main() {
	FILE* fcsv = NULL;
	fcsv = fopen("test.csv", "a+");
	char sel;
	int valueInp;
	char commentInp[100];
	int cnt = 1;

	if (fcsv != NULL) {
		// Prüfen ob in der Datei schon Inhalt ist...
		// fseek setzt den Lese-/Schreibcursor in der Datei.
		// Hier wird der Cursor auf das Ende der Datei gesetzt
		fseek(fcsv, 0, SEEK_END);
		// ftell gibt die aktuelle Position des Lese/Schreibcursors
		// zurück
		int pos = ftell(fcsv);
		if (pos == 0) {	// Datei ist leer, wenn akt. Pos 0 ist
			//Schreibe "Tabellenüberschriften"
			fprintf(fcsv, "Nr;Wert;Kommentar\n");
		}

		while (1) {
			system("cls");
			printf("Moechten Sie eine Zeile in der Datei ergaenzen? (j/n)\n");
			sel = getchar();
			if (sel != 'j') {
				break;
			}
			else {
				printf("Bitte Wert und Kommentar (optional) eingeben.\n");
				scanf("%i", &valueInp); rewind(stdin);
				gets(commentInp);
				fprintf(fcsv, "%i;%i;%s\n", cnt++, valueInp, commentInp);
			}
		}
		
		// Datei wird erneut ausgegeben.
		printf("\nAusgabe der Datei:\n");
		// Lese-Schreibcursor wird dafür auf Anfang der Datei
		// gesetzt
		fseek(fcsv, 0, SEEK_SET);
		char readIn;
		while (!feof(fcsv)) {
			readIn = fgetc(fcsv);
			putchar(readIn);
		}
		
		fclose(fcsv);		// Datei schließen
	}
	return 0;
}