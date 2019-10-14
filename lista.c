#include <stdio.h>
#include <stdlib.h>

typedef struct tipoPessoa {
	char nome[30];
	char endereco[20];
	float altura;
}tipoPessoa;

typedef struct tipoNo {
	tipoPessoa d;
	struct tipoNo *prox;
}tipoNo;

typedef struct tipoLista {
	tipoNo *prim;
}tipoLista;

void criaLista (tipoLista *l) {
	l->prim = NULL;
}

void lePessoa (tipoPessoa *d) {
	printf("Digite o nome da pessoa -> \n");
	scanf("%[^\n]%*c", d->nome);
	printf("\nDigite o endereco -> \n");
	scanf("%[^\n]%*c", d->endereco);
	printf("Digite a altura -> \n");
	scanf("%f%*c", &d->altura);
}

void insereNaLista (tipoLista *lista, tipoPessoa dado) {
	tipoNo *aux;
	aux = (tipoNo*) malloc (sizeof(tipoNo));

	aux ->d = dado;
	aux-> prox = lista-> prim;
	lista-> prim = aux;
}

// 1º Questão ->

tipoPessoa removeFloat (tipoLista *l, float chave) {
	tipoNo*aux;

	
}

void mostraDado(tipoPessoa d) {
  printf("------------------\n");
  printf("Nome: %s\n", d.nome);
  printf("ID: %s\n", d.endereco);
  printf("Altura: %.2f\n", d.altura);
}

// uma das muitas versoes para mostrar os dados armazenados em uma lista

void mostraLista(tipoLista l) {
  while(l.prim) {
    mostraDado(l.prim->d);
    l.prim = l.prim->prox;
  }
}

int main () {
	tipoPessoa d;
	tipoLista lista1;

	criaLista(&lista1);
	lePessoa(&d);
	insereNaLista(&lista1, d);
	lePessoa(&d);
	insereNaLista(&lista1, d);
	lePessoa(&d);
	insereNaLista(&lista1, d);
	mostraLista(lista1);


	return 0;
}