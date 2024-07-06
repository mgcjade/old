#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
using namespace std;
typedef long long ll;

const int N = 1e6;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

ll ans;
ll sum;
ll sx, sy;
ll ex, ey;

int main()
{
    cin >> sx >> sy >> ex >> ey;
    if ((sx + sy) & 1)
        sx--;
    if ((ex + ey) & 1)
        ex--;
    ans = min(abs(sx - ex), abs(sy - ey));
    if (ans == abs(sx - ex))
        ans = abs(sy - ey);
    else
        ans = abs(sy - ey) + abs((sx < ex ? sx + abs(sy - ey) : sx - abs(sy - ey)) - ex) / 2;
    cout << ans;
    return 0;
}