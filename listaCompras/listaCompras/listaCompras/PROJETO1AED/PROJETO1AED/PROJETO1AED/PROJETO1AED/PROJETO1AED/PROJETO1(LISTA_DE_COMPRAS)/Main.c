#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Produto.h"
#include "ArrayProdutos.h"
#include "ListaDeCompra.h"
#include "ArrayListaCompras.h"
#include "ListaDeCompra.h"

/*PROJETO NUMERO 1: ALGORITMOS E ESTRUTURAS DE DADOS

PROJETO 1: LISTA DE COMPRAS

AUTOR: SANTIAGO MOLINA SANCHEZ (25151)

DATA: 28/04/2024

NOTA:

ESTOU A ENVIAR O PROJETO Nº 1 DE  ALGORITMOS E ESTRUTURAS DE DADOS COM AS DEVIDAS MELHORIAS PREVIAMENTE INFORMADAS SENDO ESTAS AS SEGUINTES:
		->FOI LISTADAS AS LISTAS DE COMPRAS CORRETAMENTE.
		->FORAM IMPLEMENTADAS AS FUNÇÕES DE MARCAR E DESMARCAR.
		->FORAM ADICIONADAS FUNÇÕES PARA LIDAR COM AS EXCEÇÕES DO UTILIZADOR E TENTAR MANTER E CODIGO MAIS RIGIDO E SOLIDO.
		->CODIGO DEVIDAMENTE COMENTADO

É NECESSARIO REFERIR QUE SURGIRAM ALGUMAS DIFICULDADES EM RELAÇÃO À UTILIZAÇÃO DOS PONTEIROS PARA ESTRUTURAS, MAS QUE FORAM SENDO RESOLVIDAS AO LONGO DA
REALIZAÇÃO DO PROJETO E A PARTIR DO MATERIAL TEORICA DAS AULAS.


OBRIGADO.

SANTIAGO MOLINA SANCHEZ (24151)

*/

char NomeProduto[2048]; // VARIAVEL GERAL PARA LER STRING DO TECLADO

char TipoProduto[2048]; // VARIAVEL GERAL PARA LER STRING DO TECLADO

void inserirNovoProdutoNoArrayProdutos() {
	
	ptrProduto Produto = NULL;  //IGUALA O PONTEIRO A NULO

	printf("Indique o nome do Produto:");

	fgets(NomeProduto, sizeof(NomeProduto), stdin);
	
	NomeProduto[strcspn(NomeProduto, "\n")] = '\0';

	printf("Indique o Tipo do Produto:");
	
	fgets(TipoProduto, sizeof(TipoProduto), stdin);
	
	TipoProduto[strcspn(TipoProduto, "\n")] = '\0';

	Produto = criarProduto(NomeProduto,TipoProduto); //CHAMA A FUNÇÃO PARA PODER CRIAR O PRODUTO

	if (!InserirProdutoNoArrayProdutos(Produto)) { //SE NAO FOI INSERIDO NO ARRAY DE PRODUTOS, SIGNIFICA QUE ESTA A MEMORIA CHEIA
	
		printf("Memoria cheia!\n");
		
		apagarProduto(Produto); //É APAGADO O PRODUTO PARA NAO FICAR LIXO
	}

}
void RetirarProduto() {

	printf("indique o nome do produto que deseja retirar:"); //PEDE O NOME DO PRODUTO PARA REMOVER

	fgets(NomeProduto, sizeof(NomeProduto), stdin);

	NomeProduto[strcspn(NomeProduto, "\n")] = '\0';

	apagarProdutoDeArray(NomeProduto);// CHAMA A FUNÇÃO PARA APAGAR O PRODUTO DO ARRAY PRODUTOS

}
void clearInputBuffer() { //FUNÇÃO IMPLEMENTADA PARA LIDAR COM O BUFFER DE ENTRADA

	int c;

	while ((c = getchar()) != '\n' && c != EOF);

}
void listarProdutosPorTipo(ptrProduto* Produto, int n) {

	printf("Indique o Tipo do Produto:"); 
	
	fgets(TipoProduto, sizeof(TipoProduto), stdin);
	
	TipoProduto[strcspn(TipoProduto, "\n")] = '\0';

	listarProdutoPorTipo(TipoProduto);// LISTA TODOS OS PRODUTOS COM O TIPO DE PRODUTO SOLICITADO

}

void ListarProdutosPorNome() {

	printf("\nIndique o nome do produto que deseja encontrar:");

	fgets(NomeProduto, sizeof(NomeProduto), stdin);

	// Remova o caractere de nova linha, se estiver presente
	NomeProduto[strcspn(NomeProduto, "\n")] = '\0';

	listarProdutoPorNome(NomeProduto); //LISTA TODOS OS PRODUTOS COM O TIPO DE PRODUTO SOLICITADO

}

void AdicionarNovaListaDeCompras(int n) { 

	ptrLista_Compras Lista = NULL; //IGUALA O PONTEIRO A NULO

	char Nomelista[2048]; //VARIAVEL PARA GUARDAR O NOME DA LISTA

	printf("Indique o nome da lista de Compras:");

	fgets(Nomelista, sizeof(Nomelista), stdin);
	
	Nomelista[strcspn(Nomelista, "\n")] = '\0';

	Lista = criarlistaCompra(Nomelista,n);// A LISTA É CRIADA

	if (!InserirListaComprasNoArrayListasDeCompras(Lista)) {//SE NAO É INSERIDA NO ARRAY DE LISTAS , A MEMORIA ESTA CHEIA
		
		printf("Memoria cheia!!");
		
		apagar(Lista);
	}

}
void ApagarListasDeCompras() {
	
	char ListaDeCompras[2048];

	printf("indique o nome da lista de Compras que deseja apagar:");

	fgets(ListaDeCompras, sizeof(ListaDeCompras), stdin);

	ListaDeCompras[strcspn(ListaDeCompras, "\n")] = '\0';
	
	ApagarListaDeComprasDeArray(ListaDeCompras);//CHAMA A FUNÇÃO PARA APAGAR A LISTA DE COMPRAS DO ARRAY DE LISTA DE COMPRAS


}
void AdicionarProdutosAlistaCompras() {

	char NomeLista[2048];
	
	int quantidade;
	
	char NomeProduto[2048];

	printf("Escreva o nome da lista de compras:");
	
	fgets(NomeLista, sizeof(NomeLista), stdin);
	
	NomeLista[strcspn(NomeLista, "\n")] = '\0';

	ptrLista_Compras Lista = EncontrarListaDeCompras(NomeLista);//VERFICA SE ENCONTROU A LISTA DE COMPRAS 

	if (Lista == NULL) {
	
		printf("Lista invalida!\n");
		
		return;
	}

	ListarProdutoDeArrayProduto();//MOSTRA OS PRODUTOS DISPONIVES AO UTILIZADOR PARA QUE POSSA ESCOLHER O PRETENDIDO

	printf("\nIndique o Produto que deseja adicionar na lista de Compras:");
	
	fgets(NomeProduto, sizeof(NomeProduto), stdin);
	
	NomeProduto[strcspn(NomeProduto, "\n")] = '\0';

	ptrProduto Produto = EncontrarProduto(NomeProduto);//VERIFICA SE FOI ENCONTRADO O PRODUTO

	if (produtoJaInserido(Lista, NomeProduto)) {//CHAMA A FUNÇÃO PARA VERIFICA SE ESSE PRODUTO JA FOI INSERIDO ANTERIORMENTE NA LISTA DE COMPRAS 
		
		printf("Produto ja esta na lista de compras!\n");
		
		return;
	}

	if (Produto == NULL) { //  SE O PRODUTO NAO FOI ENCONTRADO, É PERGUNTADO AO USUARIO SE DESEJA CRIAR UM NOVO PRODUTO 
		
		char opcao;
		
		printf("Produto nao encontrado. Deseja criar um novo produto com este nome? (S/N): ");//DA A POSSIBILIDADE AO UTILIZADOR DE CRIAR UM PRODUTO NOVO 

		scanf(" %c", &opcao);

		clearInputBuffer();

		if (opcao == 'S' || opcao == 's') {
			
			char tipoProduto[2048];
			
			printf("Digite o tipo de produto: ");
			
			fgets(tipoProduto, sizeof(tipoProduto), stdin);
			
			tipoProduto[strcspn(tipoProduto, "\n")] = '\0';
			
			Produto = criarProduto(NomeProduto, tipoProduto); //CRIA O NOVO PRODUTO

			InserirProdutoNoArrayProdutos(Produto);//INSERE O PRODUTO CRIADO NO ARRAY PRODUTOS


			if (Produto == NULL) {
				
				printf("Erro ao criar o produto!\n");
				
				return;
			}
		}
		else {
			
			printf("Operacao cancelada pelo usuario.\n");
			
			return;
		}
	}

	printf("Indique a quantidade que deseja inserir:");

	scanf("%i", &quantidade);
	
	if (quantidade <= 0) {
	
		printf("Erro: Quantidade invalida.\n");
		
		return;
	}

	InserirProdutoLista(Lista, Produto, quantidade);//CHAMA FUNÇÃO PARA INSERIR O PRODUTO NA LISTA DE COMPRAS DESEJADA
}
void ListarProdutosDeListaCompras(int nlistacompras) { 

	char NomeLista[2048];

	printf("Digite o nome da lista de compras que deseja listar os produtos:\n");//É PEDIDO O NOME DA LISTA PARA LISTAR OS PRODUTOS DESSA LISTA
	
	fgets(NomeLista, sizeof(NomeLista), stdin);
	
	NomeLista[strcspn(NomeLista, "\n")] = '\0';

	ptrLista_Compras lista = EncontrarListaDeCompras(NomeLista);//ENCONTRA A LISTA DE COMPRAS
	
	if (lista == NULL) {
		
		printf("Lista de compras nao encontrada!\n");
		
		return;
	}
	printf("Produtos da lista de compras '%s':\n", NomeLista);
	
	listarProdutosDaLista(lista);//CHAMA A FUNÇÃO PARA LISTAR OS PRODUTOS DA  LISTA DE COMPRAS
}

void RetirarProdutoLista() {

	char NomeLista[2048];

	char NomeProduto[2048];

	printf("Digite o nome da lista de compras a qual deseja retirar um produto:\n");

	fgets(NomeLista, sizeof(NomeLista), stdin);

	NomeLista[strcspn(NomeLista, "\n")] = '\0';

	ptrLista_Compras lista = EncontrarListaDeCompras(NomeLista); //ENCONTRA A LISTA DE COMPRAS

	if (lista == NULL) {

		printf("Lista de compras nao encontrada!\n");

		return;
	}

	printf("\nIndique o nome do produto que deseja retirar da lista:");

	fgets(NomeProduto, sizeof(NomeProduto), stdin);

	NomeProduto[strcspn(NomeProduto, "\n")] = '\0';

	removerProdutoDaLista(lista, NomeProduto);//CHAMA A FUNÇÃO PARA REMOVER O PRODUTO DA LISTA (MAS NAO ELIMINA O PRODUTO)

}
void MarcarProdutoComoComprado() {

	char NomeLista[2048]; //VARIAVEL PARA GUARDAR O NOME DA LISTA DO USUARIO

	char NomeProduto[2048]; //VARIAVEL PARA GUARDAR O NOME DO PRODUTO DO USUARIO

	char Loja[2048]; //VARIAVEL PARA GUARDAR A LOJA DO USUARIO

	float preco; //VARIAVEL PARA GUARDAR O PREÇO DO USUARIO


	printf("Digite o nome da lista:\n");

	fgets(NomeLista, sizeof(NomeLista), stdin);

	NomeLista[strcspn(NomeLista, "\n")] = '\0';

	ptrLista_Compras lista = EncontrarListaDeCompras(NomeLista);//ENCONTRA A LISTA DE COMPRAS

	if (lista == NULL) {

		printf("Lista de compras nao encontrada!\n");

		return;
	}

	printf("\nIndique o nome do produto que deseja marcar da lista:");//É PEDIDO O NOME DO PRODUTO DESEJADO PARA MARCAR COMO COMPRADO

	fgets(NomeProduto, sizeof(NomeProduto), stdin);

	NomeProduto[strcspn(NomeProduto, "\n")] = '\0';

	ptrProduto Produto = EncontrarProduto(NomeProduto);//ENCONTRA O PRODUTO PRETENDIDO
	
	printf("\nIndique a loja onde foi comprado o produto:"); //PEDE A LOJA PARA POSTERIORMENTE ATUALIZAR ESTE CAMPO

	fgets(Loja, sizeof(Loja), stdin);

	Loja[strcspn(Loja, "\n")] = '\0';

	printf("Indique o preco ao que foi comprado:");//PEDE O PREÇO AO QUE FOI COMPRADO

	scanf("%f", &preco);

	if (preco <= 0.0) {//VERIFICA SE É UM PRODUTO VALIDO

		printf("Preco Invalido!!");
		
		return;
	}
	clearInputBuffer();//LIMPA OS CARATERES NAO DESEJADOS

	marcarProdutoComprado(lista, NomeProduto, preco, Loja);//CHAMA A FUNÇÃO PARA MARCAR O PRODUTO COMO COMPRADO
}

void DesmarcarProdutoComoComprado() {

	char NomeLista[2048];

	char NomeProduto[2048];

	printf("Digite o nome da lista:\n");//PEDE O NOME DA LISTA
	
	fgets(NomeLista, sizeof(NomeLista), stdin);
	
	NomeLista[strcspn(NomeLista, "\n")] = '\0';

	ptrLista_Compras lista = EncontrarListaDeCompras(NomeLista);//ENCONTRA A LISTA DE COMPRAS PRETENDIDA

	printf("Digite o nome do produto a ser desmarcado como comprado:\n"); //PEDE O NOME DO PRODUTO PARA SER DESMARCADO
	
	fgets(NomeProduto, sizeof(NomeProduto), stdin);
	
	NomeProduto[strcspn(NomeProduto, "\n")] = '\0';

	ptrProduto Produto = EncontrarProduto(NomeProduto);//ENCONTRA O PRODUTO PRETENDIDO

	if (lista == NULL) {//VERIFICA SE O PONTEIRO NAO É NULO
	
		printf("Lista de compras nao encontrada!\n");
		
		return;
	}

	DesmarcarProdutoComprado(lista, NomeProduto);//CHAMA A FUNÇÃO PARA DESMARCAR O PRODUTO PRETENDIDO
}
int menu() {//MENU QUE É MOSTRADO AO UTILIZADOR PARA QUE POSSA ESCOLHAR A OPÇÃO SOLICITADA

	int opcao;

	printf("\n\n  *** MENU ***\n\n");

	printf("1 ->Inserir novo Produto\n");

	printf("2 -> Apagar Produto\n");

	printf("3 -> listar Produtos\n");

	printf("4 -> listar Produtos por Tipo de produto\n");

	printf("5 -> listar Produtos por Nome de produto\n");

	printf("6 -> Adicionar lista de Compras\n");

	printf("7 -> Apagar lista de Compras:\n");

	printf("8 -> Listar listas de Compras:\n");

	printf("9 -> Adicionar Produto a lista de compras\n");

	printf("10 -> Retirar produto de lista de Compras\n");

	printf("11 -> Listar Produtos de listas de compras\n");

	printf("12 -> Marcar Produto como comprado\n");

	printf("13 -> Desmarcar Produto\n");

	printf("0 -> sair\n");

	printf("\n->Indique a sua opcao: ");

	scanf("%i", &opcao);

	clearInputBuffer();//LIMPA OS CARATERES NAO DESEJADOS

	return opcao;//RETORNA A OPCAO
}





int main(){

	int n;//NUMERO DE PRODUTOS

	int opcao; //OPCAO PRETENDIDA PELO USUARIO

	int i;

	int nlistasCompras;//NUMERO DE LISTAS DE COMPRAS

	printf("Indique o numero de produtos:");

	scanf("%i", &n);

	printf("Indique o numero de listas de Compras:");

	scanf("%i", &nlistasCompras);

	ptrProduto* Produto; // DECLARAMOS UM PONTEIRO PARA O PONTEIRO DA ESTRUTURA PRODUTO

	Produto = (ptrProduto*)malloc(n * sizeof(ptrProduto));//ALOCAMOS MEMORIA DINAMICAMENTE PARA ESSE PONTEIRO

	ptrLista_Compras* ListaDeCompras; // DECLARAMOS UM PONTEIRO PARA O PONTEIRO DA ESTRUTURA LISTA DE COMPRAS

	ListaDeCompras = (ptrLista_Compras*)malloc(nlistasCompras * sizeof(ptrLista_Compras)); //ALOCAMOS MEMORIA DINAMICAMENTE PARA ESSE PONTEIRO

	criarArrayProdutos(n);//CRIAMOS INICIALMENTE O ARRAY DE PRODUTOS COM O VALOR REQUERIDO PELO UTILIZADOR

	criarArrayListaDeCompras(nlistasCompras);//CRIAMOS INICIALMENTE O ARRAY DE LISTAS DE COMPRAS COM O VALOR REQUERIDO PELO UTILIZADOR

	do {
		opcao = menu();

		switch (opcao) {
		case 0:
			printf("Obrigado por utilizar este programa!");
			break;
		case 1:
			inserirNovoProdutoNoArrayProdutos();
			break;
		case 2:
			RetirarProduto();
			break;
		case 3:
			ListarProdutoDeArrayProduto();
			break;
		case 4:
			listarProdutosPorTipo(Produto, n);
			break;
		case 5:
			ListarProdutosPorNome();
			break;
		case 6:
			AdicionarNovaListaDeCompras(n);
			break;
		case 7:
			ApagarListasDeCompras();
			break;
		case 8:
			ListarListasDeComprasArrayLista();
			break;
		case 9:
			AdicionarProdutosAlistaCompras();
			break;
		case 10:
			RetirarProdutoLista();
			break;
		case 11:
			ListarProdutosDeListaCompras(nlistasCompras);
			break;
		case 12:
			MarcarProdutoComoComprado();
			break;
		case 13:
			DesmarcarProdutoComoComprado();
			break;



		default:
			printf("\n\nOpcao errada\n");
		}
	} while (opcao != 0);

	//LIBERAMOS A MEMORIA DOS ARRAYS E DOS PONTEIROS PARA NAO MANTER LIXO
	
	apagarArrayProdutos();

	ApagarArrayListaDeCompras();
	
	free(ListaDeCompras);

	free(Produto);

	return(0);
}