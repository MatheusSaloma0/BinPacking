#include<stdio.h> 
#include<stdlib.h> 
#include "bst.h"
  
struct bst { 
    Type key; 
    int count; //Permite que nós com chaves iguais sejam inseridas.
    Bst* left;
    Bst* right; 
}; 

 
Bst* BST_build(Type item) { 
    Bst* new =  (Bst*) malloc (sizeof(*new)); 
    new->key = item; 
    new->left = new->right = NULL; 
    new->count = 1; 
    
    return new; 
} 

int BST_empty(Bst* tree){
    return tree == NULL;
}
  
Bst* BST_insert(Bst* tree, Type key){ 
    if (tree == NULL) return BST_build(key); 
  
    if (key == tree->key) { // Caso já exista um nó com o valor da chave dada como 
       (tree->count)++;     // parâmetro, o campo count desse nó é incrementado para
       return tree;         // representar a quantidade de nós com a chave em questão.
    } 
  
    if (key < tree->key) {
        tree->left  = BST_insert(tree->left, key); 
    }
    else {
        tree->right = BST_insert(tree->right, key);         
    }
    return tree; 
} 
  
Bst* BST_remove(Bst* tree, Type key){ 
    if (tree == NULL) {
        return tree; 
    }
    if (key < tree->key) {
        tree->left = BST_remove(tree->left, key); 

    }  
    else if (key > tree->key) {
        tree->right = BST_remove(tree->right, key); 
    }
    else{ 
        if (tree->count > 1) {          // Caso exista mais de um nó com o valor da chave dada
            (tree->count)--;            // como parâmetro o nó não é realmente removido da árvore,
            return tree;                // o campo count é simplesmente decrementado.
        }
        // Caso 1: o nó representa uma folha.
        // Caso 2: o nó possui apenas um filho.

        if (tree->left == NULL) {       // Caso o nó só possua o filho da direita...
            Bst* tmp = tree->right;     // Caso o nó seja uma folha ele também entrará 
            free(tree);                 // nessa condição.
            return tmp; 
        } 
        else if (tree->right == NULL) { // Caso o nó só possua o filho da esquerda...
            Bst* tmp = tree->left; 
            free(tree); 
            return tmp; 
        }
        // Caso 3: o nó possui dois filhos.
        Bst* tmp = tree->right;         // São realizadas algumas operações para
        while (tmp->left != NULL){      // transformar o caso 3 em um dos casos anteriores.
            tmp = tmp->left;
        }
        tree->key = tmp->key; 

        tree->right = BST_remove(tree->right, tmp->key); 
    } 
    return tree; 
} 

Type BST_search (Bst* tree, Type item) {
  if(tree->key >= item){           // Caso o nó atual tenha espaço para o novo arquivo
    if(BST_empty(tree->left)){     // é verificado se existe opções a esquerda.
      return tree->key;            // Caso não exista, a chave do nó atual é retornada.
    }
    else{                          // Caso exista é realizada uma recursão no nó a esquerda.
      Type aux = BST_search(tree->left,item); // O resultado é armazenado em uma variável auxiliar.
      if(aux > 0) {                // Caso ela seja positiva quer dizer que foi encontrada uma
          return aux;              // opção melhor, e a chave desse nó será retornada.
      }
      else {  // Caso o valor da auxiliar seja negativo isso demonstra que não foi encontrado um
          return tree->key;        // nó válido e, portanto, o último nó válido será retornado.
      }
    }
  }
  else {                           // Caso o nó atual não tenha espaço para o arquivo
    if(BST_empty(tree->right)){    // é verificado se existem posições disponíveis a direita.
      return -1;                   // Caso não haja é retornado -1.
    }
    else {                         // Caso haja é realizada uma recursão no nó a direita.
      return BST_search(tree->right,item);
    }
  }
}

void BST_destroy(Bst* tree){
    if(tree == NULL){
        return;
    }
    BST_destroy(tree->right);
    BST_destroy(tree->left);
    free(tree);
}