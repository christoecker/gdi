#include <stdio.h>

int main() {
	int wahlAusgabe = 0, dezInp;

	printf("Bitte geben Sie eine Dezimalzahl (als ganze Zahl) ein: ");
	scanf_s("%i", &dezInp);

	printf("Bitte waehlen Sie, in welchem Format die von Ihnen eingegebene Zahl ausgegeben werden soll.\n");
	printf(" (1) Oktalzahl\n");
	printf(" (2) HEX-Zahl\n");
	printf(" (3) ASCII-Zeichen\n");
	scanf_s("%i", &wahlAusgabe);

	switch (wahlAusgabe) {
	case 1: printf("Die Zahl %i ist als Oktalzahl %o.\n", dezInp, dezInp); break;
	case 2: printf("Die Zahl %i ist als HEX-Zahl %x.\n", dezInp, dezInp); break;
	case 3: printf("Die Zahl %i ist als ASCII-Zeichen %c.\n", dezInp, dezInp); break;
	default: printf("Sie haben eine ungueltige Auswahl getroffen.\n");
	}
}