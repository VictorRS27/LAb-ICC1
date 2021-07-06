#include <stdio.h>
#include <stdlib.h>

void atualization( int **matriz){
    int copy[32][64], i, j;
    for ( i = 0; i < 32; i++)
    {
        for ( j = 0; j < 64; j++)
        {
            copy[i][j] = matriz[i][j];
        }
        
    }
    for ( i = 0; i < 32; i++)
    {
        for ( j = 0; j < 64; j++)
        {
            if (copy[i][j]=='#') 
            {
                if (copy[i+1][j]==' ' || copy[i+1][j]=='~' )
                {
                    matriz[i+1][j]=copy[i][j];
                    matriz[i][j] = copy[i+1][j];
                }else if ( j > 0 && (copy[i+1][j-1]==' ' || copy[i+1][j-1]=='~' ))
                {
                    matriz[i+1][j-1]=copy[i][j];
                    matriz[i][j] = copy[i+1][j-1];
                }else if ( j < 64 && (copy[i+1][j+1]==' ' || copy[i+1][j+1]=='~' ))
                {
                    matriz[i+1][j+1]=copy[i][j];
                    matriz[i][j] = copy[i+1][j+1];
                }
            }
            if (copy[i][j]=='~') 
            {
                if (copy[i+1][j]==' ')
                {
                    matriz[i+1][j]=copy[i][j];
                    matriz[i][j] = copy[i+1][j];
                }else if ( j > 0 && copy[i+1][j-1]==' ' )
                {
                    matriz[i+1][j-1]=copy[i][j];
                    matriz[i][j] = copy[i+1][j-1];
                }else if ( j < 64 && copy[i+1][j+1]==' ')
                {
                    matriz[i+1][j+1]=copy[i][j];
                    matriz[i][j] = copy[i+1][j+1];
                }
            }
            
        }
        
    }
}

int main(int argc, char const *argv[])
{
    int totalFrames, frame, x, y, matriz[32][64]={0}, j, i;
    char nova_particula;

scanf("%d", &totalFrames);

int counter = 0;
while (counter < totalFrames) {

        int endVerifier = scanf(" %d: %d %d %c", &frame, &x, &y, &nova_particula);

        if (endVerifier == EOF) {
                frame = totalFrames;
        }
        
        while (counter < frame) {
                printf("frame: %d\n", counter + 1);
                for ( i = 0; i < 32; i++)
                {
                    for ( j = 0; j < 64; j++)
                    {
                        printf("%c", matriz[i][j]);
                    }
                    
                }
                atualization(matriz);
                counter++;
        }

        if (endVerifier != EOF) {
                matriz[y][x] = nova_particula;
        }
}
    return 0;
}
