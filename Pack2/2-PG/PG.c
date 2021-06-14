#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    float A1 = 0, Q = 0;
    int N = 0;

    scanf(" %f %f %i", &A1, &Q, &N);
    //long long int An = A1 + razao * (N - 1);//, soma = A1 + An, div = N / 2, final = soma * div;
    printf("%.2f\n%.2f", A1*pow(Q, (N-1)), A1*(pow(Q, N)-1)/(Q-1));

    return 0;
}