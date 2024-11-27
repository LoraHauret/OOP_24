#pragma once
//#include "Header.h"
#include <string>
#include <ctime>
#include <iostream>
using namespace std;

class Visa
{
    string destination;
    tm issue_date;
    tm expiry_date;

public:
    Visa();
    Visa(string destination, tm issue, tm expiry);
    string GetDestination();
    tm GetIssueDate();
    tm GetExpiryDate();
    void SetDestination(string);
    void SetDestination();
    void SetIssueDate(tm);
    void SetIssueDate();
    void SetExpiryDate(tm);
    void SetExpiryDate();
    
    friend ostream& operator<<(ostream& os, const Visa& p);
};
