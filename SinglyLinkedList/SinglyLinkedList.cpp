#pragma once
#include "SinglyLinkedList.h"


ostream& operator<<(ostream& os, const SinglyLinkedList& li)
{
    if (li.GetCount() == 0)
    {
	os << "Empty list!\n";
	return os;
    }
    SinglyLinkedList::Node* it = li.current;
    it = li.head;
    while (it != nullptr)
    {
	os << it->data << "\t" << it << "\n";
	it = it->next;
    }
    os << endl;
    return os;
}

SinglyLinkedList::Node::Node(int value)
{
    data = value;
}

SinglyLinkedList::SinglyLinkedList()
{
    head = tail = current = new Node;
}
SinglyLinkedList::SinglyLinkedList(int value) :SinglyLinkedList()
{    
    AddToHead(value);
}
SinglyLinkedList::SinglyLinkedList(SinglyLinkedList& other)
{
    if (other.GetCount())
    {
	other.current = other.head;
	while (other.current != nullptr)
	{
	    this->AddToTail(other.current->data);
	    other.current = other.current->next;	    
	}
    }
}
SinglyLinkedList& SinglyLinkedList::operator=(const SinglyLinkedList& other)
{
    if (other.GetCount())
    {
	this->Clear();
	Node* it = other.head;
	while (it != nullptr)
	{
	    this->AddToTail(it->data);
	    it = it->next;
	}
    }
    return *this;
}
void SinglyLinkedList::Clear() // последовательно удаляю все элементы 
{
    while (head != nullptr)
    {
	current = head;
	head = head->next;
	delete current;
    }
    head = tail = current = nullptr;
    count = 0;
}

SinglyLinkedList::~SinglyLinkedList()
{
    Clear();
}

bool SinglyLinkedList::IsEmpty()
{
    return head == tail;
}

int SinglyLinkedList::LastIndexOf(int val)
{
    int ret = -1;
    int current_index = 0;
    current = head;
    while (current != tail)
    {
	if (current->data == val)
	    ret = current_index;
	++current_index;
    }
    if (tail->data == val)
	++ret;
    return ret;
}

bool SinglyLinkedList::ReverseNodes()
{
    if (count > 1)
    {
	while (head != tail)
	{

	    current = head;
	    head = head->next;
	    current->next = tail->next;
	    tail->next = current;
	}
	//cout << "curr " << current << " " << current->data << endl;
	//cout << "head " << head << " " << head->data << endl;
	//cout << "tail" << tail << " " << tail->data << endl;
	//cout << "tail->next" << tail->next << " " << tail->next->data << endl;

	current = head;

	while (tail->next != nullptr)
	{
	    tail = tail->next;
	}
	current = head;
	//cout << "curr " << current << " " << current->data << endl;
	//cout << "head " << head << " " << head->data << endl;
	//cout << "tail" << tail << " " << tail->data << endl;

	return 1;
    }
    return 0;
}
bool SinglyLinkedList::ReverseValues()
{
    if (count > 1)
    {
	tail->next = tail;  // хвост указывает сам на себя

	Node* temp = tail; // вспомогательный итератор, указывает на хвост

	current = head;	// основной итератор указывает на голову и движется слева направо

	int temp_data;  // временная переменная для обмена значениями
	
	for (int i = 0; i < count / 2; i++)
	{
	    temp_data = current->data;  // запоминаю значение во временную переменную
	    current->data = temp->data; // обмениваю значения
	    temp->data = temp_data;

	    current = current->next;  // левый итератор 
	    temp = current->next;  // правый итератор будет искать крайнее положение справа
	    while (temp->next != tail->next)
		temp = temp->next;
	    tail->next = temp;
	}
	tail->next = nullptr;
	return 1;
    }
    return 0;
}

bool SinglyLinkedList::SortAsc()
{
    if (count > 1)
    {
	current = head;
	tail->next = tail;
	Node* temp = head;
	int i = count - 1;
	while (i)
	{
	    while (current != tail->next)
	    {
		if (current->data > current->next->data)  // если больше, поменяла значения
		{
		    int temp_val = current->data;
		    current->data = current->next->data;
		    current->next->data = temp_val;
		}

		current = current->next;
		if (current->next != tail->next && current->next != tail)
		    temp = temp->next;

		//cout << "t " << temp << " " << temp->data << endl;
		//cout << "tl.n " << tail->next << " " << tail->next->data << endl;
		//cout << "c " << current << " " << current->data << endl;
		//testPrint();
	    }
	    current = head;
	    tail->next = temp->next;
	    temp = head;
	    --i;
	}
	tail->next = nullptr;	
	return true;
    }
    return false;
}

bool SinglyLinkedList::SortDesc()
{
    SortAsc();
    return ReverseValues();
}

bool SinglyLinkedList::Shuffle()
{
    int* arr = new int[count]; // массив по размеру списка
    current = head;
    for (int i = 0; i < count && current != nullptr; i++, current = current->next)
    {
	arr[i] = current->data;
	//cout << arr[i] << "\n";
    }
    //cout << "count = " << count << endl;
    for (int i = 0; i < count * 10; i++)
    {
	int ind1 = rand() % count;
	int ind2 = rand() % count;
	if (ind1 == ind2)
	    continue;
	int temp = arr[ind1];
	arr[ind1] = arr[ind2];
	arr[ind2] = temp;

	//cout << ind1 << "\t";
    }
    current = head;
    for (int i = 0; i < count && current != nullptr; i++, current = current->next)
    {
	current->data = arr[i];
	/*cout << arr[i] << " ";*/
    }
    cout << endl;
    delete arr;
    return 0;
}
bool SinglyLinkedList::Equals(SinglyLinkedList* other)
{
    if (this == other)
	return true;
    if (this->count != other->count)
	return false;
    this->current = this->head;
    other->current = other->head;
    while (this->current != this->tail)
    {

	if (this->current->data != other->current->data)
	    return false;
	this->current = this->current->next;
	other->current = other->current->next;
    }
    return true;
}
SinglyLinkedList* SinglyLinkedList::Clone()
{
    SinglyLinkedList* ret = new SinglyLinkedList(*this);
    return ret;
}
bool SinglyLinkedList::Contains(int val)
{
    bool ret = false;
    current = head;
    while (current != nullptr)
    {
	if (current->data == val)
	{
	    ret = true;
	    break;
	}
	current = current->next;
    }

    return ret;
}
bool SinglyLinkedList::SetAt(int ind, int val)
{
    if (ind < 0 || ind >= count)
	return false;
    if (this->count == 0)
	return false;

    current = head;
    for (int i = 0; i < ind; ++i)
    {
	current = current->next;
    }
    current->data = val;
    return true;

}
int* SinglyLinkedList::ToArray()
{
    if (count == 0)
	return nullptr;

    int* ret = new int[count];
    current = head;
    for (int i = 0; i < count && current != nullptr; i++, current = current->next)
    {
	ret[i] = current->data;
    }
    return ret;
}
bool SinglyLinkedList::MergeWith(SinglyLinkedList& other)
{
    if (other.GetCount() != 0)
    {
	other.current = other.head;
	while (other.current != nullptr)
	{
	    this->AddToTail(other.current->data);
	    other.current = other.current->next;
	}
	return true;
    }
    return false;
}
int& SinglyLinkedList::operator[](size_t ind)
{
    if (ind >= count)
	throw out_of_range("индекс вне допустимого диапазона!");
    current = head;
    for (int i = 0; i < ind; i++)
    {
	current = current->next;
    }
    return current->data;
}
const int& SinglyLinkedList::operator[](size_t ind)const
{
    if (ind >= count)
	throw out_of_range("индекс вне допустимого диапазона!");
    Node* it = head;
    for (int i = 0; i < ind; i++)
    {
	it = it->next;
    }
    return it->data;
}
bool SinglyLinkedList::operator==(const SinglyLinkedList& other)
{
    if (this->count != other.count)
	return false;
    this->current = this->head;
    Node* other_current = other.head;
    while (this->current != this->tail)
    {

	if (this->current->data != other_current->data)
	    return false;
	this->current = this->current->next;
	other_current = other_current->next;
    }
    return true;
}

bool SinglyLinkedList::operator!=(const SinglyLinkedList& other)
{
    return !(*this == other);
}
bool SinglyLinkedList::operator< (const SinglyLinkedList& other)
{
    return count < other.count;
}
bool SinglyLinkedList::operator>(const SinglyLinkedList& other)
{
    return count > other.count;
}
bool SinglyLinkedList::operator<= (const SinglyLinkedList& other)
{
    return count <= other.count;
}
bool SinglyLinkedList::operator>=(const SinglyLinkedList& other)
{
    return count > other.count;
}
bool SinglyLinkedList::operator+=(const SinglyLinkedList& other)
{
    if (other.GetCount() != 0)
    {
	Node* other_current = other.head;
	while (other_current != nullptr)
	{
	    this->AddToTail(other.current->data);
	    other_current = other_current->next;
	}
	return true;
    }
    return false;
}
SinglyLinkedList*& SinglyLinkedList::operator+(const SinglyLinkedList& other)
{
    SinglyLinkedList* temp = new SinglyLinkedList;
    if (count != 0)
    {
	current = head;
	while (current != nullptr)
	{
	    temp->AddToTail(current->data);
	    current = current->next;
	}
    }
    if (other.GetCount() != 0)
    {
	Node* other_current = other.head;
	while (other_current != nullptr)
	{
	    temp->AddToTail(other_current->data);
	    other_current = other_current->next;
	}
    }
    return temp;
}
SinglyLinkedList::operator int *()const
{
    if (count == 0)
	return nullptr;

    int* ret = new int[count];
    Node* temp = head;
    for (int i = 0; i < count && temp != nullptr; i++, temp = temp->next)
    {
	ret[i] = temp->data;
    }
    return ret;
}
//int SinglyLinkedList::count = 0;