#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <typeinfo>
//#include <filesystem>
//#include <fstream>
//#include <sys/stat.h>
#include <iterator>
#include <direct.h>

using namespace std;

class Device {
protected:
    string name;
    string model;
    string manufactor;
    float capacity;
    int count;
    string dir;

public:
    Device();
    Device(const string n, const string m, const string manuf, float c, int cnt, string d="");
    string GetName() const;
    string GetModel() const;
    string GetManufactor() const;
    float GetCapacity() const;
    int GetCount();
    //bool IsDir();
    string GetDir();
    void SetName();
    void SetName(const string);
    void SetModel();
    void SetModel(const string);
    void SetManufactor();
    void SetManufactor(const string);
    void SetCapacity();
    void SetCapacity(float);
    void SetCount();
    void SetCount(int);
    void SetDirectory();
    void SetDirectory(const string);
    virtual ~Device() = default; // чтобы при наличии указателя базового класса на потомка при уничтожении и освобождении ресурсов вызвало бы корректный веерный/ послойный вызов деструкторов потомков.
    virtual void Print()
    {
	cout << *this;
    }

    virtual void Load()const { cout << "\nФайлы на устройстве: \n"; }
    virtual void Save() {}//const
    virtual void CreateFile(string) {}
    friend ostream& operator<<(ostream&, Device&);

};
