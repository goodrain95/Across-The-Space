#include <stdio.h>
#include <windows.h>
#include <conio.h>
//#include "function.c"

void StartScreen();

void main() {
    system("mode con cols=120 lines=30");
    Cursor(0);
    StartScreen();
    //gotoxy(3, 5);
    int a;
    //printf("hello");
    //return 0;
}

void StartScreen() {
    BOX(120, 30, 0, 0);
    gotoxy(1, 1); printf("°           ☆ 　       　★　      .        *                       ●           ¸  　　　★ ");
    gotoxy(1, 2); printf("                                                        ☆　               .                            .");
    gotoxy(1, 3); printf("	                ________     _______      _______      ________     ________     ________");
    gotoxy(1, 4); printf("     *                |  ___   |   |  _____|    |  ___  |    |  ___   |:. |  ______|:  |  ______|               ○ ");
    gotoxy(1, 5); printf("             *        |　|__|  |   |  |    .　  |  |__| |    |  |  |  |   |  |_____    |  |_____      ● ¸       ");
    gotoxy(1, 6); printf("     .                |　 __   |   |  |____     |  ___　\\  * |  |__|  |   |______  |   |______  |              *　");
    gotoxy(1, 7); printf("                      |__| |___|   |_______|　  |__|  |__|   |________|   |________|   |________|  ");
    gotoxy(1, 8); printf("○               　　       　  　　　         *                ★         °                                 .　　");
    gotoxy(1, 9); printf("        .  ★　      .        *      ●      _________    ___   ___     ________　★ 　     °           ");
    gotoxy(1, 10); printf("                   　　　                 |___  ___|   |  |  |  |    |  _____|                                     ☆");
    gotoxy(1, 11); printf("★            ★              °                |  |      |  |--|  |    |  |_____    *                 .　");
    gotoxy(1, 12); printf("                      °          ★           |  |      |  |--|  |    |  |_____               ");
    gotoxy(1, 13); printf("       　                     　　    　     |__|      |__|  |__|    |_______|              ○             *");
    gotoxy(1, 14); printf("　 　                 .   ☆                            .           *  　　　     °    ☆ 　          .             ●");
    gotoxy(1, 15); printf("     ★                                       ˚ ˚                              *                 .　 　    　 °     .");
    gotoxy(1, 16); printf("         °　 ____________        ____________         ___________        ____________        ____________         ★");
    gotoxy(1, 17); printf("            |           |       |   _____   | 　　   |   　      |       |           |°      |           |");
    gotoxy(1, 18); printf("            |    _______| 　    |  |     |  |　　　  |   _____   |       |   ________|       |   ________|");
    gotoxy(1, 19); printf("       °  . |   |_______        |  |_____|  | 　　★　|  |     |  |       |　 |               |　 |_______    °☆");
    gotoxy(1, 20); printf("  *         |_______    |       |   ________|　　　  |  |_____|  |  ★    |　 |               |　 ________|");
    gotoxy(1, 21); printf("     ★      _______|    |       |   |          ★     |   _____   |    ☆  |　 |_______        |　 |_______           *");
    gotoxy(1, 22); printf("            |           |       |   |                |   |    |  |       |　 　      |★ 　   |　 　      |*       .  ");
    gotoxy(1, 23); printf("            |___________|       |___|                |___|    |__|       |___________|    ★　|___________|    ●   ");
    gotoxy(1, 24); printf("");
    gotoxy(1, 25); printf("");
    gotoxy(1, 26); printf("");
    gotoxy(1, 27); printf("");
}