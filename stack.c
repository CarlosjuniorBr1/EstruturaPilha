#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int valor;
    struct no *next;
} No;

// Empilhar
No* push(No *topo, int num) {
    No *novo = (No*)malloc(sizeof(No));
    if (novo) {
        novo->valor = num;
        novo->next = topo;
        return novo;
    } else {
        printf("Erro ao alocar\n");
        return NULL;
    }
}

// Desempilhar
No* pop(No **topo) {
    if (*topo != NULL) {
        No *remover = *topo;
        *topo = remover->next;

        return remover;
    }

    printf("Pilha vazia\n");
    return NULL;
}

void imprimir(No *pilha) {
    while (pilha) {
        printf("%d\n", pilha->valor);
        pilha = pilha->next;
    }
}

int main() {
    No *topo = NULL;
    No *remover = NULL;

    topo = push(topo, 5);
    topo = push(topo, 2);
    topo = push(topo, 3);
    topo = push(topo, 4);

    printf("Pilha original:\n");
    imprimir(topo);

    printf("----------------------------\n\n");

    remover = pop(&topo);

    printf("Pilha após a remoção:\n");
    imprimir(topo);
    remover = pop(&topo);

    printf("Pilha após a remoção:\n");
    imprimir(topo);
    remover = pop(&topo);

    printf("Pilha após a remoção:\n");
    imprimir(topo);

    return 0;
}
