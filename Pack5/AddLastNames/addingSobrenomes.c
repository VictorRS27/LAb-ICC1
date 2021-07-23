#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Victor Rodrigues da Silva
 * N°USP: 12566140
 * 
 * programa para ler indefinidos nomes e remanejar sobrenomes
 * 
*/


// funcao para leitura com alocacao dinamica
char *read_line() {
    int i=0;
    char *line= malloc(sizeof(char));
    do
    {
        line[i]= getchar();
        if (line[i]=='\n' || line[i]=='\r')
        {
            line[i]='\0';
        }else
        {
            line = realloc(line, (i+2) * sizeof(char));
        }
        i++;
    }while (line[i-1]!='\0');
    return line;
}


int main(int argc, char const *argv[])
{
    int i=-1, j=0, qntdNomes=0, saida=0;
    char **nomes = malloc((qntdNomes+1) * sizeof(char *));

    //repete a cada nome 
    do
    {
        qntdNomes++;
        i++;
        nomes = realloc( nomes, qntdNomes * sizeof(char *));
        nomes[i]=read_line();
        char *tmp= strstr(nomes[i], "$");

        //lê o $ e engatilha o fim de arquivo, alem de sumir com o $
        if (tmp)
        {
            *tmp='\0';
            saida=1;
        }
        
        //adiciona o sobrenme do par ao impar, ja realocando espaço o suficiente para isso
        if (i%2==1)
        {
            nomes[i] = realloc(nomes[i], strlen(nomes[i])+strlen(strrchr(nomes[i-1], ' ')) * sizeof(char));
            strcat(nomes[i], strrchr(nomes[i-1], ' '));
        }
        
    } while (!saida);

    //escreve os nomes
    for ( j = 0; j <= i; j++)
    {
        printf("%s\n", nomes[j]);
    }
    //libera a matriz
    for ( j = 0; j < i; j++)
    {
        free(nomes[j]);
    }
    free(nomes);
    
    
    return 0;
}
