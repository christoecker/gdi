#include <stdio.h>
// Makrodefinitionen unter Verwendung des
// ternaeren Operators
#define MAX(a, b) a>b?a:b
#define MIN(a, b) a<b?a:b


int main() {
	int a = 12, b = 3;
	printf("max(%i, %i) = %i\n", a, b, MAX(a, b));
	printf("min(%i, %i) = %i\n", a, b, MIN(a, b));
	return 0;
}