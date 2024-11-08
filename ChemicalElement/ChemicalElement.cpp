#pragma once
#include <iostream>
#include <string.h>
#include <string>
#include <filesystem>
#include <fstream>
#include <stdio.h>
using namespace std;

class Element
{  
    Element();
public:   
    enum class Origin{UNDEFINED=0, GREEK, INDIA, PERSIAN, LATIN};
    enum class PHASE{ UNDEFINED = 0, GAS, SOLID, LIQUID};
    
    //block
    float atomic_weight;          // ������������� ������� �����
    float* density = nullptr;                // ���������
    float* melting_point = nullptr;          // ����������� ���������
    float* boiling_point = nullptr;          // ����������� �������
    float* specific_heat_capacity = nullptr; // �������� ������������
    float* electronegativity = nullptr;       // �������������������
    size_t atomic_number;          // ���������� ����� �������� � ���������� ��������
    size_t neutrons_number;        // ���������� ���������, ���� ���������� �� ���������, �� ������
    Origin name_origin;            // ������������� ��������
    PHASE phase;                   // ���������� ���������
    string name;                   // �������� ��������
    unsigned short group;          //  ������
    unsigned short period;         // ������
    string symbol;                 // ������ ��������

    

    Element(string, string, unsigned short, unsigned short, float, size_t, size_t, Origin, PHASE, float*, float*, float*, float*, float*);
    ~Element();
    // demo functions:
    void printElement();
    void meltElement();
    void boilElement();
    void freezeElement();
    Element* loadElement(ifstream&);
    Element** loadElements(string path, size_t&);


    friend ostream& operator<<(ostream& os, Element&);
};

ostream& operator<<(ostream& os, Element& el)
{
    os << "�������� ��������:\t" << el.name << "\n";
    os << "������ ��������:\t" << el.symbol << "\n";
    os << "������:\t\t\t" << el.group << "\n";
    os << "������:\t\t\t" << el.period << "\n";
    os << "�������. ������� �����:\t" << el.atomic_weight << "\n";
    os << "���������� �����:\t" << el.atomic_number << "\n";
    os << "���������� ���������:\t" << el.neutrons_number << "\n";
    os << "������������� ��������:\t";
    switch (el.name_origin)
    {
    case Element::Origin::GREEK:
	os << "���������\n";
	break;
    case Element::Origin::LATIN:
	os << "���������\n";
	break;
    case Element::Origin::INDIA:
	os << "���������\n";
	break;
    case Element::Origin::UNDEFINED:
    default:
	os << "-\n";
	break;
    }
    os << "���������� ���������:\t";
    switch (el.phase)
    {
    case Element::PHASE::GAS:
	os << "������������\n";
	break;
    case Element::PHASE::LIQUID:
	os << "������\n";
	break;
    case Element::PHASE::SOLID:
	os << "�������\n";
	break;
    case Element::PHASE::UNDEFINED:
    default:
	os << "-\n";
	break;
    }

    os << "�������� ������������:\t";
     el.density == nullptr ? os <<"-": os << *el.density;
     os << "\n";
     os << "����������� ���������:\t";
     el.melting_point == nullptr ? os << "-" : os << *el.melting_point;
     os<<"\n";
     os << "����������� �������:\t";
     el.boiling_point == nullptr ? os << "-" : os << *el.boiling_point;
     os << "\n"; 
    os << "�������� ������������:\t";
    el.specific_heat_capacity == nullptr ? os << "-" : os << *el.specific_heat_capacity;
    os << "\n";  
    os << "�������������������:\t";
    el.electronegativity == nullptr ? os << "-" : os << *el.electronegativity;
    os << "\n"; 
    return os;
}
Element::Element(string name, string symbol, unsigned short group, unsigned short period, float atomic_weight, size_t atomic_number, size_t neutrons_number, Origin name_origin, PHASE phase, float* density = nullptr, float* melting_point = nullptr, float* boiling_point = nullptr, float* specific_heat_capacity = nullptr, float* electronegativity = nullptr)
{
    this->name = name;
    this->symbol = symbol;
    this->group = group;
    this->period = period;
    this->atomic_weight = atomic_weight;
    this->atomic_number = atomic_number;
    this->neutrons_number = neutrons_number;
    this->name_origin = name_origin;
    this->phase = phase;
    this->density = density;
    this->melting_point = melting_point;
    this->boiling_point = boiling_point;
    this->specific_heat_capacity = specific_heat_capacity;
    this->electronegativity = electronegativity;
}

Element::~Element()
{
    if (density != nullptr)
    {
	delete density;
	density = nullptr;
    }
    if (melting_point != nullptr)
    {
	delete melting_point;
	melting_point = nullptr;
    }
    if (boiling_point != nullptr)
    {
	delete boiling_point;
	boiling_point = nullptr;
    }
    if (specific_heat_capacity != nullptr)
    {
	delete specific_heat_capacity;
	specific_heat_capacity = nullptr;
    }
    if (electronegativity != nullptr)
    {
	delete electronegativity;
	electronegativity = nullptr;
    }     
}
void Element::printElement()
{
    cout << *this<<"\n";
}
void Element::boilElement()
{
    cout << "The element " << name << " is boiling!!...\n\n";
    phase = PHASE::LIQUID;
}
void Element::freezeElement()
{
    cout << "The element " << name << " is freezing!!...\nThe temperature has been dropped to " << 23 << "!\n\n";
    phase = PHASE::SOLID;
}
void Element::meltElement()
{
    cout << "The element " << name << " is melting!!...\n\n";
    phase = PHASE::LIQUID;
}
Element* Element::loadElement(ifstream& reader)
{ 
    Element* ret = nullptr;
    size_t atomic_number; 
    string symbol;
    string name;    
    Element::Origin name_origin; 
    unsigned short group;          //  ������
    unsigned short period;
    float atomic_weight;          // ������������� ������� �����
    float* density = nullptr;                // ���������
    float* melting_point = nullptr;          // ����������� ���������
    float* boiling_point = nullptr;          // ����������� �������
    float* specific_heat_capacity = nullptr; // �������� ������������
    float* electronegativity = nullptr;       // �������������������    
    Element::PHASE phase;   //size_t neutrons_number;        

    reader >> atomic_number >> symbol >> name;
    string temp;
    reader >> temp;
    if (temp == "Greek")
	name_origin = Element::Origin::GREEK;
    else  if (temp == "Latin")
	name_origin = Element::Origin::LATIN;
    else  if (temp == "India")
	name_origin = Element::Origin::INDIA;
    else  if (temp == "Persian")
	name_origin = Element::Origin::PERSIAN;
    else
	name_origin = Element::Origin::UNDEFINED;

    reader >> group >> period >> atomic_weight;
    
    reader >> temp;
    if (temp != "underfined")
     density = new float(std::stof(temp));

    reader >> temp;
    if (temp != "underfined")
	melting_point = new float(std::stof(temp));

    reader >> temp;
    if (temp != "underfined")
	boiling_point = new float(std::stof(temp));

    reader >> temp;
    if (temp != "underfined")
	specific_heat_capacity = new float(std::stof(temp));

    reader >> temp;
    if (temp != "underfined")
	electronegativity = new float(std::stof(temp));

    reader >> temp;
    if (temp == "GAS")
	phase = Element::PHASE::GAS;
    else  if (temp == "SOLID")
	phase = Element::PHASE::SOLID;
    else  if (temp == "LIQUID")
	phase = Element::PHASE::LIQUID;
    else
	phase = Element::PHASE::UNDEFINED;

    return new Element(name, symbol, group, period, atomic_weight, atomic_number, atomic_number, name_origin, phase, density, melting_point, boiling_point, specific_heat_capacity, electronegativity);
}
Element** Element::loadElements(string path, size_t& count)
{
    std::ifstream reader(path);
    if (reader)
    {
	reader >> count;	// ������� �������� ���������� ���� ��������� � �����
	
	Element** ret = new Element*[count];
	for (int i = 0; i < count && !reader.eof(); i++)
		ret[i] = loadElement(reader);             // � �������� ����� ������ ��� ����������� �� ������ ���� ��������
	reader.close();

	return ret;
    }    
    else
	throw("file is not openned.");
}

int main()
{
    setlocale(0, "");
    
    { // �������� ������ �����������
	Element el((string)"Hydrogen", (string)"H", 1, 1, 1.008f, 1, 1, Element::Origin::GREEK, Element::PHASE::GAS, new float(0.00008988f), new float(14.01f));
	cout << el << "\n";

	el.printElement();

	el.meltElement();
	el.printElement();

	el.boilElement();
	el.printElement();

	el.freezeElement();
	el.printElement();
	string path = "D:\\c++\\C++_24\\projects_24\\OOP_homework\\ChemicalElement\\elements.txt";
	size_t size;
	Element** el_array = el.loadElements(path, size);
	for (size_t i = 0; i < size; i++)
	{
	    cout << "\n*********************\n";
	    cout << *el_array[i];
	}
	delete[]el_array;
    }
    
    cout<<"the end!"; // �������� ������� ������������ ������ � ������� ���������
    return 0;

}
