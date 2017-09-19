#include <stdio.h>
#include <stdlib.h>
int main (){
	FILE *arq, *arq1;
	arq=fopen("entrada.txt", "r");
	arq1=fopen("saida.txt", "w");
	long long int peso;
	char palavra[30];
	int i=0, j=0;
	while(!(feof(arq)))
	{ 
		while(arq!='t')
		{
			fscanf(arq, "%c", &palavra[i]);
			i++;
		}
		fscanf(arq, "%lli", &peso);
		fprintf(arq1, "%lli", peso);
		for(i=0;i<30;i++)
		{
	
			fprintf(arq1, "%c", palavra[i]);
			printf("%c", palavra[i]);
			i++;
		}
		fprintf(arq1, "\n");
		j++;
	}
	fclose(arq);
	fclose(arq1);
	return 0;
}
	
