
#include <string>
#include <iostream>
using namespace std;

class Person {
	string name;
	int ausleihdauer;
public:
	Person(string name, int dauer = 0)
	{
		this->name = name;
		this->ausleihdauer = dauer;
	}
	int getAusleihdauer() const 
	{
		return this->ausleihdauer;
	}
	void print() const
	{
		cout << name;
	}
};

// Implmentierung des Konstruktors und der Methoden

class Dozent : public Person 
{
	int prfNr;
	public:
		Dozent(string name, int prfNr) : Person(name, 90)
		{
			this->prfNr = prfNr;
		}

		void print() const 
		{
			Person person = *this;
			person.print();
			cout << ", prfNr " << prfNr << endl;
		}
};

// Implmentierung des Konstruktors und der Methoden

class Student : public Person
{
	int matNr;
	public:
		Student(string name, int matNr) : Person(name, 30)
		{
			this->matNr = matNr;
		}

		void print() const
		{
			Person person = *this;
			person.print();
			cout << ", matNr " << matNr << endl;
		}
};

// Implmentierung des Konstruktors und der Methoden

int main(int argc, char *argv[]) {
    Student maier = Student("maier", 12345678);
    Dozent mueller = Dozent("mueller", 98);
    maier.print();
    cout << "Ausleihdauer: " << maier.getAusleihdauer() << " Tage(e)" << endl;
    mueller.print();
    cout << "Ausleihdauer: " << mueller.getAusleihdauer() << " Tage(e)" << endl;
}

