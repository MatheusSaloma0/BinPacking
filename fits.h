#ifndef FITS_H
#define FITS_H
#include "bst.h"
#include "heap.h"
#include "type.h"

/* Realiza o método de worstfit para empacotar os arquivos em discos.
* inputs: um vetor de inteiros e o tamanho do vetor.
* output: um inteiro.
* pre-condicao: nenhuma.
* pos-condicao: o número de discos utilizado é retornado.
*/
int worstFit (Type* files, int size);

/* Realiza o método de bestfit para empacotar os arquivos em discos.
* inputs: um vetor de inteiros e o tamanho do vetor.
* output: um inteiro.
* pre-condicao: nenhuma.
* pos-condicao: o número de discos utilizado é retornado.
*/
int bestFit(Type *files, int size);

/* Realiza o método worstfit e bestfit para um vetor de inteiros. Em seguida ordena 
o vetor e realiza os métodos novamente.
* inputs: um vetor de inteiros e o tamanho do vetor.
* output: nenhum.
* pre-condicao: nenhuma.
* pos-condicao: o número de discos utilizado em cada um dos métodos é retornado 
(worstfit, bestfit, worstfit decrescente e bestfit decrescente, respectivamente).
*/
void fits(Type *files, int size);

#endif