#include <stdio.h>
#include <stdlib.h>
#include "fits.h"
#include "bst.h"

int main(int argc, char const *argv[]) {
    FILE* input = fopen(argv[1],"r");

    if(input != NULL) {
        int size;
        Type item;

        fscanf(input,"%d\n",&size);

        int* files = malloc(size*sizeof(*files));

        for(int i = 0; i < size && !feof(input); i++){
            fscanf(input,"%d\n",&item);
            files[i] = item;
        }

        fits(files,size);
    
        free(files);
        fclose(input);
    }
    else {
        printf("Arquivo %s inexistente\n",argv[1]);
    }
    return 0;
}