#include <stdio.h>

void copiar(char nomeFicheiro[150], char nomeFicheiroDestino[150]) {
    FILE *file;
    file = fopen(nomeFicheiro, "r");
    if (file == NULL) {
        printf("Erro ao abrir o ficheiro");
        return;
    }

    FILE *fileDestino;
    fileDestino = fopen(nomeFicheiroDestino, "w");
    if (fileDestino == NULL) {
        printf("Erro ao abrir o ficheiro");
        return;
    }

    char linha[255];
    while (fgets(linha, 255, file) != NULL) {
        fputs(linha, fileDestino);
    }

    fclose(file);
    fclose(fileDestino);
}

void anexar(char nomeFicheiroOriginal[150], char nomeFicheiroAnexo[150]) {
    FILE *file;
    file = fopen(nomeFicheiroOriginal, "a");
    if (file == NULL) {
        printf("Erro ao abrir o ficheiro");
        return;
    }

    FILE *fileAnexo;
    fileAnexo = fopen(nomeFicheiroAnexo, "r");
    if (fileAnexo == NULL) {
        printf("Erro ao abrir o ficheiro");
        return;
    }

    char linha[255];
    while (fgets(linha, 255, fileAnexo) != NULL) {
        fputs(linha, file);
    }

    fclose(file);
    fclose(fileAnexo);
}

void main() {
    while (1) {
        int opcao;
        char nomeFicheiro[150], nomeFicheiroDestino[150];

        printf("-------------------\n");
        printf("1 - Copiar ficheiro\n");
        printf("2 - Anexar ficheiro\n");
        printf("0 - Sair           \n");
        printf("-------------------\n");
        printf("Opcao: ");
        scanf("%d", &opcao);
        switch (opcao) {
            case 0:
                return;
                break;
            case 1:
                printf("Nome do ficheiro original: ");
                scanf("%s", nomeFicheiro);
                printf("Nome do ficheiro destino: ");
                scanf("%s", nomeFicheiroDestino);
                copiar(nomeFicheiro, nomeFicheiroDestino);
                break;
            case 2:
                printf("Nome do ficheiro original: ");
                scanf("%s", nomeFicheiro);
                printf("Nome do ficheiro a anexar ao original: ");
                scanf("%s", nomeFicheiroDestino);
                anexar(nomeFicheiro, nomeFicheiroDestino);
                break;
            default:
                printf("Opcao invalida\n");
                break;
        }
    }

}