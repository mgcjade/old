#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define reb(i, a, b) for (int i = (a); i >= (b); i--)
#define ref(i, a, b) for (int i = (a); i < (b); i++)
using namespace std;
typedef long long ll;
// #define int long long

const int N = 1e6;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

int n, X, Y;
int x, y;
string s;

int turn[130][2];
map<pair<int, int>, int> mp;

signed main()
{
    turn['N'][0] = 1, turn['W'][1] = 1, turn['S'][0] = -1, turn['E'][1] = -1;
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> X >> Y;
    cin >> s;
    s = " " + s;
    x = 0, y = 0;
    mp[{x, y}] = 1;
    rep(i, 1, n)
    {
        int dx = turn[s[i]][0], dy = turn[s[i]][1];
        x += dx, y += dy;
        X += dx, Y += dy;
        mp[{x, y}] = 1;
        if (mp.find({X, Y}) != mp.end())
            cout << 1;
        else
            cout << 0;
    }
    return 0;
}