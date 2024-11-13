#include <stdio.h>
#include <windows.h>

int main()
{
    // alt key
    wint_t KEYCODE = 0x12;
    int delay;
    int cps;
    printf("How many clicks per seconds do you want?\n");
    printf("Input 0 to click as fast as possible.\n");
    scanf("%d", &cps);
    if (cps <= 0)
    {
        delay = 0;
    }
    else
    {
        delay = 1000 / cps;
    }

    // clear console
    system("cls");

    // wait for alt key to be pressed
    printf("Click alt\n");
    while (1)
    {
        // sleep 5 milliseconds to not let your pc burn as hot as the sun
        Sleep(5);
        while (GetAsyncKeyState(KEYCODE))
        {
            // one click
            mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
            mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
            // wait the desired amount so the clicks per second are reached
            Sleep(delay);
        }
    }

    return 0;
}
