#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No *inicio;
    struct No *final;
} node;

int tamanho;

void inicializa (node *fila) {
    fila->inicio = NULL;
    fila->final = NULL;
    tamanho = 0;
}

void enfileirar(node *FILA) {

    node *novoDado = (node *)malloc(sizeof(node));
    novoDado->final = NULL;
    novoDado->inicio = NULL;

    printf("Digite o valor que deseja adicionar na fila:\n");
    scanf("%d", &novoDado->valor);

    if(!FILA) { //fila vazia
        FILA->final = novoDado;
        FILA->inicio = novoDado;
    }
    else {
        FILA->final->final = novoDado;
        FILA->final = novoDado;
    }
    tamanho++;
}

int escolha (node *FILA, int opcao) {
    switch (opcao) {
    case 1:
        enfileirar(FILA);
        break;
    case 2:

        break;
    case 3:

        break;
    case 4:

        break;
    case 5:
        exit(1);    
    }
}

int main() {
    node *fila = (node *)malloc(sizeof(node));
    if(!fila) {
        printf("fila vazia");
        exit(1);
    }
    else {
        inicializa(fila);
    }

    int op;
    //opcoes de enfileirar, desenfileirar, esvaziar fila, vizualizar fila, sair;
    do {
        printf("Digite a opção desejada:\n");
        scanf("%d", &op);
        if(op <= 0 && op >= 6) printf("Essa opção não existe. Digite corretamente\n");
        else {
            escolha(fila, op);
        }
    } while(op > 0 && op < 6);

    free(fila);

    return 0;
}