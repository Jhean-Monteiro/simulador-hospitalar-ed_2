#ifndef FILA_CIRCULAR_H
#define FILA_CIRCULAR_H

#include "paciente.h"

#define MAX_CIRCULAR 8

typedef struct {
    Paciente *dados; // vetor alocado dinamicamente
    int frente;
    int tras;
    int tamanho;
    int capacidade;
    
} FilaCircular;

void fc_iniciar(FilaCircular *f);
int fc_vazia(FilaCircular *f);
int fc_cheia(FilaCircular *f);
void fc_enfileirar(FilaCircular *f, Paciente p);
Paciente fc_desenfileirar(FilaCircular *f);
void fc_exibir(FilaCircular *f);
void fc_liberar(FilaCircular *f);

#endif