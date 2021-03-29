#include <stdio.h>

int main() {
	int n;
	float sum = 0, mean, inp;

	// Abfrage, aus wie vielen Zahlen der Mittelwert gebildet werden soll.
	printf("Aus wie vielen Zahlen (1 .. 10) soll ein Mittelwert gebildet werden?\n ");
	scanf_s("%i", &n);

	if (n >= 1 && n <= 10)
	{
		// Abfrage der Eingaben und gleichzeitig Summenbildung
		for (int i = 1; i <= n; i++) {
			printf("Bitte die %i. Zahl eingeben.\n", i);
			scanf_s("%f", &inp);
			sum += inp;
		}
		printf("Der Mittelwert der von Ihnen eingegebenen Zahlen betraegt %.2f.\n", sum / n);

	}
	else {
		printf("Es muessen mindestens 1 und maximal 10 Zaheln eingegeben werden.\n");
	}
}