#include <stdio.h>
#include "fila_prioridade.h"
#include "fila_circular.h"

int main() {
    FilaPrioridade fila;
    FilaCircular filaa;

    fp_iniciar(&fila);
    fc_iniciar(&filaa);

    Paciente p0 = {"Pedro", 50, 4, 1};

    fc_enfileirar(&filaa, p0);


    Paciente p1 = {"Pedro", 50, 4, 1};
    Paciente p2 = {"Ana",   30, 5, 1};
    Paciente p3 = {"Carlos",65, 3, 1};

    fp_enfileirar(&fila, p1, 8);
    fp_enfileirar(&fila, p2, 10);
    fp_enfileirar(&fila, p3, 7);

    fp_exibir(&fila);

    fp_desenfileirar(&fila);  // vai atender Ana (prioridade 10)
    fp_exibir(&fila);

    return 0;
}