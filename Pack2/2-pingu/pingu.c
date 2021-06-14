#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n = 0, m = 0, p = 0, i = 0, j = 1, counter = 1;

    scanf(" %i %i %i", &n, &m, &p);
    
    /*while (j<counter*3)
    {
        if (j>n)
        {
            exit(0);
        }
        
        if (p==j%m)
        {
            if (j <= counter)
            {
                if (counter == 1)
                {
                    printf("%i pinguim\n", counter);
                }
                else
                {
                    printf("%i pinguins\n", counter);
                }
            }
            else if (j <= counter * 2)
            {
                printf("no gelo\n");
            }
            else if (j <= counter * 3)
            {
                printf("uhuu!\n");
            }
        }
    }*/
    

    while (j <= n)
    {
        for (i = 1; i <= counter * 3; i++)
        {
            
            if (j > n)
            {
                exit(0);
            }
            if (p % m == j % m)
            {
                if (i <= counter)
                {
                    if (counter == 1)
                    {
                        printf("%i pinguim\n", counter);
                    }
                    else
                    {
                        printf("%i pinguins\n", counter);
                    }
                }
                else if (i <= counter * 2)
                {
                    printf("no gelo\n");
                }
                else if (i <= counter * 3)
                {
                    printf("uhuu!\n");
                }
            }
            j++;
        }
        counter++;
    }

    return 0;
}
