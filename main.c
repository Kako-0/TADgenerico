#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "TADGenerico.h"
#define TRUE 1
#define FALSE !TRUE
typedef struct _carro_{
    char marca[20];
    int potencia;
    int numPortas;
    float preco;
    long int placa;
}Carro;

int main()
{
    setlocale(LC_ALL, "Portuguese");
    int tam, option, ctrl = 0; //vari�vel para definir o tamanho do cofo e vari�veis de controle, respectivamente
    Cofo *c;
    do{
        printf("--------------------------------------------------------------------------------\n");
        printf("\t\t\t* Trabalho de TAD Gen�rico *\n\t\t\t  Aluno: Kayro M. de Fran�a\n\n");
        printf("--------------------------------------------------------------------------------\n");
        printf("   Menu\n");
        printf("Criar um cofo[1]\nDestruir um cofo[2]\nInserir um novo dado[3]\nConsultar um dado[4]\nRemover um dado[5]\nListar todos os dados[6]\n");
        printf("\nSelecione uma op��o:\n");
        scanf("%d",&option);
        system("cls");

        if (option == 1)//Op��o para criar um cofo
        {
            if(ctrl == 0)//Controle do cofo para saber se j� existe um ou n�o
            {
                printf("escolha o tamanho do cofo: ");
                scanf("%d", &tam);
                c = cofCreate(tam);//cria um cofo com o tamanho digitado
                if (c != NULL)
                {
                    printf("Criado com sucesso!\n\n\n");
                    option = 0;//volta para o menu
                    ctrl++;//controle do cofo
                }else
                {
                    printf("Falha ao criar\n\n\n");
                    option = 0;//volta para o menu
                }
            }else
            {
                printf("J� existe um cofo\n\n\n");
                option = 0;//volta para o menu
            }
        }else if(option == 2)//op��o para destruir um cofo
        {
            if(ctrl == 1)//existe um cofo
            {
                int aux = cofDestroy(c);
                if (aux == TRUE)//O cofo s� ser� destru�do se n�o existit nenhum elemento dentro dele
                {
                    printf("Cofo destru�do com sucesso!\n\n");
                    ctrl--;//controle do cofo para dizer que n�o existe mais cofo
                    option = 0;//volta para o menu
                }else
                {
                    printf("Esvazie o cofo para destrui-lo\n\n");
                    option = 0;//volta para o menu
                }
            }else
            {
                printf("Cofo inexistente\n\n");
                option = 0;//volta para o menu
            }
        }else if (option == 3)//op��o para inserir um novo dado no cofo
        {
            if(ctrl == 1)//existe um cofo
            {
                Carro *novo = (Carro*)malloc(sizeof(Carro));//criando um novo dado
                printf("Digite a marca do novo carro: ");
                scanf(" %[^\n]s", novo ->marca);
                printf("\nDigite o n�mero de portas do novo carro: ");
                scanf(" %d", &novo ->numPortas);
                printf("\nDigite a placa do novo carro: ");
                scanf(" %ld", &novo ->placa);
                printf("\nDigite o pre�o do novo carro: ");
                scanf(" %f", &novo ->preco);
                printf("\nDigite a pot�ncia do novo carro: ");
                scanf(" %d", &novo ->potencia);
                if(cofInsert(c,(void*)novo) == TRUE)
                {
                    printf("Novo dado inserido com sucesso!\n\n");
                    option = 0;//volta para o menu
                }else
                {
                    printf("Erro ao inserir um novo dado\n\n");
                    option = 0;//volta para o menu
                }
            }else
            {
                printf("Cofo inexistente\n\n");
                option = 0;//volta para o menu
            }
        }else if (option == 4)//Op��o para consultar um dado dentro do cofo
        {
            if (ctrl == 1)//existe um cofo
            {
                long int placa; char marca[20]; Carro *checkOut;
                printf("Digite o n�mero da placa do carro: ");
                scanf("%ld", &placa);
                printf("\nDigite a marca do carro: ");
                scanf(" %[^\n]s", marca);
                checkOut = (Carro*)cofQuerry(c,(void*)placa,(void*)marca,cmpPlacaMarca);
                if(checkOut != NULL)
                {
                    printf("Marca: %s\nPlaca: %ld\nPot�ncia: %d\nN�mero de portas: %d\nPre�o: R$ %.2f\n\n", checkOut->marca, checkOut->placa, checkOut->potencia, checkOut->numPortas, checkOut->preco);
                    option = 0;//volta para o menu
                }else
                {
                    printf("Desculpe, carro n�o encontrado\n\n");
                    option = 0;//volta para o menu
                }
            }else
            {
                printf("Cofo inexistente\n\n");
                option = 0;//volta para o menu
            }
        }else if(option == 5)//Op��o para remover um dado do cofo
        {
            if(ctrl == 1)//existe um cofo
            {
                long int placa; char marca[20]; Carro *checkOut;
                printf("Digite o n�mero da placa do carro: ");
                scanf("%ld", &placa);
                printf("\nDigite a marca do carro: ");
                scanf(" %[^\n]s", marca);
                checkOut = (Carro*)cofRemove(c,(void*)placa,(void*)marca,cmpPlacaMarca);
                if(checkOut != NULL)
                {
                    printf("Marca: %s\nPlaca: %ld\nPot�ncia: %d\nN�mero de portas: %d\nPre�o: R$ %.2f\n\n", checkOut->marca, checkOut->placa, checkOut->potencia, checkOut->numPortas, checkOut->preco);
                    printf("Dado removido com sucesso!\n\n");
                    option = 0;//volta para o menu
                }else
                {
                    printf("Desculpe, carro n�o encontrado\n\n");
                    option = 0;//volta para o menu
                }
            }else
            {
                printf("Cofo inexistente\n\n");
                option = 0;//volta para o menu
            }
        }else if(option == 6)//Op��o para listar todos os dados do cofo
        {
            if(ctrl == 1)//se existe um cofo
            {
               Carro *imprime;
               imprime = (Carro*)cofGetFirst(c);//pega a primeira posi��o dentro do cofo
               while(imprime != NULL)
               {
                   printf("Marca: %s\nPlaca: %ld\nPot�ncia: %d\nN�mero de portas: %d\nPre�o: R$ %.2f\n", imprime->marca, imprime->placa, imprime->potencia, imprime->numPortas, imprime->preco);
                   printf("--------------------------------------------------------------------------------\n");
                   imprime = (Carro*)cofGetNext(c);//pega a proxima posi��o dentro do cofo
               }
               option = 0;//volta para o menu
            }else
            {
                printf("Cofo inexistente\n\n");
                option = 0;//volta para o menu
            }
        }
    }while(option < 1 || option > 6);
    return 0;
}
