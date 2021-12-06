/*--------------------------------------------------*/
/*####             PROGRAMA??O EM C             ####*/
/*--------------------------------------------------*/
/*$$$$ APLICA??O                                $$$$*/
/*$$$$ nome : <nomeAplicacao>.c                 $$$$*/
/*$$$$ autor: <autor>                           $$$$*/
/*--------------------------------------------------*/
/*@@@@ DIRECTIVAS DE INCLUS?O                   @@@@*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

/*@@@@ DIRECTIVAS DE DEFIN??O                   @@@@*/

/*@@@@ VARI?VEIS GLOBAIS                        @@@@*/

/*@@@@ ESTRUTURAS                               @@@@*/

/*@@@@ FUN??ES E PROCEDIMENTOS                  @@@@*/

/*@@@@ FUN??O MAIN                              @@@@*/
int main(void) {
	
    setlocale(LC_ALL, "Portuguese");
    system("COLOR FC");
	
    // DECLARA??O DE VARI?VEIS E DE CONSTANTES
	int nAlunos;
    int nFinalAlunos;
    int nAtualAlunos = 0; 
    int numAluno[30];
    char morada[30][100]; 
    int dataNascimento[30];
    int cc[30][8]; 
    int nif[30][9]; 
    int dataConclusao[30];
    int numeroCarta[30];
    int ativo[30];
    int i;
	int escolhaPrincipal, escolhaAlunos, escolha;
	char aulas[100];

    // SEQU?NCIA L?GICA DE INSTRU??ES

    printf("\n");
    do{
        printf("--------- Menu Principal ---------\n");
        printf(" 1 - Gestão de Alunos\n");
        printf(" 2 - Gestão de Instrutores\n");
        printf(" 3 - Marcação/Consultas de Aulas\n");
        printf(" 0 - Sair\n");
        printf("Resposta: ");
        scanf("%d",&escolhaPrincipal);        
    }while(escolhaPrincipal < 0 || escolhaPrincipal > 3);

    switch (escolhaPrincipal){
    do{
    case 1:
    	printf ("\n");
        system("clear||cls");
        printf("--------- Gestão de Alunos ---------\n");
        printf(" 1 - Gestão de Alunos\n");
        printf(" 2 - Gestão de Instrutores\n");
        printf(" 3 - Marcação/Consultas de Aulas\n");
        printf(" 0 - Sair\n");
        printf("Resposta: ");
        scanf("%d",&escolhaPrincipal);        
    }while(escolhaPrincipal < 0 || escolhaPrincipal > 3);
    break;
    case 2:
    do{
    	printf ("\n");
        system("clear||cls");
        printf("--------- Gestão de Instrutores ---------\n");
        printf(" 1 - Gestão de Alunos\n");
        printf(" 2 - Gestão de Instrutores\n");
        printf(" 3 - Marcação/Consultas de Aulas\n");
        printf(" 0 - Sair\n");
        printf("Resposta: ");
        scanf("%d",&escolhaPrincipal);        
    }while(escolhaPrincipal < 0 || escolhaPrincipal > 3);
    break;
    case 3:
    do{
    	printf ("\n");
        system("clear||cls");
        printf("--------- Marcação/Consultas de Aulas ---------\n");
        printf(" 1 - Gestão de Alunos\n");
        printf(" 2 - Gestão de Instrutores\n");
        printf(" 3 - Marcação/Consultas de Aulas\n");
        printf(" 0 - Sair\n");
        printf("Resposta: ");
        scanf("%d",&escolhaPrincipal);        
    }while(escolhaPrincipal < 0 || escolhaPrincipal > 3);

    break;
    default:
        break;
    }
    switch (escolha){   
    case 1:
	printf ("\n");
    system("clear||cls");
    printf("--------- Gestão de Alunos ---------\n");
    printf ("\nIntroduza o numero de alunos que pretende inserir: ");
    scanf ("%d", &nAlunos);
    nFinalAlunos = nAtualAlunos + nAlunos;

    if (nFinalAlunos > 30){
        printf ("\nAtigiu o numero maximo de alunos");
        /*return ao menu*/
    }else{
        for (i = 0; i < nAlunos; i++){
            printf ("\nIntroduza o numero de aluno");
            scanf ("%d", &numAluno[i]);
            printf ("\nIntroduza a morada (rua, porta, código postal, localidade)");
            scanf (" %30[^\n]s", morada + nAtualAlunos);    
            printf ("\nIntroduza a data de nascimento");
            scanf ("%d", &dataNascimento[i]);
            printf ("\nIntroduza o cartao de cidadao");
            scanf ("%d", &cc[i]);
            printf ("\nIntroduza o NIF");
            scanf ("%d", &nif[i]);
            printf ("\nIntroduza a data de conclusao de carta");
            scanf ("%d", &dataConclusao[i]);
            printf ("\nIntroduza o numero de carta");
            scanf ("%d", &numeroCarta[i]);
            printf ("\nO aluno encontra-se ativo no momento\n1 - SIM\n2 - NAO");
            scanf ("%d", &ativo[i]);
            	if (ativo[i] == 1){
            		printf("");
				}else{
					printf("");
				}
            nAtualAlunos++;
        }	
    }       	    
    break; 
    case 2:
    system("clear||cls");
    printf("--------- Gestão de Alunos ---------\n");
    break;
    default:
    break;
    }
	
    printf("\n\n");
    
    for (i = 0; i < nFinalAlunos; i++){
    	printf ("Aluno %d", numAluno[i]);
	}
}
/*--------------------------------------------------*/
