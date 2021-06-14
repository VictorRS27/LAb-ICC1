#include <stdio.h>
#include <stdlib.h>

#define size_fita 512
int main()
{
    int ano;

    scanf("%i", &ano);

    if (ano % 4 == 0)
    {
        printf("SIM\n");
    }
    else
    {
        printf("NAO\n");
    }

    return 0;
}