#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{

    FILE *f = fopen("aoc1.txt", "r");
    if (f == NULL)
        return 1;

    char *line = malloc(10);

    int elf_count = 0;

    while (fgets(line, sizeof(line), f))
        if (strlen(line) == 1)
            elf_count++;

    fclose(f);

    int elves[elf_count];

    for (int i = 0; i < elf_count; i++)
        elves[i] = 0;

    int calories = 0;
    int elf = 0;

    f = fopen("aoc1.txt", "r");
    if (f == NULL)
        return 1;

    while (fgets(line, sizeof(line), f))
    {

        calories = atoi(line);

        if (strlen(line) != 1)
            elves[elf] += calories;
        else
            elf++;
    }

    int max = 0;

    for (int i = 0; i < elf_count; i++)
        if (elves[i] > elves[max])
            max = i;

    printf("Elf #%i is carrying the most calories (%i).\n", max + 1, elves[max]);

    free(line);
    fclose(f);
}
