#include <stdio.h>
#include <stdlib.h>


int main()
{
    float a=0, b=0;
    char op=0;

    scanf(" %f %c %f", &a, &op, &b);

    switch (op)
    {
    case '+':
        printf("%.6f", a+b);
        break;
    
    case '-':
        printf("%.6f", a-b);
        break;

    case '*':
        printf("%.6f", a*b);
        break;

    case '/':
        printf("%.6f", a/b);
        break;

    case '%':
        printf("%.6f", (a/100)/(b/100)*100);
        break;
    default:
        break;
    }

    return 0;
}
