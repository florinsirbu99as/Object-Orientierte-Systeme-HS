
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

int main(int argc, char* argv[]) {
	double d = 1.234;
	cout << "Nr  Oct  Hex String  Fixed     Scientific " << endl;
	for (int k = 1; k < 11; k++)
	{
		cout << setw(3) << right << dec << k;
		cout << setw(4) << right << showbase << oct << k;
		cout << setw(5) << right << hex << k << " ";
		cout << setw(7) << left  << setfill('+') <<  string(k % 5 + 1, '*')  << " ";
		cout << setw(9) << right << setfill(' ') << fixed << internal << showpos << setprecision(3) << d;
		cout << setw(11) << uppercase << right << noshowpos << setprecision(3) << scientific << d;
		d = d*-2;
		
		cout << endl;
	}
	return 0;
}