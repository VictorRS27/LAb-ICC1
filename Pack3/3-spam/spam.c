#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    char proibted[12][12]={"gratuito", "atencao", "urgente", "imediato", "zoombie", "oferta", "dinheiro", "renda", "fundo", "limitado", "ajuda", "SOS"};
    char line[77]="";
    int sizeFault=0, wordFault=0, i=0 , aux=0;
    
    do
    {
        for ( i = 0; i < 77; i++)
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
            
        }
        
        
        if (strlen(line)>76 && line[77]!='\n')
        {
            sizeFault++;
        }
        for ( i = 0; i < 12; i++)
        {
            if(strstr(line, proibted[i])){
                wordFault++;
            }
        }
    } while (line[aux]!=EOF);
    
    if (sizeFault>0 || wordFault>1)
    {
        printf("Spam");
    }else 
    {
        printf("Inbox");
    }
    
    
    
    return 0;
}
