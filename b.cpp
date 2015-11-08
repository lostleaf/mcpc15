#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <string>
#include <iostream>
using namespace std;
#define sqr(x) ((x) * (x))
#define norm(x, y) (sqrt((sqr(x)) + (sqr(y))))
const double eps = 1e-10;
int n;
double T;
const int maxn = 110;
struct Circle {
	double x, y, vx, vy, r;
};
Circle data[maxn];
double collision_time(const Circle &c1, const Circle &c2)
{
	double dvx = c2.vx - c1.vx, dvy = c2.vy - c1.vy;
	double dx = c1.x - c2.x, dy = c1.y - c2.y;
	double z = norm(dx, dy);
	double norm_v = norm(dvx, dvy);
	if (norm_v < eps)
		return -1;
	double cos_theta = (dx * dvx + dy * dvy) / z / norm_v;
	double b = -2 * z * cos_theta;
	double c = sqr(z) - sqr(c1.r + c2.r);
	double delta = sqr(b) - 4 * c;
	// printf("%lf\n", delta);
	if (delta < 0)
		return -1;
	double x = (-b - sqrt(delta)) / 2;
	double t = x / norm_v;
	// printf("%lf\n", t);
	return t;
}
void output()
{
	printf("%d %.10lf\n", n, T);
	exit(0);
}
void debug_output()
{
	printf("%d %.10lf\n", n, T);
	for (int i = 0; i < n; i++)
		printf("%lf %lf %lf %lf %lf\n", data[i].x, data[i].y, data[i].vx, data[i].vy, data[i].r);
	printf("\n-----------\n");
}
void doit()
{
	double min_time = 1e100;
	int i_ch, j_ch;
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			if (i != j)
			{
				double c_time = collision_time(data[i], data[j]);
				if (c_time < 0)
					continue;
				if (c_time < min_time)
				{
					min_time = c_time;
					i_ch = i;
					j_ch = j;
				}
			}
	if (min_time == 1e100)
		output();
	double x1 = data[i_ch].x, x2 = data[j_ch].x, y1 = data[i_ch].y, y2 = data[j_ch].y;
	double x1_prime = x1 + data[i_ch].vx * min_time, y1_prime = y1 + data[i_ch].vy * min_time;
	double x2_prime = x2 + data[j_ch].vx * min_time, y2_prime = y2 + data[j_ch].vy * min_time;
	double r3_sqr = sqr(data[i_ch].r) + sqr(data[j_ch].r);
	double r3 = sqrt(r3_sqr);
	double x3 = sqr(data[i_ch].r) / r3_sqr * x1_prime + sqr(data[j_ch].r) / r3_sqr * x2_prime;
	double y3 = sqr(data[i_ch].r) / r3_sqr * y1_prime + sqr(data[j_ch].r) / r3_sqr * y2_prime;
	double vx3 = sqr(data[i_ch].r) / r3_sqr * data[i_ch].vx + sqr(data[j_ch].r) / r3_sqr * data[j_ch].vx;
	double vy3 = sqr(data[i_ch].r) / r3_sqr * data[i_ch].vy + sqr(data[j_ch].r) / r3_sqr * data[j_ch].vy;
	swap(data[j_ch], data[n - 1]);
	data[i_ch].x = x3; data[i_ch].y = y3;
	data[i_ch].r = r3;
	data[i_ch].vx = vx3; data[i_ch].vy = vy3;
	n--;
	for (int i = 0; i <= n; i++)
		if (i_ch != i)
		{
			data[i].x += data[i].vx * min_time;
			data[i].y += data[i].vy * min_time;
		}
	T += min_time;
	// debug_output();
}
int main()
{
	scanf("%d", &n);
	int nn = n;
	for (int i = 0; i < n; i++)
		scanf("%lf%lf%lf%lf%lf", &data[i].x, &data[i].y, &data[i].vx, &data[i].vy, &data[i].r);
	for (int i = 0; i < nn; i++)
		doit();
	output();
	return 0;
}