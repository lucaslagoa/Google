#ifndef kmp_h
#define kmp_h
#include <time.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define tamanho 100

struct timeval inicio, final; 

typedef struct palavras //struct que pega os pesos e as palavras do arquivo
{
	long int peso;
	char word[tamanho];
}w;

typedef struct selecao //struct que guarda as novas palavras selecionadas e os pesos
{
	int *vetor_selec;
	long int *vetor_peso;
	int k;
}sel;

/* cabeçalho das funções utilizadas no programa */

char *min(char *palavra_digitada_usuario, int tam_palavra_user);
sel h(int tam_palavra_user, w *palavra, int numero_de_palavras, sel s, char *palavra_usuario);
sel ordena(int numero_de_palavras, w *palavra, sel s);
sel bubble_sort(sel s);
void func_imprime(w *palavra, sel s, long int *vetor_ordenado, int k);


#endif

