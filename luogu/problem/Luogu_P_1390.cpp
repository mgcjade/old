#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
using namespace std;
typedef long long ll;

const int N = 2e6 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

ll phi[N];
bool is[N];
int prime[N], cnt;
void init(int n)
{
    phi[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        if (!is[i])
        {
            prime[++cnt] = i;
            phi[i] = i - 1;
        }
        for (int j = 1; j <= cnt && i * prime[j] <= n; j++)
        {
            is[i * prime[j]] = 1;
            if (i % prime[j] == 0)
            {
                phi[i * prime[j]] = phi[i] * prime[j];
                break;
            }
            phi[i * prime[j]] = phi[i] * (prime[j] - 1);
        }
    }
}

int n;
ll ans;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    init(n);
    for (int i = 1; i <= n; i++)
        ans += phi[i] * (n / i) * (n / i - 1) / 2;
    cout << ans << '\n';
    return 0;
}