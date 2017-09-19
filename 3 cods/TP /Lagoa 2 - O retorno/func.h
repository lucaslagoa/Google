#ifndef func_h
#define func_h
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct palavra//struct palavra
{
	int peso;
	char word[50];
}w;

char *min(char *palavra_pesquisada_leitura, int tamanho_palavra_pesquisada);
void seleciona_palavra (char *palavra_pesquisada, int numero_de_palavras,w *ps);

#endif
