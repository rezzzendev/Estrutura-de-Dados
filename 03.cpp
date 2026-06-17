#include <stdio.h>
#include <stdlib.h>

//Conceito de nó
//cada nó guarda um valor e o endereço do próximo nó
typedef struct no {
    int valor;
    struct no *prox;
} No;

//Fila encadeada
//FIFO: primeiro que entra é o primeiro que sai
typedef struct fila {
    No *inicio;
    No *fim;
    int qtd;
} Fila;

//criar fila
Fila* criarFila()
{
    Fila *fila = malloc(sizeof(Fila));

    if(fila != NULL)
    {
        fila->inicio = NULL;
        fila->fim = NULL;
        fila->qtd = 0;
    }

    return fila;
}

//verificar se fila está vazia
int filaVazia(Fila *fila)
{
    if(fila == NULL || fila->inicio == NULL)
    {
        return 1;
    }

    return 0;
}

//tamanho da fila
int tamanhoFila(Fila *fila)
{
    if(fila == NULL)
    {
        return 0;
    }

    return fila->qtd;
}

//inserir na fila
//enqueue: insere no fim
int enqueue(Fila *fila, int valor)
{
    if(fila == NULL)
    {
        return 0;
    }

    No *novo = malloc(sizeof(No));

    if(novo == NULL)
    {
        return 0;
    }

    novo->valor = valor;
    novo->prox = NULL;

    if(fila->inicio == NULL)
    {
        fila->inicio = novo;
        fila->fim = novo;
    }
    else
    {
        fila->fim->prox = novo;
        fila->fim = novo;
    }

    fila->qtd++;

    return 1;
}

//remover da fila
//dequeue: remove do início
int dequeue(Fila *fila, int *valorRemovido)
{
    if(fila == NULL || fila->inicio == NULL)
    {
        return 0;
    }

    No *aux = fila->inicio;

    *valorRemovido = aux->valor;

    fila->inicio = aux->prox;

    if(fila->inicio == NULL)
    {
        fila->fim = NULL;
    }

    free(aux);
    fila->qtd--;

    return 1;
}

//buscar elemento na fila
int buscarFila(Fila *fila, int valor)
{
    if(fila == NULL)
    {
        return 0;
    }

    No *aux = fila->inicio;

    while(aux != NULL)
    {
        if(aux->valor == valor)
        {
            return 1;
        }

        aux = aux->prox;
    }

    return 0;
}

//imprimir fila
void imprimirFila(Fila *fila)
{
    if(fila == NULL)
    {
        return;
    }

    No *aux = fila->inicio;

    printf("Inicio -> ");

    while(aux != NULL)
    {
        printf("%d -> ", aux->valor);
        aux = aux->prox;
    }

    printf("NULL\n");
}

//destruir fila
void destruirFila(Fila *fila)
{
    if(fila == NULL)
    {
        return;
    }

    No *aux = fila->inicio;

    while(aux != NULL)
    {
        No *prox = aux->prox;
        free(aux);
        aux = prox;
    }

    free(fila);
}

int main()
{
    Fila *fila = criarFila();

    enqueue(fila, 10);
    enqueue(fila, 20);
    enqueue(fila, 30);

    imprimirFila(fila);

    printf("Tamanho: %d\n", tamanhoFila(fila));

    if(buscarFila(fila, 20))
    {
        printf("Elemento encontrado\n");
    }
    else
    {
        printf("Elemento nao encontrado\n");
    }

    int removido;

    if(dequeue(fila, &removido))
    {
        printf("Removido: %d\n", removido);
    }

    imprimirFila(fila);

    if(filaVazia(fila))
    {
        printf("Fila vazia\n");
    }
    else
    {
        printf("Fila nao vazia\n");
    }

    destruirFila(fila);

    return 0;
}
