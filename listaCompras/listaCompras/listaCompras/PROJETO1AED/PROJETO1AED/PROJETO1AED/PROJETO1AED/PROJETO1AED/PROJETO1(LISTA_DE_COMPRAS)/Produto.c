#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "Produto.h"
 
typedef struct Produto { //ESTRUTURA PRODUTO

	char* NomeProduto;
	
	char* Tipo_Produto;

	float Preco_minino;

	char* Loja;

	int comprado;


}Produto;

ptrProduto criarProduto(char* NomeProduto, char* Tipo_Produto) {//FUNÇÃO PARA CRIAR NOVO PRODUTO
    
	ptrProduto Produto = (ptrProduto)malloc(sizeof(struct Produto));//ALOCA MEMORIA PARA O PONTEIRO DO TIPO PONTEIRO A ESTRUTURA PRODUTO
    
	if (Produto != NULL) {//VERIFICA SE O PONTEIRO NAO É IGUAL A NULO
    
		Produto->NomeProduto = (char*)malloc(sizeof(char) * (strlen(NomeProduto) + 1));//ALOCA MEMORIA PARA O NOME
        
		if (Produto->NomeProduto != NULL) {
        
			strcpy(Produto->NomeProduto, NomeProduto); //FAZ A COPIA DO CONTEUDO DA STRING
            
			Produto->Tipo_Produto = (char*)malloc(sizeof(char) * (strlen(Tipo_Produto) + 1));//ALOCA MEMORIA PARA O TIPO DE PRODUTO
            
			if (Produto->Tipo_Produto != NULL) {
            
				strcpy(Produto->Tipo_Produto, Tipo_Produto);//FAZ A COPIA DO CONTEUDO DA STRING

				Produto->Loja = NULL;//INICIALIZA O CAMPO LOJA COMO NULL
                
				Produto->Preco_minino = 100.0;//INICIALIZA O CAMPO PREÇO MINIMO COM UM VALOR GRANDE

				Produto->comprado = 0;
                
				return Produto; //RETORNA O PRODUTO

            } else {
              
				free(Produto->NomeProduto);//CASO CONTRARIO LIBERTA A MEMORIA
            }
        }
        free(Produto);//LIBERTA A MEMORIA
    }
    return NULL; //NULL SE OCORRER ALGUM ERRO DE ALOCAÇÃO DE MEMORIA, RETORNA NULL
}
void apagarProduto(ptrProduto Produto) {

	free(Produto->NomeProduto); //LIBERTA A MEMORIA DO CAMPO DA ESTRUTURA

	free(Produto->Tipo_Produto); //LIBERTA A MEMORIA DO CAMPO DA ESTRUTURA

	free(Produto); //LIBERTA O OBJETO PRODUTO


}
void listarProduto(ptrProduto Produto) {//LISTA TODOS OS PRODUTOS

	printf("\nProduto:%s\t\t", Produto->NomeProduto);
	
	printf("Tipo de Produto:%s\t\t", Produto->Tipo_Produto);
	
	printf("Preco Minimo:%.2f\t\t", Produto->Preco_minino);
	
	printf("Loja:%s\t\t", Produto->Loja);

}

char* DaNomeProduto(ptrProduto Produto) { //FUNÇÃO PARA ACEDER AO CAMPO DA ESTRUTURA

	return Produto->NomeProduto;

}

char* DaTipoProduto(ptrProduto Produto) {//FUNÇÃO PARA ACEDER AO CAMPO DA ESTRUTURA

	return Produto->Tipo_Produto;

}
char* DaLojaProduto(ptrProduto Produto) {//FUNÇÃO PARA ACEDER AO CAMPO DA ESTRUTURA
	
	return Produto->Loja;

}
float DaPrecoProduto(ptrProduto Produto) {//FUNÇÃO PARA ACEDER AO CAMPO DA ESTRUTURA

	return Produto->Preco_minino;
}
void setLojaProduto(ptrProduto Produto, char* loja) {//FUNÇÃO PARA MODIFICAR O CAMPO DA ESTRUTURA
	
	if (Produto->Loja != NULL) {
	
		free(Produto->Loja); // Libera a memória alocada anteriormente para a loja
	}

	Produto->Loja = (char*)malloc(sizeof(char) * (strlen(loja) + 1)); // Aloca memória para a nova loja
	
	if (Produto->Loja != NULL) {
	
		strcpy(Produto->Loja, loja); // Copia a nova loja para o campo Loja do produto
	}
}

void setPrecoProduto(ptrProduto Produto, float preco) { //FUNÇÃO PARA MODIFICAR O CAMPO DA ESTRUTURA
	
	if (Produto == NULL) {

		printf("Produto inválido.\n");
		
		return;
	}
	Produto->Preco_minino = preco;
}

int DaComprado(ptrProduto Produto) {

	return Produto->comprado;

}
int setComprado(ptrProduto Produto, int num) {

	Produto->comprado = num;

}