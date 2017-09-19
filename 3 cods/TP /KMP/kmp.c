#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define tamanho 100
typedef struct palavras
{
	long int peso;
	char word[tamanho];
}w;
typedef struct selecao
{
	int *vetor_selec;
	long int *vetor_peso;
	int k;
}sel;
	
sel kmp(int tam_palavra_user, w *palavra, int numero_de_palavras, sel s, char *palavra_usuario)
{
	int i,j, cont=0, k=0;
	for(i=0;i<numero_de_palavras;i++)
	{
		cont=0;
		for(j=tam_palavra_user;j>0;j--)
		{
			if(palavra_usuario[j-1]==palavra[i].word[j])
			{
				cont++;
				if(cont==tam_palavra_user)
				{
					s.vetor_selec[k]=i;
					s.vetor_peso[k]=palavra[i].peso;
					k++;
				}
			}
		}
	}
	s.k=k;//retorna o valor que eu preciso 
	return s;
}
sel ordena(int numero_de_palavras, w *palavra, sel s)
{
	int i, posicao;
	for(i=0;i<s.k;i++)
	{
		posicao=s.vetor_selec[i];
		s.vetor_peso[i]=palavra[posicao].peso;
	}
	return s;
}
sel bubble_sort(sel s)
{
	int i, j, aux;
	for (i=s.k-1;i>=1;i--) 
	{
		for (j=0;j<i;j++) 
		{
			if (s.vetor_peso[j]< s.vetor_peso[j+1]) 
			{
				aux=s.vetor_peso[j];
				s.vetor_peso[j]=s.vetor_peso[j+1];
				s.vetor_peso[j+1]=aux;
			}
		}
	}
	return s;
}

void func_imprime(w *palavra, sel s, long int *vetor_ordenado, int k)
{
	int i, posicao=0, j=0;
	s=bubble_sort(s);
	while(j<k)
	{
		for(i=0;i<s.k;i++)
		{
			posicao=s.vetor_selec[i];
			if(s.vetor_peso[j]==palavra[posicao].peso)
			{
				printf("%s", palavra[posicao].word);
			}
		}
		j++;
	}	
}			
int main()
{
	FILE *arq;//declaração arquivo de entrada 
	arq=fopen("entrada.txt", "r");
	int numero_de_palavras, i, flag=0, tam_palavra_user, k;
	long int *vetor_ordenado;
	w *palavra;//declaração da struct 
	sel s;
	//ws *ps;//declaração da struct que receberá as palavras selecionadas 
	char *palavra_usuario="hentai";
	while(fscanf(arq, "%d", &numero_de_palavras) != EOF)//enquanto i for menor que o número de palavras ele faz a leitura das palavras 
	{	
		if(flag==0)
		{
			s.vetor_selec = (int *) malloc(numero_de_palavras * sizeof(int));
			vetor_ordenado = (long int*) malloc(numero_de_palavras * sizeof(long int));
			s.vetor_peso = (long int *) malloc(numero_de_palavras * sizeof(long int));
			palavra = (w *) malloc(numero_de_palavras * sizeof(w));//aloca palavra que é do tipo w, struct 
			flag++;
		}
		for(i=0;i<numero_de_palavras;i++)
		{
			fscanf(arq, "%li", &palavra[i].peso);//faz leitura das palavras
			fgets(palavra[i].word,tamanho,arq);
		}
	}
	printf("Digite k: ");
	scanf("%d", &k);
	tam_palavra_user=strlen(palavra_usuario);
	s=kmp(tam_palavra_user, palavra, numero_de_palavras, s, palavra_usuario);
	s=ordena(numero_de_palavras, palavra, s);
	func_imprime(palavra, s, vetor_ordenado, k);
	return 0;
}
