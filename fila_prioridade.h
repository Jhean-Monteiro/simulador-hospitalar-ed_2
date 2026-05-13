#ifndef FILA_PRIORIDADE_H
#define FILA_PRIORIDADE_H

#include "paciente.h"

typedef struct No {
    Paciente paciente;
    int prioridade;
    struct No *proximo;
} No;

typedef struct {
    No *inicio;
    int contador;
} FilaPrioridade;

#define MAX_PRIORIDADE 20

void fp_iniciar(FilaPrioridade *f);
int fp_vazia(FilaPrioridade *f);
int fp_cheia(FilaPrioridade *f);
void fp_enfileirar(FilaPrioridade *f, Paciente p, int prio);
Paciente fp_desenfileirar(FilaPrioridade *f);
void fp_exibir(FilaPrioridade *f);

#endif