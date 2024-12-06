#pragma once
#include "AnimalWorld.h"

//const int AnimalWorld::ROW = 45;
//const int AnimalWorld::COL = 85;

void AnimalWorld::SetCursorPosition(short x, short y)
{
    SetConsoleCursorPosition(console, { x, y });
}
void AnimalWorld::SetBeingOnBoard(Being* b)
{
    short x;
    short y;
    do
    {
      x = rand() % ROW;
      y = rand() % COL;
    } while (board[x][y] != 0);
    b->SetPos(x, y);
    //Being::ClassType type = b->GetClassType();
    board[x][y] = (int)b->GetClassType();
}

AnimalWorld::AnimalWorld()
{
    console = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursor;
    GetConsoleCursorInfo(console, &cursor);
    cursor.bVisible = false;
    SetConsoleCursorInfo(console, &cursor);

    /*for (int i = 0; i < ROW; i++)
    {
	for (int j = 0; j < COL; j++)
	{
	    board[i][j] = 0;
	}
    }*/
    //for (int i = 0; i < 5; i++)
    //{
	//Being* foxmale = new Fox();//((short)30, L'M');
	//SetBeingOnBoard(foxmale);
	//predators.push_back(foxmale);	
	//Being* foxfemale = new Fox();
	//foxfemale->SetSex(L'F');
	//SetBeingOnBoard(foxfemale);	
	//predators.push_back(foxfemale);
      BornPredator(nullptr, Being::ClassType::FOX, 2);    
  BornPredator(nullptr, Being::ClassType::CAT, 2);    
    BornPredator(nullptr, Being::ClassType::TIGER, 2);/**/

    BornHerbivore(nullptr, Being::ClassType::RABBIT, 4);
    BornHerbivore(nullptr, Being::ClassType::COW, 4);
   BornHerbivore(nullptr, Being::ClassType::CHICKEN, 8);
    BornHerbivore(nullptr, Being::ClassType::HORSE, 4);
    BornHerbivore(nullptr, Being::ClassType::MOUSE, 10);
    
    BornHerbivore(nullptr, Being::ClassType::PIG,4);
   // BornHerbivore(nullptr, Being::ClassType::SQUIRREL, 6);
    BornHerbivore(nullptr, Being::ClassType::ZEBRA, 4); /**/
    
    GrowPlant(nullptr, Being::ClassType::CARROT, 10);
    GrowPlant(nullptr, Being::ClassType::LEAVES, 10);
    GrowPlant(nullptr, Being::ClassType::NUT, 10);
    GrowPlant(nullptr, Being::ClassType::SEEDING, 10);
    GrowPlant(nullptr, Being::ClassType::SEEDS, 10);
    GrowPlant(nullptr, Being::ClassType::SUNFLOWER, 10);/**///
	/*GrowPlant(nullptr, Being::ClassType::);*/
	//BornHerbivore(nullptr, Being::ClassType::;
   /* BornHerbivore(nullptr, Being::ClassType::RABBIT);
    BornHerbivore(nullptr, Being::ClassType::RABBIT);*/
	//Being* tigermale = new Tiger();//((short)30, L'M');
	//SetBeingOnBoard(tigermale);
	//Being* tigerfemale = new Tiger();
	//tigerfemale->SetSex(L'F');
	//SetBeingOnBoard(tigerfemale);
	//predators.push_back(tigermale);
	//predators.push_back(tigerfemale);

	//Being* catmale = new Cat();//((short)30, L'M');
	//SetBeingOnBoard(catmale);
	//Being* catfemale = new Cat();
	//catfemale->SetSex(L'F');
	//SetBeingOnBoard(catfemale);
	//predators.push_back(catmale);
	//predators.push_back(catfemale);
	//
 //   }

   /* for (int i = 0; i < 5; i++)
    {*/
	/*Being* rabbitmale = new Rabbit();
	SetBeingOnBoard(rabbitmale);
	Being* rabbitfemale = new Rabbit();
	rabbitfemale->SetSex(L'F');
	SetBeingOnBoard(rabbitfemale);
	herbivores.push_back(rabbitmale);
	herbivores.push_back(rabbitfemale);*/

	//Being* cock = new Chicken();
	//SetBeingOnBoard(cock);
	//Being* hen = new Chicken();
	//hen->SetSex(L'F');
	//SetBeingOnBoard(hen);
	//herbivores.push_back(cock);
	//herbivores.push_back(hen);

	//Being* pigmale = new Pig();
	//SetBeingOnBoard(pigmale);
	//Being* pigfemale = new Pig();
	//pigfemale->SetSex(L'F');
	//SetBeingOnBoard(pigfemale);
	//herbivores.push_back(pigmale);
	//herbivores.push_back(pigfemale);

	//Being* bull = new Cow();
	//SetBeingOnBoard(bull);
	//Being* cow = new Cow();
	//cow->SetSex(L'F');
	//SetBeingOnBoard(cow);
	//herbivores.push_back(bull);
	//herbivores.push_back(cow);

	//Being* horsemale = new Horse();
	//SetBeingOnBoard(horsemale);
	//Being* horsefemale = new Horse();
	//horsefemale->SetSex(L'F');
	//SetBeingOnBoard(horsefemale);
	//herbivores.push_back(horsemale);
	//herbivores.push_back(horsefemale);

	//Being* zebramale = new Zebra();
	//SetBeingOnBoard(zebramale);
	//Being* zebrafemale = new Zebra();
	//zebrafemale->SetSex(L'F');
	//SetBeingOnBoard(zebrafemale);
	//herbivores.push_back(zebramale);
	//herbivores.push_back(zebrafemale);

	//Being* mousemale = new Mouse();
	//SetBeingOnBoard(mousemale);
	//Being* mousefemale = new Mouse();
	//mousefemale->SetSex(L'F');
	//SetBeingOnBoard(mousefemale);
	//herbivores.push_back(mousemale);
	//herbivores.push_back(mousefemale);
 //   }
    /*for (int i = 0; i < 20; i++)
    {*/
	/*Being* leaf = new Leaf();
	SetBeingOnBoard(leaf);
	plants.push_back(leaf);
	Being* seed = new Seeds();
	SetBeingOnBoard(seed);
	plants.push_back(seed);
	Being* sunfl = new Sunflower();
	SetBeingOnBoard(sunfl);
	plants.push_back(sunfl);
	Being* seeding = new Seeding();
	SetBeingOnBoard(seeding);
	plants.push_back(seeding);
	Being* nut = new Nut();
	SetBeingOnBoard(nut);
	plants.push_back(nut);
	Being* carrot = new Carrot();
	SetBeingOnBoard(carrot);
	plants.push_back(carrot);
    }   */
}


void AnimalWorld::MoveCurs(Point pos, short m )
{
    SetCursorPosition(pos.y*m, pos.x);
}
void AnimalWorld::MoveCurs(short x, short y, short m)
{
    SetCursorPosition(y*m, x);
}
void AnimalWorld::Print(Emodji em)
{
     wcout << em;
}
HANDLE AnimalWorld::GetConsoleHandle()
{
    return console;
}
void AnimalWorld::PrintBoard()
{
    for (int i = 0; i < predators.size(); i++)
    {
	MoveCurs(predators[i]->GetPos());
	Print(predators[i]->GetAppearance());
    }
    for (int i = 0; i < plants.size(); i++)
    {
	MoveCurs(plants[i]->GetPos());
	Print(plants[i]->GetAppearance());
    }/**/
    for (int i = 0; i < herbivores.size(); i++)
    {
        MoveCurs(herbivores[i]->GetPos());
        Print(herbivores[i]->GetAppearance());
    }
    

   //SetCursorPosition(84*2, 2 );// y двигается вправо/ влвево
   //wcout << 2;		      // x вверх/ вниз 
   // 
    /*predators[0]->SetPos(ROW-1, COL-1);
    MoveCurs(predators[0]->GetPos());
    Print(predators[0]->GetAppearance());*/
    MoveCurs(ROW,0);
    //MoveCurs(1, 83); 
    //wcout << 2;
}
void AnimalWorld::RunEmulation()
{
    /*for (int i = 0; i < 45-1; i++)
	wcout<< 1<< endl;*/
    for (int i = 0; i < ROW; i++)
    {
		for (int j = 0; j < COL; j++)
		{
		    wcout << L"  "; //L"..";
		}
		wcout << endl; 
    }
   PrintBoard();
    /*
    10 хищников
    40 травоядных
    80 растений
    */
 //   short sex = rand() % 2;
 //   Fox f((short)30, sex, 0);
 //   f.SetPos(0, 0);
 //   //Move(f.GetPos());
 //   Being* r = new Rabbit((short)20);
 //   Emodji fox = f.GetAppearance();
 //   for (short i = 0; i <1; i++)//45 - высота
 //   {
	//for (short j = 0; j < 170; j+=2)//85 - ширина
	//{
	//    MoveCurs({ j,  i});
	//    wcout << fox;
	//    /*Move(f.GetPos());
	//    Print(f.GetAppearance());
	//    f.SetPos(j, i);*/
	//    
	//}
	///*Print(r->GetAppearance());
	//r->SetPos(0, i+1);	
	//Move(r->GetPos());
	//Print(r->GetAppearance());*/	
 //   }
 //   //Print(f.GetAppearance());
 //   //Emodji app= f.GetAppearance();
 //   //wchar_t appearance[3]{ app.high_surr, app.low_surr, 0 };
 //   //wcout << f.GetAppearance();/**/

 //   //wcout << endl << endl;
 //   //f.PrintPictures();
 //   
 //   // 
 //   // Being* p = new Plant((short)5);
 //   // wcout << p->GetAppearance();
  /* for (int i = 0; i < ROW; i++)
   {
       for (int j = 0; j < COL; j++)
       {
	   if (board[i][j] == 0)
	       wcout << L'.';
	   else
	    wcout << board[i][j];
       }
       wcout << endl;
   }*/
   // test
   /*predators[0]->SetAge(2);
   predators[0]->SetLife_energy(300);
   predators[0]->SetReproduct(Being::StateR::REPRODUCTIVE);
   predators[0]->SetMature(Being::StateM::ADULT);
   predators[1]->SetAge(2);
   predators[1]->SetLife_energy(200);
   predators[1]->SetReproduct(Being::StateR::REPRODUCTIVE);
   predators[1]->SetMature(Being::StateM::ADULT);*/
   for (int lc = 0; lc < 20; lc++)
   {
       SetPredators();
       SetHerbivores();
 //      	for (int i = 0; i < predators.size(); i++)
	//{
	//    vector<vector<Point>> all_paths;
	//    switch (predators[i]->GetGoal())
	//    {
	//    case Being::StateG::FEEDING:
	//	 all_paths = GetAllPaths(predators[i], L'h');
	//	 if (!all_paths.empty())
	//	 {
	//	     int ind;
	//	     vector<Point> path = GetMinPath(all_paths, ind);
	//	     predators[i]->SetPath(path);
	//	     predators[i]->SetOther(herbivores[ind]);
	//	 }
	//	break;
	//    case Being::StateG::REPRODUCTING:
	//	vector<Being*> parteners = FindBeings(predators[i]->GetClassType(), Being::StateM::ADULT);
	//	all_paths = GetAllPaths(predators[i], parteners);
	//	if (!all_paths.empty())
	//	{
	//	    int ind;
	//	    vector<Point> path = GetMinPath(all_paths, ind);
	//	    predators[i]->SetPath(path);
	//	    predators[i]->SetOther(parteners[ind]);
	//	}
	//	break;
	//    }


	//     /* = GetAllPaths(predators[i], L'h');
	//   if (!all_paths.empty())
	//    {
	//	int ind;
	//	vector<Point> path = GetMinPath(all_paths, ind);
	//	predators[i]->SetPath(path);
	//	predators[i]->SetOther(herbivores[ind]);
	//    }	*/    
	//}
  
       for (int rt = 0; rt < 20; rt++)
       {
		   //for (int i = 0; i < predators.size(); i++)
		   //{
			  // if (predators[i]->isRunning())
			  // {
				 //  predators[i]->SetPath(GetShortestPath(predators[i]->GetPos(), predators[i]->GetOther()->GetPos()));

				 //  Point cur = predators[i]->GetPos();
				 //  MoveCurs(cur, 2);
				 //  wcout << L"..";
				 //  predators[i]->Run();
				 //  if (predators[i]->GetPos().x == predators[i]->GetOther()->GetPos().x && predators[i]->GetPos().y == predators[i]->GetOther()->GetPos().y) // если догнал
				 //  {
					//   RealisePredatorDream(predators[i]);
					//   /* if (predators[i]->GetGoal() == Being::StateG::FEEDING)
					//{
					// Being* herbiv = predators[i]->GetOther();
					// predators[i]->IncreaseDecreaseLifeEnergy(herbiv->GetLife_energy()); // слопал, сил прибавилось
					// // predators[i]->SetOther(nullptr);

					//	 // нужно у всех желающих полакомиться уже съеденным животным обнулить указатель на это животное
					// AnnulateBeing(herbiv, predators);

					// // съеденное животное удаляется из массива
					// int b_ind = FindBeing(herbiv, herbivores);
					// if (b_ind >= 0)
					// {
					//		delete herbivores[b_ind];
					//		herbivores[b_ind] = nullptr;
					//		herbivores.erase(herbivores.begin() + b_ind);
					//		//predators[i]->SetOther(nullptr);
					// }
					//}
					//else if (predators[i]->GetGoal() == Being::StateG::REPRODUCTING)
					//{
					//MakeLove(predators[i]);
					//}*/
					///*MoveCurs(predators[i]->GetPos(), 2);
					//wcout << L"  ";*/

				 //  }
			  // }
		   //}

		   MakeRunPredators();
		   MakeRunHerbivores();
			  /* MoveCurs(predators[i]->GetPos(), 2);
			   wcout << predators[i]->GetAppearance();*/
		   //system("cls");
		   PrintAnimals();


	   /*       for (int i = 0; i < predators.size(); i++)
		  {
		      if (predators[i]->isRunning())
		      {
			  MoveCurs(predators[i]->GetPos(), 2);
			  wcout<<predators[i]->GetAppearance();

		      }
		  }*/
	   Sleep(100);
	   MoveCurs(ROW - 1, 0);
	   
       }
       DecreaseLifeConsumption(); // за цикл израсходовалась часть жизненной энергии
       AgeBeings();
       BornBeings();
       if (lc%3 == 0) // растения растут каждый 3й цикл
	   GrowPlants();
       RecountStates(); // пересчет состояний всех существ
       PrintBoard();
       
       
   }
   

   // найти минимальный путь
   //int min = all_paths[0].size();
   //int ind = 0;
   //for (int i = 1; i < all_paths.size(); i++) // поиск ближайшей добычи
   //{
   //    if (all_paths[i].size() < min)
   //    {
	  //  min = all_paths[i].size();
	  //  ind = i;
   //    }	   
   //}


   //vector<Point> path = GetShortestPath(first->GetPos(), second->GetPos());
   //if (!all_paths.empty())
   //{
   //    Point cur;// = first->GetPos();
   //    for (int i = 0; i < all_paths[ind].size() - 1; i++)
   //    {
	  // Sleep(500);
	  // cur = first->GetPos();
	  // MoveCurs(cur, 2);
	  // wcout << "..";
	  // first->SetPos(all_paths[ind][i + 1].x, all_paths[ind][i + 1].y);
	  // MoveCurs(first->GetPos(), 2);
	  // Print(first->GetAppearance());
   //    }
   //} 
}

bool AnimalWorld::isValidCell(short x, short y, Point end)
{
    if (x >= 0 && x < ROW && y >= 0 && y < COL)
    {
	if (board[x][y] == 0)
	{
	    return true;	    
	}	    
	else if (x == end.x && y == end.y)
	{
	    return true;
	}
    }
    return false;
}


//void printQ(queue<Point> q)
//{
//    queue<Point> temp = q;
//    auto var = temp.front();
//    while (var.x != q.back().x && var.y != q.back().y)
//    {
//	wcout << L"X:" << var.x << L" Y:" << var.y<<L'; ';
//	temp.pop();
//	var = temp.front();
//    }  
//    wcout << endl;
//    
//}
void printP(Point** arr, int r, int c)
{
    for (int i = 0; i < r; i++)
    {
	for (int j = 0; j < c; j++)
	{
	    wcout << arr[i][j].x << arr[i][j].y << L' ';
	    
	}wcout << endl;
	
    }wcout << endl << endl;
}

vector<Point> AnimalWorld::GetShortestPath(Point start, Point end)
{
    vector<Point> path;
    bool visited[ROW][COL] = { false };
    queue<Point> find_path;
    Point** points = new Point*[ROW];
        
    for (int i = 0; i < ROW; i++)
    {
	points[i] = new Point[COL];
	for (int j = 0; j < COL; j++)
	{
	    points[i][j].x = -1;
	    points[i][j].y = -1;
	}
    }
    
    find_path.push(start);
    visited[start.x][start.y] = true;

    while (!find_path.empty()) 
    {
	//printQ(find_path);

	Point cur = find_path.front();
	find_path.pop();

	if (cur.x == end.x && cur.y == end.y) // если найдено 
	{
	    path = NormalizePath(points, end);   
	    break;
	}

	for (int i = 0; i < 4; i++) // проверка 4 клеток рядом
	{
	    int curX = cur.x + dir[i][0]; // узнала координаты клетки по одному из направлений
	    int curY = cur.y + dir[i][1];
	    
	    if (isValidCell(curX, curY, end) && !visited[curX][curY])
	    {
		visited[curX][curY] = true;
		points[curX][curY] = cur;    // элемент по данным координатам будет содержать координаты предыдущего элемента 
		find_path.push(Point(curX, curY));
		//printP(points, ROW, COL);
	    }
	}
    }

    for (int i = 0; i < ROW; i++)
    {
	delete[] points[i];
    }
    delete[] points;
    return path;  
}
vector<vector<Point>> AnimalWorld::GetAllPaths(Being* b, wchar_t  flag)
{
    vector<vector<Point>> ret;
    switch (flag)
    {
	case L'p':
	    for (int i = 0; i < predators.size(); i++)
	    {
		vector<Point> path = GetShortestPath(b->GetPos(), predators[i]->GetPos());
		if (!path.empty())
		    ret.push_back(path);
	    }
	    break;
	case L'h':
	    for (int i = 0; i < herbivores.size(); i++)
	    {
		vector<Point> path = GetShortestPath(b->GetPos(), herbivores[i]->GetPos());
		if (!path.empty())
		    ret.push_back(path);
	    }
	    break;
	case L'f':
	    for (int i = 0; i < plants.size(); i++)
	    {
		vector<Point> path = GetShortestPath(b->GetPos(), plants[i]->GetPos());
		if (!path.empty())
		    ret.push_back(path);
	    }
	default:
	    break;
    }
    return ret;
}
vector<vector<Point>> AnimalWorld::GetAllPaths(Being* b, vector<Being*>& parteners)
{
    vector<vector<Point>> ret;
	for (int i = 0; i < parteners.size(); i++)
	{
	    vector<Point> path = GetShortestPath(b->GetPos(), parteners[i]->GetPos());
	    if (!path.empty())
		ret.push_back(path);
	}
    return ret;
}

vector<Point> AnimalWorld::GetMinPath(vector<vector<Point>>& all_paths, int& ind)
{
    vector<Point> ret;

    if (!all_paths.empty())
    {
	// Удаление путей с одним элементом
	for (auto it = all_paths.begin(); it != all_paths.end(); )
	{
	    if (it->size() == 1) {
		it = all_paths.erase(it); // Удаление и переход к следующему элементу
	    }
	    else {
		++it;
	    }
	}

	
	if (!all_paths.empty()) // Поиск минимального пути
	{
	    size_t min = all_paths[0].size();
	    ind = 0;
	    for (int i = 1; i < all_paths.size(); i++) // поиск ближайшей добычи
	    {
		if (all_paths[i].size() < min)
		{
		    min = all_paths[i].size();
		    ind = i;
		}
	    }
	    if(ind != -1)
	       ret = all_paths[ind];
	}
    }

    return ret;
}

//vector<Point> AnimalWorld::GetMinPath(vector<vector<Point>> & all_paths, int &ind)
//{
//    vector<Point> ret;
//    // найти минимальный путь
//    if (!all_paths.empty())
//    {
//	for (int i = 0; i < all_paths.size() && !all_paths.empty(); i++)
//	{
//	    if (all_paths[i].size() == 1)
//		all_paths.erase(all_paths.begin() + i);
//	}
//
//	int min = all_paths[0].size();
//	for (int i = 1; i < all_paths.size() && !all_paths.empty(); i++) // поиск ближайшей добычи
//	{
//	    if (all_paths[i].size() < min)
//	    {
//		min = all_paths[i].size();
//		ind = i;
//	    }
//	}
//	ret = all_paths[ind];
//    }    
//    return ret;
//}

vector<Point> AnimalWorld::NormalizePath(Point** points, Point end)
{
    vector<Point> path;
    Point cur = end;
    
    /*for (int i = 0; i < ROW; i++)
    {
	for (int j = 0; j < COL; j++)
	{
	    cout << points[i][j].x << " " << points[i][j].y << "\t";
	}
	cout << endl;
    }
    cout << endl;*/
    while (cur.x != -1 && cur.y != -1)
    {
	path.push_back(cur);
	cur = points[cur.x][cur.y];
    }

    reverse(path.begin(), path.end());
    return path;
}
void  AnimalWorld::DecreaseLifeConsumption()
{
    for (int i = 0; i < predators.size(); i++)
    {
	predators[i]->IncreaseDecreaseLifeEnergy();
    }
    for (int i = 0; i < herbivores.size(); i++)
    {
	herbivores[i]->IncreaseDecreaseLifeEnergy();
    }
    for (int i = 0; i < plants.size(); i++)
    {
	plants[i]->IncreaseDecreaseLifeEnergy();
    }
}

void AnimalWorld::AgeBeings()
{
    for (int i = 0; i < predators.size(); i++)
    {
	predators[i]->SetAge(predators[i]->GetAge() +1);
    }
    for (int i = 0; i < herbivores.size(); i++)
    {
	herbivores[i]->SetAge(herbivores[i]->GetAge() + 1);
    }
    for (int i = 0; i < plants.size(); i++)
    {
	plants[i]->SetAge(plants[i]->GetAge() + 1);
    }
}
void AnimalWorld::BornBeings()
{
	for (int i = 0; i < predators.size(); i++)
	{
		unsigned short count = predators[i]->GetChild_count();
		if (count > 0)
		{
			BornPredator(predators[i], predators[i]->GetClassType(), count);
			predators[i]->SetChild_count(0);
		}
	}
    
    for (int i = 0; i < herbivores.size(); i++)
    {
		unsigned short count = herbivores[i]->GetChild_count();
		if (count > 0)
		{
			BornHerbivore(herbivores[i], herbivores[i]->GetClassType(), count);
			herbivores[i]->SetChild_count(0);
		}
	//herbivores[i]->SetAge(herbivores[i]->GetAge() + 1);
    }
   
   
}

void AnimalWorld::GrowPlants()
{
    for (int i = 0; i < plants.size(); i++)
    {
	//plants[i]->SetAge(plants[i]->GetAge() + 1);
	if (plants[i]->GetMature() == Being::StateM::ADULT)
	{
	    /*int cnt = rand() % 10;
	    for (int i = 0; i < cnt; i++)
	    {
		if(i%5 == 0)	//регуляция плодородности растений*/
	    GrowPlant(plants[i]);

	    //}

	}

    }
}
void AnimalWorld::BornPredator(Being* b, Being::ClassType t, unsigned short count)
{
    Being::ClassType type;
    if (!b)
    {
	type = t;
    }
    else
    {
	type = b->GetClassType();
    }
    short s;
    for (int i = 0; i < count; i++)
    {	
	switch (type)
	{
	case Being::ClassType::FOX:
	    s  = rand() % 2;
	    if (s == 0)
	    {
		Being* foxmale = new Fox();
		SetBeingOnBoard(foxmale);
		predators.push_back(foxmale);
	    }
	    else
	    {
		Being* foxfemale = new Fox();
		foxfemale->SetSex(L'F');
		SetBeingOnBoard(foxfemale);
		predators.push_back(foxfemale);
	    }    
	    break;
	case Being::ClassType::CAT:
	    s = rand() % 2;
	    if (s == 0)
	    {
		Being* catmale = new Cat();//((short)30, L'M');
		SetBeingOnBoard(catmale);
		
		predators.push_back(catmale);
	    }
	    else
	    {
		Being* catfemale = new Cat();
		catfemale->SetSex(L'F');
		SetBeingOnBoard(catfemale);
		
		predators.push_back(catfemale);
	    }
	    break;
	case Being::ClassType::TIGER:
	    s = rand() % 2;
	    if (s == 0)
	    {
		Being* tigermale = new Tiger();//((short)30, L'M');
		SetBeingOnBoard(tigermale);
		predators.push_back(tigermale);
	    }
	    else
	    {
		Being* tigerfemale = new Tiger();
		tigerfemale->SetSex(L'F');
		SetBeingOnBoard(tigerfemale);
		predators.push_back(tigerfemale);
	    }
	    break;
	default:
	    Being* unknown = new Being();
	    unknown->SetSex(L'F');
	    SetBeingOnBoard(unknown);
	    predators.push_back(unknown);
	    break;

	}
    }
}

void AnimalWorld::BornHerbivore(Being* b, Being::ClassType t, unsigned short count)
{
    Being::ClassType type;
    if (!b)
    {
	type = t;
    }
    else
    {
	type = b->GetClassType();
    }
    short s;
    for (int i = 0; i < count; i++)
    {
	switch (type)
	{
	case Being::ClassType::RABBIT:
	    s = rand() % 2;
	    if (s == 0)
	    {
		Being* rabbitmale = new Rabbit();
		SetBeingOnBoard(rabbitmale);
		herbivores.push_back(rabbitmale);
	    }
	    else
	    {
		Being* rabbitfemale = new Rabbit();
		rabbitfemale->SetSex(L'F');
		SetBeingOnBoard(rabbitfemale);
		herbivores.push_back(rabbitfemale);
	    }
	    break;
	case Being::ClassType::CHICKEN:
	    s = rand() % 2;
	    if (s == 0)
	    {
		Being* cock = new Chicken();
		SetBeingOnBoard(cock);
		herbivores.push_back(cock);
	    }
	    else
	    {
		Being* hen = new Chicken();
		hen->SetSex(L'F');
		SetBeingOnBoard(hen);
		herbivores.push_back(hen);
	    }
	    break;
	case Being::ClassType::PIG:
	    s = rand() % 2;
	    if (s == 0)
	    {
		Being* pigmale = new Pig();
		SetBeingOnBoard(pigmale);
		herbivores.push_back(pigmale);
	    }
	    else
	    {
		Being* pigfemale = new Pig();
		pigfemale->SetSex(L'F');
		SetBeingOnBoard(pigfemale);
		herbivores.push_back(pigfemale);
	    }
	    break;
	case Being::ClassType::COW:
	    s = rand() % 2;
	    if (s == 0)
	    {
		Being* bull = new Cow();
		SetBeingOnBoard(bull);
		herbivores.push_back(bull);
	    }
	    else
	    {
		Being* cow = new Cow();
		cow->SetSex(L'F');
		SetBeingOnBoard(cow);
		herbivores.push_back(cow);
	    }
	    break;
	case Being::ClassType::HORSE:
	    s = rand() % 2;
	    if (s == 0)
	    {
		Being* horsemale = new Horse();
		SetBeingOnBoard(horsemale);
		herbivores.push_back(horsemale);
	    }
	    else
	    {
		Being* horsefemale = new Horse();
		horsefemale->SetSex(L'F');
		SetBeingOnBoard(horsefemale);
		herbivores.push_back(horsefemale);
	    }
	    break;
	case Being::ClassType::ZEBRA:
	    s = rand() % 2;
	    if (s == 0)
	    {
		Being* zebramale = new Zebra();
		SetBeingOnBoard(zebramale);
		herbivores.push_back(zebramale);
	    }
	    else
	    {
		Being* zebrafemale = new Zebra();
		zebrafemale->SetSex(L'F');
		SetBeingOnBoard(zebrafemale);
		herbivores.push_back(zebrafemale);
	    }
	    break;
	case Being::ClassType::MOUSE:
	    s = rand() % 2;
	    if (s == 0)
	    {
		Being* mousemale = new Mouse();
		SetBeingOnBoard(mousemale);
		herbivores.push_back(mousemale);
	    }
	    else
	    {
		Being* mousefemale = new Mouse();
		mousefemale->SetSex(L'F');
		SetBeingOnBoard(mousefemale);
		herbivores.push_back(mousefemale);
	    }
	default:
	    break;
	}
    }
}
void AnimalWorld::GrowPlant(Being* parent, Being::ClassType t, unsigned short count)
{
	Being::ClassType type;
	if (!parent)
		type = t;
	else
		type=parent->GetClassType();
	Being* plant = nullptr;
	for (int i = 0; i < count; i++)
	{
	    switch (type)
	    {
	    case Being::ClassType::CARROT:
		plant = new Carrot();
		break;
	    case Being::ClassType::LEAVES:
		plant = new Leaf();
		break;
	    case Being::ClassType::NUT:
		plant = new Nut();
		break;
	    case Being::ClassType::SEEDING:
		plant = new Seeding();
		break;
	    case Being::ClassType::SEEDS:
		plant = new Seeds();
		break;
	    case Being::ClassType::SUNFLOWER:
		plant = new Sunflower();
	    default:
		break;
	    }

	    if (plant != nullptr)
	    {
		SetBeingOnBoard(plant);
		plants.push_back(plant);
	    }
	}
									
}
void AnimalWorld::RecountStates()
{
    for (int i = 0; i < predators.size(); i++)
    {
	predators[i]->RecountStates();
    }
    for (int i = 0; i < herbivores.size(); i++)
    {
	herbivores[i]->RecountStates();
    }
    for (int i = 0; i < plants.size(); i++)
    {
	plants[i]->RecountStates();
    }
}

void AnimalWorld::MakeLove(Being* b)
{
    queue<Emodji> love_q;
    string arr[] = { "chili", "mouth", "kiss", "heart", "chili", "mouth", "kiss" };

    for (int i = 0; i < arr->size(); i++)
    {
	auto it = Being::pictures.find(arr[i]);
	if (it != Being::pictures.end())
	{
	    love_q.push(it->second);
	    //love_q.push(b->GetAppearance());		
	}
    }
    PrintAnimals();
    Point pos1 = b->GetPos();/*
    Point pos2 = pos1;
    pos2.x -= 1;*/

    while (!love_q.empty())
    {
	MoveCurs(pos1, 2);
	wcout << L"  ";/*L"..";*/
	MoveCurs(pos1, 2);
	wcout << love_q.front();
	Sleep(500);
	MoveCurs(pos1, 2);
	wcout << L"  ";/*L"..";*/
	love_q.pop();
	Sleep(500);
    }
    MoveCurs(pos1, 2);
    wcout << b->GetAppearance();
}
AnimalWorld::~AnimalWorld()
{
    for (int i = 0; i < plants.size(); i++)
    {
	delete plants[i];
	plants[i] = 0;
    }
    plants.clear();
    for (int i = 0; i < herbivores.size(); i++)
    {
	delete herbivores[i];
	herbivores[i] = 0;
    }
    herbivores.clear();
    for (int i = 0; i < predators.size(); i++)
    {
	delete predators[i];
	predators[i] = 0;
    }
    predators.clear();
}