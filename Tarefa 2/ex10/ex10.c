#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[50];
    int dia;
    int mes;
    int ano;
} Contacto;

void inserirContacto(FILE *file) {
    Contacto contacto;
    printf("Nome: ");
    scanf("%s", contacto.nome);
    printf("Dia: ");
    scanf("%d", &contacto.dia);
    printf("Mês: ");
    scanf("%d", &contacto.mes);
    printf("Ano: ");
    scanf("%d", &contacto.ano);
    fprintf(file, "%s %d %d %d\n", contacto.nome, contacto.dia, contacto.mes, contacto.ano);
    return;
}

void removerContacto(FILE *file) {
    fseek(file, 0, SEEK_SET);
    char nome[50];
    printf("Nome: ");
    scanf("%s", nome);
    FILE *fileTemp = fopen("temp.txt", "w");
    if (fileTemp == NULL) {
        printf("Erro ao abrir o ficheiro.\n");
        return;
    }
    char nomeTemp[50];
    int dia, mes, ano;
    while (fscanf(file, "%s %d %d %d", nomeTemp, &dia, &mes, &ano) != EOF) {
        if (strcmp(nome, nomeTemp) != 0) {
            fprintf(fileTemp, "%s %d %d %d\n", nomeTemp, dia, mes, ano);
        }
    }
    fclose(file);
    fclose(fileTemp);
    remove("contactos.txt");
    rename("temp.txt", "contactos.txt");
    return;
}

void pesquisar_por_nome(FILE *file) {
    fseek(file, 0, SEEK_SET);
    char nome[50];
    printf("Nome: ");
    scanf("%s", nome);
    char nomeTemp[50];
    int dia, mes, ano;
    while (fscanf(file, "%s %d %d %d", nomeTemp, &dia, &mes, &ano) != EOF) {
        if (strcmp(nome, nomeTemp) == 0) {
            printf("%s %d %d %d\n", nomeTemp, dia, mes, ano);
        }
    }
    return;
}

void listar_contactos(FILE *file) {
    fseek(file, 0, SEEK_SET);
    Contacto contacto;
    while (fscanf(file, "%s %d %d %d", contacto.nome, &contacto.dia, &contacto.mes, &contacto.ano) != EOF) {
        printf("%s %d/%d/%d\n", contacto.nome, contacto.dia, contacto.mes, contacto.ano);
    }
    return;
}

void listar_letra_inicial(FILE *file) {
    fseek(file, 0, SEEK_SET);
    char letra;
    Contacto contacto;
    printf("Letra: ");
    scanf(" %c", &letra);
    
    while (fscanf(file, "%s %d %d %d", contacto.nome, &contacto.dia, &contacto.mes, &contacto.ano) != EOF) {
        if (contacto.nome[0] == letra) {
            printf("%s %d/%d/%d\n", contacto.nome, contacto.dia, contacto.mes, contacto.ano);
        }
    }
    return;
}

void listar_por_mes(FILE *file) {
        fseek(file, 0, SEEK_SET);
    int mes;
    Contacto contacto;
    printf("Mês: ");
    scanf("%d", &mes);
    
    while (fscanf(file, "%s %d %d %d", contacto.nome, &contacto.dia, &contacto.mes, &contacto.ano) != EOF) {
        if (contacto.mes == mes) {
            printf("%s %d %d %d\n", contacto.nome, contacto.dia, contacto.mes, contacto.ano);
        }
    }
    return;
}

void main() {
    FILE *file = fopen("contactos.txt", "w+");
    while (1) {
        printf("--------------------------------------\n");
        printf("1 - Inserir Contacto\n");
        printf("2 - Remover Contacto\n");
        printf("3 - Pesquisar Contacto por nome\n");
        printf("4 - Listar Contactos\n");
        printf("5 - Listar Contactos por letra inicial\n");
        printf("6 - Listar aniversariante do mês\n");
        printf("0 - Sair\n");

        int opcao;
        printf("Opção: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            inserirContacto(file);
            break;
        case 2:
            removerContacto(file);
            file = fopen("contactos.txt", "w+");
            break;
        case 3:
            pesquisar_por_nome(file);
            break;
        case 4:
            listar_contactos(file);
            break;
        case 5:
            listar_letra_inicial(file);
            break;
        case 6:
            listar_por_mes(file);
            break;
        case 0:
            fclose(file);
            return;
        default:
            break;
        }
    }
}