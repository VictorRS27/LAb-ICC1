#include <stdio.h>
#include <stdlib.h>



int main(int argc, char const *argv[])
{
    char table[3][3]={0};
    int i=0, j=0;

    for ( i = 0; i < 3; i++)
    {
        for ( j = 0; j < 3; j++)
        {
            scanf(" %c", &table[i][j]);
        }
    }

    if (table[1][1]!='-' && ((table[0][0]==table[1][1] && table[2][2]==table[1][1]) || (table[1][1]==table[0][2] && table[1][1]==table[2][0])) )
    {
        printf("%c ganhou", table[1][1]);
    }else
    {
        for ( i = 0; i < 3; i++)
        {
            if (table[i][1]!='-' && table[i][1]==table[i][2] && table[i][0]==table[i][2])
            {
                printf("%c ganhou", table[i][0]);
                exit(0);
            }else if (table[i][1]!='-' && table[0][i]==table[1][i] && table[0][i]==table[2][i])
            {
                printf("%c ganhou", table[0][i]);
                exit(0);
            }else if (i==2)
            {
                for ( i = 0; i < 3; i++)
                {
                    for ( j = 0; j < 3; j++)
                    {
                        if (table[i][j]=='-')
                        {
                            printf("em jogo");
                            exit(0);
                        }else if (i==2 && j==2)
                        {
                            printf("empate");
                        }                        
                    }
                }                                                
            }                      
        }
    }   
    
    return 0;
}
