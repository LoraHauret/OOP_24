#pragma once
#include "Cow.h"

vector <Behaviour> Cow::behaviour = {}; // возможность расширения на будущее

const short Cow::MAX_AGE = 10;
const short Cow::REPRODUCTIVE_AGE = 1;
const int Cow::MIN_LIFE_ENERGY = 1;
const int Cow::MAX_LIFE_ENERGY = 100;
const int Cow::CHILD_ELEVATION_CONSUMPTION = 15;
const int Cow::LIFE_CONSUMPTION = 3;
const int Cow::SPEED = 2;

Being::ClassType Cow::GetClassType()
{
    return ClassType::COW;
}
