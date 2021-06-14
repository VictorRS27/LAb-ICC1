#include <stdio.h>
#include <math.h>

int main()
{
    float a;
    int b;

    scanf("%f", &a);
	scanf("%i", &b);

    printf("%.4f", pow(a,b));
   
    return 0;
}
