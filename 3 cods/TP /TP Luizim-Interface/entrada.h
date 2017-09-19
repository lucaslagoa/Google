typedef struct{
	long int grau;
	int quant;
	char nome[100];
}vocabulario;

void encontraPalavra(char *pala);
void Quick(vocabulario *vetor, int inicio, int fim);
vocabulario *leitura_Arq(char *nomeArq);

vocabulario *voc;


