// INCLUDES
#include <string.h>

// CONSTANT
const char WORD[8] = {'i','n','i','t','i','a','l','e'};

// VARIRABLE
char MORD[8] = {'_','_','_','_','_','_','_','_'};
int lifes = 10;

// PROTOTYPE
void MenuTitle(int*);
void Quit();
void DrawGame();
void Analyse(char);
void Victory(int*);
void EndTitle(int*);
void Init();
void DrawPicture();
int GetAnswer();

// MENU TITLE
void MenuTitle(int *g){
    system("cls");
    Init();

    printf("### PENDU ###\n");
    printf("\n");
    printf("Bienvenu dans le jeu du pendu. Voulez-vous commencer ? [Y/N]\n");
    *g = GetAnswer();
}

// SEND GAME STATE
int GetAnswer(){
    char answer = ' ';

    // Request valid answer
    while(answer != 'y' && answer != 'Y' && answer != 'n' && answer != 'N'){
        fflush(stdin);
        scanf("%c", &answer);
    }

    // Return integer (game state)
    if (answer == 'y' || answer == 'Y')
        return 1;
    else
        return -1;
}

// QUIT TITLE
void Quit(){
    system("cls");
    printf("Au revoir.\n");
}

// DRAW THE GAME INTERFACE
void DrawGame(){
    char l;

    system("cls");

    DrawPicture();

    for (int i = 0; i < strlen(WORD); i++)
        printf(" %c", MORD[i]);

    printf("\n\nIl vous reste %d vies.\n", lifes);
    printf("Proposez une lettre : ");

    fflush(stdin);

    l = getchar();

    Analyse(l);
}

// ANALYSE THE ENTERED CHARACTER
void Analyse(char l){
    int letterFound = 0;
    for (int i = 0; i < strlen(WORD); i++)
        if (l == WORD[i]){
            MORD[i] = l;
            letterFound = 1;
        }
    if (letterFound == 0)
        lifes--;
}

// SET VICTORY
void Victory(int *g){
    int isWinning = 1;
    for (int i = 0; i < strlen(WORD); i++)
        if (MORD[i] == '_')
            isWinning = 0;
    if (isWinning == 1 || lifes < 1)
        *g = 2;
}

// END TITLE
void EndTitle(int *g){
    system("cls");
    fflush(stdin);

    if (lifes > 0)
        printf("Felicitation !\nVous avez gagne ! [ENTER]");
    else
        printf("Dommage ! Vous avez perdu ! [ENTER]");
    getchar();

    *g = 0;
}

// INIT MORD
void Init(){
    for (int i = 0; i < strlen(WORD); i++)
        MORD[i] = '_';
    lifes = 10;
}

void DrawPicture(){
    switch(lifes){
        case 10:
            printf("\n     \n     \n     \n     \n\n");
        break;
        case 9:
            printf("\n     \n     \n     \n     \n___\n");
        break;
        case 8:
            printf("\n |    \n |    \n |    \n |    \n_|_\n");
        break;
        case 7:
            printf("________\n |    \n |    \n |    \n |    \n_|_\n");
        break;
        case 6:
            printf("________\n |    |\n |    0\n |    \n |    \n_|_\n");
        break;
        case 5:
            printf("________\n |    |\n |    0\n |    | \n |    \n_|_\n");
        break;
        case 4:
            printf("________\n |    |\n |    0\n |   /| \n |    \n_|_\n");
        break;
        case 3:
            printf("________\n |    |\n |    0\n |   /|\\ \n |    \n_|_\n");
        break;
        case 2:
            printf("________\n |    |\n |    0\n |   /|\\ \n |   /  \n_|_\n");
        break;
        case 1:
            printf("________\n |    |\n |    0\n |   /|\\ \n |   / \\ \n_|_\n");
        break;
    }
}
