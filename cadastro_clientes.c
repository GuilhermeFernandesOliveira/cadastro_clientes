#include <stdio.h>
#include <string.h>

#define MAX 100

typedef struct {
    char nome[50];
    int idade;
} Cliente;

Cliente clientes[MAX];

int total = 0;

int lerInteiro(){
    int valor;
    while(scanf("%d", &valor) != 1){
        printf("\nEntrada invalida, insira um numero: ");
        while(getchar() != '\n');
    }
    return valor;
}

void cadastrar() {
    if (total >= MAX) {
        printf("Limite atingido\n");
        return;
    }

    printf("\nNome: ");
    scanf(" %[^\n]", clientes[total].nome);
    
    printf("\nIdade: ");
    clientes[total].idade = lerInteiro();
    
    if (clientes[total].idade < 0){
		while (clientes[total].idade < 0) {
			printf("Idade negativa, tente novamente:");
		    scanf("%d", &clientes[total].idade);
		}
	}
    total++;
    printf("\nCliente cadastrado com sucesso!\n");
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

void editar_exluir(){
	int NumEdit;
	int i;
	int opcaoEdEx;
	int excluir;
	
	if (total == 0) {
		printf("\nNenhum cliente cadastrado\n");
		return;
	}
	
	printf("\nEscolha uma opcao:\n");
	printf("\n1 - Editar as informacoes de um Cadastro\n\n2 - Excluir um Cadastro\n\n3 - Voltar ao menu\n\n");
	opcaoEdEx = lerInteiro();
	
	while(opcaoEdEx != 1 && opcaoEdEx != 2 && opcaoEdEx != 3){
		printf("\nOpcao invalida, tente novamente:\n");
		opcaoEdEx = lerInteiro();
	}
	
	if (opcaoEdEx == 1){
		for (i = 0; i < total; i++){
		 printf("\n%d - Nome: %s | Idade: %d", i + 1, clientes[i].nome, clientes[i].idade);
	 }
	   printf("\n\nQual cadastro gostaria de editar? (Insira o ID do usuario)\n\n");
	   NumEdit = lerInteiro();
	   NumEdit--;

	 while(NumEdit < 0 || NumEdit >= total){
		printf("\nID invalido, tente novamente:\n");
		NumEdit = lerInteiro();
		NumEdit--;
	}
	   
	printf("\nNome: ");
    scanf(" %[^\n]", clientes[NumEdit].nome);

    printf("\nIdade: ");
    scanf("%d", &clientes[NumEdit].idade);

    printf("\nEdicao realizada com sucesso!\n");
    return;
    }
    
    if (opcaoEdEx == 2){
    	for(i = 0; i < total; i++){
    		printf("\n%d - Nome: %s | Idade: %d", i + 1, clientes[i].nome, clientes[i].idade);
		}
		printf("\n\nQual cadastro gostaria de excluir? (Insira o ID do usuario)\n\n");
		excluir = lerInteiro();
		excluir--;
		
		while(excluir < 0 || excluir >= total){
			printf("ID invalido, tente novamente:\n");
			excluir = lerInteiro();
			excluir--;
		}
		
	    for (i = excluir; i < total - 1; i++){
            clientes[i] = clientes[i + 1];
        }
     total--;
     
     printf("\nExclusao de Cadastro com sucesso!\n");
	 return;
	}
    
    if(opcaoEdEx == 3){
    	return;
	}
    
}

int main() {
    int opcao;

    do {
    	printf("\nEscolha uma opcao do menu:\n");
        printf("\n1 - Cadastrar\n2 - Listar\n3 - Editar\n0 - Sair\n\n");
        opcao = lerInteiro();

        switch(opcao) {
            case 1:
                cadastrar();
                break;
            case 2:
                listar();
                break;
            case 3:
            	editar_exluir();
            	break;
            case 0:
            	return 0;
            	break;
            default:
            	printf("\nOpcao invalida, tente novamente:\n ");
            	break;
        }
    } while(opcao != 0);
    return 0;
}
