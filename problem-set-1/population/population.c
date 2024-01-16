#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Prompt for start size
    int startSize;
    do
    {
        startSize = get_int("Start size: ");
    }
    while (startSize < 9);

    // Prompt for end size
    int endSize;
    do
    {
        endSize = get_int("End size: ");
    }
    while (endSize < startSize);

    // Calculate number of years until we reach threshold
    int population = startSize;
    int n = 0;
    while (population < endSize)
    {
        population = population + (population / 3) - (population / 4);
        n++;
    }

    // Print number of years
    printf("Years: %i\n", n);
}
