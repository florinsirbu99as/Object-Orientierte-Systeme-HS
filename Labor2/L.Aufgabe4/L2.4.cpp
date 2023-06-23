
#include <iostream>
using namespace std;
int f(int i) // funktionen haben gleiche parameter aber andere return typen
{
    cout << "Funktion 1: i=" << i << endl;
    return 0;
}
/*
void f(int i) // funktionen haben gleiche parameter aber andere return typen
{
    cout << "Funktion 2: i=" << i << endl;
}
*/
/*
char f(int i) // Überall sind zahlen bei return außer hier, hier ist ein 'a';
{
    cout << "Funktion 3: i=" << i << endl;
    return 'a';
}
*/
/*
int f(int &i) //???????????
{
    cout << "Funktion 4: i=" << i << endl;
    return 1;
}
*/
int f(int i, int k)
{
    cout << "Funktion 5: i=" << i << " k=" << k << endl;
    return 1;
}
int f(char c, int k)
{
    cout << "Funktion 6: c=" << c << " k=" << k << endl;
    return 1;
}
/*int f(int i, int k = 0)// geht nicht da man möchte f neu definieren, oben int f(int i, int j);
{
    cout << "Funktion 7: i=" << i << " k=" << k << endl;
    return 1;
}*/
int f(double d, int i, char c = 'a')
{
    cout << "Funktion 8: d=" << d << " i=" << i << " c=" << c << endl;
    return 1;
}
int f(double d, double e = 1.1, int i = 0)
{
    cout << "Funktion 9: d=" << d << " e=" << e << " i=" << i << endl;
    return 1;
}
/*int f(double d, double e = 1.1, char c) // es gibt keine c wert
{
    cout << "Funktion 10: d=" << d << " e=" << e << " c=" << c << endl;
    return 1;
}*/
int f(char c, char d, int i = 2, char e = 'c')
{
    cout << "Funktion 11: c=" << c << " d=" << d << " i=" << i << " e=" << e << endl;
    return 1;
}
int main(int argc, char* argv[])
{
    int i = 1;
    char c = 'a';
    f(1);
    f(c);
    f(i);
    c = f('a');
    c = 'a';
    f(1, 2);
    f(c, i);
    f(1.0, 2.0);
    f(1.0, 2.0, 1);
    f(1.0, 1, 'a');
    f(1.0, 1);
    f(1.0, static_cast<double>(i));
    f(c, c, i);
    f(c, i);
    return 0;
}

