#include <stdio.h>
#include <stdlib.h>

// HEADERS
#include "define.h"
#include "function.c"

int main()
{
    int gameState = 0;

    while (gameState != -1){
        switch(gameState){
        case 0:
            // MENU
            MenuTitle(&gameState);
        break;
        case 1:
            // GAME
            DrawGame();
            Victory(&gameState);
        break;
        case 2:
            // END
            EndTitle(&gameState);
        break;
        }
    }
    Quit();
}
