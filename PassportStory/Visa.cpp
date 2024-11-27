#pragma once
#include "Visa.h"
//#include "Header.h"
using namespace std;

Visa::Visa()
{
    SetDestination();
    SetIssueDate();
    SetExpiryDate();
}
Visa::Visa(string destination, tm issue, tm expiry)
{
    SetDestination(destination);
    SetIssueDate(issue);
    SetExpiryDate(expiry);
}
string Visa::GetDestination()
{
    return destination;
}
tm Visa::GetIssueDate()
{
    return issue_date;
}
tm Visa::GetExpiryDate()
{
    return expiry_date;
}
void Visa::SetDestination(string var)
{
    this->destination = var;
}
void Visa::SetDestination()
{
    cout << "Страна назначени: ";
    cin >> destination;
    cout << "\n";
}
void Visa::SetIssueDate(tm var)
{
    this->issue_date.tm_year = var.tm_year;
    this->issue_date.tm_mon = var.tm_mon;
    this->issue_date.tm_mday = var.tm_mday;
}
void Visa::SetIssueDate()
{
    cout << "Дата выдачи визы:\nДень: ";
    cin >> issue_date.tm_mday;
    cout << "\nМесяц: ";
    size_t m;
    cin >> m;    // можно проверить
    issue_date.tm_mon = m - 1;
    cout << "\nГод: ";    // можно проверить
    size_t y;
    cin >> y;
    issue_date.tm_year = y - 1900;
    cout << "\n";
}
void Visa::SetExpiryDate(tm var)
{
    this->expiry_date.tm_year = var.tm_year;
    this->expiry_date.tm_mon = var.tm_mon;
    this->expiry_date.tm_mday = var.tm_mday;
}
void Visa::SetExpiryDate()
{
    cout << "Срок действия визы:\nДень: ";
    cin >> expiry_date.tm_mday;
    cout << "\nМесяц: ";
    size_t m;
    cin >> m;    // можно проверить
    expiry_date.tm_mon = m - 1;
    cout << "\nГод: ";    // можно проверить
    size_t y;
    cin >> y;
    expiry_date.tm_year = y - 1900;
    cout << "\n";
}


ostream& operator<<(ostream& os, const Visa& v)
{
    os << "Visa Info\n";
    os << "Destination country: " << v.destination << "\n";
    os << "Issue Date: " << v.issue_date.tm_mday << "." << v.issue_date.tm_mon + 1 << "." << v.issue_date.tm_year + 1900 << "\n";
    os << "Expiry Date: " << v.expiry_date.tm_mday << "." << v.expiry_date.tm_mon + 1 << "." << v.expiry_date.tm_year + 1900 << "\n";
    return os;
}