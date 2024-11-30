#pragma once
#include "Device.h"

class SmartPh : public Device
{
    vector<string> paths;

public:
    SmartPh() : Device() {}
    SmartPh(string, string, string, float, int, string);
    void Load()const override;
    void Save() override;
    void CreateFile(string filepath)override;
    void Print() override;
};