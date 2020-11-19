// INCLUDES
#include <string.h>

// CONSTANT
const char WORD[9] = {'i','n','i','t','i','a','l','e'};

// PROTOTYPE
void MenuTitle(int*, int*, char*);
void Quit();
void Round(int*, int*, char*);
void Analyse(char, int*, char*);
void Victory(int*, int*, char*);
void EndTitle(int*, int*);
void Init(int*, char*);
void DrawPicture(int*);
void GetAnswer(int*);

// MENU TITLE
void MenuTitle(int *g, int *lifes, char *MORD){
    system("cls");
    Init(lifes, MORD);

    printf("### PENDU ###\n");
    printf("\n");
    printf("Bienvenu dans le jeu du pendu. Voulez-vous commencer ? [Y/N]\n");
    GetAnswer(g);
}

// SEND GAME STATE
void GetAnswer(int *a){
    char answer = ' ';

    // Request valid answer
    while(answer != 'y' && answer != 'Y' && answer != 'n' && answer != 'N'){
        fflush(stdin);
        scanf("%c", &answer);
    }

    // Return integer (game state)
    if (answer == 'y' || answer == 'Y')
        *a = 1; // return 1;
    else
        *a = -1; // return -1;
}

// QUIT TITLE
void Quit(){
    system("cls");
    printf("Au revoir.\n");
}

// DRAW THE GAME INTERFACE
void Round(int *g, int *lifes, char *MORD){
    char letter;

    system("cls");

    DrawPicture(lifes);

    for (int i = 0; i < strlen(WORD); i++)
        printf(" %c", MORD[i]);

    printf("\n\nIl vous reste %d vies.\n", *lifes);
    printf("Proposez une lettre : ");

    fflush(stdin);
    scanf("%c", &letter);
    // letter = getchar();
    printf("%c", letter);

    Analyse(letter, lifes, MORD);
    Victory(g, lifes, MORD);
}

// ANALYSE THE ENTERED CHARACTER
void Analyse(char letter, int *lifes, char *MORD){
    int letterFound = 0;
    for (int i = 0; i < strlen(WORD); i++)
        if (letter == WORD[i]){
            MORD[i] = letter;
            letterFound = 1;
        }
    if (letterFound == 0)
        (*lifes)--;
}

// SET VICTORY
void Victory(int *g, int *lifes, char *MORD){
    int isWinning = 1;
    for (int i = 0; i < strlen(WORD); i++)
        if (MORD[i] == '_')
            isWinning = 0;
    if (isWinning == 1 || *lifes < 1)
        *g = 2;
    else
        *g = 1;
}

// END TITLE
void EndTitle(int *g, int *lifes){
    system("cls");
    fflush(stdin);

    if (*lifes > 0)
        printf("Felicitation !\nVous avez gagne ! [ENTER]");
    else
        printf("Dommage ! Vous avez perdu ! [ENTER]");
    getchar();

    *g = 0;
}

// INIT MORD
void Init(int *lifes, char *MORD){
    for (int i = 0; i < strlen(WORD); i++)
        MORD[i] = '_';
    *lifes = 10;
}

void DrawPicture(int *lifes){
    switch(*lifes){
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
