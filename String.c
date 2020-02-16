#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct strDin {
	struct strDin* prox;
	char letra;
};

typedef struct strDin String;

void Init(String** str) {
	*str = NULL;
}

void Reset(String** str) {
	if (*str != NULL) {
		Reset(&(*str)->prox);
	}
	free(*str);
	*str = NULL;
}

void ViewString(String* str) {
	if (str != NULL) {
		printf("%c",str->letra);
		ViewString(str->prox);
	}
}

void ViewInvertString(String* str) {
	if (str != NULL)
		ViewInvertString(str->prox);
	if(str != NULL)
		printf("%c", str->letra);
}

void Length(String* str, int* length) {
	if (str != NULL) {
		*length = *length + 1;
		Length(str->prox, &(*length));
	}
}

String* CreateNode(char elem) {
	String* aux = (String*)malloc(sizeof(String));
	aux->letra = elem;
	aux->prox = NULL;
	return aux;
}

void InsertC(String** str, char letra) {
	if (*str == NULL) {
		*str = CreateNode(letra);
	}
	else
		InsertC(&(*str)->prox, letra);
}

void Copy(String* str1, String** str2) {

	while (str1 != NULL)
	{
		InsertC(&(*str2), str1->letra);
		str1 = str1->prox;
	}
}

void Concat(String* str1, String* str2, String** str3) {
	Copy(str1, &(*str3));
	Copy(str2, &(*str3));
}

void Remove(String** str, int start, int nro) {
	int i;
	String* ant, *aux, *del;
	aux = *str;
	for (i = 0; i < start-1; i++)
	{
		if (aux != NULL) {
			aux = aux->prox;
		}
	}
	ant = aux;
	aux = aux->prox;
	for (i = 0; i < nro; i++)
	{
		if (aux != NULL) {
			del = aux;
			aux = aux->prox;
			free(del);
		}
	}
	ant->prox = aux;
}

void InsertSubs(String** str, String* subs, int start) {
	int i;
	String* aux, *auxsub;
	aux = *str;
	for (i = 0; i < start; i++)
	{
		if (aux != NULL) {
			aux = aux->prox;
		}
	}
	auxsub = subs;
	while (auxsub->prox!=NULL)
	{
		auxsub = auxsub->prox;
	}
	auxsub->prox = aux->prox;
	aux->prox = subs;
}

bool Smaller(String* str1, String* str2) {
	int x=0, y=0;
	Length(str1, &x);
	Length(str2, &y);
	return x < y;
}

bool Equal(String* str1, String* str2) {
	while (str1!=NULL && str2!=NULL && str1->letra == str2->letra)
	{
		str1 = str1->prox;
		str2 = str2->prox;
	}
	if (str1 == NULL && str2 == NULL)
		return 1;
	else
		return 0;
}

void Seek(String* str1, String*subs, int* pos) {
	String* aux, * auxsubs;
	int cont = 1;
	auxsubs = subs;

	while (str1!=NULL)
	{
		if (str1->letra == auxsubs->letra) {
			aux = str1;
			while (auxsubs!=NULL && auxsubs->letra == aux->letra)
			{
				aux = aux->prox;
				auxsubs = auxsubs->prox;
			}
			if (auxsubs == NULL) {
				*pos = cont;
			}
			auxsubs = subs;
		}
		str1 = str1->prox;
		cont++;
	}
}

int main(void) {
	String* str, * strcop, * strconcat, *subs;
	int length = 0, cont=0;
	Init(&str);
	Init(&strcop);
	Init(&strconcat);
	InsertC(&str, 'E');
	InsertC(&str, 'D');
	InsertC(&str, 'e');
	InsertC(&str, 'F');
	InsertC(&str, 'O');
	InsertC(&str, 'D');
	InsertC(&str, 'A');
	ViewString(str);
	printf("\n");
	ViewInvertString(str);
	Length(str, &length);
	printf("\n%d", length);
	printf("\n");
	Copy(str, &strcop);
	ViewString(strcop);
	printf("\n");
	Concat(str, strcop, &strconcat);
	ViewString(strconcat);
	printf("\n");
	Remove(&str, 2, 2);
	ViewString(str);
	printf("\n");
	InsertSubs(&str, strcop, 0);
	ViewString(str);
	printf("\n");
	if(Smaller(str, strcop))
		printf("menor\n");
	else
		printf("maior\n");
	if(Equal(str, str))
		printf("igual\n");
	else
		printf("diferente\n");
	Init(&subs);
	InsertC(&subs, 'F');
	InsertC(&subs, 'O');
	InsertC(&subs, 'D');
	InsertC(&subs, 'A');
	Seek(str, subs, &cont);
	printf("%d", cont);
	Reset(&str);
	ViewString(str);

}
