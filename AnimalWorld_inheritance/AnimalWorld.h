#pragma once
#include <vector>
#include <cstdlib>
#include "Fox.h"
#include "Rabbit.h"
#include "Leaf.h"
#include "Seeds.h"
#include "Sunflower.h"
#include "Seeding.h"
#include "Nut.h"
#include "Carrot.h"
#include "Tiger.h"
#include "Cat.h"
#include "Chicken.h"
#include "Pig.h"
#include "Cow.h"
#include "Horse.h"
#include "Zebra.h"
#include "Mouse.h"
#include "ZebraHorse.h"

using namespace std;

//typedef void(*Position)(HANDLE, int, int);


class AnimalWorld { 
    HANDLE console;
   // Position fcurs_pos;
    static const int ROW = 44;  // x вверх вниз
    static const int COL = 85; // y вправо влево
    const int dir[4][2]{ {-1, 0},{1, 0},{0,-1},{0,1} }; // вверх, вниз, влево, вправо
   
    vector<Being*>plants = {};
    vector<Being*>predators = {};
    vector<Being*>herbivores = {};
    //Point board[45][85];
    int board[ROW][COL];    

    void SetCursorPosition(short x, short y);
    void MoveCurs(Point pos, short m = 2);
    void MoveCurs(short x, short y, short m = 2);
    void Print(Emodji em);
    void SetBeingOnBoard(Being*);
    void PrintBoard();
    bool isValidCell(short x, short y, Point end);
    vector<Point> GetShortestPath(Point start, Point end);
    vector<Point> NormalizePath(Point**, Point);
    vector<vector<Point>> GetAllPaths(Being* b, wchar_t  flag);
    vector<vector<Point>> GetAllPaths(Being* b, vector<Being*>& parteners);
    vector<Point> GetMinPath(vector<vector<Point>>& all_paths, int& ind);
    int FindBeing(Being* b, vector<Being*>& arr)
    {
	for (int i = 0; i < arr.size(); i++)
	{
	    if (arr[i] == b)
		return i;
	}
	return -1;
    }
    vector<Being*> FindBeings(Being::ClassType t, Being::StateM m)
    {
	vector<Being*> ret;
	switch (t)
	{
	case Being::ClassType::FOX:
	case Being::ClassType::CAT:
	case Being::ClassType::TIGER:
	    for (int i = 0; i < predators.size(); i++)
	    {
		if (predators[i]->GetClassType() == t && predators[i]->GetMature() == m)
		    ret.push_back(predators[i]);
	    }
	    break;
	case Being::ClassType::MOUSE:
	case Being::ClassType::RABBIT:
	case Being::ClassType::CHICKEN:
	case Being::ClassType::COW:
	case Being::ClassType::HORSE:
	case Being::ClassType::ZEBRA:
	case Being::ClassType::PIG:
	case Being::ClassType::SQUIRREL:
	    for (int i = 0; i < herbivores.size(); i++)
	    {
		if (herbivores[i]->GetClassType() == t && herbivores[i]->GetMature() == m)
		    ret.push_back(herbivores[i]);
	    }
	    break;
	case Being::ClassType::LEAVES:
	case Being::ClassType::SEEDS:
	case Being::ClassType::SUNFLOWER:
	case Being::ClassType::SEEDING:
	case Being::ClassType::NUT:
	case Being::ClassType::CARROT:
	    for (int i = 0; i < plants.size(); i++)
	    {
		if (plants[i]->GetClassType() == t && plants[i]->GetMature() == m)
		    ret.push_back(plants[i]);
	    }
	    break;
	}
	return ret;
    }
    
    void AnnulateBeing(Being* b, vector<Being*>& arr)
    {
	for (int i = 0; i < arr.size(); i++)
	{
	    if (arr[i]->GetOther() == b)
	    {
		arr[i]->SetOther(nullptr);
		arr[i]->ClearRunPath();
	    }
		
	}
    }
    void DecreaseLifeConsumption();
    void AgeBeings();
    void BornBeings();
    void GrowPlants();
    void BornPredator(Being*, Being::ClassType t= Being::ClassType::BASE, unsigned short count = 1);
    void BornHerbivore(Being*, Being::ClassType t = Being::ClassType::BASE, unsigned short count = 1);
    void GrowPlant(Being*, Being::ClassType t = Being::ClassType::BASE, unsigned short count = 1);
    void RecountStates();
    void MakeLove(Being* b);
    void CheckPartnersForValidity(vector<Being*>& parteners, Being* b)
    {
	if (!parteners.empty())
	{
	    for (auto it = parteners.begin(); it != parteners.end();)
	    {
		if (*it == b)
		{
		    parteners.erase(it);
		    return;
		}
		it++;
	    }
	}

    }
    void SetPredators()
    {
	for (int i = 0; i < predators.size(); i++)
	{
	    vector<vector<Point>> all_paths;
	    switch (predators[i]->GetGoal())
	    {
	    case Being::StateG::FEEDING:
		all_paths = GetAllPaths(predators[i], L'h');
		if (!all_paths.empty())
		{
		    int ind = -1;
		    vector<Point> path = GetMinPath(all_paths, ind);
		    predators[i]->SetPath(path);
		    if (ind != -1)
		       predators[i]->SetOther(herbivores[ind]);
		}
		break;
	    case Being::StateG::REPRODUCTING:
		vector<Being*> parteners = FindBeings(predators[i]->GetClassType(), Being::StateM::ADULT);
		CheckPartnersForValidity(parteners, predators[i]);
		all_paths = GetAllPaths(predators[i], parteners);
		if (!all_paths.empty() )// иначе это путь к самому себе, а не к партнеру
		{
		    int ind = -1;;
		    vector<Point> path = GetMinPath(all_paths, ind);
		    predators[i]->SetPath(path);
		    if (ind != -1)
		    {
			predators[i]->SetOther(parteners[ind]);
			/*predators[i]->SetGoal(Being::StateG::)*/
		    }
		       
		}
		else
		    predators[i]->SetGoal(Being::StateG::FEEDING);
		break;
	    }


	    /* = GetAllPaths(predators[i], L'h');

	  if (!all_paths.empty())
	   {
	       int ind;
	       vector<Point> path = GetMinPath(all_paths, ind);
	       predators[i]->SetPath(path);
	       predators[i]->SetOther(herbivores[ind]);
	   }	*/
	}
    }
    void SetHerbivores()
	{
		for (int i = 0; i < herbivores.size(); i++)
		{
			vector<vector<Point>> all_paths;
			switch (herbivores[i]->GetGoal())
			{
			case Being::StateG::FEEDING:
				all_paths = GetAllPaths(herbivores[i], L'f');
				if (!all_paths.empty())
				{
					int ind = -1;
					vector<Point> path = GetMinPath(all_paths, ind);
					herbivores[i]->SetPath(path);
					if (ind != -1)
					  herbivores[i]->SetOther(plants[ind]);
				}
				break;
			case Being::StateG::REPRODUCTING:
				vector<Being*> parteners = FindBeings(herbivores[i]->GetClassType(), Being::StateM::ADULT);
				CheckPartnersForValidity(parteners, herbivores[i]);
				all_paths = GetAllPaths(herbivores[i], parteners);
				if (!all_paths.empty())
				{
					int ind= -1;
					vector<Point> path = GetMinPath(all_paths, ind);
					herbivores[i]->SetPath(path);
					if (ind != -1)
					  herbivores[i]->SetOther(parteners[ind]);
				}
				break;
			}


			/* = GetAllPaths(predators[i], L'h');

		  if (!all_paths.empty())
		   {
			   int ind;
			   vector<Point> path = GetMinPath(all_paths, ind);
			   predators[i]->SetPath(path);
			   predators[i]->SetOther(herbivores[ind]);
		   }	*/
		}
	}
    void MakeRunPredators()
	{
		for (int i = 0; i < predators.size(); i++)
		{
			if (predators[i]->isRunning())
			{
			    predators[i]->ClearRunPath();
				predators[i]->SetPath(GetShortestPath(predators[i]->GetPos(), predators[i]->GetOther()->GetPos()));

				Point cur = predators[i]->GetPos();
				MoveCurs(cur, 2);
				wcout << L"  "; //L"..";
				predators[i]->Run();
				if (predators[i]->GetPos().x == predators[i]->GetOther()->GetPos().x && predators[i]->GetPos().y == predators[i]->GetOther()->GetPos().y) // если догнал
				{
					RealisePredatorDream(predators[i]);
					/* if (predators[i]->GetGoal() == Being::StateG::FEEDING)
				 {
				  Being* herbiv = predators[i]->GetOther();
				  predators[i]->IncreaseDecreaseLifeEnergy(herbiv->GetLife_energy()); // слопал, сил прибавилось
				  // predators[i]->SetOther(nullptr);

					  // нужно у всех желающих полакомиться уже съеденным животным обнулить указатель на это животное
				  AnnulateBeing(herbiv, predators);

				  // съеденное животное удаляется из массива
				  int b_ind = FindBeing(herbiv, herbivores);
				  if (b_ind >= 0)
				  {
						 delete herbivores[b_ind];
						 herbivores[b_ind] = nullptr;
						 herbivores.erase(herbivores.begin() + b_ind);
						 //predators[i]->SetOther(nullptr);
				  }
				 }
				 else if (predators[i]->GetGoal() == Being::StateG::REPRODUCTING)
				 {
				 MakeLove(predators[i]);
				 }*/
				 /*MoveCurs(predators[i]->GetPos(), 2);
				 wcout << L"  ";*/

				}
			}

		}
	}
    void MakeRunHerbivores()
	{
		for (int i = 0; i < herbivores.size(); i++)
		{
			if (herbivores[i]->isRunning())
			{
			    herbivores[i]->ClearRunPath();
				herbivores[i]->SetPath(GetShortestPath(herbivores[i]->GetPos(), herbivores[i]->GetOther()->GetPos()));

				Point cur = herbivores[i]->GetPos();
				MoveCurs(cur, 2);
				wcout << L"  "; //L"..";
				herbivores[i]->Run();
				if (herbivores[i]->GetPos().x == herbivores[i]->GetOther()->GetPos().x && herbivores[i]->GetPos().y == herbivores[i]->GetOther()->GetPos().y) // если догнал
				{
					RealiseHerbivorDream(herbivores[i]);
				}
			}
		}
	}
    void RealisePredatorDream(Being* hunter)
    {
	Being::StateG goal = hunter->GetGoal();
	switch (goal)
	{
	case Being::StateG::FEEDING:
	{
		Being* herbiv = hunter->GetOther();
		hunter->IncreaseDecreaseLifeEnergy(herbiv->GetLife_energy());// слопал, сил прибавилось
		// нужно у всех желающих полакомиться уже съеденным животным обнулить указатель на это животное
		AnnulateBeing(herbiv, predators);
		// съеденное животное удаляется из массива
		int b_ind = FindBeing(herbiv, herbivores);
		if (b_ind >= 0)
		{
			delete herbivores[b_ind];
			herbivores[b_ind] = nullptr;
			herbivores.erase(herbivores.begin() + b_ind);
		}
	}	    
	    break;
	case Being::StateG::REPRODUCTING:
		// выяснить, кто мама, кто папа
		hunter->SetSex(L'M');
		Being* mother = hunter->GetOther();
		mother->SetOther(nullptr); // мама принимающая сторона
		mother->SetHungriness(Being::StateH::HUNGRY);
		mother->SetGoal(Being::StateG::FEEDING);		
	    MakeLove(hunter);
		int count_children = (hunter->GetEnergyForChild() + mother->GetEnergyForChild()) / hunter->GetLife_energy();
		mother->SetChild_count(count_children);
		hunter->SetOther(nullptr); // охотник выполнил свою задачу
		hunter->SetHungriness(Being::StateH::HUNGRY);
		hunter->SetGoal(Being::StateG::FEEDING);
	    break;
	}
    }
    void RealiseHerbivorDream(Being* hunter)
	{
		Being::StateG goal = hunter->GetGoal();
		switch (goal)
		{
		case Being::StateG::FEEDING:
		{
			Being* plant = hunter->GetOther();
			hunter->IncreaseDecreaseLifeEnergy(plant->GetLife_energy());// слопал, сил прибавилось
			// нужно у всех желающих полакомиться уже съеденным животным обнулить указатель на это животное
			AnnulateBeing(plant, herbivores);
			// съеденное животное удаляется из массива
			int ind = FindBeing(plant, plants);
			if (ind >= 0)
			{
				delete plants[ind];
				plants[ind] = nullptr;
				plants.erase(plants.begin() + ind);
			}
		}
		break;
		case Being::StateG::REPRODUCTING:
			// выяснить, кто мама, кто папа
			hunter->SetSex(L'M');
			Being* mother = hunter->GetOther();
			mother->SetOther(nullptr); // мама принимающая сторона
			mother->SetHungriness(Being::StateH::HUNGRY);
			mother->SetGoal(Being::StateG::FEEDING);
			MakeLove(hunter);
			int count_children = (hunter->GetEnergyForChild() + mother->GetEnergyForChild()) / hunter->GetLife_energy();
			mother->SetChild_count(count_children);
			hunter->SetOther(nullptr); // охотник выполнил свою задачу
			hunter->SetHungriness(Being::StateH::HUNGRY);
			hunter->SetGoal(Being::StateG::FEEDING);
			break;
		}
	}
    void PrintAnimals()
	{
		Point pos;
		for (int i = 0; i < predators.size(); i++)
		{
			pos = predators[i]->GetPos();
			MoveCurs(pos, 2);
			wcout << predators[i]->GetAppearance();
		}
		for (int i = 0; i < herbivores.size(); i++)
		{
			pos = herbivores[i]->GetPos();
			MoveCurs(pos, 2);
			wcout << herbivores[i]->GetAppearance();
		}
		for (int i = 0; i < plants.size(); i++)
		{
		    pos = plants[i]->GetPos();
		    MoveCurs(pos, 2);
		    wcout << plants[i]->GetAppearance();
		}
	}
public:
    AnimalWorld();    
    ~AnimalWorld();
    /*AnimalWorld(HANDLE hwnd, Position curs)
    {
	console = hwnd;
	fcurs_pos = curs;
    }*/
    HANDLE GetConsoleHandle();
    void RunEmulation();
};