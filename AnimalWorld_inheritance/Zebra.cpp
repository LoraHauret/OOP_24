#pragma once
#include "Zebra.h"

vector <Behaviour> Zebra::behaviour = {}; // возможность расширения на будущее

const short Zebra::MAX_AGE = 10;
const short Zebra::REPRODUCTIVE_AGE = 1;
const int Zebra::MIN_LIFE_ENERGY = 1;
const int Zebra::MAX_LIFE_ENERGY = 120;
const int Zebra::CHILD_ELEVATION_CONSUMPTION = 18;
const int Zebra::LIFE_CONSUMPTION = 3;
const int Zebra::SPEED = 3;

Being::ClassType Zebra::GetClassType()
{
    return ClassType::ZEBRA;
}
