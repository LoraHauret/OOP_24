#pragma once
#include "Student.h"

class Aspirant : Student
{
    string theme = "";
public:
    Aspirant();
    Aspirant(string name, string surname, size_t group, size_t age, string theme); 
    Aspirant(const Aspirant& other);
    Aspirant(const Student& other);
    Aspirant& operator=(const Aspirant& other);    
    ~Aspirant();  
    string GetTheme();
    void SetTheme();
    void SetTheme(string);
    friend std::ostream& operator<<(std::ostream& out, const Aspirant& st);
};