#include <stdio.h>
#include <string.h>			// zur Ermittlung der Stringlaenge

int main() {
	char str[100];			// speichert String
	int strLen;				// speichert Laenge der eingegebenen Zeichenkette
	short isPalindrom = 1;	// Merker

	printf("Bitte geben Sie eine Zeichenkette mit max. 100 Zeichen ein:\n");
	fgets(str, 100, stdin); 
	rewind(stdin);			// Leert den Eigabepuffer
	strLen = strlen(str);	// Achtung: ein Wort mit n lesbaren Zeichen
							// hat die Laenge n+1. Der Index laeuft also
							// von 0 bis (n-2).

	int s = 0;				// Laufvariable fuer Index des Strings
	while (isPalindrom && s <= (strLen-2) / 2) {
		if (str[s] != str[strLen-2 - s]) {
			isPalindrom = 0;
		}
		s++;
	}
	// Ausgabe in Abhaengigkeit der Variablen isPalindrom
	printf("Das eingegebene Wort ist %s Palindrom.\n", isPalindrom ? "ein" : "kein");
}


