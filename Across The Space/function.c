#include <stdio.h>
#include <windows.h>
#include <conio.h>

void gotoxy(int X, int Y) { // Ŀ�� ��ġ ����
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), (COORD) { X, Y });
}


void SetColor(int color) { // ����Ʈ ���� �� ����
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void BOX(int WIDTH, int HIGHT, int X, int Y) { //������, ���� ��ġ�� �Է��ϸ� �� ũ���� �׸�ڽ��� ����.
    int i;
    gotoxy(X, Y);
    for (i = X; i < WIDTH + X; i++) {
        printf("%c", 1);
    }
    for (i = Y; i < HIGHT + Y - 1; i++) {
        gotoxy(X, i);
        printf("%c", 1);
        gotoxy(X + WIDTH - 1, i);
        printf("%c", 1);
    }
    gotoxy(X, HIGHT + Y - 1);
    for (i = X; i < WIDTH + X; i++) {
        printf("%c", 1);
    }
}

/*void BOX(int WIDTH, int HIGHT, int X, int Y) { //������, ���� ��ġ�� �Է��ϸ� �� ũ���� �׸�ڽ��� ����.
    int i;
    gotoxy(X, Y);
    for (i = X; i < WIDTH + X; i++) {
        printf("-");
    }
    for (i = Y; i < HIGHT + Y - 1; i++) {
        gotoxy(X, i);
        printf("|");
        gotoxy(X + WIDTH - 1, i);
        printf("|");
    }
    gotoxy(X, HIGHT + Y - 1);
    for (i = X; i < WIDTH + X; i++) {
        printf("-");
    }
}*/

void Cursor(BOOL n) { // Ŀ���� ���̰� ���� �Ⱥ��̰� ���� ����
    CONSOLE_CURSOR_INFO c;
    GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &c);
    c.dwSize = 1;
    c.bVisible = n;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &c);
}

void Reset_Screen() { // ��ũ���� �����ϰ� ����.
    int i;
    for (i = 0; i < 30; i++) {
        gotoxy(0, i); printf("                                                                                                                        ");
    }
}

void Clean_Screen(int WIDTH, int HIGHT, int X, int Y) {
    int i, j;
    for (i = 0; i < HIGHT; i++) {
        gotoxy(X, Y + i);
        for (j = 0; j < WIDTH; j++) {
            printf(" ");
        }
    }
}