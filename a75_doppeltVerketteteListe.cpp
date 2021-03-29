#include <stdio.h>
#include <stdlib.h>

struct ITEM {
	int number;		// int-Wert
	ITEM* pre;		// Zeiger auf Vorgaenger
	ITEM* post;		// Zeiger auf Nachfolger
};
typedef struct ITEM;

ITEM* anfang = NULL;	//Anfang der Liste

// Funktion zum Hinzufuegen eines Elements
void addItem(int num) {
	if (anfang == NULL) {
		// Liste noch leer
		anfang = (ITEM*)malloc(sizeof(ITEM));
		if (anfang == NULL) {	// Fehler
			printf("Es konnte kein Speicher zugewiesen werden.\n");
			return;
		}
		anfang->number = num;
		anfang->pre = NULL;		// Anfang hat keinen Vorgaenger...
		anfang->post = NULL;	// und (noch) keinen Nachfolger.
	}
	else {
		ITEM* lastItem = anfang;
		while (lastItem->post != NULL) {	// Navigiere zum Ende der Liste
			lastItem = lastItem->post;
		}
		ITEM* newItem = (ITEM*)malloc(sizeof(ITEM));
		// Neues Element mit Werten fuellen
		newItem->number = num;
		newItem->post = NULL; // Neues letztes ELement hat keinen Nachfolger
		newItem->pre = lastItem;	// Vorgaenger ist das vorherige letzte Element
		lastItem->post = newItem; // und dessen Nachfolger ist das neue Element
	}
}

// Funktion zum Anzeigen der Liste (Ausgabe forwaerts)
void showList_fwd() {
	if (anfang == NULL) {
		printf("Die Liste ist noch leer.\n");
		return;
	}

	if (anfang->post == NULL) {	// Es gibt nur ein Element
		printf("(ANFANG) %i (ENDE)\n", anfang->number);
		return;
	}

	ITEM* showItem = anfang;
	while (showItem != NULL) {
		if (showItem->post == NULL)
			printf("%i (ENDE)\n", showItem->number);
		else if(showItem->pre == NULL)
			printf("(ANFANG) %i <-> ", showItem->number);
		else
			printf("%i <-> ", showItem->number);

		showItem = showItem->post;
	}
}


// Funktion zum Anzeigen der Liste (Ausgabe rueckwaerts)
void showList_bwd() {
	if (anfang == NULL) {
		printf("Die Liste ist noch leer.\n");
		return;
	}
	ITEM* lastItem = anfang;
	int listLen = 1;
	// Navigiere zum Ende der Liste
	while (lastItem->post != NULL) {
		lastItem = lastItem->post;
		listLen++;
	}

	if (listLen == 1) {
		printf("(ENDE) %i (ANFANG)\n", lastItem->number);
		return;
	}

	ITEM* showItem = lastItem;
	// Ausgabe
	while(showItem != NULL){
		if (showItem->post == NULL)
			printf("(ENDE) %i", showItem->number);
		else if (showItem->pre == NULL)
			printf(" <-> %i (ANFANG)\n", showItem->number);
		else
			printf(" <-> %i", showItem->number);

		showItem = showItem->pre;
	}
}


// Funktion zum Enfernen von Elementen
// Hier werden alle Elemente entfernt, deren Wert number = num ist
void removeItem(int num) {
	if (anfang == NULL) {
		printf("Die Liste ist leer. Es koennen keine Elemente entfernt werden.\n");
		return;
	}

	ITEM* delItem = anfang;
	ITEM* bfrItem = NULL;
	while (delItem != NULL) {
		if (delItem->number == num) {
			// Element muss entfernt werden
			if (delItem->pre == NULL) {	// delItem ist der Anfang der Liste
				if (delItem->post == NULL) { // delItem ist auch Ende der Liste
					free(delItem);
					delItem = NULL;
					anfang = NULL;
				}
				else {	//delItem ist Anfang der Liste aber nicht das letzte Element
					delItem->post->pre = NULL;
					bfrItem = delItem->post;
					free(delItem);
					delItem = bfrItem;
				}
			}
			else {
				if (delItem->post == NULL) { // delItem ist nicht Anfang, aber Ende der Liste
					delItem->pre->post = NULL;
					free(delItem);
					delItem = NULL;
				}
				else { // delItem ist in der Mitte der Liste
					delItem->pre->post = delItem->post;
					delItem->post->pre = delItem->pre;
					bfrItem = delItem->post;
					free(delItem);
					delItem = bfrItem;
				}
			}
		}
		else {
			delItem = delItem->post;
		}

	}
}

int main() {
	// Erzeuge eine Liste
	addItem(1);
	addItem(2);
	addItem(4);
	addItem(3);
	addItem(2);
	addItem(1);
	// Zeige Liste vorwaerts und rueckwaerts
	showList_bwd();
	showList_fwd();

	// Entferne alle Eintraege mit '2'
	removeItem(2);
	// Zeige Liste erneut
	showList_bwd();
	showList_fwd();
	return 0;
}