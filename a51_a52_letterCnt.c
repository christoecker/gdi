#include <stdio.h>

// Funktion zaehlt wie haeufig ein Buchstabe in dem 
// Wort str vorkommt.
// Diese Funktion ist ein Beispiel dafuer, wie eine 
// Funktion mit mehreren Rueckgabeparametern erstellt 
// werden kann.
int* countLetters(char* str) {
	static int cnt[26];
	// Zaehler zuruecksetzen
	for (int i = 0; i < 26; i++) {
		cnt[i] = 0;
	}

	int i = 0;
	while (str[i] != '\0') {
		// Zaehle nur falls auch ein Buchstabe vorliegt
		if (str[i] >= 65 && str[i] <= 90) {
			// Hier wird der ASCII-Wert des Buchstaben (dekrementiert
			// um den Wert des Buchstabens A (= 65) als Index benutzt.
			cnt[str[i] - 65]++;
		}
		i++;
	}

	return cnt;	// Gibt den Zeiger auf das erste Element von cnt zurueck
}

// Funktion wandelt alle Buchstaben des Worts str in Grossbuchstaben um
void setCapitals(char* str) {
	int i = 0;
	while (str[i] != '\0') {
		if (str[i] >= 97 && str[i] <= 122) {
			// Kleinbuchstabe erkannt
			str[i] -= 32;	// in Grossbuchstaben umwandeln
		}
		i++;
	}
}

int main() {
	char test[] = "Grundlagen der Informatik";
	int* letterCnt;

	// Buchstaben in Grossbuchstaben setzen
	setCapitals(test);
	printf("Modifizierte Eingabe: %s\n", test);

	// Haeufigkeit der Buchstaben zaehlen
	letterCnt = countLetters(test);
	printf("\nBuchstabe   Haeufigkeit\n");
	// Tabellarische Ausgabe
	for (int i = 0; i < 26; i++) {
		if(*(letterCnt + i) > 0)
			printf("    %c %12i\n", i + 65, *(letterCnt + i));
	}
	return 0;
}