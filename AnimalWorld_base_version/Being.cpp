#pragma once
#include "Being.h"


//void Being::convertToSurrogate(uint32_t u_ch)
//{
//    convertToSurrogate(u_ch, appearance);
//}
const std::map<string, Emodji> Being::pictures =
{
    //{"", Being::convertToSurrogate(0x) },
    {"chicken", Being::convertToSurrogate(0x1F414) },
    {"pig", Being::convertToSurrogate(0x1F437) },
    {"cow", Being::convertToSurrogate(0x1F42E) },
    {"horse", Being::convertToSurrogate(0x1F434) },
    {"zebra", Being::convertToSurrogate(0x1F993) },
    {"rabbit", Being::convertToSurrogate(0x1F430) },	
    {"squirrel", Being::convertToSurrogate(0x1F43F) },
    {"hamster", Being::convertToSurrogate(0x1F439) },
    {"mouse", Being::convertToSurrogate(0x1F400) },
    {"fox", Being::convertToSurrogate(0x1F98A) },
    {"tiger", Being::convertToSurrogate(0x1F42F) },
    {"cat", Being::convertToSurrogate(0x1F431) },
    {"frog", Being::convertToSurrogate(0x1F438) },
    {"unhappy", Being::convertToSurrogate(0x1F644) },
    {"chocolate", Being::convertToSurrogate(0x1F36B) },
    {"happy", Being::convertToSurrogate(0x1F601) },
    {"chili", Being::convertToSurrogate(0x1F336) },
    {"star", Being::convertToSurrogate(0x2B50) },
    {"mouth", Being::convertToSurrogate(0x1F444) },
    {"heart", Being::convertToSurrogate(0x1F494) },
    {"kiss", Being::convertToSurrogate(0x1F48B) },
    {"wilted_flower", Being::convertToSurrogate(0x1F940) },
    {"crossed_swords", Being::convertToSurrogate(0x2694) },
    {"sword", Being::convertToSurrogate(0x1F5E1) },
    {"shield", Being::convertToSurrogate(0x1F6E1) },
    {"leaves", Being::convertToSurrogate(0x1F33F) },
    {"seeds", Being::convertToSurrogate(0x1F33E) },
    {"sunflower", Being::convertToSurrogate(0x1F33B) },
    {"seeding", Being::convertToSurrogate(0x1F331) },
    {"nut", Being::convertToSurrogate(0x1F330) },
    {"carrot", Being::convertToSurrogate(0x1F955) },
    {"rocket", Being::convertToSurrogate(0x1F680) },
    {"gem_stone", Being::convertToSurrogate(0x1F48E) },
    {"female", Being::convertToSurrogate(0x2640) },
    {"mail", Being::convertToSurrogate(0x2642) },
    {"game_die", Being::convertToSurrogate(0x1F3B2) },
    {"egg", Being::convertToSurrogate(0x1F95A) },
    {"hatching_egg", Being::convertToSurrogate(0x1F423) },
    {"chick", Being::convertToSurrogate(0x1F425) },
    {"death_hole", Being::convertToSurrogate(0x1F573) }

};

Emodji Being::convertToSurrogate(uint32_t u_ch)
{
    Emodji ret;
    if (u_ch < 0x10000 || u_ch >0x10ffff)
    {
	wcerr << L"недопустимый диапазон кодовой точки";
	return ret;
    }
    
    uint32_t primary_code = u_ch - 0x10000;

    wchar_t high_surr = 0xD800 + (primary_code >> 10); // 10 старших бит
    wchar_t low_surr = 0xDC00 + (primary_code & 0x3ff); // 10 младших бит

    ret.high_surr = high_surr; // массив для записи суррогатной пары и 0 в конце
    ret.low_surr = low_surr;
    ret.zero = 0;
    return ret;
    /*wchar_t v[] = { high_surr, low_surr, 0 };
    wcout << v;*/
}

wostream& operator<<(wostream& os, Emodji e)
{
    wchar_t arr[3]{ e.high_surr, e.low_surr, 0 };
    os << arr;
    return os;
}

Being::Being(int life_energy, wchar_t sex, short age, short speed, StateT type, unsigned short child_count, unsigned short parential_investment, Point cur_pos, string ap_key) : life_energy(life_energy), sex(sex), age(age), speed(speed), type(type), child_count(child_count), parential_investment(parential_investment), cur_pos(cur_pos)
{
    //appearance = Being::convertToSurrogate(appear);
    auto it = Being::pictures.find(ap_key);
    if (it != pictures.end())
    {
	appearance = it->second;
	 
    }
}

Being::Being(const Being& other)
{
    this->life_energy = other.life_energy;
    this->sex = other.sex;
    this->age = other.age;
    this->speed = other.speed;
    this->type = other.type;
    this->reproductiveness = StateR::NOTREPRODUCTIVE;
    this->mature = StateM::CHILD;
    this->hungriness = StateH::HUNGRY;
    this->child_count = other.child_count;
    this->parential_investment = other.parential_investment;
    this->cur_pos.x = other.cur_pos.x;
    this->cur_pos.y = other.cur_pos.y;
    for (int i = 0; i < 3; i++)
    {
	this->appearance.high_surr = other.appearance.high_surr;
	this->appearance.low_surr = other.appearance.low_surr;
	//this->appearance.zero = 0;
    }


}

bool Being::IsAlive()
{
    return life_energy > 0;
}

const Point& Being::GetPos()
{
    return cur_pos;
}
const Emodji& Being::GetAppearance()
{
    return appearance;
}
const int& Being::GetLife_energy()
{
    return life_energy;
}
const wchar_t& Being::GetSex()
{
    return sex;
}
const short& Being::GetAge()
{
    return age;
}
const short& Being::GetSpeed()
{
    return speed;
}
Being::StateT Being::GetType()
{
    return type;
}
Being::StateR Being::GetReproduct()
{
    return reproductiveness;
}
Being::StateM Being::GetMature()
{
    return mature;
}
Being::StateG Being::GetGoal()
{
    return goal;
}
Being::StateH Being::GetHungriness()
{
    return hungriness;
}
bool Being::isHungry()
{
    return hungriness == Being::StateH::HUNGRY;
}
float Being::GetHungerLevel()
{
    return hunger_degree;
}
const unsigned short& Being::GetChild_count()
{
    return child_count;
}
const unsigned short& Being::GetParentInvest()
{
    return parential_investment;
}
Being* Being::GetOther()
{
    return other;
}
//vector<Point> Being::GetPath()
//{
//    return run_path;
//}

void Being::SetLife_energy(int val)
{
    life_energy = val;
    
}
void Being::SetSex(wchar_t val)
{
    sex = val;
}
void Being::SetAge(short val)
{
    age = val;
}
void Being::SetSpeed(short val)
{
    speed = val;
}
void Being::SetType(StateT val)
{
    type = val;
}
void Being::SetReproduct(StateR val)
{
    reproductiveness = val;
}
void Being::SetMature(Being::StateM val)
{
    mature = val;
}
void Being::SetGoal(Being::StateG g)
{
    this->goal = g;
}
void Being::SetHungriness(StateH val)
{
    hungriness = val;
}

void Being::SetHungerLevel(float val)
{
    hunger_degree = val;
}
void Being::SetChild_count(unsigned short val)
{
    child_count = val;
}
void Being::SetParentInvest(unsigned short val)
{
    parential_investment = val;
}
void Being::SetOther(Being* b)
{
    other = b;
}
void Being::SetPath(vector<Point> path)
{
    for(int i = 0; i < path.size(); i++)
    run_path.push(path[i]);
    /*for (int i = path.size() - 1; i >=0 ; i--)
	run_path.push(path[i]);*/
}
bool Being::IsReadyForReproduction()
{
    return reproductiveness == StateR::REPRODUCTIVE;
}

void Being::IncreaseDecreaseLifeEnergy(int val)
{
    life_energy += val;
}
void Being::IncreaseDecreaseHunger(float val)
{
    hunger_degree += val;
}