#include <bits/stdc++.h>
using namespace std;
const int N = 101, M = 1e5 + 10;
const int P = 1e9 + 7;
int a[N];
int n, m;
int ps[N]; // 2的次方
int maxn[N];

long long ans1;
long long ans2; //
long long fac[M], cc[M], psw[M];

int tg[N];
int v[N];
int c[N];
int q;
int L;
int num[N], k; // 100以内的质数

long long power(int x, int y) // 快速幂
{
    int z = y;
    long long ans = 1, sum = x;
    while (z)
    {
        if (z & 1)
            ans = ans * sum % P;
        sum = sum * sum % P;
        z >>= 1;
    }
    return ans;
}
void cg(int x)
{
    for (int i = 1; i <= k; i++)
    {
        int cnt = 0, yy = x;
        while (yy % num[i] == 0)
            yy = yy / num[i], cnt++;
        maxn[i] = max(maxn[i], cnt);
    }
    return;
}
bool check(int x) // 检查是否为质数
{
    for (int i = 2; i * i <= x; i++)
    {
        if (x % i == 0)
            return false;
    }
    return true;
}
void getp() // 预处理
{
    // ans2 = power(n, m);
    // ans2 = power(ans2, P - 2);
    ps[1] = 1;
    for (int i = 2; i <= 14; i++)
        ps[i] = ps[i - 1] * 2;
    for (int i = 2; i <= 97; i++)
    {
        if (check(i))
            num[++k] = i;
    }
    return;
}
int get(int z) // 找环的长度
{
    int x = z;
    x = a[x];
    for (int i = 1;; i++)
    {
        if (x == z)
            return i;
        x = a[x];
    }
    return 0;
}
int main()
{
    scanf("%d%d", &n, &m);
    getp();
    for (int i = 1; i <= m; i++)
        scanf("%d", &a[i]);
    for (int i = 1; i <= m; i++)
        tg[get(i)]++;
    for (int i = 1; i <= m; i++)
    {
        if (!tg[i])
            continue;
        q++;
        v[q] = i;     // 环q的长度为i
        c[q] = tg[i]; // 个数
    }
    L = ps[q + 1] - 1;
    for (int S = 1; S <= L; S++)
    {
        int ss = 0;
        fac[S] = 1;
        memset(maxn, 0, sizeof(maxn));
        for (int j = 1; j <= q; j++)
        {
            if (!(S & ps[j]))
                continue;
            cc[S]++;
            ss = ss + c[j];
            cg(v[j]);
        }
        for (int j = 1; j <= k; j++) // 求方案数
        {
            fac[S] = fac[S] * power(num[j], maxn[j]) % P;
        }
        psw[S] = ss * power(m, P - 2) % P;
        psw[S] = power(psw[S], n);
    }
    for (int S = 1; S <= L; S++)
    {
        long long sum = 0;
        for (int T = 1; T <= S; T++)
        {
            if (S - T != (S ^ T))
                continue;
            if ((cc[S] - cc[T]) % 2 == 0)
                sum = (sum + psw[T]) % P;
            else
                sum = (sum - psw[T] + P) % P;
        }
        ans1 = (ans1 + sum * fac[S] % P) % P;
    }
    printf("%lld", ans1);
    return 0;
}