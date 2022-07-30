#include <stdio.h>

#define W 80
#define H 25

void game_pong() {
    int lScore = 0;
    int rScore = 0;
    char input = 0;
    do {
        printf("Left Score:%d", lScore);
        for (int i = 0; i < 29; i++) {
            printf(" ");
        }
        printf("Right Score:%d\n", rScore);
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                if (i == 0  || i == H - 1) {
                    printf("#");
                } else {
                    if (j == 0 || j == W - 1){
                        printf("#");
                    } else {
                        if (j == 39 || j == 40){
                            printf("|");
                        } else {
                            printf(" ");
                        }
                    }
                }
            }
            printf("\n");
        }
        printf("\nA/Z, K/M to play game\nenter e to exit\n");
        scanf("%c",&input);
        printf("\n!%c!",input);
    } while(input != 'e' || lScore != 21 || rScore != 21);
}





int main() {
    game_pong();
    return 0;
}
