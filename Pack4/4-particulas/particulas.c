#include <stdio.h>
#include <stdlib.h>

char matriz[32][64];

void atualization()
{
    char tmp;
    int i, j;
    char copy[32][64];
    for (i = 0; i < 32; i++)
    {
        for (j = 0; j < 64; j++)
        {
            copy[i][j] = matriz[i][j];
        }
    }
    for (i = 0; i < 32; i++)
    {
        for (j = 0; j < 64; j++)
        {
            if (copy[i][j] == '#' && i <= 32)
            {
                if (copy[i + 1][j] == ' ' || copy[i + 1][j] == '~')
                {
                    tmp = matriz[i][j];
                    matriz[i][j] = matriz[i + 1][j];
                    matriz[i + 1][j] = tmp;
                }
                else if (j > 0 && (copy[i + 1][j - 1] == ' ' || copy[i + 1][j - 1] == '~'))
                {
                    tmp = matriz[i][j];
                    matriz[i][j] = matriz[i + 1][j - 1];
                    matriz[i + 1][j - 1] = tmp;
                }
                else if (j < 64 && (copy[i + 1][j + 1] == ' ' || copy[i + 1][j + 1] == '~'))
                {
                    tmp = matriz[i][j];
                    matriz[i][j] = matriz[i + 1][j + 1];
                    matriz[i + 1][j + 1] = tmp;
                }
            }
            if (copy[i][j] == '~' && i <= 32)
            {
                if (copy[i + 1][j] == ' ')
                {
                    tmp = matriz[i][j];
                    matriz[i][j] = matriz[i + 1][j];
                    matriz[i + 1][j] = tmp;
                }
                else if (j > 0 && copy[i + 1][j - 1] == ' ')
                {
                    tmp = matriz[i][j];
                    matriz[i][j] = matriz[i + 1][j - 1];
                    matriz[i + 1][j - 1] = tmp;
                }
                else if (j < 64 && copy[i + 1][j + 1] == ' ')
                {
                    tmp = matriz[i][j];
                    matriz[i][j] = matriz[i + 1][j + 1];
                    matriz[i + 1][j + 1] = tmp;
                }
                else if (j > 0 && copy[i][j - 1] == ' ')
                {
                    tmp = matriz[i][j];
                    matriz[i][j] = matriz[i][j - 1];
                    matriz[i][j - 1] = tmp;
                }
                else if (j < 64 && copy[i][j + 1] == ' ')
                {
                    tmp = matriz[i][j];
                    matriz[i][j] = matriz[i][j + 1];
                    matriz[i][j + 1] = tmp;
                }
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    int totalFrames, frame, x, y, j, i;
    char nova_particula;

    for (i = 0; i < 32; i++)
    {
        for (j = 0; j < 64; j++)
        {
            matriz[i][j] = ' ';
        }
    }

    scanf("%d", &totalFrames);

    int counter = 0;
    while (counter < totalFrames)
    {

        int endVerifier = scanf(" %d: %d %d %c", &frame, &x, &y, &nova_particula);

        if (endVerifier == EOF)
        {
            frame = totalFrames;
        }

        while (counter < frame)
        {
            printf("frame: %d\n", counter + 1);
            for (i = 0; i < 32; i++)
            {
                for (j = 0; j < 64; j++)
                {
                    printf("%c", matriz[i][j]);
                }
                printf("\n");
            }
            atualization();
            counter++;
        }

        if (endVerifier != EOF)
        {
            matriz[y][x] = nova_particula;
        }
    }
    return 0;
}
