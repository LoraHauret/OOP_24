#pragma once
#include "note.h"



int main()
{
    Note n1(0.25, "A", Note::FLAT, Note::PIANISSIMO);
    n1.ShowNote();
    n1.MakeSound();
    n1.PrintNote();
    n1.ChangeDuration(0.3);
    n1.ChangeArticultaion(Note::LEGATO);

    cout << "\n";
    n1.PrintNote();

}