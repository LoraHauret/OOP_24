#pragma once
#include "Figure.h"


class Line : public Figure
{
    Point start;
    Point end;
public:
    Point GetLastControl()override;
    Line(char ch, double x1, double y1, double x2, double y2);
    Line(char ch, Point start, Point end);
    Point GetStart();
    Point GetEnd()override;
    void SetStart(double x, double y);
    void SetStart(Point p);
    void SetEnd(double x, double y);
    void SetEnd(Point p);
    void IncreaseEnd(double xval, double yval);
    void IncreaseEnd(Point val);
    vector<Point> GetLinePoints(Point start, Point end, int numPoints = 100);
    void Draw(HDC& hdc, double scale, int mx = 0, int my = 0)override;
};
