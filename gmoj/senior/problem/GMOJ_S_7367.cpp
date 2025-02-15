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
const int MOD = 998244353;

class ST
{
private:
    int _Tp[N][__lg(N)];

public:
    void init(int _N, int *_A)
    {
        rep(i, 1, _N) _Tp[i][0] = _A[i];
        int _s = __lg(_N);
        rep(i, 1, _s) rep(j, 1, _N - (1 << i) + 1) _Tp[j][i] = max(_Tp[j][i - 1], _Tp[j + (1 << (i - 1))][i - 1]);
    }
    int mymax(int _L, int _R)
    {
        if (_L > _R)
            return -INF;
        int _K = __lg(_R - _L + 1);
        return max(_Tp[_L][_K], _Tp[_R - (1 << _K) + 1][_K]);
    }
};
class TREE_ARRAY
{
private:
    int t1[N], t2[N];
    int lowbit(int x) { return x & (-x); }

public:
    int n;
    void add(int k, int v)
    {
        int v1 = k * v;
        v %= MOD, v1 %= MOD;
        while (k <= n)
        {
            t1[k] += v, t2[k] += v1;
            t1[k] %= MOD, t2[k] %= MOD;
            k += lowbit(k);
        }
    }
    int getsum(int *t, int k)
    {
        int ret = 0;
        while (k)
        {
            ret += t[k];
            ret %= MOD;
            k -= lowbit(k);
        }
        return ret;
    }
    void add1(int l, int r, int v) // 区间加
    {
        if (l > r)
            return;
        add(l, v), add(r + 1, -v);
    }
    long long getsum1(int l, int r) // 区间和
    {
        int res = 0;
        res += (r + 1ll) * getsum(t1, r) % MOD;
        res -= 1ll * l * getsum(t1, l - 1) % MOD;
        res -= (getsum(t2, r) - getsum(t2, l - 1)) % MOD;
        res = (res + MOD) % MOD;
        return res;
    }
    // void debug()
    // {
    //     rep(i, 1, n) cout << getsum1(i, i) << ' ';
    //     cout << '\n';
    // }
};

ST st;
TREE_ARRAY t0, t1, t2;
int n, m;
int a[N];
struct node
{
    int x, y, w;
    bool operator<(const node &other) const
    {
        return this->y < other.y;
    }
} b[N];
int L[N], R[N];

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    t0.n = n, t1.n = n, t2.n = n;
    rep(i, 1, n) cin >> a[i];
    rep(i, 1, m) cin >> b[i].x >> b[i].y >> b[i].w;
    sort(b + 1, b + m + 1);
    st.init(n, a);
    rep(i, 1, m)
    {
        int l, r;
        l = 1, r = b[i].x - 1;
        while (l <= r)
        {
            int mid = (l + r) >> 1;
            if (st.mymax(mid, b[i].x - 1) < b[i].y)
                r = mid - 1;
            else
                l = mid + 1;
        }
        L[i] = r + 1;
        l = b[i].x + 1, r = n;
        while (l <= r)
        {
            int mid = (l + r) >> 1;
            if (st.mymax(b[i].x + 1, mid) < b[i].y)
                l = mid + 1;
            else
                r = mid - 1;
        }
        R[i] = l - 1;
        // cerr << L[i] << ' ' << R[i] << '\n';
    }
    int ans = 0;
    rep(i, 1, m)
    {
        b[i].w %= MOD;
        t0.add1(b[i].x, b[i].x, 1), t1.add1(b[i].x, b[i].x, b[i].w), t2.add1(b[i].x, b[i].x, b[i].w * b[i].w % MOD);
        // cerr << i << ' ' << t0.getsum1(L[i], R[i]) << ' ' << t1.getsum1(L[i], R[i]) << ' ' << t2.getsum1(L[i], R[i]) << '\n';
        ans += t2.getsum1(L[i], R[i]) + b[i].w * b[i].w % MOD * t0.getsum1(L[i], R[i]) % MOD - 2 * t1.getsum1(L[i], R[i]) % MOD * b[i].w % MOD;
        ans %= MOD;
        // cerr << ans << '\n';
        // t0.debug(), t1.debug(), t2.debug();
        // cout << ans << '\n';
        // cout << '\n';
    }
    ans = (ans + MOD) % MOD;
    cout << ans << '\n';
    // cerr << t0.getsum1(1, n) << ' ' << t1.getsum1(1, n) << ' ' << t2.getsum1(1, n) << '\n';
    return 0;
}