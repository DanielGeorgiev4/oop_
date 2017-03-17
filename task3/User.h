#pragma once
#include <iostream>
using namespace std;
class User
{
	char id[32], pass[32];
public:
	User() {}
	User(char* _id, char* _pass)
	{
		strcpy_s(id, 32, _id);
		strcpy_s(pass, 32, _pass);
	}
	char* get_id() { return id; }
	char* get_pass() { return pass; }
	void print() { cout << "id:" << id << "    pass:" << pass << endl; }
};