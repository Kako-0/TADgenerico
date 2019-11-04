#ifndef _TAD_c_
#define _TAD_c_
#define TRUE 1
#define FALSE !TRUE
#include <stdlib.h>
#include <string.h>
#include "TADGenerico.h"
    typedef struct _cofo_{
        void **elms;
        int max;
        int nelms;
        int cur;
    }Cofo;

    typedef struct _carro_{
    char marca[20];
    int potencia;
    int numPortas;
    float preco;
    long int placa;
}Carro;

//cria um cofo com N espa�o.
Cofo *cofCreate(int n)
{
    //cria um novo cofo.
    Cofo *c;
    //condi��o para que exista.
    if (n > 0)
    {
        //aloca e testa.
        c = (Cofo*)malloc(sizeof(Cofo));
        if (c != NULL)
        {
            c ->elms = (void**)malloc(sizeof(void*)*n);
            if (c ->elms != NULL)
            {
                c ->max = n;//Quantidade m�xima
                c ->nelms = 0;//posi��o inicial
                c ->cur = -1;//posi��o atual
                return c;
            }else
            {
                free(c);
            }

        }
    }
    return NULL;
}

//Destr�i um cofo.
int *cofDestroy(Cofo *c)
{
    if (c != NULL)
    {
        if (c ->nelms == 0)//Condi��o para destruir o cofo
        {
            free(c->nelms);
            free(c);
            return TRUE;
        }
    }
    return FALSE;
}

//Insere um dado no cofo
int cofInsert(Cofo *c, void *elms)
{
    if (c != NULL)
    {
        if (c ->nelms < c ->max)//Se o vetor n�o estiver cheio
        {
            c ->elms[c ->nelms] = elms;//Adiciona um novo elemento
            c ->nelms++;//Incrementa a posi��o
            return TRUE;
        }
    }
    return FALSE;
}

//Fun��o que compara se duas entradas est�o no cofo
int cmpPlacaMarca(void *placa,void *marca, void *elm)
{
    long int *ip = (long int*)placa;
    char *cm = (char*)marca;
    Carro *Celm = (Carro*)elm;
    if (ip == Celm ->placa && (strcmp(cm, Celm ->marca)==0))
    {
        return TRUE;
    }else
    {
        return FALSE;
    }
}

//Fun��o que consulta um dado dentro do cofo
void *cofQuerry(Cofo *c, void *placa, void *marca, int(*cmp)(void *,void *, void *))
{
    void *aux;//vari�vel auxiliar
    int i, stat;
    if (c != NULL)
    {
        if (c ->nelms > 0)//condi��o
        {
            i = 0;//contador limite
            stat = cmpPlacaMarca(placa, marca, c ->elms[i]);//recebe uma fun��o de compara��o
            while (stat != TRUE && i < c ->nelms)//stat vai receber a fun��o de compara��o ate que ela seja verdadeira e i chegar ao �ltimo nelms
            {
                i++;
                stat = cmpPlacaMarca(placa, marca, c ->elms[i]);//stat recebe a fun��o de compara��o com o i incrementado
            }
            if (stat == TRUE)//Quando verdadeiro, aux ir� receber o elemento correspondente da compara��o
            {
                aux = c ->elms[i];
                return aux;
            }
        }
    }
    return NULL;
}

//Func�o que remove um elemento do cofo
void *cofRemove(Cofo *c, void *placa,void *marca, int(*cmp)(void *, void *, void *))
{
    void *aux;
    int i, stat;
    if (c != NULL)
    {
        if (c ->nelms > 0)//condi��o
        {
            i = 0;//contador limite
            stat = cmpPlacaMarca(placa, marca, c ->elms[i]);//recebe uma fun��o de compara��o
            while (stat != TRUE && i < c ->nelms)//stat vai receber a fun��o de compara��o ate que ela seja verdadeira e i chegar ao �ltimo nelms
            {
                i++;
                stat = c ->elms[i];//stat recebe a fun��o de compara��o com o i incrementado
            }
            if (stat == TRUE)//Quando verdadeiro, aux ir� receber o elemento correspondente da compara��o
            {
                aux = c ->elms[i];
                for (int j = i; j < c ->nelms-1; j++)
                {
                    c ->elms[j] = c ->elms[j+1];//coloca o elemento i na �ltima posi��o
                }
                c ->nelms--;//remove o elemento deixado na �ltima posi��o
                return aux;
            }
        }
    }
    return NULL;
}

//Fun��o que retorna o primeiro elemento dentro do cofo
void *cofGetFirst(Cofo *c)
{
    if (c != NULL)
    {
        if (c ->nelms > 0)//condi��o
        {
            c ->cur = 0;//primeira posi��o dentro do cofo
            return c ->elms[c ->cur];
        }
    }
    return NULL;
}

//Fun��o que retorna a pr�xima posi��o dentro do cofo
void *cofGetNext(Cofo *c)
{
    if (c != NULL)
    {
        if (c ->nelms > 0)//condi��o
        {
            c ->cur++;//incrementa a posi��o atual dentro do cofo
            if (c ->cur < c ->nelms)
            {
                return c ->elms[c ->cur];
            }
        }
    }
    return NULL;
}

#endif // _cofo_c_

