#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
using namespace std;
typedef long long ll;

const int N = 1e6 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

int n;
struct node
{
    int lson, rson;
    int step, size;
    int fa;
};
node tr[N];
vector<int> st[N];
int cnt;
int ans;
void made(int k, int fa)
{
    tr[k].fa = fa;
    tr[k].step = tr[fa].step + 1;
    cnt = max(cnt, tr[k].step);
    st[tr[k].step].push_back(k);
    if (tr[k].lson)
        made(tr[k].lson, k);
    if (tr[k].rson)
        made(tr[k].rson, k);
    tr[k].size = tr[tr[k].lson].size + tr[tr[k].rson].size + 1;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    ans = n - 2;
    for (int i = 1; i <= n; i++)
        cin >> tr[i].lson >> tr[i].rson;
    made(1, 1);
    int sum = 0;
    for (int i = 1; i <= cnt; i++)
    {
        int sz = st[i].size();
        ans = min(ans, (n - sum - sz) + (1 << (i - 1)) - 1 - sum);
        if (n < (n - sum - sz) + (1 << (i - 1)) - 1 - sum)
            break;
        sum += sz;
    }
    cout << ans;
    return 0;
}