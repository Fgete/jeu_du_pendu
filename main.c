#include <stdio.h>
#include <stdlib.h>

// HEADERS
#include "define.h"
#include "function.c"

int main()
{
    int gameState = 0;
    int lifes = 10;

    char MORD[9] = {'_','_','_','_','_','_','_','_'};

    while (gameState != -1){
        switch(gameState){
        case 0:
            // MENU
            MenuTitle(&gameState, &lifes, MORD);
        break;
        case 1:
            // GAME
            Round(&gameState, &lifes, MORD);
        break;
        case 2:
            // END
            EndTitle(&gameState, &lifes);
        break;
        }
    }
    Quit();
}
