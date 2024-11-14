#pragma once
#include "stack.h"
using namespace std;

ostream& operator<<(ostream& os, Stack& st)
{
    if (!st.IsEmpty())
    {
	for (list<int>::iterator it = st.data.begin(); it != st.data.end(); it++)
	    cout << *it << " ";
	cout << "\n";
    }
    else
	cout << "стек пуст!\n";
    return os;
}

void Stack::Clear() {
    top = 0;
}

bool Stack::IsEmpty()const
{
    return top == 0;
}
bool Stack::IsFull()const
{
    return false;
}
unsigned int Stack::GetCount() const {
    return top;
}
void Stack::Push(int value) {
    data.push_back(value);
    top++;
}
void Stack::Pop() {
    if (!IsEmpty()) {
	data.pop_back();
	top--;
    }
}
int Stack::Pop(int val)
{
    if (!IsEmpty()) {
	int ret = data.back();
	top--;
	return ret;
    }
    return -1;
}

int Stack::Top() {
    if (!IsEmpty())
	return data.back();
    else throw "Stack is empty!";
}

bool Stack::Contains(int value)
{
    if (!IsEmpty())
    {
	for (list<int>::iterator it = data.begin(); it != data.end(); it++)
	{
	    if (*it == value)
	    {
		return true;
	    }
	}
    }
    return false;
}

void Stack::Print()
{
    cout << *this;
    /*if (!IsEmpty())
    {
	for (list<int>::iterator it = data.begin(); it != data.end(); it++)
	{
	    cout << *it << " ";
	    cout << "\n";
	}
    }
    else
	cout << "стек пуст!";*/
}

// Добавить в реализацию стека на списке метод PushLessValue, который добавляет в стек элемент только в том случае, если его значение меньше, чем у «верхнего» элемента.
bool Stack::PushLessValue(int val)
{
    if (!IsEmpty())
    {
	list<int>::iterator it = data.end();
	if (*(--it) > val)
	{
	    Push(val);
	    return true;
	}
    }
    return false;
}

// Добавить в реализацию стека на списке метод PushUnique, который добавляет в стек элемент только в том случае, если его значение уникально (ещё не содержится в стеке).
bool Stack::PushUnique(int val)
{
    if (!IsEmpty())
    {
	int count = 0;
	for (list<int>::iterator it = data.begin(); it != data.end(); it++)
	{
	    if (*it == val)
	    {
		++count;
	    }
	}
	if (count == 0)
	{
	    Push(val);
	    return true;
	}
    }
    return false;
}