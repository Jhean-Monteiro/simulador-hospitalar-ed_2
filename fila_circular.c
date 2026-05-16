#include <stdio.h>
#include <stdlib.h>
#include "fila_circular.h"

void fc_iniciar(FilaCircular *f) {
    f->dados = malloc(MAX_CIRCULAR * sizeof(Paciente));
    f->frente = 0;
    f->tras = -1;
    f->tamanho = 0;
    f->capacidade = MAX_CIRCULAR;
}

int fc_vazia(FilaCircular *f) {
    return f->tamanho == 0;
}

int fc_cheia(FilaCircular *f) {
    return f->tamanho == f->capacidade;
}

void fc_enfileirar(FilaCircular *f, Paciente p) {
    if (fc_cheia(f)) {
        printf("Fila de exames cheia! Removendo paciente mais antigo: %s\n", f->dados[f->frente].nome);

        f->frente = (f->frente + 1) % f->capacidade;
        f->tamanho--;
    }

    f->tras = (f->tras + 1) % f->capacidade;
    f->dados[f->tras] = p;
    f->tamanho++;
    printf("Paciente %s adicionado à fila de exames.\n", p.nome);
}

Paciente fc_desenfileirar(FilaCircular *f) {
    Paciente vazio = {"", 0, 0, 0};

    if (fc_vazia(f)) {
        printf("Não há pacientes na fila de exames.\n");
        return vazio;
    }

    Paciente atendido = f->dados[f->frente];
    f->frente = (f->frente + 1) % f->capacidade;
    f->tamanho--;

    return atendido;
}

void fc_exibir(FilaCircular *f) {
    if (fc_vazia(f)) {
        printf("Não há pacientes na fila de exames.\n");
        return;
    }

    printf("~~~~ EXAMES ~~~~\n\n");
    for (int count = 0; count < f->tamanho; count++) {
        int i = (f->frente + count) % f->capacidade;
        printf("Nome: %s | Idade: %d | Gravidade: %d\n",
               f->dados[i].nome, f->dados[i].idade, f->dados[i].gravidade);
    }
}

void fc_liberar(FilaCircular *f) {
    free(f->dados);
    f->dados = NULL;
}