#pragma once
#include "stack.h"



// {9())}
//[(})]
void PrintErrorMessage(string str, int& ind)
{
    cout << str << "\n";
    for (int j = 0; j < ind; j++)
    {
	cout << " ";
    }
    cout << "^\nНеверная скобка";
}

void ParseString(const string& str)
{
    /*
    91	[
    123 {
    40	(
    41	)
    125	}
    93	]
    */

    Stack str_st;
    int length = str.length();
    for (int i = 0; i < length; i++)
    {
	if ((int)str[i] == 91 || (int)str[i] == 123 || (int)str[i] == 40)
	    str_st.Push(str[i]);
	else if ((int)str[i] == 41)
	{
	    if (str_st.Pop(str[i]) != 40)
	    {
		//PrintErrorMessage(str, i);
		cout << str << "\n";
		for (int j = 0; j < i; j++)
		{
		    cout << " ";
		}
		cout << "^\nНеверная скобка";
		return;
	    }
	}
	else if ((int)str[i] == 125)
	{
	    if (str_st.Pop(str[i]) != 123)
	    {
		/*PrintErrorMessage(str, i);*/
		cout << str << "\n";
		for (int j = 0; j < i; j++)
		{
		    cout << " ";
		}
		cout << "^\nНеверная скобка";
		return;
	    }
	}
	else if ((int)str[i] == 93)
	{
	    if (str_st.Pop(str[i]) != 98)
	    {
		/*PrintErrorMessage(str, i);*/
		cout << str << "\n";
		for (int j = 0; j < i; j++)
		{
		    cout << " ";
		}
		cout << "^\nНеверная скобка";
		return;
	    }
	}

    }
    if (str_st.IsEmpty())
	cout << "Строка прошла валидацию.\n";
    else
	cout << "нет закрывающей скобки\n";

}


int main() {
    setlocale(0, "");
    srand(time(0));
    Stack st; // создаём "пустой" стек

    // до тех пор, пока стек не заполнился
    for (int i = 0; i < 10; i++)
	st.Push(rand() % 90 + 10); // добавляем элемент на вершину стека

    cout << "Метод Print: \n";
    st.Print();
    cout << "\nМетод Contains проверяет наличие 74 в стеке: " << boolalpha << st.Contains(74) << endl;
    cout << st;
    cout << "\nДобавление элемента 80 методом PushLessValue возвращает: " << boolalpha << st.PushLessValue(80);
    cout << "\n";
    cout << st;
    cout << "Метод PushUnique добавляет 31: " << boolalpha << st.PushUnique(31) << endl;
    cout << st;


    // до тех пор, пока в стеке есть какие-либо значения
    while (!st.IsEmpty()) {
	cout << st.Top() << "  ";
	st.Pop(); // извлечь значение и показать на экране
    }


    /*
     Пусть имеется выражение, поддерживающее 4 вида скобок: (), [], {}, <>. Задача - проверить правильность расположения скобок в выражении. Применить при этом вашу кастомизированную версию стека. Примеры:

{(5-[3+<9>])-4} - правильное выражение
{(>5-<[3+)9]-4} - неправильное выражение

Задачу легко решить с помощью стека. Алгоритм следующий: необходимо выполнить проход по выражению слева направо. Если встречается открывающая скобка, то её нужно поместить в стек. Если встречается закрывающая скобка, то достаём элемент из стека, и поверяем форму скобки. Если формы разные или стек пуст, то это значит,  что выражение неверное. Если к концу работы программы стек оказался не пуст, то это также означает, что выражение составлено неверно.

    */

    string str;
    cout << "\nВведите строку: \n";
    cin >> str;
    ParseString(str);
}
