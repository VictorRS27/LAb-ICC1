#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    int lines=0, words=0, chars=0;
    char current, memory;

    current=getchar();
    memory=current;

    
    while (current!='8')
    {
        current=getchar();
        

        if ((memory!='\r' && current=='\n')|| current=='\r')
        {
            lines++;
        }
        
        if ((memory!=' ' || memory!='\n' || memory!='\t' || memory!='\r') && (current==' ' || current=='\n' || current=='\t' || current=='\r'))
        {
            printf("%c %c ||", current, memory);
            words++;
        }
        chars++;

        memory=current;

    }
    
    printf("Linhas\tPalav.\tCarac.\n");
    printf("%d\t%d\t%d", lines, words, chars);

    return 0;
}
