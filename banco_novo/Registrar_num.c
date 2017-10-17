#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<time.h>
#include<string.h>

typedef struct
{
	int numero;
	int agencia;
	char senha[6];
	float saldo;
}Conta;

typedef struct
{
	char nome[40];
	char cpf[11];
	int acessos;
	Conta conta;
}Cliente;


typedef struct
{
	char nome[50];
	char cpf[11];
	int senha;
	int agencia;	
}Funcionario;


main()
{
	
	FILE *arq;
	
	arq = fopen("num_clientes.txt", "w");
	if(arq == NULL)
	{
		printf("Falha em abrir Arquivo num.");
	}
	else
	{
		arq = fopen("num_clientes.txt", "w");
		int num_clientes = -1;
		
		fwrite(&num_clientes, sizeof(int), 1, arq);
		fclose(arq);
		
		printf(" Número '%i' salvo em num_clientes.txt! ", num_clientes);
	}	
	
	
}
	

