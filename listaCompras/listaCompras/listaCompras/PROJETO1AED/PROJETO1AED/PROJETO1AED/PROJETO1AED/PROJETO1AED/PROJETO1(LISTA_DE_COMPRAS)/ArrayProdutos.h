#ifndef ARRAY_PRODUTOS_H
#define ARRAY_PRODUTOS_H

#include "Produto.h"

void criarArrayProdutos(int nProdutos);

void apagarArrayProdutos();

int InserirProdutoNoArrayProdutos(ptrProduto p);

void apagarProdutoDeArray(char*);

void ListarProdutoDeArrayProduto();

void listarProdutoPorNome(char*);

void listarProdutoPorTipo(char*);

ptrProduto EncontrarProduto(char*);


#endif // !PRODUTO_H

