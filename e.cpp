#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <string>
#include <iostream>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <deque>
using namespace std;
const int maxn = 6;
#define power powe
unordered_map<int, int> ret;
unordered_set<int> inque;
int vol[maxn], n, target, power[maxn], best = 2000000000;
int get_volumn(int s, int i)
{
	return (s / power[i]) % 65;
}
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &vol[i]);
	power[0] = 1;
	for (int i = 1; i <= 5; i++)
		power[i] = power[i - 1] * 65;
	scanf("%d", &target);
	if (target == vol[0])
	{
		printf("0\n");
		return 0;
	}
	deque<int> que;
	ret[vol[0]] = 0;
	que.push_back(vol[0]);
	// return 0;
	while(!que.empty())
	{
		int cur_s = que[0];
		for (int i = 0; i < n; i++)
		{
			int vol_i = get_volumn(cur_s, i);
			for (int j = 0; j < n; j++)
				if (i != j)
				{
					int vol_j = get_volumn(cur_s, j);
					int pour = min(vol_i, vol[j] - vol_j);
					if (pour == 0)
						continue;
					int new_s = cur_s - pour * power[i] + pour * power[j];
					int new_cost = ret[cur_s] + pour;
					if (ret.find(new_s) == ret.end() || ret[new_s] > new_cost)
					{
						ret[new_s] = new_cost;
						if (get_volumn(new_s, 0) == target && new_cost < best)
							best = new_cost;
						if (inque.find(new_s) == inque.end())
						{
							inque.insert(new_s);
							que.push_back(new_s);
						}
					}
				}
		}
		inque.erase(que[0]);
		que.pop_front();
	}
	if (best == 2000000000)
		printf("impossible\n");
	else
		printf("%d\n", best);
	return 0;
}