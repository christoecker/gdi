#include <stdio.h>

// Ermittlung der Fibonacci-Zahl
int fib(int n) {
	switch (n) {
		case 0: return 0;		// fib(0) = 0
		case 1: return 1;		// fib(1) = 1
		default: return fib(n - 1) + fib(n - 2);	// Rekursion
	}
}

int main() {
	int nInp;
	
	// Testausgabe
	printf("Bitte n eingeben, fuer das die Fibonacci-Zahl ermittelt werden soll:\n");
	scanf_s("%i", &nInp);
	printf("fib(%i) = %i.\n", nInp, fib(nInp));
}