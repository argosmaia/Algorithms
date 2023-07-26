/**
 * 
 */
package listacircular;
import java.util.Scanner;
/**
 * @author argosmaia
 *
 */


public class Main {

    public static void main(String[] args) {
        ListaEncadeadaCircular<Integer> lista = new ListaEncadeadaCircular<>();
        Scanner scanner = new Scanner(System.in);

        int opcao;
        do {
            System.out.println("\n===== Menu =====");
            System.out.println("1 - Adicionar elemento");
            System.out.println("2 - Adicionar elemento em posição específica");
            System.out.println("3 - Remover elemento");
            System.out.println("4 - Obter tamanho da lista");
            System.out.println("5 - Imprimir lista");
            System.out.println("0 - Sair");
            System.out.print("Escolha uma opção: ");
            opcao = scanner.nextInt();

            switch (opcao) {
                case 1:
                    System.out.print("Digite o elemento a ser adicionado: ");
                    int elementoAdd = scanner.nextInt();
                    lista.add(elementoAdd);
                    System.out.println("Elemento adicionado com sucesso!");
                    break;

                case 2:
                    System.out.print("Digite a posição do elemento: ");
                    int posicaoAdd = scanner.nextInt();
                    System.out.print("Digite o elemento a ser adicionado: ");
                    int elementoAddPosicao = scanner.nextInt();
                    lista.add(posicaoAdd, elementoAddPosicao);
                    System.out.println("Elemento adicionado na posição " + posicaoAdd + " com sucesso!");
                    break;

                case 3:
                    System.out.print("Digite a posição do elemento a ser removido: ");
                    int posicaoRemover = scanner.nextInt();
                    int elementoRemovido = lista.remove(posicaoRemover);
                    System.out.println("Elemento removido: " + elementoRemovido);
                    break;

                case 4:
                    System.out.println("Tamanho da lista: " + lista.size());
                    break;

                case 5:
                    System.out.println("Lista: " + lista);
                    break;

                case 0:
                    System.out.println("Saindo do programa...");
                    break;

                default:
                    System.out.println("Opção inválida!");
                    break;
            }
        } while (opcao != 0);

        scanner.close();
    }
}
