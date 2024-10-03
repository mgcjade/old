#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
using namespace std;
typedef long long ll;

const int N = 1e6;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

struct node
{
    int val, num;
} a[N], ans[N];
int n, m;
int cnt;
int l, r;

bool cmp(node x, node y)
{
    if (x.val == y.val)
        return x.num < y.num;
    return x.val < y.val;
}

void read()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i].val, a[i].num = i;
    sort(a + 1, a + 1 + n, cmp);
    cnt = 1;
    l = 1, r = n;
    a[n + 1].val = 0;
    ans[0] = {0, 0}, ans[n + 1] = {0, 0};
}

void solve(int i)
{
    if (cnt == 1)
    {
        if (ans[l - 1].val < ans[r + 1].val)
            ans[l++] = a[i - 1];
        else if (ans[l - 1].val > ans[r + 1].val)
            ans[r--] = a[i - 1];
        else
        {
            if (a[i - 1].num < a[i].num)
                ans[l++] = a[i - 1];
            else
                ans[r--] = a[i - 1];
        }
    }
    else
    {
        ans[l++] = a[i - cnt], ans[r--] = a[i - 1];
        for (int q = 1, j = i - cnt + 1; q < cnt - 1; j++, q++)
        {
            if (i < n && a[i + 1].val != a[i].val && a[i + 1].num < a[j].num)
            {
                for (int k = i - 2; k >= j; k--)
                    ans[r--] = a[k];
                break;
            }
            else if (a[i].num < a[j].num)
            {
                for (int k = i - 2; k >= j; k--)
                    ans[r--] = a[k];
                break;
            }
            else
                ans[l++] = a[j];
        }
    }
}

void write()
{
    for (int i = 1; i <= n; i++)
        cout << ans[i].num << " ";
    cout << '\n';
}

int T;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> T;
    while (T--)
    {
        read();
        for (int i = 2; i <= n + 1; i++)
        {
            if (a[i].val != a[i - 1].val)
                solve(i), cnt = 0;
            cnt++;
        }
        write();
    }
    return 0;
}