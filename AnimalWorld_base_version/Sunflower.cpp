#pragma once
#include "Sunflower.h"

const short Sunflower::MAX_AGE = 5;
const short Sunflower::REPRODUCTIVE_AGE = 1;
const int Sunflower::MIN_LIFE_ENERGY = 4;
const int Sunflower::MAX_LIFE_ENERGY = 8;
const int Sunflower::CHILD_ELEVATION_CONSUMPTION = 0;
const int Sunflower::LIFE_CONSUMPTION = 0;
const int Sunflower::SPEED = 0;

Being::ClassType Sunflower::GetClassType()
{
    return ClassType::SUNFLOWER;
}