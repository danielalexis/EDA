#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char rua[50];
    int numero;
    char cpostal[8];
    char localidade[50];
    char pais[50];
} Morada;

typedef struct {
    int dia;
    int mes;
    int ano;
} Data;

typedef struct {
    char nome[120];
    char email[120];
    Morada endereco;
    int telefone;
    Data nascimento;
    char observacoes[255];
} Pessoa;

Pessoa agenda[100];
Pessoa *ptrAgenda = agenda;

void encontrar_pessoas_por_nome(Pessoa agenda[], char nome[120]) {
    Pessoa pessoas[100];
    for (int i = 0; i < 100; i++) {
        // Usar strstr para comparar strings parciais
        if (strstr(agenda[i].nome, nome) != NULL) {
            printf("Nome: %s\n", agenda[i].nome);
            printf("Email: %s\n", agenda[i].email);
            printf("Endereco: %s, %d, %s, %s, %s\n", agenda[i].endereco.rua, agenda[i].endereco.numero, agenda[i].endereco.cpostal, agenda[i].endereco.localidade, agenda[i].endereco.pais);
            printf("Telefone: %d\n", agenda[i].telefone);
            printf("Nascimento: %d/%d/%d\n", agenda[i].nascimento.dia, agenda[i].nascimento.mes, agenda[i].nascimento.ano);
            printf("Observacoes: %s\n", agenda[i].observacoes);
        }
    }
}

void encontrar_pessoas_por_mes_nascimento(Pessoa agenda[],Data nascimento) {
    for (int i = 0; i < 100; i++) {
        if (agenda[i].nascimento.mes == nascimento.mes) {
            printf("Nome: %s\n", agenda[i].nome);
            printf("Email: %s\n", agenda[i].email);
            printf("Endereco: %s, %d, %s, %s, %s\n", agenda[i].endereco.rua, agenda[i].endereco.numero, agenda[i].endereco.cpostal, agenda[i].endereco.localidade, agenda[i].endereco.pais);
            printf("Telefone: %d\n", agenda[i].telefone);
            printf("Nascimento: %d/%d/%d\n", agenda[i].nascimento.dia, agenda[i].nascimento.mes, agenda[i].nascimento.ano);
            printf("Observacoes: %s\n", agenda[i].observacoes);
        }
    }
}

void encontrar_pessoas_por_dia_mes_nascimento(Pessoa agenda[],Data nascimento) {
    for (int i = 0; i < 100; i++) {
        if (agenda[i].nascimento.dia == nascimento.dia && agenda[i].nascimento.mes == nascimento.mes) {
            printf("Nome: %s\n", agenda[i].nome);
            printf("Email: %s\n", agenda[i].email);
            printf("Endereco: %s, %d, %s, %s, %s\n", agenda[i].endereco.rua, agenda[i].endereco.numero, agenda[i].endereco.cpostal, agenda[i].endereco.localidade, agenda[i].endereco.pais);
            printf("Telefone: %d\n", agenda[i].telefone);
            printf("Nascimento: %d/%d/%d\n", agenda[i].nascimento.dia, agenda[i].nascimento.mes, agenda[i].nascimento.ano);
            printf("Observacoes: %s\n", agenda[i].observacoes);
        }
    }
}

void inserir_pessoa(Pessoa agenda[], Pessoa pessoa) {
    int posicao = 0;
    while (strcmp(agenda[posicao].nome, pessoa.nome) < 0 && agenda[posicao].nome[0] != '\0') {
        posicao++;
        if (posicao >= 100) {
            printf("A agenda está cheia. Não é possível adicionar mais pessoas.\n");
            return;
        }
    }
    
    int i;
    for (i = 99; i > posicao; i--) {
        agenda[i] = agenda[i - 1];
    }
    
    agenda[posicao] = pessoa;
    printf("Pessoa adicionada à agenda com sucesso!\n");
}

void remover_pessoa(Pessoa agenda[], char nome[120]) {
    int posicao = -1;
    for (int i = 0; i < 100; i++) {
        if (strcmp(agenda[i].nome, nome) == 0) {
            posicao = i;
            break;
        }
    }
    
    if (posicao == -1) {
        printf("Não foi encontrada nenhuma pessoa com o nome especificado.\n");
        return;
    }
    
    // Ordena a agenda
    for (int i = posicao; i < 99; i++) {
        agenda[i] = agenda[i + 1];
    }
    
    // Limpar a última posição da agenda
    agenda[99].nome[0] = '\0';
    
    printf("Pessoa removida da agenda com sucesso!\n");
}


void imprimir_agenda(Pessoa agenda[100]) {
    for (int i = 0; i < 100; i++) {
        if (agenda[i].nome[0] == '\0') {
            break;
        }
        printf("Nome: %s\n", agenda[i].nome);
        printf("Email: %s\n", agenda[i].email);
        printf("Endereco: %s, %d, %s, %s, %s\n", agenda[i].endereco.rua, agenda[i].endereco.numero, agenda[i].endereco.cpostal, agenda[i].endereco.localidade, agenda[i].endereco.pais);
        printf("Telefone: %d\n", agenda[i].telefone);
        printf("Nascimento: %d/%d/%d\n", agenda[i].nascimento.dia, agenda[i].nascimento.mes, agenda[i].nascimento.ano);
        printf("Observacoes: %s\n", agenda[i].observacoes);
    }
}


void main() {

    while (1)  {
        int opcao;
        Data nascimento;
        Pessoa pessoa;
        char nome[120];
        printf("-------------------------------------------------\n");
        printf("1 - Encontrar pessoas por nome\n");
        printf("2 - Encontrar pessoas por mes de nascimento\n");
        printf("3 - Encontrar pessoas por dia e mes de nascimento\n");
        printf("4 - Inserir pessoa\n");
        printf("5 - Remover pessoa\n");
        printf("6 - Imprimir agenda\n");
        printf("0 - Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);
        printf("-------------------------------------------------\n");
        switch (opcao)
        {
        case 1:
            printf("Nome: ");
            scanf("%s", nome);
            encontrar_pessoas_por_nome(agenda, nome);
            break;
        case 2:
            printf("Mes de nascimento: ");
            scanf("%d", &nascimento.mes);
            encontrar_pessoas_por_mes_nascimento(agenda, nascimento);
            break;

        case 3:
            printf("Dia de nascimento: ");
            scanf("%d", &nascimento.dia);
            printf("Mes de nascimento: ");
            scanf("%d", &nascimento.mes);
            encontrar_pessoas_por_dia_mes_nascimento(agenda, nascimento);
            break;

        case 4:
            printf("Nome: ");
            scanf("%s", pessoa.nome);
            printf("Email: ");
            scanf("%s", pessoa.email);
            printf("Endereco: ");
            scanf("%s", pessoa.endereco.rua);
            printf("Numero: ");
            scanf("%d", &pessoa.endereco.numero);
            printf("Codigo postal: ");
            scanf("%s", pessoa.endereco.cpostal);
            printf("Localidade: ");
            scanf("%s", pessoa.endereco.localidade);
            printf("Pais: ");
            scanf("%s", pessoa.endereco.pais);
            printf("Telefone: ");
            scanf("%d", &pessoa.telefone);
            printf("Dia de nascimento: ");
            scanf("%d", &pessoa.nascimento.dia);
            printf("Mes de nascimento: ");
            scanf("%d", &pessoa.nascimento.mes);
            printf("Ano de nascimento: ");
            scanf("%d", &pessoa.nascimento.ano);
            printf("Observacoes: ");
            scanf("%s", pessoa.observacoes);
            inserir_pessoa(agenda, pessoa);
            break;

        case 5:
            printf("Nome: ");
            scanf("%s", pessoa.nome);
            remover_pessoa(agenda, pessoa.nome);
            break;
        
        case 6:
            imprimir_agenda(agenda);
            break;

        case 0:
            exit(0);
            break;
        
        default:
            printf("Opcao invalida\n");
            break;
        }
    }
}