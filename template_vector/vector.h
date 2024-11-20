#pragma once
#include <iostream>
#include <random>
using namespace std;
template <typename T, typename K>
class Vector // Vector
{
    T size = 0; // количество действительно присутствующих элементов в контейнере
    T capacity = 10; // ёмкость (вместительность, запас памяти)
    K* data = nullptr; // указатель на динамический массив целых чисел

    void IncreaseCapacity();
    void IncreaseCapacity(T);
    void EnsureCapacity();
    void EnsureCapacity(T);
public:
    Vector() : Vector(10)
    {
	// cout << "C-TOR WITHOUT PARAMS!\n";
    }

    Vector(T capacity)
    {
	if (capacity < 10)
	{
	    capacity = 10;
	}
	this->capacity = capacity;
	data = new K[capacity];
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

    void PushBack(K value)
    {	
	EnsureCapacity(); // проверка, хватит ли места для нового элемента
	data[size] = value;
	size++;
    }

    void PushFront(K value)
    {
	EnsureCapacity();
	for (K i = size; i > 0; i--) // i = 1
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

	for (K i = 0; i < size; i++)
	{
	    cout << data[i] << " ";
	}
	cout << "\n";
    }

    // ...остальные методы...
    bool Insert(T index, K value, T countinsert = 1);
    bool RemoveAt(T index, T countdelete = 1);
    bool RemoveByValue(K value, bool remOne = true);
    bool PopFront();
    bool PopBack();
    bool TrimToSize();
    int IndexOf(K value);
    int LastIndexOf(K value);
    bool Reverse();
    bool SortAsc(); 
    bool SortDesc();
    bool Shuffle();
    bool RandomFill();
    bool Equals(const Vector<T,K>& other);
    int GetElementAt(T);
    Vector<T, K>*& Clone();
    Vector<T, K>(const Vector<T, K>&);
    Vector<T, K>& operator=(const Vector<T, K>&);
 ////  /* void testCopyConstructor(Vector v)
 ////   {	v.Print();
	////cout << "testing" << endl;
 ////   }*/
    K& operator[](T index);
    T GetSize()
    {
	return size;
    }
    T GetCapacity()
    {
	return capacity;
    }
    bool operator==(const  Vector<T, K>& other);
    bool operator!=(const  Vector<T, K>& other);
    bool operator< (const  Vector<T, K>& other);
    bool operator>(const   Vector<T, K>& other);
    bool operator<= (const Vector<T, K>& other);
    bool operator>=(const  Vector<T, K>& other);

    template <typename T, typename K>
    friend ostream& operator<<(ostream& os, Vector<T, K>& v);
    template <typename T, typename K>
    friend istream& operator>>(istream& is, Vector<T, K>& v);
};


template <typename T, typename K>
ostream& operator<<(ostream& os, Vector<T, K>& v)
{
    if (v.IsEmpty())
    {
        os << "Vector is empty.\n";
        return os;
    }

    for (int i = 0; i < v.size; i++)
    {
        os << v.data[i] << " ";
    }
    os << "\n";

    return os;
}

template <typename T, typename K>
istream& operator>>(istream& is, Vector<T, K>& v) {
    unsigned int count;
    cout << "Введите количество элементов вектора: ";
    is >> count;
    v.EnsureCapacity();

    int val;
    try
    {
        for (int i = 0; i < count; i++)
        {
            cout << "Введите элемент # " << i + 1 << ": ";
            is >> val;
            v.PushBack(val);
        }

    }
    catch (exception ex)
    {
        cout << "данные не введены\n Причина: ";
        cout << ex.what() << "\n";
    }
    return is;

}



// Insert (вставка одного элемента в массив по указанному индексу, с проверкой на выход за пределы массива)
template <typename T, typename K>
bool Vector<T, K>::Insert(T index, K value, T countinsert)//куда вставлять, что вставлять, сколько раз
{
    //cout << "\ninside Insert\n";
    if (index < 0 || index > size || countinsert == 0)
        return false;

    if (index == size)                        // если индекс вставки == количесву элементов, то вставляю в конец массива
    {
        for(T i = 0; i < countinsert; i++)
            PushBack(value);
        return true;
    }
        

    EnsureCapacity(countinsert);
    for (K i = size + countinsert-1; i > size + countinsert - 1 - (size - index); i--)
        data[i] = data[i - countinsert];

    size += countinsert;

    while (countinsert)
    {
        data[index] = value;
        --countinsert;
        ++index;
    }
       
    
    //cout << *this;
    return true;
}

//// (удаление одного элемента по указанному индексу. Должна быть проверка на допустимость индекса)
template <typename T, typename K>
bool Vector<T, K>::RemoveAt(T index, T countdelete)
{
    if (IsEmpty())
        return false;

    if (index < 0 || index >= size || countdelete == 0)
        return false;

    if (countdelete >= size - index)   // если пользователь хочет удалить больше элементов, нежели находится правее от указанного индекса, то просто "удаляю" все элементы до конца массива
    {
        size = index;
        return true;
    }

    for (int i = index + countdelete; i < size; i++)
    {
        data[index] = data[i];
        ++index;
    }

    size -= countdelete;

    return true;
}

//// RemoveByValue (удаление одного или всех элементов, значение которых совпадает со значением переданного параметра)
template <typename T, typename K>
bool Vector<T, K>::RemoveByValue(K value, bool remAll)
{
    if (IsEmpty())
        return false;
    for (T i = 0; i < size; i++)
    {
        if (data[i] == value)
        {
            RemoveAt(i);
            --i; // поскольку элемент удален 
            if (remAll)
                continue;
            else
                return true;
        }

    }
    return false; // элемент не найден
}

////  (удаление элемента по индексу 0 из массива)
template <typename T, typename K>
bool Vector<T, K>::PopFront()
{
    return RemoveAt(0);
}

//  (удаление последнего элемента из массива)
template <typename T, typename K>
bool Vector<T, K>::PopBack()
{
    return RemoveAt(size - 1);
}

//(метод подгоняет значение capacity под size, естественно с перевыделением памяти)
template <typename T, typename K>
bool Vector<T, K>::TrimToSize()
{
    if (IsEmpty() || size == capacity)
        return false;

    K* temp = new K[size];
    for (T i = 0; i < size; i++)
    {
        temp[i] = data[i];
    }
    delete[] data;
    data = temp;
    capacity = size;
    return true;
}


//  (линейный поиск слева направо первого вхождения в массив указанного значения. В результате работы вернуть индекс найденного элемента, а eсли ничего не найдено, вернуть -1)
template <typename T, typename K>
int Vector<T, K>::IndexOf(K value)
{
    if (IsEmpty())
        return -1;
    for (T i = 0; i < size; i++)
    {
        if (data[i] == value)
            return i;
    }
    return -1;
}

//LastIndexOf(линейный поиск справа налево вхождения в массив указанного значения.В результате работы вернуть индекс найденного элемента, а eсли ничего не найдено, вернуть - 1)
template <typename T, typename K>
int Vector<T, K>::LastIndexOf(K value)
{
    if (IsEmpty())
        return -1;

    for (T i = size - 1; i >= 0; i--)
    {
        if (data[i] == value)
            return i;
    }
    return -1;
}


//  (изменение порядка следования элементов в массиве на противоположный)
template <typename T, typename K>
bool Vector<T, K>::Reverse()
{
    if (IsEmpty())
        return false;
    for (T i = 0, j = size - 1; i < size / 2; i++, j--)
    {
        K temp = data[i];
        data[i] = data[j];
        data[j] = temp;
    }
    return true;
}

//SortAsc (быстрая сортировка значений элементов массива по возрастанию)
template <typename T, typename K>
bool Vector<T, K>::SortAsc()
{
    if (IsEmpty())
        return false;

    for (T i = size - 1; i > 0; i--)
    {
        for (T j = 0; j < i; j++)
        {
            if (data[j] > data[j + 1])
            {
                K temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
        }
    }
    return true;
}

//  SortDesc (быстрая сортировка значений элементов массива по убыванию)
template <typename T, typename K>
bool Vector<T, K>::SortDesc()
{
    if (IsEmpty())
        return false;

    for (T i = size - 1; i > 0; i--)
    {
        for (T j = 0; j < i; j++)
        {
            if (data[j] < data[j + 1])
            {
                K temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
        }
    }
    return true;
}

template <typename T, typename K>
bool Vector<T, K>::Shuffle()
{
    if (IsEmpty())
        return false;
    for (T i = 0; i < 100; i++)
    {
        T ind1 = rand() % size;
        T ind2 = rand() % size;
        if (ind1 == ind2)
            continue;
        //cout << ind1 << " " << ind2 << endl;
        K temp = data[ind1];
        data[ind1] = data[ind2];
        data[ind2] = temp;
    }
    return true;
}

// (заполнение массива случайными значениями)
template <typename T, typename K>
bool Vector<T, K>::RandomFill()
{
    if (!IsEmpty())
    {
        for (T i = 0; i < size; i++)
        {
            data[i] = rand() % 100;
        }
        return true;
    }
    return false;
}

//  (в качестве параметра передаётся константную ссылку на другой вектор. Метод сравнивает массивы не только по количеству элементов, но и по их содержимому)
template <typename T, typename K>
bool Vector<T, K>::Equals(const Vector<T, K>& other)
{
    return (*this == other);
}

// GetElementAt (возврат копии элемента массива по указанному индексу, с проверкой на выход за пределы массива)
template <typename T, typename K>
int Vector<T, K>::GetElementAt(T index)
{
    if (IsEmpty())
        throw ("вектор пуст!");
    if (index < 0 || index >= size)
        throw out_of_range("индекс за пределами допустимых значений!");
    return data[index];
}

//  (метод создаёт точную копию вектора).
template <typename T, typename K>
Vector<T, K>*& Vector<T, K>::Clone()
{
    Vector* ret = new Vector(size);
    if (!IsEmpty())
    {
        for (T i = 0; i < size; i++)
        {
            ret->PushBack(data[i]);
        }
    }
    return ret;
}
template <typename T, typename K>
Vector<T, K>::Vector(const Vector<T, K>& other)
{
    cout << "\n\n ********* КОНСТРУКТОР  КОПИРОВАНИЯ ДЛЯ " << this << " **********\n\n";


    if (other.size != 0)
    {
        this->capacity = other.capacity;
        this->size = other.size;
        data = new int[capacity];
        //копирую один блок памяти в другой
        // memcpy(data, other.data, sizeof(int) * size);
        // или вот так
        for (T i = 0; i < size; i++)
            data[i] = other.data[i];
    }
    else
    {
        //Vector();
        if (capacity < 10)
        {
            capacity = 10;
        }
        this->capacity = capacity;
        data = new int[capacity];
        size = 0;

    }
}

// перегрузка операции =
template <typename T, typename K>
Vector<T, K>& Vector<T, K>::operator=(const Vector<T, K>& other)
{
    if (*this != other)
    {
        Clear();
        EnsureCapacity(other.size);

        //копирую один блок памяти в другой
        //for (int i = 0; i < other.size; i++)
        //    this->PushBack(other.data[i]);        
        // или так
        // memcpy(data, other.data, sizeof(int) * size);
        // или вот так
        for (T i = 0; i < other.size; i++)
            data[i] = other.data[i];

        this->size = other.size;
    }

    return *this;    //возвращаю объект, чтобы можно было присваивать векторы друг другу в цепочке присваивания
}

// перегрузка операции [ ]
template <typename T, typename K>
K& Vector<T, K>::operator[](T index)
{
    if (IsEmpty())
        throw ("вектор пуст!");
    if (index < 0 || index >= size)
        throw out_of_range("индекс за пределами допустимых значений!");
    return data[index];
}


//// перегрузка операции ==
template <typename T, typename K>
bool Vector<T, K>::operator==(const Vector<T, K>& other)
{
    if (size != other.size)
        return false;
    for (T i = 0; i < size; i++)
    {
        if (data[i] != other.data[i])
            return false;
    }
    return true;
}
template <typename T, typename K>
bool Vector<T, K>::operator!=(const Vector<T, K>& other)
{
    return !(*this == other);
}
template <typename T, typename K>
bool Vector<T, K>::operator< (const  Vector<T, K>& other)
{
    return size < other.size;
}
template <typename T, typename K>
bool Vector<T, K>::operator>(const Vector<T, K>& other)
{
    return size > other.size;
}
template <typename T, typename K>
bool Vector<T, K>::operator<= (const Vector<T, K>& other)
{
    return size <= other.size;
}
template <typename T, typename K>
bool Vector<T, K>::operator>=(const  Vector<T, K>& other)
{
    return size >= other.size;
}

template <typename T, typename K>
void Vector<T, K>::IncreaseCapacity()
{
    T temp_capacity = size + 10;
    K* temp = new K[temp_capacity];
    for (K i = 0; i < size; i++)
        temp[i] = data[i];
    delete data;
    data = temp;
    capacity = temp_capacity;
}
template <typename T, typename K>
void Vector<T, K>::IncreaseCapacity(T min_incr)
{
    T temp_capacity = size + min_incr + 10;
    K* temp = new K[temp_capacity];
    for (K i = 0; i < size; i++)
        temp[i] = data[i];
    delete[] data;
    data = temp;
    capacity = temp_capacity;
}
template <typename T, typename K>
void Vector<T, K>::EnsureCapacity()
{
    /*if (data == nullptr)
        data = new int[10];*/

    if (size == capacity)
        IncreaseCapacity();
}
template <typename T, typename K>
void Vector<T, K>::EnsureCapacity(T incr)
{
    /*if (data == nullptr)
        data = new int[10];*/
    if (size + incr >= capacity)
        IncreaseCapacity(incr);
}