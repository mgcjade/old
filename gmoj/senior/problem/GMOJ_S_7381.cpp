#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
#define rep(i, a, _a) for (int i = (a); i <= (_a); i++)
#define reb(i, a, _a) for (int i = (a); i >= (_a); i--)
#define ref(i, a, _a) for (int i = (a); i < (_a); i++)
using namespace std;
typedef long long ll;
// #define int long long

const int N = 1e6;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

int n, m;
int k;
int a[N], _a[N];
int cnt, _cnt;
pair<int, int> ans[10 * N], _ans[10 * N];

int b[N];
void reverse(int l, int r)
{
    if (l >= r)
        return;
    int mid = (l + r - 1) >> 1;
    rep(i, l, mid)
    {
        swap(a[i], a[r - i + l]);
        ans[++cnt] = {i, r - i + l};
    }
}
void dfs(int l, int mid, int r)
{
    if (l >= r)
        return;
    if (l + 1 == r)
    {
        if (a[l] > a[r])
            ans[++cnt] = {l, r};
        return;
    }
    rep(i, l, r) b[i] = a[i];
    sort(b + l, b + r + 1);
    int val = b[mid];
    int nl = l - 1, nr = mid;
    rep(i, l, mid) if (a[i] < val) nl = i;
    rep(i, mid + 1, r) if (a[i] < val) nr = i;
    reverse(nl + 1, mid), reverse(mid + 1, nr);
    reverse(nl + 1, nr);
    if (nl >= l)
        dfs(l, nl, mid);
    if (mid < nr)
        dfs(mid + 1, nr, r);
}
void dg(int l, int r)
{
    if (l >= r)
        return;
    if (l + 1 == r)
    {
        if (a[l] > a[r])
            ans[++cnt] = {l, r};
        return;
    }
    int mid = (l + r) >> 1;
    dg(l, mid), dg(mid + 1, r);
    rep(i, l, r) b[i] = a[i];
    sort(b + l, b + r + 1);
    int val = b[mid];
    int nl = l - 1, nr = mid;
    rep(i, l, mid) if (a[i] < val) nl = i;
    rep(i, mid + 1, r) if (a[i] < val) nr = i;
    reverse(nl + 1, mid), reverse(mid + 1, nr);
    reverse(nl + 1, nr);
    if (nl >= l)
        dfs(l, nl, mid);
    if (mid < nr)
        dfs(mid + 1, nr, r);
}

int _b[N];
void _reverse(int _l, int _r)
{
    if (_l >= _r)
        return;
    int _mid = (_l + _r - 1) >> 1;
    rep(_i, _l, _mid)
    {
        swap(_a[_i], _a[_r - _i + _l]);
        _ans[++_cnt] = {_i, _r - _i + _l};
    }
}
void _dfs(int _l, int _mid, int _r)
{
    if (_l >= _r)
        return;
    if (_l + 1 == _r)
    {
        if (_a[_l] > _a[_r])
            _ans[++_cnt] = {_l, _r};
        return;
    }
    rep(_i, _l, _r) _b[_i] = _a[_i];
    sort(_b + _l, _b + _r + 1);
    int _val = _b[_mid];
    int _nl, _nr;
    rep(_i, _l, _mid) if (_a[_i] < _val) _nl = _i;
    rep(_i, _mid + 1, _r) if (_a[_i] < _val) _nr = _i;
    _reverse(_nl + 1, _mid), _reverse(_mid + 1, _nr);
    _reverse(_nl + 1, _nr);
    if (_nl >= _l)
        _dfs(_l, _nl, _mid);
    if (_mid < _nr)
        _dfs(_mid + 1, _nr, _r);
}
void _dg(int _l, int _r)
{
    if (_l >= _r)
        return;
    if (_l + 1 == _r)
    {
        if (_a[_l] > _a[_r])
            _ans[++_cnt] = {_l, _r};
        return;
    }
    int _mid = (_l + _r) >> 1;
    _dg(_l, _mid), _dg(_mid + 1, _r);
    rep(_i, _l, _r) _b[_i] = _a[_i];
    sort(_b + _l, _b + _r + 1);
    int _val = _b[_mid];
    int _nl = _l - 1, _nr = _mid;
    rep(_i, _l, _mid) if (_a[_i] < _val) _nl = _i;
    rep(_i, _mid + 1, _r) if (_a[_i] < _val) _nr = _i;
    _reverse(_nl + 1, _mid), _reverse(_mid + 1, _nr);
    _reverse(_nl + 1, _nr);
    if (_nl >= _l)
        _dfs(_l, _nl, _mid);
    if (_mid < _nr)
        _dfs(_mid + 1, _nr, _r);
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    rep(i, 1, n) cin >> a[i];
    rep(i, 1, n) cin >> _a[i];
    dg(1, n), _dg(1, n);
    cout << cnt + _cnt << '\n';
    rep(i, 1, cnt) cout << ans[i].first << ' ' << ans[i].second << '\n';
    reb(i, _cnt, 1) cout << _ans[i].first << ' ' << _ans[i].second << '\n';
    return 0;
}