#include <stdio.h>
#include <stdlib.h>

//PILHA DINAMICA ENCADEADA
typedef struct nopde{
	struct nopde * atras;
	int valor;
}noPDE;

typedef struct{
	noPDE * topo;
	int size;
}PDE;


PDE * create(){
	PDE * p = (PDE *) malloc(sizeof(PDE));
	p -> topo = NULL;
	p -> size  = 0;
	return p;
}

int empty(PDE * p){
	if(p -> topo == NULL)
		return 1;

	return 0;
}

void push(PDE * p, int v){
	noPDE * Item = (noPDE *)malloc(sizeof(noPDE));
	if(empty(p)){
		Item -> atras = NULL;
		Item -> valor = v;
		p -> topo = Item;
		p -> size = 1;
		//printf("A pilha estava vazia e foi adicionado %d ao topo\n", p -> topo -> valor);
	} else{
		int t = p -> topo -> valor;
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
			int t = p -> topo -> valor;
			noPDE * aux = p -> topo -> atras;
			free(p -> topo);
			p -> topo = aux;
			//printf("O topo antigo era %d e agora sera %d\n", t, p->topo->valor);
			return t;
		}else{	
			int t = p -> topo -> valor;
			//printf("O topo antigo era %d, agora a pilha esta vazia\n", p -> topo -> valor);
			free(p -> topo);
			free(p);
			p = create();

			return t;
		}
	}
}

int main(){
	system("clear");
	PDE * pilha = create();
	printf("Push: + value value ... | value[0,9] | pop: - - - ...\n");
	int quit = 0, entry = 0, cont = 0;
	while(!quit){
		char operation;
		scanf("%c", &operation);
		if(operation == '\n')
			printf("%d", operation);
		switch(operation){
			case '+':	
				while(scanf("%c", &entry) && entry != '\n'){
					if(entry >= '0' && entry <= '9'){
						int aux = (int)entry - (int)'0';
						push(pilha, aux);
					}
				}
			break;

			case '-':
				while(scanf("%c", &entry) && entry != '\n'){
					if(entry == '-')
						pop(pilha);
				}
			break;

			default:
				quit = 1;
			break;
		}

		if(!empty(pilha)){
			noPDE * Item = (noPDE *)malloc(sizeof(noPDE));
			Item = pilha -> topo;
			printf("Stack:");
			while(Item != NULL){
				printf(" %d", Item -> valor);
				Item = Item -> atras;
			}
			printf("\n");
		}else
			printf("Stack is empty\n");

		cont++;
	}

	return 0;
}
