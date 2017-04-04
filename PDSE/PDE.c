#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//PILHA DINAMICA ENCADEADA
typedef struct nopde{
	struct nopde * atras;
	void * valor;
}noPDE;

typedef struct{
	noPDE * topo;
	int tamInfo;
	int size;
}PDE;


PDE * create(int tamInfo){
	PDE * p = (PDE *) malloc(sizeof(PDE));
	p -> topo    = NULL;
	p -> size    = 0;
	p -> tamInfo = tamInfo;
	return p;
}

int empty(PDE * p){
	if(p -> topo == NULL)
		return 1;

	return 0;
}

void * top(PDE * p)
{
	if (p -> topo != NULL)
		return p -> topo -> valor;
	else
		return NULL;
}

void push(PDE * p, void * v){
	noPDE * Item = (noPDE *)malloc(sizeof(noPDE));
	Item -> valor = (void *) malloc(p -> tamInfo);
	if(empty(p)){
		Item -> atras = NULL;
		memcpy(Item -> valor, v, p -> tamInfo);
		p -> topo = Item;
		p -> size = 1;
		//printf("A pilha estava vazia e foi adicionado %d ao topo\n", p -> topo -> valor);
	} else{
		//int t = p -> topo -> valor;
		noPDE * aux = (noPDE *)malloc(sizeof(noPDE));
		aux -> valor = v;
	 	aux -> atras = p -> topo;
	 	p -> topo = aux;
	 	p -> size++;
	 	//printf("O topo era %d, e agora será %d\n", t, p->topo->valor);
	}
}

int pop(PDE * p){
	if(empty(p)){
		//printf("Pilha esta vazia\n");
	}else{
		if(p -> topo -> atras != NULL){
			//int t = p -> topo -> valor;
			noPDE * aux = p -> topo -> atras;
			free(p -> topo);
			p -> topo = aux;
			//printf("O topo antigo era %d e agora sera %d\n", t, p->topo->valor);
			//return t;
		}else{	
			//int t = p -> topo -> valor;
			//printf("O topo antigo era %d, agora a pilha esta vazia\n", p -> topo -> valor);
			int tam = p->tamInfo;
			free(p -> topo);
			free(p);
			p = create(tam);

			//return t;
		}
	}
}

int main(){
	PDE * pilha = create(sizeof(int));
	int a[] = {1, 2, 3, 4, 5};
	push(pilha, &a[0]);
	push(pilha, &a[1]);
	push(pilha, &a[2]);
	push(pilha, &a[3]);
	push(pilha, &a[4]);
	pop(pilha);

	int * Topo = (int *) top(pilha);
	printf("topo é %d\n", *Topo);

	//char * topo = pilha -> topo -> valor;
	//printf("%c\n", topo(pilha));
	return 0;
}
