#include <stdio.h>

int main() {
	int wb1, wb2, zahl;
	int wb_min, wb_max;

	// Eingabe des Wertebereichs
	printf("Bitte geben Sie den Wertebereich (zwei Zahlen) ein:\n");
	scanf_s("%i %i", &wb1, &wb2);

	// Eingabe der Zahl
	printf("Bitte geben Sie nun eine weitere Zahl ein:\n");
	scanf_s("%i", &zahl);

	// Ueberpruefung, ob die Zahl im Wertebereich liegt.
	// Zunaechst wird ermittelt was die untere und was 
	// die obere Grenze des Wertebereichs sind.
	wb_min = wb1 < wb2 ? wb1 : wb2;
	wb_max = wb1 > wb2 ? wb1 : wb2;
	// Dann wird geprueft, ob die eingegebene Zahl in diesem
	// Intervall liegt:
	if (zahl >= wb_min && zahl <= wb_max)
		printf("%i liegt im geschlossenen Intervall [%i, %i].\n", zahl, wb_min, wb_max);
	else
		printf("%i liegt ausserhalb des geschlossenen Intervalls [%i, %i].\n", zahl, wb_min, wb_max);
}