#ifndef FILA_H
#define FILA_H
 
#include "paciente.h"
 
#define MAX_FILA 10
 
typedef struct NoFila {
    Paciente paciente;
    struct NoFila *prox;
} NoFila;
 
void fila_iniciar();
int  fila_vazia();
int  fila_cheia();
void fila_enfileirar(Paciente paciente);
Paciente fila_desenfileirar();
void fila_exibir();
 
#endif
 