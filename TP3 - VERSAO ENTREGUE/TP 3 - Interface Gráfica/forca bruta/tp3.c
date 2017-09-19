//********************************************************
//* Aluno: Lucas Felix e Lucas Lagoa                     *
//* Professor: Leonardo Rocha                            *
//* Matéria: Algoritmos e estrutura de dados III         *
//********************************************************
#include "func.h"


int main(int argc, char *argv[]){

	if(argc != 5){
		printf("Os parametros foram passados de forma incorreta\n");
		 exit(0);
	}
	FILE *arq;//declaração dos arquivos de entrada e saída
	arq=fopen(argv[2], "r");//arquivo de entrada
	int numero_de_palavras, i, tamanho_palavra_pesquisada, q, flag;//declaração de variavéis
	long long int *vetor_ordenado, *vetor;
	w *palavras;//declaração da struct 
	ws *ps;//declaração da struct que receberá as palavras selecionadas 
	char *palavra_pesquisada_leitura=argv[3];
	char *palavra_pesquisada;
	q=atoi(argv[4]);
	while(fscanf(arq, "%d", &numero_de_palavras) != EOF)//realiza a leitura do arquivo de acordo com o primeiro parâmetro do arquivo 
	{	
		if(flag==0)
		{
			palavras = (w *) malloc(numero_de_palavras * sizeof(w));//aloca palavra que é do tipo w, struct 
			ps= (ws *) malloc(numero_de_palavras * sizeof(ws));//aloca palavra que é do tipo ws, struct 
			flag++;
		}
		for(i=0;i<numero_de_palavras;i++)
		{
			fscanf(arq, "%lli", &palavras[i].peso);//faz leitura dos pesos 
			fgets(palavras[i].word,tamanho,arq); //faz leitura das palavras
		}
	}
	vetor_ordenado = (long long int*)malloc(numero_de_palavras * sizeof(long long int*));//aloca vetor ordenado 
	vetor = (long long int*)malloc(numero_de_palavras * sizeof(long long int*));//aloca vetor
	tamanho_palavra_pesquisada=strlen(palavra_pesquisada_leitura);//retorna o tamanho da palavra
	palavra_pesquisada=min(palavra_pesquisada_leitura, tamanho_palavra_pesquisada);
	ps=seleciona_palavra(ps,tamanho_palavra_pesquisada, palavras, palavra_pesquisada, numero_de_palavras);//responsável por selecionar as palavras que serão utilizadas 
	vetor_ordenado=vetor_maiores(ps, tamanho_palavra_pesquisada, vetor_ordenado, vetor, numero_de_palavras);
	ps=selecao(ps, vetor_ordenado, numero_de_palavras, q);
	return 0;
}
	
