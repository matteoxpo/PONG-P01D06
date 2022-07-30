#include <stdio.h>

#define W 80
#define H 25

void game_pong() {
    int lScore = 0;
    int rScore = 0;
    char input;
    do {
        printf("Left Score:%d", lScore);
        for (int i = 0; i < 29; i++) {
            printf(" ");
        }
        printf("Right Score:%d\n", rScore);
        for (int i = 0; i < H + 2; i++) { // i - строки
            
            for (int j = 0; j < W + 2; j++) { // j - столбцы
                
                if (i == 0  || i == H + 1) { // СЛУЧАЙ НИЖНЕЙ И ВЕРХНЕЙ ГРАНИЦЫ ПОЛЯ
                    printf("#");             // выводим на всю строку #
                } else { //
                    if (j == 0 || j == W + 1){ // СЛУЧАЙ ЛЕВОЙ И ПРАВОЙ ГРАНИЦЫ ПОЛЯ
                        printf("#");           // выводим символ #
                    } else {
                        if (j == 40 || j == 41 ) {// Вывод сетки (добавить условие что шарик не на той же координате)
                            printf("|");
                        } else {
                            //
                            printf(" ");
                        }
                    }
                }
            }
            printf("\n");
        }
        printf("\nA/Z, K/M to play game\nenter e to exit\nInput:");
        scanf("%c",&input);
        printf("\n!%c!",input);//|| lScore != 21 || rScore != 21
    } while(input != 'e' );
}





int main() {
    
    // for while
    //int i = 0;
    //
    
    game_pong();
    return 0;
}
