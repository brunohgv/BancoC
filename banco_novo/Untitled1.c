#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<time.h>

main()
{
	setlocale(LC_ALL, "portuguese");
	FILE *arq;
	arq = fopen("num_clientes.txt", "w");
	
	int num_clientes;
	
	scanf("%i", &num_clientes);
	
	fwrite(&num_clientes, sizeof(int), 1, arq);
	fclose(arq);
	
	system("pause");
}


