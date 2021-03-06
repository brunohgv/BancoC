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
	char nome[50];
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
	printf("Ag�ncia: ");
	scanf("%i", &cliente[num_clientes].conta.agencia);
	fflush(stdin);
	
	printf("Senha: ");
	
	int i;
	fflush(stdin);
	for (i=0;i<6;i++)
	{
		cliente[num_clientes].conta.senha[i] = getch();
		putchar('*');
    }
    printf("\n");
	fflush(stdin);
	
	printf("O numero de sua conta �: %i\n\n", num_clientes);
	cliente[num_clientes].conta.saldo = 0;
	cliente[num_clientes].acessos = 0;

}

void logo()
{
	printf("----------------------------------------\n");
	printf("                        Bem vindo ao BCC\n");
	printf("----------------------------------------\n");
}



main()
{
	system("color 1F");
	setlocale(LC_ALL, "portuguese");
	
	int senha_gerente = 123456;
	
	int opcao=9;
	
	int num_clientes;
	
	FILE *arq;
	arq = fopen("num_clientes.txt", "r");
	if(arq == NULL)
	{
		printf("Falha em abrir Arquivo num.\n");
	}
	else
	{
		fread(&num_clientes, sizeof(int), 1, arq);
		fclose(arq);
	}
	
	Cliente* cliente = (Cliente*)malloc((num_clientes+2)*sizeof(Cliente));
	
	arq = fopen("clientes.txt", "r");
	if(arq == NULL)
	{
		printf("Falha em abrir Arquivo Cliente.\n");
	}
	else
	{	
		fread(cliente, sizeof(Cliente), num_clientes+2, arq);
		fclose(arq);
	}
	
	
	while(opcao != 0)
	{
		logo();
		printf("\nO que deseja?\n\n1 - Acesso Cliente\n2 - Acesso funcion�rio\n0 - Sair\n");
		scanf("%i", &opcao);
		
		//menu inicial
	
		switch(opcao)
		{
			case 1:
				{
					
					system("cls");
						
					
					int validacao = 0;
					int origem;
					int destino;
					
					//sistema de login
					while(validacao != 1 && validacao != 3)
					{
						logo();	
						printf("\nTela de acesso\n");
						validacao = validar(cliente, &origem, num_clientes);
						if(validacao != 3)
						{
							printf("\nDigite 1 para sair ou 2 para tentar novamente.\n");
							scanf("%i", &validacao);
							system("cls");
						}	
						if(validacao == 3)
						{
							system("pause");
						}
						
					}
					//Menu p�s login
					if(validacao == 3)
					{	
						while(opcao != 8)
						{
								
							system("cls");
							logo();
							
							printf("\nBem vindo(a), %s!\n\n1 - Consultar saldo\n2 - Dep�sito\n3 - Saque\n4 - Transfer�ncia\n5 - Extrato\n6 - Empr�stimo\n7 - Calculadora de juros\n8 - Sair\n", cliente[origem].nome);
							scanf("%i", &opcao);
							switch(opcao)
							{
								//consultar saldo
								case 1:
									{
										saldo(cliente, &origem);
										system("pause");
										system("cls");
										break;
									}
								//Ralizar dep�sito
								case 2:
									{
										deposito(cliente, &origem);
										system("pause");
										system("cls");
										break;	
									}
								//Realizar saque
								case 3:
									{
										saque(cliente, &origem);
										system("pause");
										system("cls");
										break;	
									}
								case 4:
									{
										validacao = validar_destino(cliente, &destino, num_clientes);
										if(validacao == 1)
										{
											transferencia(cliente, &origem, &destino, num_clientes);	
										}
										system("pause");
										system("cls");
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
								case 8:
									{
										system("cls");
										break;
									}
								
							}	
						}
					}
					break;	
				}
			case 2:
				{
					//Colocar sistema de Login
					
					//menu acesso funcion�rio
					system("cls");
					logo();
					printf("\nAcesso Funcion�rio\n\n1 - Cadastrar cliente\n2 - Remover cliente\n0 - Sair\n");
					scanf("%i", &opcao);
					switch(opcao)	
					{	
						case 1:
							{
								num_clientes++;
								cliente = (Cliente*)realloc(cliente, (num_clientes+2)*sizeof(Cliente));
								cadastrarCliente(cliente, num_clientes);
								system("pause");
								break;
							}
						case 2:
							{
								
								break;
							}
					}
					system("cls");
				
				}
		}
	}
	
	
	printf("Preparando para salvar arquivos...\n");

	arq = fopen("num_clientes.txt", "w");
	if (arq == NULL)
	{
		printf("Falha em salvar Arquivo num_clientes.txt!");
		fclose(arq);
	}
	else
	{
		fwrite(&num_clientes, sizeof(int), 1, arq);
        fclose(arq);
			
		printf("Lista de clientes atualizada: %i.\n", num_clientes+1);
	}

	arq = fopen("clientes.txt", "w");
	if(arq == NULL)
	{
		printf("Falha em salvar Arquivo clientes.txt!");
		fclose(arq);
	}
	else
	{
		fwrite(cliente, sizeof(Cliente), num_clientes+2, arq);	
		fclose(arq);
		
		printf("numero de clientes salvo!\n");
	}
	
	system("pause");
}


