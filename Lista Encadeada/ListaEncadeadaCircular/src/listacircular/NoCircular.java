/**
 * 
 */
package listacircular;

public class NoCircular<T> {
    private T conteudo;
    private NoCircular<T> prox;

    public NoCircular(T conteudo) {
        this.conteudo = conteudo;
        this.prox = null;
    }

    public T getConteudo() {
        return conteudo;
    }

    public void setConteudo(T conteudo) {
        this.conteudo = conteudo;
    }

    public NoCircular<T> getProx() {
        return prox;
    }

    public void setProx(NoCircular<T> prox) {
        this.prox = prox;
    }

	@Override
	public String toString() {
		return "Conteudo: " + conteudo + "\nProx=" + prox + "\n";
	}
    
    
}