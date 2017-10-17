

//Ps.: A contagem do FOR vai at� "j<100", por estar predefinido um vetor com 100 espa�os para conta (sem aloca��o din�mica implementada).


//FUN��O DE VALIDA��O (L� AG�NCIA, CONTA, SENHA E COMPARA. RETORNA 1 SE A VALIDA��O FOR CONFIRMADA.)

int validar(Cliente clientes[], int* origem, int num_clientes)
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
    printf("Digite sua senha: ");
	int i;
	fflush(stdin);
	for (i=0;i<6;i++)
	{
		senha1[i] = getch();
		putchar('*');
    }
    printf("\n");

	/*FUN��O QUE COMPARA O N� DE AG�NCIA, CONTA E SENHA DIGITADOS*/
	for(j=0; j<=num_clientes+1; j++)
        {
            if(clientes[j].conta.agencia == aux_agencia && clientes[j].conta.numero == aux_conta)
            {


                if (strcmp(clientes[j].conta.senha, senha1) == 0)
                    {
                        
						printf("VALIDA��O BEM SUCEDIDA!\n");
						*origem = j;
						return 3;
                    }
				else
				{
				printf("\n*****SENHA INCORRETA!*****\n");
				}

            }else if (j==num_clientes+1)
                {
                    printf("\nAG�NCIA OU CONTA INV�LIDA!\n");
                    break;
                }

        }

}




//FUN��O DE VALIDA��O DA CONTA DESTINO EM UMA TRANSFER�NCIA (L� AG�NCIA E CONTA E COMPARA. RETORNA 1 SE A VALIDA��O FOR CONFIRMADA.)

int validar_destino(Cliente clientes[], int* destino, int num_clientes)
{

    int j;
    int aux_agencia2, aux_conta2;

    fflush(stdin);

        printf("\nDigite o n�mero da ag�ncia: ");
        scanf("%d", &aux_agencia2);

        fflush(stdin);
        printf("Digite o n�mero da conta: ");
        scanf ("%d",&aux_conta2);


        for(j=0; j<=num_clientes+1; j++)
            {
                if(clientes[j].conta.agencia == aux_agencia2 && clientes[j].conta.numero == aux_conta2)
                {
                    *destino = j;
                    return 1;

                }else if (j==num_clientes+1)
                    {
                        printf("\nAG�NCIA OU CONTA INV�LIDA!");
                        return 0;
                    }

            }

}

//FUN��O SALDO:

void saldo(Cliente clientes[], int *origem)
{

        printf("Seu saldo � de R$%.2f \n", clientes[*origem].conta.saldo);

}


//FUN��O SAQUE:

void saque(Cliente clientes[], int *origem)
{
    float valor;

    printf("Seu saldo � de R$%.2f \n",clientes[*origem].conta.saldo);

    printf("Valor do saque: ");
    fflush(stdin);
    scanf("%f", &valor);
    if(valor <= clientes[*origem].conta.saldo)
    {
    	clientes[*origem].conta.saldo = clientes[*origem].conta.saldo - valor;	
	    printf("\nSaque realizado com sucesso! Retire o dinheiro no local indicado.\n");
	}
	else
	{
		printf("\nSeu saldo � insuficiente para realizar esse saque!\n");
	}
    

    printf("Novo saldo: R$%.2f \n", clientes[*origem].conta.saldo);


}


//FUN��O DEP�SITO:

void deposito(Cliente clientes[], int *origem)
{
    float valor;

    printf("Valor do dep�sito: ");
    fflush(stdin);
    scanf("%f", &valor);
    clientes[*origem].conta.saldo = clientes[*origem].conta.saldo + valor;

    printf("Dep�sito realizado com sucesso!\n");
    printf("Novo saldo: R$%.2f \n", clientes[*origem].conta.saldo);

}




//FUN��O TRANSFER�NCIA:

void transferencia(Cliente clientes[], int* origem, int* destino, int num_clientes)
{
    float valor;
	int continuar;
   printf("Seu saldo � de R$%.2f \n", clientes[*origem].conta.saldo);

    printf("Conta destino: %i\nCliente: %s\n\n", clientes[*destino].conta.numero, clientes[*destino].nome);

	printf("Pressione 1 para confirmar ou 2 para cancelar opera��o.\n");
	scanf("%i", &continuar);
	
    if(continuar == 1)
    {

       printf("Valor a ser transferido: ");
       fflush(stdin);
       scanf("%f", &valor);

       if(valor <= clientes[*origem].conta.saldo && valor >= 0)
        {

            clientes[*destino].conta.saldo = clientes[*destino].conta.saldo + valor;
            clientes[*origem].conta.saldo = clientes[*origem].conta.saldo - valor;

            printf("Tranfer�ncia realizada com sucesso!\n");
            printf("Novo saldo: R$%.2f \n", clientes[*origem].conta.saldo);
        }
        else if(valor < 0)
        {
        	printf("Voc� n�o pode transferir um valor negativo.\n");
		}
		else
		{
			printf("Saldo insuficiente!\n");
		} 
    }
    else
    {
    	printf("Opera��o cancelada com sucesso.\n");
	}


}









