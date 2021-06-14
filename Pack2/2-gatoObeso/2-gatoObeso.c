#include <stdio.h>
#include <stdlib.h>

int main()
{
    int mordidas = 0, bolinha = 0;

    scanf(" %i %i", &bolinha, &mordidas);

    if (mordidas * 3 - bolinha * 5 > 0)
    {
        printf("R");
    }
    else if (bolinha * 5 - mordidas * 3 >= 30)
    {
        printf("P");
    }
    else
    {
        printf("B");
    }

    return 0;
}