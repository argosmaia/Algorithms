/**
 * 
 */
package listacircular;

/**
 * @author argosmaia
 *
 */
public class ListaEncadeadaCircular<T> {
    private NoCircular<T> cabeca;
    private int tamanho;

    public ListaEncadeadaCircular() {
        cabeca = null;
        tamanho = 0;
    }

    public boolean isEmpty() {
        return tamanho == 0;
    }

    public int size() {
        return tamanho;
    }

    public void add(T conteudo) {
        NoCircular<T> novoNo = new NoCircular<>(conteudo);
        if (isEmpty()) {
            cabeca = novoNo;
            cabeca.setProx(cabeca);
        } else {
            NoCircular<T> ultimo = cabeca;
            while (ultimo.getProx() != cabeca) {
                ultimo = ultimo.getProx();
            }
            novoNo.setProx(cabeca);
            ultimo.setProx(novoNo);
        }
        tamanho++;
    }

    public void add(int index, T conteudo) {
        if (index == 0) {
            NoCircular<T> novoNo = new NoCircular<>(conteudo);
            NoCircular<T> ultimo = cabeca;
            while (ultimo.getProx() != cabeca) {
                ultimo = ultimo.getProx();
            }
            novoNo.setProx(cabeca);
            cabeca = novoNo;
            ultimo.setProx(cabeca);
        } else if (index >= tamanho) {
            add(conteudo);
        } else {
            NoCircular<T> novoNo = new NoCircular<>(conteudo);
            NoCircular<T> anterior = getNo(index - 1);
            novoNo.setProx(anterior.getProx());
            anterior.setProx(novoNo);
        }
        tamanho++;
    }

    private NoCircular<T> getNo(int index) {
        if (index < 0 || index >= tamanho) {
            throw new IndexOutOfBoundsException("Índice inválido");
        }
        NoCircular<T> atual = cabeca;
        for (int i = 0; i < index; i++) {
            atual = atual.getProx();
        }
        return atual;
    }

    public T get(int index) {
        return getNo(index).getConteudo();
    }

    public T remove(int index) {
        if (isEmpty()) {
            throw new RuntimeException("Lista vazia, não é possível remover elementos.");
        }

        NoCircular<T> pivo = cabeca;
        if (index == 0) {
            NoCircular<T> ultimo = cabeca;
            while (ultimo.getProx() != cabeca) {
                ultimo = ultimo.getProx();
            }
            cabeca = cabeca.getProx();
            ultimo.setProx(cabeca);
        } else if (index >= tamanho - 1) {
            pivo = getNo(tamanho - 1);
            NoCircular<T> anterior = getNo(tamanho - 2);
            anterior.setProx(cabeca);
        } else {
            NoCircular<T> anterior = getNo(index - 1);
            pivo = anterior.getProx();
            anterior.setProx(pivo.getProx());
        }
        tamanho--;
        return pivo.getConteudo();
    }

    @Override
    public String toString() {
        if (isEmpty()) {
            return "Lista Encadeada Circular Vazia";
        }

        StringBuilder sb = new StringBuilder();
        NoCircular<T> atual = cabeca;
        do {
            sb.append(atual.getConteudo());
            sb.append(" -> ");
            atual = atual.getProx();
        } while (atual != cabeca);
        sb.append("...");
        return sb.toString();
    }
}