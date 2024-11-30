#pragma once
#include "Device.h"
using namespace std;

class PortableHD : public Device
{
    vector<string> paths; 

public:
    PortableHD() : Device() {}
    PortableHD(string, string, string, float, int, string);
    void Load()const override;
    void Save() override;//const
    void CreateFile(string filepath)override;
    void Print() override;
};
