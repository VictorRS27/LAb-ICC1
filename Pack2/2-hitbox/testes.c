#include <stdio.h>
#include <stdlib.h>

int main()
{
    long long int px=0, pl=0, comp=0;

    scanf(" %li %li %li", &px, &pl, &comp); 

    if (px+pl<comp)
    {
        printf("executou %li %li", px+pl, comp);
    }else
    {
        printf("não executou");
    }
    
    
    return 0;
}
