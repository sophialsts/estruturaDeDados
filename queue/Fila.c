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
    novoDado->inicio = NULL;
    
    printf("Digite o valor que deseja adicionar na fila:\n");
    scanf("%d", &novoDado->valor);
    
    if(FILA->inicio == NULL) { //fila vazia
        FILA->inicio = novoDado;
        FILA->final = novoDado;
        novoDado->final = NULL;
    }
    else {
        FILA->final->final = novoDado; //ponteiro do final da fila apontando pro novoDado
        FILA->final = novoDado; //atualizando ponteiro de final geral pro novo dado
        novoDado->final = NULL;
    }
    tamanho++;
}

void verFila(node *FILA) {
    if(verificaFila(FILA)) {
        //pegar do FILA->inicio até FILA->final->final == NULL
    }
    else {
        printf("A fila está vazia.");
        return;
    }
}

int verificaFila(node *FILA) {
    if(FILA->inicio == NULL) return 0;
    else return 1;
}

void escolha (node *FILA, int opcao) {
    switch (opcao) {
    case 1:
        enfileirar(FILA);
        break;
    case 2:

        break;
    case 3:

        break;
    case 4:
        verFila(FILA);
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
    printf("1- Enfileirar\n");
    printf("2- Desenfileirar\n");
    printf("3- Esvaziar fila\n");
    printf("4- Vizualizar fila\n");
    printf("5- Sair\n");
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