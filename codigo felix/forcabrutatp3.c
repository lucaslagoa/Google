#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct palavra//struct palavra
{
	int peso;
	char word[50];
}w;

typedef struct palavras_selec//struct com as palavras selecionadas 
{
	int peso_palavra_selecionada;
	char palavra_selecionada[50];
}ws;

ws *seleciona_palavra(ws *ps, int tamanho_palavra_pesquisada, w *palavras, char *palavra_pesquisada, int numero_de_palavras)
{
	int i=0, j=0,cont=0, k=0;
	for(i=0;i<numero_de_palavras;i++)
	{//numero de palavras totais do dicionário
		cont=0;//tem que ser zero a cada palavra 
		for(j=0;j<tamanho_palavra_pesquisada;j++)
		{//vai até o tamanho do préfixo 
			if(palavra_pesquisada[j]==palavras[i].word[j+1]) 
			{
				cont++;
				if(cont==tamanho_palavra_pesquisada)//quer dizer que palavra é do tamanho do prefixo
				{
					k=0;
					while(k<50)//saber ao certo quantas serão as palavras selecionadas 
					{//copiando o peso e a palavra para a struct de palavras selecionadas 
						ps[i].peso_palavra_selecionada=palavras[i].peso;
						ps[i].palavra_selecionada[k]=palavras[i].word[k];
						k++;
					}
				}
			}				
			else 
			{
				i++;//se nao bater a primeira letra, automaticamente ja posso ir para proxima palavra
			}
		}
	}
	return ps;
}
int *bubble_sort(int *vetor, int numero_de_palavras)
{
	int i, j, aux;
	for (i=numero_de_palavras-1;i>=1;i--) 
	{
		for (j=0;j<i;j++) 
		{
			if (vetor[j]<vetor[j+1]) 
			{
				aux=vetor[j];
				vetor[j]=vetor[j+1];
				vetor[j+1]=aux;
			}
		}
	}
	return vetor;
}
int *vetor_maiores(ws *ps, int tamanho_palavra_pesquisada, int *vetor_ordenado, int *vetor, int numero_de_palavras)
{
	int i=0;//aloco um vetor do tamanho do número de linhas da matriz
	while(i<50)//saber ao certo a quantidade de palavras que serão retornadas
	{
		vetor[i]=ps[i].peso_palavra_selecionada;
		i++;
	}
	vetor_ordenado=bubble_sort(vetor, numero_de_palavras);//ordena o vetor utilizando o bubblesort
	return vetor_ordenado;
}
ws *selecao(ws *ps, int *vetor_ordenado, int numero_de_palavras, FILE *arq_saida)
{//função responsável de selecionar e printar as palavras que serão fornecidas pelo autocomplete
	int i=0, j=0;
	for(i=0;i<numero_de_palavras;i++)
	{
		for(j=0;j<numero_de_palavras;j++)
		{
			if(vetor_ordenado[i]==ps[j].peso_palavra_selecionada)
			{
				printf("%s", ps[j].palavra_selecionada);
			}
		}
	}
	return ps;
}
int main(){
	FILE *arq, *arq_saida;//declaração dos arquivos de entrada e saída
	arq=fopen("entrada.txt", "r");//arquivo de entrada
	arq_saida=fopen("saida.txt", "w");//arquivo de saída
	int numero_de_palavras, *vetor_ordenado, *vetor, i, tamanho_palavra_pesquisada;//declaração de variavéis
	w *palavras;//declaração da struct 
	ws *ps;//declaração da struct que receberá as palavras selecionadas 
	char palavra_pesquisada[50]="b";
	palavras = (w *) malloc(numero_de_palavras * sizeof(w));//aloca palavra que é do tipo w, struct 
	ps= (ws *) malloc(numero_de_palavras * sizeof(ws));//aloca palavra que é do tipo ws, struct 
	while(fscanf(arq, "%d", &numero_de_palavras) != EOF)//enquanto i for menor que o número de palavras ele faz a leitura das palavras 
	{
		for(i=0;i<numero_de_palavras;i++)
		{
			fscanf(arq, "%d", &palavras[i].peso);//faz leitura das palavras
			fgets(palavras[i].word,50,arq);
		}
	}
	vetor_ordenado = (int*)malloc(numero_de_palavras * sizeof(int*));//aloca vetor ordenado 
	vetor = (int*)malloc(numero_de_palavras * sizeof(int*));//aloca vetor
	tamanho_palavra_pesquisada=strlen(palavra_pesquisada);//retorna o tamanho da palavra
	ps=seleciona_palavra(ps, tamanho_palavra_pesquisada, palavras, palavra_pesquisada, numero_de_palavras);
	vetor_ordenado=vetor_maiores(ps, tamanho_palavra_pesquisada, vetor_ordenado, vetor, numero_de_palavras);
	ps=selecao(ps, vetor_ordenado, numero_de_palavras, arq_saida);
	return 0;
}
