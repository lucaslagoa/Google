#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define tamanho 100
typedef struct palavra//struct palavra
{
	long long int peso;
	char word[tamanho];
}w;

typedef struct palavras_selec//struct com as palavras selecionadas 
{
	long long int peso_palavra_selecionada;
	char palavra_selecionada[tamanho];
}ws;
char *min(char *palavra_pesquisada_leitura, int tamanho_palavra_pesquisada)
{//função responsável por deixar todas as letras minusculas para a pesquisa
	int i;
	for(i=0;i<tamanho_palavra_pesquisada;i++)
	{
		if((palavra_pesquisada_leitura[i]>=65)&&(palavra_pesquisada_leitura[i]<=90))
		{
			palavra_pesquisada_leitura[i]=palavra_pesquisada_leitura[i]+32;
		}
	}
	return palavra_pesquisada_leitura;
}
ws *seleciona_palavra(ws *ps, int tamanho_palavra_pesquisada, w *palavras, char *palavra_pesquisada, int numero_de_palavras)
{
	int i=0, j=0,cont=0, k=0;
	for(i=0;i<numero_de_palavras;i++)
	{//numero de palavras totais do dicionário
		cont=0;//tem que ser zero a cada palavra  	 
		for(j=0;j<tamanho_palavra_pesquisada;j++)
		{//vai até o tamanho do préfixo  
			if(palavra_pesquisada[j]==palavras[i].word[j+1]) //tem que ser j+1, pois na leitura pega-se o espaço
			{
				cont++;
				if(cont==tamanho_palavra_pesquisada)//quer dizer que palavra é do tamanho do prefixo
				{
					k=0;
					while(k<100)//saber ao certo quantas serão as palavras selecionadas 
					{//copiando o peso e a palavra para a struct de palavras selecionadas 
						ps[i].peso_palavra_selecionada=palavras[i].peso;
						ps[i].palavra_selecionada[k]=palavras[i].word[k];
						k++;
					}
				}
			}				
		}
	}
	return ps;
}
long long int *bubble_sort(long long int *vetor, int numero_de_palavras)
{
	int i, j;
	long long int aux;
	for(i=numero_de_palavras-1;i>=1;i--) 
	{
		for(j=0;j<i;j++) 
		{
			if(vetor[j]<vetor[j+1]) 
			{
				aux=vetor[j];
				vetor[j]=vetor[j+1];
				vetor[j+1]=aux;
			}
		}
	}
	return vetor;
}
long long int *vetor_maiores(ws *ps, int tamanho_palavra_pesquisada,long long int *vetor_ordenado, long long int *vetor, int numero_de_palavras)
{
	int i=0;//aloco um vetor do tamanho do número de linhas da matriz
	while(i<numero_de_palavras)//saber ao certo a quantidade de palavras que serão retornadas
	{
		vetor[i]=ps[i].peso_palavra_selecionada;
		i++;
	}
	vetor_ordenado=bubble_sort(vetor, numero_de_palavras);//ordena o vetor utilizando o bubblesort
	return vetor_ordenado;
}
ws *selecao(ws *ps, long long int *vetor_ordenado, int numero_de_palavras, FILE *arq_saida)
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
	int numero_de_palavras, i, tamanho_palavra_pesquisada;//declaração de variavéis
	long long int *vetor_ordenado, *vetor;
	w *palavras;//declaração da struct 
	ws *ps;//declaração da struct que receberá as palavras selecionadas 
	char palavra_pesquisada_leitura[tamanho]="b";//olhar a função de passar de maiuscula para minuscula 
	char *palavra_pesquisada;
	palavras = (w *) malloc(numero_de_palavras * sizeof(w));//aloca palavra que é do tipo w, struct 
	ps= (ws *) malloc(numero_de_palavras * sizeof(ws));//aloca palavra que é do tipo ws, struct 
	while(fscanf(arq, "%d", &numero_de_palavras) != EOF)//enquanto i for menor que o número de palavras ele faz a leitura das palavras 
	{
		for(i=0;i<numero_de_palavras;i++)
		{
			fscanf(arq, "%lli", &palavras[i].peso);//faz leitura das palavras
			fgets(palavras[i].word,tamanho,arq);
		}
	}
	vetor_ordenado = (long long int*)malloc(numero_de_palavras * sizeof(long long int*));//aloca vetor ordenado 
	vetor = (long long int*)malloc(numero_de_palavras * sizeof(long long int*));//aloca vetor
	tamanho_palavra_pesquisada=strlen(palavra_pesquisada_leitura);//retorna o tamanho da palavra
	palavra_pesquisada=min(palavra_pesquisada_leitura, tamanho_palavra_pesquisada);
	ps=seleciona_palavra(ps,tamanho_palavra_pesquisada, palavras, palavra_pesquisada, numero_de_palavras);//responsável por selecionar as palavras que serão utilizadas 
	vetor_ordenado=vetor_maiores(ps, tamanho_palavra_pesquisada, vetor_ordenado, vetor, numero_de_palavras);
	ps=selecao(ps, vetor_ordenado, numero_de_palavras, arq_saida);
	return 0;
}
	
