#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "Produto.h"
#include "ListaDeCompra.h"

ptrLista_Compras* ListaCompras;//DEFINE UM PONTEIRO QUE APONTA PARA O PONTEIRO DO TIPO LISTA DE COMPRAS

ptrProduto_De_Lista* Produto_De_Lista; //DEFINE UM PONTEIRO QUE APONTA PARA O PONTEIRO DO TIPO PRODUTO DE LISTAS

ptrProduto *Produto;//DEFINE UM PONTEIRO QUE APONTA PARA O PONTEIRO DO TIPO PRODUTO



int nlista;//NUMERO DE PRODUTOS

int num_listas_atuais;//NUMERO DE LISTAS DE COMPRAS ATUAIS


void criarArrayListaDeCompras(int nListas_de_Compras) {

	nlista = nListas_de_Compras; //PASSA O VALOR À VARIAVEL LOCAL

	ListaCompras = (ptrLista_Compras*)malloc(sizeof(ptrLista_Compras) * nlista);//ALOCA MEMORIA PARA O ARRAY DE PONTEIROS COM O RESPETIVO TAMANHO DO NUMERO DE LISTAS DE COMPRAS

	for (int i = 0; i < nlista; i++)
	{
		ListaCompras[i] = NULL;//INICIALIZA OS PONTEIROS COM VALOR NULL

	}
	num_listas_atuais = 0;//INICIAMOS COM ZERO LISTAS ATUAIS CRIADAS

}

int InserirListaComprasNoArrayListasDeCompras(ptrLista_Compras l) {

	for (int i = 0; i < nlista; i++) {
		if (ListaCompras[i] == NULL) {      // ENCONTRA UMA POSIÇÃO VAZIA
			
			ListaCompras[i] = l;            //ATRIBUI A INFORMAÇÃO PARA A LISTA DE COMPRAS
			
			num_listas_atuais++;			//INCREMENTA  O NUMERO DE LISTAS
			
			return 1;
		}
	}

	return 0;



}
void ApagarListaDeComprasDeArray(char* NomeLista) {


	for (int i = 0; i < nlista; i++) {

		if (ListaCompras[i] != NULL && (strcmp(DaNomeListaCompra(ListaCompras[i]), NomeLista) == 0)) {

			apagar(ListaCompras[i]);//APAGA A LISTA DE COMPRAS
			
			ListaCompras[i] = NULL;//VOLTA A COLOCAR O PONTEIRO A APONTAR PARA NULL
			
			num_listas_atuais--; //DIMINUI O NUMERO DE LISTAS ATUAIS
			
			printf("Lista apagada com sucesso");
			
			break;//SAI DO CICLO

		}
		
	}

}

void ListarListasDeComprasArrayLista() {

	int i;

	printf("\n\n** Listagem de Listas de Compras **\n");

	for (i = 0; i < nlista; i++) {

		if (ListaCompras[i] != NULL) {//SE FOR DIFERENTE DE NULL
			
			printf("\nLista De Compras %i\n", i + 1);
			
			listar_ListaCompra(ListaCompras[i]);//LISTA TODAS AS LISTAS DE COMPRAS
		}
	}
}
void ApagarArrayListaDeCompras() {

	for (int i = 0; i < nlista; i++)
	{
		if (ListaCompras[i] != NULL) {

			apagar(ListaCompras[i]);
		}
	}
}
ptrLista_Compras EncontrarListaDeCompras(char* NomeLista) {//ECONTRA A LISTA DE COMPRAS A PARTIR DO NOME

	for (int i = 0; i < nlista; i++) {

		if (ListaCompras[i] != NULL && (strcmp(DaNomeListaCompra(ListaCompras[i]), NomeLista) == 0)) { //SE O NOME FOR IGUAL AO INSERIDO , E O PONTEIRO NAO ESTIVER APONTAR PARA NULL

			printf("Lista Encontrada!!!\n");

			return ListaCompras[i];//RETORNA A LISTA DE COMPRAS

		}
	}
	return NULL;//CASO CONTRARIO RETORNA NULL

}


