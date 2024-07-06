#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout);
using namespace std;
typedef long long ll;

const int N = 1e6;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

ll n;
int q;
ll k;
ll ans;
ll wei[35];

int main()
{
    wei[1] = 1;
    for (int i = 2; i <= 33; i++)
        wei[i] = wei[i - 1] << 1;
    scanf("%lld%d", &n, &q);
    while (q--)
    {
        scanf("%lld", &k);
        if ((n & wei[k]) == wei[k])
            continue;
        ans += ((n | wei[k]) - (n & (wei[k] - 1))) - n;
        n = (n | wei[k]) - (n & (wei[k] - 1));
    }
    printf("%lld", ans);
    return 0;
}