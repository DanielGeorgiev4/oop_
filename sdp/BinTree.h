#pragma once
#include<iostream>
#include<stack>
#include<vector>
using std::cout;
using std::stack;
using std::vector;

struct Node 
{
	int data;
	Node* left;
	Node* right;
	Node(int _data) : data(_data), left(nullptr), right(nullptr) {}
};

class BinTree 
{
	Node* root;
	void add(int, Node*&, char*);
	void print(Node*) const;
	void del(Node*&);
	unsigned count(Node*) const;
	unsigned count_even(Node*) const;
	unsigned searchCount(Node*, bool(*)(const int&)) const;
	unsigned heigth(Node*) const;
	unsigned count_leaves(Node*) const;
	int max_leaf(Node*) const;
public:
	BinTree();
	~BinTree();
	void add(int, char*);
	void print();
	unsigned count() const;
	unsigned count_even() const;
	unsigned searchCount(bool (*)(const int&)) const;
	unsigned heigth() const;
	unsigned count_leaves() const;
	int max_leaf() const;
};
BinTree::BinTree() : root(nullptr) {}
BinTree::~BinTree()
{
	del(root);
}
void BinTree::add(int x, char* path)
{
	add(x, root, path);
}
void BinTree::add(int x, Node*& sub_root, char* path)
{
	if (sub_root == nullptr) {
		sub_root = new Node(x);
		return;
	}
	if (path[0] == 'L') {
		add(x, sub_root->left, path + 1);
		return;
	}
	add(x, sub_root->right, path + 1);
	return;
}
void BinTree::print(Node* sub_root) const 
{
	if (sub_root == nullptr)
	{
		return;
	}
	cout << sub_root->data << " ";
	print(sub_root->left);
	print(sub_root->right);
}
void BinTree::print()
{
	print(root);
}
void BinTree::del(Node*& subroot)
{
	if (subroot == nullptr) return;
	del(subroot->left);
	del(subroot->right);
	delete subroot;
}
unsigned BinTree::count(Node* curr) const
{
	if (curr == nullptr) return 0;
	return 1 + count(curr->left) + count(curr->right);
}
unsigned BinTree::count() const
{
	return count(root);
}
unsigned BinTree::count_even(Node* curr) const
{
	if (curr == nullptr) return 0;
	return count_even(curr->left) + count_even(curr->right) + (curr->data % 2 ? 0 : 1);
}
unsigned BinTree::count_even() const
{
	return count_even(root);
}
unsigned BinTree::searchCount(Node* curr, bool(*f)(const int&)) const
{
	if (curr == nullptr) return 0;
	return searchCount(curr->left, f) + searchCount(curr->right, f) + (f(curr->data) ? 1 : 0);
}
unsigned BinTree::searchCount(bool(*f)(const int&)) const
{
	return searchCount(root,f);
}
unsigned BinTree::heigth(Node* curr) const
{
	if (curr == nullptr) return 0;
	unsigned left = 0, right = 0;
	left = heigth(curr->left);
	right = heigth(curr->right);
	return 1 + (left > right ? left : right);
}
unsigned BinTree::heigth() const
{
	return heigth(root);
}
unsigned BinTree::count_leaves(Node* curr) const
{
	if (curr == nullptr) return 0;
	if (curr->left == nullptr && curr->right == nullptr) return 1;
	return count_leaves(curr->left) + count_leaves(curr->right);
}
unsigned BinTree::count_leaves() const
{
	return count_leaves(root);
}
int BinTree::max_leaf(Node* curr) const
{
	if (curr == nullptr) return 0;
	if (curr->left == nullptr && curr->right == nullptr) return curr->data;
	int left, right;
	left = max_leaf(curr->left);
	right = max_leaf(curr->right);
	return (left > right ? left : right);
}
int BinTree::max_leaf() const
{
	return max_leaf(root);
}