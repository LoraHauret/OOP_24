#pragma once
#include "ForeignPassport.h"
//#include "Header.h"
using namespace std;

ForeignPassport::ForeignPassport():Passeport()
{}

ForeignPassport::ForeignPassport(string fullName, tm dateOfBirth, size_t passportNumber, string issuedBy):Passeport(fullName, dateOfBirth, passportNumber, issuedBy)
{}

void ForeignPassport::AddVisa(const Visa& var)
{
    visas.push_back(var);
}


std::ostream& operator<<(std::ostream& os, const ForeignPassport& p)
{
    os << Passeport(p);
    for(int i = 0; i <p.visas.size(); i++)
	os << p.visas[i]<<"\n";

    return os;
}