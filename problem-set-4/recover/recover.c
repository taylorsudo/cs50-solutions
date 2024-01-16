#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: %s IMAGE\n", argv[0]);
        return 1;
    }

    char *infile = argv[1];

    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }

    unsigned char buffer[512];

    char filename[8];

    int imageNum = 0;

    FILE *outptr;

    bool jpeg = false;

    while (fread(buffer, sizeof(buffer), 1, inptr))
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            if (jpeg)
            {
                fclose(outptr);
                jpeg = false;
            }
            sprintf(filename, "%03i.jpg", imageNum);

            outptr = fopen(filename, "w");

            fwrite(buffer, sizeof(buffer), 1, outptr);

            jpeg = true;

            imageNum++;
        }
        else
        {
            if (jpeg)
            {
                fwrite(buffer, sizeof(buffer), 1, outptr);
            }
        }
    }
    fclose(inptr);

    fclose(outptr);

    return 0;
}
