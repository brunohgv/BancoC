#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<time.h>

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

main()
{
	setlocale(LC_ALL, "portuguese");
	FILE *arq;
	arq = fopen("clientes.txt", "r");
	
	
	Cliente cliente[10];
	
	fread(cliente, sizeof(Cliente), 10, arq);
	fclose(arq);
	
	int i;
	for(i=0;i<10;i++)
	{
		printf("nome: %s\nconta: %i\nagência: %i\nsenha: %s\n\n", cliente[i].nome, cliente[i].conta.numero, cliente[i].conta.agencia, cliente[i].conta.senha);
	}
	
	system("pause");
}


