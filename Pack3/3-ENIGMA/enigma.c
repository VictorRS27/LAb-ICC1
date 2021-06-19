#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    int rotor1[26]={0}, rotor2[26]={0}, rotor3[26]={0}, i=0, aux=0;

    for ( i = 0; i < 26; i++)
    {
        scanf("%i", rotor1[i]);
    }
    for ( i = 0; i < 26; i++)
    {
        scanf("%i", rotor2[i]);
    }
    for ( i = 0; i < 26; i++)
    {
        scanf("%i", rotor2[i]);
    }
    scanf("%*[^\r\n]s"); // Ignora tudo até o final da linha
    scanf("%*[\r\n]s"); // Ignora o pula linha

    

    
    return 0;
}
