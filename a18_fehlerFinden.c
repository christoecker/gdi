#include <stdio.h>

int main() {
	float gradC, gradF;

	printf("Bitte Grad Celsius eingeben:\n");
	scanf_s("%f", &gradC);
	gradF = gradC * 1.8 + 32;
	printf("Temperatur in Grad Fahrenheit: %.2f.\n", gradF);
}