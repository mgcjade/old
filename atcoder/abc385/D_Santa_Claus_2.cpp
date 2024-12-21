#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define reb(i, a, b) for (int i = a; i >= b; i--)
#define ref(i, a, b) for (int i = a; i < b; i++)
using namespace std;
typedef long long ll;

const int N = 1e6;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

int n, m;
ll x, y;
set<pair<ll, ll>> house;
set<pair<ll, ll>> House;

ll a, b;
char ch;
int c;
int ans;

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    cin >> x >> y;
    rep(i, 1, n)
    {
        cin >> a >> b;
        house.insert({a, b});
        House.insert({b, a});
    }
    pair<ll, ll> t;
    rep(i, 1, m)
    {
        cin >> ch >> c;
        if (ch == 'U')
        {
            auto it = house.lower_bound({x, y});
            y += c;
            while (it != house.end() && it->first == x && it->second <= y)
            {
                // cout << it->first << " " << it->second << "\n";
                ans++;
                House.erase({it->second, it->first});
                t = *it;
                house.erase(it);
                it = house.lower_bound({t.first, t.second + 1});
            }
        }
        else if (ch == 'D')
        {
            auto it = house.lower_bound({x, y - c});
            while (it != house.end() && it->first == x && it->second <= y)
            {
                // cout << it->first << " " << it->second << "\n";
                ans++;
                House.erase({it->second, it->first});
                t = *it;
                house.erase(it);
                it = house.lower_bound({t.first, t.second + 1});
            }
            y -= c;
        }
        else if (ch == 'L')
        {
            auto it = House.lower_bound({y, x - c});
            while (it != House.end() && it->first == y && it->second <= x)
            {
                // cout << it->second << " " << it->first << "\n";
                ans++;
                house.erase({it->second, it->first});
                t = *it;
                House.erase(it);
                it = House.lower_bound({t.first, t.second + 1});
            }
            x -= c;
        }
        else
        {
            auto it = House.lower_bound({y, x});
            x += c;
            while (it != House.end() && it->first == y && it->second <= x)
            {
                // cout << it->second << " " << it->first << "\n";
                ans++;
                house.erase({it->second, it->first});
                t = *it;
                House.erase(it);
                it = House.lower_bound({t.first, t.second + 1});
            }
        }
    }
    cout << x << " " << y << " " << ans;
    return 0;
}