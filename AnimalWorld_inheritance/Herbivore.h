#pragma once
#include "Being.h"

class Herbivore : virtual public Being
{
   // Herbivore();
public:
    Herbivore(short life_energy = 0, wchar_t sex =L'M', short age = 0, short speed = 0, Being::StateT t = StateT::ANIMAL, unsigned short child_count = 0, unsigned short parential_investment = 1, Point cur_pos = {0,0}, string app = "frog") : Being(life_energy, sex, age, speed, t, child_count, parential_investment, cur_pos, app)
    {

    }

    ~Herbivore() override
    {
    }
    ClassType GetClassType()override;
};