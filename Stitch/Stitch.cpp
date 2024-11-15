#pragma once
#include <iostream>
#include <windows.h>

using namespace std;

class Stitch
{
private:
    Stitch();                                                        // закрываю конструктор. (мне не нужен экземпляр класса в неинициализированными основными полями)
public:
    enum Type { BASIC = 1, DECORATIVE, RELIEF, OPENWORK };	     // основная, декоративная, рельефная, ажурная
    enum Application { KNITTING = 1, CROCHETING };		     // вязание на спицах, вязание крючком
private:
    string name_en;						     // название петли на английском
    string name_ru;						     // название петли на русском
    string img_path;						     // путь к изображению петли
    Type type;							     // тип петли
    Application zone_appl;					     // область применения (крючок, спицы, в дальнейшем, возможно что-то еще)
    string description;					             // описание петли
    string implementation_technique;			             // инструкция по выполнению петли
    COORD start_pos{ 0,0 };
							     
public:
    Stitch(string, string, string, Type, Application, string, string);
    // demo functions:
    void drawStitch();
    //void drawStitch(HDC hdc);
    void printStitchInfo();
    void moveStitch(int);
    void moveStitch(int, int);
    void moveStitchX(int);
    void moveStitchY(int);

    const string& get_name_en();
    const string& get_name_ru();
    const string& get_img_path();
    Type get_type();
    Application get_zone_appl();
    const string& get_description();
    const string& get_implementation_technique();
    const COORD& get_start_pos();
    
    void set_name_en(const string&);
    void set_name_ru(const string&);
    void set_img_path(const string&);
    void set_type(const Type);
    void set_zone_appl(const Application);
    void set_description(const string&);
    void set_implementation_technique(const string&);
    void set_start_pos(const COORD&);
    

    friend ostream& operator<<(ostream& os, Stitch s);
}; 

Stitch::Stitch(string en, string ru, string path, Type t = Stitch::Type::BASIC, Application app = Stitch::Application::CROCHETING, string description = "описание", string impl_tech = "техника выполнения")
{
    this->name_en = en;
    this->name_ru = ru;
    this->img_path = path;
    this->type = t;
    this->zone_appl = app;
    this->description = description;
    this->implementation_technique = impl_tech;
}
void Stitch::drawStitch()
{
    cout << "The stitch is drawing using the picture path \""<<this->img_path<<"\"...\n";
}

void Stitch::moveStitchX(int h)
{
    moveStitch(h, 0);
}
void Stitch::moveStitchY(int v)
{
    moveStitch(0, v);
}
void Stitch::moveStitch(int h, int v)
{
    this->start_pos.X += h;
    this->start_pos.Y += v;
}
void Stitch::moveStitch(int val)
{
    this->start_pos.X += val;
    this->start_pos.Y += val;
}
//void Stitch::drawStitch(HDC hdc)
//{
//
//}
void Stitch::printStitchInfo()
{
    cout << *this<<"\n";
}

ostream& operator<<(ostream& os, Stitch::Application appl)
{
    switch (appl)
    {
    case 1:
	os << "вязание на спицах";
	break;
    case 2:
	os << "вязание крючком";
	break;
    default:
	os << " не определено";
	break;
    }
    os << "\n";
    return os;
}
ostream& operator<<(ostream& os, Stitch::Type type)
{
    switch (type)
    {
    case 1:
	os << "базовая\n";
	break;
    case 2:
	os << "декоративная\n";
	break;
    case 3:
	os << "рельефная\n";
	break;
    case 4:
	os << "ажурная\n";
	break;
    default:
	os << " не определен\n";
	break;
    }
    return os;
}
ostream& operator<<(ostream& os, Stitch s)
{
    os << "Английское название:\t" << s.name_en << "\n";
    os << "Русское название:\t" << s.name_ru << "\n";
    os<<"Путь к файлу:\t\t"<< s.img_path << "\n";
    os << "Тип:\t\t\t"<< s.type;	
    os << "Зона применения:\t"<<s.zone_appl;
    os << "Описание:\t\t" << s.description << "\n";
    os << "Техника выполнения:\t" << s.implementation_technique << "\n";
    os << "Начальные координаты:\t{" << s.start_pos.X << ", "<<s.start_pos.Y << "}\n";
    return os;
}

const string& Stitch::get_name_en()
{
    return name_en;
}
const string& Stitch::get_name_ru()
{
    return name_ru;
}
const string& Stitch::get_img_path()
{
    return img_path;
}
Stitch::Type Stitch::get_type()
{
    return type;
}
Stitch::Application Stitch::get_zone_appl()
{
    return zone_appl;
}
const string& Stitch::get_description()
{
    return description;
}
const string& Stitch::get_implementation_technique()
{
    return implementation_technique;
}
const COORD& Stitch::get_start_pos()
{
    return start_pos;
}

void Stitch::set_name_en(const string& val)
{
    name_en = val;
}

void Stitch::set_name_ru(const string& val)
{
    name_ru = val;
}

void Stitch::set_img_path(const string& val)
{
    img_path = val;
}

void Stitch::set_type(const Type val)
{
    type = val;
}

void Stitch::set_zone_appl(const Application val)
{
    zone_appl = val;
}

void Stitch::set_description(const string& val)
{
    description = val;
}

void Stitch::set_implementation_technique(const string& val)
{
    implementation_technique = val;
}

void Stitch::set_start_pos(const COORD& val)
{
    start_pos = val;
}


int main()
{
    setlocale(0, "");    
    Stitch st1(string("Chain stitch"), string("Воздушная петля"), string("./img/chain_stitch.svg"));
    st1.printStitchInfo();
    st1.drawStitch();
    st1.moveStitchX(2);
    st1.moveStitchY(3);
    st1.moveStitch(1, 1);
    st1.printStitchInfo();
    return 0;
}