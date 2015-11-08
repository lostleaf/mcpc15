#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <string>
#include <iostream>
#include <map>
using namespace std;
const int MAXN = 5005;
int f[MAXN], w[MAXN], h[MAXN];
int n, c;
int main(){
	scanf("%d %d",&n, &c);
	// printf("%d %d\n", n, c);
	for(int i = 1; i <= n; i++)
	{
		scanf("%d%d",&w[i],&h[i]);
		// printf("%d %d\n", w[i], h[i]);
	}
	for(int i = 1; i <= n; i++)
	{
		int tot_w = 0;
		f[i] = 1000000000;
		int max_h = 0;
		for (int j = i; j > 0; j--)
		{
			max_h = max(max_h, h[j]);
			tot_w += w[j];
			if (tot_w > c)
				break;
			f[i] = min(f[i], f[j - 1] + max_h);
		}
	}
	printf("%d\n", f[n]);
	return 0;
}