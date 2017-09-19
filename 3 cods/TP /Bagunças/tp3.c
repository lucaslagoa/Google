#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char **aloca_matriz(int total_de_valores)//responsável pela alocação da matriz
{
	char i=0, **matriz;
	matriz = (char**)malloc(total_de_valores * sizeof(char*)); //Aloca um Vetor de Ponteiros
	for (i=1;i<50;i++)
	{ //Percorre as linhas do Vetor de Ponteiros
		matriz[i-1] = (char*)malloc(50 * sizeof(char)); //Aloca um Vetor de Inteiros para cada posição do Vetor de Ponteiros.
	}
	return matriz;//retorna matriz
}
void imprime_matriz(char **matriz, int total_de_valores)//responsável apenas por imprimir a matriz na tela 
{
	int i, j;
	for(i=0;i<total_de_valores;i++)
	{
		for(j=0;j<100;j++)
		{
			printf("%c", matriz[i][j]);
		}
		printf("\n");
	}
}
int main (){
	FILE *arq;
	int total_de_valores, i=0, j=0;
	char **matriz, c;
	arq=fopen("entrada.txt", "r");
	fscanf(arq, "%d", &total_de_valores);
	matriz = aloca_matriz(total_de_valores);
	c=fgetc(arq);
	while(!(feof(arq)))
	{
		j=0;
		while(j<30)
		{
			fscanf(arq, "%c", &c);
			if((c>=64 && c<=90)||(c>=48 && c<=58)||(c>=97 && c<=122)||(c!='\0'))
			{
				matriz[i][j]=c;
			}
			else if(c=='\n')
			{
				i++;
				matriz[i][j]=c;

			}
			j++;
		}
	}
	printf("%d\n", i);
	return 0;
}
