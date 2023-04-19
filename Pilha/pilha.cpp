#include <iostream>
#include <cstdlib>
#include <cstring>

#define MAX_SIZE 100

class Pilha {
private:
    char *dados[MAX_SIZE]; // Vetor para armazenar os dados
    int topo; // Variável para rastrear o topo da pilha

public:
    Pilha() { // Construtor da classe Pilha
        topo = -1; // Define o topo como -1 para indicar pilha vazia
    }

    bool is_vazia() { // Função para verificar se a pilha está vazia
        return topo == -1; // Retorna true se o topo for igual a -1, indicando pilha vazia
    }

    bool is_cheia() { // Função para verificar se a pilha está cheia
        return topo == MAX_SIZE - 1; // Retorna true se o topo for igual ao tamanho máximo da pilha
    }

    void inserir_string(const char *str) { // Função para inserir uma string na pilha
        if (is_cheia()) {
            std::cout << "Erro: Pilha cheia" << std::endl;
            return;
        }
        topo++; // Incrementa o topo
        dados[topo] = strdup(str); // Aloca memória para a string e a insere no topo da pilha
    }

    bool is_numero(const char *str) { // Função para verificar se uma string é um número real (float) ou inteiro (int)
        char *endptr;
        strtod(str, &endptr); // Converte a string para double e armazena o ponteiro para o próximo caractere em endptr
        return *endptr == '\0'; // Retorna true se o próximo caractere for o caractere nulo, indicando que a string é um número válido
    }

    void converter_numero(const char *str) { // Função para converter uma string para número real (float) ou inteiro (int)
        if (is_numero(str)) {
            int inteiro = strtol(str, NULL, 10); // Converte a string para inteiro
            std::cout << "Número inteiro: " << inteiro << std::endl;
        } else {
            float real = strtof(str, NULL); // Converte a string para float
            std::cout << "Número real: " << real << std::endl;
        }
    }

    void remover_topo() { // Função para remover o topo da pilha
        if (is_vazia()) {
            std::cout << "Erro: Pilha vazia" << std::endl;
            return;
        }
        free(dados[topo]); // Libera a memória alocada para a string do topo da pilha
        topo--; // Decrementa o topo
    }

    void ver_topo() { // Função para verificar o topo da pilha
        if (is_vazia()) {
            std::cout << "Erro: Pilha vazia" << std::endl;
            return;
        }
        std::cout << "Topo da pilha: " << dados[topo] << std::endl;
    }

    void ver_pilha() { // Função para visualizar toda a pilha
        if (is_vazia()) {
            std::cout << "Pilha vazia" << std::endl;
            return;
        }
        std::cout << "Conteúdo da pilha:" << std::endl;
        for (int i = topo; i >= 0; i--) { // Loop para percorrer a pilha do topo até o primeiro elemento
          std::cout << dados[i] << std::endl; // Imprime o elemento da pilha
         }
      }
};

int main() {
Pilha pilha; // Cria um objeto da classe Pilha
