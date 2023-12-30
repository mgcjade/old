#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
using namespace std;
typedef long long ll;

inline void read(int &s)
{
    s = 0;
    char ch = getchar(), last = ' ';
    while (ch < '0' || ch > '9')
        last = ch, ch = getchar();
    while (ch >= '0' && ch <= '9')
        s = (s << 1) + (s << 3) + (ch ^ 48), ch = getchar();
    s = last == '-' ? -s : s;
}

int n;
int a[200005];

void Sort(int h, int r)
{
    int i = h, j = r, mid = (h + r) >> 1;
    if (a[h] <= a[mid] && a[h] <= a[r])
        mid = min(a[mid], a[r]);
    else if (a[mid] <= a[h] && a[mid] <= a[r])
        mid = min(a[h], a[r]);
    else
        mid = min(a[h], a[mid]);
    while (i <= j)
    {
        while (a[i] < mid)
            i++;
        while (mid < a[j])
            j--;
        if (i <= j)
        {
            swap(a[i], a[j]);
            i++, j--;
        }
    }
    if (h < j)
        Sort(h, j);
    if (i < r)
        Sort(i, r);
}

int main()
{
    fre(ans);
    read(n);
    for (int i = 1; i <= n; i++)
        read(a[i]);
    Sort(1, n);
    int i = 1;
    while (i <= n)
    {
        int cnt = 1;
        while (i <= n && a[i] == a[i + 1])
            i++, cnt++;
        printf("%d %d\n", a[i], cnt);
        i++;
    }
    return 0;
}