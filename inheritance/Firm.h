#pragma once
#include <iostream>
#include "Manager.h"
#include "Programmer.h"
#include "Employee.h"
#define MIN_CAPACITY 16
class Firm 
{
	Employee** arr;
	unsigned size, capacity;
public:
	Firm();
	~Firm();
	void add(Employee&);
	void fire(Employee&);
	void print();
};

Firm::Firm() : size(0), capacity(MIN_CAPACITY)
{
	arr = new Employee*[capacity];
}
Firm::~Firm()
{
	delete[] arr;
}
void Firm::add(Employee& new_employee)
{
	if (size == capacity)
	{
		capacity *= 2;
		Employee** new_arr = new Employee*[capacity];
		for (unsigned i = 0; i < size; i++) new_arr[i] = arr[i];
		delete[] arr;
		arr = new_arr;
	}
	arr[size] = &new_employee;
	size++;
}
void Firm::fire(Employee& fire_employee)
{
	
}
void Firm::print()
{
	for (unsigned i = 0; i < size; i++) arr[i]->print();
}