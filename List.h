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
public:
	List();
	List(Node<valT>*&);
	//~List();
	void push(valT);
	void print();
	bool is_empty();
	//Node*& get_start();
	void pop(unsigned);
};
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
	if (index != 1)
	{
		delete curr->next;
		curr->next = nullptr;
		return;
	}
	Node<valT>* helper = curr->next->next;
	delete curr->next;
	curr->next = helper;

}
//Node*& last(Node*& top)
//{
//	if (top->next == nullptr) return top;
//	last(top->next);
//}
//void append_help(Node*& end, Node* l2)
//{
//	if (l2 == nullptr) return;
//	end->next = new Node(l2->value);
//	append_help(end->next, l2->next);
//}
//int count(Node* l, int x)
//{
//	int count = 0;
//	while (l != nullptr)
//	{
//		if (l->value == x) count++;
//		l = l->next;
//	}
//	return count;
//}
//Node* range(int x, int y)
//{
//	List* list = new List;
//	for (int i = x; i <= y; i++)
//	{
//		list->add(i);
//	}
//	return list->get_start();
//}
//void removeAll(Node*& l, int x)
//{
//	if (l == nullptr) return;
//	while (l->value == x)
//	{
//		Node* helper = l;
//		l = l->next;
//		delete helper;
//		if (l == nullptr) return;
//	}
//	removeAll(l->next, x);
//}
//void append(Node*& l1, Node* l2)
//{
//	Node*& end = last(l1);
//	append_help(end, l2);
//}
//Node* concat(Node* l1, Node* l2)
//{
//	Node* start;
//	if (l1 == nullptr && l2 == nullptr) return nullptr;
//	start = new Node(l1->value);
//	append_help(start, l1->next);
//	append_help(last(start), l2);
//	return start;
//}
//void reverse_help(Node*& top, int* arr, int index)
//{
//	if (top == nullptr) return;
//	top->value = arr[index-1];
//	reverse_help(top->next, arr, --index);
//}
//void reverse(Node* top)
//{
//	int size = 0, capacity = 16;
//	int *arr = new int[capacity];
//	Node* curr = top;
//	while (curr != nullptr)
//	{
//		if (size == capacity)
//		{
//			capacity *= 2;
//			int *new_arr = new int[capacity];
//			for (int i = 0; i < size; i++) new_arr[i] = arr[i];
//			delete arr;
//			arr = new_arr;
//		}
//		arr[size] = curr->value;
//		size++;
//		curr = curr->next;
//	}
//	reverse_help(top, arr, size);
//}
