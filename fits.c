#include <stdio.h>
#include <stdlib.h>
#include "fits.h"
#include "sort.h"
#define MAX_SIZE 1000000

int worstFit (Type* files, int size){
    MaxHeap *heap = Init_Heap(size);
    PQ_insert(heap, MAX_SIZE);

    for(int i = 0; i < size; i++){
        if(files[i] < PQ_max(heap)){
            Type new = PQ_delmax(heap) - files[i];
            PQ_insert(heap,new);
        }
        else {
            PQ_insert(heap, MAX_SIZE-files[i]);
        }
    }
    Type aux = getN(heap);
    free_Heap(heap);

    return aux;
}

int bestFit (Type* files, int size) {
    Bst* tree = BST_build(MAX_SIZE);

    int count = 1;
    for(int i = 0; i < size; i++){
        Type aux = BST_search(tree,files[i]);

        if(aux == -1){
            if (MAX_SIZE - files[i] > 0) {
                tree = BST_insert(tree, MAX_SIZE - files[i]);
            }
            count++;
        }
        else {
            tree = BST_remove(tree,aux);
            if (aux - files[i] > 0){
                tree = BST_insert(tree, aux - files[i]);
            }
        }
    }
    BST_destroy(tree);

    return count;
}

void fits (Type* files, int size) {
    printf("%d\n",worstFit(files,size));
    printf("%d\n",bestFit(files,size));

    sort(files,0,size-1);

    printf("%d\n", worstFit(files, size));
    printf("%d\n", bestFit(files, size));
}
