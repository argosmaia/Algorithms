package listadupla;

import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        ListaDuplamenteEncadeada<Integer> lista = new ListaDuplamenteEncadeada<>();

        int opcao;

        do {
            System.out.println("\n===== Menu =====");
            System.out.println("1 - Adicionar elemento");
            System.out.println("2 - Adicionar elemento em posição específica");
            System.out.println("3 - Remover elemento em posição específica");
            System.out.println("4 - Ver tamanho da lista");
            System.out.println("5 - Ver elementos da lista");
            System.out.println("6 - Sair");
            System.out.print("Escolha uma opção: ");

            opcao = scanner.nextInt();

            switch (opcao) {
                case 1:
                    System.out.print("Digite o valor a ser adicionado: ");
                    int valor = scanner.nextInt();
                    lista.add(valor);
                    System.out.println("Valor adicionado com sucesso!");
                    break;

                case 2:
                    System.out.print("Digite o valor a ser adicionado: ");
                    int valorAdicionar = scanner.nextInt();
                    System.out.print("Digite a posição: ");
                    int posicao = scanner.nextInt();
                    lista.add(posicao, valorAdicionar);
                    System.out.println("Valor adicionado com sucesso na posição " + posicao + "!");
                    break;

                case 3:
                    System.out.print("Digite a posição do elemento a ser removido: ");
                    int posicaoRemover = scanner.nextInt();
                    int valorRemovido = lista.remove(posicaoRemover);
                    System.out.println("Elemento removido: " + valorRemovido);
                    break;

                case 4:
                    System.out.println("Tamanho da lista: " + lista.size());
                    break;

                case 5:
                    System.out.println("Elementos da lista: " + lista.toString());
                    break;

                case 6:
                    System.out.println("Saindo do programa...");
                    break;

                default:
                    System.out.println("Opção inválida!");
                    break;
            }

        } while (opcao != 6);

        scanner.close();
    }
}
