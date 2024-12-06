#pragma once
#include "Chicken.h"

vector <Behaviour> Chicken::behaviour = {}; // возможность расширения на будущее

const short Chicken::MAX_AGE = 3;
const short Chicken::REPRODUCTIVE_AGE = 1;
const int Chicken::MIN_LIFE_ENERGY = 1;
const int Chicken::MAX_LIFE_ENERGY = 20;
const int Chicken::CHILD_ELEVATION_CONSUMPTION = 5;
const int Chicken::LIFE_CONSUMPTION = 1;
const int Chicken::SPEED = 2;

Being::ClassType Chicken::GetClassType()
{
    return ClassType::CHICKEN;
}
