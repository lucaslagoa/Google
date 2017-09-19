//********************************************************
//* Aluno: Lucas Felix e Lucas Lagoa                     *
//* Professor: Leonardo Rocha                            *
//* Matéria: Algoritmos e estrutura de dados III         *
//********************************************************
#include "kmp.h"

int main(int argc, char *argv[]){
	if(argc != 5){  //parâmetros do argc para a leitura
		printf("Os parametros foram passados de forma incorreta\n");
		 exit(0);
	}
	FILE *arq;//declaração arquivo de entrada 
	int tmili;//função de tempo
	gettimeofday(&inicio, NULL);//função de tempo
	arq=fopen(argv[2], "r");
	int numero_de_palavras, i, flag=0, tam_palavra_user, k;
	long int *vetor_ordenado;
	w *palavra;//declaração da struct 
	sel s; //declaração da struct com as palavras selecionadas
	char *palavra_digitada_usuario=argv[3]; //recebimento da palavra digitada pelo usuário pelo parâmetro
	char *palavra_usuario; 
	k=atoi(argv[4]); //recebimento do tamanho de palavras a serem impressas 
	while(fscanf(arq, "%d", &numero_de_palavras) != EOF) //leitura das informações contidas no arquivo, começando pelo número de palavras 
	{	
		if(flag==0)  //flag realizada para não haver a necessidade de alocar mais do que é necessário
		{
			s.vetor_selec = (int *) malloc(numero_de_palavras * sizeof(int)); //alocação dos vetores que serão utilizados pelo programa
			vetor_ordenado = (long int*) malloc(numero_de_palavras * sizeof(long int));
			s.vetor_peso = (long int *) malloc(numero_de_palavras * sizeof(long int));
			palavra = (w *) malloc(numero_de_palavras * sizeof(w));//aloca palavra que é do tipo w, struct 
			flag++;
		}
		for(i=0;i<numero_de_palavras;i++) //leitura das palavras e seus respectivos pesos
		{
			fscanf(arq, "%li", &palavra[i].peso); 
			fgets(palavra[i].word,tamanho,arq);
		}
	}

	tam_palavra_user=strlen(palavra_digitada_usuario); //leitura do tamanho da palavra lida no momento
	palavra_usuario=min(palavra_digitada_usuario, tam_palavra_user); //chamada da função min que realiza as modificações necessárias para as palavras
	s=h(tam_palavra_user, palavra, numero_de_palavras, s, palavra_usuario); //chamada da função h que realiza as operações de verificar se a palavra pode ser uma possível solução
	s=ordena(numero_de_palavras, palavra, s); //chamada da função que ordena de acordo com o peso 
	func_imprime(palavra, s, vetor_ordenado, k); //chamada da função que imprime as palavras 
	gettimeofday(&final, NULL);//função de tempo
	tmili = (int) (1000 * (final.tv_sec - inicio.tv_sec) + (final.tv_usec - inicio.tv_usec) / 1000);//função de tempo
	printf("\ntempo decorrido: %d ms\n", tmili); //função de tempo
	return 0;
}
