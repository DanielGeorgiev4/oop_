#pragma once
#include <iostream>
using namespace std;

class Price
{
	int leva, stotinki;
public:
	void set_leva(int _leva) { leva = _leva; }
	void set_stotinki(int _stotinki) { stotinki = _stotinki; }
	int get_leva() { return leva; }
	int get_stotinki() { return stotinki; }
	int amount() { return leva * 100 + stotinki; }
};
class Items
{
	char name[32];	
	unsigned int quantity, sale;
	Price price;
public:
	Items() {}
	Items(char _name[32], int _quantity, int _leva, int _stotinki, int _sale)
	{
		strcpy_s(name, strlen(_name) + 1, _name);
		quantity = _quantity;
		sale = _sale;
		price.set_leva(_leva);
		price.set_stotinki(_stotinki);
	}
	char* get_name() { return name; }
	void set_quantity(int _quantity) { quantity = _quantity; }
	int get_quantity() { return quantity; }
	int amount() { return price.amount(); }
	double amount_sale() { return price.amount()*(100 - sale) / 100.; }
	void print() { cout <<"name:"<< name << "    quantity:" << quantity << "    leva:" << price.get_leva() << "    stotinki:" <<price.get_stotinki() <<"    sale:"<< sale << endl; }
};
