#include "sort.h"

int partition(Type *a, int lo, int hi) {
    int i = lo;
    int j = hi+1;
    Type v = a[lo];
    
    while(1) {
        while (!less(a[++i], v)) {  
            if (i == hi) {
                break;
            }
        }
        while (!less(v, a[--j])) {  
            if (j == lo) {
                break;
            }
        }
        if (i >= j) { 
            break;
        }
        exch(a[i], a[j]);
    }
    exch(a[lo], a[j]); 
    return j; 
}

void quick_sort(Type *a, int lo, int hi) {
    if (hi <= lo) {
        return;
    }
    int j = partition(a, lo, hi);
    quick_sort(a, lo, j-1);
    quick_sort(a, j+1, hi);
}

void sort(Type *a, int lo, int hi) {
    quick_sort(a, lo, hi);
}
