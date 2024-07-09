#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
using namespace std;
typedef long long ll;

const int N = 1e6;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

struct Matrix
{
    ll a[2][2];
    Matrix operator*(const Matrix &b) const
    {
        Matrix res;
        res.a[0][0] = 0, res.a[0][1] = 0, res.a[1][0] = 0, res.a[1][1] = 0;
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
                for (int k = 0; k < 2; k++)
                    res.a[i][k] = (res.a[i][k] + a[i][j] * b.a[j][k]) % MOD;
        return res;
    }
};
Matrix power(Matrix base, ll exp)
{
    Matrix res;
    res.a[0][0] = 1, res.a[0][1] = 1, res.a[1][0] = 1, res.a[1][1] = 0;
    while (exp)
    {
        if (exp & 1)
            res = base * res;
        base = base * base;
        exp >>= 1;
    }
    return res;
}
ll n;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    while (cin >> n)
    {
        if (n & 1)
        {
            cout << 0 << '\n';
            continue;
        }
        Matrix base;
        base.a[0][0] = 1, base.a[0][1] = 1, base.a[1][0] = 1, base.a[1][1] = 0;
        base = power(base, (n / 2) - 1);
        cout << base.a[0][0] * base.a[0][0] % MOD << '\n';
    }
    return 0;
}