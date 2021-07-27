#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//struct com os dados dos alunos
typedef struct aluno
{
    long int identificador;
    char *nome;
    char *curso;
    int idade;
} CadAluno;

//função para ler frase
char *read_line()
{
    int i = 0;
    char *line = malloc(sizeof(char));
    do
    {
        line[i] = getchar();
        if (line[i] == '\n' || line[i] == '\r')
        {
            line[i] = '\0';
        }
        else
        {
            line = realloc(line, (i + 2) * sizeof(char));
        }
        i++;
    } while (line[i - 1] != '\0');
    return line;
}

//retorna uma struct para compor o vetor de structs da main
CadAluno cadastrarAlunos(int identificador)
{
    CadAluno tmpAlunoCad;

    getchar();
    tmpAlunoCad.identificador = identificador;
    tmpAlunoCad.nome = read_line();
    tmpAlunoCad.curso = read_line();
    scanf(" %i", &tmpAlunoCad.idade);

    return tmpAlunoCad;
}

//procura por um identificador a ser inserido e printa os dados a relacionados
void searchNum(CadAluno *alunos, int totalAlunos) {
    int i;
    long int query;
    scanf(" %li", &query);
    fflush(stdin);
    for ( i = 0; i < totalAlunos; i++)
    {
        if (alunos[i].identificador==query)
        {
            printf("Nome: %s\nCurso: %s\nN USP: %li\nIDADE: %i\n\n", alunos[i].nome, alunos[i].curso, alunos[i].identificador, alunos[i].idade);
        }
    }
}

//procura por um curso a ser inserido e printa os dados a todos os alunos relacionados
void searchCurso(CadAluno *alunos, int totalAlunos) {
    int i;
    getchar();
    char *query = read_line();

    for ( i = 0; i < totalAlunos; i++)
    {
        if (strstr(alunos[i].curso, query))
        {
            printf("Nome: %s\nCurso: %s\nN USP: %li\nIDADE: %i\n\n", alunos[i].nome, alunos[i].curso, alunos[i].identificador, alunos[i].idade);
        }
    }

    free(query);
}

int main(int argc, char const *argv[])
{
    int i=-1, j=0, operador;
    CadAluno *alunos;

    //cadastramento dos alunos
    do
    {
        i++;
        alunos = realloc(alunos, (i + 1) * sizeof(CadAluno));
        scanf(" %li", &alunos[i].identificador);
        if (alunos[i].identificador != -1)
        {
            alunos[i] = cadastrarAlunos(alunos[i].identificador);
        }        
    } while (alunos[i].identificador != -1);
    
    //direcionamento e processamento
    do
    {
        scanf(" %i", &operador);

        switch (operador)
        {
        case 1:
            searchNum(alunos, i);
            break;
        
        case 2:
            searchCurso(alunos, i);
            break;

        case 3:
            for ( j = 0; j < i; j++)
            {
                printf("Nome: %s\nCurso: %s\nN USP: %li\nIDADE: %i\n\n", alunos[j].nome, alunos[j].curso, alunos[j].identificador, alunos[j].idade);
            }
            break;
        
        default:
            break;
        }
    } while (operador!=-1);

    //libera as variaveis alocadas dinamicamente na struct e a propria struct
    for ( j = 0; j < i; j++)
    {
        free(alunos[j].nome);
        free(alunos[j].curso);
    }
    free(alunos);
    
    return 0;
}
