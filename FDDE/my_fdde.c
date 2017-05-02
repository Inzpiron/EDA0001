#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct nofila{
    void * dados;
    struct nofila * atras;
    struct nofila * defronte;
} NoFila;
 
typedef struct{
    int tamInfo;
    NoFila * frente;
    NoFila * cauda;
} Fila;
 
Fila * create(int tamInfo){
    Fila * fila = (Fila *) malloc(sizeof(Fila));
    fila -> frente  = (NoFila *) malloc(sizeof(NoFila));
    fila -> cauda   = (NoFila *) malloc(sizeof(NoFila));
    fila -> tamInfo = tamInfo;

    return fila;
}
 
void insere(Fila * fila, void * novo){
    NoFila * temp = (NoFila *) malloc(sizeof(NoFila));
    temp -> dados = (void *) malloc(sizeof(fila -> tamInfo));
    memcpy(temp -> dados, novo, fila->tamInfo);
    temp -> atras = temp -> defronte = NULL;
   
    if(fila -> frente == NULL) //testa vazia
        fila -> frente = fila -> cauda = temp;
    else{
        fila -> cauda -> atras = temp;
        temp -> defronte = fila -> cauda;
        fila -> cauda = temp;
        fila -> cauda -> atras = NULL;
    }
}

void * top(Fila * fila){
    if(fila->frente == NULL){
        printf("Fila está vazia");
        return 0;
    }
   
    return fila->cauda->dados; 
}
 
void * bottom(Fila * fila){
    return fila->cauda->dados;
}
 
int main(){
    Fila * fila = create(sizeof(int));
    top(fila);
    int valor = 0;
    insere(fila, &valor);
    printf("%d", *((int *) top(fila)));
}