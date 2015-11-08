#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <string>
#include <iostream>
using namespace std;

int main()
{
	int n;
	string last, cur;
	cin >> n;
	cin >> last >> cur;
	int order = 0;
	if (last < cur) order = -1;
	if (last > cur) order = 1;
	for (int i = 0; i < n - 2; i++)
	{
		last = cur;
		cin >> cur;
		if (last < cur && order == 1)
		{
			cout << "NEITHER" << endl;
			return 0;
		}
		if (last > cur && order == -1)
		{
			cout << "NEITHER" << endl;
			return 0;
		}
	}
	if (order == -1)
		cout << "INCREASING" << endl;
	else
		cout << "DECREASING" << endl;
	return 0;
}