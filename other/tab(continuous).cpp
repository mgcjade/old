#include <windows.h>
#include <cstdio>

int main()
{
    int __time = 0;
    while (1)
    {
        if (GetAsyncKeyState(255) & 0x8000)
        {
            __time = 0;
            keybd_event(VK_TAB, 0, 0, 0);
            while (GetAsyncKeyState(255) & 0x8000)
            {
                __time++;
                if (__time >= 1000000)
                {
                    keybd_event(VK_TAB, 0, 2, 0);
                    printf("Tab downed! Timed spend %d\n", __time);
                    keybd_event(VK_TAB, 0, 0, 0);
                    __time -= 120000;
                }
            }
            keybd_event(VK_TAB, 0, 2, 0);
            printf("Tab downed! Timed spend %d\n", __time);
        }
        Sleep(1);
    }
}
