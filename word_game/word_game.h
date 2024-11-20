#pragma once
#include <string>
#include <iostream>
#include <random>
#include <fstream>
using namespace std;

class WordGame
{
    static const int MAXSIZE = 10;
    static int choice;

    WordGame();
    static void SetChoice()
    {
	cin >> choice;
	if (choice < 0 && choice > 1)
	    choice = -1;
    }
    
    static bool LoadFile(string path, string* arr)
    {
	ifstream reader(path);
	if (reader)
	{
	    int ind = 0;	    
	    while (!reader.eof() && ind != MAXSIZE)
	    {
		getline(reader, arr[ind]);
		++ind;
	    }
	    /*for (int i = 0; i < MAXSIZE; i++)
		cout << arr[i] << "\n";
	    cout << endl;*/

	    reader.close();
	    return true;
	}
	else
	{
	    cout << "файл не открылся\n";
	    return false;
	}
	    
    }

    static void PrintPhrase(string s1, string s2, string s3, string s4, string s5, string s6, string s7)
    {
	system("cls");
	cout<<"Фраза: \n" << s1 << " " << s2 << " " << s3 << " " << s4 << " " << s5 << " => " << s6 << "\n";
	cout << "Мораль: \n" << s7 << "\n";

    }

    static void Play1()
    {
	/*string who[MAXSIZE];
	string when[MAXSIZE];
	string where[MAXSIZE];
	string with_who [MAXSIZE];
	string did_what[MAXSIZE];
	string result[MAXSIZE];
	string morality[MAXSIZE];*/
	string** gamearr = new string*[7];
	for (int i = 0; i < 7; i++)
	    gamearr[i] = new string[MAXSIZE];

	const int PATHSIZE = 7;
	string paths[PATHSIZE]{ "Who.txt", "When.txt", "Where.txt", "WithWho.txt", "DidWhat.txt", "Result.txt", "Morality.txt" }; // все файлы сохранила в кодировке 1251
	bool isLoaded = false;
	int i = 0;
	do
	{
	    isLoaded = LoadFile(paths[i], gamearr[i]);
	    ++i;
	    if (!isLoaded)
	    {
		cout << "файл не загружен\n";
		for (int i = 0; i < 7; i++)
		    delete[] gamearr[i];
		delete[] gamearr;
		return;
	    }
	} while (isLoaded && i < PATHSIZE);

	char ch = 'Y';
	while (ch == 'Y' || ch == 'y')
	{
	    PrintPhrase(gamearr[0][rand() % MAXSIZE], gamearr[1][rand() % MAXSIZE], gamearr[2][rand() % MAXSIZE], gamearr[3][rand() % MAXSIZE], gamearr[4][rand() % MAXSIZE], gamearr[5][rand() % MAXSIZE], gamearr[6][rand() % MAXSIZE]);
	    cout << "Продолжить?(Y - да, N - нет)";	    
	    cin >> ch;
	}
	for (int i = 0; i < 7; i++)
	    delete[] gamearr[i];
	delete[] gamearr;
    }
    static void FindRhyme(string w, string* arr, int count)
    {
	string temp;
	if (w.length() >= 3)
	    temp = w.substr(w.length() - 3, 3);
	else
	    temp = w;

	for (int i = 0; i < count; i++)
	{
	    if (arr[i].length() >= 3)
	    {
		if (arr[i].substr(arr[i].length() - 3, 3) == temp)
		    cout << arr[i] << "\n";
	    }
	    else
		continue;
	}
    }
    static void Play2()
    {
	int count = 0;
	ifstream reader("teacherNouns.txt");
	if (reader)
	{
	    string temp;
	    while (!reader.eof())
	    {
		getline(reader, temp);
		++count;
	    }
	    string* gamearr = new string[count];
	    reader.clear();
	    reader.seekg(0, ios::beg); 
	    int ind = 0;
	    while (!reader.eof() && ind < count)
	    {
		getline(reader, gamearr[ind]);
		++ind;
	    }
		
	    char ch = 'Y';	    
	    while (ch == 'Y' || ch == 'y')
	    {
		system("cls");
		cout << "Ваше слово: ";
		cin.get();		
		getline(cin, temp);

		FindRhyme(temp, gamearr, count);
		cout << "Продолжить?(Y - да, N - нет)";
		cin >> ch;
	    }
	    delete[] gamearr;
	    reader.close();
	}
	else
	    cout << "файл не открылся\n";
    }

public:

    static void PrintMenu()
    {
	system("cls");
	cout << "1. Составить шуточную фразу.\n";
	cout << "2. Подобрать рифму.\n";
	SetChoice();
    }

    static void Play()
    {
	switch (choice)
	{
	case 1:
	    Play1();
	    break;
	case 2:
	    Play2();
	    break;
	case -1:
	default:
	    cout << "\nВыбор не сделан.\n";
	    break;

	}
    }
};

int WordGame::choice = -1;