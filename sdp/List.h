#pragma once
#include <iostream>
template <typename valT>
struct Node
{
	valT value;
	Node* next;
	Node()
	{
		next = nullptr;
	}
	Node(valT _value)
	{
		value = _value;
		next = nullptr;
	}
	Node(valT _value, Node* _next)
	{
		value = _value;
		next = _next;
	}
};
template <typename valT>
class List
{
	Node<valT>* start;
	void del(Node<valT>*&);
	unsigned count(valT,Node<valT>*);
	void map(int(*)(int), Node<valT>*);
	Node<valT>* reverse(Node<valT>*);
	unsigned number_of_elements(Node<valT>*);
	void array(Node<valT>*, unsigned, valT*);
public:
	List();
	List(Node<valT>*&);
	~List();
	void push(valT);
	void print();
	bool is_empty();
	void pop(unsigned);
	unsigned count(valT);
	void removeAll(valT);
	void map(int(*)(int));
	Node<valT>* get_last();
	void reverse();
	unsigned number_of_elements();
	valT* array();
	bool has_duplicates();
	void init_from_array(valT*, unsigned);
	void remove_duplicates();
	bool is_sorted();
	bool polindrom();
};
template <typename valT>
valT* List<valT>::array()
{
	valT* arr = new valT[number_of_elements()];
	array(start,0,arr);
	return arr;
	
}
template <typename valT>
void List<valT>::array(Node<valT>* top, unsigned index, valT* arr)
{
	if (top == nullptr) return;
	arr[index] = top->value;
	array(top->next,++index,arr);
}
template <typename valT>
unsigned List<valT>::number_of_elements()
{
	return number_of_elements(start);
}
template <typename valT>
unsigned List<valT>::number_of_elements(Node<valT>* top)
{
	if (top == nullptr) return 0;
	return 1 + number_of_elements(top->next);
}
template <typename valT>
Node<valT>* List<valT>::get_last()
{
	Node<valT>* curr = start;
	if (curr == nullptr) return curr;
	while (curr->next != nullptr)
	{
		curr = curr->next;
	}
	return curr;
}
template <typename valT>
List<valT>::List()
{
	start = nullptr;
}
template <typename valT>
List<valT>::List(Node<valT>*& top)
{
	start = top;
}
template <typename valT>
List<valT>::~List()
{
	del(start);
}
template <typename valT>
void List<valT>::del(Node<valT>*& top)
{
	if (top == nullptr) return;
	del(top->next);
	delete top;
}
template <typename valT>
void List<valT>::push(valT _value)
{
	Node<valT>* curr = start;
	if (start == nullptr)
	{
		start = new Node<valT>(_value);
	}
	else
	{
		while (curr->next != nullptr)
		{
			curr = curr->next;
		}
		curr->next = new Node<valT>(_value);
	}
}
template <typename valT>
void List<valT>::print()
{
	Node<valT>* curr = start;
	if (start == nullptr)
	{
		std::cout << "empty list\n";
	}
	else
	{
		while (curr != nullptr)
		{
			std::cout << curr->value << std::endl;
			curr = curr->next;
		}
	}
}
template <typename valT>
bool List<valT>::is_empty()
{
	if (start == nullptr) return true;
	return false;
}
template <typename valT>
void List<valT>::pop(unsigned index)
{
	if (start == nullptr) return;
	if (start->next == nullptr)
	{
		delete start;
		start = nullptr;
		return;
	}
	if (index == 1)
	{
		Node<valT>* helper = start->next;
		delete start;
		start = helper;
		return;
	}
	Node<valT>* curr = start;
	while (index != 2 && curr->next->next!=nullptr)
	{
		curr = curr->next;
		index--;
	}
	Node<valT>* helper = curr->next->next;
	delete curr->next;
	curr->next = helper;

}
template <typename valT>
unsigned List<valT>::count(valT x)
{
	return count(x,start);
}
template <typename valT>
unsigned List<valT>::count(valT x, Node<valT>* top)
{
	if (top == nullptr) return 0;
	return (top->value == x ? 1 + count(x, top->next) : count(x, top->next));
}
template <typename valT>
void List<valT>::removeAll(valT x)
{
	Node<valT>* curr = start;
	unsigned index = 1;
	while (curr != nullptr)
	{
		if (curr->value == x)
		{
			curr = curr->next;
			pop(index);
		}
		else
		{
			index++;
			curr = curr->next;
		}
	}
}
template <typename valT>
void List<valT>::map(int (*func)(int))
{
	map(func, start);
}
template <typename valT>
void List<valT>::map(int(*func)(int), Node<valT>* top)
{
	if (top == nullptr) return;
	top->value = func(top->value);
	map(func, top->next);
}
template <typename valT>
void List<valT>::reverse()
{
	if (start != nullptr) reverse(start);
}
template <typename valT>
Node<valT>* List<valT>::reverse(Node<valT>* top)
{
	if (top->next == nullptr)
	{
		start = new Node<valT>(top->value);
		return start;
	}
	Node<valT>* helper = reverse(top->next);
	helper->next = new Node<valT>(top->value);
	return helper->next;
}
template <typename valT>
bool List<valT>::has_duplicates()
{
	valT* arr = array();
	unsigned size = number_of_elements();
	for (int i = 0; i < size - 1; i++)
		for (int k = i + 1; k < size; k++)
		{
			if (arr[i] == arr[k]) return true;
		}
	return false;
}
template <typename valT>
void List<valT>::init_from_array(valT* arr, unsigned size)
{
	del(start);
	start = nullptr;
	for (unsigned i = 0; i < size; i++) push(arr[i]);
}
template <typename valT>
void List<valT>::remove_duplicates()
{
	if (has_duplicates())
	{
		valT* arr = array();
		unsigned size = number_of_elements(),new_size=0;
		bool* dupl = new bool[size];
		for (int i = 0; i < size; i++) dupl[i] = false;
		for (int i = 0; i < size-1; i++)
		{
			for (int k = i+1; k < size; k++)
			{
				if (arr[i] == arr[k])
				{
					dupl[i] = true;
					dupl[k] = true;
				}
			}
		}
		valT* new_arr = new valT[size];
		for (int i = 0; i < size; i++)
		{
			if (!dupl[i])
			{
				new_arr[new_size] = arr[i];
				new_size++;
			}
		}
		init_from_array(new_arr, new_size);
	}
}
template <typename valT>
bool List<valT>::is_sorted()
{
	valT* arr = array();
	unsigned size = number_of_elements(), up = 0, down = 0;
	for (unsigned i = 0; i < size-1; i++)
	{
		if (arr[i] >= arr[i + 1]) down++;
		if (arr[i] <= arr[i + 1]) up++;
	}
	if (up == size - 1 || down == size - 1) return true;
	return false;
}
template <typename valT>
bool List<valT>::polindrom()
{
	valT* arr = array();
	unsigned size = number_of_elements();
	for (unsigned i = 0; i < size / 2; i++)
	{
		if (arr[i] != arr[size - 1 - i]) return false;
	}
	return true;

}

List<int>* range(int x, int y)
{
	List<int>* llist = new List<int>;
	while (x <= y)
	{
		llist->push(x++);
	}
	return llist;
}
