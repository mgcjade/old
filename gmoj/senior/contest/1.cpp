#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
using namespace std;
typedef long long ll;

const int N = 1e6;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

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

int n, m;
int a[5005][5005];
int x[5005], y[5005];
int ans[5005];
int nw[5005], cnt;

bool vis[5005];
void dg(int k)
{
	vis[k] = 1;
	nw[++cnt] = k;
	for (int i = 1; i <= n; i++)
		if (!vis[i] && a[k][i])
			dg(i);
}
bool check()
{
	if (cnt < n)
		return 0;
	for (int i = 1; i <= n; i++)
		if (nw[i] < ans[i])
			return 1;
		else if (nw[i] > ans[i])
			return 0;
	return 0;
}

int main()
{
	// fre(travel);
	// memset (ans, 0x3f, sizeof(ans));
	read(n), read(m);
	for (int i = 1; i <= m; i++)
	{
		read(x[i]), read(y[i]);
		a[x[i]][y[i]] = 1;
		a[y[i]][x[i]] = 1;
	}
	dg(1);
	for (int i = 1; i <= n; i++)
		ans[i] = nw[i];
	for (int i = 1; i <= m; i++)
	{
		a[x[i]][y[i]] = 0;
		a[y[i]][x[i]] = 0;
		memset(vis, 0, sizeof(vis));
		cnt = 0;
		dg(1);
		if (check())
		{
			for (int i = 1; i <= n; i++)
				ans[i] = nw[i];
		}
		a[x[i]][y[i]] = 1;
		a[y[i]][x[i]] = 1;
	}
	for (int i = 1; i <= n; i++)
		printf("%d ", ans[i]);
	return 0;
}
