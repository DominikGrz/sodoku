#include <stdio.h>
#include <math.h>
#include <time.h>

void createBoard(int n, int board[9][9]) {
    //printf(“\033[0;34m”); textausgabe wird blau
    //printf(“\033[0m”); reset zu white

    int wdh = 0;
    int errSum = 0;

    //Füllt das gesamte 2d-Array mit 0
    for (int j = 0; j < 9; j++) {
        for (int i = 0; i < 9; i++) {
            //board[j][i] = (j * 2) + i;
            board[j][i] = 0;
        }
    }

    //Füllt n Felder mit einer rdm Zahl zwischen 1 und 9
    //Wobei 0 = nicht belegt
    do {
        int err = 0;
        int x = rand() % 9;
        int y = rand() % 9;
        int quadrantX = 0;
        int quadrantY = 0;

        int val = rand() % 9 + 1;

        //int qDiv = x / val;
        if (board[x][y] == 0) {
            if (x < 3) {
                quadrantX = 0;
                if (y < 3) {
                    quadrantY = 0;
                }
                else if (y < 6) {
                    quadrantY = 3;
                }
                else {
                    quadrantY = 6;
                }
            }
            else if (x < 6) {
                quadrantX = 3;
                if (y < 3) {
                    quadrantY = 0;
                }
                else if (y < 6) {
                    quadrantY = 3;
                }
                else {
                    quadrantY = 6;
                }
            }
            else {
                quadrantX = 6;
                if (y < 3) {
                    quadrantY = 0;
                }
                else if (y < 6) {
                    quadrantY = 3;
                }
                else {
                    quadrantY = 6;
                }
            }

            //Überprüft den Quadranten, in den der Wert reingeschrieben werden soll
            for (int a = quadrantX; a < (3 + quadrantX); a++) {
                for (int b = quadrantY; b < (3 + quadrantY); b++) {
                    if (board[a][b] == val && ((x != a) || (y != b))) {
                        err = 1;
                        errSum++;
                        break;
                    }
                }
            }

            if (err != 1) {
                //Überprüft jede Reihe der Spalte y
                for (int reX = 0; reX < 9; reX++) {
                    if (board[reX][y] == val && ((x != reX))) {
                        err = 1;
                        errSum++;
                        break;
                    }
                }
            }

            if (err != 1) {
                //Überprüft jede Spalte der Reihe x
                for (int reY = 0; reY < 9; reY++) {
                    if (board[x][reY] == val && ((y != reY))) {
                        err = 1;
                        errSum++;
                        break;
                    }
                }
            }

            if (err != 1) {
                board[x][y] = val;
                wdh++;
            }
        }

    } while (wdh != n);

    printf("Beim Generieren aufgetretene Fehler: %d\n", errSum);
    printf("Vorgegebene Felder: %d\n", n);
}

void drawBoard(int board[9][9]) {
    for (int j = 0; j < 9; j++) {
        for (int i = 0; i < 9; i++) {
            if (board[j][i] != 0 && ((i + 1) % 3) == 0) {
                printf("\033[1;34m");
                printf("%3d ", board[j][i]);
                printf("\033[0m");
            }
            else if (board[j][i] == 0 && ((i + 1) % 3) == 0) {
                printf("%3d ", board[j][i]);
            }
            else if (board[j][i] != 0) {
                printf("\033[1;34m");
                printf("%3d", board[j][i]);
                printf("\033[0m");
            }
            else if (board[j][i] == 0) {
                printf("%3d", board[j][i]);
            }
            if (i == 8 && ((j + 1) % 3) == 0) printf("\n");
        }
        printf("\n");
    }
}

int main(void) {
    int p_board[9][9];
    char a;
    time_t t;
    int belegteFelder = 51;

    srand((unsigned)time(&t));

    createBoard(belegteFelder, p_board);
    drawBoard(p_board);

    /*while (true) {
        scanf("%c", &a);

        switch (a) {
            case 'r':
                system("cls");
                createBoard(belegteFelder, p_board);
                drawBoard(p_board);
            default:
                printf("Rofl");
        }
    }*/

    return 0;
}
