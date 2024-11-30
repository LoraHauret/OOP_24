#pragma once
#include "Tablet.h"


Tablet::Tablet(string n, string m, string manuf, float c, int cnt, string d) : Device{ n, m, manuf, c, cnt, d }
{
}
void Tablet::Load()const
{
    Device::Load();
    for (int i = 0; i < paths.size(); i++)
	cout << i + 1 << ". " << paths[i] << "\n";
}
void Tablet::Save()
{
    cout << "Файлы на устройстве сохранены.";
}

void Tablet::CreateFile(string filepath)
{
    paths.push_back(dir + filepath);
}
void Tablet::Print()
{
    cout << "\nПланшет\n";
    Device::Print();
}