#include <stdio.h>
#include <stdlib.h>

//Conceito de nó
//cada nó guarda um valor e o endereço do próximo nó
typedef struct no {
	int valor;
	struct no *prox;	
}No;

//Lista encadeada simples
typedef struct lista {
    No *inicio;
    int qtd;
} Lista;

//criar lista
Lista* criarLista()
{
	Lista *lista = malloc(sizeof(Lista));
	if(lista != NULL)
	{
		lista->inicio = NULL;
		lista->qtd = 0;
	}
	return lista;
}

int inserirInicio(Lista *lista, int valor)
{
	if(lista == NULL){
		return 0;
	}
	
	No *novo = malloc(sizeof(No));
	
	if(novo == NULL){
		return 0;
	}
	
	novo->valor = valor;
	novo->prox = lista->inicio;
	
	lista->inicio = novo;
	lista->qtd++;
	
	return 1;
}

int inserirFinal(Lista *lista, int valor)
{
	if(lista == NULL){
		return 0;
	}
	
	No *novo = malloc(sizeof(No));
	if(novo == NULL){
		return 0;
	}
	
	novo->valor = valor;
	novo->prox = NULL;
	
	if(lista->inicio == NULL){
		lista->inicio = novo;
	}else{
		No *aux = lista->inicio;
		while(aux->prox != NULL){
			aux = aux->prox;
		}
		aux->prox = novo;
	}
	lista->qtd++;
	return 1;
}

No *buscarElemento(Lista *lista, int valor){
	if(lista == NULL){
		return NULL;
	}
	
	No *aux = lista->inicio;
	while(aux != NULL){
		if(aux->valor == valor){
			return aux;
		}
		
		aux = aux->prox;
	}
	return NULL;
}

int removerElemento(Lista *lista, int valor){
	if(lista == NULL || lista->inicio == NULL){
		return 0;
	}
	
	No *aux = lista->inicio;
	No *ant = NULL;
	
	while(aux != NULL || aux->valor != valor){
		ant = aux;
		aux = aux->prox;
	}
	
	if(aux == NULL){
		return 0;
	}
	if(ant == NULL){
		return 0;	
	}
	
	if(ant == NULL){
		lista->inicio = aux->prox;
	}else{
		ant->prox = aux->prox;
	}
	free(aux);
	lista->qtd--;
	return 1;
}

void destruirLista(Lista *lista) {
    if (lista == NULL) {
        return;
    }

    No *aux = lista->inicio;

    while (aux != NULL) {
        No *prox = aux->prox;
        free(aux);
        aux = prox;
    }

    free(lista);
}

void imprimirLista(Lista *lista) {
    if (lista == NULL) {
        return;
    }

    No *aux = lista->inicio;

    while (aux != NULL) {
        printf("%d -> ", aux->valor);
        aux = aux->prox;
    }

    printf("NULL\n");
}

int main() {
    Lista *lista = criarLista();

    inserirInicio(lista, 30);
    inserirInicio(lista, 20);
    inserirFim(lista, 40);
    inserirInicio(lista, 10);

    imprimirLista(lista);

    printf("Tamanho: %d\n", tamanhoLista(lista));

    No *busca = buscarElemento(lista, 20);

    if (busca != NULL) {
        printf("Elemento encontrado: %d\n", busca->valor);
    } else {
        printf("Elemento nao encontrado\n");
    }

    removerElemento(lista, 20);

    imprimirLista(lista);

    if (listaVazia(lista)) {
        printf("Lista vazia\n");
    } else {
        printf("Lista nao vazia\n");
    }

    destruirLista(lista);

    return 0;
}














