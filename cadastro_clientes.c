#include <stdio.h>
#include <string.h>

#define MAX 100

typedef struct {
    char nome[50];
    int idade;
} Cliente;

Cliente clientes[MAX];

int total = 0;

void cadastrar() {
    if (total >= MAX) {
        printf("Limite atingido\n");
        return;
    }

    printf("\nNome: ");
    scanf(" %[^\n]", clientes[total].nome);
    
    printf("\nIdade: ");
    scanf("%d", &clientes[total].idade);
    
    if (clientes[total].idade < 0){
		while (clientes[total].idade < 0) {
			printf("Idade negativa, tente novamente:");
		    scanf("%d", &clientes[total].idade);
		}
	}
    total++;
    printf("\nCliente cadastrado com sucesso\n");
}

void listar() {
	int i;
	
    if (total == 0) {
        printf("\nNenhum cliente cadastrado\n");
        return;
    }

    for (i = 0; i < total; i++) {
        printf("\nNome: %s | Idade: %d\n", clientes[i].nome, clientes[i].idade);
    }
}

void editar(){
	int NumEdit;
	int i;
	
	if (total == 0) {
		printf("\nNenum cliente cadastrado\n");
		return;
	}
	
	for (i = 0; i < total; i++){
		printf("\n%d: Nome: %s | Idade: %d", i + 1, clientes[i].nome, clientes[i].idade);
	}
	   printf("\n\nQual cadastro gostaria de editar? (Insira o ID do usuario)\n");
	   scanf("%d", &NumEdit);
	   NumEdit--;
	   

	while(NumEdit < 0 || NumEdit >= total){
		printf("\nID invalido, tente novamente:");
		scanf("%d", &NumEdit);
		NumEdit--;
	}
	   
	printf("\nNome: ");
    scanf(" %[^\n]", clientes[NumEdit].nome);

    printf("\nIdade: ");
    scanf("%d", &clientes[NumEdit].idade);

    printf("\nEdicao realizada com sucesso!\n");

}


int main() {
    int opcao;

    do {
        printf("\n1 - Cadastrar\n2 - Listar\n3 - Editar\n0 - Sair\n\n");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                cadastrar();
                break;
            case 2:
                listar();
                break;
            case 3:
            	editar();
            	break;
            default:
            	printf("\nOpcao invalida, tente novamente:\n ");
            	break;
        }
    } while(opcao != 0);
    return 0;
    
}
