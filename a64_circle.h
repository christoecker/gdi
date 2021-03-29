// Verhindert doppeltes Einbinden von circle.h
#ifndef CIRCLE_H
#define CIRCLE_H

// Konstante M_PI verfuegbar machen
#define _USE_MATH_DEFINES
#include <math.h>
/*
	Das Makro _USE_MATH_DEFINES wird in math.h
	abgefragt. Nur wenn dieses Makro existiert wird
	eine bedingte Kompilierung ausgefuehrt in der dann
	Konstanten, wie z.B. M_PI definiert werden.
*/
// Alternative zur Verwendung der math.h ueber
// die Definition einer Konstanten PI
// #define PI 3.141592654

// Sprachumstellung: String-Konstanten werden nur dann
// davon angelegt, wenn das Makro LANG_EN definiert ist
// (Definition siehe a64_sprachumstellung.cpp)
#ifdef LANG_EN
#define MSG_INP "Please enter radius R:\n"
#define MSG_OUT "Circle with radius R=%.1f yields area A=%.1f\n"
#endif
// Falls Makro LANG_EN nicht definiert wurde, wird automatisch
// das Programm in Deutsch kompiliert
#ifndef LANG_EN
#define MSG_INP "Bitte Radius R eingeben:\n"
#define MSG_OUT "Der Kreis mit Radius R=%.1f hat den Flaecheninhalt A=%.1f\n"
#endif

// Makro zur Berechnung des Flaecheninhalt
#define getA(r) M_PI*r*r

#endif