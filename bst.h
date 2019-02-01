#ifndef BST_H
#define BST_H

#include "type.h"

typedef struct bst Bst;

/*Inicializa uma árvore alocando o espaço necessário, preenchendo a chave com 
o inteiro dado e definindo o campo count como um. 
* inputs: um inteiro que representa a chave do nó.
* output: ponteiro para o nó da árvore.
* pre-condicao: o valor do inteiro deve ser positivo.
* pos-condicao: o nó da árvore foi criado corretamente.
*/
Bst * BST_build(Type item);

/*  Insere um nó na árvore.
* inputs: a árvore e um inteiro.
* output: a árvore.
* pre-condicao: o valor do inteiro deve ser positivo.
* pos-condicao: a árvore foi atualizada.
*/
Bst* BST_insert(Bst* tree, Type key);

/* Remove um determinado nó da árvore a partir do valor de sua chave.
* inputs: uma árvore e um inteiro.
* output: a árvore atualizada.
* pre-condicao: nenhuma.
* pos-condicao: se o elemento estava na árvore ele foi retirado.
*/
Bst* BST_remove (Bst* tree, Type key);

/* Retorna a chave mais próxima de um inteiro passado como parâmetro, isto é, a
chave com um valor igual ou maior ao valor do parâmetro.
* inputs: uma árvore e um inteiro.
* output: um inteiro.
* pre-condicao: nenhuma.
* pos-condicao: o valor mais próximo do inteiro foi retornado. Caso todos as
chaves sejam menores que o valor do parâmetro é retornado -1.
*/
Type BST_search(Bst* tree, Type k);

/* Libera todo a memória alocada por uma árvore.
* inputs: uma árvore.
* output: nenhum.
* pre-condicao: a árvore não está vazia.
* pos-condicao: a memória alocada pela árvore foi liberada.
*/
void BST_destroy(Bst* tree);

/* Verifica se uma árvore está vazia.
* inputs: uma árvore.
* output: um inteiro.
* pre-condicao: nenhuma.
* pos-condicao: 1 caso a árvore esteja vazia e 0, caso contrário.
*/
int BST_empty(Bst* tree);

#endif