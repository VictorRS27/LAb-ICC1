#include <stdio.h>
#include <stdlib.h>

int main()
{
    int dia = 0, i = 0;

    scanf("%d", &dia);

    printf("         Abril 2021         \n");
    printf(" Do  Se  Te  Qu  Qu  Se  Sa \n");
    printf("                ");

    for (i = 1; i <= 30; i++)
    {
        if (i == dia)
        {
            printf("(%2d)", i);
        }
        else
        {
            printf("%3d ", i);
        }
        if (i % 7 - 3 == 0)
        {
            printf("\n");
        }
    }

    return 9;
}
