#pragma once
#include "Plant.h"


class Nut :public Plant
{
    static const short MAX_AGE;
    static const short REPRODUCTIVE_AGE;
    static const int MIN_LIFE_ENERGY;
    static const int MAX_LIFE_ENERGY;
    static const int CHILD_ELEVATION_CONSUMPTION;
    static const int LIFE_CONSUMPTION;
    static const int SPEED;
    //Plant();
public:
    Nut(short life_energy = MAX_LIFE_ENERGY, wchar_t sex = L'M', short age = 0, short speed = 0, Being::StateT t = StateT::PLANT, unsigned short child_count = 0, unsigned short parential_investment = 0, Point cur_pos = { 0,0 }, string app = "nut") : Plant(life_energy, sex, age, speed, t, child_count, parential_investment, cur_pos, app)
    {

    }

    ~Nut() override
    {
    }
    ClassType GetClassType()override;

    void RecountStates() override
    {
	if (GetAge() >= REPRODUCTIVE_AGE)
	    SetMature(Being::StateM::ADULT);

	if (GetMature() == Being::StateM::ADULT && GetLife_energy() / MAX_LIFE_ENERGY > 1)
	    SetReproduct(Being::StateR::REPRODUCTIVE);
	else if (GetLife_energy() < MAX_LIFE_ENERGY)
	{
	    SetHungriness(Being::StateH::HUNGRY);
	    SetReproduct(Being::StateR::NOTREPRODUCTIVE);
	}

	if (GetHungriness() == Being::StateH::HUNGRY)
	{
	    SetGoal(Being::StateG::FEEDING);
	}
	if (GetReproduct() == Being::StateR::REPRODUCTIVE)
	{
	    SetGoal(Being::StateG::REPRODUCTING);
	}
    }

    void IncreaseDecreaseLifeEnergy() override
    {
	//if(!(GetMature() == Being::StateM::CHILD && GetAge()==0)) // у новорожденных жизненная энергия не пересчитывается
	((Being*)this)->IncreaseDecreaseLifeEnergy(MIN_LIFE_ENERGY);
    }

    int GetEnergyForChild() override
    {	
	return MAX_LIFE_ENERGY;
    }
};