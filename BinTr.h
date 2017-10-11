#pragma once
#include <iostream>
#include <string>
using namespace std;
struct Node
{
	int value;
	Node *left, *right;
	Node() :left(nullptr), right(nullptr) {}
	Node(int _value): value(_value), left(nullptr), right(nullptr) {}
};
class BinTree
{
	Node* start;
	void add(int,Node*& ,char* );
	unsigned count_nodes(Node*);
	void del(Node*);
	void print(Node* subtree);
	unsigned height(Node*);
public:
	BinTree();
	~BinTree();
	void add(int, char*);
	void print();
	unsigned count_nodes();
	unsigned height();
};

BinTree::BinTree()
{
	start = nullptr;
}
BinTree::~BinTree()
{
	del(start);
}
void BinTree::del(Node* subtree)
{
	if (subtree == nullptr) return;
	del(subtree->left);
	del(subtree->right);
	delete subtree;

}
void BinTree::add(int value, Node*& subtree, char* path)
{
	if (subtree == nullptr)
	{
		subtree = new Node(value);
		return;
	}
	if (path[0] == 'L')
	{
		add(value, subtree->left, path+1);
		return;
	}
	if (path[0] == 'R')
	{
		add(value, subtree->right, path + 1);
		return;
	}
}
void BinTree::add(int value, char* path)
{
	add(value, start, path);
}
void BinTree::print()
{
	print(start);
}
void BinTree::print(Node* subtree)
{
	if (subtree == nullptr) return;
	cout << subtree->value << endl;
	print(subtree->left);
	print(subtree->right);
}
unsigned BinTree::count_nodes(Node* top)
{
	if (top == nullptr) return 0;
	return 1 + count_nodes(top->left) + count_nodes(top->right);
}
unsigned BinTree::count_nodes()
{
	return count_nodes(start);
}
unsigned BinTree::height()
{
	return height(start);
}
unsigned BinTree::height(Node* subtree)
{
	if (subtree == nullptr) return 0;
	unsigned left, right;
	left = height(subtree->left);
	right = height(subtree->right);
	return 1 + (left > right ? left : right);
	/*if (left > right) return left + 1;
	return right + 1;*/
}
