#include <stdio.h>

int main() {
	// Zeilennummer
	for (int i = 1; i <= 10; i++) {
		// Spaltennummer
		for (int j = 1; j <= 10; j++) {
			printf("%4i", i*j);
		}
		printf("\n");
	}
}