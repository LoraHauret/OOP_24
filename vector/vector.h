#pragma once
#include <iostream>
#include <random>
using namespace std;
/*
- Insert (вставка одного элемента в массив по указанному индексу, с проверкой на выход за пределы массива)
- RemoveAt (удаление одного элемента по указанному индексу. Должна быть проверка на допустимость индекса)
- RemoveByValue (удаление одного или всех элементов, значение которых совпадает со значением переданного параметра)
- PopFront (удаление элемента по индексу 0 из массива)
- PopBack (удаление последнего элемента из массива)
- TrimToSize (метод подгоняет значение capacity под size, естественно с перевыделением памяти)
- IndexOf (линейный поиск слева направо первого вхождения в массив указанного значения. В результате работы вернуть индекс найденного элемента, а eсли ничего не найдено, вернуть -1)
- LastIndexOf (линейный поиск справа налево вхождения в массив указанного значения. В результате работы вернуть индекс найденного элемента, а eсли ничего не найдено, вернуть -1)
- Reverse (изменение порядка следования элементов в массиве на противоположный)
- SortAsc (быстрая сортировка значений элементов массива по возрастанию)
- SortDesc (быстрая сортировка значений элементов массива по убыванию)
- Shuffle (случайное перемешивание элементов массива)
- RandomFill (заполнение массива случайными значениями)
- Equals (в качестве параметра передаётся константную ссылку на другой вектор. Метод сравнивает массивы не только по количеству элементов, но и по их содержимому)
- GetElementAt (возврат копии элемента массива по указанному индексу, с проверкой на выход за пределы массива)
- Clone (метод создаёт точную копию вектора).
- конструктор копирования
- перегрузка операции =
- перегрузка операции [ ]
- перегрузка операции ==
- перегрузка >>  и <<
*/

class Vector // Vector
{
    unsigned int size = 0; // количество действительно присутствующих элементов в контейнере
    unsigned int capacity = 10; // ёмкость (вместительность, запас памяти)
    int* data = nullptr; // указатель на динамический массив целых чисел

    void IncreaseCapacity();
    void IncreaseCapacity(int);
    void EnsureCapacity();
    void EnsureCapacity(int);
public:
    Vector() : Vector(10)
    {
	// cout << "C-TOR WITHOUT PARAMS!\n";
    }

    Vector(unsigned int capacity)
    {
	if (capacity < 10)
	{
	    capacity = 10;
	}
	this->capacity = capacity;
	data = new int[capacity];
	// cout << "C-TOR WITH PARAMS!\n";
	cout << "\n\n ********* КОНСТРУКТОР ДЛЯ " << this << " **********\n\n";
    }

    ~Vector()
    {
	cout << "\n\n ********* ДЕСТРУКТОР ДЛЯ " << this << " **********\n\n";	
	// cout << "DESTRUCTOR!\n";
	if (data != nullptr)
	{
	    delete[] data;
	    data = nullptr;
	}
    }

    void PushBack(int value)
    {
	EnsureCapacity(); // проверка, хватит ли места для нового элемента
	data[size] = value;
	size++;
    }

    void PushFront(int value)
    {
	EnsureCapacity();
	for (int i = size; i > 0; i--) // i = 1
	{
	    data[i] = data[i - 1]; // data[1] = data[0]
	}
	data[0] = value;
	size++;
    }

    void Clear()
    {
	size = 0;
    }

    bool IsEmpty() const
    {
	return size == 0;
    }

    void Print() const
    {
	if (IsEmpty())
	{
	    cout << "Vector is empty.\n";
	    return;
	}

	for (int i = 0; i < size; i++)
	{
	    cout << data[i] << " ";
	}
	cout << "\n";
    }

    // ...остальные методы...
    bool Insert(int index, int n, int countinsert = 1);
    bool RemoveAt(int index, int countdelete = 1);
    bool RemoveByValue(int value, bool remOne = true);
    bool PopFront();
    bool PopBack();
    bool TrimToSize();
    int IndexOf(int value);
    int LastIndexOf(int value);
    bool Reverse();
    bool SortAsc(); 
    bool SortDesc();
    bool Shuffle();
    bool RandomFill();
    bool Equals(const Vector& other);
    int GetElementAt(int);
    Vector*& Clone();
    Vector(const Vector&);
    Vector& operator=(const Vector&);
 //  /* void testCopyConstructor(Vector v)
 //   {	v.Print();
	//cout << "testing" << endl;
 //   }*/
    int& operator[](int index);
    int GetSize()
    {
	return size;
    }
    int GetCapacity()
    {
	return capacity;
    }
    bool operator==(const  Vector& other);
    bool operator!=(const  Vector& other);
    bool operator< (const  Vector& other);
    bool operator>(const   Vector& other);
    bool operator<= (const Vector& other);
    bool operator>=(const  Vector& other);

    friend ostream& operator<<(ostream& os, Vector& v);
};

