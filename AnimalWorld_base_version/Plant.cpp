#pragma once
#include "Plant.h"
//
//const short Plant::MAX_AGE = 5;
//const short Plant::REPRODUCTIVE_AGE = 1;
//const int Plant::MIN_LIFE_ENERGY = 5;
//const int Plant::MAX_LIFE_ENERGY = 10;
//const int Plant::CHILD_ELEVATION_CONSUMPTION =0;
//const int Plant::LIFE_CONSUMPTION = 0;
//const int Plant::SPEED = 0;

Being::ClassType Plant::GetClassType() 
{
    return ClassType::PLANT;
}