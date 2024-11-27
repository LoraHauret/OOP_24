#pragma once
#include "Passport.h"
//#include "Header.h"
using namespace std;

Passeport::Passeport()
{
    this->SetFullName();
    this->SetBirthDate();
    this->SetPassportNumber();
    this->SetIssuedBy();
}
Passeport::Passeport(string fullName, tm dateOfBirth, size_t passportNumber, string issuedBy)
{
    this->SetFullName(fullName);
    this->SetBirthDate(dateOfBirth);
    this->SetPassportNumber(passportNumber);
    this->SetIssuedBy(issuedBy);
}
string Passeport::GetFullName()
{
    return full_name;
}
tm Passeport::GetBirthDate()
{
    return birth_date;
}
size_t Passeport::GetPassportNumber()
{
    return passport_number;
}
string Passeport::GetIssuedBy()
{
    return issuedBy;
}
void Passeport::SetFullName(string full_name)
{
    this->full_name = full_name;
}
void Passeport::SetFullName()
{ 
    cout << "ФИО: ";
    getline(cin, full_name);
    cout << "\n";
}
void Passeport::SetBirthDate(tm date)
{
    this->birth_date = date;
}
void Passeport::SetBirthDate()
{
    cout << "Дата рождения:\nДень: ";
    cin >> birth_date.tm_mday;
    cout << "\nМесяц: ";
    size_t m;
    cin >> m;    // можно проверить
    birth_date.tm_mon = m -1;
    cout << "\nГод: ";    // можно проверить
    size_t y;
    cin >> y;
    birth_date.tm_year = y - 1900;
    cout << "\n";
}
void Passeport::SetPassportNumber(size_t number)
{
    this->passport_number = number;
}
void Passeport::SetPassportNumber()
{
    cout << "Номер: ";
    cin >> passport_number;
    cout << "\n";
}
void Passeport::SetIssuedBy(string val)
{
    this->issuedBy = val;
}
void Passeport::SetIssuedBy()
{
    cout << "Выдан: ";
    cin >> issuedBy;
    cout << "\n";
}

std::ostream& operator<<(std::ostream& os, const Passeport& p)
{
    os << "Passport Info\n";
    os << "Full Name: " << p.full_name << "\n";
    os << "Date of Birth: " << p.birth_date.tm_mday << "." << p.birth_date.tm_mon + 1 << "." << p.birth_date.tm_year + 1900 << "\n";
    os << "Passport Number: " << p.passport_number << "\n";
    os << "Issued By: " << p.issuedBy << "\n";

    return os;
}