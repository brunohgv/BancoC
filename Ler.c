#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<time.h>




main()
{
	setlocale(LC_ALL, "portuguese");
	
	
	int num_clientes;
	
	FILE *arq;
	arq = fopen("num_clientes.txt", "r");
	
	fread(&num_clientes, sizeof(int), 1, arq);
	fclose(arq);
	
	
	printf("%i\n", num_clientes);	
	
	
	
	system("pause");
}


