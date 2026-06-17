#include <stdio.h>
#include <stdlib.h>

//Conceito de nó
//cada nó guarda um valor e o endereço do próximo nó
typedef struct no {
    int valor;
    struct no *prox;
} No;

//Pilha encadeada
//LIFO: último que entra é o primeiro que sai
typedef struct pilha {
    No *topo;
    int qtd;
} Pilha;

//criar pilha
Pilha* criarPilha()
{
    Pilha *pilha = malloc(sizeof(Pilha));

    if(pilha != NULL)
    {
        pilha->topo = NULL;
        pilha->qtd = 0;
    }

    return pilha;
}

//verificar se pilha está vazia
int pilhaVazia(Pilha *pilha)
{
    if(pilha == NULL || pilha->topo == NULL)
    {
        return 1;
    }

    return 0;
}

//tamanho da pilha
int tamanhoPilha(Pilha *pilha)
{
    if(pilha == NULL)
    {
        return 0;
    }

    return pilha->qtd;
}

//inserir na pilha
//push: insere no topo
int push(Pilha *pilha, int valor)
{
    if(pilha == NULL)
    {
        return 0;
    }

    No *novo = malloc(sizeof(No));

    if(novo == NULL)
    {
        return 0;
    }

    novo->valor = valor;
    novo->prox = pilha->topo;

    pilha->topo = novo;
    pilha->qtd++;

    return 1;
}

//remover da pilha
//pop: remove do topo
int pop(Pilha *pilha, int *valorRemovido)
{
    if(pilha == NULL || pilha->topo == NULL)
    {
        return 0;
    }

    No *aux = pilha->topo;

    *valorRemovido = aux->valor;

    pilha->topo = aux->prox;

    free(aux);
    pilha->qtd--;

    return 1;
}

//buscar elemento na pilha
int buscarPilha(Pilha *pilha, int valor)
{
    if(pilha == NULL)
    {
        return 0;
    }

    No *aux = pilha->topo;

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

//imprimir pilha
void imprimirPilha(Pilha *pilha)
{
    if(pilha == NULL)
    {
        return;
    }

    No *aux = pilha->topo;

    printf("Topo -> ");

    while(aux != NULL)
    {
        printf("%d -> ", aux->valor);
        aux = aux->prox;
    }

    printf("NULL\n");
}

//destruir pilha
void destruirPilha(Pilha *pilha)
{
    if(pilha == NULL)
    {
        return;
    }

    No *aux = pilha->topo;

    while(aux != NULL)
    {
        No *prox = aux->prox;
        free(aux);
        aux = prox;
    }

    free(pilha);
}

int main()
{
    Pilha *pilha = criarPilha();

    push(pilha, 10);
    push(pilha, 20);
    push(pilha, 30);

    imprimirPilha(pilha);

    printf("Tamanho: %d\n", tamanhoPilha(pilha));

    if(buscarPilha(pilha, 20))
    {
        printf("Elemento encontrado\n");
    }
    else
    {
        printf("Elemento nao encontrado\n");
    }

    int removido;

    if(pop(pilha, &removido))
    {
        printf("Removido: %d\n", removido);
    }

    imprimirPilha(pilha);

    if(pilhaVazia(pilha))
    {
        printf("Pilha vazia\n");
    }
    else
    {
        printf("Pilha nao vazia\n");
    }

    destruirPilha(pilha);

    return 0;
}
