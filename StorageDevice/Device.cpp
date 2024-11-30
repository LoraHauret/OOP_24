#pragma once
#include "Device.h"

ostream& operator<<(ostream& os, Device& d)
{
    os << "\nНаименование: " << d.name << "\nМодель: " << d.model << "\nПроизводитель: " << d.manufactor << "\nОбъем памяти: " << d.capacity << "\nКоличество: " << d.count << "\n";
    return os;
}


Device::Device()
{
    SetName();
    SetModel();
    SetManufactor();
    SetCapacity();
    SetCount();
    SetDirectory();
}

Device::Device(const string n, const string m, const string manuf, float c, int cnt, string d)
{
    SetName(n);
    SetModel(m);
    SetManufactor(manuf);
    SetCapacity(c);
    SetCount(cnt);
    if (d == "")
	SetDirectory();
    else
	SetDirectory(d);
}

string Device::GetName() const
{
    return name;
}
string Device::GetModel() const
{
    return model;
}
string Device::GetManufactor() const
{
    return manufactor;
}
float Device::GetCapacity() const
{
    return capacity;
}
int Device::GetCount()
{
    return count;
}
//bool Device::IsDir()
//{
//    struct stat info;
//    if (stat(dir.c_str(), &info) == 0 && (info.st_mode & S_IFDIR))
//	return true;
//    return false;
//}
string Device::GetDir()
{
    return dir;
}
void Device::SetName()
{

}
void Device::SetName(const string val)
{
    name = val;
}
void Device::SetModel()
{

}
void Device::SetModel(const string val)
{
    model = val;
}
void Device::SetManufactor()
{

}
void Device::SetManufactor(const string val)
{
    manufactor = val;
}
void Device::SetCapacity()
{

}
void Device::SetCapacity(float val)
{
    capacity = val;
}
void Device::SetCount()
{

}
void Device::SetCount(int val)
{
    count = val;
}
void Device::SetDirectory(string val)
{
    //if (IsDir() == false && dir!= val)
    dir = val;
    //if (_mkdir(dir.c_str()) == 0)
    if (dir.length())
	cout << "\nУстройство определено. Название: " << dir << "\n";
    else
	cout << "\nУстройство не определено\n";
}
void Device::SetDirectory()
{
    string d = ".\\HD" + name + model + "\\";
    SetDirectory(d);
}

//void Device::load()const
//{
//
//}