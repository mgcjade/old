#include <bits/stdc++.h>
using namespace std;
#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define reb(i, a, b) for (int i = (a); i >= (b); i--)
#define ref(i, a, b) for (int i = (a); i < (b); i++)
using namespace std;
// typedef long long ll;
#define int long long

const int N = 1e6;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int MAXLOG = 24;

class _01trie
{
private:
    struct Node
    {
        int ch[2];
        int siz, cnt;
    } T[1 << MAXLOG];
    int cnt;

public:
    void update(int x, int offset)
    {
        int now = 0;
        reb(i, MAXLOG - 1, 0)
        {
            bool now_bit = (x >> i) & 1;
            if (T[now].ch[now_bit] == 0)
                T[now].ch[now_bit] = ++cnt;
            now = T[now].ch[now_bit];
            T[now].siz += offset;
        }
        T[now].cnt += offset;
    }
    int get_rank(int x)
    {
        int now = 0, ans = 0;
        reb(i, MAXLOG - 1, 0)
        {
            bool now_bit = (x >> i) & 1;
            if (now_bit == 1)
                ans += T[T[now].ch[0]].siz;
            now = T[now].ch[now_bit];
            if (now == 0)
                break;
        }
        return ans;
    }
    int get_kth(int k)
    {
        int now = 0, ans = 0;
        reb(i, MAXLOG - 1, 0)
        {
            int tmp = T[T[now].ch[0]].siz;
            if (k <= tmp)
                now = T[now].ch[0];
            else
                k -= tmp, now = T[now].ch[1], ans |= (1 << i);
            if (now == 0)
                break;
        }
        return ans;
    }
    int pre(int x) { return get_kth(get_rank(x)); }
    int nxt(int x) { return get_kth(get_rank(x + 1) + 1); }
    void clear() { T[1].ch[0] = 0, T[1].ch[1] = 0, cnt = 1; }
} t;

int n;
int p[N], a[N];

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    rep(i, 1, n)
            cin >>
        p[i],
        t.update(i, 1);
    reb(i, n, 1)
        a[t.get_kth(p[i])] = i,
        t.update(t.get_kth(p[i]), -1);
    rep(i, 1, n)
            cout
        << a[i] << " ";
    return 0;
}