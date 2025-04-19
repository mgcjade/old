#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define reb(i, a, b) for (int i = (a); i >= (b); i--)
#define ref(i, a, b) for (int i = (a); i < (b); i++)
using namespace std;
typedef long long ll;
// #define int long long

const int N = 1e6;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

signed main()
{
    queue<int> q;
    int n;
    cin >> n;
    while (n--)
    {
        int x;
        cin >> x;
        if (x == 1)
        {
            cin >> x;
            q.push(x);
        }
        else
        {
            cout << q.front() << endl;
            q.pop();
        }
    }
    return 0;
}