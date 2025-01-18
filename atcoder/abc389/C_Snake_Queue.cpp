#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define reb(i, a, b) for (int i = a; i >= b; i--)
#define ref(i, a, b) for (int i = a; i < b; i++)
using namespace std;
#define int long long

const int N = 1e6;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

int T;
int flag;

int l, r;
int tre[N];
int lowbit(int x) { return x & (-x); }
void add(int val, int x)
{
    while (x <= N)
    {
        tre[x] += val;
        x += lowbit(x);
    }
}
int sum(int x)
{
    int res = 0;
    while (x)
    {
        res += tre[x];
        x -= lowbit(x);
    }
    return res;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> T;
    int tmp;
    while (T--)
    {
        cin >> flag;
        if (flag == 1)
        {
            cin >> tmp;
            r++;
            add(tmp, r);
        }
        else if (flag == 2)
        {
            l++;
        }
        else
        {
            cin >> tmp;
            cout << sum(tmp + l - 1) - sum(l) << '\n';
        }
    }
    return 0;
}