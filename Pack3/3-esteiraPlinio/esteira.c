#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINES 32
#define COLUMNS 65

int main(int argc, char const *argv[])
{
    char esteira[LINES][COLUMNS] = {0};
    int i = 0, j = 0, k = 0, l = 0, fim = 0, history = 0;

    //leitura
    for (i = 0; i < LINES; i++)
    {
        for (j = 0; j < COLUMNS; j++)
        {
            esteira[i][j] = getchar();
            if (esteira[i][j] == '[')
            {
                k = i;
                l = j;
            }
        }
    }

    //achar o ponto inicial
    i = k;
    j = l;
    j+=2;
    //achado o ponto inicial, deve-se seguir a esteira

    //printf("%i %c %i ", i, esteira[1][0], esteira[1][0]);
    do
    {
        switch (esteira[i][j])
        {
        case '>':
            esteira[i][j] = '.';
            j+=2;
            history = 3;
            
            break;

        case '<':
            esteira[i][j] = '.';
            j-=2;
            history = 4;
            break;

        case '^':
            esteira[i][j] = '.';
            i--;
            history = 2;
            break;

        case 'v':
            esteira[i][j] = '.';
            i++;
            history = 1;
            //printf("   %i  %i  ggbiughreuighighidgif", i, j);
            break;

            /*para fazer com que deslize é preciso saber de que lado veio, portanto cá estão os codigos de origem para history:
entrada              sinal   conta   codigo
cima -     anterior = "v" =  i++ ->  1
baixo -    anterior = "^" =  i-- ->  2
esquerda - anterior = ">" =  j++ ->  3
direita -  anterior = "v" =  j-- ->  4          */

        case '#':
            switch (history)
            {
            case 3:
                j+=2;
                break;

            case 4:
                j-=2;
                break;

            case 2:
                i--;
                break;

            case 1:
                i++;
                break;

            default:
                break;
            }
            break;

        case '.':
            printf("Loop infinito.\n");
            fim = 1;
            j = COLUMNS;
            i = LINES;
            break;

        case ']':
            printf("Ok.\n");
            fim = 1;
            j = COLUMNS;
            i = LINES;
            break;

        default:
            printf("Falha na esteira.\n");
            fim = 1;
            j = COLUMNS;
            i = LINES;
            break;
        }
        //só se pode parar de seguir a esteira em 3 casos, loop, falha ou termino,
        //por isso uma variavel para controlar o fim da esteira
    } while (fim != 1);

    for (i = 0; i < LINES; i++)
    {
        for (j = 0; j < COLUMNS; j++)
        {
            printf("%c", esteira[i][j]);
            //printf("%i", i);
        }
        //printf("\n");
    }

    return 0;
}


/*
[ v > ] 
  > ^   
*/