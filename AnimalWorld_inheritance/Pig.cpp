#pragma once
#include "Pig.h"

vector <Behaviour> Pig::behaviour = {}; // возможность расширения на будущее

const short Pig::MAX_AGE = 3;
const short Pig::REPRODUCTIVE_AGE = 1;
const int Pig::MIN_LIFE_ENERGY = 1;
const int Pig::MAX_LIFE_ENERGY = 50;
const int Pig::CHILD_ELEVATION_CONSUMPTION = 10;
const int Pig::LIFE_CONSUMPTION = 2;
const int Pig::SPEED = 2;

Being::ClassType Pig::GetClassType()
{
    return ClassType::PIG;
}
