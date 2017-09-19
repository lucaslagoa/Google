#include "kmp.h"

struct timeval inicio, final;


char *min(char *palavra_digitada_usuario, int tam_palavra_user)
{/*função responsável para o tratamento da palavra recebida com a tabela ASCII
	caso a palavra seja maiuscula ou minuscula*/
	int i;
	for(i=0;i<tam_palavra_user;i++)
	{
		if((palavra_digitada_usuario[i]>=65)&&(palavra_digitada_usuario[i]<=90)&&(palavra_digitada_usuario[i]>=49))
		{
			palavra_digitada_usuario[i]=palavra_digitada_usuario[i]+32;
		}
		else if((palavra_digitada_usuario[i]>=48)&&(palavra_digitada_usuario[i]<=57))
		{
			palavra_digitada_usuario[i]=palavra_digitada_usuario[i]-32;
		}
	}
	return palavra_digitada_usuario;
}	

sel h(int tam_palavra_user, w *palavra, int numero_de_palavras, sel s, char *palavra_usuario)
{ /* função responsável por realizar a comparação da palavra digitada com as palavras que contém no arquivo
	de entrada, fazendo as devidas verificações
  */
	int i,j, cont=0, k=0;
	for(i=0;i<numero_de_palavras;i++)
	{
		cont=0;
		for(j=tam_palavra_user;j>0;j--)
		{
			if((palavra_usuario[j-1]==palavra[i].word[j])||(palavra_usuario[j-1]==palavra[i].word[j]+32)||(palavra_usuario[j-1]==palavra[i].word[j]-32))
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
// função que ordena os valores de acordo com o peso das palavras selecionadas

	int i, posicao;
	for(i=0;i<s.k;i++)
	{
		posicao=s.vetor_selec[i];
		s.vetor_peso[i]=palavra[posicao].peso;
	}
	return s;
}
sel bubble_sort(sel s)
{ //método de ordenação implementado para ordenar o vetor de pesos
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
{ //função que imprime os valores selecionados e ordenados previamente
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

