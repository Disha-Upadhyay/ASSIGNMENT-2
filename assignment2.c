#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>

#define KEY_LEFT 75
#define KEY_RIGHT 77

// Flicker ????? ?? ???
void clear_screen_fast() {
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos = {0, 0};
    SetConsoleCursorPosition(h, pos);
}

// Obstacle structure
typedef struct {
    int lane;
    int step;
} Obstacle;

void playGame() {
    int playerLane = 1;   // Player ?? lane (0,1,2)
    int score = 0;        // Score
    int speed = 120;      // Initial speed

    Obstacle obstacle;
    obstacle.lane = rand() % 3;
    obstacle.step = 0;

    while (1) {
        // ---- INPUT ----
        if (_kbhit()) {
            char ch = getch();
            if (ch == KEY_LEFT && playerLane > 0) playerLane--;
            if (ch == KEY_RIGHT && playerLane < 2) playerLane++;
        }

        // ---- DRAW ----
        clear_screen_fast();
        printf("Car Dodger Game   |   Score: %d\n", score);
        printf("|--- --- ---|\n");

        for (int i = 0; i < 10; i++) {
            if (obstacle.step == i) {
                if (obstacle.lane == 0) printf("| X        |\n");
                else if (obstacle.lane == 1) printf("|     X    |\n");
                else if (obstacle.lane == 2) printf("|        X |\n");
            } else {
                printf("|           |\n");
            }
        }

        // ---- PLAYER ----
        if (playerLane == 0) printf("| A         |\n");
        else if (playerLane == 1) printf("|     A     |\n");
        else if (playerLane == 2) printf("|        A  |\n");

        // ---- COLLISION ----
        if (obstacle.step == 10 && playerLane == obstacle.lane) {
            clear_screen_fast();
            printf("\nGAME OVER!\n");
            printf("Final Score: %d\n", score);
            if (score >= 20) printf("Great job! You played really well!\n");
            printf("Press R to restart or Q to quit...\n");

            while (1) {
                if (_kbhit()) {
                    char choice = getch();
                    if (choice == 'r' || choice == 'R') return; // restart
                    if (choice == 'q' || choice == 'Q') exit(0); // quit
                }
            }
        }

        Sleep(speed);

        // ---- MOVE OBSTACLE ----
        obstacle.step++;
        if (obstacle.step > 10) {
            obstacle.step = 0;
            obstacle.lane = rand() % 3;
            score++;
            if (speed > 40) speed--; // ????-???? speed ??????
        }
    }
}

int main() {
    srand(time(0));
    system("color 3F"); // Blue theme

    printf("Welcome to Car Dodger!\n");
    printf("Instructions:\n");
    printf("? Move Left   |   ? Move Right\n");
    printf("Avoid the obstacles (X) and survive!\n");
    printf("Press any key to start...\n");
    getch();

    while (1) {
        playGame(); // ?? ??? ????
    }

    return 0;
}
