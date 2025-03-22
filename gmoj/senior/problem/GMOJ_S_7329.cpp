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
const int MOD = 1e9;

int n, k, T;
string s;
int a[N], w[N];
int ans;

priority_queue<int> q1;                            // 大根堆
priority_queue<int, vector<int>, greater<int>> q2; // 小根堆
void clr()
{
    ans = 0;
    while (!q1.empty())
        q1.pop();
    while (!q2.empty())
        q2.pop();
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> k >> T;
    cin >> s;
    s = " " + s;
    rep(i, 1, k) cin >> a[i];
    rep(i, 1, n) cin >> w[i];
    rep(_CnT, 1, n)
    {
        w[_CnT] = (w[_CnT] + ans * T) % MOD;
        clr();
        rep(i, 1, _CnT) q1.push(w[i]), q2.push(w[i]), ans += w[i] /*, cerr << ans << ' '*/;
        rep(i, 1, k)
        {
            ans += a[i];
            q1.push(a[i]), q2.push(a[i]);
            if (s[i] == '0')
                /*cerr << q2.top() << " x ", */ ans -= q2.top(), q2.pop();
            else
                /*cerr << q1.top() << " x ",*/ ans -= q1.top(), q1.pop();
            /* cerr << ans << ' ';*/
        }
        /*  cerr << '\n';*/
        cout << ans << ' ';
    }
    return 0;
}
