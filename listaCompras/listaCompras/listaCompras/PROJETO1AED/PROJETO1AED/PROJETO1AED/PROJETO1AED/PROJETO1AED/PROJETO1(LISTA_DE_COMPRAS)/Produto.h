#ifndef PRODUTO_H

#define PRODUTO_H

//Definição do tipo

typedef struct Produto* ptrProduto; 

//Cabeçalho das funções

ptrProduto criarProduto(char*, char*); 

void apagarProduto(ptrProduto);

void listarProduto(ptrProduto);

char* DaNomeProduto(ptrProduto);

char* DaTipoProduto(ptrProduto);

char* DaLojaProduto(ptrProduto);

float DaPrecoProduto(ptrProduto);

void setLojaProduto(ptrProduto);

void setPrecoProduto(ptrProduto,float);

int DaComprado(ptrProduto);

int setComprado(ptrProduto, int num);


#endif // !HEADERPRODUTO_H
