#include "forcabruta.h"

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

	int i=0, j=0,cont=0,k=0,tamanho_palavra_pesquisada=0,*vetor1,x=0;
	char *vetor;
	tamanho_palavra_pesquisada=strlen(palavra_pesquisada);
	vetor = (char*)malloc(numero_de_palavras * sizeof(char*));
	vetor1 = (int*)malloc(numero_de_palavras * sizeof(int*));
	

	for(i=0;i < numero_de_palavras; i++) {//numero de palavras totais do dicionário
		j=0;
		cont=0;

		if(palavra_pesquisada[j] == ps[i].word[j+1]) {
			for(j=1;j< tamanho_palavra_pesquisada; j++){
				if( (ps[i].word[j+1]) != (palavra_pesquisada[j]) ) {
					cont=1;
				}
			}
			
			for(x=0;x<50;x++){
				if (cont == 0){ 
					vetor1[k] = ps[i].peso;
					vetor[k] = ps[i].word[x+1];
					k++;
				}
			}	
		}
	}

	/*if (aux == 1) {
		printf("Não existe palavra com esse prefixo.\n");
	}*/

	for(i=0;i < k; i++) {
		printf("%c",vetor[i]);
	}

}

/*int *bubble_sort(int *vetor, int numero_de_palavras)
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
*/

