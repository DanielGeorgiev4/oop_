#include <iostream>
#include "Commander.h"
using namespace std;
int main()
{
	Knight test;
	Commander a(10),b(test);
	test.print_stats();
	b.print_stats();
	test.buff();
	test.print_stats();
	b.print_stats();
	cout << endl;
}