#include <stdio.h>
#include <string.h>

#define LINHAS  10
#define COLUNAS  30

char DadosMorada[LINHAS][COLUNAS];

size_t funcDividirVirgula(char* Morada, char *dividir){
  char *ptrMorada;
  ptrMorada = strtok (Morada,dividir);
  int i = 0,j;
  while (ptrMorada!= NULL){
    strcpy(DadosMorada[++i], ptrMorada);
    ptrMorada = strtok (NULL, dividir);
  }
  return i;
}

int main (){

    char Morada[70];
    char dividir[] = ",";
    char rua[40], porta[40], codigoPostal[40], localidade[40];

    printf("Morada:");
    scanf(" %70[^\n]s", Morada);

  size_t final = funcDividirVirgula (Morada, dividir);
  int i;
 /*
   for (i = 0; i < 4; i++)   {
    rua[i] = DadosMorada[1];
    porta[i] = DadosMorada[2];
    codigoPostal[i] = DadosMorada[3]; 
    localidade[i] = DadosMorada[4];
  }
*/  
    printf ("%s\n",DadosMorada[1]);
    printf ("%s\n",DadosMorada[2]);
    printf ("%s\n",DadosMorada[3]);
    printf ("%s\n",DadosMorada[4]);
    
    /*
 for (i = 0; i < final+1; i++)   {
    
    printf ("%s\n",rua[i]);
    printf ("%s\n",porta[i]);
    printf ("%s\n",codigoPostal[i]);
    printf ("%s\n",localidade[i]);
  }
*/
    
  return 0;
}
