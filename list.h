#pragma once
#include <iostream>
using namespace std;
class Person
{
public:
	virtual void get_days() = 0;
};
class Kid : public Person
{
	unsigned years;
public:
	Kid() : years(10){}
	void get_days()
	{
		cout << years << endl;
	}
};
class Adult : public Person
{
	unsigned years;
public:
	Adult() : years(20) {}
	void get_days()
	{
		cout << years << endl;
	}
	void debuff() { years /= 2; }
};
class Data
{
	Person** arr;
	unsigned size, capacity;
public:
	Data();
	~Data();
	void add(Person&);
	void print();
};
Data::~Data()
{
	delete[] arr;
}
Data::Data()
{
	size = 0;
	capacity = 16;
	arr = new Person*[capacity];
}
void Data::add(Person& element)
{
	if (size == capacity)
	{
		capacity *= 2;
		Person **new_arr = new Person*[capacity];
		for (unsigned i = 0; i < size; i++) new_arr[i] = arr[i];
		delete[] arr;
		arr = new_arr;
	}
	arr[size] = &element;
	size++;
}
void Data::print()
{
	for (unsigned i = 0; i < size; i++) arr[i]->get_days();
}