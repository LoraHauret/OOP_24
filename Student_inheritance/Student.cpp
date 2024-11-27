#pragma once
#include "Student.h"
//using namespace std;

Student::Student()
{
    this->SetName();
    this->SetSurname();
    this->SetGroup();
    this->SetAge();   
    marks = new int[ capacity];
    cout << "\nвызван конструктор по умолчанию класса Стьюдент\n";
}

///Вариант 1///
//Student::Student(string n, string srn, size_t gr, size_t a): name(n), surname(srn), group(gr), age(a), marks(new int[20])
//{  }

///Вариант 2///
//Student::Student(string n, string srn, size_t gr, size_t a, size_t count)
//{
//    this->name = n;
//    this->surname = srn;
//    this->group = gr;
//    this->age = age;
//    this->marks_count = count;
//    marks = new int[capacity];
// }


///Вариант 3///
Student::Student(string n, string srn, size_t gr, size_t a)
{
    this->SetName(n);
    this->SetSurname(srn);
    this->SetGroup(gr);
    this->SetAge(a);
    marks = new int[capacity];
    cout << "\nвызван конструктор класса Стьюдент\n";
}
///Вариант 1///
//Student::Student(const Student& other) :name(other.name), surname(other.surname), age(other.age), marks(new int[other.marks_count]), marks_count(other.marks_count)
//{
//    for (int i = 0; i < marks_count; i++)
//	this->marks[i] = other.marks[i];
//}

///Вариант 2///
Student::Student(const Student& other)
{
    this->SetName(other.name);
    this->SetSurname(other.surname);
    this->SetGroup(other.group);
    this->SetAge(other.age);
    this->marks_count = other.marks_count;
    for (int i = 0; i < marks_count; i++)
	this->Mark(other.marks[i]);
    cout << "\nвызван конструктор копирования класса Стьюдент\n";
}
Student::~Student()
{
    if (marks)
    {
	delete[] marks;
	marks = nullptr;
	marks_count = 0;
    }
    cout << "\nвызван деструктор класса Стьюдент\n";
}
Student& Student::operator=(const Student& other)
{
    if (this != &other)
    {
	this->SetName(other.name);
	this->SetSurname(other.surname);
	this->SetGroup(other.group);
	this->SetAge(other.age);
	this->marks_count = other.marks_count;
	for (int i = 0; i < marks_count; i++)
	    this->marks[i] = other.marks[i];
    }
    return *this;
}
string Student::GetName()
{
    return name;
}
string Student::GetSurname()
{
    return surname;
}
size_t Student::GetAge()
{
    return age;
}
size_t Student::GetGroup()
{
    return group;
}
void Student::SetName()
{
   cout << "Имя: ";
   cin >> this->name;
   cout << "\n";
}
void Student::SetName(string name)
{
    this->name = name;
}
void Student::SetSurname()
{
    cout << "Фамилия: ";
    cin >> this->surname;
    cout << "\n";
}
void Student::SetSurname(string surname)
{
    this->surname = surname;
}
void Student::SetGroup()
{
    cout << "Группа: ";
    cin >> this->group;
    cout << "\n";
}
void Student::SetGroup(size_t group)
{
    this->group = group;
}
void Student::SetAge()
{
    cout << "Возраст: ";
    cin >> this->age;
    cout << "\n";
}
void Student::SetAge(size_t age)
{
    this->age = age;
}

void Student::Mark(int m)
{
    if (EnsureCapacity())
    {
	marks[marks_count] = m;
	++marks_count;
    }
    else
	cout << "Оценка не выставлена.\n";
}

bool Student::EnsureCapacity()
{
    if (marks_count < capacity)
	return true;
    else  // (marks_count == capacity)
    {
	int* temp = new int[marks_count + ENLARGEMENT];
	for (int i = 0; i < marks_count; i++)
	    temp[i] = marks[i];
	delete[] marks;
	marks = temp;
	capacity += ENLARGEMENT;
	return true;
    }
    return false;
}

bool Student::operator==(const Student& other) const {
    return (name == other.name && surname == other.surname && age == other.age);
}

bool Student::operator!=(const Student& other) const {
    return !(*this == other); 
}

Student Student::operator+(const Student& other) const {
    Student temp;
    /*temp.name = name;
    temp.surname = surname;
    temp.group = group;
    temp.age = age;*/
    for (int i = 0; i < marks_count; i++)
	temp.Mark(marks[i]);
    for (int i = 0; i < other.marks_count; i++)
	temp.Mark(other.marks[i]);
    return temp;
}
Student::operator string() const
{
    return "\n**********************************************\nИмя: " + name + "\nФамилия: " + surname +"\nВозраст: " + to_string(age) +"\nГруппа: " + to_string(group) + "\n**********************************************\n";
}
std::ostream& operator<<(std::ostream& os, const Student& st)
{
    os << "\n**********************************************\n";
    os<<"Имя: " << st.name << "\n";
    os << "Фамилия: " << st.surname << "\n";
    os << "Возраст: " << st.age << "\n";
    os << "Группа: " << st.group << "\n";

    os << "Оценки:\n";
    for(int i = 0; i< st.marks_count; i++)
	os << st.marks[i] << ", ";
    //os << "\n**********************************************\n";
    os << "\n";
    return os;
}