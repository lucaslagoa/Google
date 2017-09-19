#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char **aloca_matriz(int total_de_valores)//responsável pela alocação da matriz
{
	char i=0, **matriz;
	matriz = (char**)calloc(total_de_valores , sizeof(char*)); //Aloca um Vetor de Ponteiros
	for (i=1;i<50;i++)
	{ //Percorre as linhas do Vetor de Ponteiros
		matriz[i-1] = (char*)calloc(50 , sizeof(char)); //Aloca um Vetor de Inteiros para cada posição do Vetor de Ponteiros.
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
	int total_de_valores, i=0, j=0, k =0;
	char **matriz, c;
	arq = fopen("entrada.txt", "r");
	fscanf(arq, "%d", &total_de_valores);
	matriz = aloca_matriz(total_de_valores);
	while(!(feof(arq))){
		j = 0;
		do {
			c = fgetc (arq);
			matriz[i][j] = c;
			j++;
		} while ((c >= 64 && c <= 90) || (c >= 48 && c <= 58) || (c >= 97 && c <= 122));
		for (k = 0; k < j; k++){
			printf("%c ", matriz[i][k]);
		}
		printf("\n");
		i++;
	}

	return 0;
}
