#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout);
using namespace std;
typedef long long ll;

const int N = 2e5 + 5;
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
    if (last == '-')
        s = -s;
}

int n;
int a[N];
int ans;

int main()
{
    read(n);
    for (int i = 1; i <= n; i++)
        read(a[i]);
    
    printf("%d", ans);
    return 0;
}