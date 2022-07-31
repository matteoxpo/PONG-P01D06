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
    int BallXS = -1;
    int BallYS = 1;

    int lPadXC = 2;
    int lPadYC = H/2; 

    int rPadXC  = W-1;
    int rPadYC  = H/2;

    int flag = 1;
    printf("\nTO PLAY GAME:\npush A K - to up left/right paddle\npush Z M - to down left/right paddle\nAny symbol to start:");
    getchar();
    do {
        fpurge(stdin);
        printf("Left Score:%d", lScore);
        for (int i = 0; i < 29; i++) {
            printf(" ");
        }
        printf("Right Score:%d\n", rScore);

        if (flag){
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
                    if (x == BallXC && y == BallYC && BallXC != 0 && BallXC != W + 1) { // мяч
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
        }

        if (BallYC + BallYS == 0 || BallYC + BallYS == H + 1)
            BallYS*=-1;
        

        if (BallXC == 0) {
            rScore++;
            BallXC = W/2;
            BallYC = H/2;
        }
        if (BallXC == W + 1) {
            lScore++;
            BallXC = W/2;
            BallYC = H/2;
        }

        if (lScore == 21 || rScore == 21)
            break;
        
        BallXC+=BallXS;
        BallYC+=BallYS;

        if (BallXC == lPadXC && (BallYC == lPadYC || BallYC == lPadYC +1 || BallYC == lPadYC - 1)){
            BallYS*=-1;
            BallXS*=-1;
        }

        if (BallXC == rPadXC && (BallYC == rPadYC || BallYC == rPadYC + 1 || BallYC == rPadYC - 1)){
            BallYS*=-1;
            BallXS*=-1;
            printf("CHANGED!");
        }

        //scanf("%c",&input);
        input = getchar();
        switch(input){
            case 'a':
                if(lPadYC - 2 != 0) 
                    lPadYC--;    
                flag = 1;
                break;
            case 'A':
                if(lPadYC - 2 != 0) 
                    lPadYC--;
                flag = 1;
                break;
            case 'z':
                if (lPadYC + 2 != 26)
                    lPadYC++;
                flag = 1;
                break;
            case 'Z':
                if (lPadYC + 2 != 26)
                    lPadYC++;
                flag = 1;
                break;
            case 'k':
                if(rPadYC - 2 != 0) 
                    rPadYC--;
                flag = 1;
                break;
            case 'K':
                if(rPadYC - 2 != 0) 
                    rPadYC--;
                flag = 1;
                break;
            case 'm':
                if (rPadYC + 2 != 26)
                    rPadYC++;
                flag = 1;
                break;
            case 'M':
                if (rPadYC + 2 != 26)
                    rPadYC++;
                flag = 1;
                break;
            case ' ':
                flag = 1;
                break;
            case '\n':
                flag = 1;
                break;
            default:
                flag = 0;
                break;
            }
    } while(input != 'e');
    
}

