
#include <string>
#include <iostream>
using namespace std;

// Klasse Student
class Student {
    private:
        string name, vorname;
    public:
        Student(string name_, string vorname_);
        ~Student();
        void print(bool t);
        void print();
        string getVorname();
        string getName();
};

Student::Student(string name_, string vorname_) {
    Student::name = name_;
    Student::vorname = vorname_;
    cout << "Parametisierter Konstruktor Studen: " << name << endl;
}

Student::~Student() {
    cout << "Destruktor Student: " << name << endl;
}

string Student::getName() {
    return name;
}

string Student::getVorname() {
    return vorname;
}

void Student::print(bool b) {
    cout << "Student flag; Name: " << name << ", Vorname: " << vorname;
    
    if(b == true) {
        cout << endl;
    }
}

void Student::print() {
    cout << "Student; Name: " << name << ", Vorname: " << vorname << endl;

}


// Klasse Mitarbeiter
class Mitarbeiter {
    private: 
        string name, vorname;
    public:
        Mitarbeiter(Student &Student) {
            name = Student.getName();
            vorname = Student.getVorname();
            cout << "Konvertierungskonstruktor Mitarbeiter: " << vorname << endl;
        }

        Mitarbeiter(string name_, string vorname_) {
            name = name_;
            vorname = vorname_;
            cout << "Parametisierter Konstruktor Mitarbeiter: " << name << endl;
        }

        Mitarbeiter(): name("Alice"), vorname("Bob") {
            cout << "Standardkonstruktor Mitarbeiter: " << name << endl;
        }

        ~Mitarbeiter() {
            cout << "Destruktor Mitarbeiter: " << name << endl;
        };

        void print(bool b) {
           cout << "Mitarbeiter; Name: " << name << ", Vorname: " << vorname;
    
            if(b == true) {
                cout << endl;
            }
        }

        void print() {
            cout << "Mitarbeiter; Name: " << name << ", Vorname: " << vorname << endl;
        }
};

int main(int argc, char *argv[])
{
    Student stud_maier = Student("Maier", "Peter");
    Mitarbeiter mit_maier = Mitarbeiter(stud_maier);
    Mitarbeiter mit_default = Mitarbeiter();
    stud_maier.print();
    stud_maier.print(true);
    mit_maier.print();
    mit_default.print();
    cout << "Block beginnt" << endl;
    Student *stud_mueller = nullptr;
    {
        stud_mueller = new Student("Mueller", "Paula");
        stud_mueller->print(true);
    }
    cout << "Block verlassen" << endl;
    delete stud_mueller;
    return 0;
}

