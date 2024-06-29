// This is a simple 2048 game.

#include <iostream>
#include <vector>
#include <Windows.h>
#include <string>
#include <random>
#include <ctime>
#include <conio.h>
using namespace std;

unsigned long score = 0;
int stop = 0;
string s0 = "    ";
string s2 = " 2  ";
string s4 = " 4  ";
string s8 = " 8  ";
string s16 = " 16 ";
string s32 = " 32 ";
string s64 = " 64 ";
string s128 = "128 ";
string s256 = "256 ";
string s512 = "512 ";
string s1024 = "1024";
string s2048 = "2048";
string s4096 = "4096";
string s8192 = "8192";

vector<vector<string>> p = {{s0, s0, s0, s0}, {s0, s2, s0, s0}, {s0, s0, s0, s0}, {s0, s0, s0, s0}};

int equal_int(string str)
{
    if (str == s2)
        return 4;
    else if (str == s4)
        return 8;
    else if (str == s8)
        return 16;
    else if (str == s16)
        return 32;
    else if (str == s32)
        return 64;
    else if (str == s64)
        return 128;
    else if (str == s128)
        return 256;
    else if (str == s256)
        return 512;
    else if (str == s512)
        return 1024;
    else if (str == s1024)
        return 2048;
    else if (str == s2048)
        return 4096;
    else if (str == s4096)
        return 8192;
    else
        return 0;
}

string equal_str(string str)
{
    int num = equal_int(str);
    switch (num)
    {
    case 4:
        return s4;
    case 8:
        return s8;
    case 16:
        return s16;
    case 32:
        return s32;
    case 64:
        return s64;
    case 128:
        return s128;
    case 256:
        return s256;
    case 512:
        return s512;
    case 1024:
        return s1024;
    case 2048:
        return s2048;
    case 4096:
        return s4096;
    case 8192:
        return s8192;
    default:
        return "    ";
    }
}

void change(int n)
{
    switch (n)
    {
    case 3: // left
        for (int i = 0; i != 4; i++)
        {
            if (p[i][0] == s0)
            {
                p[i][0] = p[i][1];
                p[i][1] = p[i][2];
                p[i][2] = p[i][3];
                p[i][3] = s0;
            }
            if (p[i][0] == s0)
            {
                p[i][0] = p[i][1];
                p[i][1] = p[i][2];
                p[i][2] = s0;
            }
            if (p[i][0] == s0)
            {
                p[i][0] = p[i][1];
                p[i][1] = s0;
            }
            if (p[i][1] == s0)
            {
                p[i][1] = p[i][2];
                p[i][2] = p[i][3];
                p[i][3] = s0;
            }
            if (p[i][1] == s0)
            {
                p[i][1] = p[i][2];
                p[i][2] = s0;
            }
            if (p[i][2] == s0)
            {
                p[i][2] = p[i][3];
                p[i][3] = s0;
            }
        }
        for (int i = 0; i != 4; i++)
        {
            if (p[i][0] == p[i][1] && p[i][0] != s0)
            {
                score += equal_int(p[i][0]);
                p[i][0] = equal_str(p[i][0]);
                p[i][1] = p[i][2];
                p[i][2] = p[i][3];
                p[i][3] = s0;
                if (p[i][1] == p[i][2] && p[i][1] != s0)
                {
                    score += equal_int(p[i][1]);
                    p[i][1] = equal_str(p[i][1]);
                    p[i][2] = p[i][3];
                }
            }
            else if (p[i][1] == p[i][2] && p[i][1] != s0)
            {
                score += equal_int(p[i][1]);
                p[i][1] = equal_str(p[i][1]);
                p[i][2] = p[i][3];
                p[i][3] = s0;
            }
            else if (p[i][2] == p[i][3] && p[i][2] != s0)
            {
                score += equal_int(p[i][2]);
                p[i][2] = equal_str(p[i][2]);
                p[i][3] = s0;
            }
        }
        break;
    case 4: // right
        for (int i = 0; i != 4; i++)
        {
            if (p[i][3] == s0)
            {
                p[i][3] = p[i][2];
                p[i][2] = p[i][1];
                p[i][1] = p[i][0];
                p[i][0] = s0;
            }
            if (p[i][3] == s0)
            {
                p[i][3] = p[i][2];
                p[i][2] = p[i][1];
                p[i][1] = s0;
            }
            if (p[i][3] == s0)
            {
                p[i][3] = p[i][2];
                p[i][2] = s0;
            }
            if (p[i][2] == s0)
            {
                p[i][2] = p[i][1];
                p[i][1] = p[i][0];
                p[i][0] = s0;
            }
            if (p[i][2] == s0)
            {
                p[i][2] = p[i][1];
                p[i][1] = s0;
            }
            if (p[i][1] == s0)
            {
                p[i][1] = p[i][0];
                p[i][0] = s0;
            }
        }
        for (int i = 0; i != 4; i++)
        {
            if (p[i][3] == p[i][2] && p[i][3] != s0)
            {
                score += equal_int(p[i][3]);
                p[i][3] = equal_str(p[i][3]);
                p[i][2] = p[i][1];
                p[i][1] = p[i][0];
                p[i][0] = s0;
                if (p[i][2] == p[i][1] && p[i][2] != s0)
                {
                    score += equal_int(p[i][2]);
                    p[i][2] = equal_str(p[i][2]);
                    p[i][1] = p[i][0];
                }
            }
            else if (p[i][2] == p[i][1] && p[i][2] != s0)
            {
                score += equal_int(p[i][2]);
                p[i][2] = equal_str(p[i][2]);
                p[i][1] = p[i][0];
                p[i][0] = s0;
            }
            else if (p[i][1] == p[i][0] && p[i][1] != s0)
            {
                score += equal_int(p[i][1]);
                p[i][1] = equal_str(p[i][1]);
                p[i][0] = s0;
            }
        }
        break;
    case 1: // up
        for (int i = 0; i != 4; i++)
        {
            if (p[0][i] == s0)
            {
                p[0][i] = p[1][i];
                p[1][i] = p[2][i];
                p[2][i] = p[3][i];
                p[3][i] = s0;
            }
            if (p[0][i] == s0)
            {
                p[0][i] = p[1][i];
                p[1][i] = p[2][i];
                p[2][i] = s0;
            }
            if (p[0][i] == s0)
            {
                p[0][i] = p[1][i];
                p[1][i] = s0;
            }
            if (p[1][i] == s0)
            {
                p[1][i] = p[2][i];
                p[2][i] = p[3][i];
                p[3][i] = s0;
            }
            if (p[1][i] == s0)
            {
                p[1][i] = p[2][i];
                p[2][i] = s0;
            }
            if (p[2][i] == s0)
            {
                p[2][i] = p[3][i];
                p[3][i] = s0;
            }
        }
        for (int i = 0; i != 4; i++)
        {
            if (p[0][i] == p[1][i] && p[0][i] != s0)
            {
                score += equal_int(p[0][i]);
                p[0][i] = equal_str(p[0][i]);
                p[1][i] = p[2][i];
                p[2][i] = p[3][i];
                p[3][i] = s0;
                if (p[1][i] == p[2][i] && p[1][i] != s0)
                {
                    score += equal_int(p[1][i]);
                    p[1][i] = equal_str(p[1][i]);
                    p[2][i] = p[3][i];
                }
            }
            else if (p[1][i] == p[2][i] && p[1][i] != s0)
            {
                score += equal_int(p[1][i]);
                p[1][i] = equal_str(p[1][i]);
                p[2][i] = p[3][i];
                p[3][i] = s0;
            }
            else if (p[2][i] == p[3][i] && p[2][i] != s0)
            {
                score += equal_int(p[2][i]);
                p[2][i] = equal_str(p[2][i]);
                p[3][i] = s0;
            }
        }
        break;
    case 2: // down
        for (int i = 0; i != 4; i++)
        {
            if (p[3][i] == s0)
            {
                p[3][i] = p[2][i];
                p[2][i] = p[1][i];
                p[1][i] = p[0][i];
                p[0][i] = s0;
            }
            if (p[3][i] == s0)
            {
                p[3][i] = p[2][i];
                p[2][i] = p[1][i];
                p[1][i] = s0;
            }
            if (p[3][i] == s0)
            {
                p[3][i] = p[2][i];
                p[2][i] = s0;
            }
            if (p[2][i] == s0)
            {
                p[2][i] = p[1][i];
                p[1][i] = p[0][i];
                p[0][i] = s0;
            }
            if (p[2][i] == s0)
            {
                p[2][i] = p[1][i];
                p[1][i] = s0;
            }
            if (p[1][i] == s0)
            {
                p[1][i] = p[0][i];
                p[0][i] = s0;
            }
        }
        for (int i = 0; i != 4; i++)
        {
            if (p[3][i] == p[2][i] && p[3][i] != s0)
            {
                score += equal_int(p[3][i]);
                p[3][i] = equal_str(p[3][i]);
                p[2][i] = p[1][i];
                p[1][i] = p[0][i];
                p[0][i] = s0;
                if (p[2][i] == p[1][i] && p[2][i] != s0)
                {
                    score += equal_int(p[2][i]);
                    p[2][i] = equal_str(p[2][i]);
                    p[1][i] = p[0][i];
                }
            }
            else if (p[2][i] == p[1][i] && p[2][i] != s0)
            {
                score += equal_int(p[2][i]);
                p[2][i] = equal_str(p[2][i]);
                p[1][i] = p[0][i];
                p[0][i] = s0;
            }
            else if (p[1][i] == p[0][i] && p[1][i] != s0)
            {
                score += equal_int(p[1][i]);
                p[1][i] = equal_str(p[1][i]);
                p[0][i] = s0;
            }
        }
        break;
    default:
        break;
    }
}

void input()
{
    char c2 = _getch();
    switch (c2)
    {
    case 72: // up
        change(1);
        break;
    case 80: // down
        change(2);
        break;
    case 75: // left
        change(3);
        break;
    case 77: // right
        change(4);
        break;
    default:
        break;
    }
}

void random_n(vector<vector<string>> q, unsigned n)
{
    vector<unsigned> xx, yy;
    char c = 'A';
    for (int i = 0; i != 4; i++)
    {
        for (int j = 0; j != 4; j++)
            if (q[i][j] == s0)
            {
                q[i][j] = "";
                (q[i][j]).push_back(c);
                xx.push_back(i);
                yy.push_back(j);
                ++c; // move to next character
            }
    }
    if (c == 'A')
        stop = 1; // indicate the end of the game
    else
    {
        srand((unsigned)time(NULL));
        int ran = rand() % (c - 'A'); // generate a random number
        string random_number = (n % 7 == 6) ? s4 : s2;
        p[xx[ran]][yy[ran]] = random_number;
    }
}

void print()
{
    std::cout << "+----+----+----+----+" << endl;
    for (int i = 0; i != 4; i++)
    {
        for (int j = 0; j != 4; j++)
            std::cout << "|" << p[i][j];
        std::cout << "|\n+----+----+----+----+" << endl;
    }
}

int main()
{
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cci;
    GetConsoleCursorInfo(hOut, &cci);
    cci.bVisible = FALSE;
    SetConsoleCursorInfo(hOut, &cci);
    // The five lines above are used to hide the Console Cursor.
    std::cout << "This is a simple 2048 game.\nProgrammer：Teddy van Jerry" << endl;
    std::cout << "\nYou can use ↑,↓,←,→ to control." << endl;
    std::cout << "\nNow you have 3 seconds to get ready. After that, we will begin.\n";
    for (int i = 3; i != 0; i--)
    {
        std::cout << i;
        Sleep(1000); // wait for a second;
        std::cout << " ";
    }
    std::cout << "Go!\n";
    long time_start = clock(); // the starting point
    unsigned cnt = 0;
    print();
    while (stop == 0) // when it's unfinshed
    {
        input();
        random_n(p, cnt);
        print();
        std::cout << "Your current score is " << score << "." << endl;
        std::cout << "\n";
        ++cnt;
    }
    long total_time = clock() - time_start;
    int min = total_time / 60000;
    int second = (total_time % 60000) / 1000;
    string zero = (second < 10) ? "0" : "";
    std::cout << "The game is over." << endl;
    std::cout << "Your final score is " << score << "." << endl;
    std::cout << "The total time is " << min << "'" << zero << second << "\"." << endl;
    std::cout << "\nALL RIGHTS RESERVED (c) 2020 Teddy van Jerry" << endl;
    char anything;
    std::cin >> anything;
    return 0;
}