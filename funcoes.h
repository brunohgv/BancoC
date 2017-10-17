

//Ps.: A contagem do FOR vai at� "j<100", por estar predefinido um vetor com 100 espa�os para conta (sem aloca��o din�mica implementada).


//FUN��O DE VALIDA��O (L� AG�NCIA, CONTA, SENHA E COMPARA. RETORNA 1 SE A VALIDA��O FOR CONFIRMADA.)

int validar(Cliente clientes[], int* origem)
{

	int j;
    int aux_agencia, aux_conta;
	char senha1[6];
	
	//CAPTURA DE DADOS (AG�NCIA, CONTA, SENHA)
	fflush(stdin);
	printf("\nDigite o n�mero da ag�ncia: ");
    scanf("%i", &aux_agencia);

    fflush(stdin);
    printf("Digite o n�mero da conta: ");
    scanf ("%i", &aux_conta);

    fflush(stdin);
    printf("\nDigite sua senha: ");
    gets(senha1);


	/*FUN��O QUE COMPARA O N� DE AG�NCIA, CONTA E SENHA DIGITADOS*/
	for(j=0; j<100; j++)
        {
            if(clientes[j].conta.agencia == aux_agencia && clientes[j].conta.numero == aux_conta)
            {


                if (strcmp(clientes[j].conta.senha, senha1) == 0)
                    {
                        
						printf("VALIDA��O BEM SUCEDIDA!");
						*origem = j;
						return 1;
                    }
				else
				{
				printf("\n*****SENHA INCORRETA!*****");
				}

            }else if (j==99)
                {
                    printf("\nAG�NCIA OU CONTA INV�LIDA!");
                    break;
                }

        }

}




//FUN��O DE VALIDA��O DA CONTA DESTINO EM UMA TRANSFER�NCIA (L� AG�NCIA E CONTA E COMPARA. RETORNA 1 SE A VALIDA��O FOR CONFIRMADA.)

int validar_destino(Cliente clientes[], int* destino)
{

    int j;
    int aux_agencia2, aux_conta2;

    fflush(stdin);

        printf("\nDigite o n�mero da ag�ncia: ");
        scanf("%d", &aux_agencia2);

        fflush(stdin);
        printf("Digite o n�mero da conta: ");
        scanf ("%d",&aux_conta2);


        for(j=0; j<100; j++)
            {
                if(clientes[j].conta.agencia == aux_agencia2 && clientes[j].conta.numero == aux_conta2)
                {
                    *destino = j;
                    return 1;

                }else if (j==99)
                    {
                        printf("\nAG�NCIA OU CONTA INV�LIDA!");
                        break;
                    }

            }

}

//FUN��O SALDO:

void saldo(Cliente clientes[], int *origem)
{

        printf("Seu saldo � de R$%.2f \n",clientes[*origem].conta.saldo);

}


//FUN��O SAQUE:

void saque(Cliente clientes[], int *origem)
{
    float valor;

    printf("Seu saldo � de R$%.2f \n",clientes[*origem].conta.saldo);

    printf("Valor do saque: ");
    fflush(stdin);
    scanf("%f", &valor);
    clientes[*origem].conta.saldo = clientes[*origem].conta.saldo - valor;

    printf("Saque realizado com sucesso! Retire o dinheiro no local indicado.\n");

    printf("Novo saldo: R$%.2f \n", clientes[*origem].conta.saldo);


}


//FUN��O DEP�SITO:

void deposito(Cliente clientes[], int *origem)
{
    float valor;

    printf("Seu saldo � de R$%.2f \n",clientes[*origem].conta.saldo);

    printf("Valor do dep�sito: ");
    fflush(stdin);
    scanf("%f", &valor);
    clientes[*origem].conta.saldo = clientes[*origem].conta.saldo - valor;

    printf("Dep�sito realizado com sucesso!\n");
    printf("Novo saldo: R$%.2f \n", clientes[*origem].conta.saldo);

}




//FUN��O TRANSFER�NCIA:

void transferencia(Cliente clientes[], int* origem, int* destino)
{
    float valor;

   printf("Seu saldo � de R$%.2f \n", clientes[*origem].conta.saldo);

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

            printf("Tranfer�ncia realizada com sucesso!\n");
            printf("Novo saldo: R$%.2f \n", clientes[*origem].conta.saldo);

            } else printf("Saldo insuficiente!\n");


    }


}









