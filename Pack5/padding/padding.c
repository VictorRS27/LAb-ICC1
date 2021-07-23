#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Victor Rodrigues da Silva
 * N°USP: 12566140
 * 
 * Programa para ler uma matriz com tamanho dado e adicionar bordas de 0s conforme informado
 * 
*/
// preenche um espaço quadrilatero de 0s
void printer(int lines, int lineSize) {
    int i, j;
    for ( i = 0; i < lines; i++)
    {
        for ( j = 0; j < lineSize; j++)
        {
            printf("0 ");
        }
        if (lines!=1)
        {
            printf("\n");
        }
        
    }
}

int main(int argc, char const *argv[])
{
    int **imagem, largura, altura, padding, i=0, j=0;

    scanf(" %i", &largura);
    scanf(" %i", &altura);
    //le e aloca dinamicamente a imagem numa matriz
    imagem = malloc(altura * sizeof(int *));
    for ( i = 0; i < altura; i++)
    {
        imagem[i] = malloc(largura * sizeof(int));  
        for ( j = 0; j < largura; j++)
        {
            scanf(" %i", &imagem[i][j]);
        }
    }

    scanf(" %i", &padding);

    //printa a matriz imagem dentro do padding
    printer(padding, largura+2*padding);
    for ( i = 0; i < altura; i++)
    {
        printer(1, padding);
        for ( j = 0; j < largura; j++)
        {
            printf("%i ", imagem[i][j]);
        }
        printer(1, padding);        
        printf("\n");
    }
    printer(padding, largura+2*padding);
    printf("\n");

    //printa a matriz imagem original
    for ( i = 0; i < altura; i++)
    {
        for ( j = 0; j < largura; j++)
        {
            printf("%i ", imagem[i][j]);
        }
        printf("\n");
    }
    
    //livra a memoria da matriz
    for ( i = 0; i < altura; i++)
    {
        free(imagem[i]);
    }    
    free(imagem);

    return 0;
}
