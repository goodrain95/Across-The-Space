#include <stdio.h>
#include <windows.h>
#include <conio.h>

void gotoxy(int X, int Y) {
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), (COORD) { X, Y });
}


void SetColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void BOX(int WIDTH, int HIGHT, int X, int Y) {
    SetColor(10);
    int i;
    gotoxy(X, Y);
    for (i = X; i < WIDTH + X; i++) {
        printf("*");
    }
    for (i = Y; i < HIGHT + Y - 1; i++) {
        gotoxy(X, i);
        printf("*");
        gotoxy(X + WIDTH - 1, i);
        printf("*");
    }
    gotoxy(X, HIGHT + Y - 1);
    for (i = X; i < WIDTH + X; i++) {
        printf("*");
    }
}

void Cursor(BOOL n) {
    CONSOLE_CURSOR_INFO c;
    GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &c);
    c.dwSize = 1;
    c.bVisible = n;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &c);
}