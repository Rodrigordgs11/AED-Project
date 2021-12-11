#include <stdio.h>
#include <time.h>
#define MAX_ANO  9999
#define MIN_ANO  1900

//structure to store date
typedef struct Data{
    int aaaa;
    int mm;
    int dd;
} Data;

int  anoBissexto(int ano){
    return (((ano % 4 == 0) &&     //é ano bissexto quando o ano for divisor por 4 ou 400 e o resto for 0 e retornar 1 
             (ano % 100 != 0)) ||
            (ano % 400 == 0));
}

int dataValida(Data *validarData){
    
    if (validarData->aaaa > MAX_ANO ||		//ano tem de ser maior que 1900 e menor que 9999
            validarData->aaaa < MIN_ANO)
        return 0;
    if (validarData->mm < 1 || validarData->mm > 12)	//mes maior que 1 e menor que 12
        return 0;
    if (validarData->dd < 1 || validarData->dd > 31)	//dia mais que 1 e menor que 31
        return 0;
        
    if (validarData->mm == 2){
        if (anoBissexto(validarData->aaaa))
            return (validarData->dd <= 29);	//se for ano bissexto fevereiro tem 29 dias
        else
            return (validarData->dd <= 28); 	//senao tem 28 dias
    }
    
    if (validarData->mm == 4 || validarData->mm == 6 ||		//os meses 4,6,9,11 só têm 30 dias
        validarData->mm == 9 || validarData->mm == 11)
        return (validarData->dd <= 30);
    return 1;
}
int main(void){
		
	Data data[30]; 		//variavel para guardar data
    int estado = 0; 
	int i;				//estado inicia com 0
    
	do{
		for (i = 0; i < 2; i++){
			printf("\n\n Insira a data no formato neste (dd/mm/yyyy): ");
    		scanf("%d/%d/%d",&data[i].dd,&data[i].mm,&data[i].aaaa);
    		estado = dataValida(&data); 	//verifica se a data é válida
    		
    		if(estado != 1){				//se for diferente de 1
        		printf("\nPor favor insira uma data válida!\n");
    		}else{							//senao guarda os dados inseridos
    			printf("\nData valida!\n");
        		printf("\n %d/%d/%d\n", data[i].dd, data[i].mm, data[i].aaaa);
    		}	
		}
		
		for (i = 0; i < 2; i++){
			printf("\n %d/%d/%d", data[i].dd, data[i].mm, data[i].aaaa);
		}		    	
	}while(estado != 1);
   	   
    return 0;
}
