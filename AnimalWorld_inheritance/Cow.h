#pragma once
#include "Herbivore.h"

class Cow : public Herbivore
{
    const static short MAX_AGE;
    const static short REPRODUCTIVE_AGE;
    const static int MIN_LIFE_ENERGY;
    const static int MAX_LIFE_ENERGY;
    const static int CHILD_ELEVATION_CONSUMPTION;
    const static int LIFE_CONSUMPTION;
    const static int SPEED;
    static vector <Behaviour> behaviour;
public:
    Cow(short life_energy = Cow::MAX_LIFE_ENERGY, wchar_t sex = L'M', short age = 0, short speed = Cow::SPEED, Being::StateT t = StateT::ANIMAL, unsigned short child_count = 0, unsigned short parential_investment = 1, Point cur_pos = { 0,0 }, string app = "cow") : Herbivore(life_energy, sex, age, speed, t, child_count, parential_investment, cur_pos, app)
    {

    }

    ~Cow() override
    {
    }
    ClassType GetClassType() override;

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
	((Being*)this)->IncreaseDecreaseLifeEnergy(LIFE_CONSUMPTION * -1);
    }

    int GetEnergyForChild() override
    {
	int ret = GetLife_energy() - MAX_LIFE_ENERGY;
	SetLife_energy(MAX_LIFE_ENERGY);// внутреннее перераспределение ресурсов так, чтобы мать была достаточно ресурсной для выращивания потомства
	return ret;
    }
};