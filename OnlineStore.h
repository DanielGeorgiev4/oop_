#pragma once
#include <iostream>
#include <fstream>
#include "Items.h"
#include "User.h"
using namespace std;

class OnlineStore
{
	Items items[128];
	User users[16];
	int number_of_elements, number_of_users, logged_now=-1;
public:
	OnlineStore (char* items_name, char* users_name)
	{
		ifstream file(items_name);
		file >> number_of_elements;
		file.get();
		for (int i = 0; i < number_of_elements; i++)
		{
			char name[32];
			int quantity, leva, stotinki, sale;
			file.getline(name, 32, '|');
			file >> quantity >> leva >> stotinki >> sale;
			file.get();
			Items helper(name, quantity, leva, stotinki, sale);
			items[i] = helper;
		}
		file.close();
		ifstream file2(users_name);
		file2 >> number_of_users;
		file2.get();
		for (int i = 0; i < number_of_users; i++)
		{
			char id[32],pass[32];
			file2.getline(id, 32, '|');
			file2.getline(pass, 32);
			User helper(id, pass);
			users[i] = helper;
		}
		file2.close();
	}
	void login()
	{
		char id[32], pass[32], action[16], user_order[32];
		int user_quantity;
		while (true)
		{
			while (logged_now == -1)
			{
				cout << "Enter username: ";
				cin.getline(id,32);
				cout << "Enter password: ";
				cin.getline(pass,32);
				for (int i = 0; i < number_of_users; i++)
				{
					if (!strcmp(id, users[i].get_id()) && !strcmp(pass, users[i].get_pass()))
					{
						logged_now = i;
						break;
					}
				}
				if (logged_now == -1) cout << "Wrong username/password!!!\n";
			}
			strcpy_s(action, 16, "buy");
			while (!strcmp(action, "buy"))
			{
				cout << "Enter item's name: ";
				cin.getline(user_order,32);
				cout << "Enter quantity: ";
				cin >> user_quantity;
				cin.ignore(1, '\n');
				bool flag = 0;
				for (int k = 0; k < number_of_elements; k++)
				{
					flag = 0;
					int x = items[k].get_quantity();
					if (!strcmp(user_order, items[k].get_name()) && user_quantity<=x )
					{
						cout << "Total amout: " << user_quantity*items[k].amount_sale() << endl;
						items[k].set_quantity(items[k].get_quantity()-user_quantity);
						cout << "Enter action(quit\\logout\\buy): ";
						cin.getline(action,32);
						flag = 1;
						break;
					}
				}
				if ( !strcmp(action, "quit") ) exit(0);
				if ( !strcmp(action, "logout") ) logged_now = -1;
				if(!flag) cout << "Wrong item's name or quantity!!!\n";
			}
		}
	}
	double order(char* filename)
	{
		int number_of_orders, order_quantity;
		double money=0;
		char order_name[32];
		ifstream file(filename);
		file >> number_of_orders;
		file.get();
		for (int i = 0; i < number_of_orders; i++)
		{
			file.getline(order_name, 32, '|');
			file >> order_quantity;
			for (int k = 0; k < number_of_elements; k++)
			{
				if (!strcmp(order_name, items[k].get_name()))
				{
					if (order_quantity > items[k].get_quantity()) order_quantity = items[k].get_quantity();
					//money += order_quantity*items[k].amount();
					money += order_quantity*items[k].amount_sale();
					break;
				}
			}
			file.get();
		}
		file.close();
		return money;
	}
	void print_items()
	{
		for (int i = 0; i < number_of_elements; i++) items[i].print();
	}
	void print_user()
	{
		for (int i = 0; i < number_of_users; i++) users[i].print();
	}
};