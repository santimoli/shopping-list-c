#ifndef LISTA_DE_COMPRAS_H
#define LISTA_DE_COMPRAS_H
#include "Produto.h"

//DEFINIÇÃO DO TIPO

typedef struct Lista_De_Compra* ptrLista_Compras;

typedef struct Produto_De_Lista* ptrProduto_De_Lista;

//CABEÇALHO DAS FUNÇÕES 

ptrLista_Compras criarlistaCompra(char*);

void apagar(ptrLista_Compras); // FUNÇÃO APAGAR LISTA DE COMPRAS

void listar_ListaCompra(ptrLista_Compras);//FUNÇÃO LISTAR LISTA DE COMPRAS

char* DaNomeListaCompra(ptrLista_Compras);//FUNÇÃO PARA ACEDER AO NOME DA LISTA

void InserirProdutoLista(ptrLista_Compras,ptrProduto,int); //FUNÇÃO INSERIR PRODUTO NA LISTA DE COMPRAS

void listarProdutosDaLista(ptrLista_Compras); //FUNÇÃO PARA LISTAR PRODUTOS DE UMA LISTA

void removerProdutoDaLista(ptrLista_Compras,char*); //FUNÇÃO PARA REMOVER PRODUTOS DE UMA LISTA

void marcarProdutoComprado(ptrLista_Compras,char*,float, char* ); //FUNÇÃO PARA MARCAR O PRODUTO COMPRADO

void DesmarcarProdutoComprado(ptrLista_Compras,char*);//FUNÇÃO PARA DESMARCAR PRODUTO MARCADO

int produtoJaInserido(ptrLista_Compras,char*); //FUNÇÃO PARA VERIFICAR SE O PRODUTO JA FOI INSERIDO ANTERIORMENTE


#endif // !LISTA_DE_COMPRAS_H

