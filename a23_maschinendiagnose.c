#include <stdio.h>

int main() {
	float schwingung, temp, leistung;

	printf("Simulation der Maschinendaten:\n");
	printf("Schwingungen in Hz: ");
	scanf_s("%f", &schwingung);
	printf("Temperatur in Grad C: ");
	scanf_s("%f", &temp);
	printf("Leistungsaufnahme in %: ");
	scanf_s("%f", &leistung);

	// Identifikation der Betriebsweise
	//    normale Betriebsweise
	if (leistung >= 20 && leistung <= 60) {		
		if (temp >= 85 && temp <= 105 && schwingung >= 100 && schwingung <= 110)
			printf("Maschine ist im Gutzustand.\n");
		else
			printf("Es liegt ein Fehler in der Maschine vor.\n");
	} 
	//    Volllast
	if (leistung > 60 && leistung <= 80) {
		if (temp >= 90 && temp <= 120 && schwingung >= 110 && schwingung <= 120)
			printf("Maschine ist im Gutzustand.\n");
		else
			printf("Es liegt ein Fehler in der Maschine vor.\n");
	}
	//    Notabschaltung
	if (leistung > 80) {
		printf("Zu hohe Leistungsaufnahme -> Notabschaltung!\n");
	}
	//    Maschine wird abgefahren
	if (leistung < 20) {
		printf("Maschine wird abgefahren. Keine Ausgabe von Alarmen!\n");
	}

	/*
		Bei dieser Loesung wird im Fehlerfall die Fehlerursache (z.B. 
		zu hohe Temperatur) nicht analysiert. Um dies zu tun, waere 
		eine weitere Gliederung des Programms in if-else-Anweisungen 
		noetig.
	*/
}