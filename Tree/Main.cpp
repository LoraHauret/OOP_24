#pragma once;
#include "Tree.h"


int main()
{
    setlocale(0, "UKR");

    const int SIZE = 25;
    int ar[SIZE] = { // в начале и в конце массива - сотки
	    100, 50, 25, 10, 5,
	    15, 35, 27, 40, 75,
	    60, 90, 300, 200, 150,
	    250, 500, 400, 350, 370,
	    700, 800, 750, 900, 100
    };

    AVLTree bt;
    for (int i = 0; i < SIZE; i++)
	bt.AddNode(ar[i]);
    bt.ShowTree();

    cout << "\n" << bt.GetCount() << "\n";
    // 24 элемента, потому что вторая сотка не добавилась

    AVLTree bt2 = bt;

    bt2.ShowTree();

    AVLTree bt3;
    for (int i = 0; i < 10; i++)
	bt3.AddNode(rand() % 100);
    bt3.ShowTree();

    bt3 = bt2;
    cout << "\n" << bt3.GetCount() << "\n";

    AVLTree::Node* f = bt.FindNode(750);
    if (f)
	cout << "\nзначение 750 найдено!\n";

    bt.DeleteNode(750);
    bt.ShowTree();

    bt.DeleteNode(700);
    bt.ShowTree();

    bt.DeleteNode(500);
    bt.ShowTree();

    bt.DeleteNode(25);
    bt.ShowTree();

    return 0;
}