#include <stdio.h>
#include <stdlib.h>

int main()
{
    int base=0, expoente=0, i=0, resultado=1;

    scanf(" %i %i", &base, &expoente);

    for ( i = 0; i < expoente; i++)
    {
        resultado=base*resultado;
    }

    printf("%i", resultado);
    
    return 0;
}
