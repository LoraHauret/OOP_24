#pragma once
#include "Device.h"

class Tablet : public Device
{
    vector<string> paths;

public:
    Tablet() : Device() {}
    Tablet(string, string, string, float, int, string);
    void Load()const override;
    void Save() override;
    void CreateFile(string filepath)override;
    void Print() override;
};