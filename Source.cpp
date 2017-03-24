#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int main()
{
	ifstream file("test.txt");
	string **data, helper;
	int number_rows = 0;
	while (!file.eof())
	{
		number_rows++;
		getline(file, helper);
	}
	data = new string*[number_rows];
	file.clear();
	file.seekg(0, ios::beg);
	int i = 0;
	while (!file.eof())
	{
		getline(file, helper);
		int number_cols = 1;
		for (int k = 0; k < helper.length(); k++)
		{
			if (helper[k] == ',') number_cols++;
		}
		data[i] = new string[number_cols];
		number_cols = 0;
	    for (int k = 0; k < helper.length(); k++)
		{
			int start=k, finish = 0;
			while (helper[k] != ',' && k<helper.length())
			{
				finish++;
				k++;
			}
			data[i][number_cols].append(helper, start, finish);
			number_cols++;
		}
		i++;
	}
	for (int i = 0; i < number_rows; i++)
	{
		for (int k = 0; k < 3;k++)
		{
			cout << data[i][k] << ' ';
		}
		cout << endl;
	}
}