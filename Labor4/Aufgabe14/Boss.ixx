/* hier */
#include <iostream>
#include <string>
using namespace std;

export module Boss;
import Mitarbeiter;
export class Boss: public Mitarbeiter;
{
    double bossGehalt;

public:
    Boss::Boss(const string vn, const string nn, double g = 0)
    : Mitarbeiter(vn, nn) 
{
    /* HIER */
    bossGehalt = g;
}
    double getEinkommen() const
{
    /* HIER */
    return bossGehalt;
}
void print() const
{
    cout << "Boss: ";
    Mitarbeiter::print();
}
};


