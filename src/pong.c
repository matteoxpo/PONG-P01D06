#include <stdio.h>
#include <math.h>

#define W 80
#define H 25

void game_menu();
void game_pong();

int main() {
  game_menu();
  return 0;
  }
void game_menu() {
  printf("-------------------------------------------");
  printf("\n|                 PONG GAME               |");
  printf("\n-------------------------------------------");
  char command = ' ';
  while ( command != 'e' ) {
    printf("\nGame menu:\n1 - rules\n2 - play\ne - exit");
    printf("\nEnter command:");
    if (scanf("%c", &command)) {
      switch (command) {
        case '1':
          printf(
              "\nPong is a two-dimensional sports game that simulates table tennis. The "
              "player controls an in-game paddle by moving it vertically across the left "
              "or right side of the screen. They can compete against another player "
              "controlling a second paddle on the opposing side. Players use the paddles "
              "to hit a ball back and forth. The goal is for each player to reach eleven "
              "points before the opponent; points are earned when one fails to return "
              "the ball to the other.");
          break;
          case '2':
          game_pong();
          break;
        case 'e':
          return;
          break;
      }
    } else {
      printf("\nInput error! Let's try again!\nEnter command:");
    }
    getchar();
  }
}

void game_pong() {
int lScore = 0;  // счета игроков
int rScore = 0;
char input;  // ввод команды игроком

int BallXC = W / 2;  // переменные координаты и скорости шара
int BallYC = H / 2 + 1;
int BallXS = -1;
int BallYS = -1;

int lPadXC = 2;  // переменные координат ракетки
int lPadYC = H / 2;
int rPadXC = W - 1;
int rPadYC = H / 2;
int flag = 1;  // флаг корректности ввода
getchar();
printf(
    "\nTO PLAY GAME:\nEnter A K - to up left/right paddle\nEnter Z M - to down "
    "left/right paddle\nEnter e to exit\n");
printf("-------------------------------------------");
printf("\n|                 Game PLAY               |");
printf("\n-------------------------------------------\n");
do {  // do ... while(...) - цикл с постусловием, то есть он 1 раз срабатывает
      // 100%, затем проверят условие
  printf("Left Score:%d", lScore);  // вывод счетов игроков
  for (int i = 0; i < 29; i++) {
    printf(" ");
  }
  printf("Right Score:%d\n", rScore);

  if (flag) {  // если введенная игроком команда корректна, то заходим чертить
               // поле

    for (int y = 0; y < H + 2; y++) {     // проходим по всем строкам поля
      for (int x = 0; x < W + 2; x++) {   // проходим по столбцам поля
        if (y == 0 || y == H + 1) {  // верхняя и нижняя границы поля
          printf("#");               // выводим на всю строку #
          continue;
        }

        if (x == 0 || x == W + 1) {  // левая и правая граница
          printf("#");               // выводим только если координата X
          continue;                  // находится на нужных координатах
        }
        if (lPadXC == x &&
            (lPadYC == y || lPadYC + 1 == y ||  // вывод левой ракетки
             lPadYC - 1 == y)) {                // если попали по X и на одну из 3 по Y
          printf("|");                          // напомню, что lPadYC - центр ракетки
          continue;
        }
        if (rPadXC == x &&
            (rPadYC == y || rPadYC + 1 == y ||  // вывод правой ракетки
             rPadYC - 1 == y)) {                // как и левую
          printf("|");
          continue;
        }
        if (x == BallXC && y == BallYC && BallXC != 0 &&  // выводим мяч
            BallXC != W + 1) {                            // совпал по координатам
          printf("o");                                    // + не в "воротах"
          continue;
        }

        if (x == W / 2 + 1 || x == W / 2) {  // сетека посередине
          printf("|");  // попали в серединку
          continue;
        }
        printf(" ");    // ничего не вывели выше? - выводим пробел
      }
      printf("\n");
    }
  }

    if (BallXC + BallXS == 0) {                     // если попали в ворота
      rScore++;                                     // увеличили счет
      BallXC = W / 2;                               // поставли по местам
      BallYC = H / 4 + 2 * rScore % (H * 3 / 4);    // тут авторский рандом
      BallXS = 1;
      BallYS = (int)pow(-1, rScore);
      continue;
    }
    if (BallXC + BallXS == W + 1) {                 // попадание
      lScore++;
      BallXC = W / 2 + 3;
      BallYC = H / 2 + 2 * lScore % (H * 3 / 4);
      BallXS = -1;
      BallYS = (int)pow(-1, lScore);
      continue;
    }

    if (lScore == 21 || rScore == 21) break;  // 21 очко? - закончим игру

              // если шарик около ракетки
    if ((BallXC + BallXS == lPadXC) || (BallXC + BallXS == rPadXC)) {
      if (BallXC + BallXS == lPadXC) {    // если около левой ракетки
        if (BallYC == lPadYC) {           // попали в середину
          BallXS *= -1;                   // отворачиваемся
          BallYS *= -1;
          if (BallYS / 2 == 1) {          // при необходимости
            BallYS /= 2;                  // замедляемся
          }
        }
        if (BallYC == lPadYC - 1 || BallYC == lPadYC + 1) {
          BallXS *= -1;                   // попали в край ракетки
          BallYS *= -1;
          if (BallYS / 2 != 1) {          // скорость 1?
            BallYS *= 2;                  // ускоряемся!
          }
        }
      }
      if (BallXC + BallXS == rPadXC) {    // тоже самое с правой ракеткой
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
        BallYS /= -2;         // если ускоренные пытаемся вылететь за пределы
      }
      if (BallYC + BallYS == 0 || BallYC + BallYS == H + 1) {
        BallYS *= -1;         // пытаемся вылететь за карту
      }                       // в любом случае перенаправляем по Y
    }

    BallXC += BallXS;         // делаем шаг по координатам
    BallYC += BallYS;

    input = getchar();  // ввод команды с консоли

    // напомню, что у нас получилась перевернутая система координат по Y
    // то есть, чтобы подняться по Y, нужно уменьшить значение координаты ракетки
    // и наоборот, чтобы спуститься, нужно увеличить координату ракетки
    switch (input) {
      case 'a':
        if (lPadYC - 2 != 0) lPadYC--;    // если не в краю карты, то можно смещаться
        flag = 1;                         // флаг отвечает за ввод!!
        break;
      case 'A':
        if (lPadYC - 2 != 0) lPadYC--;
        flag = 1;
        break;
      case 'z':
        if (lPadYC + 2 != H + 1) lPadYC++;
        flag = 1;
        break;
      case 'Z':
        if (lPadYC + 2 != H + 1) lPadYC++;
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
        if (rPadYC + 2 != H + 1) rPadYC++;
        flag = 1;
        break;
      case 'M':
        if (rPadYC + 2 != H + 1) rPadYC++;
        flag = 1;
        break;
      case ' ':
        flag = 1;
        break;
      case '\n':
        flag = 1;
        break;
      default:      // случай некорректного ввода:
        flag = 0;
        break;
    }
  } while (input != 'e');   // условие окончания цикла, то есть ввод e
}
