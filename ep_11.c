#include <stdio.h>
#include <stdlib.h>


int funcaoHash(int chave, int TAM){
  return chave % TAM;
}

typedef struct no{
  int chave;
  struct no *prox;
}No;

typedef struct Lista{
  No* inicio;
  int tam;
}Lista;

void inciaLista(Lista *l){
  l->inicio = NULL;
  l->tam = 0;
}

/*
entradas: 
2
13 9
44 45 49 70 27 73 92 97 95
7 8
35 12 2 17 19 51 88 86
*/

void inserelista(Lista *l, int valor){
No *novoNo = (No*) malloc(sizeof(No));
  novoNo->chave = valor;
  novoNo->prox = NULL;

  // Verifica se a lista está vazia
  if (l->inicio == NULL) {
    l->inicio = novoNo;
  } else {
    
    No *atual = l->inicio;
    while (atual->prox != NULL) {
      atual = atual->prox;
    }
   
    atual->prox = novoNo;
  }

 
  l->tam++;
}

int buscarNaLista(Lista *l, int chave){

  No* aux = l->inicio;

  while(aux != NULL && aux->chave != chave)
    aux = aux->prox;
  if(aux){
    return aux->chave;
  }
  return 0;
}

void imprimeLista(Lista *l){
  No *aux = l->inicio;
 
  while(aux){
    printf(" ");
    printf("%d ->", aux->chave);
    aux = aux->prox;
  }
}
//----------------------------------------------------------------
void iniciaTabelaLista(Lista t[], int TAM){
  int i;
  for(i=0; i<TAM; i++){
   inciaLista(&t[i]);//empty position
  }
}

void inserirLista(Lista t[], int valor, int TAM){
  int id = funcaoHash(valor, TAM);
  inserelista(&t[id], valor);
}



void imprimirLista(Lista t[], int TAM){
  int i;
  for(i = 0; i<TAM; i++){
    printf("%d ->", i);
    imprimeLista(&t[i]);
      printf(" \\");
    printf("\n");
  }  
  printf("\n");
}


int main(void) {
  int C, M, testes, retorno, valor, i=0;
  
  scanf("%d", &testes);
  
 
  
  while(i < testes){
    scanf("%d %d", &C, &M);
    
    Lista tabela[C];
    
    iniciaTabelaLista(tabela, C);
    
   
    
    for(int j = 0; j < M; j++){
      scanf("%d", &valor);
        inserirLista(tabela, valor, C);
    }
    imprimirLista(tabela, C);

      
    i++;
  }

 
  return 0;
}
