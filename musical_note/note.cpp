#pragma once
#include "note.h"


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

