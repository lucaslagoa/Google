#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "entrada.h"
#include "GUI/gui.h"

vocabulario * leitura_Arq(char *nomeArq){
	int quant,i=0,k=0;
	char esp;
	FILE *arq;
	arq=fopen(nomeArq,"r");
	fscanf(arq,"%d",&quant);
	voc=(vocabulario *)malloc(quant * sizeof(vocabulario));
	while(k<quant){
		fscanf(arq,"%li",&voc[i].grau);
		fscanf(arq,"%c",&esp);
		fscanf(arq,"%s",voc[i].nome);
		voc[i].quant = quant;
		i++;
		k++;
	}
	
	fclose(arq);	
	return voc;
}
void encontraPalavra(char *pala){
	int i,j,tamPala,k,tam=0;
	int quant = voc[0].quant;
	
	i=0;
	vocabulario *result;
	result=(vocabulario *)malloc(1*sizeof(vocabulario));
	tamPala=strlen(pala);
	while(i<quant){
		j=0;
		
		k=0;
		while(j<tamPala && pala[j]==voc[i].nome[j] ){
			if(pala[j]==voc[i].nome[j]){
				k++;
			}
			j++;
		}
		if(k==tamPala){
			
			result[tam]=voc[i];
			tam++;
			result=(vocabulario *)realloc(result,(tam+1)*sizeof(vocabulario));
		}
		i++;
	}
	Quick(result,0,tam-1);
	i=0;
	

	char * result_str;
	clean_text_view ();
	
	while(i<tam){
		result_str = strcat(result[i].nome, "\n");
   		print_text_view (result_str);
   		
   		i++;
   }
}

void Quick(vocabulario *vetor, int inicio, int fim){
   
   int  i, j, meio;
   vocabulario pivo,aux;
   
   i = inicio;
   j = fim;
   
   meio = (int) ((i + j) / 2);
   pivo = vetor[meio];
   
   do{
      while (vetor[i].grau < pivo.grau) i = i + 1;
      while (vetor[j].grau > pivo.grau) j = j - 1;
      
      if(i <= j){
         aux = vetor[i];
         vetor[i] = vetor[j];
         vetor[j] = aux;
         i = i + 1;
         j = j - 1;
      }
   }while(j > i);
   
   if(inicio < j) Quick(vetor, inicio, j);
   if(i < fim) Quick(vetor, i, fim); 
}
