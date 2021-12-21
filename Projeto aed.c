//INSTRUTOR ALTERAÇÃO DADOS 2 INT, MORADA SPLIT MAIS DE 30 CARATERES DA ERRO

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <locale.h>
typedef struct Morada{
	char DadosMorada[30][30];
    char rua[30][30];
    char porta[30][30];
    char codigoPostal[30][8];
    char localidade[30][30];
} Morada;

typedef struct DataNascimento{
    int aaaa;
    int mm;
    int dd;
} DataNascimento;

typedef struct DataConclusao{
    int aaaa;
    int mm;
    int dd;
} DataConclusao;

typedef struct Aluno{
    //VARIAVEIS ALUNOS
    Morada morada;
    int numAluno;
    char nomeAluno[30][30];
    DataNascimento dataNascimento;
    int ccAluno;
    int nif;
    DataConclusao dataConclusao;
    int numeroCarta;
    int ativoAluno;
} Aluno;
   
    typedef struct Instrutores{
    int numInstrutor;
    char nomeInstrutor[10][30];
    char ccInstrutor[10][9];
    char emailInstrutor[10][30];
    char anoEntrada[10][10];
	int ativoInstrutor;
} Instrutores;

Aluno aluno_x[30];
Instrutores instrutores_x[10];

/*@@@@ FUN??ES E PROCEDIMENTOS                  @@@@*/

// 			OUTRAS FUNÇÕES

void limpaEcra();

// 			MENUS 	

void Menu();
int MenuPrincipal();
int MenuAlunos();
int MenuInstrutores();
int MenuConsulta();
int MenuListarAlunos();

//			FUNÇÕES ALUNOS 	
	
void InserirAlunos();
void DadosAlunos();
void alterarAluno();
void listaAtivosAlunos();
void listaCartaConducaoAlunos();
void listaMais18AnosAlunos();
void verificacaoCCAluno();
void verificacaoNIFAluno();
void verificacaoCartaConducaoAluno();

//			FUNÇÕES INSTRUTORES 

void InserirInstrutores();
void DadosInstrutores();
void alterarInstrutor();
void verificacaoCCInstrutor();
void verificacaoEmailInstrutor();


//			FUNÇÕES MARCAÇÕES

void MarcacaoAula();
void subMenu3_esc2();



/* variaveis*/
int flag = 0;
char dividir[] = ",";
char idk[30][70];
char DadosMorada[30][30];

// 			SPLIT MORADA

size_t divMoradaAluno(char *idk, char *dividir){

  char *ptrMorada;
  ptrMorada = strtok (idk,dividir); 		//a morada é dividida por virgulas e guarda no apontador ptrMorada
  int i = 0;
  while (ptrMorada!= NULL){				//enquanto houver virgulas para partir ele parte quando a frase acaba da return 
    strcpy(DadosMorada[++i], ptrMorada);
    ptrMorada = strtok (NULL, dividir);
  }
  return 0;
}


// DECLARA??O DE VARI?VEIS E DE CONSTANTES
int escolhaPrincipal;
//VARIAVEIS INSTRUTORES
int resInstrutores;
int nInstrutores, nAtualInstrutores = 0, nFinalInstrutores;
int escolhaInstrutores;
int i,j;
int resAlunos,respConcluCarta;
//VARIAVEIS MARCAÇÃO
int resMarcacao;
char aulas[100];
int escolhaMarcacao;
int escolhaAlunos;
int escolhaListaAlunos;
int nAlunos, nFinalAlunos, nAtualAlunos = 0;


/*@@@@ 					FUN??O MAIN                		 @@@@*/
int main(void) {
	setlocale(LC_ALL, "Portuguese");
	system("COLOR FC");
	Menu();
}

/*-------------------------Funçoes-------------------------*/

//EM FALTA,  
void Menu(){
    do{
    	printf("\n");
		switch (MenuPrincipal()){
		case 1:
			limpaEcra();
	    	switch (MenuAlunos()){
	    	case 1:
	        	limpaEcra();
	        	InserirAlunos();
		    break;
			case 2:
		    	limpaEcra();
		    	switch(MenuListarAlunos()){
		    	limpaEcra();
			    case 1:
			    	limpaEcra();
			        DadosAlunos();	
			  	break;
			    case 2:
			    	limpaEcra();
			        listaAtivosAlunos();	
			    break;
			    case 3:
			    	limpaEcra();
			        listaCartaConducaoAlunos();	
			  	break;
			    case 4:
			    	limpaEcra();
			        DadosAlunos();	
			    break;
			    case 0:
	        		limpaEcra();
   				break;
				}		        	
	    	break;
			case 3:
		    	limpaEcra();
		    	alterarAluno();
			break;
			case 0:
        		limpaEcra();
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
		break;
    	case 2:
	    	limpaEcra();
		    switch (MenuInstrutores()){
		    case 1:
				limpaEcra();
		        InserirInstrutores();
		    break;
		    case 2:
		    	limpaEcra();
		        DadosInstrutores();  
		    break;
		    case 3:
		    	alterarInstrutor();
		    break;
		    case 0:
        		limpaEcra();
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
	    break;
    	case 3:
    		limpaEcra();
	    	switch (MenuConsulta()){
		    case 1:
		        MarcacaoAula();
		    break;
		    case 2:
		    //listar MARCAçÕES
		        limpaEcra();
		        subMenu3_esc2();
		    break;
		    case 0:
        		limpaEcra();
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
	    break;
   		case 0:
        	limpaEcra();
        	printf("\nA fechar o programa..");
        	sleep(1);
   		break;
    	}
    printf("\n\n");
    }while(escolhaPrincipal != 0);
}

int MenuPrincipal(){
	do{
		printf("--------- Menu Principal ---------\n");
		printf(" 1 - Gestão de Alunos\n");
		printf(" 2 - Gestão de Instrutores\n");
		printf(" 3 - Marcação/Consultas de Aulas\n");
		printf(" 0 - Sair\n");
		printf("Resposta: ");
		scanf("%d",&escolhaPrincipal);
	}while(escolhaPrincipal < 0 || escolhaPrincipal > 3);
	return escolhaPrincipal;
}

int MenuAlunos(){
    do{
       printf("--------- Gestão de Alunos ---------\n");
        printf(" 1 - Inserir Alunos\n");
        printf(" 2 - Listagem Alunos\n");
        printf(" 3 - Alteração De Dados Aluno\n");
        /*printf(" 4 - Marcação/Consultas de Aulas\n");*/
        printf(" 0 - Sair\n");
        printf("Resposta: ");
        scanf("%d",&escolhaAlunos);
    }while(escolhaAlunos < 0 || escolhaAlunos > 4);
    return escolhaAlunos;
}

int MenuInstrutores(){
    do{
        printf("--------- Gestão de Instrutores ---------\n");
        printf(" 1 - Inserir Instrutores\n");
        printf(" 2 - Listagem Instrutores\n");
        printf(" 3 - Alteração De Dados Instrutor\n");
        /*printf(" 3 - Marcação/Consultas de Aulas\n");*/
        printf(" 0 - Sair\n");
        printf("Resposta: ");
        scanf("%d",&escolhaInstrutores);
    }while(escolhaInstrutores < 0 || escolhaInstrutores > 4);
    return escolhaInstrutores;
}

int MenuConsulta(){
    do{
        printf("--------- Marcação/Consultas de Aulas ---------\n");
        printf(" 1 - Inserir Marcação\n");
        printf(" 2 - Listagem Marcação\n");
        printf(" 3 - Marcação/Consultas de Aulas\n");
        printf(" 0 - Sair\n");
        printf("Resposta: ");
        scanf("%d",&escolhaMarcacao);
    }while(escolhaMarcacao < 0 || escolhaMarcacao > 3);
    return escolhaMarcacao;
}

int MenuListarAlunos(){
	do{
        printf("--------- Listagem De Alunos ---------\n");
        printf(" 1 - Listar Todos Os Alunos\n");
        printf(" 2 - Listar Alunos Ativos\n");
        printf(" 3 - Listar Alunos Com Carta De Condução\n");
        printf(" 4 - Listar Alunos Com Mais/Menos de 18 Anos\n");
        printf(" 0 - Sair\n");
        printf("Resposta: ");
        scanf("%d",&escolhaListaAlunos);
    }while(escolhaListaAlunos < 0 || escolhaListaAlunos > 4);
    return escolhaListaAlunos;
}

void InserirAlunos(){
    printf("--------- INSERIR ALUNOS ---------\n");
    printf ("\nIntroduza o número de alunos que pretende inserir: ");
    scanf ("%d", &nAlunos);
    nFinalAlunos = nAtualAlunos + nAlunos;
    if (nFinalAlunos > 30){
        printf ("\nSó podem existir no maximo 30 alunos");
        limpaEcra();
    }else{
        for (i = nAtualAlunos; i < nFinalAlunos; i++){
            limpaEcra();
            printf("--------- INSERIR ALUNOS ---------\n");
            printf("\nIntroduza o nome do aluno: ");
            scanf(" %30[^\n]s", &aluno_x[i].nomeAluno);
            printf("\nIntroduza a morada (rua, porta, código postal, localidade): ");
            scanf(" %30[^\n]s", idk);
            size_t final = divMoradaAluno (idk, dividir);

            strcpy(&aluno_x[i].morada.rua, &DadosMorada[1][0]);		//copia a 1 parcela do array para o vetor rua 
            strcpy(&aluno_x[i].morada.porta, &DadosMorada[2][0]);		//copia a 2 parcela do array para o vetor porta 
            strcpy(&aluno_x[i].morada.codigoPostal, &DadosMorada[3][0]);	//copia a 3 parcela do array para o vetor codigoPostal 
            strcpy(&aluno_x[i].morada.localidade, &DadosMorada[4][0]);	//copia a 4 parcela do array para o vetor localidade 

            /*printf("\nIntroduza a rua: ");
            scanf(" %30[^\n]s", &aluno_x[i].morada.rua);
            printf("\nIntroduza a porta: ");
            scanf(" %30[^\n]s", &aluno_x[i].morada.porta);
            printf("\nIntroduza a código postal: ");
            scanf(" %30[^\n]s", &aluno_x[i].morada.codigoPostal);
            printf("\nIntroduza a localidade: ");
            scanf(" %30[^\n]s", &aluno_x[i].morada.localidade);*/
            
            printf("\nIntroduza a data de nascimento no seguinte formato (dd/mm/aaaa): ");
            scanf("%d/%d/%d",&aluno_x[i].dataNascimento.dd,&aluno_x[i].dataNascimento.mm,&aluno_x[i].dataNascimento.aaaa);
            printf("\nIntroduza o cartão de cidadão: ");
            scanf("%d", &aluno_x[i].ccAluno);
            verificacaoCCAluno();
            printf("\nIntroduza o NIF: ");
            scanf("%d", &aluno_x[i].nif);
            verificacaoNIFAluno();
            do{
                printf("\nO aluno %s ja concluiu a carta de condução?\n1- Sim\n2- Não\nR:. ",aluno_x[i].nomeAluno);
                scanf("%d",&respConcluCarta);
                	if(respConcluCarta == 1){
	                    printf("\nIntroduza a data de conclusão de carta no seguinte formato (dd/mm/aaaa): ");
	                    scanf("%d/%d/%d",&aluno_x[i].dataConclusao.dd,&aluno_x[i].dataConclusao.mm,&aluno_x[i].dataConclusao.aaaa);
	                    printf("\nIntroduza o número de carta: ");
	                    scanf("%d", &aluno_x[i].numeroCarta);
	                    verificacaoCartaConducaoAluno();
	                    aluno_x[i].ativoAluno = 0;
	                break;
                	}else if(respConcluCarta == 2){
	                    printf("\nO aluno encontra-se ativo no momento\n1 - SIM\n2 - NÃO\nR:. ");
	                    scanf("%d", &aluno_x[i].ativoAluno);
                    break;
	                }else if(respConcluCarta != 1 || respConcluCarta != 2){
	                    limpaEcra();
	                    printf("Introduza uma opção Valida");
	                    limpaEcra();
	                }
            }while(respConcluCarta != 1 || respConcluCarta != 2);
            aluno_x[i].numAluno = nAtualAlunos + 1;
            nAtualAlunos++;
            limpaEcra();
            printf("Aluno inserido com sucesso..");
            sleep(2);
            limpaEcra();
        }
    }
}

void DadosAlunos(){
	printf("--------- LISTAGEM DE TODOS OS ALUNOS ---------\n\n");
    for (i = 0; i < nFinalAlunos; i++){
        printf("--------- ALUNO NÚMERO [ %d ] ---------\n", aluno_x[i].numAluno);
        //printf ("\nAluno: %d", aluno_x[i].numAluno);
        printf ("\nNome: %s", aluno_x[i].nomeAluno);
        printf ("\nData Nascimento: %d/%d/%d", aluno_x[i].dataNascimento.dd, aluno_x[i].dataNascimento.mm, aluno_x[i].dataNascimento.aaaa);
        printf ("\nCartão De Cidadão: %d", aluno_x[i].ccAluno);
        printf ("\nNif: %d", aluno_x[i].nif);
        printf ("\ndata Conclusão: %d/%d/%d", aluno_x[i].dataConclusao.dd, aluno_x[i].dataConclusao.mm, aluno_x[i].dataConclusao.aaaa);
        printf ("\nNúmero Carta: %d", aluno_x[i].numeroCarta);
        if (aluno_x[i].ativoAluno == 1){
        	printf ("\nAtivo: Aluno Ativo");
		}else{
			printf("\nAtivo: Aluno Não Ativo");
		}
        printf("\nMorada: %s,%s,%s,%s",aluno_x[i].morada.rua,aluno_x[i].morada.porta,aluno_x[i].morada.codigoPostal,aluno_x[i].morada.localidade);
        printf("\n\n");
    }
}

void InserirInstrutores(){
    printf("--------- INSERIR INSTRUTORES ---------\n");
    printf ("\nIntroduza o número de instrutores que pretende inserir: ");
    scanf ("%d", &nInstrutores);
    nFinalInstrutores = nAtualInstrutores + nInstrutores;
    if (nFinalInstrutores > 10){
        printf ("\nSó podem existir no máximo 10 instrutores");
        limpaEcra();
    }else{
        for (i = 0; i < nInstrutores; i++){
            limpaEcra();
            printf("--------- INSERIR INSTRUTOR ---------\n");
            printf("\nIntroduza o nome do instrutor: ");
            scanf(" %30[^\n]s", instrutores_x[i].nomeInstrutor);
            printf("\nIntroduza número do cartão de cidadão: ");
            scanf(" %9[^\n]s", instrutores_x[i].ccInstrutor);
            verificacaoCCInstrutor();
            printf("\nIntroduza o email: ");
            scanf(" %30[^\n]s", instrutores_x[i].emailInstrutor);
            verificacaoEmailInstrutor();
            printf("\nIntroduza o ano de entrada na escola de condução: ");
            scanf(" %10[^\n]s", instrutores_x[i].anoEntrada);
            printf("\nO instrutor encontra-se ativo no momento\n1 - SIM\n2 - NAO\nR:. ");
            scanf("%d", &instrutores_x[i].ativoInstrutor);
            nAtualInstrutores++;
            instrutores_x[i].numInstrutor = nAtualInstrutores;
            printf("\n\n");
            limpaEcra();
            printf("\nInstrutor inserido com sucesso..");
            sleep(2);
            limpaEcra();
        }
    }
}

void DadosInstrutores(){
	printf("--------- LISTAGEM DE INSTRUTORES ---------\n\n");
    for (i = 0; i < nFinalInstrutores; i++){
    	printf("--------- INSTRUTOR NÚMERO [ %d ] ---------\n", instrutores_x[i].numInstrutor);
        printf("\nInstrutor: %s", instrutores_x[i].nomeInstrutor);
        printf("\nCartão de cidadão: %s",instrutores_x[i].ccInstrutor);
        printf("\nEmail: %s",instrutores_x[i].emailInstrutor);
        printf("\nAno de entrada na escola de condução: %s",instrutores_x[i].anoEntrada);
        if (instrutores_x[i].ativoInstrutor == 1){
            	printf ("\nAtivo: Instrutor Ativo");
			}else{
				printf("\nAtivo: Instrutor Não Ativo");
		}
        printf("\n\n");
    }
}

void MarcacaoAula(){

    printf("-------- Tabela Instrutores --------\n\nnº Instrutor\tNome\t\t\t\tEmail");
    for(i = 0; i < nFinalInstrutores; i++){
    	printf("\n%d\t\t\t\t%s\t\t%s\n",instrutores_x[i].numInstrutor,instrutores_x[i].nomeInstrutor,instrutores_x[i].emailInstrutor);
    }
    printf("-------- Tabela Alunos --------\n\nnºAluno\t\tNome\t\t\t\tCartao de cidadao");
    for(i = 0; i < nFinalAlunos; i++){
        if (aluno_x[i].ativoAluno == 1){
    		printf("\n%d\t\t\t%s\t\t\t%d\n",aluno_x[i].numAluno,aluno_x[i].nomeAluno,aluno_x[i].ccAluno);
    	}
    }
}

void subMenu3_esc2(){
    
}

void limpaEcra(){
    system("clear||cls");
    printf ("\n");
}

void alterarAluno(){
    int alunoEcontrado, respostaAlterarAluno, numAluno;
    int flgAluno = 0;
    printf("--------- LISTAGEM DE ALUNOS ---------\n\n");
    DadosAlunos();
    
    printf("\nIntroduza o número do aluno que pretende alterar: ");
    scanf("%d", &numAluno);
    limpaEcra();
    printf("\n ... A procurar ...\n");
    sleep(2);
    limpaEcra();	
    for(i = 0;i < nFinalAlunos; i++){
        if(aluno_x[i].numAluno == numAluno){
            flgAluno = 1;
            printf("\n Aluno Encontrado --- [ %d ]", aluno_x[i].numAluno);
            printf("\n 1) Nome: %s", aluno_x[i].nomeAluno );
            printf("\n 2) Data De Nascimento: %s", aluno_x[i].dataNascimento);
            printf("\n 3) Cartão de cidadão: %d", aluno_x[i].ccAluno);
            printf("\n 4) NIF: %d", aluno_x[i].nif );
            printf("\n 5) Data de conclusão: %s", aluno_x[i].dataConclusao );
            printf("\n 6) Número da carta: %d", aluno_x[i].numeroCarta);
            printf("\n 7) Aluno Ativo: %d", aluno_x[i].ativoAluno);
            printf("\n 8) Morada: %s,%s,%s,%s",aluno_x[i].morada.rua,aluno_x[i].morada.porta,aluno_x[i].morada.codigoPostal,aluno_x[i].morada.localidade );
            printf("\n -------------------------");
            alunoEcontrado = i;
        }
    }

    if(flgAluno == 1){
    printf("\nEscolha o campo a alterar (1 - 8): ");
    scanf("%d", &respostaAlterarAluno);
    limpaEcra();
        switch(respostaAlterarAluno){
            case 1 :
                printf("\nNome: ");
                scanf(" %30[^\n]s", &aluno_x[alunoEcontrado].nomeAluno);
                limpaEcra();
            break;
            case 2 :
                printf("\nIntroduzir Data De Nascimento: ");
                scanf(" %30[^\n]s", &aluno_x[alunoEcontrado].dataNascimento);
                limpaEcra();
            break;
            case 3:
                printf("\nIntroduzir Cartão De Cidadão : ");
                scanf("%d", &aluno_x[alunoEcontrado].ccAluno);
                limpaEcra();
            break;
            case 4:
                printf("\nIntroduzir NIF : ");
                scanf("%d", &aluno_x[alunoEcontrado].nif);
                limpaEcra();
            break;
            case 5:
                printf("\nIntroduzir Data De Conclusão Da Carta : ");
                scanf(" %30[^\n]s", &aluno_x[alunoEcontrado].dataConclusao);
                limpaEcra();
            break;
            case 6:
                printf("\nIntroduzir Número De Carta : ");
                scanf("%d", &aluno_x[alunoEcontrado].numeroCarta);
                limpaEcra();
            break;
            case 7:
                printf("\nO aluno encontra-se ativo no momento?\n1 - SIM\n2 - NÃO\nR:  ");
                scanf("%d", &aluno_x[alunoEcontrado].ativoAluno);
                limpaEcra();
            break;
            case 8:
                printf("\nIntroduzir morada : ");
                scanf(" %30[^\n]s", idk);
                size_t final = divMoradaAluno (idk, dividir);

                strcpy(&aluno_x[alunoEcontrado].morada.rua, &DadosMorada[1][0]);		//copia a 1 parcela do array para o vetor rua 
                strcpy(&aluno_x[alunoEcontrado].morada.porta, &DadosMorada[2][0]);		//copia a 2 parcela do array para o vetor porta 
                strcpy(&aluno_x[alunoEcontrado].morada.codigoPostal, &DadosMorada[3][0]);	//copia a 3 parcela do array para o vetor codigoPostal 
                strcpy(&aluno_x[alunoEcontrado].morada.localidade, &DadosMorada[4][0]);	//copia a 4 parcela do array para o vetor localidade 
                limpaEcra();
            break;
        }
    }
    else{
        printf("\n -- Aluno Não Encontrado --");
    }
}

void alterarInstrutor(){
    int instrutorEcontrado, respostaAlterarInstrutor, numInstrutor;
    int flgInstrutor = 0;
    DadosInstrutores();
    
    printf("\nIntroduza o número do aluno que pretende alterar: ");
    scanf("%d", &numInstrutor);
    limpaEcra();
    printf("\n ... A procurar ...\n");
    sleep(2);
    limpaEcra();
    for(i = 0; i < nFinalInstrutores; i++){
        if(instrutores_x[i].numInstrutor == numInstrutor){
            flgInstrutor = 1;
            printf("\n Aluno Encontrado --- [ %d ]", instrutores_x[i].numInstrutor);
            printf("\n 1) Nome: %s", instrutores_x[i].nomeInstrutor );
            printf("\n 2) Cartão de cidadão: %d", instrutores_x[i].ccInstrutor);
            printf("\n 3) EMAIL: %s", instrutores_x[i].emailInstrutor );
            printf("\n 4) Ano De Entrada Na Escola De Condução: %d", instrutores_x[i].anoEntrada);
            printf("\n 5) Ativo: %d", instrutores_x[i].ativoInstrutor);
            printf("\n -------------------------");
            instrutorEcontrado = i;
        }
    }

    if(flgInstrutor == 1){
    printf("\nEscolha o campo a alterar (1 - 8): ");
    scanf("%d", &respostaAlterarInstrutor);
    limpaEcra();
        switch(respostaAlterarInstrutor){
            case 1 :
                printf("\nNome: ");
                scanf(" %30[^\n]s", instrutores_x[instrutorEcontrado].nomeInstrutor);
                limpaEcra();
            break;
            case 2 :
                printf("\nIntroduzir Número De Cartão De Cidadão: ");
                scanf(" %9[^\n]s", instrutores_x[instrutorEcontrado].ccInstrutor);
                limpaEcra();
            break;
            case 3 :
                printf("\nIntroduzir o Email: ");
                scanf(" %30[^\n]s", instrutores_x[instrutorEcontrado].emailInstrutor);
                limpaEcra();
            break;
            case 4 :
                printf("\nIntroduzir o Ano De Entrada Na Escola De Condução: ");
                scanf(" %10[^\n]s", instrutores_x[instrutorEcontrado].anoEntrada);
                limpaEcra();
            break;
            case 5 :
                printf("\nO instrutor encontra-se ativo no momento\n1 - SIM\n2 - NÃO\nR:. ");
                scanf("%d", &instrutores_x[instrutorEcontrado].ativoInstrutor);
                limpaEcra();
            break;
        }
    }
    else{
        printf("\n -- Aluno Não Encontrado --");
    }
}

void verificacaoCCAluno(){
    do{
    	for(j = 0; j < nFinalAlunos; j++){
        	while (aluno_x[i].ccAluno == aluno_x[j].ccAluno && i != j){
            	printf("\nJá existe um aluno com o número cartão de cidadão introduzido! \nInsira outro número cartão de cidadão: ");
                scanf("%d", &aluno_x[i].ccAluno);
            	j = 0;
        	}
    	}
    }while(j < nFinalAlunos);
}

void verificacaoNIFAluno(){
    do{
    	for(j = 0; j < nFinalAlunos; j++){
        	while (aluno_x[i].nif == aluno_x[j].nif && i != j){
            	printf("\nJá Existe Um Aluno Com o Numero De Identificação Fiscal Introduzido! \nInsira Outro Número De Identificação Fiscal: ");
                scanf("%d", &aluno_x[i].nif);
            j = 0;
        	}
    	}
    }while(j < nFinalAlunos);
}

void verificacaoCCInstrutor(){
    do{
    	for(j = 0; j < nFinalInstrutores; j++){
        	while (instrutores_x[i].ccInstrutor == instrutores_x[j].ccInstrutor && i != j){
            	printf("\nJá Existe Um Instrutor Com o Número Cartão De Cidadão Introduzido! \nInsira Outro Número Cartão De Cidadão: ");
            	scanf("%d", &instrutores_x[i].ccInstrutor);
            	j = 0;
        	}
    	}
    }while(j < nFinalInstrutores);
}

void verificacaoEmailInstrutor(){
    do{
    	for(j = 0; j < nFinalInstrutores; j++){
        	while (instrutores_x[i].ccInstrutor == instrutores_x[j].ccInstrutor && i != j){
            	printf("\nJá existe um instrutor com o Email introduzido! \nInsira outro Email: ");
            	scanf("%d", &instrutores_x[i].ccInstrutor);
            	j = 0;
       	 	}
   		}	
    }while(j < nFinalInstrutores);
}

void verificacaoCartaConducaoAluno(){
    do{
    	for(j = 0; j < nFinalAlunos; j++){
        	while (aluno_x[i].numeroCarta == aluno_x[j].numeroCarta && i != j){
            	printf("\nJá existe um aluno com o número de carta de condução introduzido! \nInsira outro número de carta de condução: ");
            	scanf("%d", &aluno_x[i].numeroCarta);
            	j = 0;
       	 	}
   		}	
    }while(j < nFinalAlunos);
}

void listaAtivosAlunos(){
	printf("--------- LISTAGEM DE ALUNOS ATIVOS ---------\n\n");
	for(i = 0; i < nFinalAlunos; i++){
		if (aluno_x[i].ativoAluno == 1){
			printf("--------- ALUNO NÚMERO [ %d ] ---------\n", aluno_x[i].numAluno);
	        //printf ("\nAluno: %d", aluno_x[i].numAluno);
	        printf ("\nNome: %s", aluno_x[i].nomeAluno);
	        printf ("\nData Nascimento: %d/%d/%d", aluno_x[i].dataNascimento.dd, aluno_x[i].dataNascimento.mm, aluno_x[i].dataNascimento.aaaa);
	        printf ("\nCartão De Cidadão: %d", aluno_x[i].ccAluno);
	        printf ("\nNif: %d", aluno_x[i].nif);
	        printf ("\ndata Conclusão: %d/%d/%d", aluno_x[i].dataConclusao.dd, aluno_x[i].dataConclusao.mm, aluno_x[i].dataConclusao.aaaa);
	        printf ("\nNúmero Carta: %d", aluno_x[i].numeroCarta);
	        if (aluno_x[i].ativoAluno == 1){
	        	printf ("\nAtivo: Aluno Ativo");
			}else{
				printf("\nAtivo: Aluno Não Ativo");
			}
	        printf("\nMorada: %s,%s,%s,%s",aluno_x[i].morada.rua,aluno_x[i].morada.porta,aluno_x[i].morada.codigoPostal,aluno_x[i].morada.localidade);
	        printf("\n\n");		
		}
	}
}

void listaCartaConducaoAlunos(){
	printf("--------- LISTAGEM DE ALUNOS COM CARTA DE CONDUÇÃO ---------\n\n");
	for(i = 0; i < nFinalAlunos; i++){
		if (aluno_x[i].numeroCarta != 0){
			printf("--------- ALUNO NÚMERO [ %d ] ---------\n", aluno_x[i].numAluno);
	        //printf ("\nAluno: %d", aluno_x[i].numAluno);
	        printf ("\nNome: %s", aluno_x[i].nomeAluno);
	        printf ("\nData Nascimento: %d/%d/%d", aluno_x[i].dataNascimento.dd, aluno_x[i].dataNascimento.mm, aluno_x[i].dataNascimento.aaaa);
	        printf ("\nCartão De Cidadão: %d", aluno_x[i].ccAluno);
	        printf ("\nNif: %d", aluno_x[i].nif);
	        printf ("\ndata Conclusão: %d/%d/%d", aluno_x[i].dataConclusao.dd, aluno_x[i].dataConclusao.mm, aluno_x[i].dataConclusao.aaaa);
	        printf ("\nNúmero Carta: %d", aluno_x[i].numeroCarta);
	        if (aluno_x[i].ativoAluno == 1){
	        	printf ("\nAtivo: Aluno Ativo");
			}else{
				printf("\nAtivo: Aluno Não Ativo");
			}
	        printf("\nMorada: %s,%s,%s,%s",aluno_x[i].morada.rua,aluno_x[i].morada.porta,aluno_x[i].morada.codigoPostal,aluno_x[i].morada.localidade);
	        printf("\n\n");		
		}
	}
}

void listaMais18AnosAlunos(){
	
}
