
#define _USE_MATH_DEFINES // enthält die Konstante M_PI.
#include <cmath>
#include <iostream>
using namespace std;
// hier die Methode trapezFlaeche implementieren

double trapezFlaeche(double a = 0, double b = 0, double gamma = 0, double c = 0);

double trapezFlaeche(double a, double b, double gamma, double c) {

	if (a != 0 && b != 0 && gamma != 0 && c != 0) {
		double f_trapez = 1.0/2.0 * (a + c) * b * sin(gamma * M_PI / 180.0);
		return f_trapez;
	}
	else if ( a != 0 && b != 0 && gamma != 0) {
		double f_parallelogram = a * b * sin(gamma * M_PI / 180.0);
		return f_parallelogram;
	}
	else if (a != 0 && b != 0) {
		double f_rechteck = a * b;
		return f_rechteck;
	}
	else return a * a;
	
}


int main(int argc, char* argv[]) {

	cout << "a = 2.0, b = 3.5, gamma = 45.0, c = 4.0 => Fläche: " 
	<< trapezFlaeche(2, 3.5, 45, 4) << endl;
	
	cout << "a = 3.0, b = 4.0, gamma = 45.0 => Fläche: " 
	<< trapezFlaeche(3, 4, 45) << endl;
	
	cout << "a = 4.0, b = 5.0 => Fläche: " 
	<< trapezFlaeche(4, 5) << endl;
	
	cout << "a = 2.0  => Fläche: " 
	<< trapezFlaeche(2) << endl;

	return 0;
}

