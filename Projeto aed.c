//INSTRUTOR ALTERA??O DADOS 2 INT, MORADA SPLIT MAIS DE 30 CARATERES DA ERRO,

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
typedef struct DataEntrada{
	int aaaa;
    int mm;
    int dd;
} DataEntrada;

typedef struct DataAula{
	int hora;
	int aaaa;
	int mm;
	int dd;
} DataAula;

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
    int ccInstrutor;
    char emailInstrutor[10][30];
    DataEntrada dataEntrada;
    char anoEntrada[10][10];
	int ativoInstrutor;
} Instrutores;

Aluno aluno_x[30];
Instrutores instrutores_x[10];
DataAula dataAula;

/*@@@@ FUN??ES E PROCEDIMENTOS                  @@@@*/

// 			OUTRAS FUN??ES

void limpaEcra();
void limpaEspera();

// 			MENUS 	

void Menu();
int MenuPrincipal();
int MenuAlunos();
int MenuInstrutores();
int MenuConsulta();
int MenuListarAlunos();
int MenuListarInstrutores();

//			FUN??ES ALUNOS 	
	
void InserirAlunos();
void DadosAlunos();
void alterarAluno();
void listaAtivosAlunos();
void listaCartaConducaoAlunos();
void listaMais18AnosAlunos();
void verificacaoCCAluno();
void verificacaoNIFAluno();
void verificacaoCartaConducaoAluno();
void listarPorNomeAluno();

//			FUN??ES INSTRUTORES 

void InserirInstrutores();
void DadosInstrutores();
void alterarInstrutor();
void verificacaoCCInstrutor();
void verificacaoEmailInstrutor();
void listaAtivosInstrutores();
void listarPorNomeInstrutor();


//			FUN??ES MARCA??ES

void MarcacaoAula();
void subMenu3_esc2();

/* variaveis*/
int flag = 0;
char dividir[] = ",";
char moradaSplit[30][70];
char DadosMorada[30][30];

// 			SPLIT MORADA

size_t divMoradaAluno(char *moradaSplit, char *dividir){

  char *ptrMorada;
  ptrMorada = strtok (moradaSplit,dividir); 		//a morada ? dividida por virgulas e guarda no apontador ptrMorada
  int i = 0;
  while (ptrMorada!= NULL){				//enquanto houver virgulas para partir ele parte quando a frase acaba da return 
    strcpy(DadosMorada[++i], ptrMorada);
    ptrMorada = strtok (NULL, dividir);
  }
  return 0;
}


// DECLARA??O DE VARI?VEIS E DE CONSTANTES
int escolhaPrincipal;
int tamanho[30];
//VARIAVEIS INSTRUTORES

int nInstrutores, nAtualInstrutores = 0, nFinalInstrutores;
int escolhaInstrutores;
int i,j;
int resAlunos,respConcluCarta;
//VARIAVEIS MARCA??O

char aulas[100];
int escolhaMarcacao;
int escolhaAlunos;
int escolhaListaAlunos;
int escolhaListaInstrutores;
int nAlunos, nFinalAlunos, nAtualAlunos = 0;


/*@@@@ 					FUN??O MAIN                		 @@@@*/
int main(void) {
	setlocale(LC_ALL, "Portuguese");
	system("COLOR FC");
	Menu();
}

/*-------------------------Fun?oes-------------------------*/

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
		    	switch(MenuListarInstrutores()){
		    	case 1:
		    		limpaEcra();
		        	DadosInstrutores();	
				break;	
				case 2:
					limpaEcra();
		        	listaAtivosInstrutores();
				break;
				case 0:
					limpaEcra();
				break;
				}
		    break;
		    case 3:
		    	alterarInstrutor();
		    break;
		    case 0:
        		limpaEcra();
   			break;
		    }
	    break;
    	case 3:
    		limpaEcra();
	    	switch (MenuConsulta()){
		    case 1:
		        MarcacaoAula();
		    break;
		    case 2:
		    //listar MARCA??ES
		        limpaEcra();
		        subMenu3_esc2();
		    break;
		    case 0:
        		limpaEcra();
   			break;
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
		printf("--------- MENU PRINCIPAL ---------\n");
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
       printf("--------- GESTÃO DE ALUNOS ---------\n");
        printf(" 1 - Inserir Alunos\n");
        printf(" 2 - Listagem Alunos\n");
        printf(" 3 - Alteração De Dados Aluno\n");
        /*printf(" 4 - Marca??o/Consultas de Aulas\n");*/
        printf(" 0 - Sair\n");
        printf("Resposta: ");
        scanf("%d",&escolhaAlunos);
    }while(escolhaAlunos < 0 || escolhaAlunos > 4);
    return escolhaAlunos;
}

int MenuInstrutores(){
    do{
        printf("--------- GESTÃO DE INSTRUTORES ---------\n");
        printf(" 1 - Inserir Instrutores\n");
        printf(" 2 - Listagem Instrutores\n");
        printf(" 3 - Alteração De Dados Instrutor\n");
        /*printf(" 3 - Marca??o/Consultas de Aulas\n");*/
        printf(" 0 - Sair\n");
        printf("Resposta: ");
        scanf("%d",&escolhaInstrutores);
    }while(escolhaInstrutores < 0 || escolhaInstrutores > 4);
    return escolhaInstrutores;
}

int MenuConsulta(){
    do{
        printf("--------- MARCAÇÃO/CONSULTAS DE AULAS ---------\n");
        printf(" 1 - Inserir Marcação\n");
        printf(" 2 - Listagem Marcação\n");
        printf(" 3 - Consultar Aulas\n");
        printf(" 0 - Sair\n");
        printf("Resposta: ");
        scanf("%d",&escolhaMarcacao);
    }while(escolhaMarcacao < 0 || escolhaMarcacao > 3);
    return escolhaMarcacao;
}

int MenuListarAlunos(){
	do{
        printf("--------- LISTAGEM DE ALUNOS ---------\n");
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

int MenuListarInstrutores(){
	do{
        printf("--------- LISTAGEM DE INSTRUTORES ---------\n");
        printf(" 1 - Listar Todos Os Instrutores\n");
        printf(" 2 - Listar Instrutores Ativos\n");
        printf(" 0 - Sair\n");
        printf("Resposta: ");
        scanf("%d",&escolhaListaInstrutores);
    }while(escolhaListaInstrutores < 0 || escolhaListaInstrutores > 2);
    return escolhaListaInstrutores;
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
            printf("\nIntroduza a morada (rua, porta, c?digo postal, localidade): ");
            scanf(" %30[^\n]s", moradaSplit);
            size_t final = divMoradaAluno (moradaSplit, dividir);

            strcpy(&aluno_x[i].morada.rua, &DadosMorada[1][0]);		//copia a 1 parcela do array para o vetor rua 
            strcpy(&aluno_x[i].morada.porta, &DadosMorada[2][0]);		//copia a 2 parcela do array para o vetor porta 
            strcpy(&aluno_x[i].morada.codigoPostal, &DadosMorada[3][0]);	//copia a 3 parcela do array para o vetor codigoPostal 
            strcpy(&aluno_x[i].morada.localidade, &DadosMorada[4][0]);	//copia a 4 parcela do array para o vetor localidade 

            /*printf("\nIntroduza a rua: ");
            scanf(" %30[^\n]s", &aluno_x[i].morada.rua);
            printf("\nIntroduza a porta: ");
            scanf(" %30[^\n]s", &aluno_x[i].morada.porta);
            printf("\nIntroduza a c?digo postal: ");
            scanf(" %30[^\n]s", &aluno_x[i].morada.codigoPostal);
            printf("\nIntroduza a localidade: ");
            scanf(" %30[^\n]s", &aluno_x[i].morada.localidade);*/
            
            printf("\nIntroduza a data de nascimento no seguinte formato (dd/mm/aaaa): ");
            scanf("%d/%d/%d",&aluno_x[i].dataNascimento.dd,&aluno_x[i].dataNascimento.mm,&aluno_x[i].dataNascimento.aaaa);
            printf("\nIntroduza o cartão de cidadão: ");
            scanf("%d", &aluno_x[i].ccAluno);
            //tamanho = strlen(aluno_x[i].ccAluno);
            //printf("%d", tamanho[i]);
            /*do{
            	if (tamanho[i] != 8){
           	 		printf("Introduza um número de cartão de cidadão válido: ");
            		scanf("%d", &aluno_x[i].ccAluno);
            		tamanho[i] = strlen(aluno_x[i].ccAluno);
				}
			}while(tamanho[i] != 8);*/
			verificacaoCCAluno();
            printf("\nIntroduza o NIF: ");
            scanf("%d", &aluno_x[i].nif);
            verificacaoNIFAluno();
            do{
                printf("\nO aluno %s ja concluiu a carta de condução\n1- Sim\n2- Não\nR:. ",aluno_x[i].nomeAluno);
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
	printf("--------- LISTAGEM DE ALUNOS ---------\n\n");
    for (i = 0; i < nFinalAlunos; i++){
        printf("--------- ALUNO NÚMERO [ %d ] ---------\n", aluno_x[i].numAluno);
        //printf ("\nAluno: %d", aluno_x[i].numAluno);
        printf ("\nNome: %s", aluno_x[i].nomeAluno);
        printf ("\nData Nascimento: %d/%d/%d", aluno_x[i].dataNascimento.dd, aluno_x[i].dataNascimento.mm, aluno_x[i].dataNascimento.aaaa);
        printf ("\nCartão De Cidadão: %d", aluno_x[i].ccAluno);
        printf ("\nNif: %d", aluno_x[i].nif);
        if (aluno_x[i].numeroCarta == 0){
        	printf ("\nData Conclusão: Não data de Conclusão");
		}else{
			printf ("\nData Conclusão: %d/%d/%d", aluno_x[i].dataConclusao.dd, aluno_x[i].dataConclusao.mm, aluno_x[i].dataConclusao.aaaa);	
		}
		
        if (aluno_x[i].numeroCarta == 0){
        	printf ("\nNúmero Carta: Não existe número de carta");
		}else{
			printf ("\nNúmero Carta: %d", aluno_x[i].numeroCarta);	
		}
		
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
        for (i = nAtualInstrutores; i < nFinalInstrutores; i++){
            limpaEcra();
            printf("--------- INSERIR INSTRUTOR ---------\n");
            printf("\nIntroduza o nome do instrutor: ");
            scanf(" %30[^\n]s", &instrutores_x[i].nomeInstrutor);
            printf("\nIntroduza número do cartão de cidadão: ");
            scanf("%d", &instrutores_x[i].ccInstrutor);
            verificacaoCCInstrutor();
            printf("\nIntroduza o email: ");
            scanf(" %30[^\n]s", instrutores_x[i].emailInstrutor);
            verificacaoEmailInstrutor();
            printf("\nIntroduza o ano de entrada na escola de condução: ");
            scanf("%d/%d/%d",&instrutores_x[i].dataEntrada.dd,&instrutores_x[i].dataEntrada.mm,&instrutores_x[i].dataEntrada.aaaa);
            printf("\nO instrutor encontra-se ativo no momento\n1 - SIM\n2 - NÃO\nR:. ");
            scanf("%d", &instrutores_x[i].ativoInstrutor);
            nAtualInstrutores++;
            instrutores_x[i].numInstrutor = nAtualInstrutores;
            nAtualInstrutores++;
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
        printf("\nCartão de cidadão: %d",instrutores_x[i].ccInstrutor);
        printf("\nEmail: %s",instrutores_x[i].emailInstrutor);
        printf("\nAno de entrada na escola de condução: %d/%d/%d",instrutores_x[i].dataEntrada.dd, instrutores_x[i].dataEntrada.mm, instrutores_x[i].dataEntrada.aaaa);
        if (instrutores_x[i].ativoInstrutor == 1){
            	printf ("\nAtivo: Instrutor Ativo");
			}else{
				printf("\nAtivo: Instrutor Não Ativo");
		}
        printf("\n\n");
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
            printf("\n 2) Data Nascimento: %d/%d/%d", aluno_x[i].dataNascimento.dd, aluno_x[i].dataNascimento.mm, aluno_x[i].dataNascimento.aaaa);
            printf("\n 3) Cartão de cidadão: %d", aluno_x[i].ccAluno);
            printf("\n 4) NIF: %d", aluno_x[i].nif );
            if (aluno_x[i].numeroCarta == 0){
        		printf("\n 5) Data Conclusão: Não existe data de Conclusão");
			}else{
				printf("\n 5) Data Conclusão: %d/%d/%d", aluno_x[i].dataConclusao.dd, aluno_x[i].dataConclusao.mm, aluno_x[i].dataConclusao.aaaa);	
			}
			if (aluno_x[i].numeroCarta == 0){
        		printf("\n 6) Número Carta: Não existe número de carta");
			}else{
				printf("\n 6) Número da carta: %d", aluno_x[i].numeroCarta);	
			}
		    if (aluno_x[i].ativoAluno == 1){
        		printf("\n 7) Ativo: Aluno Ativo");
			}else{
				printf("\n 7) Aluno: Aluno Não Ativo");
			}
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
                scanf("%d/%d/%d",&aluno_x[alunoEcontrado].dataNascimento.dd,&aluno_x[alunoEcontrado].dataNascimento.mm,&aluno_x[alunoEcontrado].dataNascimento.aaaa);
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
            	if (aluno_x[alunoEcontrado].numeroCarta == 0){
            		printf("\nIntroduzir Data De Conclusão Da Carta : ");
                	scanf("%d/%d/%d",&aluno_x[alunoEcontrado].dataConclusao.dd,&aluno_x[alunoEcontrado].dataConclusao.mm,&aluno_x[alunoEcontrado].dataConclusao.aaaa);
                	printf("\nIntroduzir Número De Carta : ");
                	scanf("%d", &aluno_x[alunoEcontrado].numeroCarta);
				}else{
					printf("\nIntroduzir Data De Conclusão Da Carta : ");
                	scanf("%d/%d/%d",&aluno_x[alunoEcontrado].dataConclusao.dd,&aluno_x[alunoEcontrado].dataConclusao.mm,&aluno_x[alunoEcontrado].dataConclusao.aaaa);
				}
                limpaEcra();
            break;
            case 6:
                if (aluno_x[alunoEcontrado].numeroCarta == 0){
                	printf("\nIntroduzir Número De Carta : ");
                	scanf("%d", &aluno_x[alunoEcontrado].numeroCarta);
            		printf("\nIntroduzir Data De Conclusão Da Carta : ");
                	scanf("%d/%d/%d",&aluno_x[alunoEcontrado].dataConclusao.dd,&aluno_x[alunoEcontrado].dataConclusao.mm,&aluno_x[alunoEcontrado].dataConclusao.aaaa);
				}else{
					printf("\nIntroduzir Número De Carta : ");
                	scanf("%d", &aluno_x[alunoEcontrado].numeroCarta);
				}
                limpaEcra();
            break;
            case 7:
                printf("\nO aluno encontra-se ativo no momento?\n1 - SIM\n2 - NÃO\nR:  ");
                scanf("%d", &aluno_x[alunoEcontrado].ativoAluno);
                limpaEcra();
            break;
            case 8:
                printf("\nIntroduzir morada : ");
                scanf(" %30[^\n]s", moradaSplit);
                size_t final = divMoradaAluno (moradaSplit, dividir);

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
            printf("\n 4) Ano De Entrada Na Escola De Condução: %d/%d/%d", instrutores_x[i].dataEntrada.dd, instrutores_x[i].dataEntrada.mm, instrutores_x[i].dataEntrada.aaaa);
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
                scanf("%d", instrutores_x[instrutorEcontrado].ccInstrutor);
                limpaEcra();
            break;
            case 3 :
                printf("\nIntroduzir o Email: ");
                scanf(" %30[^\n]s", instrutores_x[instrutorEcontrado].emailInstrutor);
                limpaEcra();
            break;
            case 4 :
                printf("\nIntroduzir o Ano De Entrada Na Escola De Condução: ");
                scanf("%d/%d/%d",&instrutores_x[instrutorEcontrado].dataEntrada.dd,&instrutores_x[instrutorEcontrado].dataEntrada.mm,&instrutores_x[instrutorEcontrado].dataEntrada.aaaa);
                limpaEcra();
            break;
            case 5 :
                printf("\nO instrutor encontra-se ativo no momento\n1 - SIM\n2 - N?O\nR:. ");
                scanf("%d", &instrutores_x[instrutorEcontrado].ativoInstrutor);
                limpaEcra();
            break;
        }
    }
    else{
        printf("\n -- Instrutor Não Encontrado --");
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
            	printf("\nJá Existe Um Aluno Com o Número De Identifição Fiscal Introduzido! \nInsira Outro Número De Identifição Fiscal: ");
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
            	printf("\já existe um aluno com o número de carta de condução introduzido! \nInsira outro número de carta de condução: ");
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
	        printf ("\nCartão De Cidad?o: %d", aluno_x[i].ccAluno);
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
	        printf ("\nData Conclusão: %d/%d/%d", aluno_x[i].dataConclusao.dd, aluno_x[i].dataConclusao.mm, aluno_x[i].dataConclusao.aaaa);
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

void listaAtivosInstrutores(){
	printf("--------- LISTAGEM DE INSTRUTORES ATIVOS ---------\n\n");
	for(i = 0; i < nFinalInstrutores; i++){
		if (instrutores_x[i].ativoInstrutor == 1){
			printf("--------- INSTRUTOR NÚMERO [ %d ] ---------\n", instrutores_x[i].numInstrutor);
	        printf ("\nNome: %s", instrutores_x[i].nomeInstrutor);
	        printf ("\nData De Entrada: %d/%d/%d", instrutores_x[i].dataEntrada.dd, instrutores_x[i].dataEntrada.mm, instrutores_x[i].dataEntrada.aaaa);
	        printf ("\nCartão De Cidadão: %d", instrutores_x[i].ccInstrutor);
	        printf ("\nEmail: %s", instrutores_x[i].emailInstrutor);
	        if (instrutores_x[i].ativoInstrutor == 1){
	        	printf ("\nAtivo: Instrutor Ativo");
			}else{
				printf("\nAtivo: Instrutor Não Ativo");
			}
	        printf("\n\n");		
		}
	}	
}

void MarcacaoAula(){
int numAlunoMarc;
int numInstrutorMarc;
limpaEcra();
printf("--------- MARCAÇÃO DE UMA AULA ---------\n\n");
printf("Introduza a hora da aula");
scanf("%d",&dataAula.hora);
printf("Introduza a data da aula");
scanf("%d/%d/%d",&dataAula.dd, &dataAula.mm, &dataAula.aaaa);
//IDEIA: LIMPAR A VARIAVEL
//IDEIA: IMPLEMENTAR COM SPLIT.   EX: 19H, 11/09/2020
listaAtivosAlunos(); 	//tenho algo pensado melhor mas para testes chega 
printf("\nIntroduza o número do aluno para marcar a aula: ");
scanf("%d", &numAlunoMarc);
	for (i = 0; i < nFinalAlunos; i++){
		if(aluno_x[i].numAluno == numAlunoMarc){
			limpaEcra();
			printf("\nEscolheu o aluno %s com o número %d", aluno_x[i].nomeAluno, aluno_x[i].numAluno);
			sleep(3);
		}else{
			for(j = 0; j < nFinalAlunos; j++){
				while(aluno_x[j].numAluno != numAlunoMarc){
					limpaEcra();
					printf("\nAluno não encontrado\nPor favor introduza um número de aluno válido\n");
					sleep(2);
					limpaEcra();
					listaAtivosAlunos();
					printf("\nIntroduza o número do aluno para marcar a aula: ");
					scanf("%d", &numAlunoMarc);
					j = 0;	
				}	
			}
		}
	}
limpaEcra();
listaAtivosInstrutores();
printf("\nIntroduza o número do instrutor para marcar a aula: ");
scanf("%d", &numInstrutorMarc);
	for (i = 0; i < nFinalInstrutores; i++){
		if(instrutores_x[i].numInstrutor == numInstrutorMarc){
			limpaEcra();
			printf("\nEscolheu o instrutor %s com o número %d", instrutores_x[i].nomeInstrutor, instrutores_x[i].numInstrutor);
			sleep(3);
		}else{
			for(j = 0; j < nFinalAlunos; j++){
				while(instrutores_x[j].numInstrutor == numInstrutorMarc){
					limpaEcra();
					printf("\nInstrutor não encontrado\nPor favor introduza um número de instrutor válido\n");
					sleep(2);
					limpaEcra();
					listaAtivosInstrutores();
					printf("\nIntroduza o número do instrutor para marcar a aula: ");
					j = 0;	
				}
			}		
		}
	}    
//pedir confirmação ao utilizador
limpaEcra();

/*printf("-------- Tabela Instrutores --------\n\nn? Instrutor\tNome\t\t\t\tEmail");
	for(i = 0; i < nFinalInstrutores; i++){
		printf("\n%d\t\t\t\t%s\t\t%s\n",instrutores_x[i].numInstrutor,instrutores_x[i].nomeInstrutor,instrutores_x[i].emailInstrutor);
	}
	printf("-------- Tabela Alunos --------\n\nn?Aluno\t\tNome\t\t\t\tCartao de cidadao");
		for(i = 0; i < nFinalAlunos; i++){
    		if (aluno_x[i].ativoAluno == 1){
			printf("\n%d\t\t\t%s\t\t\t%d\n",aluno_x[i].numAluno,aluno_x[i].nomeAluno,aluno_x[i].ccAluno);
			}
		}*/
}

void listarPorNomeAluno(){
    int resAltera, resConsult, numListarNome = 1, ids[30], flg = 0;
    char nome[20];
    system("clearcls");
    printf ("\nInsira o nome do aluno que pretende consultar: ");
    scanf (" %20[^\n]s", &nome);
    if(strlen(nome) < 2) 
		do{
        	printf("\nPor favor insira pelo menos 2 caracteres para procurar pelo nome: ");
        	scanf (" %20[^\n]s", &nome);
    	}while(strlen(nome) < 2);
    limpaEcra();
    for(i = 0; i < nFinalAlunos; i++){
        if (strstr(aluno_x[i].nomeAluno, nome)){
            flg = 1;
            break;
        }
    }
    if(flg == 1){
    	printf("--------- DADOS ALUNOS QUE CONTEM '%s' ---------\n\n", nome);
        for(i = 0; i < nFinalAlunos; i++){
            if (strstr(aluno_x[i].nomeAluno, nome)){
                printf("\n%d - %s", numListarNome, aluno_x[i].nomeAluno);
                //posicao de cada aluno no array que corresponde a pesquisa
                ids[numListarNome] = i; 
                numListarNome++;
            }
        }
        printf("\n0 - Voltar");
        printf("\nInsira o numero do aluno que deseja consultar/alterar: ");
        scanf("%d", &resConsult);
        fflush(stdin);
        if(resConsult != 0){
            DadosAlunos(ids[resConsult]); //posição do aluno no array
            printf("\nPretende alterar este aluno?\n1 - (Sim)\n0 - Não\nResposta: ");
            scanf("%d", &resAltera);
            if(resAltera == 1){
                alterarAluno(ids[resConsult]);
            }
        }
    }else{
    	printf("Nenhum aluno com esse número digitado encontrado! A redirecionar ....");
    	limpaEspera();
    }
}

void listarPorNomeInstrutor(){
    int resAltera, resConsult, numListarNome = 1, ids[30], flg = 0;
    char nome[20];
    system("clearcls");
    printf ("\nInsira o nome do aluno que pretende consultar: ");
    scanf (" %20[^\n]s", &nome);
    if(strlen(nome) < 2) 
		do{
        	printf("\nPor favor insira pelo menos 2 caracteres para procurar pelo nome: ");
        	scanf (" %20[^\n]s", &nome);
    	}while(strlen(nome) < 2);
    limpaEcra();
    for(i = 0; i < nFinalInstrutores; i++){
        if (strstr(instrutores_x[i].nomeInstrutor, nome)){
            flg = 1;
            break;
        }
    }
    if(flg == 1){
    	printf("--------- DADOS INSTRUTORES QUE CONTEM '%s' ---------\n\n", nome);
        for(i = 0; i < nFinalAlunos; i++){
            if (strstr(instrutores_x[i].nomeInstrutor, nome)){
                printf("\n%d - %s", numListarNome, instrutores_x[i].nomeInstrutor);
                //posicao de cada aluno no array que corresponde a pesquisa
                ids[numListarNome] = i; 
                numListarNome++;
            }
        }
        printf("\n0 - Voltar");
        printf("\nInsira o numero do aluno que deseja consultar/alterar: ");
        scanf("%d", &resConsult);
        fflush(stdin);
        if(resConsult != 0){
            DadosInstrutores(ids[resConsult]); //posição do aluno no array
            printf("\nPretende alterar este aluno?\n1 - (Sim)\n0 - Não\nResposta: ");
            scanf("%d", &resAltera);
            if(resAltera == 1){
                alterarInstrutor(ids[resConsult]);
            }
        }
    }else{
    	printf("Nenhum instrutor com o número digitado encontrado! A redirecionar ....");
    	limpaEspera();
    }
}

void limpaEspera(){
	limpaEcra();
	sleep(2);
}
