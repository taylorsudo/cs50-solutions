#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;

    // Get height between 1 - 8 from user
    do
    {
        height = get_int("Enter height: ");
    }
    while (height < 1 || height > 8);

    // Increment rows before reaching height value
    for (int i = 0; i < height; i++)
    {
        // Decrement spaces until subtraction value is greater than 1
        for (int k = height - i; k > 1; k--)
        {
            printf(" ");
        }
        // Increment hashtags until value equal to outer loop
        for (int j = 0; j <= i; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}
