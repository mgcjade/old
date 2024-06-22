#include <bits/stdc++.h>
#define new_file(x) freopen(#x ",in", "w", stdout)
using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    new_file(qinggong);
    mt19937 myrand(time(NULL));
    cout << 500 << ' ' << 100 << ' ' << 9999999 << '\n';
    for (int i = 1; i <= 100; i++)
        cout << myrand() % 500 + 1 << ' ' << 10000000 << '\n';
    cout << 50000;
    for (int i = 1; i <= 500000; i++)
        cout << myrand() % 500 + 1 << ' ' << myrand() % 100 + 1 << '\n';
    return 0;
}