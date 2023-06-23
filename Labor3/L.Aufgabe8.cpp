
#include <iostream>
using namespace std;

// Klasse Point und Circle implementieren
class Point {
    private:
        double X, Y;
    public:
        void setX(double x) {
            X = x;
        }
        void setY(double y) {
            Y = y;
        }
        double getX() {
            return X;
        }
        double getY() {
            return Y;
        }
        void move(double x, double y) {
            X = X + x;
            Y = Y + y;
        }
        void print (bool t) {
            cout << "(" << X << "," << Y << ")";
    
            if(t == true) {
                cout << endl;
            }
        }

        void print () {
            cout << "(" << X << "," << Y << ")";
            cout << endl;
        }
};

class Circle {
    private:
        Point centre;
        double radius;
    public:
        Circle(Point p) {
            centre = p;
        };
        void setCentre(Point ce) {
            centre = ce;
        }
        void setRadius(double r) {
            radius = r;
        }
        Point getCentre() {
            return centre;
        }
        double getRadius() {
            return radius;
        }
        void move(double x, double y) {
            centre.move(x, y);
        }
        void print (bool t) {
            cout << "<(" << centre.getX() << "," << centre.getY() << ")," << getRadius() << ">";
    
            if(t == true) {
                cout << endl;
            }
        }

        void print () {
            cout << "<(" << centre.getX() << "," << centre.getY() << ")," << getRadius() << ">";
            cout << endl;
        }
};


// Hauptprogramm
int main(int argc, char *argv[])
{
	Point p;
	Circle c(p);
	cout << "Ausgabe 1:" << endl;
	p.print();
	c.print();
	p.setX(1.1);
	p.setY(2.2);
	c.setCentre(p);
	c.setRadius(3.3);
	cout << "Ausgabe 2:" << endl;
	p.print(false);
	cout << " == (" << p.getX() << ", " << p.getY() << ")"
		<< endl;
	c.print();
	p.move(1.0, 1.0);
	c.move(2.0, 2.0);
	cout << "Ausgabe 3:" << endl;
	p.print();
	c.print();
	return 0;
}

