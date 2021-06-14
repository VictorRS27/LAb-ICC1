#include <stdio.h>
#include <stdlib.h>

#define MIN(X, Y) (((X) < (Y)) ? (X) : (Y))

int main()
{
    double a=0, b=0, c=0, d=0;

    scanf(" %lf %lf %lf %lf", &a, &b, &c, &d);
    //printf("%.4lf %.4lf %.4lf %.4lf", a, b, c, d);
    printf("%.4lf", (a+b+c+d-MIN(MIN(a,b),MIN(c,d)))/3);

    return 0;
}
