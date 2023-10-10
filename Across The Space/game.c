#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include <process.h>

#define UP 72
#define DOWN 80
#define RIGHT 77
#define LEFT 75
#define ENTER 13

extern int hidden;

char Print[30][120];
FILE* cur_fp;

CRITICAL_SECTION critical_section;
/*
typedef struct aliens{
	int x;
	int y;
	int direct; // 0 는 좌우, 1은 위아래
}ALIENS;
ALIENS maze_lev1[2];
*/
void Print_Maze(FILE* fp) {
	int a = 0;
	int b = 0;
	int i, j;
	int y = 0, c;
	char p;

	gotoxy(0, y);
	fseek(fp, 0, SEEK_SET);

	while ((c = fgetc(fp)) != EOF) {
		//printf("%c", c);
		Print[a][b] = c;
		b++;
		if (c == '\n') { b = 0; a++; }
	}

	for (i = 0; i < 30; i++) {
		for (j = 0; j < 120; j++) {
			p = Print[i][j];
			
			if (p == 48) { SetColor(15);  printf(" "); }
			if (p == 49) { SetColor(255);  printf("#"); }
			if (p == '\n') { y++; gotoxy(0, y); }
			if (p == '2') { SetColor(13); printf("U"); }
			if (p == '5') { SetColor(12); printf("Ω"); }
			if (p == '3') { SetColor(10); printf("★"); }
			if (p == '4') { SetColor(11);  printf("+"); }
			if (p == '8') { SetColor(8); printf("?"); }
		}
	}
	SetColor(13);
	gotoxy(0, 3); printf("->");
	gotoxy(117, 28); printf("->");
}
/*int Whe_Obstacle(FILE* fp, int x, int y) {
	int position, character;
	position = 119 * (y - 2) + 4 + x;
	fseek(fp, position, SEEK_SET);
	character = fgetc(fp);
	if (character == '0') return 0;
	else if (character == '3') return 3;
	else if (character == '4') return 4;
	else if (character == '5') return 5;
	else return 1;
}*/

int Whe_Obstacle(int x, int y) {
	char character;
	character = Print[y][x];
	if (character == '0') return 0;
	else if (character == '3') return 3;
	else if (character == '4') return 4;
	else if (character == '5') return 5;
	else if (character == '8') return 8;
	else if (character == '1') return 1;
	//else if (character == '9') return 9;
	//else return 2;
}

void Move(int x, int y) {
	int dir, w;
	int res;

	while (1) {
		if (_kbhit()) {
			EnterCriticalSection(&critical_section); SetColor(14);
			dir = _getch();
			if (dir == UP) {
				w = Whe_Obstacle(x, y - 1);

				if (w == 1) continue;
				else if (y <= 3) continue;
				gotoxy(x, y); printf(" ");
				gotoxy(x, --y); printf("U");

				//Print[y][x] = '0';
				//Print[--y][x] = '2';

				switch (w) {
				case 3:
					Weapon();
					break;
				case 4:
					Potion();
					break;
				case 5:
					Fight_screen();
					break;
				case 8:
					Hidden_piece();
					break;
				
				}
			}
			else if (dir == DOWN) {
				w = Whe_Obstacle(x, y + 1);

				if (w == 1) continue;
				else if (y >= 29) continue;

				gotoxy(x, y); printf(" ");
				gotoxy(x, ++y); printf("U");
				//Print[y][x] = '0';
				//Print[++y][x] = '2';

				switch (w) {
				case 3:
					Weapon();
					break;
				case 4:
					Potion();
					break;
				case 5:
					Fight_screen();
					break;
				case 8:
					Hidden_piece();
					break;
				}

			}
			else if (dir == LEFT) {
				w = Whe_Obstacle(x - 1, y);

				if (w == 1) continue;
				if (x <= 3) continue;

				gotoxy(x, y); printf(" ");
				gotoxy(--x, y); printf("U");
				//Print[y][x] = '0';
				//Print[y][--x] = '2';

				switch (w) {
				case 3:
					Weapon();
					break;
				case 4:
					Potion();
					break;
				case 5:
					Fight_screen();
					break;
				case 8:
					Hidden_piece();
					break;
				}
			}
			else if (dir == RIGHT) {
				w = Whe_Obstacle(x + 1, y);

				if (w == 1) continue;
				//if (x >= 119) continue;
				gotoxy(x, y); printf(" ");
				gotoxy(++x, y); printf("U");
				//Print[y][x] = '0';
				//Print[y][++x] = '2';

				switch (w) {
				case 3:
					Weapon();
					break;
				case 4:
					Potion();
					break;
				case 5:
					Fight_screen();
					break;
				case 8:
					Hidden_piece();
					break;
				}
			}
			SetColor(255);
			LeaveCriticalSection(&critical_section);
		}
		
	}
	
}

unsigned int __stdcall EnemyMove (void* data) {
	int* parameters = (int*)data; //void*를 int*로 형 변환해줘야 함.
	int x = parameters[0]; 
	int y = parameters[1]; 
	int direct = parameters[2];
	//gotoxy(0, 0); printf("%d %d", parameters[0], parameters[1]);
	int a = 1;

	if (direct == 0) {
		while (1) {
			/*EnterCriticalSection(&g_cs);
			
			gotoxy(x, y); printf("Ω"); Print[y][x] = '5'; Sleep(100);
			gotoxy(x, y); printf(" "); Print[y][x] = '0';

			LeaveCriticalSection(&g_cs);
			x += a;

			if (Print[y][x] == '1') { a *= -1; x += 2 * a;}
			*/
			EnterCriticalSection(&critical_section);
			Print[y][x] = '0';
			if (Print[y][x + a] == '1') a *= -1;
			x += a;
			Print[y][x] = '5';
			//if (Print[y][x + a] == '1') a *= -1;
			LeaveCriticalSection(&critical_section);
			
			Sleep(200);
		}
	}
	if (direct == 1) {
		while (1) {
			/*EnterCriticalSection(&g_cs);

			gotoxy(x, y); printf("Ω"); Print[y][x] = '5'; Sleep(100);
			gotoxy(x, y); printf(" "); Print[y][x] = '0';
			
			LeaveCriticalSection(&g_cs);
			y += a;

			if (Print[y][x] == '1') { a *= -1; y += 2 * a;}
			*/
			EnterCriticalSection(&critical_section);
			Print[y][x] = '0';
			if (Print[y + a][x] == '1') a *= -1;
			y += a;
			Print[y][x] = '5';
			
			LeaveCriticalSection(&critical_section);
			//if (Print[y + a][x]) a *= -1;
			Sleep(200);
		}
	}
	return NULL;
}

unsigned int __stdcall PrintEnemy(void* arg) {
	int a, b;
	int i, j, y = 0;
	char p;
	int count = 0;
	while(1) {
		EnterCriticalSection(&critical_section);
		
		SetColor(15);
		gotoxy(0, 0);
		//Print_Maze(cur_fp);
		for (i = 0; i < 30; i++) {
			for (j = 0; j < 120; j++) {
				p = Print[i][j];
				
				if (p == 48) { SetColor(15);  printf(" "); }
				if (p == 49) { SetColor(255);  printf("#"); }
				if (p == '\n') { printf("\n"); }
				if (p == '2') { SetColor(13); printf("U"); }
				if (p == '5') { SetColor(12); printf("Ω"); }
				if (p == '3') { SetColor(10); printf("★"); }
				if (p == '4') { SetColor(11);  printf("+"); }
				if (p == '8') { SetColor(8); printf("?"); }
				
			}
			
		}
		//SetColor(11);  gotoxy(0, 0); printf("%d", count); printf("%d", y);
		LeaveCriticalSection(&critical_section);
		count++;
		Sleep(100);
	}
	return NULL;
}

void Maze1() {
	Reset_Screen();
	FILE* fp1 = fopen("C:\\Users\\goodr\\source\\repos\\Across The Space\\Maze_Level_1.txt", "r");
	cur_fp = fp1;

	int parameters[18][3];
	int i;
	HANDLE threadHandle[3];

	Print_Maze(cur_fp);
	
	InitializeCriticalSection(&critical_section);
	
	/*maze_lev1[0].x = 9;
	maze_lev1[0].y = 12;
	maze_lev1[0].direct = 0;

	maze_lev1[1].x = 23;
	maze_lev1[1].y = 3;
	maze_lev1[1].direct = 1;*/

	parameters[0][0] = 9; parameters[0][1] = 12; parameters[0][2] = 0;
	parameters[1][0] = 23; parameters[1][1] = 3; parameters[1][2] = 1;
	parameters[2][0] = 20; parameters[2][1] = 23; parameters[2][2] = 0;
	parameters[3][0] = 14; parameters[3][1] = 27; parameters[3][2] = 0;
	parameters[4][0] = 45; parameters[4][1] = 3; parameters[4][2] = 1;
	parameters[5][0] = 46; parameters[5][1] = 14; parameters[5][2] = 1;
	parameters[6][0] = 58; parameters[6][1] = 6; parameters[6][2] = 1;	
	parameters[7][0] = 45; parameters[7][1] = 25; parameters[7][2] = 0;
	parameters[8][0] = 69; parameters[8][1] = 26; parameters[8][2] = 0;
	parameters[9][0] = 65; parameters[9][1] = 5; parameters[9][2] = 1;
	parameters[10][0] = 89; parameters[10][1] = 6; parameters[10][2] = 0;
	parameters[11][0] = 77; parameters[11][1] = 18; parameters[11][2] = 0;
	parameters[12][0] = 101; parameters[12][1] = 8; parameters[12][2] = 1;
	parameters[13][0] = 102; parameters[13][1] = 8; parameters[13][2] = 0;
	parameters[14][0] = 106; parameters[14][1] = 14; parameters[14][2] = 0;
	parameters[15][0] = 96; parameters[15][1] = 26; parameters[15][2] = 0;
	parameters[16][0] = 112; parameters[16][1] = 21; parameters[16][2] = 1;

	
	gotoxy(3, 3); SetColor(14); printf("U");


	for (i = 0; i < 17; i++) {
		threadHandle[i] = (HANDLE)_beginthreadex(NULL, 0, EnemyMove, parameters[i], 0, NULL);
	}
	threadHandle[i] = (HANDLE)_beginthreadex(NULL, 0, PrintEnemy, NULL, 0, NULL);
	
	Move(3, 3);

	WaitForMultipleObjects(18, threadHandle, TRUE, INFINITE);

	for (i = 0; i < 18; i++) {
		CloseHandle(threadHandle[i]);
	}
	
	DeleteCriticalSection(&critical_section);

	fclose(cur_fp);
}

/*void Maze2() {
	Reset_Screen();
	FILE* fp2 = fopen("C:\\Users\\goodr\\OneDrive\\문서\\Maze_Level_2.txt", "r");
	int i;
	HANDLE threadHandle[17];
	int parameters[17][3];

	parameters[0][0] = 4; parameters[0][1] = 17; parameters[0][2] = 0;
	parameters[1][0] = 17; parameters[1][1] = 11; parameters[1][2] = 1;
	parameters[2][0] = 42; parameters[2][1] = 9; parameters[2][2] = 0;
	parameters[3][0] = 32; parameters[3][1] = 13; parameters[3][2] = 1;
	parameters[4][0] = 42; parameters[4][1] = 28; parameters[4][2] = 1;
	parameters[5][0] = 52; parameters[5][1] = 28; parameters[5][2] = 0;
	parameters[6][0] = 66; parameters[6][1] = 3; parameters[6][2] = 1;
	parameters[7][0] = 53; parameters[7][1] = 11; parameters[7][2] = 0;
	parameters[8][0] = 68; parameters[8][1] = 5; parameters[8][2] = 1;
	parameters[9][0] = 85; parameters[9][1] = 13; parameters[9][2] = 0;
	parameters[10][0] = 71; parameters[10][1] = 19; parameters[10][2] = 1;
	parameters[11][0] = 82; parameters[11][1] = 19; parameters[11][2] = 1;
	parameters[12][0] = 83; parameters[12][1] = 8; parameters[12][2] = 1;
	parameters[13][0] = 100; parameters[13][1] = 5; parameters[13][2] = 1;
	parameters[14][0] = 102; parameters[14][1] = 11; parameters[14][2] = 0;
	parameters[15][0] = 110; parameters[15][1] = 19; parameters[15][2] = 1;
	parameters[16][0] = 97; parameters[16][1] = 27; parameters[16][2] = 0;

	Print_Maze(fp2);
	gotoxy(3, 3); SetColor(14);  printf("U");

	//InitializeCriticalSection(&g_cs);

	for (i = 0; i < 17; i++) {
		threadHandle[i] = (HANDLE)_beginthreadex(NULL, 0, EnemyMove, parameters[i], 0, NULL);

	}

	Move(3, 3);

	WaitForMultipleObjects(17, threadHandle, TRUE, INFINITE);

	for (i = 0; i < 17; i++) {
		CloseHandle(threadHandle[i]);
	}
	//DeleteCriticalSection(&g_cs);
	
	fclose(fp2);
}*/

void Maze3() {
	Reset_Screen();
	FILE* fp3 = fopen("C:\\Users\\goodr\\OneDrive\\문서\\Maze_Level_3.txt", "r");
	

	Print_Maze(fp3);
	gotoxy(3, 3); SetColor(14);  printf("U");

	Move(3, 3);

	fclose(fp3);
}
void GameStart() {
	Maze1();
	//Maze2();
	//Maze3();
	//Ending(hidden);
	printf("end");
}