#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura do nó da árvore
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Função para criar um novo nó com o dado informado
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Função para inserir um novo dado na árvore
Node* insert(Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    } else if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    return root;
}

// Função para realizar a busca de um dado na árvore
Node* search(Node* root, int data) {
    if (root == NULL || root->data == data) {
        return root;
    } else if (data < root->data) {
        return search(root->left, data);
    } else {
        return search(root->right, data);
    }
}

// Função para imprimir os dados da árvore em ordem crescente
void inorderTraversal(Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

int main() {
    Node* root = NULL;
    int choice;
    int data;

    while (1) {
        printf("Digite 1 para inserir um dado, 2 para buscar um dado, 3 para imprimir a arvore em ordem crescente, ou 0 para sair: ");
        scanf("%d", &choice);

        switch (choice) {
            case 0:
                printf("Saindo...\n");
                exit(0);
            case 1:
                printf("Digite o valor a ser inserido: ");
                scanf("%d", &data);
                root = insert(root, data);
                printf("Valor inserido com sucesso!\n");
                break;
            case 2:
                printf("Digite o valor a ser buscado: ");
                scanf("%d", &data);
                Node* result = search(root, data);
                if (result == NULL) {
                    printf("Valor nao encontrado na arvore.\n");
                } else {
                    printf("Valor encontrado na arvore.\n");
                }
                break;
            case 3:
                printf("Arvore em ordem crescente: ");
                inorderTraversal(root);
                printf("\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
                break;
        }
    }

    return 0;
}
