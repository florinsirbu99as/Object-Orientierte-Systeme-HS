
#include <cstddef>
#include <array>
#include <iostream>
using namespace std;

const unsigned int laenge = 10;

//hier

template <typename T>
array <T, laenge> sortiere(array<T, laenge> int_feld) 
{
    bool ist_sortiert = false;
    while (ist_sortiert == false)
    {
        ist_sortiert = true;
        for( int i = 0; i < int_feld.size() - 1; i++)
        {
            if(int_feld[i] > int_feld[i + 1])
            {
                T temp = int_feld[i];
                int_feld[i] = int_feld[i + 1];
                int_feld[i + 1] = temp;
                ist_sortiert = false;
            }
        }
    }
    return int_feld;
}

int main(int argc, char *argv[]) 
{
    array<int,laenge> int_feld = {10, 2, 7, 5, 8, 3, 4, 1, 9, 6};
    array<int, laenge> int_feld_sortiert = sortiere(int_feld);

    for (size_t i = 0; i < int_feld_sortiert.size(); i++) {
        cout << i << ": " << int_feld_sortiert[i] << endl;
    }

    array<char,laenge> char_feld = {'j', 'm', 'e', 't', 'k', 'o', 'p', 's', 'a', 'f'};
    array<char, laenge> char_feld_sortiert = sortiere(char_feld);

    for (size_t i = 0; i < char_feld_sortiert.size(); i++) {
        cout << i << ": " << char_feld_sortiert[i] << endl;
    }
}

