#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definition einer Struktur fuer
// einen Eintrag auf der Einkaufsliste
struct eintrag {
	char produkt[20];
	int anzahl;
	eintrag* nextItem;
};
typedef struct eintrag;

// Zeiger auf das erste Element erstellen
eintrag* anfang = NULL;

// Funktion zum Hinzufuegen eines Elements
// zur Einkaufsliste
void ergaenzen() {
	char prod[20]; 
	int stk;
	printf("Bitte geben Sie die Produktbezeichnung und die Anzahl ein:\n");
	rewind(stdin); gets_s(prod);
	rewind(stdin); scanf_s("%i", &stk);
	if (anfang == NULL) {
		// Die Einkaufsliste ist noch leer
		anfang = (eintrag*)malloc(sizeof(eintrag));
		if (anfang == NULL) {
			// Fehler: Kein Speicher zugewiesen
			printf("Ein Fehler ist aufgetrten...\n");
			return;
		}
		strcpy(anfang->produkt, prod);
		anfang->anzahl = stk;
		anfang->nextItem = NULL;
	}
	else {
		eintrag* letztesElement = anfang;
		// Suche das letzte Element der, angefangen bei 'anfang'
		while (letztesElement->nextItem != NULL) {
			letztesElement = letztesElement->nextItem;
		}
		eintrag* neuesElement = (eintrag*)malloc(sizeof(eintrag));
		if (neuesElement == NULL) {
			// Fehler: Kein Speicher zugewiesen
			printf("Ein Fehler ist aufgetreten...\n");
			return;
		}
		strcpy(neuesElement->produkt, prod);
		neuesElement->anzahl = stk;
		neuesElement->nextItem = NULL;
		letztesElement->nextItem = neuesElement;
	}
}

// Funktion zur Ausgabe der Einkaufsliste
void zeigeListe() {
	if (anfang == NULL) {
		printf("Die Einkaufsliste ist noch leer.\n");
	}
	else {
		eintrag* anzeigeElement = anfang;
		int nr = 1;
		printf("Nr. | %19s | Anzahl\n", "Produkt"); // Kopf der Tabelle
		while (anzeigeElement != NULL) {
			// Navigiere durch die Liste
			printf("%3i | %19s | %3i\n", nr++, anzeigeElement->produkt, anzeigeElement->anzahl);
			anzeigeElement = anzeigeElement->nextItem;
		}
		printf("\n");
	}
}

void aendern() {
	int nr;
	if (anfang == NULL) {
		printf("Den Eintrag mit der Nr. %i gibt es in der Liste nicht.\n", nr);
	}
	else {
		printf("Bitte geben Sie die Nummer des Eintrags an, der geaendert werden soll:\n");
		rewind(stdin); scanf_s("%i", &nr);
		eintrag* anzeigeElement = anfang;
		int i = 1;
		while (anzeigeElement != NULL && i <= nr) {
			if (i == nr) {
				// Eintrag gefunden
				printf("Nr. | %19s | Anzahl\n", "Produkt"); // Kopf der Tabelle
				printf("%3i | %19s | %3i\n", i, anzeigeElement->produkt, anzeigeElement->anzahl);
				printf("Bitte geben Sie die neue Produktbezeichnung und die gewuenscht Anzahl ein:\n");
				char prodBfr[20];
				rewind(stdin); gets_s(prodBfr);
				strcpy(anzeigeElement->produkt, prodBfr);
				rewind(stdin); scanf_s("%i", &(anzeigeElement->anzahl));
				return;
			}
			i++;
			anzeigeElement = anzeigeElement->nextItem;
		}
		// Wird nur ausgefuehrt, wenn while-Schleife verlassen wird
		printf("Den Eintrag mit der Nr. %i gibt es in der Liste nicht.\n", nr);
	}
}

void loeschen() {
	int nr;
	
	if (anfang == NULL) {
		printf("Den Eintrag mit der Nr. %i gibt es in der Liste nicht.\n", nr);
	}
	else {
		printf("Bitte geben Sie die Nummer des Eintrags an, der geloescht werden soll:\n");
		scanf_s("%i", &nr);
		eintrag* loeschenElement = anfang;
		eintrag* prev = NULL;	// Das Element in der Liste VOR dem zu loeschenden
		int i = 1;
		while (loeschenElement != NULL && i <= nr) {
			if (i == nr) {
				// Eintrag gefunden
				printf("Nr. | %19s | Anzahl\n", "Produkt"); // Kopf der Tabelle
				printf("%3i | %19s | %3i\n", i, loeschenElement->produkt, loeschenElement->anzahl);
				printf("Soll dieser Eintrag wirklich geloescht werden? (j/n)\n");
				rewind(stdin);
				char confirmation = getc(stdin); 
				if (confirmation == 'j') {
					if (prev != NULL) {
						prev->nextItem = loeschenElement->nextItem;
					}
					else {
						anfang = NULL;
					}
					free(loeschenElement);	// loeschenElement wird geloescht
				}
				return;
			}
			prev = loeschenElement;
			loeschenElement = loeschenElement->nextItem;
			i++;
		}
		// Wird nur ausgefuehrt, wenn while-Schleife verlassen wird
		printf("Den Eintrag mit der Nr. %i gibt es in der Liste nicht.\n", nr);
	}
}

int menu() {
	int sel;
	printf("Bitte treffen Sie eine Auswahl:\n");
	printf("(1) Eintrag ergaenzen\n");
	printf("(2) Eintrag aendern\n");
	printf("(3) Eintrag loeschen\n");
	printf("(4) Liste anzeigen\n");
	printf("(0) Programm beenden\n");
	scanf_s("%i", &sel);
	return sel;
}

int main() {
	char prod[20];
	int cont = 1;

	do {
		switch (menu()) {
		case 0: cont = 0; break;
		case 1: system("cls"); ergaenzen(); break;
		case 2: system("cls"); aendern(); break;
		case 3: system("cls"); loeschen(); break;
		case 4: system("cls"); zeigeListe(); break;
		default:
			system("cls");
			printf("Falsche Eingabe. Bitte wiederholen...\n");
		}
	} while (cont);
	return 0;
}