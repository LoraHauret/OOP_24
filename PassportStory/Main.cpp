#pragma once
#include "ForeignPassport.h"
#include "Passport.h"
#include "Visa.h"

using namespace std;

int main()
{
    setlocale(0, "");
    Passeport p;
    cout << p;

    Visa v;
    cout << v;

    ForeignPassport fp("Lora Hauret", tm{ 02, 11, 1977 }, 1234567, "Local Authority");
    fp.AddVisa(v);
    cout << "\n";
    cout << fp;
}