#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout);
using namespace std;
typedef long long ll;

char ch[2005];
int ans;

int main()
{
    scanf("%s", ch);
    int len = strlen(ch);
    for (int i = 0; i + 13 <= len; i++)
    {
        if (ch[i] == 'G' && ch[i + 1] == 'e' && ch[i + 2] == 'n' && ch[i + 3] == 's' && ch[i + 4] == 'h' && ch[i + 5] == 'i' && ch[i + 6] == 'n')
            for (int j = i + 7; j + 6 <= len; j++)
                if (ch[j] == 'p' && ch[j + 1] == 'l' && ch[j + 2] == 'a' && ch[j + 3] == 'y' && ch[j + 4] == 'e' && ch[j + 5] == 'r')
                    ans++;
    }
    printf("%d", ans);
    return 0;
}