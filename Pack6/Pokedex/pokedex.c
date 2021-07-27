#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Victor Rodrigues da Silva
 * N°USP: 12566140
 * 
 * Atividade de cadastramento de pokemons
 * 
*/

//declaração das structs
typedef struct attribute{
	int hp;
	int attackPoints;
	int defensePoints;
	int specialAttack;
	int specialDefense;
	int speed;
} Attribute;

typedef struct attack{
	char *nome;
	int power;
	float accuracy;
	char class;
} Attack;

typedef struct pokemon{
    char *nome;
    char *primeType;
    char *secType;
    Attribute status;
    Attack attacks[4];
} Pokemon;

//funcao para leitura e alocacao, ps.usei dinamica pq essa funcao ja tava pronta, nao tava escrito que nao podia
char *read_line() {
    int i=0;
    char *line= malloc(sizeof(char));
    fflush(stdin);
    do
    {
        line[i]= getchar();
        if (line[i]=='\n' || line[i]=='\r')
        {
            line[i]='\0';
        }else
        {
            line = realloc(line, (i+2) * sizeof(char));
        }
        i++;
    }while (line[i-1]!='\0');
    return line;
}

int main(int argc, char const *argv[])
{
    int switcher, totalPokemons=-1, i, j;
    int pokeIndex, attackIndex;  
    Pokemon *pokedex;
    pokedex = malloc((totalPokemons+1) * sizeof(Pokemon));

    //repeticao da leitura de comando ate ler 0
    do
    {   
        //seleciona a opcao do usuario
        scanf("%i%*[\r\n]s", &switcher);
        switch (switcher)
        {
        //le um pokemon
        case 1:
            totalPokemons++;
            pokedex = realloc(pokedex, (totalPokemons+1) * sizeof(Pokemon));
            pokedex[totalPokemons].nome = read_line();
            pokedex[totalPokemons].primeType = read_line();
            pokedex[totalPokemons].secType = read_line();
            scanf("%i%*[\r\n]s", &pokedex[totalPokemons].status.hp);
            scanf("%i%*[\r\n]s", &pokedex[totalPokemons].status.attackPoints);
            scanf("%i%*[\r\n]s", &pokedex[totalPokemons].status.defensePoints);
            scanf("%i%*[\r\n]s", &pokedex[totalPokemons].status.specialAttack);
            scanf("%i%*[\r\n]s", &pokedex[totalPokemons].status.specialDefense);
            scanf("%i%*[\r\n]s", &pokedex[totalPokemons].status.speed);
            break;
        //le um ataque relacionado a um pokemon
        case 2:           
            scanf("%i%*[\r\n]s", &pokeIndex);
            scanf("%i%*[\r\n]s", &attackIndex);

            pokedex[pokeIndex].attacks[attackIndex].nome=read_line();
            scanf("%i%*[\r\n]s", &pokedex[pokeIndex].attacks[attackIndex].power);
            //gato para poder ler o char no run.codes
            scanf("%f", &pokedex[pokeIndex].attacks[attackIndex].accuracy);
            getchar();
            pokedex[pokeIndex].attacks[attackIndex].class = getchar();
            break;
        //exibe os dados de um pokemon
        case 3:                       
            scanf("%i%*[\r\n]s", &pokeIndex);

            printf("Nome do Pokemon: %s\n", pokedex[pokeIndex].nome);
            printf("Tipo primario: %s\n", pokedex[pokeIndex].primeType);
            printf("Tipo secundario: %s\n", pokedex[pokeIndex].secType);
            printf("Status:\n");
            printf("\tHP: %d\n", pokedex[pokeIndex].status.hp);
            printf("\tAtaque: %d\n", pokedex[pokeIndex].status.attackPoints);
            printf("\tDefesa: %d\n", pokedex[pokeIndex].status.defensePoints);
            printf("\tAtaque Especial: %d\n", pokedex[pokeIndex].status.specialAttack);
            printf("\tDefesa Especial: %d\n", pokedex[pokeIndex].status.specialDefense);
            printf("\tVelocidade: %d\n\n", pokedex[pokeIndex].status.speed);
            break;
        //exibe os dados de um ataque especial
        case 4:                       
            scanf("%i%*[\r\n]s", &pokeIndex);
            scanf("%i%*[\r\n]s", &attackIndex);

            printf("Nome do Ataque: %s\n", pokedex[pokeIndex].attacks[attackIndex].nome);
            printf("Poder base: %d\n", pokedex[pokeIndex].attacks[attackIndex].power);
            printf("Acuracia: %f\n", pokedex[pokeIndex].attacks[attackIndex].accuracy);
            printf("Classe: %c\n\n", pokedex[pokeIndex].attacks[attackIndex].class);
            break;
        default:
            break;
        }

    } while (switcher!=0);    
    //liberacao de variaveis
    for ( i = 0; i < totalPokemons; i++)
    {
        for ( j = 0; j < 4 ; j++)
        {
            free(pokedex[i].attacks[j].nome);
        }
        free(pokedex[i].nome);
        free(pokedex[i].primeType);
        free(pokedex[i].secType);
    }
    free(pokedex);
    
    return 0;
}
