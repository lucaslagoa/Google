//********************************************************
//* Aluno: Lucas Felix e Lucas Lagoa                     *
//* Professor: Leonardo Rocha                            *
//* Matéria: Algoritmos e estrutura de dados III         *
//********************************************************
#include "kmp.h"

int main(int argc, char *argv[]){
	if(argc != 5){
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
	sel s;
	//ws *ps;//declaração da struct que receberá as palavras selecionadas 
	char *palavra_digitada_usuario=argv[3];
	char *palavra_usuario;
	k=atoi(argv[4]);
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

	tam_palavra_user=strlen(palavra_digitada_usuario);
	palavra_usuario=min(palavra_digitada_usuario, tam_palavra_user);
	s=h(tam_palavra_user, palavra, numero_de_palavras, s, palavra_usuario);
	s=ordena(numero_de_palavras, palavra, s);
	func_imprime(palavra, s, vetor_ordenado, k);
	gettimeofday(&final, NULL);//função de tempo
	tmili = (int) (1000 * (final.tv_sec - inicio.tv_sec) + (final.tv_usec - inicio.tv_usec) / 1000);//função de tempo
	//printf("\ntempo decorrido: %d ms\n", tmili); //função de tempo
	return 0;
}
