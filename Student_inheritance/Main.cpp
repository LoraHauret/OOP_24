#pragma once
#include <iostream>
#include "Aspirant.h"
#include "Student.h"

int main()
{
    setlocale(0, "");
    /*Student st1;
    
    Student st2;
    
    st1.Mark(10);
    st1.Mark(11);
    st1.Mark(12);

    st2.Mark(5);
    st2.Mark(6);
    st2.Mark(7);
    
    cout << st1;
    cout << st2;
    st1 = st2;
    st1.Mark(10);
    cout << st1;
    cout << st2;

    Student st3 = st1 + st2;
    cout << st3;*/

    /*Student st4{ "Vika","Belkina", 12, 23};
    string ststr = st4;
    cout << ststr;*/

    Aspirant asp1{ "Kristina", "Furshetkina", 14, 34, "SOLID" };
    cout << asp1;
}