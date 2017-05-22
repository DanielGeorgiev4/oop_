#pragma once
#include <iostream>
using namespace std;
class Employee
{
protected:
	string name;
	unsigned experiance;
public:
	Employee();
	Employee(const Employee&);
	Employee(string, unsigned);
	Employee& operator = (const Employee&);
	virtual void print() { return; }
};

Employee::Employee()
{
 	name = '\0';
	experiance = 0;
}
Employee::Employee(const Employee& other)
{
	experiance = other.experiance;
	name = other.name;
}
Employee::Employee(string _name, unsigned _experiance)
{
	name = _name;
	experiance = _experiance;
}
Employee& Employee::operator=(const Employee& other)
{
	experiance = other.experiance;
	name = other.name;
	return *this;
}