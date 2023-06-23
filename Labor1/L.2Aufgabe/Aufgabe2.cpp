#include <string>
#include <iostream>
using namespace std;

struct listenElement {
    int id;
    listenElement *next;
};

listenElement *anfang = nullptr;

void element_hinzufuegen_vorne(int id_) {
    listenElement *neuesElement = new listenElement();
    neuesElement->id = id_;
    neuesElement->next = anfang;
    anfang = neuesElement;
}

void element_hinzufuegen_hinten(int id_) {
    /* HIER programmieren:
    Neues listenElement erzeugen.
    Ans Ende der Liste navigieren und neues listenElement anhängen. 
    */
}

void element_loeschen(int id_) {
    listenElement* ptr = anfang;
    listenElement* vorgaenger = nullptr;

    while (ptr != nullptr && ptr->id != id_) {
        vorgaenger = ptr;
        ptr = ptr->next;
    }
    if (ptr != nullptr) {
        if (ptr == anfang) {
            anfang = ptr->next;
        } else {
            vorgaenger->next = ptr->next;
        }
    }
    delete ptr;
}

void liste_ausgeben() {
    /* 
    Hier programmieren:
    Die Liste durchlaufen und jeweils die id des listenElements ausgeben. 
    */
}

int main(void)
{
    element_hinzufuegen_vorne(2);
    element_hinzufuegen_hinten(9);
    element_hinzufuegen_vorne(1);
    element_hinzufuegen_hinten(10);
    liste_ausgeben();
    element_loeschen(2);
    liste_ausgeben();
    return 0;
};
