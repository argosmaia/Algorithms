#include <iostream>
#define SIZE 10

using namespace std;

struct Fila {
    int dado[SIZE];
    int frente;
    int fim;

    Fila() {
        frente = -1;
        fim = -1;
    }

    bool vazio() {
        return frente == -1;
    }

    bool cheio() {
        return (fim + 1) % SIZE == frente;
    }

    void enfileirar(int valor) {
        if (cheio()) {
            cout << "\nFila cheia!\n";
            return;
        }

        if (vazio()) {
            frente = 0;
            fim = 0;
        } else {
            fim = (fim + 1) % SIZE;
        }

        dado[fim] = valor;
    }

    void desenfileirar() {
        if (vazio()) {
            cout << "\nFila vazia!\n";
            return;
        }

        if (frente == fim) {
            frente = -1;
            fim = -1;
        } else {
            frente = (frente + 1) % SIZE;
        }
    }

    void mostrar() {
        if (vazio()) {
            cout << "A fila está vazia!\n";
            return;
        }

        cout << "Elementos da fila: ";
        int i = frente;
        while (i != fim) {
            cout << dado[i] << " ";
            i = (i + 1) % SIZE;
        }
        cout << dado[fim] << endl;
    }

    void verFrente() {
        if (vazio()) {
            cout << "A fila está vazia!\n";
            return;
        }

        cout << "Elemento do inicio da fila: " << dado[frente] << endl;
    }

    void verFim() {
        if (vazio()) {
            cout << "A fila está vazia!\n";
            return;
        }

        cout << "Elemento do fim da fila: " << dado[fim] << endl;
    }
};

int main() {
    Fila fila;

    int opcao, valor;

    while (true) {
        cout << "\n----- Menu de Opcoes -----\n";
        cout << "1. Enfileirar\n";
        cout << "2. Desenfileirar\n";
        cout << "3. Ver frente\n";
        cout << "4. Ver fim\n";
        cout << "5. Ver toda a fila\n";
        cout << "6. Sair\n";
        cout << "Digite sua opcao: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                cout << "Digite o valor para enfileirar: ";
                cin >> valor;
                fila.enfileirar(valor);
                break;
            case 2:
                fila.desenfileirar();
                break;
            case 3:
                fila.verFrente();
                break;
            case 4:
                fila.verFim();
                break;
            case 5:
                fila.mostrar();
                break;
            case 6:
                cout << "Saindo...\n";
                return 0;
            default:
                cout << "Opcao invalida! Tente novamente.\n";
                break;
        }
    }

    return 0;
}
