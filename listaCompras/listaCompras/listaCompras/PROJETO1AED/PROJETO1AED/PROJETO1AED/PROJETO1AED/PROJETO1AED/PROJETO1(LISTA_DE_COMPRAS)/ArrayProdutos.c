#include <stdlib.h>
#include"ArrayProdutos.h"
#include "Produto.h"
#include <string.h>
#include <stdio.h>


ptrProduto* produtos; //DEFINE UM PONTEIRO QUE APONTA PARA O PONTEIRO DA ESTRUTURA PRODUTO

int nProduto;//NUMERO DE PRODUTOS

int num_produtos_atuais;//NUMERO DE PRODUTOS ATUAIS

void criarArrayProdutos(int nprodutos) { 

	nProduto = nprodutos;//ATRIBUI O VALOR A VARIAVEL LOCAL

	produtos = (ptrProduto*)malloc(sizeof(ptrProduto) * nProduto);//ALOCA MEMORIA PARA O ARRAY DE PONTEIROS PRODUTOS

	for (int i = 0; i < nProduto; i++)
	{
		produtos[i] = NULL;//INICIALIZA OS PONTEIROS COMO NULL

	}
	num_produtos_atuais = 0;

}

void apagarArrayProdutos() {//APAGA OS PR0DUTOS DO ARRAY

	for (int  i = 0; i < nProduto; i++)
	{
		if (produtos[i] != NULL){
			
			apagarProduto(produtos[i]);
		}
	}
}

int InserirProdutoNoArrayProdutos(ptrProduto p) {//INSERE UM PRODUTO NO ARRAY PRODUTOS

	for (int i = 0; i < nProduto; i++) {

		if (produtos[i] == NULL) {   //VERIFICA SE ESTA APONTAR PARA O VAZIO

			produtos[i] = p;

			num_produtos_atuais++;

			return 1;
		}
	}
	return 0;
}

void apagarProdutoDeArray(char* nome_produto) {

	for (int i = 0; i < nProduto; i++)
	{
		if (produtos[i] != NULL && (strcmp(DaNomeProduto(produtos[i]), nome_produto)==0)){//SE FOR DIFERENTE DE NULL E O NOME FOR IGUAL 

			apagarProduto(produtos[i]);//APAGA O PRODUTO
			
			produtos[i] = NULL;//REINCIA O PONTEIRO COM VALOR NULL
			
			num_produtos_atuais--;//DIMINUI O NUMERO DE PRODUTO ATUAIS
			
			break;//SAI DO CICLO

		}
		else
		{
			printf("Produto nao encontrado");
			
			break;
		}
	}
}
void ListarProdutoDeArrayProduto() {//LISTA TODOS OS PRODUTOS DO ARRAY

	int i;

	printf("\n\n** Listagem de Produtos **\n\n");

	for (i = 0; i < nProduto; i++) {

		if (produtos[i] != NULL) {

			listarProduto(produtos[i]);
		}
	}
}

void listarProdutoPorNome(char* NomeProduto) {//LISTA OS PRODUTOS PELO NOME

	printf("\n\n***Listagem de Produtos***\n\n");
	
	for (int  i = 0; i < nProduto; i++)
	{
		if (produtos[i] != NULL && strstr(DaNomeProduto(produtos[i]), NomeProduto)) {
			
			printf("\nProduto %i", i + 1);
			
			listarProduto(produtos[i]);

		}

	}

}

void listarProdutoPorTipo(char* TipoProduto) {//LISTA OS PRODUTOS PELO TIPO DO PRODUTO

	printf("\n\n***Listagem de Produtos***\n\n");

	for (int i = 0; i < nProduto; i++) {

		if (produtos[i] != NULL && (strcmp(DaTipoProduto(produtos[i]), TipoProduto) == 0)) {
			
			printf("\n******Produtos do Tipo: %s \n", TipoProduto);
			
			printf("\nProduto %i", i + 1);
			
			listarProduto(produtos[i]);
		}
	}

}
ptrProduto EncontrarProduto(char* NomeProduto) {//ENCONTRA O PRODUTO A PARTIR DO NOME

	for (int i = 0; i < nProduto; i++) {

		if (produtos[i] != NULL && (strcmp(DaNomeProduto(produtos[i]), NomeProduto) == 0)) {

			printf("Produto Encontrado!!!\n");

			return produtos[i];//RETORNA O OBJETO PRODUTO

		}
	}
	printf("Produto '%s' nao encontrado!\n", NomeProduto);
	
	return NULL;//CASO CONTRARIO RETORNA NULL

}