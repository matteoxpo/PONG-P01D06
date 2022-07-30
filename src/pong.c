#include <stdio.h>

#define W 80
#define H 25



void game_pong();





int main() {
    game_pong();
}

void game_pong(){
    printf("Hello! This is PONG!\n We think that you know rules.");
    printf("Before we start let's decide who will start?(in which direction will the ball fly?)");
    int lScore = 0; // счета игроков
    int rScore = 0;
    char input; // ввод команды игроком

    
    int BallXC = W/2;
    int BallYC = H/2;
    //int BallXS = 1;
    //int BallYS = 1;

    int lPadXC = 2;
    int lPadYC = H/2; 

    int rPadXC  = W-1;
    int rPadYC  = H/2;

    printf("\nTO PLAY GAME:\npush A K - to up left/right paddle\npush Z M - to down left/right paddle\n");
    getchar();
    do {
        fpurge(stdin);
        
        printf("Left Score:%d", lScore);
        for (int i = 0; i < 29; i++) {
            printf(" ");
        }
        printf("Right Score:%d\n", rScore);

        for (int y = 0; y < H + 2; y++) { // i - строки
            
            for (int x = 0; x < W + 2; x++) { // j - столбцы
                
                if (y == 0  || y == H + 1) { // СЛУЧАЙ НИЖНЕЙ И ВЕРХНЕЙ ГРАНИЦЫ ПОЛЯ
                    printf("#");             // выводим на всю строку #
                    continue;
                }
                
                if (x == 0 || x == W + 1){ // крайние границы
                    printf("#");
                    continue;
                }
                if (lPadXC == x && (lPadYC == y || lPadYC + 1 == y || lPadYC - 1 == y)){ // вывод левой ракетки
                    printf("|");
                    continue;
                }
                if (rPadXC == x && (rPadYC == y || rPadYC + 1 == y || rPadYC - 1 == y)) { // вывод правой ракетки
                    printf("|");
                    continue;
                }
                if (x == BallXC && y == BallYC) { // мяч
                    printf("*");
                    continue;
                }
                
                if (x == W/2 + 1 || x == W/2){ // сетека посередине
                    printf("|");
                    continue;
                }
                printf(" ");

            }
            printf("\n");
        }
        if (lScore == 21 || rScore == 21)
            break;
        
        scanf("%c",&input);
        //printf("\n!%c!\n", input);
        //if (input == 'w' || input == 'W')
        switch(input){
            case 'a':
                if(lPadYC - 2 != 0) 
                    lPadYC--;
                break;
            case 'A':
                if(lPadYC - 2 != 0) 
                    lPadYC--;
                break;
            case 'z':
                if (lPadYC + 2 != 26)
                    lPadYC++;
                break;
            case 'Z':
                if (lPadYC + 2 != 26)
                    lPadYC++;
                break;
            case 'k':
                if(rPadYC - 2 != 0) 
                    rPadYC--;
                break;
            case 'K':
                if(rPadYC - 2 != 0) 
                    rPadYC--;
                break;
            case 'm':
                if (rPadYC + 2 != 26)
                    rPadYC++;
                break;
            case 'M':
                if (rPadYC + 2 != 26)
                    rPadYC++;
                break;
            case ' ':
                break;
            
        }
        printf("%c", input);



    } while(input != 'e');
    
}

