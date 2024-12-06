#include <stdio.h>
#include <string.h>

#include "type.c"
#include "console.c"
#include "varient.c"
#include "scene/menuScene.c"
#include "playerInitScene.h"

int CONSOLE_WIDTH, CONSOLE_HEIGHT;

void printMap() {
    moveTo(0, 0);
    for(int i = 0; i < CONSOLE_WIDTH - 1; i++) {
        if(i == 0)
            printf("┌");
        else if(i == CONSOLE_WIDTH - 2)
            printf("┐");
        else
            printf("─");
    }

    for(int i = 1; i < CONSOLE_HEIGHT - 1; i++) {
        moveTo(0, i);
        printf("│");
        moveTo(CONSOLE_WIDTH - 2, i);
        printf("│");
    }

    moveTo(0, CONSOLE_HEIGHT - 2);

    for(int i = 0; i < CONSOLE_WIDTH - 1; i++) {
//        printf("%d", i);
        if(i == 0)
            printf("└");
        else if(i == CONSOLE_WIDTH - 2)
            printf("┘");
        else
            printf("─");
    }
}

void printSelectorBar(int choiceIndex) {
    char selectors[3][5] = {"하프", "다이", "더블"};

    printWithColor(GREEN, "픽을 선택하세요\n");
    printf("%d", strlen("픽을 선택하세요"));

    for(int i = 0; i < 3; i++) {
        if(i != 0) {
            printf("   |   ");
        }
        printWithColor(choiceIndex == i ? RED : WHITE, &(selectors[i]));
    }
}

int main() {
//    system("mode con cols=100 lines=30 | title 섯다");
    CONSOLE_WIDTH = getConsoleWidth();
    CONSOLE_HEIGHT = getConsoleHeight();
    hideCursor();
    clearConsole();

    char c;
    int mapKey;
    GameManger gameManger = {0, 0, 0, NULL};

    initPlayerScene(&gameManger);

    printPlayerList(gameManger.headPlayer);

//    int menuIndex = menuScene();

//    int actionIndex = 0;
//    clearConsole();
//    printSelectorBar(actionIndex);

//    while(1) {
//        c = getKeyPress();
//        if(c == 0)
//            continue;
//
//        if(c == 'q')
//            break;
//
//        if(c == -32) {
//            c = getKeyPress();
//            mapKey = mapKeyPress(c);
//            switch(mapKey) {
//                case KEY_UP:
//                    break;
//                case KEY_RIGHT:
//                    if(actionIndex >= 2)
//                        break;
//                    actionIndex += 1;
//                    break;
//                case KEY_LEFT:
//                    if(actionIndex <= 0)
//                        break;
//                    actionIndex -= 1;
//                    break;
//                case KEY_DOWN:
//                    break;
//            }
//        }
//
//        clearConsole();
//        printSelectorBar(actionIndex);
//    }
}