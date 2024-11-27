#pragma once
#include "Aspirant.h"

Aspirant::Aspirant()
{
    Student::Student();
    this->SetTheme();
    cout << "\nвызван конструктор по умолчанию класса Аспирант\n";
}
Aspirant::Aspirant(string name, string surname, size_t group, size_t age, string theme):Student(name, surname, group, age)
{    
    SetTheme(theme);
    cout << "\nвызван конструктор класса Аспирант\n";
}
Aspirant::Aspirant(const Aspirant& other):Student(other)
{
    this->theme = other.theme;
    cout << "\nвызван конструктор копирования класса Аспирант\n";
}
Aspirant::Aspirant(const Student& other) :Student(other)
{
    this->SetTheme();
    cout << "\nвызван конструктор копирования класса Аспирант\n";
}
Aspirant& Aspirant:: operator=(const Aspirant& other)
{
    if (this != &other)
    {
	Student::operator=(other);
	this->SetTheme(other.theme);
    }
    return *this;
}
Aspirant::~Aspirant()
{
    cout << "\nвызван деструктор класса Аспирант\n";
}
string Aspirant::GetTheme()
{
    return theme;
}
void Aspirant::SetTheme()
{
    cout << "Тема кандидатской работы: ";
    cin >> theme;
    cout << "\n";
}
void Aspirant::SetTheme(string theme)
{
    this->theme = theme;
}

std::ostream& operator<<(std::ostream& os, const Aspirant& asp)
{
    os << Student(asp);
    os << "Теиа: " << asp.theme<< "\n";
    return os;
}