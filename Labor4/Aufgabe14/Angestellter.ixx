/* hier */
#include <iostream>
#include <string>
using namespace std;

export module Angestellter;
export class Angestellter: public Mitarbeiter /* hier */
{
    double stundenLohn;
    double stunden;

public:
    Angestellter(const string vn, const string nn, double stdl = 0.0, double std = 0.0) : Mitarbeiter(vn, nn)
    {
        /* HIER */
        vorname = vn;
        nachname = nn;
        stundenLohn = stdl;
        stunden = std;
    }

    double getEinkommen() const
    {
        /* HIER */
        double einkommen = stundenLohn * stunden;
        return einkommen;
    }

    void print() const
    {
        cout << "Angestellter: ";
        Mitarbeiter::print();
    }
};