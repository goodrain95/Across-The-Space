#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

int damage = 1;

int target_c;
int alien_hp = 100;
int my_hp = 100;

int weapon_cnt = 0;
int potion_cnt = 0;
int fight_cnt = 0;

int target_c;
int hidden = 0;

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

Print_Option() {
	gotoxy(97, 9); printf("My HP: %d", my_hp);
	gotoxy(97, 10); printf("Alien HP: %d", alien_hp);
	gotoxy(97, 11); printf("My Damage: %d", damage);

}
void Suc_or_Fail(char input) {
	if (input == target_c) {
		gotoxy(13, 5); printf("success!"); Sleep(500);
		gotoxy(13, 5); printf("        ");
		alien_hp -= damage;
		Print_Option();

	}

	else {
		gotoxy(15, 5); printf("fail!"); Sleep(500);
		gotoxy(15, 5); printf("     ");
		//printf("[%d] [%d]", input, target_c);
	}

	Clean_Screen(10, 5, 12, 9);
	/*if (alien_hp <= 0) {
		//alien_hp = 0;
		goback();
	}*/
}

void Fight() {
	char a;
	int alien_hp_max;
	/*fight_cnt++;
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
	}*/
	
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
	Clean_Screen(20, 10, 7, 7);
	Clean_Screen(20, 10, 93, 7);

	BOX(60, 20, 30, 2);
	BOX(20, 10, 7, 7);
	BOX(20, 10, 93, 7);

	Print_Option();
	
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

	Print_Option();
	Fight();
}

void Weapon() { // 스레드 처리 해야 됨
	gotoxy(45, 0); SetColor(11); printf("무기 획득!! 공격력이 00만큼 증가하였다!");
	SetColor(14); Sleep(2000);
	gotoxy(45, 0);  printf("                                       ");
	damage++;
}

void Potion() {
	gotoxy(45, 0); SetColor(11); printf("물약 획득!! hp가 00만큼 증가하였다!");
	SetColor(14); Sleep(2000);
	gotoxy(45, 0);  printf("                                   ");
	my_hp += 10;
	if (my_hp >= 100) my_hp = 100;
	
}

void Hidden_piece() {
	gotoxy(55, 0); SetColor(11); printf("?? 획득!!");
	hidden = 1;
}

void Ending(int hidden) {
	Reset_Screen();
	int b;

	gotoxy(50, 1); SetColor(11); printf("GAME ENDING");

	gotoxy(1, 4); SetColor(15);

	if (hidden == 1) {
		printf("지구에 다시 돌아오는데 성공하였다!!! \n"
			"하지만 지구는 이미 시간이 훨씬 지난 뒤였다. 엄청난 과학적 진보를 이루었지만, 과학자들은 아아주 멀리에 있는 우주에도 순식간에 갈 수 있는 방법을 찾느라 매우 애먹고 있었다.\n"
			"근데 주인공이 가져온 히든피스가 알고보니 이를 가능하게 해주는 웜홀을 인공적으로 만드는 데 필요한 엄청난 원석이어던 것..!!\n"
			"주인공은 엄청나게 유명해지고 웜홀 게이트는 주인공의 이름을 따서 지어졌다.\n"
			"Happy Ending!!");
	}
	else {
		printf("지구에 다시 돌아오는데 성공하였다"
			"하지만 지구는 멸망 바로 직전이다.. 주인공이 출발했을 때ㅗ보다 시간이 훨씬 많이 지났고, 곳곳이 불타고 있으며 사람의 흔적이 없었다.\n"
			"가족들의 생사 역시 알 수 없자 주인공은 그토록 힘들게 도착한 지구가 이런 모습인 것에 비관하고 투신한다..\n"
			"Bad Ending.");
	}

	while (1) {
		if (_kbhit()) {
			b = _getch();
			if (b == 13) {
				break;
			}
		}
	}
	return;
}