#pragma once
#include <cmath>
#include "Figure.h"
#define M_PI 3.14159265358979323846


/*rx — радиус по оси X.
ry  — радиус по оси Y.
x axisrotation без поворота эллипса.
large arc flag — малая дуга(менее 180 градусов).
sweep-flag— рисование в отрицательном направлении.
x  — конечная точка по оси X.
y — конечная точка по оси Y*/

class ArcF : public Figure
{
    Point start;
    double rx;
    double ry;
    double xAxisRotation;
    bool largeArcFlag;
    bool sweepFlag;
    Point end;
public:
    Point GetLastControl()override { return { -1, -1 }; }
    ArcF() { ; }
    ArcF(char ch, double x1, double y1, double rx, double ry, double xAxisRotation, bool largeArcFlag, bool sweepFlag, double x2, double y2) : ArcF(ch, { x1, y1 }, rx, ry, xAxisRotation, largeArcFlag, sweepFlag, { x2, y2 }) {}
     ArcF(char ch, Point start, double rx, double ry, double xAxisRotation, bool largeArcFlag, bool sweepFlag, Point end) : Figure(ch), start(start), rx(rx), ry(ry), xAxisRotation(xAxisRotation), largeArcFlag(largeArcFlag), sweepFlag(sweepFlag), end(end) {}
    Point GetStart() { return start; }
    double GetRX() { return rx; }
    double GetRY() { return ry; }
    double GetxAxisRotation() { return xAxisRotation; }
    bool GetLargeArcFlag() { return largeArcFlag; }
    bool GetSweepFlag() { return sweepFlag; }
    Point GetEnd() override { return end; }
    void SetStart(Point val) { this->start.x = val.x; this->start.y = val.y; }
    void SetStart(double x, double y) { SetStart({ x,y }); }
    void SetRX(double rx) { this->rx = rx; }
    void SetRY(double ry) { this->ry = ry; }
    void SetxAxisRotation(double val) { this->xAxisRotation = val; }
    void SetLargeArcFlag(bool val) { largeArcFlag = val; }
    void SetSweepFlag(bool val) { sweepFlag = val; }
    void SetEnd(Point val) { this->end.x = val.x; this->end.y = val.y; }
    void IncreaseStart(double xval, double yval)
    {
        this->start.x += xval;
        this->start.y += yval;
    }
    void IncreaseStart(Point val)
    {
        this->start.x += val.x;
        this->start.y += val.y;
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

    double toRadians(double angle) {
        return angle * M_PI / 180.0;
    }
    vector<Point> GetArcPoints(Point start, Point end, double rx, double ry,
        double xAxisRotation, bool largeArcFlag, bool sweepFlag, int numPoints = 100)
    {
        vector<Point> points;

        double rotation = toRadians(xAxisRotation); // в радианы


        double cx = (start.x + end.x) / 2.0; // центр эллипса (зависит от start, end, rx, ry и флагов)
        double cy = (start.y + end.y) / 2.0;


        double startAngle = atan2(start.y - cy, start.x - cx); // углы начала и конца дуги
        double endAngle = atan2(end.y - cy, end.x - cx);


        if (!sweepFlag && endAngle > startAngle)  // коррекция углов в зависимости от флагов
        {
            endAngle -= 2 * M_PI;
        }
        if (sweepFlag && endAngle < startAngle)
        {
            endAngle += 2 * M_PI;
        }
        if (largeArcFlag)
        {
            if (sweepFlag)
            {
                if (endAngle - startAngle < M_PI) endAngle += 2 * M_PI;
            }
            else
            {
                if (startAngle - endAngle < M_PI) startAngle += 2 * M_PI;
            }
        }


        for (int i = 0; i <= numPoints; i++) // нахождение точек 
        {
            double t = static_cast<double>(i) / numPoints;
            double angle = startAngle + t * (endAngle - startAngle);


            double xLocal = rx * cos(angle); // координаты в локальной системе
            double yLocal = ry * sin(angle);

            double x = cos(rotation) * xLocal - sin(rotation) * yLocal + cx; // координаты в глобальной системе
            double y = sin(rotation) * xLocal + cos(rotation) * yLocal + cy;

            points.push_back({ x, y });
        }

        return points;
    }
    void Draw(HDC& hdc, double scale, int mx = 0, int my = 0)override
    {
        vector<Point> p = GetArcPoints(start, end, rx, ry, xAxisRotation, largeArcFlag, sweepFlag, 100);
        for (Point point : p)
        {
            SetPixel(hdc, point.x * scale + mx, point.y * scale + my, RGB(255, 255, 255));
        }
    }
};