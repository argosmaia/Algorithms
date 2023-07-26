package pilha;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Pilha pilha = new Pilha();

        int opcao = 0;

        do {
            System.out.println("\n===== Menu =====");
            System.out.println("1 - Empilhar");
            System.out.println("2 - Desempilhar");
            System.out.println("3 - Exibir a pilha");
            System.out.println("4 - Sair");
            System.out.print("Escolha uma opção: ");

            opcao = scanner.nextInt();

            switch (opcao) {
                case 1:
                    System.out.print("Digite o dado a ser empilhado: ");
                    int dado = scanner.nextInt();
                    No novoNo = new No(dado);
                    pilha.empilha(novoNo);
                    System.out.println("Dado empilhado com sucesso!");
                    break;

                case 2:
                    No noDesempilhado = pilha.desempilha();
                    if (noDesempilhado != null) {
                        System.out.println("Dado desempilhado: " + noDesempilhado.getDado());
                    } else {
                        System.out.println("A pilha está vazia!");
                    }
                    break;

                case 3:
                    System.out.println(pilha);
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
