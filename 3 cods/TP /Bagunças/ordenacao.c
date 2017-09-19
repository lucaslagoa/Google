#include <stdio.h>
int main(){
	int i=0, vetor_aux[3], aux=0, j=0, k=0, cont=0, vetor_ordenado[3];
	int numero_de_palavras=3;
	printf("Digite os valores do vetor ordenado");
	scanf("%d", &vetor_ordenado[0]);
	scanf("%d", &vetor_ordenado[1]);
	scanf("%d", &vetor_ordenado[2]);
	for(j=0;j<numero_de_palavras;j++)
	{
			
		for(i=0;i<numero_de_palavras;i++)
		{
			if(aux<=vetor_ordenado[i])
			{
				aux=vetor_ordenado[i];
				vetor_aux[j]=aux;
				printf("%d", vetor_aux[i]);
			}
			if(i==numero_de_palavras-1)
			{
				cont=0;
				while((k<numero_de_palavras)&&(cont<1))
				{
					if(vetor_aux[j]==vetor_ordenado[k])
					{
						vetor_ordenado[k]=0;
						cont++;
					}
					k++;
				}
			}
		}	
	}
	for(i=0;i<numero_de_palavras;i++)
	{
		printf("%d ", vetor_aux[i]);
	}
	return 0;
}
