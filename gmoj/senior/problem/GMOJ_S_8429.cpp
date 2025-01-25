#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define reb(i, a, b) for (int i = a; i >= b; i--)
#define ref(i, a, b) for (int i = a; i < b; i++)
using namespace std;
#define int long long

const int N = 1e4 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

int n;
int a[N];
int ans;

struct node
{
    int val;
    int pre, nxt;
} b[N];
bool cmp(node a, node b) { return a.val < b.val; }
int table[N];

int tong[N];
void qsort(int l, int r)
{
    rep(i, 1, n) tong[i] = 0;
    rep(i, l, r) tong[b[i].val]++;
    int i = l, j = 1;
    while (i <= r)
    {
        while (tong[j] == 0)
            j++;
        b[i].val = j;
        i++, j++;
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    rep(i, 1, n) cin >> a[i];
    rep(i, 1, n)
    {
        ans += i * i * a[i];
        rep(j, i, n) b[j].val = a[j];
        if ((n & 1) == (i & 1))
        {
            qsort(i, n);
            rep(j, i, n) b[j].pre = j - 1, b[j].nxt = j + 1, table[b[j].val] = j;
        }
        else
        {
            qsort(i, n - 1);
            ref(j, i, n) b[j].pre = j - 1, b[j].nxt = j + 1, table[b[j].val] = j;
        }
        int mid = (i + n) >> 1;
        for (int j = n - ((n - i) & 1); j > i; j -= 2)
        {
            ans += b[mid].val * i * j;
            auto x = &b[table[a[j]]], y = &b[table[a[j - 1]]];
            if (x->val > y->val)
                swap(x, y);
            if (y->val <= b[mid].val)
                mid = b[mid].nxt;
            else if (x->val >= b[mid].val)
                mid = b[mid].pre;
            b[x->nxt].pre = x->pre, b[x->pre].nxt = x->nxt;
            b[y->nxt].pre = y->pre, b[y->pre].nxt = y->nxt;
        }
        // cout << ans << '\n';
    }
    cout << ans << '\n';
    // fprintf(stderr, "#%.3lf", 1.0 * clock() / CLOCKS_PER_SEC);
    return 0;
}