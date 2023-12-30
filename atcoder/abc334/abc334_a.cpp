#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
using namespace std;
typedef long long ll;

int a, b;
int main()
{
    cin >> a >> b;
    if (a > b)
        printf("Bat");
    else
        printf("Glove");
    return 0;
}