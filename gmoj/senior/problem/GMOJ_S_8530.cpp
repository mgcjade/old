#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define reb(i, a, b) for (int i = (a); i >= (b); i--)
#define ref(i, a, b) for (int i = (a); i < (b); i++)
using namespace std;
typedef long long ll;
#define int long long

const int N = 1e6 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

template <typename _Tp>
class Tree_Array
{
private:
    _Tp t1[N + 5], t2[N + 5], n;
    _Tp lowbit(_Tp x) { return x & (-x); }
    void _add(_Tp k, _Tp v)
    {
        _Tp v1 = k * v;
        while (k <= n)
            t1[k] += v, t2[k] += v1, k += lowbit(k);
    }
    _Tp _getsum(_Tp *t, _Tp k)
    {
        _Tp ret = 0;
        while (k)
            ret += t[k], k -= lowbit(k);
        return ret;
    }

public:
    void init(_Tp n) { this->n = n; }
    void add(_Tp l, _Tp r, _Tp v) { _add(l, v), _add(r + 1, -v); }
    long long sum(_Tp l, _Tp r) { return (r + 1ll) * _getsum(t1, r) - 1ll * l * _getsum(t1, l - 1) - (_getsum(t2, r) - _getsum(t2, l - 1)); }
};

int n;
int a[N], mx;
Tree_Array<int> t;
Tree_Array<int> s, v;
int Ans;

char op;
int x;

signed main()
{
    t.init(N), s.init(N), v.init(N);
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    rep(i, 1, n) cin >> a[i];
    reb(i, n, 1)
    {
        t.add(a[i], a[i], 1);
        int tP = t.sum(1, a[i] - 1);
        mx = max(mx, tP);
        if (tP)
            s.add(tP, tP, 1), v.add(tP, tP, tP);
    }
    int T;
    cin >> T;
    while (T--)
    {
        cin >> op >> x;
        if (op == 'A')
        {
            t.add(x, x, 1);
            int tP = t.sum(1, x - 1);
            mx = max(mx, tP);
            if (tP)
                s.add(tP, tP, 1), v.add(tP, tP, tP);
        }
        else
        {
            int ans = v.sum(1, x) + s.sum(x + 1, mx) * x;
            Ans ^= ans;
            // cerr << ans << '\n';
        }
    }
    cout << Ans << '\n';
    // cout << '\n';
    // rep(i, 1, mx) cout << v.sum(i, i) << ' ' << s.sum(i, i) << '\n';
    return 0;
}