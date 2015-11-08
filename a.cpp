#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <string>
#include <iostream>
#include <map>
using namespace std;
map<string, int> wa_times;
int main()
{
	int t, cnt_ac = 0, p = 0;
	string prob, status;
	while(1)
	{
		cin >> t;
		if (t == -1)
			break;
		cin >> prob >> status;
		if (status == "wrong")
			wa_times[prob] += 1;
		if (status == "right" && wa_times[prob] != -1)
		{
			cnt_ac += 1;
			p += wa_times[prob] * 20 + t;
			wa_times[prob] = -1;
		}
	}
	cout << cnt_ac << " " << p << endl;
	return 0;
}