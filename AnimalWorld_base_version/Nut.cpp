#pragma once
#include "Nut.h"

const short Nut::MAX_AGE = 5;
const short Nut::REPRODUCTIVE_AGE = 1;
const int Nut::MIN_LIFE_ENERGY = 6;
const int Nut::MAX_LIFE_ENERGY = 6;
const int Nut::CHILD_ELEVATION_CONSUMPTION = 0;
const int Nut::LIFE_CONSUMPTION = 0;
const int Nut::SPEED = 0;

Being::ClassType Nut::GetClassType()
{
    return ClassType::NUT;
}