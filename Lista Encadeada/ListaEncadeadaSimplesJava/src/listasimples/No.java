/**
 * 
 */
package listasimples;

/**
 * @author argosmaia
 *
 */
public class No<T> {
	private T conteudo;
	private No prox;
	
	public No() {
		this.prox = null;
	}

	/**
	 * @param conteudo
	 */
	public No(T conteudo) {
		this.conteudo = conteudo;
	}

	/**
	 * @param conteudo
	 * @param prox
	 */
	public No(T conteudo, No prox) {
		this.conteudo = conteudo;
		this.prox = prox;
	}

	/**
	 * @return the conteudo
	 */
	public T getConteudo() {
		return conteudo;
	}

	/**
	 * @param conteudo the conteudo to set
	 */
	public void setConteudo(T conteudo) {
		this.conteudo = conteudo;
	}

	/**
	 * @return the prox
	 */
	public No getProx() {
		return prox;
	}

	/**
	 * @param prox the prox to set
	 */
	public void setProx(No prox) {
		this.prox = prox;
	}

	@Override
	public String toString() {
		return "Conteudo: " + conteudo + "\nProx: " + prox + "\n";
	}
	
	public String toStringEncadeado() {
		String str = "No {"
				+ "conteudo: " + conteudo + "\n}\n";
		if(prox != null) {
			str += "->" + prox.toString();
		} else {
			str += "-> null";
		}
		return str;
	}
}
