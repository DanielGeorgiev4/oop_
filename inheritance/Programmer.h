#pragma once
#include <iostream>
#include <string>
#include "Employee.h"
class Programmer : public Employee
{
	bool knows_cplus, knows_csharp;
public:
	Programmer();
	Programmer(const Programmer&);
	Programmer(string, unsigned, bool, bool);
	Programmer& operator = (const Programmer&);
	void print() { std::cout << name << ' ' << experiance << ' ' << knows_cplus << ' ' << knows_csharp << std::endl; }
};

Programmer::Programmer() : knows_cplus(false),knows_csharp(false) {}
Programmer::Programmer(const Programmer& other) : Employee(other.name,other.experiance)
{
	knows_cplus = other.knows_cplus;
	knows_csharp = other.knows_csharp;
}
Programmer::Programmer(string _name, unsigned _experiance, bool cplus, bool csharp) : Employee(_name, _experiance)
{
	knows_cplus = cplus;
	knows_csharp = csharp;
}
Programmer& Programmer::operator=(const Programmer& other)
{
	Employee(other.name, other.experiance);
	knows_cplus = other.knows_cplus;
	knows_csharp = other.knows_csharp;
	return *this;
}