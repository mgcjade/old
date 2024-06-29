#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout);
using namespace std;
typedef long long ll;

const int N = 1e6 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

int n;
int a[N];
int num[N];

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        num[a[i]] = i;
    }
    for (int i = 1; i < n; i++)
    {
        int x = num[i], y = num[0];
        swap(num[i], num[0]);
        swap(a[x], a[y]);
    }
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    return 0;
}