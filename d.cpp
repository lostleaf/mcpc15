//team: CoolWildCats
//d.cpp
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <string>
#include <iostream>
#include <map>
using namespace std;
map<char, int> times;
void fail()
{
	cout << "FAIL" << endl;
	exit(0);
}
int main()
{
	string p, s;
	cin >> p >> s;
	for (int i = 0; i < p.size(); i++)
		times[p[i]]++;
	int i, j;
	for (i = 0, j = 0; i < p.size() && j < s.size();)
	{
		for (; j < s.size(); j++){
			if (p[i] == s[j])
			{
				times[p[i]]--;
				j++;
				i++;
				break;
			}
			if (times[s[j]] > 0)
			{
				// printf("%d\n", j);
				fail();				
			}
		}
	}
	if (i >= p.size())
		cout << "PASS" << endl;
	else
		fail();
	return 0;
}
