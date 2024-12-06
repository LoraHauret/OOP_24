#pragma once
#include "Horse.h"
#include "Zebra.h"

class ZebraHorse :public Horse, public Zebra
{
public:
    ZebraHorse(short life_energy = (Zebra::GetMaxLevelLife() + Horse::GetMaxLevelLife()), wchar_t sex = L'M', short age = 0, short speed = (Zebra::GetMaxLevelSpeed() + Horse::GetMaxLevelSpeed()), Being::StateT t = StateT::ANIMAL, unsigned short child_count = 0, unsigned short parential_investment = 1, Point cur_pos = { 0,0 }) : Herbivore(life_energy, sex, age, speed, t, child_count, parential_investment, cur_pos) 
    {
	this->SetAppearance("zebrahorse");
    };
    Being::ClassType GetClassType() override;


    void RecountStates() override
    {
	int ZebraAge = Zebra::GetAge();
	int HorseAge = Horse::GetAge();
	if (GetAge() >= (Zebra::GetReproductiveAGE() + Horse::GetReproductiveAGE() /2))
	    SetMature(Being::StateM::ADULT);

	if (GetMature() == Being::StateM::ADULT && GetLife_energy() / (Zebra::GetMaxLevelLife() + Horse::GetMaxLevelLife()) > 1)
	    SetReproduct(Being::StateR::REPRODUCTIVE);
	else if (GetLife_energy() < (Zebra::GetMaxLevelLife() + Horse::GetMaxLevelLife()))
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
	if(!(GetMature() == Being::StateM::CHILD && GetAge()==0)) // у новорожденных жизненная энергия не пересчитывается
	((Being*)this)->IncreaseDecreaseLifeEnergy((Zebra::GetLifeConsumption() + Horse::GetLifeConsumption())/2 * -1);
    }							    

    int GetEnergyForChild() override
    {
	int ret = GetLife_energy() - (Zebra::GetMaxLevelLife() + Horse::GetMaxLevelLife());
	SetLife_energy((Zebra::GetMaxLevelLife() + Horse::GetMaxLevelLife()));// внутреннее перераспределение ресурсов так, чтобы мать была достаточно ресурсной для выращивания потомства
	return ret;
    }
};