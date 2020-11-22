
#include <stdio.h>
#include <stdlib.h>

struct TpQueue {
	struct TpQueue* prox;
	int elem;
};

typedef struct TpQueue Queue;

void init(Queue** f) {
	*f = NULL;
}

Queue* CriaNo(int elem) {
	Queue* nova = (Queue*)malloc(sizeof(Queue));
	nova->elem = elem;
	nova->prox = NULL;
	return nova;
}

//void enqueue(Fila** f, int elem) {
//	Fila* nova, *aux = *f;//if(*f != NULL)
//	while (aux->prox != NULL) {
//		aux = aux->prox;
//	}
//	nova = (Fila*)malloc(sizeof(Fila));
//	nova->prox = NULL;
//	nova->elem = elem;
//	*aux->prox = *nova;
//}

void enqueue(Queue** f, int elem) {
	if (*f == NULL)
		*f = CriaNo(elem);
	else
		enqueue(&(*f)->prox, elem);
}

char isEmpty(Queue* f) {
	return f == NULL;
}

void dequeue(Queue** f, int* elem) {
	if(!isEmpty(*f)){
		Queue* aux;
		aux = *f;
		*elem = (*f)->elem;//??
		*f = (*f)->prox;
		free(aux);
	}
	else
		*elem = -1;
	
}

void ViewQueue(Queue* f) {
	if (f != NULL) {
		printf("%d ", f->elem);
		ViewQueue(f->prox);
	}
}


int main(void) {
	Queue* f;
	int i;

	init(&f);
	enqueue(&f, 10);
	enqueue(&f, 20);
	enqueue(&f, 30);
	ViewQueue(f);//10,20,30
	dequeue(&f, &i);
	printf("\n%d \n", i);//10
	enqueue(&f, 40);
	ViewQueue(f);//20,30,40
}
