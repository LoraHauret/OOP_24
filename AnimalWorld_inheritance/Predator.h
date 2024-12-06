#pragma once
#include "Being.h"

class Predator: public Being
{
    Predator();
public:
    Predator(short life_energy , wchar_t sex = 1, short age = 0, short speed = 0, Being::StateT t = StateT::ANIMAL, unsigned short child_count = 0, unsigned short parential_investment = 1, Point cur_pos = { 0,0 }, string app = "frog") : Being(life_energy, sex, age, speed, t, child_count, parential_investment, cur_pos, app)
    {

    }

    ~Predator() override
    {
    }
    ClassType GetClassType()override;
};
