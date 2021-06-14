#include <stdio.h>
#include <stdlib.h>

int main()
{
    char entrada[6]={}; 
    int x=0, y=0, i=0;



    for (i = 0; i < 6; i++)
    {
        entrada[i]=getchar();
        switch (entrada[i])
        {
        case 'W':
            y++;
            break;

        case 'S':
            y--;
            break;

        case 'A':
            x--;
            break;

        case 'D':
            x++;
            break;
        
        default:
            break;
        }
    }
    
    printf("%i %i\n", x, y);
    return 0;
}
