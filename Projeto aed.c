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
