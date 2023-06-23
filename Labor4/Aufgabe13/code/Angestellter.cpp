#include <iostream>
using namespace std;

/* HIER */
#include "Mitarbeiter.h"
#include "Angestellter.h"

Angestellter::Angestellter(const string vn, const string nn,
                   double stdl, double std)
    : Mitarbeiter(vn, nn)
{
    /* HIER */
    stundenLohn = stdl;
    stunden = std;
}
double Angestellter::getEinkommen() const
{
    /* HIER */
    double einkommen = stundenLohn * stunden;
    return einkommen;
}

void Angestellter::print() const
{
    cout << "Angestellter: ";
    Mitarbeiter::print();
}