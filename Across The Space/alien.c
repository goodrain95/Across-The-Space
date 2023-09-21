#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

int damage = 1;

int target_c;
int alien_hp;
int my_hp = 100;

int weapon_cnt = 0;
int potion_cnt = 0;
int fight_cnt = 0;

void Target_char() {
	srand(time(NULL));
	int target = rand() % 4 + 1;
	
	SetColor(15);
	switch (target) {
	case 1: 
		target_c = 97; 
		gotoxy(12, 9); printf(" ________");
		gotoxy(12, 10); printf("|  ___   |");
		gotoxy(12, 11); printf("|　|__|  |");
		gotoxy(12, 12); printf("|　 __   |");
		gotoxy(12, 13); printf("|__| |___|");
		break;
	case 2: 
		target_c = 115; 
		gotoxy(12, 9); printf(" ________");
		gotoxy(12, 10); printf("|  ______|");
		gotoxy(12, 11); printf("|  |_____");
		gotoxy(12, 12); printf("|______  |");
		gotoxy(12, 13); printf("|________|");
		break;
	case 3: 
		target_c = 100; 
		gotoxy(12, 9); printf(" _______");
		gotoxy(12, 10); printf("|  ___  \\");
		gotoxy(12, 11); printf("|  |  |  |");
		gotoxy(12, 12); printf("|  |__|  |");
		gotoxy(12, 13); printf("|_______/");
		break;
	case 4: 
		target_c = 119; 
		gotoxy(12, 9); printf(" _     _");
		gotoxy(12, 10); printf("| | _ | |");
		gotoxy(12, 11); printf("| || || |");
		gotoxy(12, 12); printf("|   _   |");
		gotoxy(12, 13); printf("|__| |__|");
		break;
	}
}

void Suc_or_Fail(int input) {
	if (input == target_c) {
		gotoxy(13, 5); printf("success!"); Sleep(500);
		gotoxy(13, 5); printf("        ");
		alien_hp -= damage;

	}

	else {
		gotoxy(15, 5); printf("fail!"); Sleep(500);
		gotoxy(15, 5); printf("     ");
	}

	Clean_Screen(10, 5, 12, 9);
	if (alien_hp <= 0) {
		alien_hp = 0;
		goback();
	}
}

void Fight() {
	int a;
	int alien_hp_max;
	fight_cnt++;
	switch (fight_cnt) {
	case 1:
	case 2:
	case 3: alien_hp_max = 10; break;
	
	case 4:
	case 5:
	case 6: alien_hp_max = 25; break;

	case 7:
	case 8:
	case 9: alien_hp_max = 45; break;

	case 10:
	case 11:
	case 12: alien_hp_max = 70; break;
	}
	
	while(1) {
		Target_char();

		a = getch();
		
		Suc_or_Fail(a);
		
	}
}

void Fight_screen() {
	Reset_Screen();

	SetColor(15);

	BackGround();

	BOX(60, 20, 30, 2);
	BOX(20, 10, 7, 7);

	Clean_Screen(17, 3, 52, 26);
	Clean_Screen(5, 3, 58, 23);
	BOX(5, 3, 58, 23);
	BOX(5, 3, 58, 26);
	BOX(5, 3, 52, 26);
	BOX(5, 3, 64, 26); 

	SetColor(10);
	gotoxy(60, 24); printf("W");
	gotoxy(60, 27); printf("S");
	gotoxy(54, 27); printf("A");
	gotoxy(66, 27); printf("D");

	Fight();
}

Weapon() {
	gotoxy(45, 0); SetColor(11); printf("무기 획득!! 공격력이 00만큼 증가하였다!");
	SetColor(15); Sleep(2000);
	gotoxy(45, 0);  printf("                                       ");
}

Potion() {
	gotoxy(45, 0); SetColor(11); printf("물약 획득!! hp가 00만큼 증가하였다!");
	SetColor(15); Sleep(2000);
	gotoxy(45, 0);  printf("                                   ");
}