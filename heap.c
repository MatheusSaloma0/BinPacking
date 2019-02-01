#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

struct bin_heap {
    Type* pq;
    int n;
};

// Inicializa a heap binária dado um inteiro que determina o tamanho da heap
MaxHeap* Init_Heap (int size) {
    MaxHeap* h = malloc (sizeof(*h));

    h->pq = malloc ((size+1)*(sizeof(Type*)));
    h->n = 0;

    return h;
}

// Libera a memória alocada pela MaxHeap Binária
MaxHeap* free_Heap (MaxHeap* heap) {
    free(heap->pq);
    free(heap);

    return NULL;
}

// Função necessária caso a chave do filho esteja maior que a do pai
void fix_up(Type* a, int k) {

    while (k > 1 && less(a[k/2], a[k])) {
        exch(a[k], a[k/2]);
        k = k/2;
    }
}

// Função necessária caso a chave do pai está menor que um dos filhos
void fix_down(Type* a,int sz, int k){
    while (2*k <= sz){
        int j = 2*k;
        if (j < sz && less(a[j], a[j + 1])){
            j++;
        }
        if (!less(a[k], a[j])){
            break;
        }
        exch(a[k], a[j]);
        k = j;
    }
}

//Inserção de um elemento na heap, fazendo as devidas modificações para manter a ordem
void PQ_insert(MaxHeap* heap, Type v){
    heap->n++;
    heap->pq[heap->n] = v;
    fix_up(heap->pq, heap->n);
}

//Remover o elemento máximo
Type PQ_delmax(MaxHeap* heap) {
    Type max = heap->pq[1];
    exch(heap->pq[1], heap->pq[heap->n]);
    heap->n--;
    fix_down(heap->pq, heap->n, 1);
    
    return max;
}

//Retorna o valor do maior valor da heap
Type PQ_max (MaxHeap* heap) {
    return heap->pq[1];
}

//Retorna o tamanho de elementos da heap
int getN (MaxHeap* heap) {
    return heap->n;
}

