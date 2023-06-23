/* hier */
#include <iostream>
#include <string>
using namespace std;

export module Mitarbeiter;
export class Mitarbeiter
{
    string vorname;
    string nachname;

public:
    Mitarbeiter(const string vn, const string nn)
    {
        /* HIER */
        vorname = vn;
        nachname = nn;
    }
    void print() const
    {
        cout << nachname << ", " << vorname << endl;
    }
};
