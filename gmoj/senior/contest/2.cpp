#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
using namespace std;
typedef long long ll;

const int N = 5e4 + 5;
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
struct edge
{
	int to, nxt, len;
};
edge a[N << 1];
int hd[N], cnt;
void add(int x, int y, int z)
{
	cnt++;
	a[cnt].to = y;
	a[cnt].len = z;
	a[cnt].nxt = hd[x];
	hd[x] = cnt;
}

int main()
{
	fre(ans);
	read(n), read(m);
	for (int i = 1; i < n; i++)
	{
		int x, y, z;
		read(x), read(y), read(z);
		add(x, y, z), add(y, x, z);
	}
	return 0;
}
