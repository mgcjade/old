#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
using namespace std;
typedef long long ll;

const int N = 1e4 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

int n;
int ans;
struct node
{
    int x, y;
    int c;
    int num;
} a[N];
bool cmp(node x, node y) { return x.c < y.c; }
void qSort(int h, int r)
{
    int i = h, j = r;
    node mid = a[(h + r) >> 1];
    while (i <= j)
    {
        while (cmp(a[i], mid))
            i++;
        while (cmp(mid, a[j]))
            j--;
        if (i <= j)
        {
            swap(a[i], a[j]);
            i++, j--;
        }
    }
    if (h < j)
        qSort(h, j);
    if (i < r)
        qSort(i, r);
}
void Qsort(int h, int r)
{
    int i = h, j = r;
    node mid = a[(h + r) >> 1];
    while (i <= j)
    {
        while (a[i].num < mid.num)
            i++;
        while (mid.num < a[j].num)
            j--;
        if (i <= j)
        {
            swap(a[i], a[j]);
            i++, j--;
        }
    }
    if (h < j)
        Qsort(h, j);
    if (i < r)
        Qsort(i, r);
}

void dg(int k)
{
    if (k > n)
    {
        qSort(1, n);
        int mn = INF;
        for (int i = 1; i < n; i++)
            mn = min(mn, a[i + 1].c - a[i].c);
        ans = max(ans, mn);
        Qsort(1, n);
        return;
    }
    a[k].c = a[k].x;
    dg(k + 1);
    a[k].c = a[k].y;
    dg(k + 1);
}

int main()
{
    fre(ans);
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].x >> a[i].y;
        a[i].num = i;
    }
    dg(1);
    cout << ans;
    return 0;
}