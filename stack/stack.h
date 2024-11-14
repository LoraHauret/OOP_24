#pragma once
#include <iostream>
#include <list>
#include <random>
using namespace std;

class Stack {
    list<int> data; // пример реализации стека на списке
    unsigned int top = 0; // индекс, по которому будет добавляться очередной новый элемент
    // также индекс можно воспринимать как количество элементов, которые были добавлены в стек на данный момент

public:
    void Clear(); 
    bool IsEmpty()const;
    bool IsFull() const;
    unsigned int GetCount() const;
    void Push(int value);
    void Pop();
    int Pop(int);
    int Top();
    bool Contains(int value);
    void Print();
    bool PushLessValue(int val);
    bool PushUnique(int val);
    friend ostream& operator<<(ostream& os, Stack& st);
};

