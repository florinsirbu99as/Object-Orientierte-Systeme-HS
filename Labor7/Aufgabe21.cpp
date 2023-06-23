#include <iostream>
#include <string>
#include <vector>
#include <exception>

using namespace std;

// Eigene Exceptionklasse "MyException"
// abgeleitet von Exception
class myException : public exception 
{
    // HIER
    string strwhat; 

public:
    myException(string dname, unsigned int znummer, string name = "") 
    {
        strwhat = "Fehler " + name + " aufgetreten in Datei " + dname + ", Zeile: " + to_string(znummer) + "."; 
    }

    const char *what() const noexcept override 
    {
        return strwhat.c_str(); 
    } 
};

// Eigene Exceptionklasse "ElefantTrifftAufMaus"
// abgeleitet von MyException
class ElefantTrifftAufMaus : public myException 
{
    // HIER
public:
    ElefantTrifftAufMaus(string dname, unsigned int znummer) 
        : myException(dname, znummer, "ElefantTrifftAufMaus") {}
};

// Klasse der Tiere
class Tier
{
    // Name des Tiers
    string name;

public:
    // Konstruktor
    Tier(string n = "") : name(n){}; 
    // virtuelle print-Funktion
    virtual void print(bool nl) const
    {
        cout << name;
        if (nl)
        {
            cout << endl;
        }
    }
    virtual Tier *clone() const = 0;
};

class Elefant : public Tier
{
public:
    // Konstruktor
    Elefant(string n = " ") : Tier(n) {}
    // virtuelle clone-Funktion
    virtual Elefant *clone() const
    {
        return new Elefant(*this);
    }
};

class Tiger : public Tier
{
public:
    // Konstruktor
    Tiger(string n = "") : Tier(n){};
    // virtuelle clone-Funktion
    virtual Tiger *clone() const
    {
        return new Tiger(*this);
    }
};

class Maus : public Tier
{
public:
    // Konstruktor
    Maus(string n = "") : Tier(n){};
    // virtuelle clone-Funktion
    virtual Maus *clone() const
    {
        return new Maus(*this);
    }
};

class Zoo
{
    // Name des Zoos
    string name;
    // Die Tiere werden in einem vektor gespeichert
    vector<Tier *> tiere;

public:
    // Konstruktor
    Zoo(string n)
    {
        
        name = n;
        
        // HIER
        if (name.length() < 4)  
            throw myException(__FILE__, __LINE__, "ZoonameZuKurz"); 
        
        name.at(4) = toupper(name.at(4)); 
    }

    // Ein Tier dem Zoo hinzufuegen
    void hinzu(const Tier &t)
    {
        
        // HIER
        if (!tiere.empty()) 
        {
            Tier *neuesTier = const_cast<Tier *>(&t); 
            Tier *letztesTier = tiere.back();

            if ((dynamic_cast<Maus *>(neuesTier) != nullptr && dynamic_cast<Elefant *>(letztesTier) != nullptr) || (dynamic_cast<Maus *>(letztesTier) != nullptr && dynamic_cast<Elefant *>(neuesTier) != nullptr))
            

            {
                throw ElefantTrifftAufMaus(__FILE__, __LINE__); 
            }
        }
        // HIER
        tiere.push_back(t.clone()); 
    }
    void print() const
    {
        // HIER
        for (Tier *tier : tiere) 
        {
            tier->print(true);
        }
    }
};

int main(int argc, char* argv[]) {
    string str;
    char c = 'X';
    // HIER
    try 
    {
        cout << "Bitte Name des Zoos eingeben: ";
        cin >> str;
        Zoo z(str);
        while (c != 'e')
        {
            cout << endl
                 << "Bitte Tierart auswaehlen:" << endl;
            cout << "1 = Elefant" << endl;
            cout << "2 = Tiger" << endl;
            cout << "3 = Maus" << endl;
            cout << "e = Ende mit Eingabe" << endl;
            cout << "Eingabe: ";
            cin >> c;
            if (c != 'e')
            {
                cout << "Bitte Namen des Tieres eingeben: ";
                cin >> str;
                Elefant el;
                Tiger ti;
                Maus ma;
                switch (c)
                {
                case '1':
                    el = Elefant(str);
                    z.hinzu(el);
                    break;
                case '2':
                    ti = Tiger(str);
                    z.hinzu(ti);
                    break;
                case '3':
                    ma = Maus(str);
                    z.hinzu(ma);
                    break;
                case 'e':
                    break;
                default:
                    // HIER
                    throw string("Fehlerhafte Eingabe!"); 
                }
            }
            cout << endl;
            z.print();
        }
    }
    
    // HIER
    catch (ElefantTrifftAufMaus &e) 
    {
        cout << e.what() << endl; 
    }
    
    // HIER
    catch (myException &e) 
    {
        cout << e.what() << endl; 
    }
    
    // HIER
    catch (exception &e) 
    {
        cout << "Standardausnahme: " << e.what() << endl; 
    }

    // HIER
    catch (...) 
    {
        cout << "Exception"; 
    return 0;
}
