#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define reb(i, a, b) for (int i = (a); i >= (b); --i)
#define ref(i, a, b) for (int i = (a); i < (b); ++i)
using namespace std;

int n, m, l;
int ans;
int v[50001];
vector<int> e[50001];

int s[50001][55][6], w[50001][55][6];
set<pair<int, int>> st;

void solve()
{
    memset(s, 0, sizeof(s));
    memset(w, 0, sizeof(w));
    rep(i, 1, n)
    {
        e[i].clear();
        cin >> v[i];
        s[i][0][1] = v[i];
        w[i][0][1] = i;
    }
    int u, v;
    ref(i, 1, n)
    {
        cin >> u >> v;
        e[u].push_back(v), e[v].push_back(u);
    }
    ref(j, 0, m)
    {
        rep(i, 1, n)
        {
            st.clear();
            rep(k, 1, l) st.insert({s[i][j][k], w[i][j][k]});
            for (auto x : e[i])
                rep(k, 1, l)
                {
                    if (s[x][j][k] == 0)
                        break;
                    st.insert({s[x][j][k], w[x][j][k]});
                    if (st.size() > l)
                        st.erase(st.begin());
                }
            reb(k, st.size(), 1) s[i][j + 1][k] = st.begin()->first, w[i][j + 1][k] = st.begin()->second, st.erase(st.begin());
        }
    }
    ans = 0;
    int sum;
    rep(i, 1, n)
    {
        sum = 0;
        rep(k, 1, l) sum += s[i][m][k];
        ans = max(ans, sum);
    }
    cout << ans << '\n';
    // rep(j, 0, m)
    // {
    //     cerr << j << '\n';
    //     rep(i, 1, n) rep(k, 1, l) cerr << s[i][j][k] << " \n"[k == l];
    //     cerr << '\n';
    // }
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    while (cin >> n >> m >> l)
        solve();
    return 0;
}
