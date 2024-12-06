#pragma once
#include "Rabbit.h"

vector <Behaviour> Rabbit::behaviour = {}; // возможность расширения на будущее

const short Rabbit::MAX_AGE = 3;
const short Rabbit::REPRODUCTIVE_AGE = 1;
const int Rabbit::MIN_LIFE_ENERGY = 1;
const int Rabbit::MAX_LIFE_ENERGY = 30;
const int Rabbit::CHILD_ELEVATION_CONSUMPTION = 6;
const int Rabbit::LIFE_CONSUMPTION = 1;
const int Rabbit::SPEED = 3;

Being::ClassType Rabbit::GetClassType()
{
    return ClassType::RABBIT;
}
