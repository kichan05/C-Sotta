#include <stdio.h>
#include <windows.h>

#include "../gameModule.h"

int menuScene() {
    int c, mapKey;
    int isSpecial;

    int index = 0;

    clearConsole();
    while (1) {
        isSpecial = 0;

        clearConsole();
        printWithColor(GREEN, "Choice next input Enter\n");
        printWithColor(index == 0 ? RED : WHITE, "1. Single Play\n");
        printWithColor(index == 1 ? RED : WHITE, "2. Multi Play\n");
        printWithColor(index == 2? RED : WHITE, "3. Setting\n");
        printWithColor(index == 3 ? RED : WHITE, "4. Exit\n");

        c = getKeyPress();
        if (c == 0) {
            continue;
        }

        if(c == 13 || c == 89) {
            isSpecial = 1;
        }

        if (c == 224 || isSpecial) {
            if(c == 224){
                c = getKeyPress();
            }
            mapKey = mapKeyPress(c);

            switch (mapKey) {
                case KEY_UP:
                    if(index > 0) {
                        index--;
                    }
                    break;
                case KEY_DOWN:
                    if(index < 3) {
                        index++;
                    }
                    break;
                case KEY_ENTER:
                    printWithColor(RED, "Choice\n");

                    return index;
            }
        }
    }
}

