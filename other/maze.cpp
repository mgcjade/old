// use wasd to move
// go to the last line (i.e. to make x == N - 1) to win, touch the wall to restart
// e to show the map
#include <bits/stdc++.h>
#include <conio.h>
using namespace std;

const int N = 15; // let me larger
const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};

bool mp[N + 1][N + 1];

void dfs(int x, int y)
{
    mp[x][y] = 0;
    int t = 2;
    while (t--)
    {
        int d = rand() % 4;
        int nx = x + dx[d], ny = y + dy[d];
        int nnx = nx + dx[d], nny = ny + dy[d];
        if (nnx >= 0 && nny < N && nny >= 0 && nny < N && mp[nnx][nny])
        {
            dfs(nx, ny);
        }
    }
}

void gen()
{
    while (1)
    {
        bool flag = 1;
        for (int i = 0; i <= N; i++)
        {
            for (int j = 0; j <= N; j++)
            {
                mp[i][j] = 1;
            }
        }
        dfs(0, 0);
        for (int j = 0; j < N && flag; j++)
        {
            flag &= mp[N - 1][j];
        }
        if (!flag)
        {
            break;
        }
    }
}

void display(int x, int y)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (i == x && j == y)
            {
                cout << 2;
            }
            else
            {
                cout << mp[i][j];
            }
        }
        cout << '\n';
    }
}

signed main()
{
    srand(time(0));
    gen();

    int x = 0, y = 0, show = 0;
    char ch = ' ';
    while (1)
    {
        if (x || y)
        {
            cout << x << ' ' << y << ' ' << ch << '\n';
        }
        else
        {
            cout << x << ' ' << y << '\n';
        }
        if (show)
        {
            display(x, y);
        }
        ch = getch();
        if (ch == 'e')
        {
            show = 1 - show;
            if (!show)
            {
                system("cls");
            }
        }
        else if (ch == 3 || ch == 27 || ch == 17 || ch == 'q')
        {
            display(x, y);
            getch();
            exit(0);
        }
        else if (ch == 'w')
        {
            x--;
        }
        else if (ch == 's')
        {
            x++;
        }
        else if (ch == 'd')
        {
            y++;
        }
        else if (ch == 'a')
        {
            y--;
        }
        if (x < 0 || x >= N || y < 0 || y >= N || mp[x][y])
        {
            cout << "-1\n";
            x = 0, y = 0;
        }
        else if (x == N - 1)
        {
            cout << "114514\n";
            display(x, y);
            getch();
            exit(0);
        }
    }

    return 0;
}
