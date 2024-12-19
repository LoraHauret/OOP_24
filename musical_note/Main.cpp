#pragma once
#include <vector>
#include "note.h"



int main()
{
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(console, { 0, 20 });

    HWND hwnd = GetConsoleWindow();
    HDC hdc = GetDC(hwnd);

    vector<Note> notes;
    /*Note n1("ref\\a.svg", 0.25, "A", Note::FLAT, Note::PIANISSIMO);
    n1.ShowNote();
    n1.MakeSound();
    n1.PrintNote();
    n1.ChangeDuration(0.3);
    n1.ChangeArticultaion(Note::LEGATO);

    cout << "\n";
    n1.PrintNote();*/
    float scale = 0.1;
    Note n2("ref\\eight.svg", 1, "A", Note::FLAT, Note::PIANISSIMO);
    notes.push_back(n2);
    Note n3("ref\\a.svg", 1, "A", Note::FLAT, Note::PIANISSIMO);
    n3.moveNote(45, 20);
    notes.push_back(n3);
    Note n4("ref\\l.svg", 1, "A", Note::FLAT, Note::PIANISSIMO);
    n4.moveNote(90, 16);
    notes.push_back(n4);
    for (int i = 0; i < notes.size(); i++)
    {
	notes[i].drawNote(hdc, scale);
    }

    ReleaseDC(hwnd, hdc);
}