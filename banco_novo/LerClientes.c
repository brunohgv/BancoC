#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<time.h>

typedef struct
{
	long int numero;
	int agencia;
	char senha[6];
	float saldo;
}Conta;

typedef struct
{
	char nome[30];
	char cpf[11];
	int acessos;
	Conta conta;
}Cliente;


#include "funcoes.h"

typedef struct
{
	char nome[30];
	char cpf[11];
	int senha;
	int agencia;	
}Funcionario;

main()
{
	setlocale(LC_ALL, "portuguese");
	
	int num_clientes;
	
	FILE *arq2;
	arq2 = fopen("num_clientes.txt", "r");
	fread(&num_clientes, sizeof(int), 1, arq2);
	fclose(arq2);
	
	Cliente* cliente = (Cliente*)malloc(num_clientes*sizeof(Cliente));
	
	FILE *arq;
	arq = fopen("clientes.txt", "r");
	fread(&cliente, sizeof(Cliente), num_clientes, arq);
	fclose(arq);		
	
	int i;
	
	for(i=0;i<=num_clientes;i++)
	{
		printf("Nome: %s\n", cliente[i].nome);
		printf("CPF: %s\n", cliente[i].cpf);
		printf("Agencia: %i\n", cliente[i].conta.agencia);
		printf("Num conta: %i\n", cliente[i].conta.numero);
		printf("senha: %s\n\n", cliente[i].conta.senha);
	}
	
	
	
	
	system("pause");
}


