
#pragma once
#include "vector.h"

ostream& operator<<(ostream& os, Vector& v)
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
istream& operator>>(istream& is, Vector& v) {
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
bool Vector::Insert(int index, int value, int countinsert)//куда вставлять, что вставлять, сколько раз
{     

    if (index < 0 || index > size || countinsert == 0)
        return false;

    if (index == size)                        // если индекс вставки == количесву элементов, то вставляю в конец массива
    {
        for(int i = 0; i < countinsert; i++)
            PushBack(value);
        return true;
    }
        

    EnsureCapacity(countinsert);
    for (int i = size + countinsert-1; i > index; i--)
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
bool Vector::RemoveAt(int index, int countdelete)
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
bool Vector::RemoveByValue(int value, bool remAll)
{
    if(IsEmpty())
        return false;
    for (int i = 0; i < size; i++)
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
bool Vector::PopFront()
{
    return RemoveAt(0);
}

//  (удаление последнего элемента из массива)
bool Vector::PopBack()
{
    return RemoveAt(size-1);
}

  //(метод подгоняет значение capacity под size, естественно с перевыделением памяти)
bool Vector::TrimToSize()
{ 
    if (IsEmpty() || size == capacity)
        return false;

    int* temp = new int[size];
    for (int i = 0; i < size; i++)
    {
        temp[i] = data[i];
    }
    delete[] data;
    data = temp;
    capacity = size;
    return true;
}


//  (линейный поиск слева направо первого вхождения в массив указанного значения. В результате работы вернуть индекс найденного элемента, а eсли ничего не найдено, вернуть -1)
int Vector::IndexOf(int value)
{
    if (IsEmpty())
        return -1;
    for (int i = 0; i < size; i++)
    {
        if (data[i] == value)
            return i;
    }
    return -1;
}

//LastIndexOf(линейный поиск справа налево вхождения в массив указанного значения.В результате работы вернуть индекс найденного элемента, а eсли ничего не найдено, вернуть - 1)
int Vector::LastIndexOf(int value)
{
    if (IsEmpty())
        return -1;
    
    for (int i = size - 1; i >=0 ; i--)
    {
        if (data[i] == value)
            return i;
    }
    return -1;
}


//  (изменение порядка следования элементов в массиве на противоположный)
bool Vector::Reverse()
{
    if (IsEmpty())
        return false;
    for (int i = 0, j = size - 1; i < size / 2; i++, j--)
    {
        int temp = data[i];
        data[i] = data[j];
        data[j] = temp;
    }
    return true;
}

//SortAsc (быстрая сортировка значений элементов массива по возрастанию)
bool Vector::SortAsc()
{
    if (IsEmpty())
        return false;

    for (int i = size-1; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (data[j] > data[j + 1])
            {
                int temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
        }     
    }
    return true;
}

//  SortDesc (быстрая сортировка значений элементов массива по убыванию)
bool Vector::SortDesc()
{
    if (IsEmpty())
        return false;

    for (int i = size - 1; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (data[j] <  data[j + 1])
            {
                int temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
        }
    }
    return true;
}

bool Vector::Shuffle()
{
    if (IsEmpty())
        return false;
    for (int i = 0; i < 100; i++)
    {
        int ind1 = rand() % size;
        int ind2 = rand() % size;
        if (ind1 == ind2)
            continue;
        //cout << ind1 << " " << ind2 << endl;
        int temp = data[ind1];
        data[ind1] = data[ind2];
        data[ind2] = temp;        
    }
    return true;
}

// (заполнение массива случайными значениями)
bool Vector::RandomFill()
{
    if (!IsEmpty())
    {
        for (int i = 0; i < size; i++)
        {
            data[i] = rand() % 100;
        }
        return true;
    } 
    return false;
}

//  (в качестве параметра передаётся константную ссылку на другой вектор. Метод сравнивает массивы не только по количеству элементов, но и по их содержимому)
bool Vector::Equals(const Vector& other)
{
    return (*this == other);
}

// GetElementAt (возврат копии элемента массива по указанному индексу, с проверкой на выход за пределы массива)
int Vector::GetElementAt(int index)
{
    if (IsEmpty())
        throw ("вектор пуст!");
    if (index < 0 || index >= size)
        throw out_of_range("индекс за пределами допустимых значений!");
    return data[index];
}

//  (метод создаёт точную копию вектора).

Vector*& Vector::Clone()
{
    Vector* ret = new Vector(size);
    if (!IsEmpty())
    {
        for(int i = 0; i < size; i++)
        {
            ret->PushBack(data[i]);
        }
    }
    return ret;
}

Vector::Vector(const Vector& other)
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
        for (int i = 0; i < size; i++)
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

Vector& Vector::operator=(const Vector& other)
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
        for (int i = 0; i < other.size; i++)
            data[i] = other.data[i];

        this->size = other.size;
    }
    
    return *this;    //возвращаю объект, чтобы можно было присваивать векторы друг другу в цепочке присваивания
}

// перегрузка операции [ ]
int& Vector::operator[](int index)
{
    if (IsEmpty())
        throw ("вектор пуст!");
    if (index < 0 || index >= size)
        throw out_of_range("индекс за пределами допустимых значений!");
    return data[index];
}


//// перегрузка операции ==
bool Vector::operator==(const Vector& other)
{
    if (size != other.size)
        return false;
    for (int i = 0; i < size; i++)
    {
        if (data[i] != other.data[i])
            return false;
    }
    return true;
}

bool Vector::operator!=(const Vector& other)
{
    return !(*this == other);
}

bool Vector::operator< (const  Vector& other)
{
    return size < other.size;
}
bool Vector::operator>(const   Vector& other)
{
    return size > other.size;
}
bool Vector::operator<= (const Vector& other)
{
    return size <= other.size;
}
bool Vector::operator>=(const  Vector& other)
{
    return size >= other.size;
}

void Vector::IncreaseCapacity()
{
    unsigned int temp_capacity = size + 10;
    int* temp = new int[temp_capacity];
    for (int i = 0; i < size; i++)
        temp[i] = data[i];
    delete data;
    data = temp;
    capacity = temp_capacity;
}
void Vector::IncreaseCapacity(int min_incr)
{
    unsigned int temp_capacity = size + min_incr + 10;
    int* temp = new int[temp_capacity];
    for (int i = 0; i < size; i++)
        temp[i] = data[i];
    delete[] data;
    data = temp;
    capacity = temp_capacity;
}
void Vector::EnsureCapacity()
{
    /*if (data == nullptr)
        data = new int[10];*/

    if (size == capacity)
        IncreaseCapacity();
}
void Vector::EnsureCapacity(int incr)
{
    /*if (data == nullptr)
        data = new int[10];*/
    if (size + incr >= capacity)
        IncreaseCapacity(incr);
}