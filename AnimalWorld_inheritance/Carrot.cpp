#pragma once
#include "Carrot.h"

const short Carrot::MAX_AGE = 1;
const short Carrot::REPRODUCTIVE_AGE = 1;
const int Carrot::MIN_LIFE_ENERGY = 5;
const int Carrot::MAX_LIFE_ENERGY = 5;
const int Carrot::CHILD_ELEVATION_CONSUMPTION = 0;
const int Carrot::LIFE_CONSUMPTION = 0;
const int Carrot::SPEED = 0;

Being::ClassType Carrot::GetClassType()
{
    return ClassType::CARROT;
}