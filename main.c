#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "paciente.h"
#include "fila_prioridade.h"
#include "fila_circular.h"
#include "fila.h"

FilaPrioridade emergencia;
FilaCircular exames;


void cadastrar_paciente();
void atender_paciente();
void mostrar_pacientes();
void transferir_paciente();
void relatorios();


int main() {
    /* INICIO DA MEDIçÃO DE TEMPO */
    clock_t inicio, fim;
    double tempo_gasto;
    inicio = clock();

    fp_iniciar(&emergencia);
    fila_iniciar();
    fc_iniciar(&exames);

    int opcao;

    do {
        printf("\n~~~~ HOSPITAL SIMULADO ~~~~\n");
        printf("1. Cadastrar paciente\n");
        printf("2. Atender paciente\n");
        printf("3. Mostrar pacientes\n");
        printf("4. Transferir paciente\n");
        printf("5. Relatorios\n");
        printf("0. Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: cadastrar_paciente(); break;
            case 2: atender_paciente(); break;
            case 3: mostrar_pacientes(); break;
            case 4: transferir_paciente(); break;
            case 5: relatorios(); break;
            case 0: printf("Encerrando sistema...\n"); break;
            default: printf("Opcao invalida!\n");
        }
       
    } while (opcao != 0);
    fc_liberar(&exames);



    fim = clock();  
    tempo_gasto = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf("\nTempo de execução: %.4f segundos\n", tempo_gasto);

    return 0;
}

void cadastrar_paciente() {
    Paciente p;
    printf("\n--- CADASTRO DE PACIENTE ---\n");

    printf("Nome: ");
    scanf(" %49[^\n]", p.nome);

    printf("Idade: ");
    scanf("%d", &p.idade);

    printf("Gravidade (1 a 5): ");
    scanf("%d", &p.gravidade);
 
    if (p.gravidade >= 4) {
        printf("Gravidade alta! Direcionando para Emergencia.\n");
        p.tipo = 1;
    } else {
        printf("Tipo de atendimento:\n");
        printf("1. Emergencia\n2. Consulta\n3. Exame\n");
        printf("Opcao: ");
        scanf("%d", &p.tipo);
    }

    switch (p.tipo) {
        case 1: fp_enfileirar(&emergencia, p, p.gravidade); break;
        case 2: fila_enfileirar(p); break;
        case 3: fc_enfileirar(&exames, p); break;
        default: printf("Tipo invalido!\n");
    }
}

void atender_paciente() {
    int opcao;
    Paciente p;
 
    printf("\n~~~~ ATENDER PACIENTE ~~~~\n");
    printf("1. Emergencia\n2. Consulta\n3. Exame\n");
    printf("Opcao: ");
    scanf("%d", &opcao);
 
    switch (opcao) {
        case 1: p = fp_desenfileirar(&emergencia); break;
        case 2: p = fila_desenfileirar(); break;
        case 3: p = fc_desenfileirar(&exames); break;
        default: printf("Opcao invalida!\n"); 
        return;
    }
 
    if (p.nome[0] != '\0') {
        printf("\n=== PACIENTE ATENDIDO ===\n");
        printf("Nome: %s\n", p.nome);
        printf("Idade: %d\n", p.idade);
        printf("Gravidade: %d\n", p.gravidade);
    }
}


void mostrar_pacientes() {
    int opcao; 
    printf("\n~~~ MOSTRAR PACIENTES ~~~\n");
    printf("1. Emergencia\n2. Consulta\n3. Exame\n4. Todos\n");
    printf("Opcao: ");
    scanf("%d", &opcao);

    switch (opcao) {
        case 1: fp_exibir(&emergencia); break;
        case 2: fila_exibir(); break;
        case 3: fc_exibir(&exames); break;
        case 4: fp_exibir(&emergencia); fila_exibir(); fc_exibir(&exames); break;
        default: printf("Opcao invalida!\n");
    }
}

void transferir_paciente() {
    int origem;
    int destino;
    Paciente p;

    printf("\n--- TRANSFERIR PACIENTE ---\n");
    printf("Origem:  1. Emergencia  2. Consulta  3. Exame\n");
    printf("Opção: ");
    scanf("%d", &origem);

    switch (origem) {
        case 1: p = fp_desenfileirar(&emergencia); break;
        case 2: p = fila_desenfileirar(); break;
        case 3: p = fc_desenfileirar(&exames); break;
        default: printf("Opcao invalida!\n"); 
        return;
    }

    if (p.nome[0] == '\0') return;

    printf("Destino:\n 1. Emergencia\n 2. Consulta\n 3. Exame\n");
    printf("Opção: ");
    scanf("%d", &destino);

    switch (destino) {
        case 1: fp_enfileirar(&emergencia, p, p.gravidade); break;
        case 2: fila_enfileirar(p); break;
        case 3: fc_enfileirar(&exames, p); break;
        default: printf("Opção invalida!\n");
    }


}

void relatorios() {
    printf("\n~~~~ RELATORIO GERAL ~~~~\n");
    fp_exibir(&emergencia);
    fila_exibir();
    fc_exibir(&exames);
}