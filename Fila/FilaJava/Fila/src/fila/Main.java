package fila;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Fila<Integer> fila = new Fila<>();

        int opcao = 0;

        do {
            System.out.println("\n===== Menu =====");
            System.out.println("1 - Enfileirar");
            System.out.println("2 - Desenfileirar");
            System.out.println("3 - Exibir a fila");
            System.out.println("4 - Sair");
            System.out.print("Escolha uma opção: ");

            opcao = scanner.nextInt();

            switch (opcao) {
                case 1:
                    System.out.print("Digite o dado a ser enfileirado: ");
                    int dado = scanner.nextInt();
                    fila.enfileira(dado);
                    System.out.println("Dado enfileirado com sucesso!");
                    break;

                case 2:
                    Integer dadoDesenfileirado = fila.desenfileirar();
                    if (dadoDesenfileirado != null) {
                        System.out.println("Dado desenfileirado: " + dadoDesenfileirado);
                    } else {
                        System.out.println("A fila está vazia!");
                    }
                    break;

                case 3:
                    System.out.println(fila);
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
