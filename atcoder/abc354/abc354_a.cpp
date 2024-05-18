#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int i = 1;
    int ans = 0;
    while (n >= 0)
    {
        n = n - i;
        i = i * 2;
        ans++;
    }
    cout << ans;
}