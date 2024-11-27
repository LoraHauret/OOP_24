#pragma once
//#include "Header.h"
#include <vector>
#include "Passport.h"
#include "Visa.h"
using namespace std;


class ForeignPassport : Passeport
{
    vector<Visa> visas; 

public:
    ForeignPassport();
    ForeignPassport(string fullName, tm dateOfBirth, size_t passportNumber, string issuedBy);

    void AddVisa(const Visa&);

    friend ostream& operator<<(ostream& os, const ForeignPassport& p);
};

