#include <stdio.h>
#include <stdlib.h>

//Conceito de nó duplo
//cada nó guarda um valor, o endereço do anterior e o endereço do próximo
typedef struct no {
    int valor;
    struct no *ant;
    struct no *prox;
} No;

//Deque
//permite inserir e remover no início e no fim
typedef struct deque {
    No *inicio;
    No *fim;
    int qtd;
} Deque;

//criar deque
Deque* criarDeque()
{
    Deque *deque = malloc(sizeof(Deque));

    if(deque != NULL)
    {
        deque->inicio = NULL;
        deque->fim = NULL;
        deque->qtd = 0;
    }

    return deque;
}

//verificar se deque está vazio
int dequeVazio(Deque *deque)
{
    if(deque == NULL || deque->inicio == NULL)
    {
        return 1;
    }

    return 0;
}

//tamanho do deque
int tamanhoDeque(Deque *deque)
{
    if(deque == NULL)
    {
        return 0;
    }

    return deque->qtd;
}

//inserir no início do deque
int inserirInicioDeque(Deque *deque, int valor)
{
    if(deque == NULL)
    {
        return 0;
    }

    No *novo = malloc(sizeof(No));

    if(novo == NULL)
    {
        return 0;
    }

    novo->valor = valor;
    novo->ant = NULL;
    novo->prox = deque->inicio;

    if(deque->inicio == NULL)
    {
        deque->inicio = novo;
        deque->fim = novo;
    }
    else
    {
        deque->inicio->ant = novo;
        deque->inicio = novo;
    }

    deque->qtd++;

    return 1;
}

//inserir no fim do deque
int inserirFimDeque(Deque *deque, int valor)
{
    if(deque == NULL)
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
    novo->ant = deque->fim;

    if(deque->fim == NULL)
    {
        deque->inicio = novo;
        deque->fim = novo;
    }
    else
    {
        deque->fim->prox = novo;
        deque->fim = novo;
    }

    deque->qtd++;

    return 1;
}

//remover do início do deque
int removerInicioDeque(Deque *deque, int *valorRemovido)
{
    if(deque == NULL || deque->inicio == NULL)
    {
        return 0;
    }

    No *aux = deque->inicio;

    *valorRemovido = aux->valor;

    deque->inicio = aux->prox;

    if(deque->inicio == NULL)
    {
        deque->fim = NULL;
    }
    else
    {
        deque->inicio->ant = NULL;
    }

    free(aux);
    deque->qtd--;

    return 1;
}

//remover do fim do deque
int removerFimDeque(Deque *deque, int *valorRemovido)
{
    if(deque == NULL || deque->fim == NULL)
    {
        return 0;
    }

    No *aux = deque->fim;

    *valorRemovido = aux->valor;

    deque->fim = aux->ant;

    if(deque->fim == NULL)
    {
        deque->inicio = NULL;
    }
    else
    {
        deque->fim->prox = NULL;
    }

    free(aux);
    deque->qtd--;

    return 1;
}

//buscar elemento no deque
int buscarDeque(Deque *deque, int valor)
{
    if(deque == NULL)
    {
        return 0;
    }

    No *aux = deque->inicio;

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

//imprimir deque
void imprimirDeque(Deque *deque)
{
    if(deque == NULL)
    {
        return;
    }

    No *aux = deque->inicio;

    printf("Inicio -> ");

    while(aux != NULL)
    {
        printf("%d <-> ", aux->valor);
        aux = aux->prox;
    }

    printf("NULL\n");
}

//destruir deque
void destruirDeque(Deque *deque)
{
    if(deque == NULL)
    {
        return;
    }

    No *aux = deque->inicio;

    while(aux != NULL)
    {
        No *prox = aux->prox;
        free(aux);
        aux = prox;
    }

    free(deque);
}

int main()
{
    Deque *deque = criarDeque();

    inserirInicioDeque(deque, 20);
    inserirInicioDeque(deque, 10);
    inserirFimDeque(deque, 30);
    inserirFimDeque(deque, 40);

    imprimirDeque(deque);

    printf("Tamanho: %d\n", tamanhoDeque(deque));

    if(buscarDeque(deque, 30))
    {
        printf("Elemento encontrado\n");
    }
    else
    {
        printf("Elemento nao encontrado\n");
    }

    int removido;

    if(removerInicioDeque(deque, &removido))
    {
        printf("Removido do inicio: %d\n", removido);
    }

    if(removerFimDeque(deque, &removido))
    {
        printf("Removido do fim: %d\n", removido);
    }

    imprimirDeque(deque);

    if(dequeVazio(deque))
    {
        printf("Deque vazio\n");
    }
    else
    {
        printf("Deque nao vazio\n");
    }

    destruirDeque(deque);

    return 0;
}
