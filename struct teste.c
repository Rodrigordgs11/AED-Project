//
//  estrutura.c
//  aulas algoritmia
//
//  Created by Rúben José rodrigues Vicente on 09/12/2021.
//

#include <stdlib.h>
#include <string.h>
#include <locale.h>
 
typedef struct Aluno
{
    int codigo;
    char nome[200];
    float nota;
} Aluno;
 
Aluno aluno_especial;
 
void menu();
void inicializar();
void imprimir();
void cadastrar();
 
int main()
{
    setlocale(LC_ALL,"portuguese");
    menu();
    return 0;
}
 
void menu()
{
    int opcao;
    do
    {
        printf(" \n Opções: ");
        printf(" \n 1. Inicializar a Estrutura" );
        printf(" \n 2. Imprimir a Estrutura" );
        printf(" \n 3. Cadastrar Aluno Especial" );
        printf(" \n 4. Para sair. \n " );
        printf(" \n Digite a opção desejada: ");
        scanf("%d%*c", &opcao);
        switch(opcao)
        {
            case 1:
                inicializar();
            break;
            case 2:
                imprimir();
            break;
            case 3:
                cadastrar();
            break;
            default:
                 printf(" \n Opção não existente. ");
            break;
        }
    }
    while(opcao!=4);
}
 
void inicializar()
{
    aluno_especial.codigo = 0;
    strcpy(aluno_especial.nome, "NULL");
    aluno_especial.nota = 0.0;
}
 
void cadastrar()
{
    printf(" Digite o código do aluno especial: ");
    scanf("%d", &aluno_especial.codigo);
    printf(" Digite o nome do aluno especial: ");
    scanf("%s", &aluno_especial.nome);
    printf(" Digite a nota do aluno especial: ");
    scanf("%f", &aluno_especial.nota);
}
 
void imprimir()
{
    printf(" \n O código do aluno especial é: %d ", aluno_especial.codigo);
    printf(" \n O nome do aluno especial é: %s ", aluno_especial.nome);
    printf(" \n A nota do aluno especial é: %.2f ", aluno_especial.nota);
    printf(" \n \n");
}
