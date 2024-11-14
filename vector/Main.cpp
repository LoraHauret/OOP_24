#pragma once
#include "vector.h"



int main()
{
    setlocale(0, "");
    srand(time(0));
    Vector ar;
    cout << "\nвставка элемента в пустой массив\n";
    bool isInserted = ar.Insert(0, 1);
    ar.Print();
    cout << "\nпопытка вставки с неверным индексом:\n";
    isInserted = ar.Insert(-1, 2);
    if(isInserted == false)
	cout << "элемент не вставлен\n";
    cout << ar;

    isInserted = ar.Insert(2, 2);
    if (isInserted == false)
	cout << "элемент не вставлен\n";
    cout << ar;

    //isInserted = ar.Insert(1, 2);
    // isInserted = ar.Insert(1, 3);
    cout << "\nвставка 2х элементов в конец массива:\n";
    isInserted = ar.Insert(1, 4, 2); // вставка 2х элементов в конец массива
    cout << ar;
    cout << "\nвставка 1 элемента в середину массива по индексу:\n";
    isInserted = ar.Insert(1, 3); // вставка 1 элемента в середину массива по индексу
    cout << ar;    
    cout << "\nвставка 10 элементов в середину массива для проверки пересчета capacity:\n";
    isInserted = ar.Insert(1, 2, 10); // вставка 10 элементов в середину массива для проверки пересчета capacity
    cout << ar;
    // removeat
    cout << "\nУдаление от 2го элемента 9ти элементов:\n";
    ar.RemoveAt(2, 9);
    cout << ar;
    cout << "\nУдаление 4го элемента:\n";
    ar.RemoveAt(4);
    cout << ar;
   
    // добавляю в массив дополнительные элементы
    cout << "\nдобавляю в массив дополнительные элементы\n";
    ar.Insert(3, 5, 2);
    ar.PushBack(5);
    ar.PushFront(5);
    cout << ar;
    cout << "\nудаляю из массива все вхождения 5ки\n";
    ar.RemoveByValue(5, 1);
    cout << ar;

    // удаление первого элемента
    cout << "\nудаление первого элемента\n";
    ar.PopFront();
    ar.Print();
    // удаление последнего элемента
    cout << "\nудаление последнего элемента\n";
    ar.PopBack();
    cout << ar;

    // "очищение" массива
    cout << "\nдля удобства очищаю и заполняю массив последовательно расположенными числами\n";
    ar.Clear();
    ar.PushBack(1);
    ar.PushBack(2);
    ar.PushBack(3);
    ar.PushBack(4);
    ar.PushBack(5);
    ar.PushBack(6);
    ar.PushBack(4);
    ar.PushBack(8);
    cout << ar;

    // Нахожу индекс 4ки
    cout << "\nНахожу индекс 4ки\n";
    cout << ar.IndexOf(4) << "\n";
    cout << "\nНахожу индекс последнего вхождения 4ки\n";
    cout << ar.LastIndexOf(4) << "\n";
    cout << "\nНахожу индекс несуществующего элемента\n";
    cout << ar.IndexOf(14) << "\n";
    cout << "\nРеверсирую массив\n";
    ar.Reverse();
    cout << ar;
    cout << "\nСортирую по возрастанию\n";
    ar.SortAsc();
    cout << ar;
    cout << "\nСортирую по убыванию\n";
    ar.SortDesc();
    cout << ar;
    cout << "\nПеремешиваю значения массива\n";
    ar.Shuffle();
    cout << ar;
    cout << "\nЗаполняю массив случайными значениями\n";
    ar.RandomFill();
    cout << ar;
    cout << "\nделаю трим массиву\nРазмер до прически:\n";
    cout <<"size: "<< ar.GetSize()<<" capacity: "<<ar.GetCapacity() << "\n\n";
    ar.TrimToSize();
    cout << "Размер после укладки:\n";
    cout << "size: " << ar.GetSize() << " capacity: " << ar.GetCapacity() << "\n\n";
    cout << "Сам массив:\n";
    cout << ar;
    cout << "\nполучение значения элемента по индексу\n";
    ar.SortAsc();
    cout << ar;
    try
    {
	cout <<"Элемент по индексу 5: " << ar.GetElementAt(5) << "\n";
	//cout << "Элемент по индексу -1: ";
	//cout<< ar.GetElementAt(-1) << "\n";
	cout << "Элемент по индексу 100: ";
	cout << ar.GetElementAt(100) << "\n";
    }
    catch (exception ex)
    {
	cout << ex.what() << "\n";
    }
    cout << "\nсоздание еще одного вектора2 с таким же размером, как вектор 1\n"; 
    Vector ar2;
    for(int i = 0; i<ar.GetSize(); i++)
	ar2.PushBack(i);
    cout << "массив #2:\n";
    cout << ar2;
    cout << "\nпроверка на равенство: \n";
    cout << "массив ar equals ar2: " << boolalpha << (ar.Equals(ar2)) << endl;
    cout << "массив ar == ar2: " << boolalpha << (ar==ar2) << endl;
    cout << "массив ar != ar2: " << boolalpha << (ar != ar2) << endl;
    cout << "массив ar > ar2: " << boolalpha << (ar > ar2) << endl;
    cout << "массив ar >= ar2: " << boolalpha << (ar >= ar2) << endl;
    cout << "массив ar < ar2: " << boolalpha << (ar < ar2) << endl;
    cout << "массив ar <= ar2: " << boolalpha << (ar <= ar2) << endl;

    cout << "\nсоздание копии вектора 1\n";
    Vector* ar3 = ar.Clone();
    cout << "вектор 1: " << ar;
    cout << "вектор 3: " << *ar3;
    cout << "\nИзменение вектора 1  (popback)\n";
    ar.PopBack();
    cout << "вектор 1: " << ar;
    cout << "вектор 3: " << *ar3;
    cout << "\nИзменение вектора 3  (popfront)\n";
    ar3->PopFront();
    cout << "вектор 1: " << ar;
    cout << "вектор 3: " << *ar3;

    delete ar3;
    cout << "\nсоздание вектора при помощи конструктора копирования.\n";
    Vector ar4(ar);
    cout << "вектор 1: " << ar;
    cout << "вектор 4: " << ar4;
    cout << "\nИзменение вектора 1  (popback)\n";
    ar.PopBack();
    cout << "вектор 1: " << ar;
    cout << "вектор 4: " << ar4;
    cout << "\nИзменение вектора 4  (popfront)\n";
    ar4.PopFront();
    cout << "вектор 1: " << ar;
    cout << "вектор 4: " << ar4;

    // cout << "\n\n";
    cout << "\nсоздаю вектор 6 при помощи пустого вектора 5 для проверки конструктора копирования\n";
    Vector ar5;
    Vector ar6(ar5);
    cout << ar5;
    cout << ar6;
    cout << "\nприсваивание значений ar4 значениям ar5\n"; 
    ar5 = ar4;
    cout << "\nИзменение вектора 4  (popback)\n";
    ar4.PopBack();
    cout << "вектор 4: " << ar4;
    cout << "вектор 5: " << ar5;
    cout << "\nИзменение вектора 5  (popfront)\n";
    ar5.PopFront();
    cout << "вектор 4: " << ar4;
    cout << "вектор 5: " << ar5;

    cout << "\nдоступ к вектору через перегруженные скобки\n";
    for (int i = 0; i < ar5.GetSize(); i++)
    {
	cout << ar5[i] << " ";
	ar5[i] = i;
    }	
    cout << "\n";

    for (int i = 0; i < ar5.GetSize(); i++)
	cout << ar5[i] << " ";
    cout << "\n";
   
    return 1;
}