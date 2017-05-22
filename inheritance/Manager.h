#pragma once
#include <iostream>
#include <string>
#include "Employee.h"
class Manager : public Employee
{
	unsigned number_subs;
public:
	Manager();
	Manager(const Manager&);
	Manager& operator = (const Manager&);
	Manager(string, unsigned, unsigned);
	void print() { std::cout << name << ' ' << experiance << ' ' << number_subs << std::endl; }

};

Manager::Manager(): number_subs(0) {}
Manager::Manager(const Manager& other) : Employee(other.name, other.experiance)
{
	number_subs = other.number_subs;
}
Manager::Manager(string _name, unsigned _experiance, unsigned _subs) : Employee(_name,_experiance)
{
	number_subs = _subs;
}
Manager& Manager::operator=(const Manager& other)
{
	Employee(other.name, other.experiance);
	number_subs = other.number_subs;
	return *this;
}
