#include <windows.h>
#include <cstdio>
#include <ctime>

int main()
{
	int __time = 0;
	while (1)
	{
		if (GetAsyncKeyState(255) & 0x8000)
		{
			__time = 0;
			keybd_event(VK_LWIN, 0, 0, 0);
			while (GetAsyncKeyState(255) & 0x8000)
			{
				__time++;
			}
			keybd_event(VK_LWIN, 0, 2, 0);
			if (__time < 800 * CLOCKS_PER_SEC)
			{
				keybd_event(VK_LCONTROL, 0, 0, 0);
				keybd_event(VK_ESCAPE, 0, 0, 0);
				keybd_event(VK_ESCAPE, 0, 2, 0);
				keybd_event(VK_LCONTROL, 0, 2, 0);
			}
			printf("Windows downed! Timed spend %d\n", __time);
		}
		Sleep(1);
	}
}