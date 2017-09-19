#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define tamanho 100
typedef struct palavra//struct palavra
{
	int peso;
	char word[50];
}w;
w *ps;
void seleciona_palavra (char *palavra_pesquisada, int numero_de_palavras, w *ps)
{
	int i=0, j=0,cont=0,k=0,tamanho_palavra_pesquisada=0,*vetor_pesos, l=0;
	char *vetor;
	tamanho_palavra_pesquisada=strlen(palavra_pesquisada);
	vetor = (char*)malloc(numero_de_palavras * sizeof(char*));
	vetor_pesos = (int*)malloc(numero_de_palavras * sizeof(int*));
	for(i=0;i<numero_de_palavras;i++)
	{//numero de palavras totais do dicionário
		j=0;
		cont=0;
		if(palavra_pesquisada[j]==ps[i].word[j+1])
		{
			for(j=1;j<tamanho_palavra_pesquisada;j++)
			{
				if((ps[i].word[j+1])!=(palavra_pesquisada[j]))
				{
					cont=1;
					break;
				}	
			}
			l=0;
			for(l=0;l<50;l++)//por que não quer funcionar com tamanho ?
			{
				if(cont==0)
				{ 
					vetor_pesos[k]=ps[i].peso;
					vetor[k]=ps[i].word[l+1];
					k++;
				}
			}		
		}
	}
	for(i=0;i<k;i++)
	{
		printf("%c",vetor[i]);
	}
}
int *bubble_sort(int *vetor, int numero_de_palavras)
{
	int i, j, aux;
	for (i=numero_de_palavras;i>=1;i--) 
	{
		for (j=0;j<i;j++) 
		{

			if (vetor[j]<vetor[j+1]) 
			{
				printf("%d\n",vetor[j]);
				aux=vetor[j];
				vetor[j]=vetor[j+1];
				vetor[j+1]=aux;
			}
		}
	}
	return vetor;
}
int main(){
	FILE *arq_entrada;//declaração dos arquivos de entrada e saída
	arq_entrada=fopen("entrada.txt", "r");//arquivo de entrada
	int numero_de_palavras=0,i=0;//declaração de variavéis
	char palavra_selecionada[tamanho];
	while(fscanf(arq_entrada, "%d", &numero_de_palavras) != EOF)//enquanto i for menor que o número de palavras ele faz a leitura das palavras 
	{
		ps = (w *) malloc(numero_de_palavras * sizeof(w));//aloca palavra que é do tipo w, struct 
		for(i=0;i<numero_de_palavras;i++)
		{
			fscanf(arq_entrada, "%d", &ps[i].peso);//faz leitura das palavras
			fgets(ps[i].word,tamanho,arq_entrada);
		}
	}
	printf("Digite a palavra a ser pesquisada\n");
	scanf("%s", palavra_selecionada);
	seleciona_palavra(palavra_selecionada,numero_de_palavras, ps);
	return 0;
}
