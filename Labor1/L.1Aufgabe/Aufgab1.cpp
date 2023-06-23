
#include <string>
#include <ctime>
#include <iostream>

using namespace std;


enum class objekt { STEIN, SCHERE, PAPIER };

enum class ergebnis { SpielerEinsGewinnt, SpielerZweiGewinnt, Unentschieden };

struct spieler
{
    string name;
    objekt wahl;
};

string gibNameEin(spieler _spieler)
{
    cout << "Name eingeben:" << endl;
    cin.clear();
    getline(cin, _spieler.name);
    return _spieler.name;
}

objekt waehleZufaellig()
{
    srand(static_cast<int>(time(nullptr)));
    int wahl = rand() % 3;
    return static_cast<objekt>(wahl);
    /* - Funktion srand generiert zufällige zahlen.
       - mit time wird es immer zufällige zahlen generiert wenn wir zb eine zahl 49 schreiben wurden ->srand(49) dann wird eine zufällige zahl generiert aber er wird immer derselbe sein aber mit time werden jedes mal andere zahlen generiert.
       - die funktion rand wählt eine zufählige zahl.
       - mit modulo 3 wird es gemacht dass die zufählige zahlen von srand sind nur von 0 bis 2;
     */
}

string gibNameZurueck(objekt _objekt)
{
    if(_objekt == objekt::STEIN)
    {
        return "Stein";
    }
    else if(_objekt == objekt::SCHERE)
    {
        return "Schere";
    }
    else
        return "Papier";
    
}

void gibWahlAus(spieler _spieler)
{
   
    cout << _spieler.name;
    cout << " hat das Objekt " << gibNameZurueck(_spieler.wahl);
    cout << " gewaehlt." << endl;
    
    
}

objekt frageWahlAb(spieler _spieler)
{
    int i;
       cout << "Bitte Objektwahl eingeben (1 = Stein, 2 = Schere, 3 = Papier): " << endl;
       cin >> i;
       if (i == 1)
       {
           return objekt::STEIN;
       }
       else if (i == 2)
       {
           return objekt::SCHERE;
       }
       else
       return objekt::PAPIER;
}

ergebnis ermittleErgebnis(spieler _spieler1, spieler _spieler2)
{
    if(_spieler2.wahl == objekt::STEIN && _spieler1.wahl == objekt::SCHERE)
    {
        return static_cast<ergebnis>(1);
    }
    else if(_spieler2.wahl == objekt::PAPIER && _spieler1.wahl == objekt::STEIN)
    {
        return static_cast<ergebnis>(1);
    }
    else if(_spieler2.wahl == objekt::SCHERE && _spieler1.wahl == objekt::PAPIER)
    {
        return static_cast<ergebnis>(1);
    }
    else if (_spieler2.wahl == _spieler1.wahl)
    {
        return static_cast<ergebnis>(2);
    }
    else return static_cast<ergebnis>(0);
}

void gibErgebnisAus(spieler _spieler1, spieler _spieler2)
{
    if(static_cast<int>(ermittleErgebnis(_spieler1, _spieler2)) == 0)
    {
        cout << "Spieler " << _spieler1.name << " hat gewonnen" << endl;
    }
    else if (static_cast<int>(ermittleErgebnis(_spieler1, _spieler2)) == 1)
    {
        cout << "Spieler " << _spieler2.name << " hat gewonnen" << endl;
    }
    else if (static_cast<int>(ermittleErgebnis(_spieler1, _spieler2)) == 2)
    {
        cout << "Unentschieden" << endl;
    }
}

int main()
{
    spieler spieler1, spieler2;
    spieler1.name = "Computer";
    spieler1.wahl = waehleZufaellig();
    cout << "Der Computer hat sein Wahl getroffen." << endl;
    spieler2.name = gibNameEin(spieler2);
    spieler2.wahl = frageWahlAb(spieler2);
    gibWahlAus(spieler1);
    gibWahlAus(spieler2);
    gibErgebnisAus(spieler1, spieler2);
}
