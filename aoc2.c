#include <stdio.h>
#include <stdlib.h>

int main(void)
{

    FILE *f = fopen("aoc2.txt", "r");

    char line[5];

    char opponent_move[2500];
    char my_move[2500];

    int my_points = 0;

    for (int i = 0; fgets(line, sizeof(line), f); i++)
    {
        opponent_move[i] = line[0];
        my_move[i] = line[2];
    }

    // 1 ROCK A X
    // 2 PAPER B Y
    // 3 SCISSORS C Z

    // 0 LOSS
    // 3 DRAW
    // 6 WIN

    // AX 1 + 3     BX 1 + 0    CX 1 + 6
    // AY 2 + 6     BY 2 + 3    CY 2 + 0
    // AZ 3 + 0     BZ 3 + 6    CZ 3 + 3

    for (int i = 0; i < 2500; i++)
    {
        if (opponent_move[i] == 'A')
        {
            if (my_move[i] == 'X')
                my_points += 4;
            if (my_move[i] == 'Y')
                my_points += 8;
            if (my_move[i] == 'Z')
                my_points += 3;
        }
        if (opponent_move[i] == 'B')
        {
            if (my_move[i] == 'X')
                my_points += 1;
            if (my_move[i] == 'Y')
                my_points += 5;
            if (my_move[i] == 'Z')
                my_points += 9;
        }
        if (opponent_move[i] == 'C')
        {
            if (my_move[i] == 'X')
                my_points += 7;
            if (my_move[i] == 'Y')
                my_points += 2;
            if (my_move[i] == 'Z')
                my_points += 6;
        }
    }
    printf("%i\n", my_points);
    fclose(f);
}
