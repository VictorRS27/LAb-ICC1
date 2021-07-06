#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TOTAL 10

int maior( int valorBruto[TOTAL]){
    int i, max;
    for ( i = 0; i < TOTAL; i++)
    {
        if (max<valorBruto[i])
        {
            max=valorBruto[i];
        }
        
    }
    return  max;
}

int menor( int valorBruto[TOTAL]){
    int i, min;
    for ( i = 0; i < TOTAL; i++)
    {
        if (min>valorBruto[i])
        {
            min=valorBruto[i];
        }
        
    }
    return  min;
}

float media( int valorBruto[TOTAL]){
    int i;
    float media = 0;
    for ( i = 0; i < TOTAL; i++)
    {
        media+=valorBruto[i];
    }
    media = media/i;
    return  media;
}

int moda( int valorBruto[TOTAL]){
    int i, j, moda = 0, ocorrencias=0, max=0;
    for ( i = 0; i < TOTAL; i++)
    {
        ocorrencias=0;
        for ( j = i; j < TOTAL; j++)
        {
            if (valorBruto[i]==valorBruto[j])
            {
                ocorrencias++;
            }
        }
        if (ocorrencias > max)
        {
            moda=i;
            max=ocorrencias;
        }
        
            
        
    }
    return  valorBruto[moda];
}

int main(int argc, char const *argv[])
{
    int valorBruto[TOTAL]={0}, i=0;

    for ( i = 0; i < TOTAL; i++)
    {
        scanf(" %i", &valorBruto[i]);
    }

    printf("%i %i %.2f %i", maior(valorBruto), menor(valorBruto), media(valorBruto), moda(valorBruto));
    
    return 0;
}
