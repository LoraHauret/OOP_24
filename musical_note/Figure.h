#pragma once
#include <iostream>
#include <windows.h>
#include <vector>
#include <fstream>
#include <regex>
#include <string>
#include <iomanip> 
#include "Point.h"

using namespace std;

class Figure
{
    char ch = 0;
public:
    Figure() {}
    Figure(char ch) :ch(ch) {}
    char GetChar()
    {
        return ch;
    }
    void SetChar(char ch)
    {
        this->ch = ch;
    }
    virtual Point GetLastControl() = 0;
    virtual Point GetEnd() = 0;
    virtual void Draw(HDC& hdc, double scale, int mx = 0, int my = 0) = 0;
};
