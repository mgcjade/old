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

int k;
string a, b;
int lena, lenb;
int flag;

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> k;
    cin >> a;
    lena = a.size();
    cin >> b;
    lenb = b.size();
    if (lena > lenb)
        swap(lena, lenb), swap(a, b);
    if (lena == lenb)
    {
        ref(i, 0, lena)
        {
            if (a[i] != b[i])
                flag++;
        }
        if (flag <= k)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    else
    {
        if (lenb - lena > k)
        {
            cout << "No\n";
            return 0;
        }
        ref(i, 0, lena)
        {
            if (a[i] != b[i + flag])
                flag++;
            if (flag > k)
            {
                cout << "No\n";
                return 0;
            }
        }
        cout << "Yes\n";
    }
    return 0;
}