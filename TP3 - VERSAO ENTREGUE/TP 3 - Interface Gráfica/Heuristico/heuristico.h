#ifndef heuristico_h
#define heuristico_h
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define tamanho 100

struct timeval inicio, final;

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

char *min(char *palavra_digitada_usuario, int tam_palavra_user);
sel h(int tam_palavra_user, w *palavra, int numero_de_palavras, sel s, char *palavra_usuario);
sel ordena(int numero_de_palavras, w *palavra, sel s);
sel bubble_sort(sel s);
void func_imprime(w *palavra, sel s, long int *vetor_ordenado, int k);


#endif

