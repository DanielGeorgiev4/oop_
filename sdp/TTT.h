#pragma once
#include <iostream>

struct Node
{
	char arr[3][3];
	Node** next;
	unsigned branch_number;
	Node(unsigned _branch_number) : branch_number(_branch_number)
	{
		for (unsigned i = 0; i < 9; i++) arr[0][i] = '\0';
		next = new Node*[branch_number];
	}
	Node(char* _arr, unsigned _branch_number) : branch_number(_branch_number)
	{
		for (unsigned i = 0; i < 9; i++) arr[0][i] = _arr[i];
		next = new Node*[branch_number];
	}
	Node(char _arr[3][3], unsigned _branch_number, unsigned index, char sym) : branch_number(_branch_number)
	{
		for (unsigned i = 0; i < 9; i++) arr[0][i] = _arr[0][i];
		arr[0][index] = sym;
		next = new Node*[branch_number];
	}
	bool is_solved()
	{
		return ((arr[0][0] == arr[0][1] && arr[0][0] == arr[0][2] && arr[0][0] != '\0') ||
			(arr[1][0] == arr[1][1] && arr[1][0] == arr[1][2] && arr[1][0] != '\0') ||
			(arr[2][0] == arr[2][1] && arr[2][0] == arr[2][2] && arr[1][0] != '\0') ||
			(arr[0][0] == arr[1][0] && arr[0][0] == arr[2][0] && arr[0][0] != '\0') ||
			(arr[0][1] == arr[1][1] && arr[0][1] == arr[2][1] && arr[0][1] != '\0') ||
			(arr[0][2] == arr[1][2] && arr[0][2] == arr[2][2] && arr[0][2] != '\0') ||
			(arr[0][0] == arr[1][1] && arr[0][0] == arr[2][2] && arr[0][0] != '\0') ||
			(arr[0][2] == arr[1][1] && arr[0][2] == arr[2][0] && arr[0][2] != '\0'));
	}
	bool is_full()
	{
		for (unsigned i = 0; i < 9; i++)
		{
			if (arr[0][i] == '\0') return false;
		}
		return true;
	}
	void print()
	{
		for (unsigned r = 0; r < 3; r++)
		{
			std::cout << '|';
			for (unsigned c = 0; c < 3; c++)
			{
				if (arr[r][c] == '\0') std::cout << ' ' << '|';
				else std::cout << arr[r][c] << '|';
			}
			std::cout << std::endl;
		}
	}
};
class TTT
{
	Node* root;
	void solve(Node*);
	void print(Node*);
public:
	TTT();
	void solve();
	void print();
};
TTT::TTT()
{
	root = new Node(9);
}
void TTT::solve()
{
	solve(root);
}
void TTT::solve(Node* curr)
{
	if (curr == nullptr) return;
	if (curr->is_solved() || curr->is_full())
	{
		curr->next = nullptr;
		return;
	}
	unsigned possition = 0;
	for (unsigned i = 0; i < curr->branch_number; i++)
	{
		if (curr->arr[0][possition] != '\0')
		{
			if(curr->branch_number%2==1) curr->next[i] = new Node(curr->arr, curr->branch_number - 1, possition, 'X');
			else curr->next[i] = new Node(curr->arr, curr->branch_number - 1, possition, 'O');
			solve(curr->next[i]);
		}
		else
		{
			possition++;
			i--;
		}
	}
}
void TTT::print()
{
	print(root);
}
void TTT::print(Node* curr)
{
	if (curr != root) return;
	if (curr == nullptr) return;
	for (unsigned i = 0; i < curr->branch_number; i++)
	{
		curr->print();
		print(curr->next[i]);
	}
	
}