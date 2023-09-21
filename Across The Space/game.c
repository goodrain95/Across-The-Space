#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <time.h>

#define UP 72
#define DOWN 80
#define RIGHT 77
#define LEFT 75
#define ENTER 13

void Print_Maze(FILE* fp) {
	int y = 0, c;
	gotoxy(0, y);
	fseek(fp, 0, SEEK_SET);
	while ((c = fgetc(fp)) != EOF) {
		if (c == 48) { SetColor(15);  printf(" "); }
		if (c == 49) { SetColor(255);  printf("#"); }
		if (c == '\n') { y++; gotoxy(0, y); }
		if (c == '5') { SetColor(12); printf("Ω"); }
		if (c == '3') { SetColor(13); printf("★"); }
		if (c == '4') { SetColor(11);  printf("+"); }
	}
	SetColor(10);
	gotoxy(0, 5); printf("->");
}
int Whe_Obstacle(FILE* fp, int x, int y) {
	int position, character;
	position = 119 * (y - 2) + 4 + x;
	fseek(fp, position, SEEK_SET);
	character = fgetc(fp);
	if (character == '0') return 0;
	else if (character == '3') return 3;
	else if (character == '4') return 4;
	else if (character == '5') return 5;
	else return 1;
}


void Maze1() {
	Reset_Screen();
	FILE* fp = fopen("C:\\Users\\goodr\\source\\repos\\Across The Space\\Maze_Level_1.txt", "r");

	int dir, x = 3, y = 5;
	int w;
	// 나: U 9, 외계인: Ω 2, 무기: ★ 3, 물약: = 4 
	Print_Maze(fp);
	gotoxy(x, y); SetColor(14);  printf("U");
	
	while (1) {
		if (_kbhit()) {
			dir = _getch();
			if (dir == UP) {
				w = Whe_Obstacle(fp, x, y - 1);

				if (w == 1) continue;
				else if (y <= 3) continue;
				gotoxy(x, y); printf(" ");
				gotoxy(x, --y); printf("U");
				if (w == 3) Weapon();
				else if (w == 4) Potion();
				else if (w == 5) Fight_screen();
				
			}
			else if (dir == DOWN) {
				w = Whe_Obstacle(fp, x, y + 1);

				if (w == 1) continue;
				else if (y >= 29) continue;
				gotoxy(x, y); printf(" ");
				gotoxy(x, ++y); printf("U");
				if (w == 3) Weapon();
				else if (w == 4) Potion();
				else if (w == 5) Fight_screen();

			}
			else if (dir == LEFT) {
				w = Whe_Obstacle(fp, x - 1, y);

				if (w == 1) continue;
				if (x <= 3) continue;
				gotoxy(x, y); printf(" ");
				gotoxy(--x, y); printf("U");
				if (w == 3) Weapon();
				else if (w == 4) Potion();
				else if (w == 5) Fight_screen();
			}
			else if (dir == RIGHT) {
				w = Whe_Obstacle(fp, x + 1, y);

				if (w == 1) continue;
				//if (x >= 119) continue;
				gotoxy(x, y); printf(" ");
				gotoxy(++x, y); printf("U");

				if (w == 3) Weapon();
				else if (w == 4) Potion();
				else if (w == 5) Fight_screen();
			}
			if (x == 116 && y == 6) return;
		}
	}
	fclose(fp);
}
void GameStart() {
	Maze1();
	//Maze2();
	//Maze3();
}