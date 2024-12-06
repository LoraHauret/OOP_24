#pragma once
#include "Seeding.h"

const short Seeding::MAX_AGE = 5;
const short Seeding::REPRODUCTIVE_AGE = 1;
const int Seeding::MIN_LIFE_ENERGY = 4;
const int Seeding::MAX_LIFE_ENERGY = 8;
const int Seeding::CHILD_ELEVATION_CONSUMPTION = 0;
const int Seeding::LIFE_CONSUMPTION = 0;
const int Seeding::SPEED = 0;

Being::ClassType Seeding::GetClassType()
{
    return ClassType::SEEDING;
}