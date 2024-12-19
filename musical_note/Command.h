#pragma once
#include "Figure.h"

class Command :public Figure
{
    Point point;
public:
    Point GetLastControl()override { return { -1, -1 }; }
    Command(char ch, double x, double y) :Command(ch, { x,y }) {}
    Command(char ch, Point var) :Figure(ch), point(var) {}
    Point GetPoint() { return point; }
    void SetPoint(double x, double y) { SetPoint({ x,y }); }
    void SetPoint(Point val) { point = val; }
    void IncreasePoint(double xval, double yval)
    {
        this->point.x += xval;
        this->point.y += yval;
    }
    void IncreasePoint(Point val)
    {
        this->point.x += val.x;
        this->point.y += val.y;
    }
    Point GetEnd() override { return point; }
    void Draw(HDC& hdc, double scale, int mx = 0, int my = 0)override {}
    
};
