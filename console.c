#include <windows.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>

#include "varient.c"
#include "ColorType.c"

CONSOLE_SCREEN_BUFFER_INFO csbi;

int getKeyPress();

int mapKeyPress(int key);

void clearConsole();

int getConsoleHeight();

int getConsoleWidth();

void hideCursor();

void showCursor();

void moveTo(int x, int y);

void textColor(enum ColorType color);

void printWithColor(enum ColorType color, char* text);

// 구현
int getKeyPress() {
    int key = _getch();
    return key;
}

int mapKeyPress(int key) {
    switch (key) {
        case 72: return KEY_UP;
        case 80: return KEY_DOWN;
        case 75: return KEY_LEFT;
        case 77: return KEY_RIGHT;
        case 13: return KEY_ENTER;
        case 89: return KEY_ESC;
        default: return -1;
    }
}

void clearConsole() {
    system("cls");
}

int getConsoleHeight() {
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    return csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
}

int getConsoleWidth() {
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    return csbi.srWindow.Right - csbi.srWindow.Left + 1;
}

void hideCursor() {
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
    cursorInfo.bVisible = FALSE;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}

void showCursor() {
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
    cursorInfo.bVisible = TRUE;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}

void moveTo(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}


void textColor(enum ColorType color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void printWithColor(enum ColorType color, char* text) {
    textColor(color);
    printf("%s", text);
    textColor(WHITE);
}
