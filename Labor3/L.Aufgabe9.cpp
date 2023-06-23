
#include<iostream>
using namespace std;

class Datum {
	
	int tag, monat, jahr;

public:
	Datum(int = 0, int = 0, int = 0);
	Datum operator+(int tage);
	friend ostream & operator<<(ostream &, const Datum &);
};

// Implementierung des Konstruktors und der Operatoren

Datum::Datum(int tag, int monat, int jahr) 
{
    this->tag = tag;
    this->monat = monat;
    this->jahr = jahr;
};

Datum Datum::operator+(int tage) 
{
    Datum datum = *this;
    for (int i = 0; i < tage; i++)
    {
        datum.tag++;
        if(datum.tag > 30)
        {
            datum.tag = 1;
            datum.monat++;
            if (datum.monat == 13) 
            {
                datum.monat = 1;
                datum.jahr++;
            }
        }
    }
    return datum;
};

ostream &operator<<(ostream &r, const Datum &datum)
{
    return r << datum.tag << "." << datum.monat << "." << datum.jahr;
};


int main(int argc, char *argv[])
{
    Datum beginnAufgabe = Datum(13,4,2022);
    cout << "Die Aufgabe beginnt am " << beginnAufgabe << endl;
    Datum endeAufgabe = beginnAufgabe + 7;
    cout << "Die Aufgabe endet am " << endeAufgabe << endl;
    Datum einJahrMonatSpaeter = beginnAufgabe + 390;
    cout << "Ein Jahr und ein Monat nach Aufgabenbeginn ist der " << einJahrMonatSpaeter << endl;
}

