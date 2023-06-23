#include <string>
#include <iostream>
using namespace std;

struct listenElement {
    int id;
    listenElement *next;
    listenElement *prev;
};

listenElement *anfang = nullptr;

void element_hinzufuegen_vorne(int id_) {
    listenElement *neuesElement = new listenElement();
    neuesElement->id = id_;
    neuesElement->next = anfang;
    anfang = neuesElement;
}

void element_hinzufuegen_hinten(int id_) {
    listenElement* neuesElement = new listenElement();
    neuesElement->id = id_;
    neuesElement->next = nullptr;
    
    if (anfang == nullptr)
    {
        anfang = neuesElement;
    }
    else
    {
        listenElement* temp = anfang;
        while(temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = neuesElement;
    }
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

void liste_ausgeben(listenElement* node) {
    while (node != nullptr)
    {
        cout << node->id << endl;
        node = node->next;
    }
    
}

int main(void)
{
    element_hinzufuegen_vorne(2);
    element_hinzufuegen_hinten(9);
    element_hinzufuegen_vorne(1);
    element_hinzufuegen_hinten(10);
    liste_ausgeben(anfang);
    element_loeschen(2);
    liste_ausgeben(anfang);
    return 0;
};
