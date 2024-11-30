#pragma once
#include "SmartPh.h"

SmartPh::SmartPh(string n, string m, string manuf, float c, int cnt, string d) : Device{ n, m, manuf, c, cnt, d }
{
}
void SmartPh::Load()const
{
    Device::Load();
    for (int i = 0; i < paths.size(); i++)
	cout << i + 1 << ". " << paths[i] << "\n";
}
void SmartPh::Save()
{
    cout << "Файлы на устройстве сохранены.";
  
}
void SmartPh::CreateFile(string filepath)
{
    paths.push_back(dir + filepath);
 }
void SmartPh::Print()
{
    cout << "\nСмартфон\n";
    Device::Print();
}