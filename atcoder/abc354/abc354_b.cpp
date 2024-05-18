#include <bits/stdc++.h>
using namespace std;

int n;
struct node
{
    string str;
    int v;
} a[105];
long long sum;
bool cmp(node a, node b) { return a.str < b.str; }

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i].str >> a[i].v;
    sort(a, a + n, cmp);
    for (int i = 0; i < n; i++)
        sum += a[i].v;
    sum = sum % n;
    cout << a[sum].str << endl;
}