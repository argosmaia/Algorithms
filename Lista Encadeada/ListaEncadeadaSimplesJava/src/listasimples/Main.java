package listasimples;

import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        ListaEncadeada<String> lista = new ListaEncadeada<>();
        Scanner scanner = new Scanner(System.in);

        int opcao = 0;

        do {
            System.out.println("\n===== Menu =====");
            System.out.println("1 - Adicionar elemento");
            System.out.println("2 - Remover elemento");
            System.out.println("3 - Imprimir lista");
            System.out.println("4 - Sair");
            System.out.print("Escolha uma opção: ");

            try {
                opcao = Integer.parseInt(scanner.nextLine());
            } catch (NumberFormatException e) {
                System.out.println("Opção inválida! Digite um número válido.");
                continue;
            }

            switch (opcao) {
                case 1:
                    System.out.print("Digite o elemento a ser adicionado: ");
                    String elemento = scanner.nextLine();
                    lista.add(elemento);
                    System.out.println("Elemento adicionado com sucesso!");
                    break;

                case 2:
                    if (lista.isEmpty()) {
                        System.out.println("A lista está vazia, não é possível remover elementos.");
                    } else {
                        System.out.print("Digite o índice do elemento a ser removido: ");
                        int index = Integer.parseInt(scanner.nextLine());
                        try {
                            String elementoRemovido = lista.remove(index);
                            System.out.println("Elemento removido: " + elementoRemovido);
                        } catch (IndexOutOfBoundsException e) {
                            System.out.println(e.getMessage());
                        }
                    }
                    break;

                case 3:
                    System.out.println("Lista: " + lista);
                    break;

                case 4:
                    System.out.println("Saindo do programa...");
                    break;

                default:
                    System.out.println("Opção inválida!");
                    break;
            }

        } while (opcao != 4);

        scanner.close();
    }
}
