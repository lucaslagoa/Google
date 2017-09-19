#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct palavra//struct palavra
{
	int peso;
	char word[50];
}w;

w *ps;

void seleciona_palavra (char palavra_pesquisada[100], int numero_de_palavras){

	int i=0, j=0,cont=0,k=0,tamanho_palavra_pesquisada=0,*vetor1, m=0;
	char *vetor;
	tamanho_palavra_pesquisada=strlen(palavra_pesquisada);
	vetor = (char*)malloc(numero_de_palavras * sizeof(char*));
	vetor1 = (int*)malloc(numero_de_palavras * sizeof(int*));
	//w* ps = (w*) malloc(numero_de_palavras * sizeof(w*));

	for(i=0;i < numero_de_palavras; i++) {//numero de palavras totais do dicionário
		j=0;
		cont=0;//tem que ser zero a cada palavra vetor = (int*)malloc(numero_de_palavras * sizeof(int*));
		if(palavra_pesquisada[j] == ps[i].word[j+1]) {
			for(j=1;j< tamanho_palavra_pesquisada; j++){
				//printf("TAM%d",tamanho_palavra_pesquisada);//vai até o tamanho do préfixo 
				if( (ps[i].word[j+1]) != (palavra_pesquisada[j]) ) {
					cont=1;
					//printf("CONT dentro %d",cont);
					break;
				}
			}
			if (cont == 0){ 
				vetor1[k] = ps[i].peso;
				m=0;
				while(m<50)
				{
					vetor[m]=ps[i].word[m];
					m++;
				}
				k++;
			}
				//printf("K %d",k);
				
			}

				/*if(cont==tamanho_palavra_pesquisada)//quer dizer que palavra é do tamanho do prefixo
				{

					strcpy(ps[k].word,palavras[i].word);
					ps[k].peso = palavras[i].peso;
					k++;
					ps[k+1].peso = -1;
					
				}
			}
			else 
			{
				i++;//se nao bater a primeira letra, automaticamente ja posso ir para proxima palavra
			}
			*/
		}
	for(i=0;i < k; i++){
			printf("%d\n",vetor1[i]);
	}
	for(i=0;i<50;i++)
	{
		printf("%c", vetor[i]);
	}
}

/*int *bubble_sort(int *vetor, int numero_de_palavras)
{
	int i, j, aux;
	for (i=numero_de_palavras;i>=1;i--) 
	{
		for (j=0;j<i;j++) 
		{

			if (vetor[j]<vetor[j+1]) 
			{
				printf("%d\n",vetor[j]);
				aux=vetor[j];
				vetor[j]=vetor[j+1];
				vetor[j+1]=aux;
			}
		}
	}


	return vetor;
}


int *vetor_maiores(w *ps, int tamanho_palavra_pesquisada, int *vetor_ordenado, int *vetor, int numero_de_palavras)
{
	int i=0;//aloco um vetor do tamanho do número de linhas da matriz
	while(i<50)//saber ao certo a quantidade de palavras que serão retornadas
	{
		vetor[i]=ps[i].peso;
		i++;
	}
	vetor_ordenado=bubble_sort(vetor, numero_de_palavras);//ordena o vetor utilizando o bubblesort
	return vetor_ordenado;
}
*/

/*void selecao(w* ps,int *vetor_ordenado, int numero_de_palavras)
{//função responsável de selecionar e printar as palavras que serão fornecidas pelo autocomplete
	int i=0, j=0, k=0;
	int tam = 0;
	int a = 0;
	//while(i<numero_de_palavras)
	FILE *arq_saida=fopen("saida.txt", "w");//arquivo de saída
	

	//printf("%s\n",ps[0].palavra_selecionada);

	for(i=0;i<numero_de_palavras;i++){

		//printf("%s\n",ps[i].palavra_selecionada);

		//while(j<numero_de_palavras)
		for(j=0;j<numero_de_palavras;j++){

			if(vetor_ordenado[i]==ps[j].peso){
				tam = strlen(ps[i].word);
				while(tam>a)
				{
					printf("%c", ps[i].word[a]);
					fprintf(arq_saida, "%c", ps[i].word[a]);
					a++;
				}
				a = 0;
			}
			
		}
		
	}
	fclose(arq_saida);
	//return ps;
}*/
int main(){

	FILE *arq_entrada;//declaração dos arquivos de entrada e saída
	arq_entrada=fopen("entrada.txt", "r");//arquivo de entrada
	int numero_de_palavras=0,i=0, tamanho_palavra_pesquisada=0;//declaração de variavéis
	char palavra_selecionada[100];
	//w *palavras;//declaração da struct 
	//char palavra_pesquisada[50]="b";
	//char auxiliar;
	

	while(fscanf(arq_entrada, "%d", &numero_de_palavras) != EOF)//enquanto i for menor que o número de palavras ele faz a leitura das palavras 
	{
		//lê a quantidade de palavras totais do arquivo
	//vetor_ordenado = (int*)malloc(numero_de_palavras * sizeof(int*));//aloca vetor ordenado 
	//vetor = (int*)malloc(numero_de_palavras * sizeof(int*));//aloca vetor
	ps = (w *) malloc(numero_de_palavras * sizeof(w));//aloca palavra que é do tipo w, struct 

		for(i=0;i<numero_de_palavras;i++){
			fscanf(arq_entrada, "%d", &ps[i].peso);//faz leitura das palavras
			//auxiliar=fgetc(arq_entrada);
			//fscanf(arq_entrada," ", auxiliar);
			fgets(ps[i].word,50,arq_entrada);

			printf("%d", ps[i].peso);
			printf("%s", ps[i].word);
		}


		//para n pergar o /n
		//vc cria string aux pra ler do arquivo
		//depois vc pega o strlen deles strlen(aux);
		//(usando for) palavra1[i] = aux[i] (aux ate o tamanho - 1)



	}

	printf("Digite a palavra a ser pesquisada\n");
	scanf("%s", palavra_selecionada);


	seleciona_palavra(palavra_selecionada,numero_de_palavras);

	//tamanho_palavra_pesquisada=strlen(palavra_pesquisada);//retorna o tamanho da palavra
	//w* ps = (w *) malloc(numero_de_palavras * sizeof(w));//aloca palavra que é do tipo w, struct 

	//ps = seleciona_palavra(tamanho_palavra_pesquisada, palavras, palavra_pesquisada, numero_de_palavras);

	/*printf("oi %s\n",ps[0].word);
	printf("oi %s\n",ps[1].word);
	printf("oi %s\n",ps[2].word);
	vetor_ordenado=vetor_maiores(ps, tamanho_palavra_pesquisada, vetor_ordenado, vetor, numero_de_palavras);
	printf("oi %d\n",vetor_ordenado[0]);
	printf("oi %d\n",vetor_ordenado[1]);
	printf("oi %d\n",vetor_ordenado[2]);
	//printf("%s\n",ps[0].palavra_selecionada);
	


	//selecao(ps, vetor_ordenado, numero_de_palavras);
	*/
	return 0;
}
