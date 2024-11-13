#pragma once
#include <iostream>
#include <stdexcept>
#include <random>

using namespace std;


class SinglyLinkedList
{
    //friend ostream& operator<<(ostream& os, SinglyLinkedList li);
    friend ostream& operator<<(ostream& os, const SinglyLinkedList& li);
    friend ostream& operator<<(ostream& os, const SinglyLinkedList*& li);
    class Node
    {
	friend class SinglyLinkedList;
	//friend ostream& operator<<(ostream& os, SinglyLinkedList li);
	friend ostream& operator<<(ostream& os, const SinglyLinkedList& li);
	friend ostream& operator<<(ostream& os, const SinglyLinkedList*& li);
	int data = 0;
	Node* next = nullptr;
	Node(int newvalue);
	Node() {}
    };

    int count;

    Node* head = nullptr;
    Node* tail = nullptr;
    Node* current = nullptr;
    Node*& GetCurrent()
    {
	return current;
    }

public:
    SinglyLinkedList();
    SinglyLinkedList(int value);
    SinglyLinkedList(SinglyLinkedList&);
    SinglyLinkedList& operator=(const SinglyLinkedList&);
    ~SinglyLinkedList();
    void Clear();
    bool IsEmpty();
    int LastIndexOf(int);
    bool ReverseNodes();
    bool ReverseValues();
    bool SortAsc();
    bool SortDesc();
    bool Shuffle();
    bool Equals(SinglyLinkedList*);
    SinglyLinkedList* Clone();
    bool Contains(int);
    bool SetAt(int, int);
    int* ToArray();
    bool MergeWith(SinglyLinkedList&);
    void AddToHead(int data)
    {
	Node* newElem = new Node(data);
	if (head == tail && count == 0)
	{
	    head = tail = current = newElem;
	}
	else
	{
	    newElem->next = head;
	    head = newElem;
	}

	++count;
    }

    void AddToTail(int data)
    {
	Node* newElem = new Node();
	newElem->data = data;
	if (head == tail && count == 0)
	{
	    head = tail = current = newElem;
	}
	else //if (head == tail && count>0)
	{
	    tail->next = newElem;
	    tail = newElem;
	}
	++count;
    }

    void InsertInto(int data, int position)
    {
	if (position >= count)
	{
	    AddToTail(data);
	    return;
	}
	else if (position <= 0)
	{
	    AddToHead(data);
	    return;
	}

	Node* newElem = new Node();
	newElem->data = data;
	int i = 1;
	Node* beforeNew = head;
	while (i++ != position)
	{
	    beforeNew = beforeNew->next;
	}
	newElem->next = beforeNew->next;
	beforeNew->next = newElem;

	count++;
    }

    void DeleteFromHead()
    {
	if (count == 0)
	{
	    // cout << "Empty list!\n";
	    return;
	}
	current = head;
	head = head->next;
	delete current;
	count--;
	if (head == nullptr)
	{
	    tail = nullptr;
	    current = nullptr;
	}
    }

    void DeleteFromTail()
    {
	if (count == 0) {
	    // cout << "Empty list!\n";
	    return;
	}
	DeleteByIndex(count - 1);
    }

    void DeleteByIndex(int position)
    {
	if (position <= 0)
	{
	    DeleteFromHead();
	    return;
	}

	if (position >= count)
	{
	    position = count - 1;
	}

	int i = 1;
	Node* beforeDel = head;
	while (i++ != position)
	{
	    beforeDel = beforeDel->next;
	}
	Node* sacrifice = beforeDel->next;
	beforeDel->next = sacrifice->next;
	delete sacrifice;
	count--;
	if (beforeDel->next == nullptr)
	{
	    tail = beforeDel;
	}
    }

    /*void Clear()
    {
	while (head != nullptr)
	{
	    DeleteFromHead();
	}
    }*/

    void Print() const
    {
	/*if (count == 0)
	{
	    cout << "Empty list!\n";
	    return;
	}
	Node* current = head;
	while (current != nullptr)
	{
	    cout << current->data << " ";
	    current = current->next;
	}
	cout << endl;*/
	cout << *this;
    }

    void testPrint()
    {
	cout << "гол   " << head << " " << head->data << endl;
	cout << "2й    " << head->next << " " << head->next->data << endl;
	cout << "3й    " << head->next->next << " " << head->next->next->data << endl;
	cout << "4й    " << head->next->next->next << " " << head->next->next->next->data << endl;
	cout << "5й    " << head->next->next->next->next << " " << head->next->next->next->next->data << endl;
	cout << "хв    " << tail << " " << tail->data << endl;
	//cout << "cur    " << current << " " << current->data << endl;
    }

    int GetCount() const
    {
	return count;
    }

    int IndexOf(int data) const
    {
	if (count == 0)
	{
	    // cout << "Empty list!\n";
	    return -1;
	}
	Node* temp = head;
	int i = 0;
	while (i < count)
	{
	    if (data == temp->data)
	    {
		return i;
	    }
	    i++;
	    temp = temp->next;
	}

	return -1;
    }

    // перегрузка <, >, <=, >=, ==, !=
    bool operator==(const SinglyLinkedList& other);
    bool operator!=(const SinglyLinkedList& other);
    bool operator< (const SinglyLinkedList& other);
    bool operator>(const SinglyLinkedList& other);
    bool operator<= (const SinglyLinkedList& other);
    bool operator>=(const SinglyLinkedList& other);

    // перегрузка [ ] – обращение к элементу по порядковому номеру
    int& operator[](size_t ind);
    const int& operator[](size_t ind)const;
    //перегрузка + и += (конкатенация списков)
    bool operator+=(const SinglyLinkedList& other);
    SinglyLinkedList*& operator+(const SinglyLinkedList& other);

    //перегрузка операции явного преобразования в int*
    explicit operator int* ()const;
};