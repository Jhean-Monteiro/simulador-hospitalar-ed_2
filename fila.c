#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

NoFila *frente;
NoFila *tras;
int contador = 0;

void fila_iniciar() {
    frente = NULL;
    tras = NULL;
    contador = 0;
}

int fila_vazia() {
    return frente == NULL;
}

int fila_cheia() {
    return contador >= MAX_FILA;
}

void fila_enfileirar(Paciente paciente) {
    if (fila_cheia()) {
        printf("Erro: Fila de consultas cheia!\n");
        return;
    }

    NoFila *novo = malloc(sizeof(NoFila));
    if (novo == NULL) {
        printf("Erro: falta de memória\n");
        return;
    } 

    novo->paciente = paciente;
    novo->prox = NULL;

    if(fila_vazia()){
        frente = novo;
        tras = novo;
    } else {
        tras->prox = novo;
        tras = novo;
    }

    contador++;
    printf("Paciente %s adicionado à fila de consultas.\n", paciente.nome);
}

Paciente fila_desenfileirar() {
    Paciente vazio = {"", 0, 0, 0};
    if (fila_vazia()){
        printf("não existe paciente para desenfileirar.\n");
        return vazio;
    }

    NoFila *removido = frente;
    Paciente atendido = removido->paciente;

    frente = frente->prox;
    if (frente == NULL) tras = NULL;
    free(removido);
    contador--;

    return atendido;
}

void fila_exibir() {
    if (fila_vazia()) {
        printf("Não há paciente na fila de consultas.\n");
        return;
    }

    printf("~~~~ CONSULTAS ~~~~\n\n");
    NoFila *atual = frente;
    while (atual != NULL) {
        printf("Nome: %s / Idade: %d / Gravidade: %d\n",
               atual->paciente.nome,
               atual->paciente.idade,
               atual->paciente.gravidade);
        atual = atual->prox;
    }
}