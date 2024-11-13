#pragma once
#include "SinglyLinkedList.h"

int main()
{
    setlocale(0, "");
    srand(time(0));
    SinglyLinkedList sll;
    /*sll.Print();*/    
   // sll.AddToHead(2);   
   // // вставка в конец списка
   // sll.AddToTail(8);

   // sll.AddToTail(3);
   // sll.AddToTail(30);
   // sll.AddToTail(40);
   // sll.Print();
  

   // // вставка в начало списка
   // sll.AddToHead(50);
   // sll.AddToHead(7);
   // sll.AddToHead(70);
   // sll.AddToHead(80);
   // sll.Print();
 

   // // количество элементов, поиск элементов
   // cout << "count: " << sll.GetCount() << "\n";
   // cout << "index of 70: " << sll.IndexOf(70) << ", index of 90: " << sll.IndexOf(90) << "\n";

   // // вставка по позиции
   // sll.InsertInto(-1, -1);
   //sll.Print();
   //  /*sll.testPrint();*/
   // sll.InsertInto(2, 2);
   // sll.Print();
   //
   // sll.InsertInto(22, 22);
   // /*sll.Print();*/
   // sll.testPrint();

   // // удаление с начала списка
   // sll.DeleteFromHead();
   // sll.DeleteFromHead();
   // sll.DeleteFromHead();
   // sll.Print();

   // // удаление с конца списка
   // sll.DeleteFromTail();
   // sll.DeleteFromTail();
   // sll.DeleteFromTail();
   // sll.Print();

   // // удаление по указанному индексу
   // sll.DeleteByIndex(0);
   // sll.DeleteByIndex(1);
   // sll.Print();
   // 
   // cout << endl;

    // очистка списка
    //sll.Clear();
    //sll.Print();
    sll.AddToTail(8);
    sll.AddToTail(2);
    sll.AddToTail(11);
    sll.AddToTail(7);
    sll.AddToTail(4);
    sll.AddToTail(1);  

    sll.AddToHead(8);
    sll.AddToHead(2);
    sll.AddToHead(11);
    sll.AddToHead(7);
    sll.AddToHead(4);
    sll.AddToHead(1);

    cout << "\nперед реверсированием значений\n" << endl;
    sll.Print();
    sll.ReverseValues();
    cout << "\nпосле реверсирования значений\n" << endl;
    sll.Print();    
    sll.ReverseNodes();
    cout << "\nпосле реверсирования узлов\n" << endl;
    sll.Print();
    cout << "\nпсортировка по возрастанию\n" << endl;
    sll.SortAsc();
    sll.Print();
    cout << endl;
    cout << "\nсортировка по убыванию\n" << endl;
    sll.SortDesc();
    sll.Print();
    cout << endl;
    cout << "\nПеремешивание значений списка\n" << endl;
    sll.Shuffle();
    sll.Print();
    cout << "\n";

    SinglyLinkedList sll1;
   /* sll1.AddToHead(1);
    sll1.AddToHead(2);
    sll1.AddToHead(3);
    sll1.AddToHead(4);
    sll1.AddToHead(5);
    sll1.AddToHead(6);*/

    // демонстрация сравнения
    sll1.AddToTail(8);
    sll1.AddToTail(2);
    sll1.AddToTail(11);
    sll1.AddToTail(7);
    sll1.AddToTail(4);
    sll1.AddToTail(1);
    sll1.AddToHead(8);
    sll1.AddToHead(2);
    sll1.AddToHead(11);
    sll1.AddToHead(7);
    sll1.AddToHead(4);
    sll1.AddToHead(1);
    cout << boolalpha << sll.Equals(&sll1) << "\n";
    sll.SortAsc();
    sll1.SortAsc();
    cout << boolalpha << sll.Equals(&sll1) << "\n";

    SinglyLinkedList* temp_li = sll.Clone();
    sll.AddToHead(555);
    temp_li->AddToTail(777);
    sll.Print();
    temp_li->Print();
    delete temp_li;

    // проверка наличия значения
    cout << boolalpha << sll.Contains(11) << "\n";
    cout << boolalpha << sll.Contains(15) << "\n";
    sll.Print();

    // установка значения в определенной позиции. Индексация с 0
    sll.SetAt(0, 3);
    sll.Print();
    sll.SetAt(12, 3);
    sll.Print();

    // преобразование в массив
    int* arr = sll.ToArray();
    int arr_count = sll.GetCount();
    cout << "массив из листа\n";
    for (int i = 0; i < arr_count; ++i)
	cout << arr[i] << " ";
    cout << "\n";
    delete arr;

    // слияние листов
    SinglyLinkedList sll2;
    sll2.AddToHead(rand()%20);
    sll2.AddToHead(rand()%20);
    sll2.AddToHead(rand()%20);
    sll2.AddToHead(rand()%20);
    sll2.AddToHead(rand() % 20);
    sll2.AddToHead(rand() % 20);
    sll2.AddToHead(rand() % 20);
    sll2.AddToHead(rand() % 20);
    cout << "список с которым будет слияние:\n";
    sll2.Print();

    sll.MergeWith(sll2);
    cout << "список sll после слияния:\n";
    sll.Print();

    // демонстрация перегруженного оператора []
    for (int i = 0; i < sll2.GetCount(); i++)
    {
	cout << sll2[i] << " ";
    }
    cout << "\n";

    sll2[0] = 30;
    sll2[1] = 30;
    sll2[2] = 30;
    for (int i = 0; i < sll2.GetCount(); i++)
    {
	cout << sll2[i] << " ";
    }
    cout << "\n";

    // операторы сравнения

    cout <<"sll == sll2 " << boolalpha << (sll == sll2) << "\n";
    cout << "sll != sll2 " << boolalpha << (sll != sll2) << "\n";
    cout << "sll  <  sll2 " << boolalpha << (sll < sll2) << "\n";
    cout << "sll <=  sll2 " << boolalpha << (sll <= sll2) << "\n";
    cout << "sll  >  sll2 " << boolalpha << (sll > sll2) << "\n";
    cout << "sll  >= sll2 " << boolalpha << (sll >= sll2) << "\n";
    

    // демонстрация + +=
    SinglyLinkedList sll3;
    sll3.AddToHead(rand() % 20);
    sll3.AddToHead(rand() % 20);
    sll3.AddToHead(rand() % 20);
    sll3.AddToHead(rand() % 20);
    sll3.AddToHead(rand() % 20);
    sll3.AddToHead(rand() % 20);
    sll3.AddToHead(rand() % 20);
    sll3.AddToHead(rand() % 20);
    cout << "первый массив\n";
    sll3.Print();

    SinglyLinkedList sll4;
    sll4.AddToHead(rand() % 20);
    sll4.AddToHead(rand() % 20);
    sll4.AddToHead(rand() % 20);
    sll4.AddToHead(rand() % 20);
    sll4.AddToHead(rand() % 20);
    sll4.AddToHead(rand() % 20);
    sll4.AddToHead(rand() % 20);
    sll4.AddToHead(rand() % 20);
    cout << "второй массив\n";
    sll4.Print();

    SinglyLinkedList* sll5 = sll3 + sll4;
    cout << "cуммарный массив\n";
    sll5->Print();

    // приведение к int*
    int* demo_arr = (int*)sll3;  // static_cast<int*>(sll3);
    for (int i = 0; i < sll3.GetCount(); i++)
    {
	cout << demo_arr[i] << " ";
    }
    cout << "\n";

    return 0;
}


