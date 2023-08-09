package no;

public class No<T extends Comparable<T>> {
	private T conteudo;
	private No<T> noEsq;
	private No<T> noDir;
	/**
	 * @param conteudo
	 */
	public No(T conteudo) {
		this.conteudo = conteudo;
		noEsq = noDir = null;
	}
	
	public No() {
		
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
	 * @return the noEsq
	 */
	public No<T> getNoEsq() {
		return noEsq;
	}

	/**
	 * @param noEsq the noEsq to set
	 */
	public void setNoEsq(No<T> noEsq) {
		this.noEsq = noEsq;
	}

	/**
	 * @return the noDir
	 */
	public No<T> getNoDir() {
		return noDir;
	}

	/**
	 * @param noDir the noDir to set
	 */
	public void setNoDir(No<T> noDir) {
		this.noDir = noDir;
	}

	@Override
	public String toString() {
		return "No " + conteudo + "\nnoEsq=" + noEsq + "\nnoDir=" + noDir + "\n";
	}
	
	
}