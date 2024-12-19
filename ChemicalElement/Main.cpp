#pragma once
#include "ChemicalElement.h"

int main()
{
    setlocale(0, "");

    Element el((string)"Hydrogen", (string)"H", 1, 1, 1.008f, 1, 1, Element::Origin::GREEK, Element::PHASE::GAS, new float(0.00008988f), new float(14.01f));
    cout << static_cast<string> (el) << "\n";

    el.printElement();

    /*el.meltElement();
    el.printElement();

    el.boilElement();
    el.printElement();

    el.freezeElement();
    el.printElement();*/
    string path = "elements.txt";
    size_t size;
    Element** el_array = el.loadElements(path, size);
    for (size_t i = 0; i < size; i++)
    {
        cout << "\n*********************\n";
        cout << static_cast<string> (*el_array[i]);
    }
    /*float aw = el_array[0]->get_atomic_weight();
    cout << aw << "\n";

    aw = 333;
    cout << aw << "\n";
    cout << el_array[0]->get_atomic_weight()<<"\n";
    float density = el_array[0]->get_density();*/
    size_t atomic_number = el_array[0]->get_atomic_number();
    cout << el_array[0]->get_atomic_number() << "\n"; 
    atomic_number = 5;
    cout << atomic_number << "\n";
    cout << el_array[0]->get_atomic_number() << "\n";
    delete[]el_array;
    return 0;

}
