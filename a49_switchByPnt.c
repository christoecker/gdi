#include <stdio.h>

/*
	Wuerden die Uebergabeparameter nicht als
	pointer (sondern als normale int-Variablen)
	definiert, waeren diese "nur" lokale Variablen
	der Funktion und wuerden nicht die tatsaechlichen
	Variablenwerte vertauschen.
*/
void switchByPnt(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

int main() {
	int i_a = 10, i_b = 12;
	printf("VOR Ausfuehrung von switchByPtr():\n");
	printf("i_a = %i, i_b = %i\n", i_a, i_b);
	switchByPnt(&i_a, &i_b);
	printf("NACH Ausfuehrung von switchByPtr():\n");
	printf("i_a = %i, i_b = %i\n", i_a, i_b);
}