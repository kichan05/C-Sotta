//
// Created by ¹ÙÅ°Âù on 2024-12-06.
//

#include <windows.h>
#include <stdio.h>

#include "../gameModule.h"

void initPlayerScene(struct GameManger * gameManger) {
    gameManger->headPlayer = getNewPlayer();
    printWithColor(YELLOW,"Input your name : ");
    scanf("%s", &(gameManger->headPlayer->name));

    printWithColor(YELLOW, "Input player count : ");
    scanf(" %d", &(gameManger->playerCount));

    struct Player * currentPlayer = gameManger->headPlayer;

    for(int i = 0; i < gameManger->playerCount - 1; i++) {
        struct Player * newPlayer = getNewPlayer();

        sprintf((char *) &(newPlayer->name), "AI %d", i + 1);
        currentPlayer->next = newPlayer;
        currentPlayer = newPlayer;
    }
}