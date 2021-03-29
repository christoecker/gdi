#include <stdio.h>

int main() {
	int monat, jahr, anzTage;

	printf("Bitte geben Sie den Monat ein, fuer den die Anzahl der Tage berechnet werden soll: ");
	scanf_s("%i", &monat);
	printf("Bitte geben Sie nun noch das Jahr ein: ");
	scanf_s("%i", &jahr);

	// Ueberpruefung des zulaessigen Wertebereichs
	if (monat >= 1 && monat <= 12 && jahr > 1582) {
		switch (monat) {
		case 1: printf("Der Januar %i hat 31 Tage.\n", jahr); break;
		case 3: printf("Der Maerz %i hat 31 Tage.\n", jahr); break;
		case 4: printf("Der April %i hat 30 Tage.\n", jahr); break;
		case 5: printf("Der Mai %i hat 31 Tage.\n", jahr); break;
		case 6: printf("Der Juni %i hat 30 Tage.\n", jahr); break;
		case 7: printf("Der Juli %i hat 31 Tage.\n", jahr); break;
		case 8: printf("Der August %i hat 31 Tage.\n", jahr); break;
		case 9: printf("Der September %i hat 30 Tage.\n", jahr); break;
		case 10: printf("Der Oktober %i hat 31 Tage.\n", jahr); break;
		case 11: printf("Der November %i hat 30 Tage.\n", jahr); break;
		case 12: printf("Der Dezember %i hat 31 Tage.\n", jahr); break;
		default: // betrifft nur den Monat 2 (Februar)
			// Ermittlung eines Schaltjahres
			if ((jahr % 400 == 0) || (jahr % 4 == 0) && (jahr % 100 != 0)) {
				printf("Das Jahr %i ist ein Schaltjahr.\n", jahr);
				printf("Der Februar %i hat daher 29 Tage.\n", jahr);
			}
			else {
				printf("Das Jahr %i ist kein Schaltjahr.\n", jahr);
				printf("Der Februar %i hat daher 28 Tage.\n", jahr);
			}
		}
	}
	else {
		printf("Ihre Eingaben liegen nicht in den zulaessigen Wertebereichen.\n");
		printf("Programmabbruch...\n");
	}
}