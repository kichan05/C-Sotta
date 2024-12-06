#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Player {
    char name[30];
    int numbers[2];
    int money;
    int isDie;
    struct Player* next;
} Player;

typedef struct GameManger {
    int playerCount;
    int gameMoney;
    int turn;
    struct Player* headPlayer;
} GameManger;

// 함수 정의
Player* getNewPlayer();

void printPlayerList(Player* head);

// 함수 구현
Player* getNewPlayer() {
    Player* newPlayer = (Player*)malloc(sizeof(Player));
    newPlayer->next = NULL;
}

void printPlayerList(Player* head) {
    Player* current = head;
    int count = 0;
    while(current != NULL) {
        printf("[%02d] - %s\n", count, current->name);
        current = current->next;
        count += 1;
    }
}
