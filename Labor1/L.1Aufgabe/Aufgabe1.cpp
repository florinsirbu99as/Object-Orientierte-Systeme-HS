/*
Spiel Stein, Schere und Papier
Regeln:
Es gibt zwei Spieler: der Programmierer und der Computer.
Beide Spieler waehlen gleichzeitig eines der drei Objekte
Stein, Schere und Papier. Beide können das gleiche Objekt wählen.
Der Spieler, der das mächtigere Objekt gewählt hat gewinnt.
SCHERE kann einen STEIN nicht zerschneiden, d.h. STEIN ist
mächtiger als SCHERE. PAPIER wickelt STEIN ein, d.h. PAPIER ist
mächtiger als STEIN. SCHERE zerschneidet PAPIER, d.h. SCHERE
ist maechtiger als PAPIER
*/

#include <string>
#include <ctime>
#include <iostream>

using namespace std;

// Aufzählungstyp für wählbare Objekte
enum class objekt { STEIN, SCHERE, PAPIER };
// STEIN - 0, SCHERE - 1, PAPIER - 2

// Aufzählungstyp für mögliche Spielausgänge
enum class ergebnis { SpielerEinsGewinnt, SpielerZweiGewinnt, Unentschieden };

// Struktur für einen Spieler bestehend aus Name und Wahl des Spielers
struct spieler
{
	string name;
	objekt wahl;
};

// Name des Spielers eingeben
string gibNameEin() 
{
	/* 
	HIER programmieren:
	Den Namen des Spielers von der Konsole einlesen und zurückgeben
	Tip: für das Einlesen eines Strings gibt es eine bestimmte Funktion, siehe auch Vorlesung Folie "Eine Zeile als String einlesen"
	*/
}

// Den Computer zufällig waehlen lassen.
objekt waehleZufaellig()
{
	/* 
	HIER beantworten Sie folgende Fragen:
	Was bewirkt die funktion srand?
	Warum wird hier die Zeit (time) verwendet?
	Wie funktioniert die funktion rand?
	Warum wird hier modulo 3 verwendet?
	*/
	srand(static_cast<int>(time(nullptr)));
	int wahl = rand() % 3;
	return static_cast<objekt>(wahl);
}

// Die Wahl von STEIN etc. als String zurückgeben lassen
string gibNameZurueck(objekt _objekt) 
{
	/* 
	HIER programmieren:
	Abhängig von der vorliegenden Objekt einen entsprechenden String zurückgeben.
	z.B: Wenn _objekt dem Wert objekt::STEIN entspricht, dann String "Stein" zurückgeben
	*/
}

// Einen Text mit dem Namen des Spielers und seiner Wahl ausgeben
void gibWahlAus(spieler _spieler)
{
	/* 
	HIER programmieren:
	Auf der Konsole ausgeben, für welches Objekt sich der Spieler entschieden hat.
	z.B.: "Computer hat das Objekt Schere gewählt"
	TIP: Nutzen sie hierzu die Funktion gibNameZurueck 
	*/
}

// Die Wahl des Spielers abfragen
objekt frageWahlAb()
{
	/* 
	HIER programmieren:
	Die Wahl des Spielers von der Konsole einlesen und zurückgeben
	Stellen sie sicher, dass es sich um eine gültige Wahl handelt!
	TIP: Nutzen Sie dazu eine geeignete Schleife. Siehe auch Vorlesung Folie "Annehmende Schleifenanweisungen – Do"  
	*/
}

ergebnis ermittleErgebnis(spieler _spieler1, spieler _spieler2)
{
	/* 
	HIER programmieren:
	Vergleichen Sie die gewählten Objekte, ermitteln sie das Spielergebnis und geben sie es zurück
	TIP: Wenn Sie für den Vergleich mit ganzene Zahlen rechnen wollen, dann nutzen sie den static_cast, siehe auch Vorlesung Folie "Casts in C++: Static_cast"
	*/
}

void gibErgebnisAus(spieler _spieler1, spieler _spieler2)
{
	/* 
	HIER programmieren:
	Ermitteln Sie zunächst das Spielergebnis. Nutzen sie dazu die Funktion ermittleErgebnis.
	Geben Sie anschließend auf der Konsole aus, wer gewonnen hat.
	z.B: "Spieler Computer hat gewonnen" oder "Unentschieden"
	*/
}

int main()
{
	spieler spieler1, spieler2;
	spieler1.name = "Computer";
	spieler1.wahl = waehleZufaellig();
	cout << "Der Computer hat sein Wahl getroffen." << endl;
	spieler2.name = gibNameEin();
	spieler2.wahl = frageWahlAb();
	gibWahlAus(spieler1);
	gibWahlAus(spieler2);
	gibErgebnisAus(spieler1, spieler2);
}
