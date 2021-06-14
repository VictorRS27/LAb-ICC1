#include <stdio.h>

int main()
{
    int a=0, c=0;

    scanf(" %i", &a);

	c= a&4278190080LL;
    printf("%c", c>>24);
    printf("%c", (a&16711680)>>16);
    printf("%c", (a&65280)>>8);
    printf("%c", a&255);

    return 0;
}
