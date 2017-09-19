#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct palavra
{
	int peso;
	char word[50];
}w;
int main (){
	FILE *arq;
	int total_de_valores, i=0;
	w *palavras;
	arq=fopen("entrada.txt", "r");
	fscanf(arq, "%d", &total_de_valores);
	palavras = (w *) malloc(total_de_valores * sizeof(w));
	while(i<total_de_valores)
	{
		fscanf(arq, "%d %s", &palavras[i].peso, palavras[i].word);
		i++;
	}
	return 0;
}
