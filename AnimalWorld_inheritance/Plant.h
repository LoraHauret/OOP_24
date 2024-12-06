#pragma once
#include "Being.h"


class Plant :public Being
{
    //Plant();
public:
    Plant(short life_energy = 0, wchar_t sex = L'M', short age = 0, short speed = 0, Being::StateT t = StateT::PLANT, unsigned short child_count = 0, unsigned short parential_investment = 0, Point cur_pos = {0,0}, string app = "frog") : Being(life_energy, sex, age, speed, t, child_count, parential_investment, cur_pos, app)
    {

    }

    ~Plant() override
    {
    }
    ClassType GetClassType()override;
    
};