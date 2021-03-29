#ifndef LAGER_H
#define LAGER_H

// Die Makrodefinition muss in diesem Fall in der
// Headerdatei erfolgen, da die Defintion SIZE
// andernfalls hier nicht gesetzt werden kann
// und dann in der Datei lager.cpp unbekannt waere
#define PROVERSION

// Makros zur Ausgabe der Programmversion
#ifdef PROVERSION
#define VER printf("Programmversion: PRO\n");
#endif
#ifdef BASISVERSION
#define VER printf("Programmversion: BASIS\n");
#endif
/*
ACHTUNG: In anderer Reihenfolge funktioniert die Definiton nicht,
da in einem #define das Zeichen '#' ein nicht erlaubtes Zeichen ist.
*/

// Festlegung der Lagergroesse
// Standardmaessig ist die Lagergroesse auf 10 (Basisversion) eingestellt
#define SIZE 10
// Falls aber die PROVERSION erstellt werden soll, wird SIZE neu definiert
#ifdef PROVERSION
#undef SIZE
#define SIZE 20
#endif

// Funktionsprototypen
void einlagern(int[], int);
void auslagern(int[], int);
void zeigeLager(int[]);

#endif