//********************************************************
//* Aluno: Lucas Felix e Lucas Lagoa                     *
//* Professor: Leonardo Rocha                            *
//* Matéria: Algoritmos e estrutura de dados III         *
//********************************************************
#include "func.h"
int main(int argc, char *argv[]){
	if(argc != 4){
		printf("Os parametros foram passados de forma incorreta\n");
		 exit(0);
	}

	FILE *arq_entrada;//declaração dos arquivos de entrada e saída
	int tmili;//função de tempo
	gettimeofday(&inicio, NULL);//função de tempo
	arq_entrada=fopen(argv[2], "r");//arquivo de entrada
	int numero_de_palavras=0,i=0, tamanho_palavra_pesquisada=0;//declaração de variavéis
	w *ps;	
	char *palavra_selecionada=argv[3];
	
	
	while(fscanf(arq_entrada, "%d", &numero_de_palavras) != EOF) {
		
		ps = (w *) malloc(numero_de_palavras * sizeof(w));//aloca palavra que é do tipo w, struct 

		for(i=0;i<numero_de_palavras;i++){

			fscanf(arq_entrada, "%d", &ps[i].peso);//faz leitura das palavras
			fgets(ps[i].word,50,arq_entrada);

		}
	}

	//printf("Digite a palavra a ser pesquisada\n");
	//scanf("%s", palavra_selecionada);
	tamanho_palavra_pesquisada=strlen(palavra_selecionada);
	palavra_selecionada = min(palavra_selecionada,tamanho_palavra_pesquisada);
	seleciona_palavra(palavra_selecionada,numero_de_palavras, ps);
	gettimeofday(&final, NULL);//função de tempo
	tmili = (int) (1000 * (final.tv_sec - inicio.tv_sec) + (final.tv_usec - inicio.tv_usec) / 1000);//função de tempo
	printf("\ntempo decorrido: %d ms\n", tmili); //função de tempo
	return 0;
}
