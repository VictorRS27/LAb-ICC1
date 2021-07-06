#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
    1 real      -> coins[0]
    50 cents    -> coins[1]
    25 cents    -> coins[2]
    10 cents    -> coins[3]
    5 cents     -> coins[4]
    1 cent      -> coins[5]
*/
//tecnicamente vetores sao passados por refenrencia, então vale. (pf n desconsidera minha preguiça)
void calculo( int *coins, int troco){
    coins[0]= troco/100;
    troco= troco%100;
    coins[1]= troco/50;
    troco= troco%50;
    coins[2]= troco/25;
    troco= troco%25;
    coins[3]= troco/10;
    troco= troco%10;
    coins[4]= troco/5;
    troco= troco%5;
    coins[5]= troco;
}

int main(int argc, char const *argv[])
{
    
    int coins[6], troco;

    scanf(" %d", &troco);

    calculo(coins, troco);

    printf("O valor consiste em %d moedas de 1 real\n", coins[0]);
    printf("O valor consiste em %d moedas de 50 centavos\n", coins[1]);
    printf("O valor consiste em %d moedas de 25 centavos\n", coins[2]);
    printf("O valor consiste em %d moedas de 10 centavos\n", coins[3]);
    printf("O valor consiste em %d moedas de 5 centavos\n", coins[4]);
    printf("O valor consiste em %d moedas de 1 centavo\n", coins[5]);


    return 0;
}
