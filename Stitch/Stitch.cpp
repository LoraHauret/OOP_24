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
	cout << "вязание на спицах";
	break;
    case 2:
	cout << "вязание крючком";
	break;
    default:
	cout << " не определено";
	break;
    }
    cout << "\n";
    return os;
}
ostream& operator<<(ostream& os, Stitch::Type type)
{
    switch (type)
    {
    case 1:
	cout << "базовая\n";
	break;
    case 2:
	cout << "декоративная\n";
	break;
    case 3:
	cout << "рельефная\n";
	break;
    case 4:
	cout << "ажурная\n";
	break;
    default:
	cout << " не определен\n";
	break;
    }
    return os;
}
ostream& operator<<(ostream& os, Stitch s)
{
    cout << "Английское название:\t" << s.name_en << "\n";
    cout << "Русское название:\t" << s.name_ru << "\n";
    cout<<"Путь к файлу:\t\t"<< s.img_path << "\n";
    cout << "Тип:\t\t\t"<< s.type;
    /*switch (s.type)
    {
    case 1:
	cout << "базовая\n";
	break;
    case 2:
	cout << "декоративная\n";
	break;
    case 3:
	cout << "рельефная\n";
	break;
    case 4:
	cout << "ажурная\n";
	break;
    default:
	cout << " не определен\n";
	break;
    }*/
	
    cout << "Зона применения:\t"<<s.zone_appl;
   /* switch(s.zone_appl)
    {
    case 1:
	cout << "вязание на спицах";
	break;
    case 2:
	cout << "вязание крючком";
	break;
    default:
	cout << " не определено";
	break;
    }
    cout<< "\n";*/
    cout << "Описание:\t\t" << s.description << "\n";
    cout << "Техника выполнения:\t" << s.implementation_technique << "\n";
    cout << "Начальные координаты:\t{" << s.start_pos.X << ", "<<s.start_pos.Y << "}\n";
    return os;
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