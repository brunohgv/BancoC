

//Ps.: A contagem do FOR vai até "j<100", por estar predefinido um vetor com 100 espaços para conta (sem alocação dinâmica implementada).


//FUNÇÃO DE VALIDAÇÃO (LÊ AGÊNCIA, CONTA, SENHA E COMPARA. RETORNA 1 SE A VALIDAÇÃO FOR CONFIRMADA.)

int validar(Cliente clientes[], int* origem)
{

	int j;
    int aux_agencia, aux_conta;
	char senha1[6];
	
	//CAPTURA DE DADOS (AGÊNCIA, CONTA, SENHA)
	fflush(stdin);
	printf("\nDigite o número da agência: ");
    scanf("%i", &aux_agencia);

    fflush(stdin);
    printf("Digite o número da conta: ");
    scanf ("%i", &aux_conta);

    fflush(stdin);
    printf("\nDigite sua senha: ");
    gets(senha1);


	/*FUNÇÃO QUE COMPARA O Nº DE AGÊNCIA, CONTA E SENHA DIGITADOS*/
	for(j=0; j<100; j++)
        {
            if(clientes[j].conta.agencia == aux_agencia && clientes[j].conta.numero == aux_conta)
            {


                if (strcmp(clientes[j].conta.senha, senha1) == 0)
                    {
                        
						printf("VALIDAÇÃO BEM SUCEDIDA!");
						*origem = j;
						return 1;
                    }
				else
				{
				printf("\n*****SENHA INCORRETA!*****");
				}

            }else if (j==99)
                {
                    printf("\nAGÊNCIA OU CONTA INVÁLIDA!");
                    break;
                }

        }

}




//FUNÇÃO DE VALIDAÇÃO DA CONTA DESTINO EM UMA TRANSFERÊNCIA (LÊ AGÊNCIA E CONTA E COMPARA. RETORNA 1 SE A VALIDAÇÃO FOR CONFIRMADA.)

int validar_destino(Cliente clientes[], int* destino)
{

    int j;
    int aux_agencia2, aux_conta2;

    fflush(stdin);

        printf("\nDigite o número da agência: ");
        scanf("%d", &aux_agencia2);

        fflush(stdin);
        printf("Digite o número da conta: ");
        scanf ("%d",&aux_conta2);


        for(j=0; j<100; j++)
            {
                if(clientes[j].conta.agencia == aux_agencia2 && clientes[j].conta.numero == aux_conta2)
                {
                    *destino = j;
                    return 1;

                }else if (j==99)
                    {
                        printf("\nAGÊNCIA OU CONTA INVÁLIDA!");
                        break;
                    }

            }

}

//FUNÇÃO SALDO:

void saldo(Cliente clientes[], int *origem)
{

        printf("Seu saldo é de R$%.2f \n",clientes[*origem].conta.saldo);

}


//FUNÇÃO SAQUE:

void saque(Cliente clientes[], int *origem)
{
    float valor;

    printf("Seu saldo é de R$%.2f \n",clientes[*origem].conta.saldo);

    printf("Valor do saque: ");
    fflush(stdin);
    scanf("%f", &valor);
    clientes[*origem].conta.saldo = clientes[*origem].conta.saldo - valor;

    printf("Saque realizado com sucesso! Retire o dinheiro no local indicado.\n");

    printf("Novo saldo: R$%.2f \n", clientes[*origem].conta.saldo);


}


//FUNÇÃO DEPÓSITO:

void deposito(Cliente clientes[], int *origem)
{
    float valor;

    printf("Seu saldo é de R$%.2f \n",clientes[*origem].conta.saldo);

    printf("Valor do depósito: ");
    fflush(stdin);
    scanf("%f", &valor);
    clientes[*origem].conta.saldo = clientes[*origem].conta.saldo - valor;

    printf("Depósito realizado com sucesso!\n");
    printf("Novo saldo: R$%.2f \n", clientes[*origem].conta.saldo);

}




//FUNÇÃO TRANSFERÊNCIA:

void transferencia(Cliente clientes[], int* origem, int* destino)
{
    float valor;

   printf("Seu saldo é de R$%.2f \n", clientes[*origem].conta.saldo);

    printf("Conta destino:\n");

    if(validar_destino(clientes, *destino) == 1)
    {

       printf("Valor a ser transferido: ");
       fflush(stdin);
       scanf("%f", &valor);

       if(valor >= clientes[*origem].conta.saldo)
            {

            clientes[*destino].conta.saldo = clientes[*destino].conta.saldo + valor;
            clientes[*origem].conta.saldo = clientes[*origem].conta.saldo - valor;

            printf("Tranferência realizada com sucesso!\n");
            printf("Novo saldo: R$%.2f \n", clientes[*origem].conta.saldo);

            } else printf("Saldo insuficiente!\n");


    }


}









