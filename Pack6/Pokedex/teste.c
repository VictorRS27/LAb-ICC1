#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *read_line() {
    int i=0;
    char *line= malloc(sizeof(char));
    fflush(stdin);
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
    int a;
    char *b, c;
    float d;
    b=read_line();
            printf("%s\n", b);
            scanf("%i", &a);
            printf("%i\n", a);
            scanf("%f", &d);
            printf("%f\n", d);
            fflush(stdin);
            c=getchar();
            printf("%c\n", c);

            free(b);
    return 0;
}

