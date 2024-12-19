#pragma once
#include "Figure.h"


class CubicBezier : public Figure
{
    Point start;
    Point control1;
    Point control2;
    Point end;
public:
    CubicBezier(char ch, double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4) : CubicBezier(ch, { x1,y1 }, { x2, y2 }, { x3, y3 }, { x4, y4 }) {}

    CubicBezier(char ch, Point start, Point control1, Point control2, Point end) :Figure(ch), start(start), control1(control1), control2(control2), end(end) {}
    Point GetStart() { return start; }
    Point GetControl1() { return control1; }
    Point GetControl2() { return control2; }
    Point GetEnd() override { return end; }
    Point GetLastControl()override{ return GetControl2(); }
    void SetStart(Point val) { start = val; }
    void SetStart(double x, double y) { SetStart({ x,y }); }

    void SetControl1(Point val) { control1 = val; }
    void SetControl1(double x, double y) { SetControl1({ x,y }); }

    void SetControl2(Point val) { control2 = val; }
    void SetControl2(double x, double y) { SetControl2({ x,y }); }

    void SetEnd(Point val) { end = val; }
    void SetEnd(double x, double y) { SetEnd({ x,y }); }
    void IncreaseControl1(double xval, double yval)
    {
        this->control1.x += xval;
        this->control1.y += yval;
    }
    void IncreaseControl1(Point val)
    {
        this->control1.x += val.x;
        this->control1.y += val.y;
    }
    void IncreaseControl2(double xval, double yval)
    {
        this->control2.x += xval;
        this->control2.y += yval;
    }
    void IncreaseControl2(Point val)
    {
        this->control2.x += val.x;
        this->control2.y += val.y;
    }
    void IncreaseEnd(double xval, double yval)
    {
        this->end.x += xval;
        this->end.y += yval;
    }
    void IncreaseEnd(Point val)
    {
        this->end.x += val.x;
        this->end.y += val.y;
    }
    vector<Point>GetCubicBezierPoints(Point start, Point control1, Point control2, Point end, int precision_count = 100)
    {
        vector<Point> points;
        double t;
        for (int i = 0; i < precision_count; i++)
        {
            t = static_cast<double> (i) / precision_count;
            double x = pow(1 - t, 3) * start.x + 3 * pow(1 - t, 2) * t * control1.x + 3 * (1 - t) * pow(t, 2) * control2.x + pow(t, 3) * end.x;
            double y = pow(1 - t, 3) * start.y + 3 * pow(1 - t, 2) * t * control1.y + 3 * (1 - t) * pow(t, 2) * control2.y + pow(t, 3) * end.y;
            points.push_back({ x, y });
        }
        return points;
    }
    void Draw(HDC& hdc, double scale, int mx = 0, int my = 0)override
    {
        vector<Point> p = GetCubicBezierPoints(start, control1, control2, end);
        for (Point point : p)
        {
            SetPixel(hdc, point.x * scale + mx, point.y * scale + my, RGB(255, 255, 255));
        }
    }
};