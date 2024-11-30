#pragma once
#include "PortableHD.h"


PortableHD::PortableHD(string n, string m, string manuf, float c, int cnt, string d) : Device{ n, m, manuf, c, cnt, d }
{
}
void PortableHD::Load()const
{
    Device::Load();
    for (int i = 0; i < paths.size(); i++)
	cout << i + 1 << ". " << paths[i] << "\n";
}
void PortableHD::Save()
{
    cout << "Файлы на устройстве сохранены.";

}

void PortableHD::CreateFile(string filepath)
{
    paths.push_back(dir + filepath);
}
void PortableHD::Print()
{
    cout << "\nВнешний жесткий диск/ бэкап\n";
    Device::Print();
}