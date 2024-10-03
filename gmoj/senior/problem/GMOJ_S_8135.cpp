#include <bits/stdc++.h>
#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
using namespace std;
typedef long long ll;

const int N = 1e6;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

ll n, a[1000005], ans = 0, s[1000005], s1[1000005], cnts1, cnts, ans1[1000005][4];
const ll Mod = 4294967296;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    ll n2 = n / 2, nw1 = n - 2, nw = n - 1;
    ans = (n - 1) * a[1] % Mod + a[n] * (n - 1) % Mod;
    for (int i = 2; i <= n2; i++)
    {
        nw += nw1;
        nw1 -= 2;
        ans += nw * a[i] % Mod;
        ans %= Mod;
        ans += nw * a[n - i + 1] % Mod;
        ans %= Mod;
    }
    if (n2 * 2 != n)
    {
        ans += a[n2 + 1] * (nw + nw1) % Mod;
        ans %= Mod;
    }

    s[++cnts] = 1;
    s1[++cnts1] = 1;
    ans1[1][0] = 0;
    ans1[1][1] = 0;
    for (ll i = 2; i <= n; i++)
    {
        while (cnts > 0 && a[s[cnts]] > a[i])
            cnts--;
        if (cnts != 0)
            ans1[i][0] = s[cnts];
        else
            ans1[i][0] = 0;
        while (cnts1 > 0 && a[s1[cnts1]] < a[i])
            cnts1--;
        if (cnts1 != 0)
            ans1[i][1] = s1[cnts1];
        else
            ans1[i][1] = 0;
        s[++cnts] = i;
        s1[++cnts1] = i;
    }
    cnts = cnts1 = 0;
    s[++cnts] = n;
    s1[++cnts1] = n;
    ans1[n][2] = n + 1;
    ans1[n][3] = n + 1;
    for (ll i = n - 1; i >= 1; i--)
    {

        while (cnts > 0 && a[s[cnts]] >= a[i])
            cnts--;
        if (cnts != 0)
            ans1[i][2] = s[cnts];
        else
            ans1[i][2] = n + 1;
        while (cnts1 > 0 && a[s1[cnts1]] <= a[i])
            cnts1--;
        if (cnts1 != 0)
            ans1[i][3] = s1[cnts1];
        else
            ans1[i][3] = n + 1;
        s[++cnts] = i;
        s1[++cnts1] = i;
    }
    ll mn1, mx1, mn2, mx2, cnt1, cnt2;
    for (ll i = 1; i <= n; i++)
    {
        mn1 = ans1[i][0] + 1;
        mx1 = ans1[i][1] + 1;
        mn2 = ans1[i][2] - 1;
        mx2 = ans1[i][3] - 1;
        cnt1 = (i - mn1) * (mn2 - i) % Mod;
        cnt2 = (i - mx1) * (mx2 - i) % Mod;
        ans = (ans + Mod - (i - mn1) * a[i] % Mod) % Mod;
        ans = (ans + Mod - (mn2 - i) * a[i] % Mod) % Mod;
        ans = (ans + Mod - (i - mx1) * a[i] % Mod) % Mod;
        ans = (ans + Mod - (mx2 - i) * a[i] % Mod) % Mod;
        ans = (ans + Mod - cnt2 * a[i] % Mod) % Mod;
        ans = (ans + Mod - cnt1 * a[i] % Mod) % Mod;
    }
    printf("%lld", ans);
}