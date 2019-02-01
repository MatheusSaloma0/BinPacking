#ifndef Heap_H
#define Heap_H
#include "type.h"

typedef struct bin_heap MaxHeap;

/* Inicializa uma heap binária alocando o espaço necessário e definindo n como 0.
* inputs: o tamanho do vetor da heap.
* output: a heap.
* pre-condicao: nenhuma.
* pos-condicao: a heap foi criada de acordo com os parâmetros passados. 
*/
MaxHeap *Init_Heap(int size);

/* Libera a memória alocada pela heap;
* inputs: a heap binária.
* output: NULL.
* pre-condicao: a heap não é vazia. 
* pos-condicao: toda a memória alocada pela heap foi liberada.
*/
MaxHeap* free_Heap(MaxHeap *heap);

/* Caso em uma heap, o filho esteja maior que o pai, são realizadas operações 
para que o filho e o pai sejam trocados até que a ordem da heap seja reestabelecida.
* inputs: o vetor da heap e um inteiro.
* output: nenhum.
* pre-condicao: o vetor não é vazio.
* pos-condicao: a ordem da heap foi reestabelecida.
*/
void fix_up(Type *a, int k);

/* Caso em uma heap, o pai tenha um valor menor que o de um dos filhos, são 
realizadas operações para que o pai e o maior filho sejam trocados até que a 
ordem da fila seja reestabelecida. 
* inputs: o vetor da heap, o tamanho da heap, um inteiro.
* output: nenhum.
* pre-condicao: a fila não está vazia.
* pos-condicao: a ordem da fila foi reestabelecida.
*/
void fix_down(Type *a, int sz, int k);

/* Insere um valor na fila, ajustando sua posição a partir da função fix_up.
* inputs: uma heap binária e um inteiro.
* output: nenhum
* pre-condicao: o inteiro deve ter valor positivo.
* pos-condicao: o elemento foi inserido sem alterar as regras de organização da heap.
*/
void PQ_insert(MaxHeap* heap, Type v);

/* O primeiro e maior elemento da heap é retornado e retirado. Para tanto, ele é 
trocado com o último valor e é utilizada a operação fix_down para manter as regras 
de organização da heap.
* inputs: uma heap binária.
* output: um inteiro
* pre-condicao: a heap não é vazia.
* pos-condicao: o maior elemento foi retornado e retirado da heap.
*/
Type PQ_delmax(MaxHeap* heap);

/* Retorna o maior elemento da heap.
* inputs: uma heap binária.
* output: um inteiro.
* pre-condicao: a heap não é vazia.
* pos-condicao: o maior elemento é retornado.
*/
Type PQ_max (MaxHeap* heap);

/* Retorna o número de elementos da heap.
* inputs: uma heap.
* output: um inteiro.
* pre-condicao: nenhuma.
* pos-condicao: o número de elementos da heap é retornado.
*/
int getN(MaxHeap *heap);

#endif
