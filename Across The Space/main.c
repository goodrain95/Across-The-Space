#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
//#include "function.c"

void StartScreen();
void Menu();
void BackGround();
void Story();
void Manual();


/*void hello(int a) {
    while (1) {
        printf("Hello! %d", a);
        Sleep(1000);
    }
}*/


void main() {
    system("mode con cols=120 lines=30");
    Cursor(0);
    //CreateThread(NULL, 0, hello, 100, NULL, 0);
    StartScreen();
    //gotoxy(47, 14); SetColor(11);
    printf("Thankyou for Playing!!!!!!!");
    return 0;
}

void BackGround() {
    gotoxy(1, 1); printf("°           ☆ 　       　★　      .        *                       ●           ¸  　　　★ ");
    gotoxy(1, 2); printf("                                                        ☆　               .                            .");
    gotoxy(1, 3); printf("	                                                                                         ");
    gotoxy(1, 4); printf("     *                                                                 :.           :                           ○ ");
    gotoxy(1, 5); printf("             *         　                  .　                                                        ● ¸       ");
    gotoxy(1, 6); printf("     .                 　                             　                                                       *　");
    gotoxy(1, 7); printf("                                            　                                                     ");
    gotoxy(1, 8); printf(" ○               　　       　  　　　         *                ★         °                                 .　　");
    gotoxy(1, 9); printf("        .  ★　      .        *      ●                                         　★ 　     °           ");
    gotoxy(1, 10); printf("                   　　　                                                                                          ☆");
    gotoxy(1, 11); printf(" ★            ★              °                                                    *                 .　");
    gotoxy(1, 12); printf("                      °          ★                                                           ");
    gotoxy(1, 13); printf("       　                     　　    　                                                    ○             *");
    gotoxy(1, 14); printf("　 　                 .   ☆                            .           *  　　　     °    ☆ 　          .             ●");
    gotoxy(1, 15); printf("     ★                                       ˚ ˚                              *                 .　 　    　 °     .");
    gotoxy(1, 16); printf("         °　                                                                                                      ★");
    gotoxy(1, 17); printf("                                              　　       　                           °                   ");
    gotoxy(1, 18); printf("                          　                 　　　                                                       ");
    gotoxy(1, 19); printf("       °  .                                   　　★　                     　                  　             °☆");
    gotoxy(1, 20); printf("  *                                          　　　                 ★     　                  　          ");
    gotoxy(1, 21); printf("     ★                                         ★                      ☆   　                  　                    *");
    gotoxy(1, 22); printf("                                                                          　 　       ★ 　    　 　       *       .  ");
    gotoxy(1, 23); printf("                                                                                          ★　                 ●   　");
    gotoxy(1, 24); printf("　.            *                             ●　                ★ 　                     :                        ☆");
    gotoxy(1, 25); printf("    ☆ 　.         　　　          ★ 　°                  ☆   　.                        ●            ¸       . ");
    gotoxy(1, 26); printf("               . 　 *                              ★　 　     * 　   .　 　                          *　　　 ");
    gotoxy(1, 27); printf("       　★　　　　          　 ° 　　           　　      ○        　　.　★　");
}

void Story() {
    int b;
    Reset_Screen();
    gotoxy(50, 1); SetColor(11); printf("게임 스토리");
    gotoxy(1, 4); SetColor(15);
    printf("2123년.. 우주정거장에서 우주비행사로 일하는 주인공!\n\n 우주선을 타고 새로운 별을 탐사하러 가던 도중 정체 모를 힘에 휩쓸려 정신을 잃고 만다..!!\n\n 다시 지구로 돌아가기 위해서는 도저히 길을 알 수 없는 미로 3개를 통과해야 한다고?! \n\n 주인공의 위험천만 스릴 넘치는 여정!!");
    SetColor(11); printf("\n\n\n 돌아가려면 Esc...");
    while (1) {
        if (_kbhit()) {
            b = _getch();
            if (b == 27) {
                Menu(); break;
            }
        }
    }
}
void Manual() {
    int b;
    Reset_Screen();
    gotoxy(55, 1); SetColor(11); printf("게임 설명");
    gotoxy(1, 3); SetColor(12);
    printf("1. 미로\n\n");
    SetColor(15);
    printf("    3개의 미로를 통과해야 한다. 방향키로 움직일 수 있다.\n\n");
    printf("    미로 길에는 외계인, 무기, 회복 물약이 존재한다.\n\n");
    printf("    숨겨진 히든 피스가 존재한다. 이에 따라 엔딩이 달라진다.!!\n\n\n");
    SetColor(12); printf("2. 외계인들\n\n");
    SetColor(15);
    printf("    외계인들이 있는 칸에 도달하면 적들과 싸운다. 죽이지 않으면 내가 죽는다!\n\n");
    printf("    a, s, d, w 키로 공격한다. 화면에 뜬 문자와 같은 키를 누르면 공격 성공!\n\n");
    printf("    외계인들은 일정 시간마다 공격을 하며, hp가 0이 되면 죽는다. (만땅이 100)\n\n\n");
    SetColor(12); printf("3. 무기와 회복 물약\n\n");
    SetColor(15);
    printf("    무기 획득 시 외계인과 싸울 때 공격력이 올라간다.!!\n\n");
    printf("    회복 물약을 먹으면 깎인 체력이 일정 수치 회복 된다.!\n\n\n");
    SetColor(11);
    printf("돌아가려면 Esc...");
    while (1) {
        b = _getch();
        if (b == 27) {
            Menu(); break;
        }
    }
}
// TODO: fi bad code
void Menu() {
    int option;
    Reset_Screen();
    SetColor(15);
    BackGround();
    Clean_Screen(30, 11, 45, 8);
    
    SetColor(14);
    BOX(30, 11, 45, 8);
    gotoxy(58, 7);printf("MENU");
    
    SetColor(15);
    gotoxy(48, 11); printf("[1] STORY     [3] MANUAL");
    gotoxy(48, 15); printf("[2] GAME      [4] END");

    /*SetColor(14);
    BOX(9, 3, 48, 10);
    BOX(8, 3, 49, 14);
    BOX(10, 3, 62, 10);
    BOX(7, 3, 63, 14);*/
    gotoxy(1, 20);
    while (1) {
        fflush(stdin);
        option = _getch();

        if (option == 49) {
            Story();
            break;
        }
        else if (option == 50) {
            GameStart();
            break;
        }
        else if (option == 51) {
            Manual();
            break;
        }
        else if (option == 52) {
            return 0;
        }
    }

}

void StartScreen() {
    int b;
    BOX(120, 30, 0, 0);
    
    BackGround();
    
    SetColor(14);
    gotoxy(23, 3); printf("________     _______      _______      ________     ________     ________");
    gotoxy(22, 4); printf("|  ___   |   |  _____|    |  ___  |    |  ___   |   |  ______|   |  ______|");
    gotoxy(22, 5); printf("|　|__|  |   |  |     　  |  |__| |    |  |  |  |   |  |_____    |  |_____");
    gotoxy(22, 6); printf("|　 __   |   |  |____     |  ___　\\    |  |__|  |   |______  |   |______  |");
    gotoxy(22, 7); printf("|__| |___|   |_______|　  |__|  |__|   |________|   |________|   |________|");

    gotoxy(42, 9); printf("_________    ___   ___     ________");
    gotoxy(42, 10); printf("|___  ___|   |  |  |  |    |  _____|");
    gotoxy(45, 11); printf("|  |      |  |--|  |    |  |_____");
    gotoxy(45, 12); printf("|  |      |  |--|  |    |  |_____");
    gotoxy(45, 13); printf("|__|      |__|  |__|    |_______|");
    gotoxy(12, 16); printf("____________        ____________         ___________         ____________        ____________");
    gotoxy(11, 17); printf("|           |       |   _____   | 　　   |   　      |       |           |       |           |");
    gotoxy(11, 18); printf("|    _______| 　    |  |     |  |　　　  |   _____   |       |   ________|       |   ________|");
    gotoxy(11, 19); printf("|   |_______        |  |_____|  | 　　 　|  |     |  |       |　 |               |　 |_______");
    gotoxy(11, 20); printf("|_______    |       |   ________|　　　  |  |_____|  |       |　 |               |　 ________|");
    gotoxy(11, 21); printf("_______|    |       |   |                |   _____   |       |　 |_______        |　 |_______");
    gotoxy(11, 22); printf("|           |       |   |                |   |    |  |       |　 　      |  　   |　 　      |");
    gotoxy(11, 23); printf("|___________|       |___|                |___|    |__|       |___________|     　|___________|");

    while (1) {

        if (_kbhit()) {
            b = _getch();
            //printf("[%d]", b);
            if (b == 13) break;
        }
        SetColor(8); gotoxy(50, 26); printf("<<ENTER KEY TO START>>");
        Sleep(300);
        
        if (_kbhit()) {
            b = _getch();
            if (b == 13) break;
        }
        gotoxy(50, 26); printf("                      ");
        Sleep(300);
    }
    Menu();
}