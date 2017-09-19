#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "GUI/gui.h"
#include "entrada.h"

int main (int argc, char *argv[]) {
	voc = leitura_Arq("lista_1.txt");
	interface(argc, argv);
	
	return 0;
}
