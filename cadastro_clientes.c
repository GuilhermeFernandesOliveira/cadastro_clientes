#include <stdio.h>
#include <string.h>

#define MAX 100

typedef struct {
    char nome[50];
    int idade;
} Cliente;

Cliente clientes[MAX];
int total = 0;
int i = 0;

void cadastrar() {
    if (total >= MAX) {
        printf("Limite atingido\n");
        return;
    }

    printf("Nome: ");
    scanf(" %[^\n]", clientes[total].nome);

    printf("Idade: ");
    scanf("%d", &clientes[total].idade);

    total++;
    printf("Cliente cadastrado com sucesso\n");
}

void listar() {
    if (total == 0) {
        printf("Nenhum cliente cadastrado\n");
        return;
    }

    for (i = 0; i < total; i++) {
        printf("Nome: %s | Idade: %d\n", clientes[i].nome, clientes[i].idade);
    }
}

int main() {
    int opcao;

    do {
        printf("\n1 - Cadastrar\n2 - Listar\n0 - Sair\n");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                cadastrar();
                break;
            case 2:
                listar();
                break;
        }
    } while(opcao != 0);

    return 0;
}
