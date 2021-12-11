#include <stdio.h>
#include <string.h>

#define LINHAS  10
#define COLUNAS  30
typedef struct {
	
};
typedef struct {
	char rua[30][40];
	char porta[30][40];
	char codigoPostal[30][40];
	char localidade[30][40];
} Morada;

Morada morada_x[30];

char DadosMorada[LINHAS][COLUNAS];

size_t funcDividirVirgula(char *Morada, char *dividir){
  char *ptrMorada;
  ptrMorada = strtok (Morada,dividir);
  int i = 0;
  while (ptrMorada!= NULL){
    strcpy(DadosMorada[++i], ptrMorada);
    ptrMorada = strtok (NULL, dividir);
  }
  return i;
}

int main (){
int i;
    char Morada[30][70];
    char dividir[] = ",";
	for (i = 0; i < 2; i++){
	printf("Morada:");
    scanf(" %30[^\n]s", Morada);
	size_t final = funcDividirVirgula (Morada, dividir);	
	
    strcpy(&morada_x[i].rua, &DadosMorada[1][0]);
    strcpy(&morada_x[i].porta, &DadosMorada[2][0]);
    strcpy(&morada_x[i].codigoPostal, &DadosMorada[3][0]);
    strcpy(&morada_x[i].localidade, &DadosMorada[4][0]);
  
/*
    printf ("%s\n",DadosMorada[1]);
    printf ("%s\n",DadosMorada[2]);
    printf ("%s\n",DadosMorada[3]);
    printf ("%s\n",DadosMorada[4]);
  */

  }

	for (i = 0; i < 2; i++){
    	printf ("%s\n",morada_x[i].rua);
    	printf ("%s\n",morada_x[i].porta);
    	printf ("%s\n",morada_x[i].codigoPostal);
    	printf ("%s\n",morada_x[i].localidade);
	}
}
