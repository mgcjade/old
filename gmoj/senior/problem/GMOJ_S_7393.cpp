#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define reb(i, a, b) for (int i = a; i >= b; i--)
#define ref(i, a, b) for (int i = a; i < b; i++)
using namespace std;
#define int long long

const int N = 1e7 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

int n, c[100005], m, k[15], z[100005], cnt;
map<int, int> num;
char ans[10000005];
int anss[10000005];

void caozuo1(int x)
{
    int g = x;
    while (x)
        z[x] = c[x], x >>= 1;
    x = g;
    while (x)
    {
        if (x != 1)
            c[x / 2] = z[x];
        else
            c[g] = z[x];
        x >>= 1;
    }
}
void caozuo2(int x)
{
    int g = x;
    while (x)
        z[x] = c[x], x >>= 1;
    x = g;
    while (x)
    {
        if (x != 1)
            c[x] = z[x / 2];
        else
            c[x] = z[g];
        x >>= 1;
    }
}
void caozuo3(int x)
{
    int u = x * 2, v = x * 2 + 1;
    while (u < (1 << n - 1))
        u *= 2, v *= 2;
    anss[cnt + 1] = u, ans[cnt + 1] = 'U';
    anss[cnt + 2] = v, ans[cnt + 2] = 'U';
    anss[cnt + 3] = u, ans[cnt + 3] = 'D';
    anss[cnt + 4] = v, ans[cnt + 4] = 'D';
    cnt += 4;
    swap(c[u], c[v]), swap(c[x], c[x / 2]);
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    m = (1 << n) - 1;
    rep(i, 1, m)
    {
        cin >> c[i];
        num[c[i]]++;
    }
    rep(i, 1, n)
    {
        int p = (1 << i - 1), x = 0;
        bool bz = 1;
        rep(j, 1, m)
        {
            if (num[c[j]] & p)
                bz = 0, x = c[j];
        }
        if (bz)
        {
            cout << -1 << '\n';
            return 0;
        }
        k[i] = x;
    }
    ref(j, (1 << n - 1), (1 << n))
    {
        if (c[j] == k[n])
            continue;
        ref(s, 1, (1 << n - 1))
        {
            if (c[s] != k[n])
                continue;
            int u = j, v = s, cnts = 0;
            while (u != v)
            {
                if (u > v)
                    u >>= 1, cnts++;
                else
                    v >>= 1;
            }
            v = s;
            while (v != u)
                caozuo3(v), v >>= 1;
            while (cnts--)
            {
                cnt++;
                ans[cnt] = 'U', anss[cnt] = j;
                caozuo2(j);
            }
            break;
        }
    }
    reb(i, n - 1, 1)
    {
        ref(j, (1 << i - 1), (1 << i))
        {
            if (c[j] == k[i])
                continue;
            ref(s, 1, (1 << i - 1))
            {
                if (c[s] != k[i])
                    continue;
                int u = j, v = s, cnts = 0;
                while (u != v)
                {
                    if (u > v)
                        z[++cnts] = u, u >>= 1;
                    else if (v > u)
                        v >>= 1;
                }
                v = s;
                while (v != u)
                    caozuo3(v), v >>= 1;
                reb(g, cnts, 1)
                    caozuo3(z[g]);
                break;
            }
        }
    }
    cout << cnt << '\n';
    rep(i, 1, cnt) cout << anss[i] << ' ' << ans[i] << '\n';
    return 0;
}
