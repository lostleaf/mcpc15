#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <string>
#include <iostream>
#include <map>
using namespace std;
const int maxn = 15;
bool used[maxn];
string data[maxn];
int n, best = 1000000000;
int calc_cost(int a, int b)
{
	int ans = 0;
	for (int i = 0, j = 0; i < data[a].size() && j < data[b].size();)
	{
		if (data[a][i] == data[b][j])
		{
			i++; j++;
			ans++;
			continue;
		}
		if (data[a][i] < data[b][j])
			i++;
		else
			j++;
	}
	return ans;
}
void dfs(int cur, int depth, int cost)
{
	// used[cur] = 1;
	if (depth == n - 1)
	{
		if (best > cost)
			best = cost;
		return;
	}
	used[cur] = 1;
	for (int i = 0; i < n; i++)
		if (!used[i])
		{
			int cost1 = cost + calc_cost(cur, i);
			if (cost1 < best)
				dfs(i, depth + 1, cost1);
		}
	used[cur] = 0;
}
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> data[i];
	// int ans = 1000000000;
	for (int i = 0; i < n; i++)
		dfs(i, 0, 0);
	printf("%d\n", best);
	return 0;
}