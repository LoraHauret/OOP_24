#pragma once
#include <iostream>
using namespace std;

class AVLTree
{
public:
    struct Node // one element of the tree
    {
	int value; // useful data
	int height = 1;
	//Node* parent = nullptr;
	Node* right = nullptr;
	Node* left = nullptr;

	Node(int value)
	{
	    this->value = value;
	}
	void ShowNode() const
	{
	    cout << value << ", ";
	}
    };

private:
    Node* root = nullptr;
    // int count;

public:
    bool IsEmpty() const;

    AVLTree() {} // так как в классе есть явно объявленный конструктор копирования, приходится и конструктор без параметров явно делать :)

    ~AVLTree()
    {
	Clear();
    }

private:
    void ShowTree(Node* element) const
    {
	if (element != 0)
	{
	    ShowTree(element->left);
	    element->ShowNode();
	    ShowTree(element->right);
	}
    }

public:
    void ShowTree() const
    {
	cout << "\n";
	ShowTree(root);
	cout << "\n";
    }

private:
    Node* RightRotate(Node* node);

    Node* LeftRotate(Node* node);

    Node* GetRoot() const
    {
	return root;
    }

    int GetCount(Node* element, int count) const
    {
	if (element != 0)
	{
	    count = GetCount(element->left, count);
	    count++;
	    count = GetCount(element->right, count);
	}
	return count;
    }

public:
    int GetCount() const
    {
	int count = 0;
	count = GetCount(root, count);
	return count;
    }

private:
    void Clear(Node* element)
    {
	if (element != nullptr)
	{
	    Clear(element->left);
	    Clear(element->right);
	    delete element;
	    element = nullptr;
	}
    }
    
    int GetHeight(Node* node);

    int GetBalance(Node* node);
        
    Node* AddNode(Node* node, int value);

    Node* GetMinNode(Node* node); 

    Node* DeleteNode(Node* node, int value, bool& isDeleted);
public:
    void Clear()
    {
	if (!IsEmpty())
	{
	    Clear(root);
	    root = nullptr;
	}
    }

    Node* FindNode(int value) const
    {
	if (IsEmpty()) 
	    return nullptr;

	Node* f = root;
	while (true)
	{
	    if (value < f->value)
	    {
		if (f->left != nullptr)
		    f = f->left;
		else
		    break;
	    }
	    else if (value > f->value)
	    {
		if (f->right != nullptr)
		    f = f->right;
		else
		    break;
	    }
	    else
		return f;
	}
	return nullptr;
    }
   

   void AddNode(int value)
    {
	//if (FindNode(value)) // зачем 2 раза бежать по дереву? Наличие элемента выяснится при попытке вставки.
	//    return;       
	
	root = AddNode(root, value); // вставка нового значения

	/*n->value = value;
	Node* parent = nullptr;
	if (IsEmpty())
	{
	    root = n;
	    root->parent = parent;
	}
	else
	{
	    Node* p = root;
	    while (p != nullptr)
	    {
		parent = p;
		if (n->value > p->value)
		    p = p->right;
		else
		    p = p->left;
	    }
	    if (n->value < parent->value)
		parent->left = n;
	    else
		parent->right = n;
	    n->parent = parent;
	}*/
    }

    AVLTree& operator = (const AVLTree& original)
    {
	if (!IsEmpty())
	    Clear();

	AddNode(original.root->value);
	Copy(original.root);
	return *this;
    }

    AVLTree(const AVLTree& original)
    {
	AddNode(original.root->value);
	Copy(original.root);
    }

    void Copy(Node* element)
    {
	if (element->left != nullptr)
	    AddNode(element->left->value);

	if (element->right != nullptr)
	    AddNode(element->right->value);

	if (element->left != nullptr)
	    Copy(element->left);

	if (element->right != nullptr)
	    Copy(element->right);
    }

    void DeleteNode(int value)
    {
	bool isDeleted = false;
	root = DeleteNode(root, value, isDeleted);

	/*Node* d = FindNode(value);
	if (d == nullptr)
	    return;

	Node* parent = d->parent;
	if (d == root && GetCount() == 1)
	{
	    Clear();
	    return;
	}
	if (d->left == nullptr && d->right == nullptr)
	{
	    if (parent->left == d)
		parent->left = nullptr;
	    else
		parent->right = nullptr;
	    delete d;
	    return;
	}
	if (d->left == nullptr && d->right != nullptr)
	{
	    if (parent->left == d)
	    {
		parent->left = d->right;
	    }
	    else
	    {
		parent->right = d->right;
	    }
	    d->right->parent = parent;
	    delete d;
	    return;
	}

	if (d->left != nullptr && d->right == nullptr)
	{
	    if (parent->left == d)
	    {
		parent->left = d->left;
	    }
	    else
	    {
		parent->right = d->left;
	    }
	    d->left->parent = parent;
	    delete d;
	    return;
	}
	if (d->left != nullptr && d->right != nullptr)
	{
	    Node* r = d->right;
	    if (r->right == nullptr && r->left == nullptr)
	    {
		d->value = r->value;
		d->right = nullptr;
		delete r;
	    }
	    else if (r->left != nullptr)
	    {
		Node* p = r->left;
		while (p->left != nullptr)
		    p = p->left;
		d->value = p->value;
		if (p->right == nullptr)
		    p->parent->left = nullptr;
		else
		    p->parent->left = p->right;
		delete p;
	    }
	    else
	    {
		d->value = r->value;
		d->right = r->right;
		delete r;
	    }
	}*/
    }
};
