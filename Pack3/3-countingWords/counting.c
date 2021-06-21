#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    int lines=0, words=0, chars=0, handleEOF=0;
    char current, memory;
    
    //o primeiro lido fora para garantir que se o primeiro digitado for algum fim de palavra não seja computado
    current=getchar();
    memory=current;

    
    do
    {
        //getchar precisa ser entregue a um int pois char é unsigned e não pode ler o -1 do EOF
        handleEOF=getchar();
        current= handleEOF;
        //conta as linhas considerando /r/n como se pulasse uma linha só
        if ((memory!='\r' && current=='\n')|| current=='\r')
        {
            lines++;
        }
        //conta as palavras baseado em quantos caracteres podem finaliza-las, contudo, cuidando para que não conte sequencias e conte a ultima palavra do arquivo
        if ((memory!=' ' && memory!='\n' && memory!='\t' && memory!='\r') && (current==' ' || current=='\n' || current=='\t' || current=='\r' || handleEOF==EOF))
        {
            words++;
        }
        chars++;

        memory=current;

        
    }while (handleEOF!=EOF);

    printf("Linhas\tPalav.\tCarac.\n");
    printf("%d\t%d\t%d", lines, words, chars);

    return 0;
}
