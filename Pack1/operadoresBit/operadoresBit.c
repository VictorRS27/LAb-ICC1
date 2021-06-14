#include <stdio.h>
#include <stdlib.h>

int main()
{
    int unsigned a=0, b=0;

    scanf(" %i", &a);
    scanf(" %i", &b);
	
	printf("%i\n", a&b);
	printf("%i\n", a|b);
	printf("%i\n", a^b);
	printf("%i\n", ~a);
	printf("%i\n", ~b);
	printf("%i\n", a>>2);
	printf("%i\n", b<<2);

}
