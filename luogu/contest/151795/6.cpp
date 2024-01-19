#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout);
using namespace std;
typedef long long ll;

int n, m, k;
char ch[105][105];

int main()
{
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < n; i++)
        scanf("%s", ch[i]);
    n *= k, m *= k;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            printf("%c", ch[i / k][j / k]);
        printf("\n");
    }
    return 0;
}