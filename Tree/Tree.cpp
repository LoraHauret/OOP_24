#pragma once;
#include "Tree.h"

#pragma once;
#include "Tree.h"

bool AVLTree::IsEmpty() const
{
    return root == nullptr;
}

AVLTree::Node* AVLTree::RightRotate(Node* node) {
    Node* n_left = node->left;
    Node* temp = n_left->right;

    n_left->right = node;
    node->left = temp;

    node->height = max(GetHeight(node->left), GetHeight(node->right)) + 1;
    n_left->height = max(GetHeight(n_left->left), GetHeight(n_left->right)) + 1;

    return n_left;
}

AVLTree::Node* AVLTree::LeftRotate(Node* node) {
    Node* n_right = node->right;
    Node* temp = n_right->left;

    n_right->left = node;
    node->right = temp;

    node->height = max(GetHeight(node->left), GetHeight(node->right)) + 1;
    n_right->height = max(GetHeight(n_right->left), GetHeight(n_right->right)) + 1;

    return n_right;  // возвращаю, как уже новый корневой элемент
}

int AVLTree::GetHeight(AVLTree::Node* node)
{
    if (!node)
	return 0;
    return node->height;
}

int AVLTree::GetBalance(AVLTree::Node* node)
{
    if (!node)
	return 0;
    return GetHeight(node->left) - GetHeight(node->right);
}

AVLTree::Node* AVLTree::AddNode(AVLTree::Node* node, int value)
{
    if (!node)
    {
	node = new Node(value);
	return node;
    }

    if (value < node->value)
	node->left = AddNode(node->left, value);
    else if (value > node->value)
	node->right = AddNode(node->right, value);
    else
	return node;

    node->height = 1 + max(GetHeight(node->left), GetHeight(node->right));

    int balance = GetBalance(node);

    
    if (balance > 1 && value < node->left->value) // леволевый поворот
	return RightRotate(node);

    
    if (balance < -1 && value > node->right->value) // правоправый поворот
	return LeftRotate(node);

    
    if (balance > 1 && value > node->left->value) // левоправый поворот
    {
	node->left = LeftRotate(node->left);
	return RightRotate(node);
    }

    
    if (balance < -1 && value < node->right->value) // праволевый поворот
    {
	node->right = RightRotate(node->right);
	return LeftRotate(node);
    }

    return node;
}

AVLTree::Node* AVLTree::GetMinNode(Node* node) {
    Node* minNode = node;
    while (minNode->left)
	minNode = minNode->left;
    return minNode;
}

AVLTree::Node* AVLTree::DeleteNode(Node* node, int value, bool& isDeleted)
{
    if (!node)  // если нулевой узел
	return node;

    // найти элемент для удаления
    if (value < node->value)
	node->left = DeleteNode(node->left, value, isDeleted);
    else if (value > node->value)
	node->right = DeleteNode(node->right, value, isDeleted);
    else
    {
	if (!node->left || !node->right) // если это сам концевой лист/ элемент или элемент с 1 потомком
	{
	    Node* temp = node->left ? node->left : node->right; // есть ли левый потомок? если есть, то запоминаю его. Иначе - запоминаю правого
	    if (!temp) // а был ли потомок? 
	    {
		temp = node; // запоминаю родителя / возвращаюсь на шаг назад
		node = nullptr;
	    }
	    else
	    {
		*node = *temp; // потомок был и его нужно переставить на место родителя
	    }
	    delete temp;
	}
	else // 2 потомка
	{
	    Node* temp = GetMinNode(node->right); // минимальный элемент справа (можно также сделать максимальный элемент слева) 
	    node->value = temp->value; // Этот элемент перемещается на место текущего элемента

	    node->right = DeleteNode(node->right, temp->value, isDeleted);
	    isDeleted = true;
	}
    }

    if (!node) // если потомок (текущий элемент) нулевой, то ничего не удалялось. т.е. ненужно делать балансировку на каждом витке рекурсии
    {
	isDeleted = false;
	return node;
    }
    if (!isDeleted) {
	return node;
    }

    // пересчет высоты
    node->height = 1 + max(GetHeight(node->left), GetHeight(node->right));

    int balance = GetBalance(node);

    if (balance > 1 && GetBalance(node->left) >= 0)
	return RightRotate(node);
    if (balance > 1 && GetBalance(node->left) < 0)
    {
	root->left = LeftRotate(node->left);
	return RightRotate(node);
    }

    if (balance < -1 && GetBalance(node->right) <= 0)
	return LeftRotate(node);
    if (balance < -1 && GetBalance(node->right) > 0)
    {
	root->right = RightRotate(node->right);
	return LeftRotate(node);
    }
    return node;
}