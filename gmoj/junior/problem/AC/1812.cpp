#include <bits/stdc++.h>
using namespace std;

int n;
int a[1005], mn[1005], wh[1005];
int tree[1005][1005];
int st1[1005], h1, st2[1005], h2;
int clr[1005];
string ans = "";
bool flag;

void dfs(int k, int color)
{
    clr[k] = color;
    for (int i = 1; i <= n; i++)
        if (i != k && tree[i][k])
        {
            if (clr[i] == 0)
                dfs(i, color * -1);
            else if (clr[i] != color * -1)
            {
                flag = 1;
                break;
            }
        }
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    mn[n] = a[n];
    wh[n] = n;
    for (int i = n - 1; i; i--)
        if (a[i] < mn[i + 1])
            mn[i] = a[i], wh[i] = i;
        else
            mn[i] = mn[i + 1], wh[i] = wh[i + 1];

    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j < n; j++)
            if (mn[j + 1] < a[i] && a[i] < a[j])
                tree[i][j] = tree[j][i] = 1;

    for (int i = 1; i <= n && !flag; i++)
        if (clr[i] == 0)
            dfs(i, 1);
    if (flag)
    {
        cout << 0;
        return 0;
    }
    int otp = 1;
    for (int i = 1; i <= n;)
    {
        while (clr[i] == 1 && (h1 <= 0 || st1[h1 - 1] != otp) && i <= n && (h1 < 1 || st1[h1 - 1] > a[i]))
        {
            st1[h1++] = a[i];
            ans += "a ";
            i++;
        }
        while (h1 > 0 && st1[h1 - 1] == otp)
        {
            h1--;
            otp++;
            ans += "b ";
            while (clr[i] == 1 && (h1 <= 0 || st1[h1 - 1] != otp) && i <= n && (h1 < 1 || st1[h1 - 1] > a[i]))
            {
                st1[h1++] = a[i];
                ans += "a ";
                i++;
            }
        }
        while (clr[i] != 1 && (h2 <= 0 || st2[h2 - 1] != otp) && i <= n && (h2 < 1 || st2[h2 - 1] > a[i]))
        {
            st2[h2++] = a[i];
            ans += "c ";
            i++;
            while (clr[i] == 1 && (h1 <= 0 || st1[h1 - 1] != otp) && i <= n && (h1 < 1 || st1[h1 - 1] > a[i]))
            {
                st1[h1++] = a[i];
                ans += "a ";
                i++;
            }
            while (h1 > 0 && st1[h1 - 1] == otp)
            {
                h1--;
                otp++;
                ans += "b ";
                while (clr[i] == 1 && (h1 <= 0 || st1[h1 - 1] != otp) && i <= n && (h1 < 1 || st1[h1 - 1] > a[i]))
                {
                    st1[h1++] = a[i];
                    ans += "a ";
                    i++;
                }
            }
        }
        while (h2 > 0 && st2[h2 - 1] == otp)
        {
            h2--;
            otp++;
            ans += "d ";
            while (clr[i] == 1 && (h1 <= 0 || st1[h1 - 1] != otp) && i <= n && (h1 < 1 || st1[h1 - 1] > a[i]))
            {
                st1[h1++] = a[i];
                ans += "a ";
                i++;
            }
            while (h1 > 0 && st1[h1 - 1] == otp)
            {
                h1--;
                otp++;
                ans += "b ";
                while (clr[i] == 1 && (h1 <= 0 || st1[h1 - 1] != otp) && i <= n && (h1 < 1 || st1[h1 - 1] > a[i]))
                {
                    st1[h1++] = a[i];
                    ans += "a ";
                    i++;
                }
            }
            while (clr[i] != 1 && (h2 <= 0 || st2[h2 - 1] != otp) && i <= n && (h2 < 1 || st2[h2 - 1] > a[i]))
            {

                st2[h2++] = a[i];
                ans += "c ";
                i++;
                while (clr[i] == 1 && (h1 <= 0 || st1[h1 - 1] != otp) && i <= n && (h1 < 1 || st1[h1 - 1] > a[i]))
                {
                    st1[h1++] = a[i];
                    ans += "a ";
                    i++;
                }
                while (h1 > 0 && st1[h1 - 1] == otp)
                {
                    h1--;
                    otp++;
                    ans += "b ";
                    while (clr[i] == 1 && (h1 <= 0 || st1[h1 - 1] != otp) && i <= n && (h1 < 1 || st1[h1 - 1] > a[i]))
                    {
                        st1[h1++] = a[i];
                        ans += "a ";
                        i++;
                    }
                }
            }
        }
    }
    cout << ans;

    return 0;
}

// P1155