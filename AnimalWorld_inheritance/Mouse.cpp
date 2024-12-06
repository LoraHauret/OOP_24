#pragma once
#include "Mouse.h"

vector <Behaviour> Mouse::behaviour = {}; // возможность расширения на будущее

const short Mouse::MAX_AGE = 3;
const short Mouse::REPRODUCTIVE_AGE = 1;
const int Mouse::MIN_LIFE_ENERGY = 1;
const int Mouse::MAX_LIFE_ENERGY = 10;
const int Mouse::CHILD_ELEVATION_CONSUMPTION = 2;
const int Mouse::LIFE_CONSUMPTION = 1;
const int Mouse::SPEED = 3;

Being::ClassType Mouse::GetClassType()
{
    return ClassType::MOUSE;
}
