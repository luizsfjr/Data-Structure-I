#include<stdio.h>
#include<stdlib.h>
struct lista
{
	int info;
	struct lista *prox;
};
typedef struct lista Lista;
Lista *inicializa()
{
	return NULL;
}
Lista *insere(Lista *l, int i)
{
	Lista *novo = (Lista*) malloc(sizeof(Lista));
	if(l == NULL){
		novo->info = i;
		novo->prox = novo;
		printf("Inserido com sucesso!!!\n");
		return novo;
	} else{
		novo->info = i;
		novo->prox = l->prox;
		l->prox = novo;
		printf("Inserido com sucesso!!!\n");
		return novo;
	}
}
void imprimir(Lista *l)
{
	Lista *p = l;
	if(p){
		do{
			printf("dado: %d | atual: %i | proximo: %i \n", p->info, p, p->prox);
			p = p->prox;
		} while(p != l );
	}
}
Lista *buscar(Lista *l, int i){
	Lista *p = l;
	Lista *achado;
	do{
		if(p->info == i){
			achado = p;
		} 
		p = p->prox;
	} while(p!=l);
	if(achado != NULL){
		printf("Valor encontrado!\n");
		return achado;
	}else{
		printf("Valor nao encontrado!\n");
		return l;
	}
}

Lista *remover(Lista *l){
	 Lista *p;
	 p = l;
	 while(p->prox != l){
	 	p = p->prox;
	 }
	 Lista *no = l;
	 p->prox = no->prox;
	 l = no->prox;
	 free(no);
	 return l;
}
main()
{
	Lista *l;
	Lista *busca;
	l = inicializa();
	l = insere(l, 70);
	l = insere(l, 100);
	l = insere(l, 15);
	l = insere(l, 30);
	l = insere(l, 9);
	busca = buscar(l, 6);
	busca = buscar(l ,100);
	imprimir(l);
	printf("Removendo...\n");
	l = remover(l);
	printf("Imprimindo...\n");
	imprimir(l);
}
