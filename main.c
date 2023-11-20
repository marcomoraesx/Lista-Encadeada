#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "lista_encadeada.h"

int main(int argc, char *argv) {

    //declaração da lista
    lista l1 = NULL;

    int valor = 0;
    int posicao = 0;
    int opc = 0;

    do {
        printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
        printf("=============================== Escolha uma função ===============================\n");
        printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
        printf("[99] Sair                 [1] Inserir Inicio      [2] Inserir Fim\n[3] Inserir Posicao       [4] Inserir Ordem       [5] Exibir\n[6] Reverso               [7] Remover Inicio      [8] Remover Fim\n[9] Remover Posicao       [10] Remover Valor      [11] Procurar\n[12] Tamanho              [13] Somatorio          [14] Quadrado\n[15] Qtde Primo\n");
        printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
        printf("=============================== Escolha uma função ===============================\n");
        printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");

        printf("                    OBS: Já existe uma lista inicializada!!\n\n");

        scanf("%d", &opc);

        switch (opc) {
            case 1:
                printf("Informe um valor para inserir no início: ");
                scanf("%d", &valor);
                l1 = inserir_inicio(l1, valor);
                printf("Inserido\n");
                exibir_lista(l1);
                break;
            case 2:
                printf("Informe um valor para inserir no fim: ");
                scanf("%d", &valor);
                l1 = inserir_fim(l1, valor);
                printf("Inserido!\n");
                exibir_lista(l1);
                break;
            case 3:
                printf("Posicao desejada: ");
                scanf("%d", &posicao);
                printf("Informe um valor: ");
                scanf("%d", &valor);
                l1 = inserir_posicao(l1, posicao, valor);
                exibir_lista(l1);
                break;
            case 4:
                printf("Informe um valor: ");
                scanf("%d", &valor);
                l1 = inserir_ordem(l1, valor);
                printf("Inserido!\n");
                exibir_lista(l1);
                break;
            case 5:
                exibir_lista(l1);
                break;
            case 6:
                exibir_lista_r(l1);
                printf("\n");
                break;
            case 7:
                l1 = remover_inicio(l1);
                printf("Removido!\n");
                exibir_lista(l1);
                break;
            case 8:
                l1 = remover_fim(l1);
                printf("Removido!\n");
                exibir_lista(l1);
                break;
            case 9:
                printf("Informe a posição para remover: ");
                scanf("%d", &posicao);
                l1 = remover_posicao(l1, posicao);
                exibir_lista(l1);
                break;
            case 10:
                printf("Informe o valor para remover: ");
                scanf("%d", &valor);
                l1 = remover_valor(l1, valor);
                exibir_lista(l1);
                break;
            case 11:
                printf("Informe o valor a ser procurado: ");
                scanf("%d", &valor);
                procurar(l1, valor);
                break;
            case 12:
                tamanho(l1, 0);
                break;
            case 13:
                somatorio(l1);
                break;
            case 14:
                l1 = quadrado(l1);
                exibir_lista(l1);
                break;
            case 15:
                qtd_primo(l1);
                break;
            case 99:
                break;

            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (opc != 99);

    return 0;
}

