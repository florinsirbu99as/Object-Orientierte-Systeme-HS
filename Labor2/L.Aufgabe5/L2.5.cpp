
#include<iostream>
using namespace std;

// hier die Klasse Punkt implementieren
/*class Punkt {
    public:
    double X;
    double Y;
    
    void setX(double x) {
        X = x;
    }

    void setY(double y) {
        Y = y;
    }

    void print() {
    cout << "print-Methode:" << endl;
    cout << "X = " << X << endl;
    cout << "Y = " << Y << endl;
}
    double getX() {
        return X;
    }
    double getY() {
        return Y;
    }
};
*/

class punkt {
    
    public:
        int X;
        int Y;

    void setX(int x);
    void setY(int y);
    int getX();
    int getY();
    void print();
};

    void punkt::setX(int x) {
        X = x;
    }

    void punkt::setY(int y) {
        Y = y;
    }

    int punkt::getX() {
        return X;
    }

    int punkt::getY() {
        return Y;
    }

    void punkt::print() {
        cout << "print-Methode:" << endl;
        cout << "X = " << X << endl;
        cout << "Y = " << Y << endl;
    }

int main(int argc, char* argv[]) {
    punkt p;
    p.setX(1);
    p.setY(10);
    p.print();
    p.setX(5);
    cout << "X ohne print(): " << p.getX() << endl;
    cout << "Y ohne print(): " << p.getY() << endl;
    return 0;
}

