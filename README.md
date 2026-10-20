# Shopping List Manager

A **shopping list manager** written in C, built on top of custom **array-based data structures**. The program allows the user to manage multiple shopping lists, each containing products with a name and category.

## Problem

Implement from scratch the core data structures — dynamic arrays of products and shopping lists — without relying on any standard container library. All memory is managed manually with `malloc`/`free`.

## Features

- Create and manage multiple shopping lists
- Add products (name + category) to a global product catalogue
- Add products from the catalogue to a specific shopping list
- Mark and unmark products as purchased
- List all products in a shopping list
- List all available shopping lists
- Input validation to handle user errors gracefully

## Data structures

| Structure | Description |
|-----------|-------------|
| `Produto` | A product with name and category (dynamic strings) |
| `ArrayProdutos` | Dynamic array of pointers to `Produto` |
| `ListaDeCompra` | A named shopping list holding references to products and their purchased state |
| `ArrayListaCompras` | Dynamic array of `ListaDeCompra` |

## Technologies

- C (C standard library only)
- Visual Studio (`.sln` / `.vcxproj` project files included)

## Project structure

```
Main.c                  # Entry point and menu logic
Produto.c / .h          # Product struct and operations
ArrayProdutos.c / .h    # Dynamic array of products
ListaDeCompra.c / .h    # Shopping list struct and operations
ArrayListaCompras.c / .h # Dynamic array of shopping lists
```

## How to build and run

### With Visual Studio
1. Open `PROJETO1_DEFINITIVO.sln`
2. Build → Run (`Ctrl+F5`)

### With GCC (command line)
```bash
gcc Main.c Produto.c ArrayProdutos.c ListaDeCompra.c ArrayListasCompras.c -o shopping
./shopping
```

### Example interaction
```
1 -> Inserir novo produto
2 -> Criar nova lista de compras
3 -> Adicionar produto a uma lista
4 -> Marcar produto como comprado
5 -> Desmarcar produto
6 -> Listar produtos de uma lista
7 -> Listar todas as listas
0 -> Sair
```

## Course

Algorithms and Data Structures — 1st year, 2nd semester (2023/2024)
