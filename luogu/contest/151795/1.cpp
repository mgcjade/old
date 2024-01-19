#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout);
using namespace std;
typedef long long ll;

int a, b, c;
int ansa, ansb;

int main()
{
    scanf("%d%d%d", &a, &b, &c);
    ansa = a + b + c;
    if (a > b + c && a - b - c < ansa - ansb)
        ansa = a, ansb = b + c;
    if (b > a + c && b - a - c < ansa - ansb)
        ansa = b, ansb = a + c;
    if (c > b + a && c - b - a < ansa - ansb)
        ansa = c, ansb = b + a;
    if (a < b + c && b + c - a < ansa - ansb)
        ansb = a, ansa = b + c;
    if (b < a + c && a + c - b < ansa - ansb)
        ansb = b, ansa = a + c;
    if (c < b + a && a + b - c < ansa - ansb)
        ansb = c, ansa = b + a;
    printf("%d %d", ansa, ansb);
    return 0;
}