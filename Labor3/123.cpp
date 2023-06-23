
#include<iostream>
using namespace std;

class Datum {
	
	int tag, monat, jahr;

public:
	Datum(int = 0, int = 0, int = 0);
    Datum operator + (int tage)
    {
        Datum beginnAufgabe;
        beginnAufgabe.tag = tage;
        beginnAufgabe.monat = monat;
        beginnAufgabe.jahr = jahr;
        return beginnAufgabe;
    }
};

// Implementierung des Konstruktors und der Operatoren

Datum::Datum(int tag, int monat, int jahr) 
{
    this->tag = tag;
    this->monat = monat;
    this->jahr = jahr;
};


int main(int argc, char *argv[])
{
    Datum beginnAufgabe = Datum(13,4,2022);
    cout << "Die Aufgabe beginnt am " << beginnAufgabe << endl;
}

