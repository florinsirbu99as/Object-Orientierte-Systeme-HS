#include <iostream>
#include <string>
using namespace std;

/* HIER */
#include "Mitarbeiter.h"
Mitarbeiter::Mitarbeiter(const string vn, const string nn)
{
    /* HIER */
    Mitarbeiter::vorname = vn;
    Mitarbeiter::nachname = nn;
}
void Mitarbeiter::print() const
{
    cout << nachname << ", " << vorname << endl;
}