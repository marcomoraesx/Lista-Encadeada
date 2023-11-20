
#include <stdio.h>
#include <stdlib.h>
#include "lista_encadeada.h"

lista inserir_inicio(lista l, int valor) {
    //Aloca espaço para o novo nó
    lista novo = (lista) malloc(sizeof(no));
    //inicializan o valor do novo a parir do parâmetro passado para função
    novo->valor = valor;
    //O próximo do novo aponta para o inicio da lista, ou seja, o antigo início passa a ser o segundo elemento (proximo do primeiro)
    novo->proximo = l;
    //Atualização da lista, através do retorno do ponteiro do novo início
    return novo;
}

void exibir_lista(lista l){
    lista aux = l;
    while(aux != NULL) {
        printf("[%d]", aux->valor);
        aux = aux->proximo;
    }

    /*
    for(aux=l; aux != NULL; aux = aux->proximo) {
        printf("[%d]", aux->valor);
    }*/
    printf("\n");
}

void exibir_lista_r(lista l){
    //caso base
    if(l == NULL) {
        printf("\n");
        return ;
    }
    //caso recursivo

    exibir_lista_r(l->proximo);
    printf("[%d]", l->valor);
}

lista inserir_fim(lista l, int valor) {
    lista aux = l;
    if(l == NULL) {
        return inserir_inicio(l, valor);
    }

    while(aux->proximo != NULL) {
        aux = aux->proximo;
    }
    //aqui aux == último
    lista novo = (lista) malloc(sizeof(no));
    novo->valor = valor;
    novo->proximo = NULL;

    //último aponte para o novo
    aux->proximo = novo;
    return l;
}

lista inserir_posicao(lista l, int posicao, int valor){
    if (l == NULL){
        return inserir_inicio(l, valor);
    }

    lista aux = l;
    int pos = 0;
    int tam = tamanho(l, 1);

    if (posicao == 0) {
        return inserir_inicio(l, valor);
    }

    if (posicao == tam + 1){
        return inserir_fim(l, valor);
    }

    if (posicao >= 0 && posicao <= tam){
        while (pos < posicao - 1) {
            aux = aux->proximo;
            pos++;
        }
        lista novo = (lista) malloc(sizeof(no));
        novo->valor = valor;
        novo->proximo = aux->proximo;

        aux->proximo = novo;

        return l;
    } else {
        printf("Posicao invalida!\n");
        return l;
    }
}

lista inserir_ordem(lista l, int valor) {
    if (l == NULL || valor <= l->valor) {
        return inserir_inicio(l, valor);
    }

    lista aux = l;

    while (aux->proximo != NULL) {
        if (valor <= aux->proximo->valor) {
            break;
        }
        aux = aux->proximo;
    }

    if (aux->proximo == NULL) {
        return inserir_fim(l, valor);
    }

    lista novo = (lista) malloc(sizeof(no));
    novo->valor = valor;
    novo->proximo = aux->proximo;
    aux->proximo = novo;

    return l;
}


lista remover_inicio(lista l) {
    if(l==NULL)
        return NULL;
    lista aux = l->proximo;
    free(l);
    return aux;
}

lista remover_fim(lista l) {
    if(l==NULL)
        return NULL;

    if(l->proximo == NULL)
       return remover_inicio(l);

    lista aux = l;
    while(aux->proximo->proximo != NULL) {
        aux = aux->proximo;
    }

    free(aux->proximo);
    aux->proximo = NULL;

    return l;
}

lista remover_posicao(lista l, int posicao){
    if(l==NULL)
        return NULL;

    lista aux = l;
    int tam = tamanho(l, 1);
    int pos = 0;

    if (posicao == 0){
        return remover_inicio(l);
    }

    if(posicao > tam - 1 || posicao < 0){
        printf("Posicao invalida!\n");
        return l;
    }

    while (aux->proximo != NULL && pos < posicao - 1){
        aux = aux->proximo;
        pos++;
    }
    lista removed = aux->proximo;
    aux->proximo = aux->proximo->proximo;
    free(removed);
    return l;
}

lista remover_valor(lista l, int valor) {
    if (l == NULL) {
        return NULL;
    }

    if (l->valor == valor) {
        lista removed = l;
        l = l->proximo;
        free(removed);
        return l;
    }

    lista aux = l;

    while (aux->proximo != NULL) {
        if (aux->proximo->valor == valor) {
            lista removed = aux->proximo;
            aux->proximo = aux->proximo->proximo;
            free(removed);
            return l;
        }
        aux = aux->proximo;
    }

    printf("Valor nao encontrado!\n");
    return l;
}


int procurar(lista l, int valor){
    lista aux = l;
    int pos = 0;

    while(aux != NULL && valor != aux->valor){
        aux = aux->proximo;
        pos++;
    }

    if(aux == NULL){
        pos = -1;
        printf("Valor nao encontrado!\n");
        return pos;
    }

    printf("%d\n", pos);

    return pos;
}

int tamanho(lista l, int forma){
    lista aux = l;

    if(l == NULL){
        printf("0");
    }

    int tamanho = 1;

    while(aux->proximo != NULL){
        tamanho++;
        aux = aux->proximo;
    }

    if (forma == 0){
    printf("%d\n", tamanho);
    }

    return tamanho;
}

int somatorio(lista l){
    lista aux = l;
    int somatorio = 0;

    while(aux != NULL){
        somatorio = somatorio + aux->valor;
        aux = aux->proximo;
    }
    printf("%d\n", somatorio);

    return somatorio;
}

lista quadrado(lista l){
    if(l == NULL){
        return NULL;
    }
    lista aux = l;

    while(aux != NULL){
        aux->valor = aux->valor*aux->valor;
        aux = aux->proximo;
    }

    return l;
}

int eh_primo(int num) {
    if (num <= 1) {
        return 0;
    }

    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) {
            return 0;
        }
    }

    return 1;
}

int qtd_primo(lista l) {
    lista aux = l;
    int contador = 0;

    if (l==NULL){
        printf("%d\n", contador);
        return 1;
    }

    while(aux != NULL) {
        if (eh_primo(aux->valor)) {
            contador++;
        }
        aux = aux->proximo;
    }

    printf("%d\n", contador);

    return 1;
}
