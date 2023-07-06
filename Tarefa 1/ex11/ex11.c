#include <stdio.h>

typedef struct {
    int horas;
    int minutos;
    int segundos;
} Horario;

typedef struct {
    int dia;
    int mes;
    int ano;
} Data;

typedef struct  {
    Horario horario;
    Data data;
    char descricao[50];
} Compromisso;

void main() {
     Horario h = {10, 20, 30};
     Data d = {1, 2, 3};
     Compromisso c = {h, d, "Compromisso"};
    printf("Compromisso no dia %d do mes %d do ano %d as horas %d minutos %d e segundos %d com o nome %s\n", c.data.dia, c.data.mes, c.data.ano, c.horario.horas, c.horario.minutos, c.horario.segundos, c.descricao);
}