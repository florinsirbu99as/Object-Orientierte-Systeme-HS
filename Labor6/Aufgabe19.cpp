
#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES //  M_PI.
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <iostream>
#include <vector>
#include <array>

using namespace std;

class Gericht {
protected:
    string name;
    vector<string> zutaten;
public:
    Gericht(string _name) : name(_name) {}
    void belegtMit(string zutat) 
    {
        zutaten.push_back(zutat);
    }
    virtual void zubereitung() 
    {
        for (string zutat : zutaten) {
            cout << "- " << zutat << endl;
        }
    }
};

class Burger : public Gericht {
public:
    Burger(string _name) : Gericht(_name) {}
    void zubereitung() override 
    {
        cout << name << ". Broetchen mit:" << endl;
        Gericht::zubereitung();
    }
};

class Pizza : public Gericht{
public:
    Pizza(string _name) : Gericht(_name) {}
    void zubereitung() override 
    {
        cout << "Pizza " << name << ". Pizzaboden, belegt mit:" << endl;
        Gericht::zubereitung();
    }
};

int main(int argc, char* argv[])
{
    Pizza* mista = new Pizza("Mista");
    mista->belegtMit("Salami");
    mista->belegtMit("Pilzen");
    Gericht* hawaii = new Pizza("Hawaii");
    hawaii->belegtMit("Schinken");
    hawaii->belegtMit("Ananas");
    Burger* hamburger = new Burger("Hamburger");
    hamburger->belegtMit("Hackfleisch");
    Gericht* cheesburger = new Burger("Cheesburger");
    cheesburger->belegtMit("Hackfleisch");
    cheesburger->belegtMit("Kaese");
    array<Gericht*, 4> speisekarte = { mista, hawaii, hamburger, cheesburger };
    for (Gericht* g : speisekarte)
    {
        g->zubereitung(); //*[1]
    }
    return 0;
}


