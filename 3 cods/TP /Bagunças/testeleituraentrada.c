#include <stdio.h>
#include <stdlib.h>
int main(){
	FILE *arq;
	arq=fopen("entrada2.txt", "r");
	char a, c[5];
	int i=0;
	fscanf(arq, "%c", &a);
	while(!feof(arq))
	{
		fscanf(arq, "%c", &c[i]);
		if((c[i]>=64 && c[i]<=90)||(c[i]>=48 && c[i]<=58)||(c[i]>=97 &&c[i]<=122))
		{
			printf("%c\n", c[i]);
		}
		i++;
	}
	
	return 0;
}
