package listadupla;

public class ListaDuplamenteEncadeada<T> {
    private NoDuplo<T> primeiro;
    private NoDuplo<T> ultimo;

    public ListaDuplamenteEncadeada() {
        this.primeiro = null;
        this.ultimo = null;
    }

    public boolean isEmpty() {
        return primeiro == null;
    }

    public int size() {
        int tamanho = 0;
        NoDuplo<T> noAux = primeiro;
        while (noAux != null) {
            tamanho++;
            noAux = noAux.getProx();
        }
        return tamanho;
    }

    public void add(T conteudo) {
        NoDuplo<T> novoNo = new NoDuplo<>(conteudo);
        if (isEmpty()) {
            primeiro = novoNo;
            ultimo = novoNo;
        } else {
            ultimo.setProx(novoNo);
            novoNo.setAnt(ultimo);
            ultimo = novoNo;
        }
    }

    public void add(int index, T conteudo) {
        if (index == 0) {
            NoDuplo<T> novoNo = new NoDuplo<>(conteudo);
            novoNo.setProx(primeiro);
            primeiro.setAnt(novoNo);
            primeiro = novoNo;
        } else if (index >= size()) {
            add(conteudo);
        } else {
            NoDuplo<T> noAux = primeiro;
            for (int i = 0; i < index - 1; i++) {
                noAux = noAux.getProx();
            }
            NoDuplo<T> novoNo = new NoDuplo<>(conteudo);
            novoNo.setProx(noAux.getProx());
            noAux.getProx().setAnt(novoNo);
            novoNo.setAnt(noAux);
            noAux.setProx(novoNo);
        }
    }

    private NoDuplo<T> getNo(int index) {
        if (index < 0 || index >= size()) {
            throw new IndexOutOfBoundsException("Índice inválido");
        }
        NoDuplo<T> noAux = primeiro;
        for (int i = 0; i < index; i++) {
            noAux = noAux.getProx();
        }
        return noAux;
    }

    public T get(int index) {
        return getNo(index).getConteudo();
    }

    public T remove(int index) {
        NoDuplo<T> pivo = getNo(index);
        if (index == 0) {
            primeiro = pivo.getProx();
        } else if (index == size() - 1) {
            ultimo = pivo.getAnt();
            ultimo.setProx(null);
        } else {
            pivo.getAnt().setProx(pivo.getProx());
            pivo.getProx().setAnt(pivo.getAnt());
        }
        return pivo.getConteudo();
    }

    @Override
    public String toString() {
        String strRetorno = "";
        NoDuplo<T> noAux = primeiro;
        while (noAux != null) {
            strRetorno += "->" + noAux.getConteudo();
            noAux = noAux.getProx();
        }
        strRetorno += "->null";
        return strRetorno;
    }
}
