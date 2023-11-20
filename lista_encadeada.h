
#ifndef LISTA_ENCADEADA_H
#define LISTA_ENCADEADA_H

typedef int tipo;

typedef struct no{
        int valor;
        struct no* proximo;
} no;

typedef no* lista;

lista inserir_fim(lista l, int valor);
lista inserir_inicio(lista l, int valor);
lista inserir_posicao(lista l, int posicao, int valor);
lista inserir_ordem(lista l, int valor);
lista remover_fim(lista l);
lista remover_inicio(lista l);
lista remover_posicao(lista l, int posicao);
lista remover_valor(lista l, int valor);
int procurar(lista l, int valor);
void exibir_lista(lista l);
void exibir_lista_r(lista l);
int tamanho(lista l, int forma);
int somatorio(lista l);
lista quadrado(lista l);
int eh_primo(int num);
int qtd_primo(lista l);
//lista concatenar(lista l1,  lista l2);

#endif

