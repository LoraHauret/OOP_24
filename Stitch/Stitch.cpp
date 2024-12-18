﻿#include "Stitch.h"
int Stitch::count_all_stitches = 0;

Stitch::Stitch(string en, string ru, string path, Type t, Application app, string description, string impl_tech, Stitch::SHERE shere)
{
    set_name_en (en);
    set_name_ru(ru);
    set_img_path (path);
    set_type(t);
    set_zone_appl(app);
    set_description(description);
    set_implementation_technique (impl_tech);
    set_shere(shere);
    fillCommands();
    ++count_all_stitches;
}

Stitch::Stitch(const Stitch& other)
{
    set_name_en(other.name_en);
    set_name_ru(other.name_ru);
    set_img_path(other.img_path);
    set_type(other.type);
    set_zone_appl(other.zone_appl);
    set_description(other.description);
    set_implementation_technique(other.implementation_technique);
    set_shere(other.shere);
    set_start_pos(other.start_pos.X, other.start_pos.Y);
    fillCommands();
    ++count_all_stitches;
}
Stitch::Stitch(Stitch&& other)
{
    set_name_en(other.name_en);
    set_name_ru(other.name_ru);
    set_img_path(other.img_path);
    set_type(other.type);
    set_zone_appl(other.zone_appl);
    set_description(other.description);
    set_implementation_technique(other.implementation_technique);
    set_shere(other.shere);
    for (int i = 0; i < other.commands.size(); i++)
    {
	this->commands.push_back(other.commands[i]);
	delete other.commands[i];
	other.commands[i] = nullptr;
    }
    other.commands.clear();
}
Stitch::~Stitch() 
{
    --count_all_stitches;
    if (!commands.empty())
    {
	if (commands.size() > 0)
	{
	    for (int i = 0; i < commands.size(); i++)
	    {
		delete commands[i];
		commands[i] = nullptr;
	    }
	    commands.clear();
	}
    }
}
void Stitch::set_start_pos(int x, int y)
{
    this->start_pos.X = x;
    this->start_pos.Y = y;
}
//void Stitch::drawStitch()
//{
//    cout << "The stitch is drawing using the picture path \"" 
//<< this->img_path << "\"...\n";
//}

void Stitch::moveStitchX(int h)
{
    moveStitch(h, 0);
}
void Stitch::moveStitchY(int v)
{
    moveStitch(0, v);
}
void Stitch::moveStitch(int hpos, int vpos)
{
    this->start_pos.X += hpos;
    this->start_pos.Y += vpos;
}
void Stitch::moveStitch(int val)
{
    this->start_pos.X += val;
    this->start_pos.Y += val;
}
void Stitch::fillCommands()
{
    if (!img_path.empty())
    {
	string text = drawingSvg::GetAllText(img_path);
	regex com_regex("-?\\d*\\.\\d+|-?\\d+"); // Все варианты числа типа дабл
	string commands_line = "MLCSQTAZHVmlcsqtazhv";
	vector<string> command_strings = drawingSvg::GetStringLines(text, commands_line);
	vector<CMD> cmds = drawingSvg::GetCommands(command_strings, com_regex);
	commands = drawingSvg::GetCommands(cmds);
	drawingSvg::RecountCoord(commands);
    }
}
void Stitch::drawStitch(HDC hdc, float scale)
{
    //string text = drawingSvg::GetAllText(img_path);
    //regex com_regex("-?\\d*\\.\\d+|-?\\d+"); // Все варианты числа типа дабл
    //string commands_line = "MLCSQTAZHVmlcsqtazhv";
    //vector<string> command_strings = drawingSvg::GetStringLines(text, commands_line);
    //vector<CMD> cmds = drawingSvg::GetCommands(command_strings, com_regex);
    //commands = drawingSvg::GetCommands(cmds);
    //drawingSvg::RecountCoord(commands);
    drawingSvg::DrawSVG(hdc, commands, scale, start_pos.X, start_pos.Y);
}
void Stitch::printStitchInfo()
{
    cout << *this << "\n";
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
    os << "Путь к файлу:\t\t" << s.img_path << "\n";
    os << "Тип:\t\t\t" << s.type;
    os << "Зона применения:\t" << s.zone_appl;
    os << "Описание:\t\t" << s.description << "\n";
    os << "Техника выполнения:\t" << s.implementation_technique << "\n";
    os << "Начальные координаты:\t{" << s.start_pos.X << ", " << s.start_pos.Y << "}\n";
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
const Stitch::SHERE Stitch::get_shere()
{
    return this->shere;
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

void Stitch::set_shere(SHERE shere)
{
    this->shere = shere;
}

bool Stitch::operator==(const Stitch& other)
{
    return this->name_en == other.name_en && this->name_ru == other.name_ru && this->type == other.type && this->zone_appl == other.zone_appl;
}
bool Stitch::operator!=(const Stitch& other)
{
    return !(*this == other);
}
bool Stitch::operator<(const Stitch& other)
{
    return this->shere < other.shere;
}
bool Stitch::operator>(const Stitch& other)
{
    return this->shere > other.shere;
}
bool Stitch::operator<=(const Stitch& other)
{
    return this->shere <= other.shere;
}
bool Stitch::operator>=(const Stitch& other)
{
    return this->shere >= other.shere;
}