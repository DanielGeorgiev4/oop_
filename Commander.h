#pragma once
#include "Knight.h"
class Commander : public Knight
{
	Knight* subs;
	unsigned capacity = 12, size = 0;
public:
	Commander(unsigned);
	Commander(const Knight&);
	Commander(const Commander&);
	void operator = (const Commander&);
	~Commander();
	void get_subs()
	{
		for (int i = 0;i < size;i++) subs[i].print_stats();
	}
};
Commander::Commander(unsigned number_of_knights)
{
	subs = new Knight[number_of_knights];
	for (int i = 0;i < number_of_knights;i++)
	{
		subs[i] = Knight();
	}
	size = number_of_knights;
}
Commander::Commander(const Commander& other)
{
	subs = new Knight[other.size];
	for (int i = 0;i < other.size; i++) subs[i] = other.subs[i];
	size = other.size;
}
Commander::~Commander()
{
	delete[]subs;
}
Commander::Commander(const Knight& new_knight)
{
	subs = new Knight[1];
	subs[0] = new_knight;
	size++;
}
void Commander::operator=(const Commander& other)
{
	if (this != &other)
	{
		subs = new Knight[other.size];
		for (int i = 0;i < other.size; i++) subs[i] = other.subs[i];
		size = other.size;
	}
}