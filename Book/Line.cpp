#pragma once
#include "Line.h"

Point Line::GetLastControl() { return { -1, -1 }; }
Line::Line(char ch, double x1, double y1, double x2, double y2) :Figure(ch), start(x1, y1), end(x2, y2) {}
Line::Line(char ch, Point start, Point end) :Figure(ch), start(start), end(end) {}
Point Line::GetStart()
{
    return start;
}
Point Line::GetEnd()
{
    return end;
}
void Line::SetStart(double x, double y)
{
    this->start.x = x;
    this->start.y = y;
}
void Line::SetStart(Point p)
{
    this->start = p;
}

void Line::SetEnd(double x, double y)
{
    this->end.x = x;
    this->end.y = y;
}
void Line::SetEnd(Point p)
{
    this->end = p;
}
void Line::IncreaseEnd(double xval, double yval)
{
    this->end.x += xval;
    this->end.y += yval;
}
void Line::IncreaseEnd(Point val)
{
    this->end.x += val.x;
    this->end.y += val.y;
}
vector<Point> Line::GetLinePoints(Point start, Point end, int numPoints)
{
    vector<Point> points;
    double curX = start.x, curY = start.y;
    float moveX = (end.x - start.x) / numPoints;
    float moveY = (end.y - start.y) / numPoints;

    for (int i = 0; i < numPoints; i++)
    {
        points.push_back({ round(curX), round(curY) });
        curX += moveX;
        curY += moveY;
    }
    return points;
}
void Line::Draw(HDC& hdc, double scale, int mx, int my)
{
    vector<Point> p = GetLinePoints(start, end);
    for (Point point : p) {
        SetPixel(hdc, point.x * scale + mx, point.y * scale + my, RGB(255, 255, 255));
    }
}