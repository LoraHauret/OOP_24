#pragma once
#include "Tablet.h"
#include "SmartPh.h"
#include "PortableHD.h"

using namespace std;

class Store
{
    vector<Device*> devices;
public:
    bool IsIndexCorrect(int ind)
    {
	if (ind < 0 || ind >= devices.size())
	{
	    cout << "�������� ������. ����� ������� �����������.\n";
	    return false;	
	}
	return true;
	   
    }
    void AddDevice(Device* dev)
    {
	devices.push_back(dev);
    }
    ~Store()
    {
	for (int i = 0; i < devices.size(); i++)
	    delete devices[i];
	devices.clear();
    }

    void Print()
    {
	for (int i = 0; i < devices.size(); i++)
	{
	    cout << "��� ����������: " << typeid(devices[i]).name() << "\n";
	    devices[i]->Print();
	}
    }
    void LoadDevice(int ind)
    {
	ind -= 1;
	if (IsIndexCorrect(ind))
	    devices[ind]->Load();
	else
	    cout << "�������� ������. ����� ������� �����������.\n";
	
    }
    void LoadDevices()
    {
	for (int i = 0; i < devices.size(); i++)
	{
	    devices[i]->Load();
	}
    }

    void SaveDevice(int ind)
    {
	ind -= 1;
	if (IsIndexCorrect(ind))
	    devices[ind]->Save();
    }
    void SaveDevices()
    {
	for (int i = 0; i < devices.size(); i++)
	{
	    devices[i]->Save();
	}
    }

    void RemoveDevice(int ind) // ������������ ������ ������� ������, ������� � 1
    {
	ind -= 1;
	if (IsIndexCorrect(ind))
	{
	    delete devices[ind];
	    devices.erase(devices.begin() + (ind));
	}
    }

    void ModifyDeviceName(int ind, string name)
    {
	ind -= 1;
	if (IsIndexCorrect(ind))
	    devices[ind]->SetName(name);
    }

    void ModifyDeviceManufacture(int ind, string val)
    {
	ind -= 1;
	if (IsIndexCorrect(ind))
	    devices[ind]->SetManufactor(val);
    }
    void ModifyDeviceModel(int ind, string val)
    {
	ind -= 1;
	if (IsIndexCorrect(ind))
	    devices[ind]->SetModel(val);
    }
    void ModifyDeviceCapacity(int ind, float cap)
    {
	ind -= 1;
	if (IsIndexCorrect(ind))
	    devices[ind]->SetCapacity(cap);
    }
    void ModifyDeviceModel(int ind, int val)
    {
	ind -= 1;
	if (IsIndexCorrect(ind))
	    devices[ind]->SetCount(val);
    }
    void SearchByName(string val)
    {
	    for (int i = 0; i < devices.size(); i++)
	    {
		if (devices[i]->GetName() == val)
		{
		    cout << "������� ������� �� ������: " << i+1 << "\n";
		    devices[i]->Print();
		    return;
		}
	    }
	    cout << "������� �� �������\n";
    }
    void SearchByManufacture(string val)
    {
	bool isFound = false;
	for (int i = 0; i < devices.size(); i++)
	{
	    if (devices[i]->GetManufactor() == val)
	    {
		cout << "������� ������� �� ������: " << i + 1 << "\n";
		devices[i]->Print();
		cout << "\n";
		isFound = true;
	    }
	}
	if(!isFound)
	    cout << "������� �� �������\n";
    }
    void SearchByModel(string val)
    {
	bool isFound = false;
	for (int i = 0; i < devices.size(); i++)
	{
	    if (devices[i]->GetModel() == val)
	    {
		cout << "������� ������� �� ������: " << i + 1 << "\n";
		devices[i]->Print();
		cout << "\n";
		isFound = true;
	    }
	}
	if (!isFound)
	    cout << "������� �� �������\n";
    }
    void SearchByCapacity(float val)
    {
	bool isFound = false;
	for (int i = 0; i < devices.size(); i++)
	{
	    if (devices[i]->GetCapacity() == val)
	    {
		cout << "������� ������� �� ������: " << i + 1 << "\n";
		devices[i]->Print();
		cout << "\n";
		isFound = true;
	    }
	}
	if (!isFound)
	    cout << "������� �� �������\n";
    }

    void SearchByCount(int val)
    {
	bool isFound = false;
	for (int i = 0; i < devices.size(); i++)
	{
	    if (devices[i]->GetCount() == val)
	    {
		cout << "������� ������� �� ������: " << i + 1 << "\n";
		devices[i]->Print();
		cout << "\n";
		isFound = true;
	    }
	}
	if (!isFound)
	    cout << "������� �� �������\n";
    }
    
};