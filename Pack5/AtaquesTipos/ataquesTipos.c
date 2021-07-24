#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Victor Rodrigues da Silva
 * N°USP: 12566140
 * 
 * Programa para ler uma matriz com multiplicadores de ataque do tipos de personagens para um jogo.
 * Cada tipo tem maior ou menor influencia sobre o outro conforme a tabela dada.
 * Ainda serao dados valores de ataque e o indice de atacante e defensor na tabela, e deve-se devolver
 * o valor do maior dano e seu indice na matriz.
 * 
*/

int main(int argc, char const *argv[])
{
    float **typeMultiplier;
    int qtdTypes, **attack, IndexMaxDamage = 0, targetIndex, i, j;

    scanf("%i", &qtdTypes);

    //aloca e le dinamicamente a matriz de multiplicadores de ataque
    typeMultiplier = malloc(qtdTypes * sizeof(float *));
    for (i = 0; i < qtdTypes; i++)
    {
        typeMultiplier[i] = malloc(qtdTypes * sizeof(float));
        for (j = 0; j < qtdTypes; j++)
        {
            scanf(" %f", &typeMultiplier[i][j]);
        }
    }
    //prepara para leitura dos ataques, foi necessario por esse malloc, nao sei porque, mas so assim foi
    i = 0;
    attack = malloc(2 * sizeof(int *));
    attack[0] = malloc( sizeof(int));
    attack[1] = malloc( sizeof(int));
    do
    {
        attack[0] = realloc(attack[0], (i+1) * sizeof(int));
        attack[1] = realloc(attack[1], (i+1) * sizeof(int));

        scanf(" %i", &attack[0][i]);
        
        //verifica se o sinal de finalizacao de ataques (-1) nao foi captado
        if (attack[0][i] != -1)
        {
            scanf(" %i", &attack[1][i]);
        }

        i++;
    } while (attack[0][i-1] != -1);

    scanf(" %i", &targetIndex);
    //avalia o dano de cada ataque ao defensor informado e salva o indice do maior dano
    for (j = 0; j < i-1; j++)
    {
        if (typeMultiplier[attack[1][j]][targetIndex] * attack[0][j] > typeMultiplier[attack[1][IndexMaxDamage]][targetIndex] * attack[0][IndexMaxDamage])
        {
            IndexMaxDamage=j;
        }
    }
    //impressao da resposta como pedida, indice seguido de dano
    printf("O melhor ataque possui indice %i e dano %.2f", IndexMaxDamage, typeMultiplier[attack[1][IndexMaxDamage]][targetIndex] * attack[0][IndexMaxDamage]);
    
    //liberacao de dados alocados dinamicamente
    for (j=0; j<2; j++)
    {
		free(attack[j]);
    }
	free(attack);
    for (i=0; i<qtdTypes; i++)
    {
		free(typeMultiplier[i]);
    }
	free(typeMultiplier);
    return 0;
}
