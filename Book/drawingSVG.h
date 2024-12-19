#pragma once
// #include "Stitch.h"
#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include <regex>
#include <string>
#include <iomanip> 
#include "Command.h"
#include "Line.h"
#include "CubicBezier.h"
#include "QuadraticBezier.h"
#include "ArcF.h"

struct CMD {
    char ch;
    vector<double>param;
};
class drawingSvg
{
   // static string commands_line; // Все возможные команды для рисования
   // static regex com_regex; // Все варианты числа типа дабл
public:

    static string GetAllText(string path)
    {
        ifstream reader(path, ios::binary);
        if (reader)
        {
            reader.seekg(0, ios::end); // переместила курсор в конец файла. позиция даст количество символов в файле. 1 позиция = 1 байт(чар)
            streampos fsize = reader.tellg();
            int64_t buffer_size = static_cast<int64_t> (fsize);

            char* char_arr = new(nothrow) char[buffer_size];
            if (char_arr != nullptr) // если память выделилась
            {
                reader.seekg(0, ios::beg); // курсор в начало файла
                reader.read(char_arr, buffer_size); // счиитала содержимое файла в буфер
                reader.close();

                string svg_picture(char_arr, buffer_size);
                delete[] char_arr;

                int pos = svg_picture.find(" d=\""); // обрезаю начало и конец текста до интересующих значений
                if (pos != string::npos)
                {
                    svg_picture.erase(0, pos + strlen(" d=\""));
                }
                   pos = svg_picture.find(">");
                   if (pos != string::npos)
                   {
                       svg_picture.erase(pos);
                   }/**/

                return svg_picture;
            }
            else
            {
                cout << "file is not openned\n";
                return "";
            }

        }
    }
    static vector<string> GetStringLines(string& svg_picture, string command_line)
    {
        regex com_regex{ "-?\\d*\\.\\d+|-?\\d+" };
        vector<string> command_strings;
        string::iterator it = find_if(svg_picture.begin(), svg_picture.end(), [&command_line](char c) { return command_line.find(c) != string::npos; });
        string::iterator temp_it = it + 1; // !!!! возможен вылет. проверить потом
        while (temp_it != svg_picture.end())
        {
            temp_it = find_if(it + 1, svg_picture.end(), [&command_line](char c) { return command_line.find(c) != string::npos; });
            string temp_str = svg_picture.substr(it - svg_picture.begin(), temp_it - it);
            command_strings.push_back(temp_str);
            it = temp_it;
            if (temp_it != svg_picture.end())
                ++temp_it;
        }
        return command_strings;
    }
    /*  M / m — moveto (перемещение "перо" в новую точку).
        L / l — lineto (рисование линии).
        H / h - Horizontal Line To
        V / v - Vertical Line To
        C / c — curveto (кубическая кривая Безье).
        S / s — smooth curveto (гладкая кубическая кривая Безье).
        Q / q — quadratic Bezier curve (квадратичная кривая Безье).
        T / t — smooth quadratic Bezier curve (гладкая квадратичная кривая).
        A / a — elliptical Arc Curve (кривая с эллиптической дугой).
        Z / z — closepath (замыкание пути).
            */
    static vector<CMD> GetCommands(vector<string> command_strings, regex com_regex)
    {
        vector<CMD> commands;
        smatch match;
        for (int i = 0; i < command_strings.size(); i++)
        {
            CMD cmd;
            cmd.ch = command_strings[i][0];

            string input = command_strings[i];
            auto start = input.cbegin();
            auto end = input.cend();
            while (regex_search(start, end, match, com_regex))
            {
                double num = stod(match[0]);  // строка в double            
                cmd.param.push_back(num);
                start = match.suffix().first;  // передвигаю итератор после найденного числа
            }

            commands.push_back(cmd);
        }
        return commands;
    }
   
    static vector<Figure*> ParseLine(CMD c)
    {
        vector<Figure*> ret;
        if (c.param.size() > 0)
        {

            for (int i = 0; i < c.param.size(); i += 2)
            {
                Figure* line = new Line(c.ch, 0, 0, c.param[i], c.param[i + 1]);
                ret.push_back(line);
            }
        }
        return ret;
    }
    static vector<Figure*> ParseHorizontalLine(CMD c)
    {
        vector<Figure*> ret;
        if (c.param.size() > 0)
        {

            for (int i = 0; i < c.param.size(); i++)
            {
                Figure* line = new Line(c.ch, 0, 0, c.param[i], 0);
                ret.push_back(line);
            }
        }
        return ret;
    }
    static vector<Figure*> ParseVerticalLine(CMD c)
    {
        vector<Figure*> ret;
        if (c.param.size() > 0)
        {

            for (int i = 0; i < c.param.size(); i++)
            {
                Figure* line = new Line(c.ch, 0, 0, 0, c.param[i]);
                ret.push_back(line);
            }
        }
        return ret;
    }
    static vector<Figure*> ParseArc(CMD a)
    {
        vector<Figure*> ret;
        if (a.param.size() > 0)
        {

            for (int i = 0; i < a.param.size(); i += 7)
            {
                double rx = a.param[i];
                double ry = a.param[i + 1];
                double xAxisRotation = a.param[i + 2];
                bool largeArcFlag = static_cast<bool> (a.param[i + 3]);
                bool sweepFlag = static_cast<bool> (a.param[i + 4]);
                double endX = a.param[i + 5];
                double endY = a.param[i + 6];

                Figure* arc = new ArcF(a.ch, 0, 0, rx, ry, xAxisRotation, largeArcFlag, sweepFlag, endX, endY);

                ret.push_back(arc);
            }
        }
        return ret;
    }
    static vector<Figure*> ParseQuadraticBezier(CMD cb)
    {
        vector<Figure*> ret;
        if (cb.param.size() > 0)
        {

            for (int i = 0; i < cb.param.size(); i += 4)
            {
                double control1X = cb.param[i];
                double control1Y = cb.param[i + 1];
                double endX = cb.param[i + 2];
                double endY = cb.param[i + 3];

                Figure* quadratic_bezier = new QuadraticBezier(cb.ch, -1, -1, control1X, control1Y, endX, endY);

                ret.push_back(quadratic_bezier);
            }
        }
        return ret;
    }
    static vector<Figure*> ParseSmoothQuadraticBezier(CMD cb)
    {
        vector<Figure*> ret;
        if (cb.param.size() > 0)
        {

            for (int i = 0; i < cb.param.size(); i += 2)
            {

                double endX = cb.param[i];
                double endY = cb.param[i + 1];

                Figure* quadratic_bezier = new QuadraticBezier(cb.ch, -1, -1, -1, -1, endX, endY);

                ret.push_back(quadratic_bezier);
            }
        }
        return ret;
    }
    static vector<Figure*> ParseCubicBezier(CMD cb)
    {
        vector<Figure*> ret;
        if (cb.param.size() > 0)
        {

            for (int i = 0; i < cb.param.size(); i += 6)
            {
                double control1X = cb.param[i];
                double control1Y = cb.param[i + 1];
                double control2X = cb.param[i + 2];
                double control2Y = cb.param[i + 3];
                double endX = cb.param[i + 4];
                double endY = cb.param[i + 5];

                Figure* cubic_bezier = new CubicBezier(cb.ch, 0, 0, control1X, control1Y, control2X, control2Y, endX, endY);

                ret.push_back(cubic_bezier);
            }
        }
        return ret;
    }
    static vector<Figure*> ParseSmoothCubicBezier(CMD cb)
    {
        vector<Figure*> ret;
        if (cb.param.size() > 0)
        {
            for (int i = 0; i < cb.param.size(); i += 4)
            {
                double control2X = cb.param[i];
                double control2Y = cb.param[i + 1];
                double endX = cb.param[i + 2];
                double endY = cb.param[i + 3];

                Figure* cubic_bezier = new CubicBezier(cb.ch, 0, 0, 0, 0, control2X, control2Y, endX, endY);

                ret.push_back(cubic_bezier);
            }
        }
        
        return ret;
    }

    static vector<Figure*> GetCommands(vector<CMD>& commands)
    {
        vector<Figure*> ret;
        for (auto el : commands)
        {
            switch (el.ch)
            {
            case 'M':
            case 'm':
            {
                Figure* c = new Command(el.ch, el.param[0], el.param[1]);
                ret.push_back(c);
            }
            break;
            case 'L':
            case 'l':
            {
                vector<Figure*> lines = ParseLine(el);
                for (int i = 0; i < lines.size(); i++)
                    ret.push_back(lines[i]);
            }
            break;
            case 'H':
            case 'h':
            {
                vector<Figure*> lines = ParseHorizontalLine(el);
                for (int i = 0; i < lines.size(); i++)
                    ret.push_back(lines[i]);
            }
            break;
            case 'V':
            case 'v':
            {
                vector<Figure*> lines = ParseVerticalLine(el);
                for (int i = 0; i < lines.size(); i++)
                    ret.push_back(lines[i]);
                //Line* l = static_cast<Line*> (lines[0]);
                   //Line* l1 = static_cast<Line*> (lines[1]);
            }
            break;
            case 'A':
            case 'a':
            {
                vector<Figure*> arcs = ParseArc(el);
                for (int i = 0; i < arcs.size(); i++)
                    ret.push_back(arcs[i]);
            }
            break;
            case 'C':
            case 'c':
            {
                vector<Figure*> cb = ParseCubicBezier(el);
                for (int i = 0; i < cb.size(); i++)
                    ret.push_back(cb[i]);
            }
            break;
            case 'Q':
            case 'q':
            {
                vector<Figure*> qb = ParseQuadraticBezier(el);
                for (int i = 0; i < qb.size(); i++)
                    ret.push_back(qb[i]);
            }
            break;
            case 'S':
            case 's':
            {
                vector<Figure*> cb = ParseSmoothCubicBezier(el);
                for (int i = 0; i < cb.size(); i++)
                    ret.push_back(cb[i]);
            }
            break;
            case 'T':
            case 't':
            {
                vector<Figure*> qb = ParseSmoothQuadraticBezier(el);
                for (int i = 0; i < qb.size(); i++)
                    ret.push_back(qb[i]);
            }
            break;
            case 'Z':
            case 'z':
            {
                Figure* c = new Command(el.ch, -1, -1);
                ret.push_back(c);
            }
            break;
            }
        }
        return ret;
    }
    static void SetSmooth(Figure* prev, Figure* cur)
    {

        char ch = prev->GetChar();
        Point prev_control_point = prev->GetLastControl();

        if (ch == 'M' || ch == 'A' || ch == 'L' || ch == 'H' || ch == 'V' || ch == 'Z') // при данных командах пересчета нет и первая контрольная точка будет начальной этого элемента
        {
            if (cur->GetChar() == 'S')
            {
                CubicBezier* cb = static_cast<CubicBezier*>(cur);
                Point control1 = cb->GetStart();
                cb->SetControl1(control1);
            }
            else if (cur->GetChar() == 'T')
            {
                QuadraticBezier* qb = static_cast<QuadraticBezier*>(cur);
                Point control1 = qb->GetStart();
                qb->SetControl(control1);
            }
        }
        else // до этого рисовалась кривая. контрольная точка расчитывается и является отражением последней контрольной точки предыдущего элемента
        {
            if (cur->GetChar() == 'S')
            {
                CubicBezier* cb = static_cast<CubicBezier*>(cur);
                Point control1 = { 2 * cb->GetStart().x - prev_control_point.x, 2 * cb->GetStart().y - prev_control_point.y };
                cb->SetControl1(control1);
            }
            else if (cur->GetChar() == 'T')
            {
                QuadraticBezier* qb = static_cast<QuadraticBezier*>(cur);
                Point control = { 2 * qb->GetStart().x - prev_control_point.x, 2 * qb->GetStart().y - prev_control_point.y };
                qb->SetControl(control);
            }
        }
    }
    static void RecountCoord(vector<Figure*> commands)
    {
        Point  current_point;
        Figure* prev_el = nullptr;
        
        for (int i = 0; i < commands.size(); i++)
        {
            char ch = commands[i]->GetChar();
            if (ch == 'M')
            {
                Command* command = static_cast<Command*> (commands[i]);               
                current_point = command->GetPoint();
                prev_el = command;                  // для того, чтобы знать предыдущий элемент, если необходимо сглаживание кривой
                //start_point = command->GetPoint();  // для замыкания фигуры, если необходимо                
            }
            else if (ch == 'm')
            {
                if (prev_el != nullptr)
                {
                    Command* command = static_cast<Command*> (commands[i]);
                    command->IncreasePoint(prev_el->GetEnd());
                    prev_el = command;
                    command->SetChar('M');
                    //start_point = command->GetPoint();
                }
            }
            else if (ch == 'L')
            {
                (static_cast<Line*> (commands[i]))->SetStart(current_point);
                current_point = (static_cast<Line*> (commands[i]))->GetEnd();
                prev_el = static_cast<Line*> (commands[i]);
            }
            else if (ch == 'l')
            {
                Line* line = static_cast<Line*> (commands[i]);
                line->SetStart(current_point);
                line->IncreaseEnd(current_point);
                current_point = line->GetEnd();
                prev_el = line;
                line->SetChar('L');
            }
            else if (ch == 'H')
            {
                (static_cast<Line*> (commands[i]))->SetStart(current_point);
                current_point = (static_cast<Line*> (commands[i]))->GetEnd();
                prev_el = static_cast<Line*> (commands[i]);
            }
            else if (ch == 'h')
            {
                Line* line = static_cast<Line*> (commands[i]);
                line->SetStart(current_point);
                line->IncreaseEnd(current_point);
                current_point = line->GetEnd();
                prev_el = line;
                line->SetChar('L');
            }
            else if (ch == 'V')
            {
                (static_cast<Line*> (commands[i]))->SetStart(current_point);
                current_point = (static_cast<Line*> (commands[i]))->GetEnd();
                prev_el = static_cast<Line*> (commands[i]);
            }
            else if (ch == 'v')
            {
                Line* line = static_cast<Line*> (commands[i]);
                line->SetStart(current_point);
                line->IncreaseEnd(current_point);
                current_point = line->GetEnd();
                prev_el = line;
                line->SetChar('L');
            }
            else if (ch == 'A')
            {
                (static_cast<ArcF*> (commands[i]))->SetStart(current_point);
                current_point = (static_cast<ArcF*> (commands[i]))->GetEnd();
                prev_el = static_cast<ArcF*> (commands[i]);
            }
            else if (ch == 'a')
            {
                ArcF* arc = static_cast<ArcF*> (commands[i]);
                arc->SetStart(current_point);
                arc->IncreaseEnd(current_point);
                current_point = arc->GetEnd();
                prev_el = arc;
                arc->SetChar('A');
            }
            else if (ch == 'C')
            {
                CubicBezier* cb = static_cast<CubicBezier*> (commands[i]);
                cb->SetStart(current_point);
                current_point = cb->GetEnd();
                prev_el = cb;
            }
            else if (ch == 'c')
            {
                CubicBezier* cb = static_cast<CubicBezier*> (commands[i]);
                cb->SetStart(current_point);
                cb->IncreaseControl1(current_point);
                cb->IncreaseControl2(current_point);
                cb->IncreaseEnd(current_point);
                current_point = cb->GetEnd();
                prev_el = cb;
                cb->SetChar('C');
            }
            else if (ch == 'Q')
            {
                QuadraticBezier* qb = static_cast<QuadraticBezier*> (commands[i]);
                qb->SetStart(current_point);
                current_point = qb->GetEnd();
                prev_el = qb;
            }
            else if (ch == 'q')
            {
                QuadraticBezier* qb = static_cast<QuadraticBezier*> (commands[i]);
                qb->SetStart(current_point);
                qb->IncreaseControl(current_point);
                qb->IncreaseEnd(current_point);
                current_point = qb->GetEnd();
                prev_el = qb;
                qb->SetChar('Q');
            }
            else if (ch == 'S') // это сглаженная кубическая кривая Безье. Храню в обычной кубической Безье
            {
                CubicBezier* cb = static_cast<CubicBezier*> (commands[i]);
                cb->SetStart(current_point);
                SetSmooth(prev_el, cb);
                current_point = cb->GetEnd();
                prev_el = cb;
            }
            else if (ch == 's')
            {
                CubicBezier* sb = static_cast<CubicBezier*> (commands[i]);
                sb->SetStart(current_point);
                sb->IncreaseControl2(current_point);
                sb->SetChar('S');
                SetSmooth(prev_el, sb);
                sb->IncreaseEnd(current_point);
                current_point = sb->GetEnd();
                prev_el = sb;

            }
            else if (ch == 'T')  // это сглаженная квадратичная кривая Безье. 
            {
                QuadraticBezier* tb = static_cast<QuadraticBezier*> (commands[i]);
                tb->SetStart(current_point);
                SetSmooth(prev_el, tb);
                current_point = tb->GetEnd();
                prev_el = tb;
            }
            else if (ch == 't')
            {
                QuadraticBezier* tb = static_cast<QuadraticBezier*> (commands[i]);
                tb->SetStart(current_point);
                tb->IncreaseControl(current_point);
                tb->SetChar('T');
                SetSmooth(prev_el, tb);
                tb->IncreaseEnd(current_point);
                current_point = tb->GetEnd();
                prev_el = tb;

            }
            else if (ch == 'z')
            {
                commands[i]->SetChar('Z');
            }

        }
    }
    static void DrawSVG(HDC& hdc, vector<Figure*> commands, double scale, int mx = 0, int my = 0)
    {
        Point start_point;
        Point cur_point;
        for (int i = 0; i < commands.size(); i++)
        {
            char ch = commands[i]->GetChar();
            switch (ch)
            {
            case 'M':
                start_point = commands[i]->GetEnd();
                cur_point = commands[i]->GetEnd();
                break;
            case 'A':
            {
                ArcF* arc = static_cast<ArcF*>(commands[i]);
                // arc-> Draw(hdc, scale);
            }
            break;
            case 'L':
            case 'H':
            case 'V':
            {
                Line* line = static_cast<Line*>(commands[i]);
                line->Draw(hdc, scale, mx, my);
                /*vector<Point> p = GetLinePoints(line.GetStart(), line.GetEnd());
                DrawLine(hdc, p, scale);*/
            }
            break;
            case 'C':
            case 'S':
            {
                CubicBezier* cb = static_cast<CubicBezier*>(commands[i]);
                /*vector<Point> p = GetCubicBezierPoints(cb.GetStart(), cb.GetControl1(), cb.GetControl2(), cb.GetEnd());
                DrawLine(hdc, p, scale);*/
                cb->Draw(hdc, scale, mx, my);
            }
            break;
            case 'Q':
            case 'T':
            {
                QuadraticBezier* qb = static_cast<QuadraticBezier*>(commands[i]);
                qb->Draw(hdc, scale, mx, my);
                /* vector<Point> p = GetQuadraticBezierPoints(qb.GetStart(), qb.GetControl(), qb.GetEnd());
                 DrawLine(hdc, p, scale);*/
            }
            break;
            case 'Z':
            {
                if (i - 1 >= 0)
                {
                    Point end = commands[i - 1]->GetEnd();
                    Line line('L', start_point, end);
                    line.Draw(hdc, scale, mx, my);
                    /*vector<Point> p = GetLinePoints(cur_point, end);
                    DrawLine(hdc, p, scale);*/
                }
            }
            break;
            }
        }
    }
};


