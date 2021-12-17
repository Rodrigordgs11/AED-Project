#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <locale.h>
typedef struct Morada{
         char rua[30];
         char porta[30];
         char codigoPostal[30];
         char localidade[30];
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
void menu();
void MenuAlunos();
void MenuInstrutores();
void MenuConsulta();
void InserirAlunos();
void DadosAlunos();
void InserirInstrutores();
void DadosInstrutores();
void MarcacaoAula();
void subMenu3_esc2();
void limpaEcra();
void verificacaoCCAluno();
void verificacaoNIF();
void verificacaoCCInstrutor();
/* variaveis*/
char rua[30][30];
char porta[30][30];
char codigoPostal[30][30];
char localidade[30][30];
int flag = 0;
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
int nAlunos, nFinalAlunos, nAtualAlunos = 0;
/*@@@@ FUN??O MAIN                              @@@@*/
int main(void) {
   setlocale(LC_ALL, "Portuguese");
   system("COLOR FC");
    menu();
}
/*-------------------------Funçoes-------------------------*/
void menu(){
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
            limpaEcra();
            MenuAlunos();
            switch (escolhaAlunos){
            case 1:
                limpaEcra();
                InserirAlunos();
            break;
            case 2:
                limpaEcra();
                DadosAlunos();
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
            MenuInstrutores();
            switch (escolhaInstrutores){
            case 1:
                limpaEcra();
                    InserirInstrutores();
            break;
            case 2:
            //listar instrutores
                DadosInstrutores();
            
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
            MenuConsulta();
            switch (escolhaMarcacao){
            case 1:
                    MarcacaoAula();
            break;
            case 2:
            //listar MARCAçÕES
                limpaEcra();
                subMenu3_esc2();
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
        sleep(1);
    break;
    }
    printf("\n\n");
    }while(escolhaPrincipal != 0);
}
void MenuAlunos(){
    do{
       printf("--------- Gestão de Alunos ---------\n");
        printf(" 1 - Inserir Alunos\n");
        printf(" 2 - Listagem Alunos\n");
        /*printf(" 3 - Marcação/Consultas de Aulas\n");*/
        printf(" 0 - Sair\n");
        printf("Resposta: ");
        scanf("%d",&escolhaAlunos);
    }while(escolhaAlunos < 0 || escolhaAlunos > 3);
}
void MenuInstrutores(){
    do{
        printf("--------- Gestão de Instrutores ---------\n");
        printf(" 1 - Inserir Instrutores\n");
        printf(" 2 - Listagem Instrutores\n");
        /*printf(" 3 - Marcação/Consultas de Aulas\n");*/
        printf(" 0 - Sair\n");
        printf("Resposta: ");
        scanf("%d",&escolhaInstrutores);
    }while(escolhaInstrutores < 0 || escolhaInstrutores > 3);
}
void MenuConsulta(){
    do{
        printf("--------- Marcação/Consultas de Aulas ---------\n");
        printf(" 1 - Inserir Marcação\n");
        printf(" 2 - Listagem Marcação\n");
        printf(" 3 - Marcação/Consultas de Aulas\n");
        printf(" 0 - Sair\n");
        printf("Resposta: ");
        scanf("%d",&escolhaMarcacao);
    }while(escolhaMarcacao < 0 || escolhaMarcacao > 3);
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
                 //scanf(" %30[^\n]s", aluno_x[30].morada + nAtualAlunos);
                 printf("\nIntroduza a rua: ");
                 scanf(" %30[^\n]s", &aluno_x[i].morada.rua);
                 printf("\nIntroduza a porta: ");
                 scanf(" %30[^\n]s", &porta[i]);
                 printf("\nIntroduza a código postal: ");
                 scanf(" %30[^\n]s", &codigoPostal[i]);
                 printf("\nIntroduza a localidade: ");
                 scanf(" %30[^\n]s", &localidade[i] );
                 printf("\nIntroduza a data de nascimento no seguinte formato(dd/mm/aaaa): ");
                 scanf("%d/%d/%d",&aluno_x[i].dataNascimento.dd,&aluno_x[i].dataNascimento.mm,&aluno_x[i].dataNascimento.aaaa);
                 printf("\nIntroduza o cartao de cidadao: ");
                 scanf("%d", &aluno_x[i].ccAluno);
                 verificacaoCCAluno();
                 printf("\nIntroduza o NIF: ");
                 scanf("%d", &aluno_x[i].nif);
                 verificacaoNIF();
                 //Perguntar se ja cuncluiu a carta!
                 do{
                     printf("\nO aluno %s ja concluiu a carta de condução?\n1- Sim\n2- Não\nR:. ",aluno_x[i].nomeAluno);
                     scanf("%d",&respConcluCarta);
                 if(respConcluCarta==1){
                     printf("\nIntroduza a data de conclusao de carta no seguinte formato(dd/mm/aaaa): ");
                     scanf("%d/%d/%d",&aluno_x[i].dataConclusao.dd,&aluno_x[i].dataConclusao.mm,&aluno_x[i].dataConclusao.aaaa);
                     printf("\nIntroduza o numero de carta: ");
                     scanf("%d", &aluno_x[i].numeroCarta);
                     aluno_x[i].ativoAluno=0;
                     break;
                 }else if(respConcluCarta==2){
                     printf("\nO aluno encontra-se ativo no momento\n1 - SIM\n2 - NAO\nR:. ");
                     scanf("%d", &aluno_x[i].ativoAluno);
                     break;
                 }else if(respConcluCarta!=1||respConcluCarta!=2){
                     limpaEcra();
                     printf("Introduza uma opção Valida");
                     limpaEcra();
                 }
                 }while(respConcluCarta!=1 || respConcluCarta!=2);
                 aluno_x[i].numAluno = nAtualAlunos+1;
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
            printf("--------- ALUNO NÚMERO[%d] ---------\n", aluno_x[i].numAluno);
            //printf ("\nAluno: %d", aluno_x[i].numAluno);
            printf ("\nNome: %s", aluno_x[i].nomeAluno);
            printf ("\nData Nascimento: %s", aluno_x[i].dataNascimento);
            printf ("\nCC: %d", aluno_x[i].ccAluno);
            printf ("\nNif: %d", aluno_x[i].nif);
            printf ("\ndata conclusao: %s", aluno_x[i].dataConclusao);
            printf ("\nnumero Carta: %d", aluno_x[i].numeroCarta);
            printf ("\nAtivo: %d", aluno_x[i].ativoAluno);
            printf("\nMorada: %s,%s,%s,%s",aluno_x[i].morada.rua,porta[i],codigoPostal[i],localidade[i]);
            printf("\n\n");
        }
}
void InserirInstrutores(){
    printf("--------- INSERIR INSTRUTORES ---------\n");
    printf ("\nIntroduza o numero de instrutores que pretende inserir: ");
    scanf ("%d", &nInstrutores);
    nFinalInstrutores = nAtualInstrutores + nInstrutores;
        if (nFinalInstrutores > 10){
            printf ("\nSó podem existir no maximo 10 instrutores");
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
                
                printf("\nIntroduza o ano de entrada na escola de condução: ");
                scanf(" %10[^\n]s", instrutores_x[i].anoEntrada);
                printf("\nO instrutor encontra-se ativo no momento\n1 - SIM\n2 - NAO\nR:. ");
                scanf("%d", &instrutores_x[i].ativoInstrutor);
                nAtualInstrutores++;
                instrutores_x[i].numInstrutor=nAtualInstrutores;
                printf("\n\n");
                limpaEcra();
                printf("\nInstrutor inserido com sucesso..");
                sleep(2);
                limpaEcra();
            }
        }
}
void DadosInstrutores(){
    for (i = 0; i < nFinalInstrutores; i++){
        printf("\nInstrutor: %s", instrutores_x[i].nomeInstrutor);
        printf("\nCartão de cidadão: %s",instrutores_x[i].ccInstrutor);
        printf("\nEmail: %s",instrutores_x[i].emailInstrutor);
        printf("\nAno de entrada na escola de condução: %s",instrutores_x[i].anoEntrada);
        printf("\nAtivo: %d",instrutores_x[i].ativoInstrutor);
        printf("\n\n");
    }
}
void MarcacaoAula(){
    printf("-------- Tabela Instrutores --------\n\nnº Instrutor\tNome\t\t\t\tEmail");
    for(i=0; i < nFinalInstrutores;i++){
    printf("\n%d\t\t\t\t%s\t\t%s\n",instrutores_x[i].numInstrutor,instrutores_x[i].nomeInstrutor,instrutores_x[i].emailInstrutor);
    }
    printf("-------- Tabela Alunos --------\n\nnºAluno\t\tNome\t\t\t\tCartao de cidadao");
    for(i=0; i < nFinalAlunos;i++){
        if (aluno_x[i].ativoAluno==1) {
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
    DadosAlunos();
    
    printf("\nIntroduza o número do aluno que pretrende alterar: ");
    scanf("%d", &numAluno);
    printf("\n ... a procurar ...\n");
    for(i = 0; i < nFinalAlunos; i++){
        if(aluno_x[i].numAluno == numAluno){
            flgAluno = 1;
            printf("\n Aluno Encontrado --- [ %d ]", aluno_x[i].numAluno);
            printf("\n 1) Nome \t\t : %s", aluno_x[i].nomeAluno );
            printf("\n 2) Data De Nascimento \t\t: %s", aluno_x[i].dataNascimento);
            printf("\n 3) Cartão de cidadão \t : %d", aluno_x[i].ccAluno);
            printf("\n 4) NIF \t\t: %d", aluno_x[i].nif );
            printf("\n 5) Data de conclusão \t : %s", aluno_x[i].dataConclusao );
            printf("\n 6) Número da carta \t : %d", aluno_x[i].numeroCarta);
            printf("\n 7) Aluno Ativo \t : %d", aluno_x[i].ativoAluno);
            printf("\n 8) Morada \t : %s,%s,%s,%s",rua[i],porta[i],codigoPostal[i],localidade[i] );
            printf("\n -------------------------");
            alunoEcontrado = i;
        }
    }
    if(flgAluno == 1){
    printf("\nEscola o campo a alterar (1 - 8): ");
    scanf("%d", &respostaAlterarAluno);
        switch(respostaAlterarAluno){
            case 1 :
                printf("\nNome: ");
                scanf(" %30[^\n]s", &aluno_x[alunoEcontrado].nomeAluno);
            break;
            case 2 :
                printf("\nIntroduzir Data De Nascimento: ");
                scanf(" %30[^\n]s", &aluno_x[alunoEcontrado].dataNascimento);
            break;
            /*case 3 :
                printf("\nIntroduzir morada : ");
                //Implementar com split
            break;*/
            case 4 :
                printf("\nIntroduzir Cartão De Cidadão : ");
                scanf("%d", &aluno_x[alunoEcontrado].ccAluno);
            break;
            case 5 :
                printf("\nIntroduzir NIF : ");
                scanf("%d", &aluno_x[alunoEcontrado].nif);
            break;
            case 6 :
                printf("\nIntroduzir Data De Conclusao Da Carta : ");
                scanf(" %30[^\n]s", &aluno_x[alunoEcontrado].dataConclusao);
            break;
            case 7 :
                printf("\nIntroduzir Número De Carta : ");
                scanf("%d", &aluno_x[alunoEcontrado].numeroCarta);
            break;
            case 8 :
                printf("\nO aluno encontra-se ativo no momento\n1 - SIM\n2 - NAO\nR:  ");
                scanf("%d", &aluno_x[alunoEcontrado].ativoAluno);
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
    DadosAlunos();
    
    printf("\nIntroduza o número do aluno que pretrende alterar: ");
    scanf("%d", &numInstrutor);
    printf("\n ... a procurar ...\n");
    for(i = 0; i < nFinalInstrutores; i++){
        if(instrutores_x[i].numInstrutor == numInstrutor){
            flgInstrutor = 1;
            printf("\n Aluno Encontrado --- [ %d ]", instrutores_x[i].numInstrutor);
            printf("\n 1) Nome \t\t : %s", instrutores_x[i].nomeInstrutor );
            printf("\n 2) Cartão de cidadão \t : %f", instrutores_x[i].ccInstrutor);
            printf("\n 3) EMAIL \t\t: %s", instrutores_x[i].emailInstrutor );
            printf("\n 4) Ano De Entrada Na Escola De Condução \t : %d", instrutores_x[i].anoEntrada );
            printf("\n 5) Ativo \t : %d", instrutores_x[i].ativoInstrutor);
            printf("\n -------------------------");
            instrutorEcontrado = i;
        }
    }
    if(flgInstrutor == 1){
    printf("\nEscola o campo a alterar (1 - 8): ");
    scanf("%d", &respostaAlterarInstrutor);
        switch(respostaAlterarInstrutor){
            case 1 :
                printf("\nNome: ");
                scanf(" %30[^\n]s", instrutores_x[instrutorEcontrado].nomeInstrutor);
            break;
            case 2 :
                printf("\nIntroduzir Número De Cartão De Cidadão: ");
                scanf(" %9[^\n]s", instrutores_x[instrutorEcontrado].ccInstrutor);
            break;
            case 3 :
                printf("\nIntroduzir o Email: ");
                scanf(" %30[^\n]s", instrutores_x[instrutorEcontrado].emailInstrutor);
            break;
            case 4 :
                printf("\nIntroduzir o Ano De Entrada Na Escola De Condução: ");
                scanf(" %10[^\n]s", instrutores_x[instrutorEcontrado].anoEntrada);
            break;
            case 5 :
                printf("\nO instrutor encontra-se ativo no momento\n1 - SIM\n2 - NAO\nR:. ");
                scanf("%d", &instrutores_x[instrutorEcontrado].ativoInstrutor);
            break;
        }
    }
    else{
        printf("\n -- Aluno Não Encontrado --");
    }
}
void verificacaoCCAluno(){
    do{
    for(j=0;j < nFinalAlunos;j++){
        while (aluno_x[i].ccAluno==aluno_x[j].ccAluno && i!=j){
            printf("\nJá existe um aluno com o número cartão de cidadão introduzido! \nInsira outro número cartão de cidadão");
                scanf("%d", &aluno_x[i].ccAluno);
            j=0;
        }
    }
    }while(j<nFinalAlunos);
}
void verificacaoNIF(){
    do{
    for(j=0;j < nFinalAlunos;j++){
        while (aluno_x[i].nif==aluno_x[j].nif && i!=j){
            printf("\nJá existe um aluno com o Numero de identificação Fiscal introduzido! \nInsira outro Numero de identificação Fiscal");
                scanf("%d", &aluno_x[i].nif);
            j=0;
        }
    }
    }while(j<nFinalAlunos);
}
void verificacaoCCInstrutor(){
    do{
    for(j = 0; j < nFinalInstrutores; j++){
        while (instrutores_x[i].ccInstrutor == instrutores_x[j].ccInstrutor && i != j){
            printf("\nJá existe um aluno com o número cartão de cidadão introduzido! \nInsira outro número cartão de cidadão");
            scanf("%d", &instrutores_x[i].ccInstrutor);
            j = 0;
        }
    }
    }while(j < nFinalInstrutores);
}
void verificacaoCCEmail(){
    do{
    for(j = 0; j < nFinalInstrutores; j++){
        while (instrutores_x[i].ccInstrutor == instrutores_x[j].ccInstrutor && i != j){
            printf("\nJá existe um aluno com o número cartão de cidadão introduzido! \nInsira outro número cartão de cidadão");
            scanf("%d", &instrutores_x[i].ccInstrutor);
            j = 0;
        }
    }
    }while(j < nFinalInstrutores);
}
