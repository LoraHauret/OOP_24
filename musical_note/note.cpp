#pragma once
#include <iostream>
using namespace std;

class Note {
public:    
    // перечисления для полей
    enum Accidental { NONE, FLAT, SHARP, NATURAL }; // Нет знака, бемоль, диез, бекар
    enum Dinamics { PIANO = 1, FORTE, MEZZO_FORTE, PIANISSIMO, FORTISSIMO, FORTE_PIANO, CRESCENDO, DIMINUENDO };
    enum Articulation { STACCATO = 1, LEGATO, MARCATO };    

    Note(float dur, string name, Accidental acc = NONE, Dinamics din = PIANO, Articulation art = STACCATO, unsigned short oct = 1) : duration{ dur }, pitch{ name }, accidental{ acc }, dinamics{ din }, articulation{ art }, octave{ oct }
    {}   

    // demo temporary functions
    void MakeSound();
    void ShowNote();
    void PrintNote();
    void ChangeDuration(float dur);
    void ChangeArticultaion(Articulation art);

private:
    float duration;
    string pitch;
    Accidental accidental;
    Dinamics dinamics;
    Articulation articulation;
    unsigned short octave;
    Note();

public:
    const float&	    get_duration();
    const string&	    get_pitch()const;
    const Accidental	    get_accidental()const;
    const Dinamics	    get_dinamics()const;
    const Articulation	    get_articulation()const;
    const unsigned short&   get_octave()const;

    void set_duration(const float&);
    void set_pitch(const string&);
    void set_accidental(const Accidental);
    void set_dinamics(const Dinamics);
    void set_articulation(const Articulation);
    void set_octave(const unsigned short&);

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

/////////////геттеры////////////////
const float& Note::get_duration()
{
    return duration;
}

const string& Note::get_pitch()const
{
    return pitch;
}

const Note::Accidental Note::get_accidental()const
{
    return accidental;
}

const Note::Dinamics Note::get_dinamics()const
{
    return dinamics;
}

const Note::Articulation Note::get_articulation()const
{
    return articulation;
}

const unsigned short& Note::get_octave()const
{
    return octave;
}

void Note::set_duration(const float& val)
{
    this->duration = val;
}
void Note::set_pitch(const string& val)
{
    this->pitch = val;
}
void Note::set_accidental(const Accidental  val)
{
    this->accidental = val;
}
void Note::set_dinamics(const Dinamics  val)
{
    this->dinamics = val;
}
void Note::set_articulation(const Articulation  val)
{
    this->articulation = val;
}
void Note::set_octave(const unsigned short& val)
{
    this->octave = val;
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
