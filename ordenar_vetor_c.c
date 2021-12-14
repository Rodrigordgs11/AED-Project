#include <stdio.h>
#include <string.h>

int main (){
int i, j;

int vInt[10];
int tInt = 10;
int temp;

for (i = 0; i < tInt;i++){
	printf("\nIntroduza o valor: ");
	scanf("%d", &vInt[i]);
}
    
for (i = 0; i < tInt -1;i++){
	for (j = 0; j < tInt -1 -i;j++){
		if(vInt[j] > vInt [j+1]){
			temp = vInt[j];
			vInt[j] =  vInt[j+1];
			vInt[j+1] = temp;
		}
	}
}

for (i = 0; i < tInt;i++){
	printf("\n %d", vInt[i]);
}
    
}
