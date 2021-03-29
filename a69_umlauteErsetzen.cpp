#include <stdio.h>

int main() {
	FILE *file_ptr = NULL;	
	char readIn;
	int cnt_ae = 0, cnt_Ae = 0, cnt_ue = 0, cnt_Ue = 0, cnt_oe = 0, cnt_Oe = 0;

	file_ptr = fopen("test_Umlaute.abc", "r");	// Datei lesend oeffnen
	if (file_ptr != NULL) {
		FILE *file_bfr = fopen("bfr", "w");
		while (!feof(file_ptr)) {	
			readIn = fgetc(file_ptr); 
			switch (readIn) {
			case char(228): fprintf(file_bfr, "%s", "ae"); cnt_ae++; break;
			case char(196): fprintf(file_bfr, "%s", "Ae"); cnt_Ae++; break;
			case char(252): fprintf(file_bfr, "%s", "ue"); cnt_ue++; break;
			case char(220): fprintf(file_bfr, "%s", "Ue"); cnt_Ue++; break;
			case char(246): fprintf(file_bfr, "%s", "oe"); cnt_oe++; break;
			case char(214): fprintf(file_bfr, "%s", "Oe"); cnt_Oe++; break;
			case char(255): break;
			default: fprintf(file_bfr, "%c", readIn);
			}
		}
		fclose(file_ptr);				// Schliesst die Datei
		fclose(file_bfr);
		remove("test_Umlaute.abc");		// Originaldatei wird geloescht
		// Datei bfr wird umbenannt
		rename("bfr", "test_Umlaute.abc");
		if (cnt_ae + cnt_Ae + cnt_ue + cnt_Ue + cnt_oe + cnt_Oe > 0) {
			printf("Es wurden folgende Ersetzungen vorgenommen:\n");
			if (cnt_ae) printf("ae: %i Mal\n", cnt_ae);
			if (cnt_Ae) printf("Ae: %i Mal\n", cnt_Ae);
			if (cnt_ue) printf("ue: %i Mal\n", cnt_ue);
			if (cnt_Ue) printf("Ue: %i Mal\n", cnt_Ue);
			if (cnt_oe) printf("oe: %i Mal\n", cnt_oe);
			if (cnt_Oe) printf("Oe: %i Mal\n", cnt_Oe);
		}
		else {
			printf("Es wurden keine Ersetzungen vorgenommen.\n");
		}
	}
	else {
		printf("Datei konnte nicht geoeffnet werden.\n");
	}
	return 0;
}