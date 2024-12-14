#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define reb(i, a, b) for (int i = a; i >= b; i--)
#define ref(i, a, b) for (int i = a; i < b; i++)
#define PAIR pair<int, int>
using namespace std;
#define int __int128

template <class _Tp>
void read(_Tp &s)
{
    s = 0;
    char ch = getchar(), last = ' ';
    while (ch < '0' || ch > '9')
        last = ch, ch = getchar();
    while (ch >= '0' && ch <= '9')
        s = (s << 3) + (s << 1) + (ch ^ 48), ch = getchar();
    if (last == '-')
        s = -s;
}
template <class _Tp>
void write(_Tp s)
{
    if (s < 0)
        putchar('-'), s = -s;
    _Tp y = 10;
    int len = 1;
    while (y <= s)
        y *= 10, len++;
    while (len--)
    {
        y /= 10;
        putchar(s / y + 48);
        s %= y;
    }
}

const int N = 1e6;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

int turn[4][2] = {0, 1, 1, 0, -1, 0, 0, -1};
int h, w, p, q;
int X, s[505][505], ans, bz[505][505];
priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> qq;

signed main()
{
    read(h), read(w), read(X), read(p), read(q);
    rep(i, 1, h)
    {
        rep(j, 1, w)
        {
            read(s[i][j]);
        }
    }
    ans = s[p][q];
    bz[p][q] = 1;
    rep(i, 0, 3)
    {
        int nx = p + turn[i][0], ny = q + turn[i][1];
        if (nx >= 1 && nx <= h && ny >= 1 && ny <= w && !bz[nx][ny])
            qq.push(make_pair(s[nx][ny], make_pair(nx, ny))), bz[nx][ny] = 1;
    }
    while (!qq.empty())
    {
        auto [x, y] = qq.top().second;
        qq.pop();
        if (s[x][y] * X < ans)
        {
            ans += s[x][y];
            rep(i, 0, 3)
            {
                int nx = x + turn[i][0], ny = y + turn[i][1];
                if (nx >= 1 && nx <= h && ny >= 1 && ny <= w && !bz[nx][ny])
                    qq.push(make_pair(s[nx][ny], make_pair(nx, ny))), bz[nx][ny] = 1;
            }
        }
    }
    write(ans);
    return 0;
}