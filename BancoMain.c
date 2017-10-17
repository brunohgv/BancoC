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

void cadastrarCliente(Cliente* cliente, int num_clientes)
{	
	
	fflush(stdin);
	printf("Nome: ");
	gets(cliente[num_clientes].nome);
	fflush(stdin);
	printf("CPF: ");
	gets(cliente[num_clientes].cpf);
	fflush(stdin);
	cliente[num_clientes].conta.numero = num_clientes;
	printf("Agência: ");
	scanf("%i", &cliente[num_clientes].conta.agencia);
	fflush(stdin);
	printf("Senha: ");
	gets(cliente[num_clientes].conta.senha);
	fflush(stdin);
	printf("O numero de sua conta é: %i\n\n", num_clientes);

}

void logo()
{
	printf("----------------------------------------\n");
	printf("                        Bem vindo ao BCC\n");
	printf("----------------------------------------\n");
}



main()
{
	system("color 2E");
	setlocale(LC_ALL, "portuguese");
	
	int senha_gerente = 123456;
	
	logo();
	
	int opcao=0;
	
	int num_clientes;
	
	FILE *arq;
	if(arq = fopen("num_clientes.txt", "r") == NULL)
	{
		printf("Falha em abrir Arquivo num.");
	}
	else
	{
		arq = fopen("num_clientes.txt", "r");
		fread(&num_clientes, sizeof(int), 1, arq);
		fclose(arq);
	}
	
	Cliente* cliente = (Cliente*)malloc(num_clientes*sizeof(Cliente));
	
	
	if(arq = fopen("clientes.txt", "r") == NULL)
	{
		printf("Falha em abrir Arquivo Cliente.");
	}
	else
	{
		arq = fopen("clientes.txt", "r");
		fread(&num_clientes, sizeof(int), 1, arq);
		fclose(arq);
	}
	
	
	
	printf("\nO que deseja?\n\n1 - Acesso Cliente\n2 - Acesso funcionário\n");
	scanf("%i", &opcao);
	
	//menu inicial
	
	switch(opcao)
	{
		case 1:
			{
				//Colocar sistema de login
				system("cls");
				logo();		
				
				int validacao = 0;
				int atual;
				while(validacao != 1)
				{
					validacao = validar(cliente, atual);	
				}
				printf("\nAcesso Cliente\n\n1 - Consultar saldo\n2 - Depósito\n3 - Saque\n4 - Transferência\n5 - Extrato\n6 - Empréstimo\n7 - Calculadora de juros\n");
				scanf("%i", &opcao);
				switch(opcao)
				{
					case 1:
						{
							
							break;
						}
					case 2:
						{
							
							break;	
						}
					case 3:
						{
						
							break;	
						}
					case 4:
						{
							
							break;
						}
					case 5:
						{
							
							break;	
						}
					case 6:
						{
						
							break;	
						}
					case 7:
						{
						
							break;	
						}
					
				}	
				break;	
			}
		case 2:
			{
				//Colocar sistema de Login
				
				//menu acesso funcionário
				system("cls");
				logo();
				printf("\nAcesso Funcionário\n\n1 - Cadastrar cliente\n2 - Remover cliente");
				scanf("%i", &opcao);
				switch(opcao)	
				{	
					case 1:
						{
							num_clientes++;
							cliente = (Cliente*)realloc(cliente, num_clientes*sizeof(Cliente));
							cadastrarCliente(cliente, num_clientes);
							break;
						}
					case 2:
						{
							
							break;
						}
				}
				break;
			}
	}
	
	printf("Preparando para salvar arquivos...\n");

	if (arq = fopen("num_clientes.txt", "w") != 1)
	{
		printf("Falha em salvar Arquivo num_clientes.txt!");
	}
	else
	{
		arq = fopen("num_clientes.txt", "w");
		fwrite(&num_clientes, sizeof(int), 1, arq);
		fclose(arq);
			
		printf("Lista de clientes atualizada!\n");
	}

	if(arq = fopen("clientes.txt", "w") != 1)
	{
		printf("Falha em salvar Arquivo clientes.txt!");
	}
	else
	{
		arq = fopen("clientes.txt", "w");
		fwrite(&cliente, sizeof(Cliente), num_clientes, arq);	
		fclose(arq);
		
		printf("numero de clientes salvo!\n");
	}
	
	
	
	system("pause");
}


