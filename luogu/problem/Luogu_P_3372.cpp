#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
using namespace std;
typedef long long ll;

const int N = 1e5;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

int n, m;
int bd[N];
int flag, x, y, k;

struct Segment_Tree_Node
{
    int n;
    int l[4 * N], r[4 * N];
    ll sum[4 * N];
    ll lz[4 * N];
    void init()
    {
        n = 0;
        memset(l, 0, sizeof(l));
        memset(r, 0, sizeof(r));
        memset(sum, 0, sizeof(sum));
        memset(lz, 0, sizeof(lz));
    }
    void push_up(int k)
    {
        sum[k] = sum[k * 2] + sum[k * 2 + 1];
    }
    void push_down(int k)
    {
        if (lz[k])
        {
            lz[2 * k] += lz[k], sum[2 * k] += lz[k] * (r[2 * k] - l[2 * k] + 1);
            lz[2 * k + 1] += lz[k], sum[2 * k + 1] += lz[k] * (r[2 * k + 1] - l[2 * k + 1] + 1);
            lz[k] = 0;
        }
    }
    void build(int k, int lft, int rgh)
    {
        l[k] = lft, r[k] = rgh;
        if (lft == rgh)
        {
            sum[k] = bd[lft];
            return;
        }
        int mid = (lft + rgh) / 2;
        this->build(2 * k, lft, mid), this->build(2 * k + 1, mid + 1, rgh);
        this->push_up(k);
    }
    void add(int k, int lft, int rgh, int xxs)
    {
        if (r[k] < lft || l[k] > rgh)
            return;
        if (lft <= l[k] && r[k] <= rgh)
        {
            lz[k] += xxs;
            sum[k] += xxs * (r[k] - l[k] + 1);
            return;
        }
        int mid = (l[k] + r[k]) / 2;
        this->add(2 * k, lft, mid, xxs), this->add(2 * k + 1, mid + 1, rgh, xxs);
        this->push_up(k);
    }
    ll cnt(int k, int lft, int rgh)
    {
        if (r[k] < lft || l[k] > rgh)
            return 0;
        if (lft <= l[k] && r[k] <= rgh)
            return sum[k];
        int mid = (l[k] + r[k]) / 2;
        this->push_down(k);
        return this->cnt(2 * k, lft, mid) + this->cnt(2 * k + 1, mid + 1, rgh);
    }
};
Segment_Tree_Node nw;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> bd[i];
    nw.init();
    nw.build(1, 1, n);
    while (m--)
    {
        cin >> flag;
        if (flag == 1)
        {
            cin >> x >> y >> k;
            nw.add(1, x, y, k);
        }
        else if (flag == 2)
        {
            cin >> x >> y;
            cout << nw.cnt(1, x, y) << "\n";
        }
    }
    return 0;
}