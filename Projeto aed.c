	  
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
  typedef struct Aluno{
    	//VARIAVEIS ALUNOS
	    int numAluno[30];
	    char nomeAluno[30][30];
	    char morada[30][100]; 
	    char dataNascimento[30][8];
	    int ccAluno[30][8]; 
	    int nif[30][9]; 
	    int dataConclusao[30];
	    int numeroCarta[30];
	    int ativoAluno[30];	
	} Aluno;
	
	 typedef struct Instrutores{
    	char nomeInstrutor[10][30];
		char ccInstrutor[10][8];
		char emailInstrutor[10][30];
		char anoEntrada[10][8];
	 	int ativoInstrutor[10];
	} Instrutores;
	
  	Aluno aluno_x;
  	Instrutores instrutores_x;
/*@@@@ FUN??ES E PROCEDIMENTOS                  @@@@*/

/*@@@@ FUN??O MAIN                              @@@@*/
int main(void) {
	
    setlocale(LC_ALL, "Portuguese");
    system("COLOR FC");
	
    // DECLARA??O DE VARI?VEIS E DE CONSTANTES
    int escolhaPrincipal;
    
    
	//VARIAVEIS INSTRUTORES 
	int resInstrutores;
	int nInstrutores, nAtualInstrutores = 0, nFinalInstrutores; 
	int escolhaInstrutores;
	
	int i;
	int resAlunos;
	
	//VARIAVEIS MARCAÇÃO
	int resMarcacao;
	char aulas[100];
	int escolhaMarcacao;
	int escolhaAlunos;
	int nAlunos, nFinalAlunos, nAtualAlunos = 0; 
	

    // SEQU?NCIA L?GICA DE INSTRU??ES      
    do{
    	
	
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
    case 1:
    	do{
        	system("clear||cls");
        	printf ("\n");
        	printf("--------- Gestão de Alunos ---------\n");
        	printf(" 1 - Inserir Alunos\n");
        	printf(" 2 - Listagem Alunos\n");
        	/*printf(" 3 - Marcação/Consultas de Aulas\n");*/
        	printf(" 0 - Sair\n");
        	printf("Resposta: ");
        	scanf("%d",&escolhaAlunos);        
    	}while(escolhaAlunos < 0 || escolhaAlunos > 3);
    break;
    case 2:
    	do{
    		printf ("\n");
        	system("clear||cls");
        	printf("--------- Gestão de Instrutores ---------\n");
        	printf(" 1 - Inserir Instrutores\n");
        	printf(" 2 - Listagem Instrutores\n");
        	/*printf(" 3 - Marcação/Consultas de Aulas\n");*/
        	printf(" 0 - Sair\n");
        	printf("Resposta: ");
        	scanf("%d",&escolhaInstrutores);        
    	}while(escolhaInstrutores < 0 || escolhaInstrutores > 3);
    break;
    case 3:
    	do{
    		printf ("\n");
        	system("clear||cls");
        	printf("--------- Marcação/Consultas de Aulas ---------\n");
        	printf(" 1 - Inserir Marcação\n");
        	printf(" 2 - Listagem Marcação\n");
        	printf(" 3 - Marcação/Consultas de Aulas\n");
        	printf(" 0 - Sair\n");
        	printf("Resposta: ");
        	scanf("%d",&escolhaMarcacao);        
    	}while(escolhaMarcacao < 0 || escolhaMarcacao > 3);
    break;
    case 0:
    	system("clear||cls");
    	printf("\nA fechar o programa..");
    	sleep(1);
    break;
    }
    
    switch (escolhaAlunos){   
    case 1:
    	do{
		system("clear||cls");
    	printf ("\n");
		printf("--------- INSERIR ALUNOS ---------\n");
    	printf ("\nIntroduza o número de alunos que pretende inserir: ");
    	scanf ("%d", &nAlunos);
    	nFinalAlunos = nAtualAlunos + nAlunos;
    		if (nFinalAlunos > 30){
        		printf ("\nAtigiu o número maximo de alunos");
        		/*return ao menu*/
    		}else{
        		for (i = 0; i < nAlunos; i++){
           			printf("\nIntroduza o número do aluno");
            		scanf("%d", &aluno_x.numAluno);
            		printf("\nIntroduza o nome do aluno");
            		scanf(" %30[^\n]s", aluno_x.nomeAluno + nAtualAlunos);
            		printf("\nIntroduza a morada (rua, porta, código postal, localidade)");
            		scanf(" %30[^\n]s", aluno_x.morada + nAtualAlunos);    
            		printf("\nIntroduza a data de nascimento");
            		scanf("%d", &aluno_x.dataNascimento);
            		printf("\nIntroduza o cartao de cidadao");
            		scanf("%d", &aluno_x.ccAluno);
            		printf("\nIntroduza o NIF");
            		scanf("%d", &aluno_x.nif);
            		printf("\nIntroduza a data de conclusao de carta");
            		scanf("%d", &aluno_x.dataConclusao);
            		printf("\nIntroduza o numero de carta");
            		scanf("%d", &aluno_x.numeroCarta);
            		printf("\nO aluno encontra-se ativo no momento\n1 - SIM\n2 - NAO");
            		scanf("%d", &aluno_x.ativoAluno);
    				nAtualAlunos++;
    			}	
    		}
		}while(escolhaAlunos < 0 || escolhaInstrutores > 3);	       	    
    break; 
    case 2:
    	printf("\n");
    	system("clear||cls");
    	printf("--------- LISTAGEM DE ALUNOS ---------\n");
    		for (i = 0; i < nFinalAlunos; i++){
    			printf ("Aluno %d", aluno_x.numAluno);
			}
    break;
    /*case 0:
    	printf("Pretende recuar para o menu principal\n1 - Sim\n2 - Não");
    	scanf("%d", &resAlunos);
    	if (resAlunos == 1){
    	return menu principal*//*
    	}else{
    		system("clear||cls");
    		printf("\nA fechar o programa..");
    		sleep(1);	
		}
    break;*/
    }
    
    switch (escolhaInstrutores){
    case 1:
    	system("clear||cls");
    	printf ("\n");
		printf("--------- INSERIR INSTRUTORES ---------\n");
    	printf ("\nIntroduza o numero de instrutores que pretende inserir: ");
    	scanf ("%d", &nInstrutores);
    	nFinalInstrutores = nAtualInstrutores + nInstrutores;
    		if (nFinalInstrutores > 10){
        		printf ("\nAtigiu o numero maximo de instrutores");
        		/*return ao menu*/
    		}else{
        		for (i = 0; i < nInstrutores; i++){
            		printf("\nIntroduza o nome do instrutor");
            		scanf(" %10[^\n]s", instrutores_x.nomeInstrutor + nAtualInstrutores);
            		printf("\nIntroduza número do cartão de cidadão");
            		scanf(" %10[^\n]s", instrutores_x.ccInstrutor + nAtualInstrutores);    
            		printf("\nIntroduza o email");
            		scanf(" %10[^\n]s", instrutores_x.emailInstrutor + nAtualInstrutores);
            		printf("\nIntroduza o ano de entrada na escola de condução");
            		scanf(" %10[^\n]s", instrutores_x.anoEntrada + nAtualInstrutores);
            		printf("\nO instrutor encontra-se ativo no momento\n1 - SIM\n2 - NAO");
            		scanf("%d", &instrutores_x.ativoInstrutor);
    				nAtualInstrutores++;
    			}	
    		}       
    break;
    case 2:
    //listar instrutores
    
    break;
    /*case 0:
    	printf("Pretende recuar para o menu principal\n1 - Sim\n2 - Não");
    	scanf("%d", &resInstrutores);
    	if (resAlunos == 1){
    	return menu principal*//*
    	}else{
    		system("clear||cls");
    		printf("\nA fechar o programa..");
    		sleep(1);	
		}
    break;*/
	}
	switch (escolhaMarcacao){
    /*case 1:
    	system("clear||cls");
    	printf ("\n");
		printf("--------- INSERIR MARCAÇÕES ---------\n");
    	printf ("\nIntroduza o numero de instrutores que pretende inserir: ");
    	scanf ("%d", &nInstrutores);
    	nFinalInstrutores = nAtualInstrutores + nInstrutores;
    		if (nFinalAlunos > 30){
        		printf ("\nAtigiu o numero maximo de alunos");
        		return ao menu*//*
    		}else{
        		for (i = 0; i < nAlunos; i++){
           			printf("\nIntroduza o numero de aluno");
            		scanf("%d", &numAluno[i]);
            		printf("\nIntroduza a morada (rua, porta, código postal, localidade)");
            		scanf(" %30[^\n]s", morada + nAtualAlunos);    
            		printf("\nIntroduza a data de nascimento");
            		scanf("%d", &dataNascimento[i]);
            		printf("\nIntroduza o cartao de cidadao");
            		scanf("%d", &cc[i]);
            		printf("\nIntroduza o NIF");
            		scanf("%d", &nif[i]);
            		printf("\nIntroduza a data de conclusao de carta");
            		scanf("%d", &dataConclusao[i]);
            		printf("\nIntroduza o numero de carta");
            		scanf("%d", &numeroCarta[i]);
            		printf("\nO aluno encontra-se ativo no momento\n1 - SIM\n2 - NAO");
            		scanf("%d", &ativo[i]);
    				nAtualAlunos++;
    			}	
    		}       
    break;
    case 2:
    //listar MARCAçÕES
    break;
    /*case 0:
    	printf("Pretende recuar para o menu principal\n1 - Sim\n2 - Não");
    	scanf("%d", &resMarcacao);
    	if (resAlunos == 1){
    	return menu principal*//*
    	}else{
    		system("clear||cls");
    		printf("\nA fechar o programa..");
    		sleep(1);	
		}
    break;*/
	}
    printf("\n\n");
    }while(escolhaPrincipal != 0);
}
/*--------------------------------------------------*/
