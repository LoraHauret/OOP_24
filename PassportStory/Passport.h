#pragma once
//#include "Header.h"
#include "Visa.h"
using namespace std;

class Passeport {
    string full_name;
    tm birth_date;
    size_t passport_number;
    string issuedBy;

public:
    Passeport();
    Passeport(string fullName, tm dateOfBirth, size_t passportNumber, string issuedBy);
    string GetFullName();
    tm GetBirthDate();
    size_t GetPassportNumber();
    string GetIssuedBy();
    void SetFullName(string);		    
    void SetFullName();
    void SetBirthDate(tm);		        
    void SetBirthDate();
    void SetPassportNumber(size_t);	        
    void SetPassportNumber();
    void SetIssuedBy(string);	
    void SetIssuedBy();

    friend ostream& operator<<(ostream& os, const Passeport& p);

};


