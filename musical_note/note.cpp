#pragma once
#include <iostream>
using namespace std;

class Note {
    Note();
public:    
    // перечисления для полей
    enum Accidental { NONE, FLAT, SHARP, NATURAL }; // Нет знака, бемоль, диез, бекар
    enum Dinamics { PIANO = 1, FORTE, MEZZO_FORTE, PIANISSIMO, FORTISSIMO, FORTE_PIANO, CRESCENDO, DIMINUENDO };
    enum Articulation { STACCATO = 1, LEGATO, MARCATO };

    float duration;
    string pitch;
    Accidental accidental;
    Dinamics dinamics;
    Articulation articulation;
    unsigned short octave;

    Note(float dur, string name, Accidental acc = NONE, Dinamics din = PIANO, Articulation art = STACCATO, unsigned short oct = 1) : duration{ dur }, pitch{ name }, accidental{ acc }, dinamics{ din }, articulation{ art }, octave{ oct }
    {}   

    // demo temporary functions
    void MakeSound();
    void ShowNote();
    void PrintNote();
    void ChangeDuration(float dur);
    void ChangeArticultaion(Articulation art);

    friend ostream& operator<<(ostream& os, Note n);
};




// demo temporary functions
void Note::MakeSound()
{
    cout << "note sounds...\n";
}
void Note::ShowNote()
{
    cout << "note is being drawed...\n";
}
void Note::PrintNote()
{
    cout << "name: " << pitch<<"\n";
    cout << "duration: " << duration << "\n";
    cout << "accidental: " << accidental << "\n";
    cout << "dinamics: " << dinamics << "\n";
    cout << "articulation: " << articulation << "\n";
    cout << "octave: " << octave << "\n";    
}

ostream& operator<<(ostream& os, Note n)
{
    os << "name: " << n.pitch << "\n";
    os << "duration: " << n.duration << "\n";
    os << "accidental: " << n.accidental << "\n";
    os << "dinamics: " << n.dinamics << "\n";
    os << "articulation: "<< n.articulation << "\n";
    os << "octave: " << n.octave << "\n";
    return os;
}
void Note::ChangeDuration( float dur)
{
    this->duration = dur;
}
void Note::ChangeArticultaion(Note::Articulation art)
{
    this->articulation = art;
}



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
