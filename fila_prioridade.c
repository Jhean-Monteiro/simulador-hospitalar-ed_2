#include <stdio.h>
#include <stdlib.h>
#include "paciente.h"
#include "fila_prioridade.h"

void fp_iniciar(FilaPrioridade *f) {
    f->inicio = NULL;
    f->contador = 0;
}

int fp_vazia(FilaPrioridade *f) {
    return (f->inicio == NULL);
}

int fp_cheia(FilaPrioridade *f) {
    return f->contador >= MAX_PRIORIDADE;
}

void fp_enfileirar(FilaPrioridade *f, Paciente p, int prio) {
    No *novo = malloc(sizeof(No));
    if (novo == NULL) {
        printf("Erro: Sem memória!\n");
        return;
    }

    novo->paciente = p;
    novo->prioridade = prio;
    novo->proximo = NULL;

    if (fp_vazia(f) || prio > f->inicio->prioridade) {
        novo->proximo = f->inicio;
        f->inicio = novo;
    } else {
        No *atual = f->inicio;
        while (atual->proximo != NULL && atual->proximo->prioridade >= prio) {
            atual = atual->proximo;
        }
        novo->proximo = atual->proximo;
        atual->proximo = novo;
    }

    f->contador++;
    printf("Paciente %s (Prio %d) adicionado na Emergência.\n", p.nome, prio);
}

Paciente fp_desenfileirar(FilaPrioridade *f) {
    Paciente vazio = {"", 0, 0, 0};

    if (fp_vazia(f)) {
        printf("Fila de Emergência vazia!\n");
        return vazio;
    }

    No *temp = f->inicio;
    Paciente atendido = temp->paciente;

    f->inicio = f->inicio->proximo;
    free(temp);
    f->contador--;

    printf("Paciente %s atendido na Emergência.\n", atendido.nome);
    return atendido;
}

void fp_exibir(FilaPrioridade *f) {
    if (fp_vazia(f)) {
        printf("Não há pacientes na Emergência.\n");
        return;
    }

    printf("\n~~~~ EMERGÊNCIA (Maior prioridade primeiro) ~~~\n\n");
    No *temp = f->inicio;
    while (temp != NULL) {
        printf("Nome: %s | Idade: %d | Prio: %d\n",
               temp->paciente.nome, temp->paciente.idade, temp->prioridade);
        temp = temp->proximo;
    }
}