#pragma once
#include "Seeds.h"

const short Seeds::MAX_AGE = 5;
const short Seeds::REPRODUCTIVE_AGE = 1;
const int Seeds::MIN_LIFE_ENERGY = 2;
const int Seeds::MAX_LIFE_ENERGY = 2;
const int Seeds::CHILD_ELEVATION_CONSUMPTION = 0;
const int Seeds::LIFE_CONSUMPTION = 0;
const int Seeds::SPEED = 0;

Being::ClassType Seeds::GetClassType()
{
    return ClassType::SEEDS;
}