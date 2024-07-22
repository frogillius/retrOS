#include <windows.h>
#include <stdio.h>

void changeColor() {
    static int colorIndex = 0;
    const int colors[] = {
        0x0F, // Black background, White text
        0x1F, // Blue background, White text
        0x2F, // Green background, White text
        0x3F, // Aqua background, White text
        0x4F, // Red background, White text
        0x5F, // Purple background, White text
        0x6F, // Yellow background, White text
        0x7F  // White background, Black text
    };
    const int numColors = sizeof(colors) / sizeof(colors[0]);

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hConsole == INVALID_HANDLE_VALUE) return;

    SetConsoleTextAttribute(hConsole, colors[colorIndex]);
    colorIndex = (colorIndex + 1) % numColors;
}

void cmd_gay() {
    changeColor();
    printf("Colors rotated!\n");
}
