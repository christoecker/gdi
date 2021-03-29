#include <stdio.h>
#include <string.h>		// fuer strcpy(), s.u.
#include <stdlib.h>

/*
Die folgenden Definitionen der Strukturvariablen sollten
NICHT in der Funktion main() gemacht werden, da sie sonst
nur dort bekannt waeren und nicht in den anderen Funktionen
genutzt werden koennen.
*/

// ---- 1. Definition der Strukturvariablen -------------
// Eine neue Strukturvariable 'adresse'
typedef struct {
	char strasse[30];
	int  hausnr;
	int  PLZ;		// Fuehrende Nullen muessten bei der 
					// Ausgabe ergaenzt werden	
	char ort[30];
}adresse;			// Der Typ der Strukturvariablen ist 
					// 'adresse'

					// Eine neue Strukturvariable 'telnr' (Speichert eine 
					// Telefonnummer)
typedef struct {
	int vorwahl;
	int nummer;
}telnr;				// Der Typ ist 'telnr'

					// Eine neue Strukturvariable 'kontakt'	
typedef struct {
	char    p_name[30];
	char    p_vorname[30];
	/* ACHTUNG: Die Strukturvariablen muessen
	vorher definiert sein, damit sie hier
	verwendet werden koennen. */
	adresse p_adr;		// Geschachtelte Strukturvariable.
	telnr   p_telnr;		// s.o.
}kontakt;
// ---- Ende der Definition der Strukturvariablen -------

/* Diese Funktion realisiert das Anlegen eines Kontakts.
Der Benutzer wird gebeten die entsprechenden Angaben
einzugeben, die dann in die Membervariablen der
Strukturvariablen kontakt gespeichert werden.

Der Parameter mit dem diese Funktion aufgerufen wird ist
ein Pointer auf eine Strukturvariable kontakt. Die
aufrufende Funktion kontrolliert damit also, welcher
Kontakt (d.h. welches Element im Kontaktverzeichnis)
beschrieben wird. Zeigt der uebergebene Pointer auf
einen Kontakt, der bereits mit Inhalt gefuellt ist, so
wird dieser Inhalt hier mit den neuen Benutzereingaben
ueberschrieben. (Damit eignet sich diese Funktion auch fuer
die Bearbeitung von Kontakten).
*/
void createContact(kontakt *k) {
	char strBfr[30];	// String, in dem die Tastatur-
						// eingaben gespeichert werden.
	int intBfr;

	// Abfrage Name
	printf("Name: ");
	scanf("%s", strBfr);			// Die Benutzereingabe 
									//wird im String strBfr 
									// gespeichert
	strcpy(k->p_name, strBfr);		// Der in strBfr 
									// gespeicherte Name wird 
									// in die Membervariable 
									// 'name' des Kontakt 
									// gespeichert
									// Abfrage Vorname
	printf("Vornamen: ");
	scanf("%s", strBfr);
	strcpy(k->p_vorname, strBfr);
	// Abfrage Strasse
	printf("Strasse: ");
	scanf("%s", strBfr);
	/* Achten Sie hier auf die Adressierung der Membervariablen
	'strasse' die wiederum Teil der Adresse ist (p_adr ist eine
	Membervariable von kontakt)*/
	strcpy(k->p_adr.strasse, strBfr);
	// Abfrage Hausnummer
	printf("Hausnummer: ");
	scanf("%i", &intBfr);
	k->p_adr.hausnr = intBfr;
	/* Der int-Wert kann der membervariablen hausnr (in p_adr)
	direkt zugewiesen werden. Dies ist ein Unterschied zu der
	uebergabe eines Strings (wie z.B. bei Name, Vorname oder
	Strasse), der mit strcpy in die Membervariable kopiert
	werden muss.*/

	// Abfrage PLZ
	printf("PLZ: ");
	scanf("%i", &intBfr);
	k->p_adr.PLZ = intBfr;
	// Abfrage Ort
	printf("Ort: ");
	scanf("%s", strBfr);
	strcpy(k->p_adr.ort, strBfr);
	// Abfrage Vorwahl
	printf("Telefon Vorwahl: ");
	scanf("%i", &intBfr);
	k->p_telnr.vorwahl = intBfr;
	// Abfrage Nummer
	printf("Telefon Nummer: ");
	scanf("%i", &intBfr);
	k->p_telnr.nummer = intBfr;

	system("cls");
	printf("Der Kontakt wurde angelegt.\n\n");
}

/* Funktion realisiert die Ausgabe eines Kontakts. Der Funktion
wird nur der Pointer auf den Kontakt uebergeben. Die aufrufende
Funktion (in diesem Fall main()) steuert damit also, welcher
Kontakt ausgegeben werden soll.
*/
void showContact(kontakt *k) {
	printf("\n--- %s %s ---\n", k->p_vorname, k->p_name);
	// Beachten Sie hier die Adressierung von strasse und hausnr.
	printf("Adresse:   %s %i\n", k->p_adr.strasse, k->p_adr.hausnr);
	printf("           %5i %s\n", k->p_adr.PLZ, k->p_adr.ort);
	// Durch die geschachtelten Strukturvariablen (Adresse in Kontakt)
	// wird ueber den Strukturoperator (->) zunaechst die Strukturvariable
	// p_adr adressiert und anschliessend wird ueber den .-Operator
	// strasse, hausnr, PLZ und ort (jeweils Membervariablen in adresse)
	// angesprochen.
	printf("Telefon:   (0%i) %i\n", k->p_telnr.vorwahl, k->p_telnr.nummer);
	printf("---------------------\n\n");
}

/* Funktion loescht den Kontakt, der ueber den uebergebenen Pointer adressiert
wird. Die Funktion funktioniert sehr aehnlich wie createContact, mit dem
Unterschied, dass der Benutzer natuerlich nicht nach Eingaben gefragt wird,
sondern die Membervariablen alle zurueckgesetzt werden.
*/
void deleteContact(kontakt *k) {
	strcpy(k->p_name, "");				// Name zuruecksetzen
	strcpy(k->p_vorname, "");			// Vorname zuruecksetzen
	strcpy(k->p_adr.strasse, "");		// Strasse zuruecksetzen
	k->p_adr.hausnr = 0;				// Hausnr. auf 0 setzten				
	k->p_adr.PLZ = 0;					// PLZ auf 0 setzen
	strcpy(k->p_adr.ort, "");			// Ort zuruecksetzen);
	k->p_telnr.vorwahl = 0;				// Vorwahl auf 0 setzen	
	k->p_telnr.nummer = 0;				// Nummer auf 0 setzen

	system("cls");
	printf("Der Kontakt wurde geloescht.\n\n");
}

/* Funktion zeigt das Kontaktverzeichnis in Kurzform an
*/
void showContactList(kontakt kV[]) {
	printf("Ihr Kontaktverzeichnis:\n");
	for (int i = 0; i < 10; i++) {
		if (strlen(kV[i].p_name) > 0) {	// Der Kontakt enthaelt Angaben
			printf("(%2i)  %s, %s\n", (i + 1), kV[i].p_name, kV[i].p_vorname);
		}
		else {			// Der Kontakt ist leer
			printf("(%2i)  - leer -\n", (i + 1));
		}
	}
}

void main() {
	kontakt kVerz[10];
	// Deklaration eines kontakt-Arrays mit 10 Elementen
	// Hier wird Speicherplatz fuer 10 Variablen vom Typ kontakt
	// reserviert, die Inhalte im Speicher sind aber noch die
	// "alten" Inhalte, d.h. hier ist das gespeichert, womit der
	// Speicher vorher belegt war.
	// Wuerde man jetzt schon die Kontakte auslesen, wuerde hier 
	// nichts Sinnvolles ausgegeben werden.

	int menuAuswahl, kontaktAuswahl;

	// Initialisiere das Kontaktverzeichnis (hiermit werden alle
	// Werte der Kontakte zurueckgesetzt)
	for (int i = 0; i < 10; i++) {
		deleteContact(&kVerz[i]);
		// Alle Werte aller Kontakt werden zurueckgesetzt
	}
	system("cls");

	// Menuauswahl
	do {
		int cnt = 0;		// Counter zaehlt die Kontakte
		printf("-- Auswahl (Kontaktverzeichnis) --\n");
		printf("(1) Neuen Kontakt anlegen\n");
		printf("(2) Kontakt bearbeiten\n");
		printf("(3) Kontakt loeschen\n");
		printf("(4) Kontakte anzeigen\n");
		printf("(0) ENDE\n\n");
		printf("Bitte treffen Sie eine Auswahl: ");
		scanf("%i", &menuAuswahl);
		system("cls");
		// Nach der Auswahl wird der Bildschirm geloescht.

		switch (menuAuswahl) {
		case 0: break;	// Programm wird beendet
		case 1:			// Neuen Kontakt anlegen
			system("cls");
			do {
				if (strlen(kVerz[cnt].p_name) == 0) {
					// Diese variable ist leer und kann daher beschrieben werden.

					createContact(&kVerz[cnt]);
					break;
				}
				else {
					cnt++;
					// cnt zaehlt, wie viele Kontakte schon angelegt sind
				}
			} while (cnt < 10);	// Kontaktverzeichnis voll
			if (cnt == 10) {
				printf("Ihr Kontaktverzeichnis ist voll. Es kann kein neuer Kontakt hinzugefuegt werden.\n\n");
			}
			break;
		case 2:			// Kontakt bearbeiten
			showContactList(kVerz);		// Zeigt das Kontaktverzeichnis (in Kurzform) an
			printf("\n Welchen Kontakt wollen Sie bearbeiten?\n");
			scanf("%i", &kontaktAuswahl);
			system("cls");
			if (kontaktAuswahl > 0 && kontaktAuswahl <= 10) {
				createContact(&kVerz[kontaktAuswahl - 1]);
				// Funktion zum Erstellen eines Kontakt wird aufgerufen
			}
			else {
				printf("Unzulaessige Auswahl!\n");
			}
			break;
		case 3:			// Kontakt loeschen
			showContactList(kVerz);		// Zeigt das Kontaktverzeichnis (in Kurzform) an
			printf("\n Welchen Kontakt wollen Sie loeschen?\n");
			scanf("%i", &kontaktAuswahl);
			system("cls");
			if (kontaktAuswahl > 0 && kontaktAuswahl <= 10) {		// Die Auswahlliste geht von 1 - 10
				deleteContact(&kVerz[kontaktAuswahl - 1]);			// Funktion zum Loeschen eines Kontakts wird aufgerufen
			}
			else {
				printf("Unzulaessige Auswahl!\n");
			}
			break;
		case 4:
			system("cls");
			printf("Ihr Kontaktverzeichnis\n");
			for (int i = 0; i < 10; i++) {
				// Es werden nur die Kontakte angezeigt, die auch einen Namen haben
				if (strlen(kVerz[i].p_name) > 0) {
					showContact(&kVerz[i]);
					cnt++;
				}
			}
			if (cnt == 0) {
				printf("... ist leer\n\n");
			}
		}
	} while (menuAuswahl != 0);
}