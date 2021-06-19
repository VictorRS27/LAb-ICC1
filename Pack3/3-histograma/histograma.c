#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX(X, Y) (((X) > (Y)) ? (X) : (Y))
#define TELA 25

int main(int argc, char const *argv[])
{
    int color[5]={0}, i=0, j=0, max=0, imagem[TELA]={0};

    for ( i = 0; i < TELA; i++)
    {
        scanf(" %i", &imagem[i]);
        switch (imagem[i])
        {
        case 1:
            color[1]++;
            break;
        case 2:
            color[2]++;
            break;
        case 3:
            color[3]++;
            break;
        case 4:
            color[4]++;
            break;
        case 0:
            color[0]++;
            break;
        default:
            break;
        }
    }

    for ( i = 0; i < 5; i++)
    {
        printf("%i: |", i);
        for ( j = 0; j < color[i]; j++)
        {
            printf("#");
        }
        printf("\n");
        if (color[i]>color[max])
        {
            max=i;
        }
        
    }
    

    for ( i = 0; i < TELA; i++)
    {
        if (max==imagem[i])
        {
            printf("%i\n", i);
        }
        
    }
    return 0;
}
