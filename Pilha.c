
#include <stdio.h>
#include <stdlib.h>

struct TpStack {
	struct TpStack* prox;
	int elem;
};

typedef struct TpStack Stack;

void init(Stack** p) {
	*p = NULL;
}

char Empty(Stack* p) {
	return p == NULL;
}

void push(Stack** p, int elem) {
	Stack*aux = (Stack*)malloc(sizeof(Stack));
	aux->elem = elem;
	aux->prox = *p;
	*p = aux;
}

void pop(Stack** p, int* elem) {
	Stack* aux;
	if (!Empty(*p)) {
		aux = *p;
		*elem = aux->elem;
		*p = (*p)->prox;
		free(aux);
	}
	else
		*elem = -1;
}

int top(Stack* p) {
	if (!Empty(p))
		return p->elem;
	else
		return -1;
}

void ViewStack(Stack* p) {
	if (p != NULL) {
		printf("%d ", p->elem);
		ViewStack(p->prox);
	}
}




/*int main(void) {
	Stack* p;
	int i;

	init(&p);
	push(&p, 10);
	push(&p, 20);
	push(&p, 30);
	ViewStack(p);//30,20,10
	pop(&p, &i);
	printf("%d \n", i);//30
	push(&p, 40);
	ViewStack(p);//40,20,10
}*/
