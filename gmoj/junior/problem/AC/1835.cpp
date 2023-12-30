#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
using namespace std;
int n;
int a0, a1, b0, b1;

int gcd(int a, int b)
{
	int c = a % b;
	while (c)
	{
		a = b, b = c, c = a % b;
	}
	return b;
}
int lcm(int a, int b)
{
	return a / gcd(a, b) * b;
}
bool check(int x)
{
	return (gcd(x, a0) == a1) & (lcm(x, b0) == b1);
}

inline void read(int &s)
{
	s = 0;
	char ch = getchar(), last = ' ';
	while (ch < '0' || ch > '9')
		last = ch, ch = getchar();
	while (ch >= '0' && ch <= '9')
		s = (s << 1) + (s << 3) + (ch ^ 48), ch = getchar();
	s = last == '-' ? -s : s;
}

int main()
{
	fre(ans);
	read(n);
	while (n--)
	{
		read(a0), read(a1), read(b0), read(b1);
		int ans = 0;
		// for (int i = 2; p > 1; i++)
		// {
		// 	if (t % i == 0)
		// 		while (p % i == 0)
		// 			p /= i, x *= i;
		// 	while (p % i == 0)
		// 		p /= i;
		// }
		int t = sqrt(b1);
		for (int i = 1; i <= t; i++)
		{
			if (b1 % i)
				continue;
			if (check(i))
				ans++;
			if (i * i != b1 && check(b1 / i))
				ans++;
		}
		printf("%d\n", ans);
	}
	return 0;
}
