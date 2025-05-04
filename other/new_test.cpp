#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define new_file(x) freopen(#x ".in", "w", stdout)
using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    new_file(jiemi);
    mt19937 myrand(time(NULL));
    rep(i, 1, 200000)
    {
        cout << char('a' + myrand() % 26);
        cout << char('a' + myrand() % 26);
        cout << char('a' + myrand() % 26);
        cout << char('a' + myrand() % 26);
        cout << char('a' + myrand() % 26);
        cout << ' ';
    }
    cout << "$\n";
    rep(i, 1, 10000)
    {
        cout << char('a' + myrand() % 26);
        cout << char('a' + myrand() % 26);
        cout << char('a' + myrand() % 26);
        cout << char('a' + myrand() % 26);
        cout << char('a' + myrand() % 26);
        cout << ' ';
    }
    cout << "$\n";
    return 0;
}