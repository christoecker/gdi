#include <stdio.h>
// Makrodefinitionen zum Vertauschen von Variablenwerten
#define TAUSCHE(a, b, typ) {typ bfr = b; b = a; a = bfr;}


int main() {
	// Test mit int-Variablen
	int i_a = 12, i_b = 3;
	printf("i_a = %i, i_b = %i\n", i_a, i_b);
	TAUSCHE(i_a, i_b, int);
	printf("i_a = %i, i_b = %i\n", i_a, i_b);

	// Test mit float-Variablen
	float f_a = 1.234, f_b = 3.212;
	printf("f_a = %f, f_b = %f\n", f_a, f_b);
	TAUSCHE(f_a, f_b, float);
	printf("f_a = %f, f_b = %f\n", f_a, f_b);

	// Test mit char-Variablen
	char c_a = 'a', c_b = 'Z';
	printf("c_a = %c, c_b = %c\n", c_a, c_b);
	TAUSCHE(c_a, c_b, char);
	printf("c_a = %c, c_b = %c\n", c_a, c_b);

	return 0;
}