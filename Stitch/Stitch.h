﻿#pragma once
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
    Stitch(string en, string ru, string path, Type t = Stitch::Type::BASIC, Application app = Stitch::Application::CROCHETING, string description = "описание", string impl_tech = "техника выполнения");
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