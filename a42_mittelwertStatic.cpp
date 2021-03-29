#include <stdio.h>
#include <stdlib.h>

float getMeanVal(float inp) {
	static int cnt = 0;		// Zaehler wird mit 0 initialisiert
	static float sum = 0;	// speichert die Summe aller uebergebenen Zahlen

	sum += inp;
	cnt++;

	return sum / cnt;		// Gibt Mittelwert zurueck
}

int main() {
	char nextInp;
	float f_inp;

	// erste Abfrage einer Zahl
	printf("Bitte geben Sie eine Zahl ein, die in die Mittelwertberechnung eingehen soll:\n");
	scanf_s("%f", &f_inp); rewind(stdin);
	printf("Der Mittelwert der eingegebenen Zahlen ist %.2f.\n", getMeanVal(f_inp));

	do { // Wiederholung der Abfrage
		printf("Moechten Sie eine weitere Zahl eingeben? (j/n)\n");
		nextInp = getchar(); rewind(stdin);
		if (nextInp == 'j' || nextInp == 'J') {
			system("cls");
			printf("Bitte geben Sie eine Zahl ein, die in die Mittelwertberechnung eingehen soll:\n");
			scanf_s("%f", &f_inp); rewind(stdin);
			printf("Der Mittelwert der eingegebenen Zahlen ist %.2f.\n", getMeanVal(f_inp));
		}
	} while (nextInp == 'j' || nextInp == 'J');
	return 0;
}


