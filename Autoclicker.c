#include <stdio.h>
#include <windows.h>

int main()
{
    wint_t KEYCODE = 0x12;
    int delay;
    int cps;
    printf("How many clicks per seconds do you want?\n");
    scanf("%d", &cps);
    if (cps <= 0)
    {
        delay = 0;
    }
    else
    {
        delay = 1000 / cps;
    }

    system("cls");

    printf("Click alt\n");
    while (1)
    {
        Sleep(5);
        while (GetAsyncKeyState(KEYCODE))
        {
            mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
            mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
            Sleep(delay);
        }
    }

    return 0;
}