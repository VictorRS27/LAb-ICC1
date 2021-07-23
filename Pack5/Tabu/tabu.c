#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Victor Rodrigues da Silva
 * N°USP: 12566140
 * 
 * programa para encontrar palavra tabu em frase e remove-la
 * */
int main(int argc, char const *argv[])
{
    char tabu_word[20];
    int ocurrency_counter = 0, i = 0, saida=0;

    scanf("%s\n", tabu_word);

    char *frase = malloc(sizeof(char));
    //repetir a leitura caracter por caracter, comparando se surgiu a palavras tabu
    do
    {
        
        frase[i] = getchar();
        if (frase[i] == '$')
        {
            frase[i] = '\0';
        }
        else
        {
            frase = realloc(frase, (i + 2) * sizeof(char));
            frase[i+1]='\0';
        }
        if (strstr(frase, tabu_word))
        {
            i = i - strlen(tabu_word);
            frase[i+3]='\0';
            frase = realloc(frase, (i + 2) * sizeof(char));
            ocurrency_counter++;
        }
        i++;
        /*foi necessário fazer esse controle de saída pois o run.codes lida com
        i==0 || frase[i-1] == '\0' no while como segmentation fault*/
        if (i!=0)
        {
            if (frase[i-1] == '\0')
            {
                saida=1;
            }
            
        }
        
    } while (!saida);

    printf("A palavra tabu foi encontrada %d vezes\nFrase: %s\n", ocurrency_counter, frase);

    free(frase);

    return 0;
}
