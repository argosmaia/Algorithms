package listadupla;

public class NoDuplo<T> {
    private T conteudo;
    private NoDuplo<T> prox;
    private NoDuplo<T> ant;

    public NoDuplo(T conteudo) {
        this.conteudo = conteudo;
        this.prox = null;
        this.ant = null;
    }

    public T getConteudo() {
        return conteudo;
    }

    public void setConteudo(T conteudo) {
        this.conteudo = conteudo;
    }

    public NoDuplo<T> getProx() {
        return prox;
    }

    public void setProx(NoDuplo<T> prox) {
        this.prox = prox;
    }

    public NoDuplo<T> getAnt() {
        return ant;
    }

    public void setAnt(NoDuplo<T> ant) {
        this.ant = ant;
    }

    @Override
    public String toString() {
        return "NoDuplo [conteudo=" + conteudo + "]";
    }
}
