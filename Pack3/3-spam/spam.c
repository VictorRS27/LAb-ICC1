#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char const *argv[])
{
    char proibted[12][12]={"gratuito", "atencao", "urgente", "imediato", "zoombie", "oferta", "dinheiro", "renda", "fundo", "limitado", "ajuda", "SOS"}, lineChar[76]={0};
    int lineInt[76]={0}, sizeFault=0, wordFault=0, i=0, j=0;
    
    do
    {
        i=0;
        do
        {
            lineInt[i]=getchar();
            lineChar[i]= lineInt[i];
            i++;
        } while (lineInt[i-1]!= 10 && lineInt[i-1]!=EOF);
        
        if (i>77 )
        {
            sizeFault++;
            break;
        }

        for ( j = 0; j < 12; j++)
        {
            if(strstr(lineChar, proibted[j])){
            wordFault++;
            }
        }

    } while (lineInt[i-1]!=EOF);
    
    
    
    if (sizeFault>0 || wordFault>1)
    {
        printf("Spam");
    }else 
    {
        printf("Inbox");
    }
    
    return 0;
}
/*for ( i = 0; i < 77; i++)
        {
            line[i]=getchar();
            if (line[i]=='\n')
            {
                i=77;
            }
            
            if (line[i]==EOF)
            {
                aux= i;
            }
            
        }*/