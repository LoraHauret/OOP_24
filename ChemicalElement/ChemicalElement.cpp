#pragma once
#include "ChemicalElement.h"

ostream& operator<<(ostream& os, Element& el)
{
    os << "название элемента:\t" << el.name << "\n";
    os << "символ элемента:\t" << el.symbol << "\n";
    os << "группа:\t\t\t" << el.group << "\n";
    os << "период:\t\t\t" << el.period << "\n";
    os << "относит. атомная масса:\t" << el.atomic_weight << "\n";
    os << "порядковый номер:\t" << el.atomic_number << "\n";
    os << "количество нейтронов:\t" << el.neutrons_number << "\n";
    os << "происхождение названия:\t";
    switch (el.name_origin)
    {
    case Element::Origin::GREEK:
	os << "греческое\n";
	break;
    case Element::Origin::LATIN:
	os << "латинское\n";
	break;
    case Element::Origin::INDIA:
	os << "индийское\n";
	break;
    case Element::Origin::UNDEFINED:
    default:
	os << "-\n";
	break;
    }
    os << "агрегатное состояние:\t";
    switch (el.phase)
    {
    case Element::PHASE::GAS:
	os << "газообразное\n";
	break;
    case Element::PHASE::LIQUID:
	os << "жидкое\n";
	break;
    case Element::PHASE::SOLID:
	os << "твердое\n";
	break;
    case Element::PHASE::UNDEFINED:
    default:
	os << "-\n";
	break;
    }

    os << "удельная теплоемкость:\t";
    el.density == nullptr ? os << "-" : os << *el.density;
    os << "\n";
    os << "температура плавления:\t";
    el.melting_point == nullptr ? os << "-" : os << *el.melting_point;
    os << "\n";
    os << "температура кипения:\t";
    el.boiling_point == nullptr ? os << "-" : os << *el.boiling_point;
    os << "\n";
    os << "удельная теплоемкость:\t";
    el.specific_heat_capacity == nullptr ? os << "-" : os << *el.specific_heat_capacity;
    os << "\n";
    os << "электронегативность:\t";
    el.electronegativity == nullptr ? os << "-" : os << *el.electronegativity;
    os << "\n";
    return os;
}
Element::Element(string name, string symbol, unsigned short group, unsigned short period, float atomic_weight, size_t atomic_number, size_t neutrons_number, Origin name_origin, PHASE phase, const float* density, const  float* melting_point, const  float* boiling_point, const  float* specific_heat_capacity, const float* electronegativity)
{
    set_name(name);
    set_symbol(symbol);
    set_group(group);
    set_period(period);
    set_atomic_weight(atomic_weight);
    set_atomic_number(atomic_number);
    set_neutrons_number(neutrons_number);
    set_name_origin(name_origin);
    set_phase(phase);
    if (density != nullptr)
	set_density(*density);
    else
	set_density(0);
    if (melting_point != nullptr)
	set_melting_point(*melting_point);
    else
	set_melting_point(0);
   if(boiling_point != nullptr)
     set_boiling_point(*boiling_point);
   else
       set_boiling_point(0);
   if(specific_heat_capacity !=0)
	set_specific_heat_capacity(*specific_heat_capacity);
   else 
       set_specific_heat_capacity(0);
   if(electronegativity !=0)
       set_electronegativity(*electronegativity);
   else
       set_electronegativity(0);
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
    cout << *this << "\n";
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
    unsigned short group;          //  группа
    unsigned short period;
    float atomic_weight;          // относительная атомная масса
    float* density = nullptr;                // плотность
    float* melting_point = nullptr;          // температура плавления
    float* boiling_point = nullptr;          // температура кипения
    float* specific_heat_capacity = nullptr; // удельная теплоемкость
    float* electronegativity = nullptr;       // электронегативность    
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
    if (temp != "undefined")
	density = new float(std::stof(temp));

    reader >> temp;
    if (temp != "undefined")
	melting_point = new float(std::stof(temp));

    reader >> temp;
    if (temp != "undefined")
	boiling_point = new float(std::stof(temp));

    reader >> temp;
    if (temp != "undefined")
	specific_heat_capacity = new float(std::stof(temp));

    reader >> temp;
    if (temp != "undefined")
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
    
   Element* el = new Element(name, symbol, group, period, atomic_weight, atomic_number, atomic_number, name_origin, phase, density, melting_point, boiling_point, specific_heat_capacity, electronegativity);
   cout << *el;
   return el;
}
Element** Element::loadElements(string path, size_t& count)
{
    std::ifstream reader(path);
    if (reader)
    {
	reader >> count;	// вначале записано количество всех элементов в файле

	Element** ret = new Element * [count];
	for (int i = 0; i < count && !reader.eof(); i++)
	    ret[i] = loadElement(reader);             // в открытом файле курсор уже переставлен на первое поле элемента
	reader.close();

	return ret;
    }
    else
	throw("file is not openned.");
}

////////////////////геттеры////////////////////////////////

const float& Element::get_atomic_weight()
{
    return atomic_weight;
}
const float& Element::get_density()
{
    return *density;
}
const float& Element::get_melting_point()
{
    return *melting_point;
}
const float& Element::get_boiling_point()
{
    return *boiling_point;
}
const float& Element::get_specific_heat_capacity()
{
    return *specific_heat_capacity;
}
const float& Element::get_electronegativity()
{
    return *electronegativity;
}
const size_t& Element::get_atomic_number()
{
    return atomic_number;
}
const size_t& Element::get_neutrons_number()
{
    return neutrons_number;
}
Element::Origin Element::get_name_origin()
{
    return name_origin;
}
Element::PHASE	Element::get_phase()
{
    return phase;
}
const string& Element::get_name()
{
    return name;
}
const unsigned short& Element::get_group()
{
    return group;
}
const unsigned short& Element::get_period()
{
    return period;
}
const string& Element::get_symbol()
{
    return symbol;
}

//////////////сеттеры/////////////////////////////

void Element::set_atomic_weight(const float& val)
{
    this->atomic_weight = val;
}
void Element::set_density(const float& val)
{
    this->density = new float(val);
}
void Element::set_melting_point(const float& val)
{
    this->melting_point = new float(val);
}
void Element::set_boiling_point(const float& val )
{ 
        this->boiling_point = new float(val);
}
void Element::set_specific_heat_capacity(const float& val)
{
	this->specific_heat_capacity = new float( val);
}
void Element::set_electronegativity(const float& val)
{
	this->electronegativity = new float(val);
}
void Element::set_atomic_number(const size_t& val = 0)
{
    this->atomic_number = val;
}
void Element::set_neutrons_number(const size_t& val = 0)
{
    this->neutrons_number = val;
}
void Element::set_name_origin(const Origin  val)
{
    this->name_origin = val;
}
void Element::set_phase(const PHASE  val)
{
    this->phase = val;
}
void Element::set_name(const string& val)
{
    this->name = name;
}
void Element::set_group(const unsigned short& val)
{
    this->group = val;
}
void Element::set_period(const unsigned short& val)
{
    this->period = val;
}
void Element::set_symbol(const string& val)
{
    this->symbol = val;
}
