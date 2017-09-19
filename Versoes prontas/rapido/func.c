#include "func.h"
struct timeval inicio, final;
int *bubble_sort(int *vetor_peso, int numero_de_palavras)
{
	int i, j, aux;
	for (i=numero_de_palavras;i>=1;i--) 
	{
		for (j=0;j<i;j++) 
		{

			if (vetor_peso[j]<vetor_peso[j+1]) 
			{
				aux=vetor_peso[j];
				vetor_peso[j]=vetor_peso[j+1];
				vetor_peso[j+1]=aux;
			}
		}
	}
	return vetor_peso;
}
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

void seleciona_palavra (char *palavra_pesquisada, int numero_de_palavras, w *ps){

	int i=0, j=0,cont=0,k=0,tamanho_palavra_pesquisada=0,*vetor_peso, *vetor_ordenado;
	tamanho_palavra_pesquisada=strlen(palavra_pesquisada);
	vetor_peso = (int*)malloc(numero_de_palavras * sizeof(int*));
	vetor_ordenado = (int*)malloc(numero_de_palavras * sizeof(int*));
	for(i=0;i<numero_de_palavras;i++) 
	{
		j=0;
		cont=0;
		if(palavra_pesquisada[j]==ps[i].word[j+1])
		{
			for(j=1;j< tamanho_palavra_pesquisada; j++)
			{
				if((ps[i].word[j+1])!=(palavra_pesquisada[j]))
				{
					cont=1;
				}
			}
			for(j=0;j<50;j++)
			{
				if(cont == 0)
				{ 
					vetor_peso[k] = ps[i].peso;
					ps[k].word_select[j] = ps[i].word[j+1];
					k++;
				}
			}	
		}
	}
	vetor_ordenado=bubble_sort(vetor_peso, numero_de_palavras);
	for(i=0;i<k;i++) 
	{
		for(j=0;j<k;j++)
		{
			if(vetor_ordenado[i]==ps[j].peso)
			{
				printf("%s", ps[i].word_select);
			}
		}
	}

}
