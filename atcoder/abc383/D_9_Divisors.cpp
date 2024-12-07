#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 3e7 + 10;

int n, m, a[N], ans;
int bb[N], cc[N], cnt;

signed main()
{
    cin >> n;
    for (int i = 2; i <= N - 10; i++)
    {
        bb[i] = bb[i - 1];
        if (!a[i])
            bb[i]++, cc[++cnt] = i;
        for (int j = 1; j <= cnt && i * cc[j] <= N - 10; j++)
        {
            a[i * cc[j]] = 1;
            if (i % cc[j] == 0)
                break;
        }
    }
    for (int i = 2;; i++)
    {
        if (a[i])
            continue;
        if ((__int128)i * i * i * i * i * i * i * i > n)
            break;
        ans++;
    }
    for (int i = 1; i <= cnt; i++)
    {
        int kj = i;
        i = cc[i];
        if (i * i > n)
            break;
        int j = sqrt(n / (i * i));
        if (j < i)
            break;
        ans += bb[j] - bb[i];
        i = kj;
    }
    cout << ans << '\n';
    return 0;
}