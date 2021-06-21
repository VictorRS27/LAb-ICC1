#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    int aux=0, i=0, j=0;
    char proibted[12][12]={"gratuito", "atencao", "urgente", "imediato", "zoombie", "oferta", "dinheiro", "renda", "fundo", "limitado", "ajuda", "SOS"}, lineChar[76]={0};
    
    for ( i = 0; i < 20; i++)
    {
        lineChar[i]=getchar();
        //printf("%i", current[i]);
    }

    for ( i = 0; i < 12; i++)
    {
        if(strstr(lineChar, proibted[i])){
        aux++;
    }
    
    }
    printf("%i", aux);
    

    return 0;
}
