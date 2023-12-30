#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
using namespace std;

bool prime(int n)
{
    if (n < 2)
        return 0;
    int a = sqrt(n);
    for (int i = 2; i <= a; i++)
        if (n % i == 0)
            return 0;
    return 1;
}

char s[105];
int len;
int cnt[26];

int main()
{
    // fre(ans);
    scanf("%s", s);
    len = strlen(s);
    for (int i = 0; i < len; i++)
        cnt[s[i] - 'a']++;
    int mx = 0, mn = len;
    for (int i = 0; i < 26; i++)
        if (cnt[i])
            mx = max(mx, cnt[i]), mn = min(mn, cnt[i]);
    if (prime(mx - mn))
        printf("Lucky Word\n%d", mx - mn);
    else
        printf("No Answer\n0");
    return 0;
}