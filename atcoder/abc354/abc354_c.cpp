#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

int n;
struct node
{
    int a, b;
    int num;
} a[N], b[N];
int pre[N], nxt[N];
bool cmp(node x, node y) { return x.a < y.a; }
bool _cmp(node x, node y) { return x.b > y.b; }
map<int, int> mp;
bool used[N];
int ans;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].a >> a[i].b;
        a[i].num = i;
        b[i] = a[i];
    }
    sort(a, a + n, cmp);
    sort(b, b + n, _cmp);
    for (int i = 0; i < n; i++)
        pre[i] = i - 1, nxt[i] = i + 1;
    for (int i = 0; i < n; i++)
        mp[a[i].num] = i;
    int i = 0, j = 0;
    used[a[i].num] = 1;
    while (i < n && j < n)
    {
        while (a[i].num != b[j].num && j < n)
        {
            int Tp = mp[b[j].num];
            nxt[pre[Tp]] = nxt[Tp];
            pre[nxt[Tp]] = pre[Tp];
            used[a[Tp].num] = 1;
            j++;
        }
        i = nxt[i];
    }
    for (int i = 0; i < n; i++)
        ans += used[i];
    cout << ans << "\n";
    for (int i = 0; i < n; i++)
        if (used[i])
            cout << i + 1 << " ";
    return 0;
}