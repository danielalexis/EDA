#include <stdio.h>
#include <stdlib.h>



void main() {
    FILE *fileTxt, *fileBin, *fileBinPositivos;
    int num;

    fileTxt = fopen("Inteiros.txt", "r");
    if (fileTxt == NULL) {
        printf("Erro ao abrir o ficheiro.\n");
        return;
    }
    
    fileBin = fopen("Inteiros.bin", "wb");
    if (fileBin == NULL) {
        printf("Erro ao criar o ficheiro.\n");
        return;
    }
    
    while (fscanf(fileTxt, "%d", &num) == 1) {
        fwrite(&num, sizeof(int), 1, fileBin);
    }
    
    fclose(fileTxt);
    fclose(fileBin);
    
    fileBin = fopen("Inteiros.bin", "rb");
    if (fileBin == NULL) {
        printf("Erro ao abrir o ficheiro\n");
        return;
    }
    
    printf("Ficheiro binario:\n");
    while (fread(&num, sizeof(int), 1, fileBin) == 1) {
        printf("%d\n", num);
    }
    
    fclose(fileBin);
    
    fileBin = fopen("Inteiros.bin", "rb");
    if (fileBin == NULL) {
        printf("Erro ao abrir o ficheiro\n");
        return;
    }
    
    fileBinPositivos = fopen("InteirosPositivos.bin", "wb");
    if (fileBinPositivos == NULL) {
        printf("Erro ao criar o ficheiro.\n");
        return;
    }
    
    while (fread(&num, sizeof(int), 1, fileBin) == 1) {
        if (num > 0) {
            fwrite(&num, sizeof(int), 1, fileBinPositivos);
        }
    }
    
    fclose(fileBin);
    fclose(fileBinPositivos);
    
    fileBinPositivos = fopen("InteirosPositivos.bin", "rb");
    if (fileBinPositivos == NULL) {
        printf("Erro ao abrir o ficheiro\n");
        return;
    }
    
    printf("ints positivos (binário):\n");
    while (fread(&num, sizeof(num), 1, fileBinPositivos) == 1) {
        printf("%d\n", num);
    }
    
    fclose(fileBinPositivos);
    
    return;
}
