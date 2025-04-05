#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define reb(i, a, b) for (int i = (a); i >= (b); i--)
#define ref(i, a, b) for (int i = (a); i < (b); i++)
using namespace std;
typedef long long ll;
#define int long long

const int N = 1e6;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

int n, ans;
struct node
{
    char flag;
    int a, b;
} in[N];

int Fa[N + 5], Fb[N + 5], Fc[N + 5];

void solve()
{
    memset(Fa, 0, sizeof(Fa)), memset(Fb, 0, sizeof(Fb)), memset(Fc, 0x3f, sizeof(Fc));
    Fc[0] = 0;
    rep(i, 1, n) if (in[i].flag == 'A') reb(j, N, in[i].a + in[i].b) Fa[j] = max(Fa[j], Fa[j - in[i].b - in[i].a] + in[i].b);
    else if (in[i].flag == 'B') reb(j, N, in[i].a + in[i].b) Fb[j] = max(Fb[j], Fb[j - in[i].b - in[i].a] + in[i].b);
    else if (in[i].flag == 'T') reb(j, N, in[i].a + in[i].b) Fc[j] = min(Fc[j], Fc[j - in[i].a - in[i].b] + in[i].a);

    reb(i, N - 1, 0) Fc[i] = min(Fc[i], Fc[i + 1]);
    rep(i, 0, N) ans = max(ans, Fa[i] + Fb[i] - Fc[i]);
}

signed main()
{
    cin >> n;
    rep(i, 1, n) cin >> in[i].flag >> in[i].a >> in[i].b;
    solve();
    rep(i, 1, n) if (in[i].flag == 'T') in[i].flag = 'B';
    else if (in[i].flag == 'B') in[i].flag = 'T';
    solve();
    rep(i, 1, n) if (in[i].flag == 'T') in[i].flag = 'B';
    else if (in[i].flag == 'B') in[i].flag = 'T';
    rep(i, 1, n) if (in[i].flag == 'A') in[i].flag = 'T';
    else if (in[i].flag == 'T') in[i].flag = 'A';
    solve();
    cout << ans;
    return 0;
}