

//Ps.: A contagem do FOR vai até "j<100", por estar predefinido um vetor com 100 espaços para conta (sem alocação dinâmica implementada).


//FUNÇÃO DE VALIDAÇÃO (LÊ AGÊNCIA, CONTA, SENHA E COMPARA. RETORNA 1 SE A VALIDAÇÃO FOR CONFIRMADA.)

int validar(Cliente clientes[], int* origem)
{

	int j;
    int aux_agencia, aux_conta, senha1;

	//CAPTURA DE DADOS (AGÊNCIA, CONTA, SENHA)
	fflush(stdin);
	printf("\nDigite o número da agência: ");
    scanf("%d", &aux_agencia);

    fflush(stdin);
    printf("Digite o número da conta: ");
    scanf ("%d",&aux_conta);

    fflush(stdin);
    printf("\nDigite sua senha: ");
    scanf("%s", &senha1);


	/*FUNÇÃO QUE COMPARA O Nº DE AGÊNCIA, CONTA E SENHA DIGITADOS*/
	for(j=0; j<100; j++)
        {
            if(clientes[j].agencia == aux_agencia && clientes[j].conta == aux_conta)
            {


                if (strcmp(clientes[j].senha, senha1) == 0)
                    {
                        *origem = j;
                        return 1;

                    }else printf("\n*****SENHA INCORRETA!*****");


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
                if(clientes[j].agencia == aux_agencia2 && clientes[j].conta == aux_conta2)
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

        printf("Seu saldo é de R$%.2f \n",clientes[*origem].saldo);

}


//FUNÇÃO SAQUE:

void saque(Cliente clientes[], int *origem)
{
    float valor;

    printf("Seu saldo é de R$%.2f \n",clientes[*origem].saldo);

    printf("Valor do saque: ");
    fflush(stdin);
    scanf("%f", &valor);
    clientes[*origem].saldo = clientes[*origem].saldo - valor;

    printf("Saque realizado com sucesso! Retire o dinheiro no local indicado.\n");

    printf("Novo saldo: R$%.2f \n", clientes[*origem].saldo);


}


//FUNÇÃO DEPÓSITO:

void deposito(Cliente clientes[], int *origem)
{
    float valor;

    printf("Seu saldo é de R$%.2f \n",clientes[*origem].saldo);

    printf("Valor do depósito: ");
    fflush(stdin);
    scanf("%f", &valor);
    clientes[*origem].saldo = clientes[*origem].saldo - valor;

    printf("Depósito realizado com sucesso!\n";
    printf("Novo saldo: R$%.2f \n"clientes[*origem].saldo);

}




//FUNÇÃO TRANSFERÊNCIA:

void transferencia()
{
    void valor;

    printf("Seu saldo é de R$%.2f \n",clientes[*origem].saldo);

    printf("Conta destino:\n");

    if(validar_destino() == 1)
    {

       printf("Valor a ser transferido: ");
       fflush(stdin);
       scanf("%f", &valor);

       if(valor >= clientes[*origem].saldo)
            {

            clientes[*destino].saldo = clientes[*destino].saldo + valor;
            clientes[*origem].saldo = clientes[*origem].saldo - valor;

            printf("DTranferência realizada com sucesso!\n";
            printf("Novo saldo: R$%.2f \n"clientes[*origem].saldo);

            } else printf("Saldo insuficiente!\n");


    }


}









