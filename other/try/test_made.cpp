#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define reb(i, a, b) for (int i = a; i >= b; i--)
#define ref(i, a, b) for (int i = a; i < b; i++)
using namespace std;
#define int unsigned long long

const int N = 1e6;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int Mod = 998244353;
const int MO = 1e18; // 最大的a[i]的值
mt19937 myrand(time(0) * time(0) % MOD * time(0) % Mod * MOD);

inline int lowbit(int x) { return x & (-x); }
int a[10000];
void solve(int n)
{
    int b[20];
    rep(i, 1, 15) b[i] = myrand() % Mod * myrand() % MO;
    int k = 1;
    reb(i, 60, 0)
    {
        rep(j, k, 15) if (b[j] & (1ull << i))
        {
            swap(b[j], b[k]);
            break;
        }
        if (b[k] & (1ull << i))
        {
            rep(j, 1, 15) if (j != k && (b[j] & (1ull << i))) b[j] ^= b[k];
            k++;
        }
        if (k == n)
            break;
    }
    int s = (1ull << n) - 1;
    rep(i, 1, s) a[i] = 1;
    rep(i, 1, s) for (int j = i; j; j -= lowbit(j)) a[i] ^= b[__lg(lowbit(j))];
    rep(i, 1, s)
    {
        a[i + 1 * s] = a[i];
        a[i + 2 * s] = a[i];
        a[i + 3 * s] = a[i];
        a[i + 4 * s] = a[i];
        a[i + 5 * s] = a[i];
        a[i + 6 * s] = a[i];
        a[i + 7 * s] = a[i];
        a[i + 8 * s] = a[i];
        a[i + 9 * s] = a[i];
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    const int n = 100;
    const int k = 5; // 最多能生成线性基的个数（不能超过6）（建议调4~6，不然程序可能会挂）
    solve(k);
    shuffle(a + 1, a + 151, myrand);
    cout << n << '\n';
    rep(i, 1, n) cout << a[i] << ' ';
    cout << '\n';
    return 0;
}