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
    {
    }

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
    const float& get_duration();
    const string& get_pitch()const;
    const Accidental	    get_accidental()const;
    const Dinamics	    get_dinamics()const;
    const Articulation	    get_articulation()const;
    const unsigned short& get_octave()const;

    void set_duration(const float&);
    void set_pitch(const string&);
    void set_accidental(const Accidental);
    void set_dinamics(const Dinamics);
    void set_articulation(const Articulation);
    void set_octave(const unsigned short&);

    friend ostream& operator<<(ostream& os, Note n);
};
