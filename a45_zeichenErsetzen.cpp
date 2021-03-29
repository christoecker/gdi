#include <stdio.h>

int main() {
	char str[100];
	char symb, repl;

	printf("Bitte geben Sie eine Zeichenkette mit max. 100 Zeichen ein:\n");
	fgets(str, 100, stdin); 
	rewind(stdin);			// Leert den Eigabepuffer

	printf("Bitte geben Sie das Zeichen ein, das in der Zeichenkette ersetzt werden soll: ");
	symb = getchar(); rewind(stdin);

	printf("Bitte geben Sie das Ersatzzeichen ein: ");
	repl = getchar(); rewind(stdin);

	int i = 0;
	while (str[i] != '\0') {
		if (str[i] == symb)
			str[i] = repl;
		i++;
	}

	printf("Der modifizierte String:\n%s\n", str);
}


