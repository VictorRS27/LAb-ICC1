#include <stdio.h>
#include <stdlib.h>

int main()
{
    int entrada=0;

    scanf("%i", &entrada);

    switch (entrada)
    {
    case 0:
        printf("* Morumbi\n");
        printf("|\n");
    case 1:
        printf("* Butanta\n");
        printf("|\n");
    case 2:
        printf("* Pinheiros\n");
        printf("|\n");
    case 3:
        printf("* Faria Lima\n");
        printf("|\n");
    case 4:
        printf("* Fradique Coutinho\n");
        printf("|\n");
    case 5:
        printf("* Oscar Freire");
        break;
    case 6:
        printf("* Paulista\n");
        printf("|\n");
    case 7:
        printf("* Higienopolis-Mackenzie\n");
        printf("|\n");
    case 8:
        printf("* Republica\n");
        printf("|\n");
    case 9:
        printf("* Luz");
        break;

    default:
        break;
    }

    return 0;
}