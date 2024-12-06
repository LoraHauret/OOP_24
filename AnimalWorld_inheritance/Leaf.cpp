#pragma once
#include "Leaf.h"

const short Leaf::MAX_AGE = 5;
const short Leaf::REPRODUCTIVE_AGE = 1;
const int Leaf::MIN_LIFE_ENERGY = 1;
const int Leaf::MAX_LIFE_ENERGY = 10;
const int Leaf::CHILD_ELEVATION_CONSUMPTION = 0;
const int Leaf::LIFE_CONSUMPTION = 0;
const int Leaf::SPEED = 0;

Being::ClassType Leaf::GetClassType()
{
    return ClassType::LEAVES;
}