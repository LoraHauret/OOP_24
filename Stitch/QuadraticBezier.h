#pragma once
#include "Figure.h"

class QuadraticBezier : public Figure
{
    Point start;
    Point control;
    Point end;
public:
    QuadraticBezier(char ch, double x1, double y1, double x2, double y2, double x3, double y3) : QuadraticBezier(ch, { x1,y1 }, { x2, y2 }, { x3, y3 }) {}

    QuadraticBezier(char ch, Point start, Point control, Point end) :Figure(ch), start(start), control(control), end(end) {}
    Point GetStart() { return start; }
    Point GetControl() { return control; }
    Point GetEnd()override { return end; }
    Point GetLastControl()override { return GetControl(); }

    void SetStart(Point val) { start = val; }
    void SetStart(double x, double y) { SetStart({ x,y }); }
    void SetControl(Point val) { control = val; }
    void SetControl(double x, double y) { SetControl({ x,y }); }
    void SetEnd(Point val) { end = val; }
    void SetEnd(double x, double y) { SetEnd({ x,y }); }
    void IncreaseControl(double xval, double yval)
    {
        this->control.x += xval;
        this->control.y += yval;
    }
    void IncreaseControl(Point val)
    {
        this->control.x += val.x;
        this->control.y += val.y;
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
    vector<Point>GetQuadraticBezierPoints(Point start, Point control1, Point end, int precision_count = 100)
    {
        vector<Point> points;
        double t;
        for (int i = 0; i < precision_count; i++)
        {
            t = static_cast<double> (i) / precision_count;
            double x = pow(1 - t, 2) * start.x + 2 * (1 - t) * t * control1.x + pow(t, 2) * end.x;
            double y = pow(1 - t, 2) * start.y + 2 * (1 - t) * t * control1.y + pow(t, 2) * end.y;
            points.push_back({ x, y });
        }
        return points;
    }

    void Draw(HDC& hdc, double scale, int mx = 0, int my = 0)override
    {
        vector<Point> p = GetQuadraticBezierPoints(start, control, end);
        for (Point point : p)
        {
            SetPixel(hdc, point.x * scale + mx, point.y * scale + my, RGB(255, 255, 255));
        }
    }
};
