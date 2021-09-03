#include<stdio.h>
#include<stdlib.h>
struct lista
{
	int info;
	struct lista *prox;
	struct lista *ant;
};
typedef struct lista Lista;
Lista *inicializa()
{
	return NULL;
}
Lista *insere(Lista *l, int i)
{
	Lista *novo = (Lista*) malloc(sizeof(Lista));
	if (l != NULL)
		l->ant = novo;
	novo->info = i;
	novo->prox = l;
	novo->ant = NULL;
	return novo;
}
void imprimir(Lista *l)
{
	Lista *p = l;
	if(p){
		do{
			printf("dado: %d | atual: %i | proximo: %i | anterior: %d\n", p->info, p, p->prox, p->ant);
			p = p->prox;
		} while(p != NULL );
	}
}
main()
{
	Lista *l;
	l = inicializa();
	l = insere(l, 70);
	l = insere(l, 100);
	l = insere(l, 15);
	l = insere(l, 30);
	l = insere(l, 6);
	imprimir(l);
	
}
