#pragma once
#include "Book.h"

int main()
{
    Book b;
    b.PrintBook();

    string n = "Mistery of Dragon's life";
    string auth = "Charlz Cooper";
    string p = "Mistic & Co";
    string g = "fantasy";
    string l = "english";
    Book b1(n, auth, 2024, p, g, "underfined", l, 100, 1);
    b1.PrintBook();
    b1.RunBookOut(100);
    b1.PrintBook();
    b1.WritePages(30);
    b1.PrintBook();
    b1.SellBook(50);
    b1.PrintBook();
    b1.SellBook(60);
    b1.PrintBook();
    cout << b1;
}