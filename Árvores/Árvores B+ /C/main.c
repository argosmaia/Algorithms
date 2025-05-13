#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define GRAU 4

// DEFINIÇÕES DE "CLASSES"
typedef struct Node {
  int *dados; // Array de chaves
  int arvore;
  struct Node** filhos; // Array de ponteiros filhos da arvore
  int n; // numero de chaves de uma arvore
  bool folhas;
  struct Node* prox;
} Node;

typedef struct ArvoreBmais {
  Node* raiz;
  int arvore;
} ArvoreBmais;

// DEFINIÇÕES PARA FUNÇÕES EM C
Node* criaNode(int arvore, bool folha);
Node* criaArvore(int arvore);
void dividir(Node* pai, int i, Node* filho);
void folhaVazia(Node* no, int dado);
void inserir(ArvoreBmais *arvorebmais, int dados);
void mostrar(Node* no);
void inserir(ArvoreBmais *arvorebmais, int dados);
bool procurar(Node* no, int dado);
void deletar(ArvoreBmais* arvorebmais, int dado);
void deletaRecursivo(Node* no, int dado);
int buscaIndexDado(Node* no, int dado);
void removerDaFolha(Node* no, int indice);
int getAntecessor(Node* no, int indice);
void preenche(Node* node, int indice);
void emprestaDoAnterior(Node* no, int indice);
void emprestaDoProximo(Node* no, int indice);
void mesclar(Node* no, int indice);

// ---------------------------------------------

// IMPLEMENTAÇÕES DO ALGORITMO
Node* inicializa() {
  return NULL;
}


// bool vazia(ArvoreBmais *arvore) {
//   if(arvore == NULL) return true; // se a arvore por completa existe
//   if(arvore->raiz == NULL) return true; // se a raiz é nula
//   return false;
// }

Node* criaNode(int arvore, bool folhas) { // Cria um nó para a árvore
  Node* novoNo = (Node*)malloc(sizeof(Node));
  novoNo->arvore = arvore;
  novoNo->folhas = folhas;
  novoNo->dados = (int*)malloc((2*arvore-1) * sizeof(int));
  novoNo->filhos = (Node**)malloc((2 * arvore) * sizeof(Node*));
  novoNo->n = 0;
  novoNo->prox = NULL;

  return novoNo;
}

Node* criaArvore(int arvore) {
  ArvoreBmais* arvorebmais = (ArvoreBmais*)malloc(sizeof(ArvoreBmais));
  arvorebmais->arvore = arvore;
  arvorebmais->raiz = criaNode(arvore, true);
  return arvorebmais;
}

void dividir(Node* pai, int i, Node* filho) {
  int arvore = filho->arvore;
  Node* novoFilho = criaNode(arvore, filho->folhas);
  novoFilho->n = arvore - 1;

  for(int j = 0; j < arvore - 1; j++) novoFilho->dados[j] = filho->dados[j + arvore];
  if(!filho->folhas) for(int j = 0; j < arvore; j++) novoFilho->filhos[j] = filho->filhos[j + arvore];
  filho->n = arvore - 1;

  for(int j = pai->n; j >= i + 1; j--) pai->filhos[j + 1] = pai->filhos[j];
  pai->filhos[i + 1] = novoFilho;

  for (int j = pai->n - 1; j >= i; j--) pai->dados[j + 1] = pai->dados[j];
  pai->dados[i] = filho->dados[arvore - 1];
  pai->n +=1;
}

void folhaVazia(Node* no, int dado) {
  int i = no->n - 1;
  if(no->folhas) {
    while(i >= 0 && no->dados[i] > dado) {
      no->dados[i + 1] = no->dados[i];
      i--;
    }
    no->dados[i + 1] = dado;
    no->n += 1;
  } else {
    while(i >= 0 && no->dados[i] > dado) i--;
    i++;
    if(no->filhos[i]->n == 2 * no->arvore - 1) {
      dividir(no, i, no->filhos[i]);
      if(no->dados[i] < dado) i++;
    }
    folhaVazia(no->filhos[i], dado);
  }
}

void inserir(ArvoreBmais *arvorebmais, int dados) {
  Node* pRaiz = arvorebmais->raiz;
  if(pRaiz->n = 2 * arvorebmais->arvore - 1) {
    Node* novaRaiz = criaNode(arvorebmais->arvore, false);
    novaRaiz->filhos[0] = pRaiz;
    dividir(novaRaiz, 0, pRaiz);
    folhaVazia(novaRaiz, dados);
    arvorebmais->raiz = novaRaiz;
  } else {
    folhaVazia(pRaiz, dados);
  }
}

void mostrar(Node* no) {
  int i = 0;
  if(no == NULL) return;
  printf("(");
  for(i = 0; i < no->n; i++) {
    if(!no->folhas) mostrar(no->filhos[i]);
    printf("%d", no->dados[i]);
  }
  if(!no->folhas) mostrar(no->filhos[i]);
  printf(")\n");
}

bool procurar(Node* no, int dado) {
  int i = 0;
  while(i < no->n && dado > no->dados[i]) i++;
  if(i < no->n && dado == no->dados[i]) return true;
  if(no->folhas) return false;
  return procurar(no->filhos[i], dado);
}

int buscaIndexDado(Node* no, int dado) {
  int indice = 0;
  while(indice < no->n && dado > no->dados[indice]) indice++;
  return indice;
}

void deletar(ArvoreBmais* arvorebmais, int dado) {
  Node* pRaiz = arvorebmais->raiz;
  deletaRecursivo(pRaiz, dado);

  // Se uma arvore não tem mais raízes, o primeiro filho é a nova raíz
  if(pRaiz->n == 0 && !pRaiz->folhas) {
    arvorebmais->raiz = pRaiz->filhos[0];
    free(pRaiz);
  }
}

void deletaRecursivo(Node* no, int dado) {
  int indice = buscaIndexDado(no, dado);
  if(indice < no->n && no->dados[indice] == dado) {
    if(no->folhas) {
      removerDaFolha(no, indice);
    } else {
      int antecessor = getAntecessor(no, indice);
      no->dados[indice] = antecessor;
      deletaRecursivo(no->filhos[indice], antecessor); // Remoção recursiva
    }
  } else {
    if(no->folhas) {
      printf("%d não foi achado no índice\n", dado); // Se não achar nada, retorna um erro
      return;
    }
    bool ultimoFilho = (indice == no->n);

    if(no->filhos[indice]->n < no->arvore) preenche(no, indice);

    if(ultimoFilho && indice > no->n) deletaRecursivo(no->filhos[indice - 1], dado);
    deletaRecursivo(no->filhos[indice], dado);
  }
}

// Remove um dado de uma nó de uma folha
void removerDaFolha(Node* no, int indice) {
  for(int i = indice + 1; i < no->n; i++) no->dados[i - 1] = no->dados[i];
  no->n--;
}

int getAntecessor(Node* no, int indice) {
  Node* atual = no->filhos[indice];
  while(!atual->folhas) atual = atual->filhos[indice];
  return atual->dados[atual->n - 1];
}

void preenche(Node* no, int indice) {
  if(indice != 0 && no->filhos[indice - 1]->n >= no->arvore) {
    emprestaDoAnterior(no, indice);
  } else if(indice != no->n && no->filhos[indice + 1]->n >= no->arvore) {
    emprestaDoProximo(no, indice);
  } else {
    if(indice != no->n) mesclar(no, indice);
    mesclar(no, indice - 1);
  }
}

void emprestaDoAnterior(Node* no, int indice) {
  Node* filho = no->filhos[indice];
  Node* irmao = no->filhos[indice - 1];

  for(int i = filho->n - 1; i >= 0; i--) filho->dados[indice + 1] = irmao->dados[irmao->n - 1];
  if(!filho->folhas) for(int i = filho->n; i >= 0; i--) filho->filhos[i + 1] = filho->filhos[i];
  filho->dados[0] = no->dados[indice + 1];
  if(!filho->folhas) filho->filhos[0] = irmao->dados[irmao->n - 1];
  no->dados[indice - 1] = irmao->dados[irmao->n - 1];
  filho->n += 1;
  irmao->n -= 1;
}

void emprestaDoProximo(Node* no, int indice) {
  Node* filho = no->filhos[indice];
  Node* irmao = no->filhos[indice + 1];

  filho->dados[(filho->n)] = no->dados[indice];
  if(!filho->folhas) filho->filhos[(filho->n) + 1] = irmao->filhos[0];
  no->dados[indice] = irmao->dados[0];

  for(int i = 1; i < irmao->n; i++) irmao->dados[i - 1] = irmao->dados[i];
  if(!irmao->folhas) for(int i = 1; i <= irmao->n; i++) irmao->filhos[i - 1] = irmao->filhos[i];

  filho->n += 1;
  irmao->n -= 1;
}

void mesclar(Node* no, int indice) {
  Node* filho = no->filhos[indice];
  Node* irmao = no->filhos[indice - 1];

  filho->dados[filho->n] = no->dados[indice];
  if(!filho->folhas) filho->filhos[filho->n + 1] = irmao->filhos[0];
  for(int i = 0; i < irmao->n; i++) filho->dados[i + filho->n + 1] = irmao->dados[i];
  for(int i = indice + 2; i < no->n; i++) no->dados[i - 1] = no->filhos[i];

  filho->n += irmao->n + 1;
  no->n--;

  free(irmao);
}

int main() {
  int opcao, valor;
  ArvoreBmais* minhaArvore = (ArvoreBmais*)malloc(sizeof(ArvoreBmais));
  minhaArvore->arvore = GRAU;
  minhaArvore->raiz = criaNode(GRAU, true);
  while (1) {
    printf("\n--- MENU ARVORE B+ ---\n");
    printf("1. Inserir valor\n");
    printf("2. Mostrar árvore\n");
    printf("3. Procurar valor\n");
    printf("4. Remover valor\n");
    printf("0. Sair\n");
    printf("Escolha uma opção: ");
    scanf("%d", &opcao);

    switch (opcao) {
      case 1:
        printf("Digite o valor a inserir: ");
        scanf("%d", &valor);
        inserir(minhaArvore, valor);
        break;

      case 2:
        printf("Árvore B+: ");
        mostrar(minhaArvore->raiz);
        break;

      case 3:
        printf("Digite o valor a procurar: ");
        scanf("%d", &valor);
        if (procurar(minhaArvore->raiz, valor)) {
          printf("Valor %d encontrado na árvore!\n", valor);
        } else {
          printf("Valor %d NÃO encontrado.\n", valor);
        }
        break;

      case 4:
        printf("Digite o valor a remover: ");
        scanf("%d", &valor);
        deletar(minhaArvore, valor);
        break;

      case 0:
        printf("Encerrando o programa.\n");
        return 0;

      default:
        printf("Opção inválida.\n");
    }
  }

  return 0;
}
