#include <stdio.h>
#include <stdlib.h>

int main()
{
    long long int A1 = 0, razao = 0, N = 0;

    scanf(" %lli %lli %lli", &A1, &razao, &N);
    long long int An = A1 + razao * (N - 1);//, soma = A1 + An, div = N / 2, final = soma * div;
    printf("%lli\n%lli", An, (A1+An) * N / 2);

    return 0;
}
