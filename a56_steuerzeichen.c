#include <stdio.h>

enum steuerzeichen { RS = 8, TAB, LF, VT, FF, CR };

int main() {
	steuerzeichen sign = RS;

	printf("Folgende Steuerzeichen sind im ASCII-Code definiert:\n");
	for (int i = 0; i <= 6; i++) {
		switch (sign + i) {
		case RS: printf("RS  (Rueckschritt): %c\n", sign + i); break;
		case TAB: printf("TAB (Tabulator): %c\n", sign + i); break;
		case LF: printf("LF  (Line Feed): %c\n", sign + i); break;
		case VT: printf("VT  (Vertikaler Tabulator): %c\n", sign + i); break;
		case FF: printf("FF  (Form Feed): %c\n", sign + i); break;
		case CR: printf("CR  (Carriage Return): %c\n", sign + i); break;
		default: printf("FEHLER! Der Wert %i ist im enum nicht definiert.\n", sign + i);
		}
	}
	return 0;
}