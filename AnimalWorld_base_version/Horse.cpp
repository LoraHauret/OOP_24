#pragma once
#include "Horse.h"

vector <Behaviour> Horse::behaviour = {}; // возможность расширения на будущее

const short Horse::MAX_AGE = 3;
const short Horse::REPRODUCTIVE_AGE = 1;
const int Horse::MIN_LIFE_ENERGY = 1;
const int Horse::MAX_LIFE_ENERGY = 150;
const int Horse::CHILD_ELEVATION_CONSUMPTION = 20;
const int Horse::LIFE_CONSUMPTION = 4;
const int Horse::SPEED = 4;

Being::ClassType Horse::GetClassType()
{
    return ClassType::HORSE;
}
