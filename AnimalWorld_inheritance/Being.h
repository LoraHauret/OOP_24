#pragma once
#include <iostream>
#include <windows.h>
#include <string>
#include <fcntl.h>
#include <io.h>
#include <iomanip>
#include <vector>
#include <random>
#include <time.h>
#include <map>
#include <queue>

using namespace std;

typedef void(*Behaviour)();
//typedef void(*pr_str)(std::wstring);

struct Point
{
    short x;
    short y;
    Point() :x(0), y(0) {}
    Point(short X, short Y) :x(X), y(Y) {}
    Point(const Point& other) :x(other.x), y(other.y) {}
};


struct Emodji
{
    wchar_t high_surr = 0;
    wchar_t low_surr = 0;
    wchar_t zero = 0;
    friend wostream& operator<<(wostream& os, Emodji);
};

 

class Being
{   
public: 
    static const map<string, Emodji> pictures;  
    enum class ClassType :char { BASE = 0, PREDATOR, HERBIVORE, CHICKEN, PIG, COW, HORSE, ZEBRA, RABBIT, SQUIRREL, MOUSE, FOX, TIGER, CAT, PLANT, LEAVES, SEEDS, SUNFLOWER, SEEDING, NUT, CARROT, ZEBRAHORSE};
    enum class StateH :char { HUNGRY = 0, FED };
    enum class StateR :char {NOTREPRODUCTIVE = 0, REPRODUCTIVE};
    enum class StateM :char { CHILD = 0, ADULT };
    enum class StateL :char { DEAD = 0, ALIVE};
    enum class StateT :char { PLANT = 0, ANIMAL };
    enum class StateG :char { FEEDING = 0, ESCAPING, REPRODUCTING };
    

private:
    int life_energy=1;
    wchar_t sex;
    short age = 0;
    short speed;
    StateT type = StateT::PLANT;
    StateR reproductiveness = StateR::NOTREPRODUCTIVE;
    StateM mature = StateM::CHILD;
    StateH hungriness = StateH::HUNGRY;    
    float hunger_degree = 0.5;
    StateG goal = StateG::FEEDING;
    unsigned short child_count = 0;
    unsigned short parential_investment = 1;    
    Point cur_pos;
    Emodji appearance;   //uint32_t appearance;  

    queue<Point> run_path = {};
    Being* other = nullptr;
    //Being();    
     
public:
    // тестирование элементов дерева с картинками
    void PrintPictures()
    {
	/*for (auto el : Being::pictures)
	    wcout << el.second << " ";*/
	auto it = Being::pictures.find("frog");
	if (it != pictures.end())
	{
	    Emodji var = it->second;
	    wcout << var;
	}
	   
    }/**/
    static Emodji convertToSurrogate(uint32_t u_ch);
    Being(int life_energy = 0, wchar_t sex = L'M', short age = 0, short speed = 0, StateT type = StateT::PLANT, unsigned short child_count = 0, unsigned short parential_investment = 0, Point cur_pos = { 0,0 }, string ap_key = "frog");
    Being(const Being&);
    virtual ClassType GetClassType() = 0; // чисто виртуальная функция
    
   
   bool IsReadyForReproduction();
   void IncreaseDecreaseLifeEnergy(int);
   virtual void IncreaseDecreaseLifeEnergy() {}
   void IncreaseDecreaseHunger(float);
   bool IsAlive();
   //virtual void RunLifeCircle() {} // рождение, жизнь, смерть, ...

   virtual void Reproduct() {}
   virtual void ResourceSearch() {}
   virtual void Growing() {}
   virtual void SpendingLifeForChild() 
   {
   }
   virtual void Feeding(Being* other) 
   {
       if (other != nullptr)
       {
	   this->IncreaseDecreaseLifeEnergy(other->life_energy);
	   other->SetLife_energy(0);
	   other->SetHungerLevel(0);
	   other->SetSpeed(0);
	   other->SetReproduct(StateR::NOTREPRODUCTIVE);
	   other->SetPos(-1, -1);
       }       
   }
   virtual void RecountStates() {}

   void Run()
   {
       if (other == nullptr)
       {
	   ClearRunPath();
	   
       }
       else// если объект вожделения никто еще не оприходовал, то имеет смысл бежать дальше навстречу счастью
       {
	   
	   if (!run_path.empty())
	   {
	       run_path.pop();
	       if (!run_path.empty())
	       {
		   Point p = run_path.front();
		   SetPos(p.x, p.y);
	       }
	       
	   }   
       }
       

       //speed = speed * (1 - hunger_degree); // скорость увеличивается в зависимости от того, насколько животное голодно
       //IncreaseDecreaseLifeEnergy(-1 * (hunger_degree * speed)); // при беге расходуется жизненная энергия
   }
   void SetPos(short x, short y)
    {
	cur_pos.x = x;
	cur_pos.y = y;
    }
   virtual ~Being() {}
   const int& GetLife_energy();
   virtual int GetEnergyForChild() { return 0; }
   const wchar_t& GetSex();
   const short& GetAge();
   const short& GetSpeed();
   StateT GetType();
   StateR GetReproduct();
   StateM GetMature();
   StateG GetGoal();
   StateH GetHungriness();
   bool isHungry();
   float GetHungerLevel();
   const unsigned short& GetChild_count();
   const unsigned short& GetParentInvest();
   const Point& GetPos();
   const Emodji& GetAppearance();
   Being* GetOther();
   bool isRunning()
   {
       return run_path.size() > 0 && other != nullptr;
   }
   void ClearRunPath()
   {
       while (!run_path.empty())
	   run_path.pop();
   }
   void SetAppearance(string a) 
   {
       auto it = Being::pictures.find(a);
       if (it != pictures.end())
       {
	   appearance = it->second;

       }
   }
   void SetLife_energy(int);
   void SetSex(wchar_t);
   void SetAge(short);
   void SetSpeed(short);
   void SetType(StateT);
   void SetReproduct(StateR);
   void SetMature(StateM);
   void SetGoal(StateG);
   void SetHungriness(StateH);
   void SetHungerLevel(float);
   void SetChild_count(unsigned short);
   void SetParentInvest(unsigned short);
   void SetOther(Being*);
   void SetPath(vector<Point>);
};

