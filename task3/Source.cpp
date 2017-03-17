#include <iostream>
#include <fstream>
#include "OnlineStore.h"
using namespace std;
int main()
{
	OnlineStore test("StoreInfo.txt", "User.txt");
	test.print_user();
	test.login();
}