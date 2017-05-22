#include <iostream>
#include "Firm.h"
using namespace std;
int main()
{
	Firm a;
	a.add( Programmer("testche",4,0,1) );
	a.add(Manager("wtf", 23, 10));
	Manager www("wtf", 23, 10);
	a.print();
	a.add(www);
	a.print();	
}