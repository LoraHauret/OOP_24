#pragma once
#include "Herbivore.h"

class Pig : public Herbivore
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
    Pig(short life_energy = Pig::MAX_LIFE_ENERGY, wchar_t sex = L'M', short age = 0, short speed = Pig::SPEED, Being::StateT t = StateT::ANIMAL, unsigned short child_count = 0, unsigned short parential_investment = 1, Point cur_pos = { 0,0 }, string app = "pig") : Herbivore(life_energy, sex, age, speed, t, child_count, parential_investment, cur_pos, app)
    {

    }

    ~Pig() override
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
	//if(!(GetMature() == Being::StateM::CHILD && GetAge()==0)) // � ������������� ��������� ������� �� ���������������
	((Being*)this)->IncreaseDecreaseLifeEnergy(LIFE_CONSUMPTION * -1);
    }

    int GetEnergyForChild() override
    {
	int ret = GetLife_energy() - MAX_LIFE_ENERGY;
	SetLife_energy(MAX_LIFE_ENERGY);// ���������� ����������������� �������� ���, ����� ���� ���� ���������� ��������� ��� ����������� ���������
	return ret;
    }
};