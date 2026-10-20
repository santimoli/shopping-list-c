#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "Produto.h"
#include "ListaDeCompra.h"
#include "ArrayProdutos.h"



typedef struct Lista_De_Compra { //ESTRUTURA LISTA DE COMPRAS

	char* NomeListaCompra;

	ptrProduto_De_Lista* ptrProdutoLista; // PONTEIRO PARA UM PONTEIRO DO TIPO PRODUTO DE LISTA

	int n;//VARIAVEL PARA GUARDAR O NUMERO DE LISTAS DE COMPRAS

	
} Lista_De_Compra;

typedef struct Produto_De_Lista { //ESTRUTURA AUXILIAR PARA GUARDAR OS CAMPOS DO PRODUTO

	ptrProduto Produto_Lista; //PONTEIRO DO TIPO PTRPRODUTO

	int quantidade; //QUANTIDADE DO PRODUTO

};

ptrLista_Compras criarlistaCompra(char* NomeLista,int n) {//CRIA A LISTA DE COMPRAS

	ptrLista_Compras Lista_De_Compra = (ptrLista_Compras)malloc(sizeof(struct Lista_De_Compra)); //ALOCA MEMORIA PARA A LISTA DE COMPRAS
	
	Lista_De_Compra->NomeListaCompra = (char*)malloc(sizeof(char) * (strlen(NomeLista) + 1)); //ALOCA MEMORIA PARA O NOMEE DA LISTA
	
	strcpy(Lista_De_Compra->NomeListaCompra, NomeLista);//FAZ A COPIA DA STRING PARA O CAMPO
	
	Lista_De_Compra->ptrProdutoLista = (ptrProduto_De_Lista*)malloc(sizeof(ptrProduto_De_Lista) * n); // ALOCA MEMORIA PARA O ARRAY DE PONTEIROS DE PRODUTOS DE LISTA 

	Lista_De_Compra->n = n; //ATUALIZA O VALOR DO CAMPO

	
	for (int i = 0; i < n; i++)
	{
		Lista_De_Compra->ptrProdutoLista[i] = NULL; //INICIALIZA O ARRAY DE PONTEIROS COMO NULOS
	}

	return Lista_De_Compra; //RETORNA O OBJETO LISTA DE COMPRAS
}

void apagar(ptrLista_Compras Lista_Compra) {

	free(Lista_Compra->NomeListaCompra);//LIBERTA A MEMORIA DO CAMPO 

	free(Lista_Compra->ptrProdutoLista);//LIBERTA A MEMORIA DO ARRAY DE PONTEIROS

	free(Lista_Compra);//LIBERTA A MEMORIA DO OBJETO LISTA COMPRA

}
void listar_ListaCompra(ptrLista_Compras Lista_Compra) {

	printf("%s", Lista_Compra->NomeListaCompra); //LISTA O NOME DA LISTA DE COMPRAS

}
char* DaNomeListaCompra(ptrLista_Compras Lista_Compra) { //ACEDE AO CAMPO DO NOME DA LISTA DE COMPRAS

	return Lista_Compra->NomeListaCompra;

}
void InserirProdutoLista(ptrLista_Compras Lista, ptrProduto Produto, int quantidade) {
	
	for (int i = 0; i < Lista->n; i++) {

		if (Lista->ptrProdutoLista[i] == NULL) {//VERIFICA SE O PONTEIRO ESTA A APONTAR PARA NULO

			Lista->ptrProdutoLista[i] = (ptrProduto_De_Lista)malloc(sizeof(struct Produto_De_Lista)); //ALOCA MEMORIA PARA O PONTEIRO
			
			Lista->ptrProdutoLista[i]->Produto_Lista = Produto;//ATUALIZA O CAMPO DO PONTEIRO PRODUTO LISTA COM O NOME DO PRODUTO
			
			Lista->ptrProdutoLista[i]->quantidade = quantidade;//ATUALIZA O CAMPO DO PONTEIRO PRODUTO LISTA COM A QUANTIDADE
			
			printf("Produto inserido na lista com sucesso!\n");
			
			break;
		}
	}
}
int produtoJaInserido(ptrLista_Compras Lista, char* nomeProduto) {//VERIFICA SE O PRODUTO JA FOI INSERIDO NA LISTA SOLICITADA
	
	for (int i = 0; i < Lista->n; i++) {
	
		if (Lista->ptrProdutoLista[i] != NULL && strcmp(DaNomeProduto(Lista->ptrProdutoLista[i]->Produto_Lista), nomeProduto) == 0) {//SE O PRODUTO NAO FOR NULO E O NOME DO PRODUTO FOR IGUAL AO NOME INSERIDO PELO USUARIO
		
			// PRODUTO ENCONTRADO
			
			return 1; // RETORNA VERDADEIRO, DE MODO QUE ESSE PRODUTO JA FOI INSERIDO ANTERIORMENTE
		}
	}
	// SE O PRODUTO NAO FOI ENCONTRADO , RETORNA FALSO
	return 0;
}

void listarProdutosDaLista(ptrLista_Compras Lista_Compra) {

	for (int i = 0; i < Lista_Compra->n; i++) {
	
		if (Lista_Compra->ptrProdutoLista[i] != NULL) { //SE O PONTEIRO FOR DIFERENTE DE NULO , LISTA OS PRODUTOS DA LISTA DE COMPRAS

			printf("\nProduto:%s\t", DaNomeProduto(Lista_Compra->ptrProdutoLista[i]->Produto_Lista));
			
			printf("Quantidade:%i\t", Lista_Compra->ptrProdutoLista[i]->quantidade);
			
		}
	}
}
void removerProdutoDaLista(ptrLista_Compras Lista_Compra, char* nomeProduto) {//REMOVE O PRODUTO DA LISTA
	
	for (int i = 0; i < Lista_Compra->n; i++) {
	
		if (Lista_Compra->ptrProdutoLista[i] != NULL && strcmp(DaNomeProduto(Lista_Compra->ptrProdutoLista[i]->Produto_Lista), nomeProduto) == 0) {
		
			//O PRODUTO FOI ENCONTRADO
			
			free(Lista_Compra->ptrProdutoLista[i]); //LIBERA APENAS O PONTEIRO PARA O PONTEIRO DE LISTA
			
			Lista_Compra->ptrProdutoLista[i] = NULL; // DEFINE O PONTEIRO PARA O PRODUTO COM NULL NA LISTA
			
			printf("Produto '%s' removido da lista de compras.\n", nomeProduto);
			
			return; //RETORNA APOS REMOVER O PRODUTO
		}
	}
	//SE O PRODUTO NAO FOI ENCONTRADO NA LISTA
	
	printf("Produto '%s' não encontrado na lista de compras.\n", nomeProduto);
}

void marcarProdutoComprado(ptrLista_Compras Lista_Compra, char* nomeProduto, float precoUnitario, char* loja) {

	printf("Marcando...\n");

	for (int i = 0; i < Lista_Compra->n; i++) {

		if (Lista_Compra->ptrProdutoLista[i] != NULL && strcmp(DaNomeProduto(Lista_Compra->ptrProdutoLista[i]->Produto_Lista), nomeProduto) == 0) {

			// PRODUTO ENCONTRADO NA LISTA DE COMPRAS

			if (!DaComprado(Lista_Compra->ptrProdutoLista[i]->Produto_Lista)) { // VERIFICA SE O PRODUTO JA FOI MARCADO COMO COMPRADO

				if (precoUnitario < DaPrecoProduto(Lista_Compra->ptrProdutoLista[i]->Produto_Lista)) {

					// SE O PREÇO UNITARIO É MENOR QUE O PREÇO MINIMO, ATUALIZA OS CAMPOS DO PRODUTO
					
					setLojaProduto(Lista_Compra->ptrProdutoLista[i]->Produto_Lista, loja);
					
					setPrecoProduto(Lista_Compra->ptrProdutoLista[i]->Produto_Lista, precoUnitario);
					
					setComprado(Lista_Compra->ptrProdutoLista[i]->Produto_Lista, 1); // MARCAR O PRODUTO COMO COMPRADO
					
					printf("Produto '%s' atualizado como comprado com sucesso!\n", nomeProduto);
				}
				else {
					//CASO CONTRARIO, APENAS MARCA O PRODUTO COMPRADO
					
					printf("Produto '%s' marcado como comprado!\n", nomeProduto);
					
					setComprado(Lista_Compra->ptrProdutoLista[i]->Produto_Lista, 1); // MARCA O PRODUTO COMO COMPRADO
				}
			}
			else {
				// O PRODUTO JA FOI MARCADO COMO COMPRADO ANTERIORMENTE
				
				printf("Produto '%s' já foi marcado como comprado anteriormente.\n", nomeProduto);
			}
			return; 
		}
	}

	//SE O PRODUTO NAO FOI ENCONTRADO NA LISTA DE COMPRAS
	printf("Produto '%s' não encontrado na lista de compras.\n", nomeProduto);
}
void DesmarcarProdutoComprado(ptrLista_Compras Lista_Compra, char* nomeProduto) {
	
	char loja[] = "indefinido";//VARIAVEL PARA COLOCAR O CAMPO LOJA COMO INDEFINIDO JA QUE VAI SER DESMARCADO

	for (int i = 0; i < Lista_Compra->n; i++) {
	
		if ((Lista_Compra->ptrProdutoLista[i] != NULL) && (Lista_Compra->ptrProdutoLista[i]->Produto_Lista != NULL) && (strcmp(DaNomeProduto(Lista_Compra->ptrProdutoLista[i]->Produto_Lista), nomeProduto)) == 0) {
			
			//ATUALIZA E MODIFICA OS CAMPOS DA LOJA E PREÇO MINIMO COMO DESMARCADOS
			if (DaComprado(Lista_Compra->ptrProdutoLista[i]->Produto_Lista) == 1) {
				
				setLojaProduto(Lista_Compra->ptrProdutoLista[i]->Produto_Lista, loja);

				setPrecoProduto(Lista_Compra->ptrProdutoLista[i]->Produto_Lista, 100.0);

				printf("Produto '%s' desmarcado como não comprado.\n", nomeProduto);

				setComprado(Lista_Compra->ptrProdutoLista[i]->Produto_Lista, 0);

				return;
			}
		}
	}
	// O PRODUTO NAO FOI ENCONTRADO NA LISTA DE COMPRAS
	printf("Produto '%s' não encontrado na lista de compras.\n", nomeProduto);
}




