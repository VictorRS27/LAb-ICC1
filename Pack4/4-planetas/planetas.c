#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//o conversor é o valor em minutos de um dia em cada planeta, assim, sabe-se o numero de dias direto dos minutos
void temporize( int *days, int *hours, long long int *minutes, long long int *seconds, long long int conversor){
    *minutes = *seconds/60;
    *seconds= *seconds%60;
    *days = *minutes/conversor;
    *minutes = *minutes%conversor;
    *hours = *minutes/60;
    *minutes = *minutes%60;
}

int main(int argc, char const *argv[])
{
    int days, hours;
    long long int minutes, seconds, travel;
    char planet[10];

    scanf(" %llu %s", &travel, planet);
    seconds=travel;

    switch (planet[0])
    {
    case 'T':
        temporize(&days, &hours, &minutes, &seconds, 1440);
        break;
    case 'V':
        temporize(&days, &hours, &minutes, &seconds, 349920);
        break;
    case 'M':
        temporize(&days, &hours, &minutes, &seconds, 84480);
        break;
    case 'J':
        temporize(&days, &hours, &minutes, &seconds, 596);
        break;
    
    default:
        break;
    }

    printf("%llu segundos no planeta %s equivalem a:\n%i dias, %i horas, %llu minutos e %llu segundos\n", travel, planet, days, hours, minutes, seconds);

    
    return 0;
}
