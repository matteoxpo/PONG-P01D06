#include <stdio.h>
#include <math.h>

#define W 80
#define H 25

void game_pong();

int main() { game_pong(); }

void game_pong() {
  printf("Hello! This is PONG!\nWe think that you know rules.");
  printf(
      "Before we start let's decide who will start?(in which direction will "
      "the ball fly?)");
  int lScore = 0;  // счета игроков
  int rScore = 0;
  char input;  // ввод команды игроком

  int BallXC = W / 2;
  int BallYC = H / 2 + 3;
  int BallXS = -1;
  int BallYS = 0;

  int lPadXC = 2;
  int lPadYC = H / 2;

  int rPadXC = W - 1;
  int rPadYC = H / 2;
  int flag = 1;
  printf(
      "\nTO PLAY GAME:\npush A K - to up left/right paddle\npush Z M - to down "
      "left/right paddle\n");
  // getchar();
  do {
    fpurge(stdout);
    printf("\33[0d\33[2J");
    printf("Left Score:%d", lScore);
    for (int i = 0; i < 29; i++) {
      printf(" ");
    }
    printf("Right Score:%d\n", rScore);

    if (flag) {
      for (int y = 0; y < H + 2; y++) {  // i - строки
        for (int x = 0; x < W + 2; x++) {  // j - столбцы
          if (y == 0 || y == H + 1) {  // СЛУЧАЙ НИЖНЕЙ И ВЕРХНЕЙ ГРАНИЦЫ ПОЛЯ
            printf("#");  // выводим на всю строку #
            continue;
          }

          if (x == 0 || x == W + 1) {  // крайние границы
            printf("#");
            continue;
          }
          if (lPadXC == x && (lPadYC == y || lPadYC + 1 == y ||
                              lPadYC - 1 == y)) {  // вывод левой ракетки
            printf("|");
            continue;
          }
          if (rPadXC == x && (rPadYC == y || rPadYC + 1 == y ||
                              rPadYC - 1 == y)) {  // вывод правой ракетки
            printf("|");
            continue;
          }
          if (x == BallXC && y == BallYC && BallXC != 0 &&
              BallXC != W + 1) {  // мяч
            printf("*");
            continue;
          }

          if (x == W / 2 + 1 || x == W / 2) {  // сетека посередине
            printf("|");
            continue;
          }
          printf(" ");
        }
        printf("\n");
      }
    }
    if (BallXC + BallXS == 0) {
      rScore++;
      BallXC = W / 2;
      BallYC = H / 4 + 2 * rScore % (H * 3 / 4);
      BallXS = 1;
      BallYS = (int)pow(-1, rScore);
      continue;
    }
    if (BallXC + BallXS == W + 1) {
      lScore++;
      BallXC = W / 2 + 3;
      BallYC = H / 2 + 2 * lScore % (H * 3 / 4);
      BallXS = 1;
      BallYS = (int)pow(-1, lScore);
      continue;
    }

    if (lScore == 21 || rScore == 21) break;

    if ((BallXC + BallXS == lPadXC) || (BallXC + BallXS == rPadXC)) {
      if (BallXC + BallXS == lPadXC) {
        if (BallYC == lPadYC) {
          BallXS *= -1;
          BallYS *= -1;
          if (BallYS / 2 == 1) {
            BallYS /= 2;
          }
        }
        if (BallYC == lPadYC - 1 || BallYC == lPadYC + 1) {
          BallXS *= -1;
          BallYS *= -1;
          if (BallYS / 2 != 1) {
            BallYS *= 2;
          }
        }
      }
      if (BallXC + BallXS == rPadXC) {
        if (BallYC == rPadYC) {
          BallXS *= -1;
          BallYS *= -1;
          if (BallYS / 2 == 1) {
            BallYS /= 2;
          }
        }
        if (BallYC == rPadYC - 1 || BallYC == rPadYC + 1) {
          BallXS *= -1;
          BallYS *= -1;
          if (BallYS / 2 != 1) {
            BallYS *= 2;
          }
        }
      }
    } else {
      if (BallYC + BallYS < 0 || BallYC + BallYS > H + 1) {
        BallYS /= -2;
      }
      if (BallYC + BallYS == 0 || BallYC + BallYS == H + 1) {
        BallYS *= -1;
      }
    }

    printf("\n    BallXS:%d, BallYS:%d, BallXC:%d, BallYC:%d \n", BallXS,BallYS, BallXC, BallYC);

    BallXC += BallXS;
    BallYC += BallYS;
    // scanf("%c",&input);
    input = getchar();  // ввод команды с консоли
    switch (input) {    // почитать как работает switch case
      case 'a':
        if (lPadYC - 2 != 0) lPadYC--;
        flag = 1;
        break;
      case 'A':
        if (lPadYC - 2 != 0) lPadYC--;
        flag = 1;
        break;
      case 'z':
        if (lPadYC + 2 != 26) lPadYC++;
        flag = 1;
        break;
      case 'Z':
        if (lPadYC + 2 != 26) lPadYC++;
        flag = 1;
        break;
      case 'k':
        if (rPadYC - 2 != 0) rPadYC--;
        flag = 1;
        break;
      case 'K':
        if (rPadYC - 2 != 0) rPadYC--;
        flag = 1;
        break;
      case 'm':
        if (rPadYC + 2 != 26) rPadYC++;
        flag = 1;
        break;
      case 'M':
        if (rPadYC + 2 != 26) rPadYC++;
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
  } while (input != 'e');
}
