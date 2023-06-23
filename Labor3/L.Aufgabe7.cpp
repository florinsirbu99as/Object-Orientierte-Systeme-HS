
#include <iostream>
#include <string>
using namespace std;

// Klasse Kunde definieren

class Kunde {
    public:
    string name;
    string ort;
    int alter;
    double umsatz = 0;
    int transaktion = 0;
    int id;
    static int anzahl; 
    static int id_generator;
    Kunde(const string &name, const int alter, const string &ort);
    ~Kunde();
    static int getAnzahl();  
    void kaufe(const double umsatz);
    void print() {
        cout << "Kunde " << name << " aus " << ort;
        cout << " (ID = " << id << ", " << alter << " Jahre) ";
        cout << "hatte " << transaktion << " Transaktion(en) und ";
        cout << umsatz << " Euro Umsatz" << endl;
    }
}; 

int Kunde::anzahl = 0;
int Kunde::id_generator = 1;

Kunde::Kunde(const string &name, const int alter, const string& ort) {
    Kunde::name = name;
    Kunde::ort = ort;
    Kunde::alter = alter;
    Kunde::id = Kunde::id_generator;
    Kunde::anzahl = Kunde::anzahl + 1;
    Kunde::id_generator = Kunde::id_generator + 1;
}
Kunde::~Kunde() {
    Kunde::anzahl = Kunde::anzahl - 1;
}

int Kunde::getAnzahl() {
        return Kunde::anzahl;
    }  

void Kunde::kaufe (const double umsatz_) {
    Kunde::umsatz = umsatz + umsatz_;
    Kunde::transaktion = Kunde::transaktion + 1;
}

int main(int argc, char *argv[]) {
    Kunde Peter = Kunde("Peter", 17, "Stuttgart");
	Kunde klaus = Kunde("Klaus", 23, "Heilbronn");
    Peter.~Kunde();
	Kunde hans = Kunde("Hans", 21, "Karlsruhe");
	Kunde claudia = Kunde("Claudia", 30, "Nagold");
    std::cout << "Anzahl Kunden: " << Kunde::getAnzahl() << std::endl;
	klaus.kaufe(230);
	klaus.kaufe(400);
	claudia.kaufe(1000);
	hans.kaufe(199);
	klaus.kaufe(3.99);
	
    klaus.print();
	hans.print();
	claudia.print();
    claudia.~Kunde();
    std::cout << "Anzahl Kunden: " << Kunde::getAnzahl() << std::endl;
	return 0;
}

