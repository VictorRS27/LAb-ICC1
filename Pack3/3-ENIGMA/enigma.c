#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 26

//roda individualmente um rotor
void rotate(int *rotor ){
    int aux=0, i=0;

    aux=*rotor;
    for ( i = 0; i < 25; i++)
    {
        *(rotor+i)=*(rotor+i+1);
    }
    *(rotor+25)=aux;
}

int main(int argc, char const *argv[])
{
    int i=0, j=0;
    int *rotor1 = (int *)malloc(SIZE * sizeof(int));
    int *rotor2 = (int *)malloc(SIZE * sizeof(int));
    int *rotor3 = (int *)malloc(SIZE * sizeof(int));

    //ignorando a linha de entrada "Rotores:"
    scanf("%*[^\r\n]s");
    scanf("%*[\r\n]s"); 

    //leitura dos rotores + comentários para debug
    for ( i = 0; i < SIZE; i++)
    {
        scanf(" %i", rotor1+i);
        //printf("%i ", *(rotor1+i));
        
    }

    for ( i = 0; i < SIZE; i++)
    {
        scanf(" %i", rotor2+i);
        //printf("%i ", *(rotor2+i));
    }

    for ( i = 0; i < SIZE; i++)
    {
        scanf(" %i", rotor3+i);
        //printf("%i ", *(rotor3+i));
    }

    //pula a linha vazia e ignora "Mensagem:"
    scanf("%*[^\r\n]s"); 
    scanf("%*[\r\n]s"); 
    scanf("%*[^\r\n]s"); 
    scanf("%*[\r\n]s"); 

    int current=0,auxInt;
    char aux=0;
    i=0;
    do
    {
        current=getchar();
        aux=current;
        //lida com entradas de minusculas
        if (current>=97 && current<=122)
        {
            auxInt=current-97;
            auxInt= rotor3[rotor2[rotor1[auxInt]]];
            auxInt+=97;
            aux=auxInt;
            printf("%c", aux);
            //coordena rodar cada rotor somente quando o anterior tiver completado a volta
            rotate(rotor1);
            i++;
            if (i>=26)
            {
                rotate(rotor2);
                j++;
                i=0;
            }
            if (j>=26)
            {
                rotate(rotor3);
                j=0;
            }
        //lida com entradas maiusculas
        }else if (current>=65 && current<=90)
        {
            auxInt=current-65;
            auxInt= rotor3[rotor2[rotor1[auxInt]]];
            auxInt+=65;
            aux=auxInt;
            printf("%c", aux);
            //repetição das instuções de coordenação
            rotate(rotor1);
            i++;
            if (i>=26)
            {
                rotate(rotor2);
                j++;
                i=0;
            }
            if (j>=26)
            {
                rotate(rotor3);
                j=0;
            }
        //lida com caracteres especiais
        }else if (current!=EOF)
        {
            printf("%c", aux);
        }
        
    } while (current!=EOF);
    
    free(rotor1);
    free(rotor2);
    free(rotor3);
    /*scanf(" %c", &current);
    printf("%c", current);*/
    

    
    return 0;
}
