/* hier */
#pragma once 
#include <string>
using namespace std;

class Mitarbeiter
{
    string vorname;
    string nachname;
 
public:
    Mitarbeiter(const string, const string);
    void print() const;
};