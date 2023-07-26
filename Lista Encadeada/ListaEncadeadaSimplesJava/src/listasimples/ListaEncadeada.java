/**
 * 
 */
package listasimples;

/**
 * @author argosmaia
 *
 */
public class ListaEncadeada<T> {
	No<T> refEntrada;
	
	public ListaEncadeada() {
		
	}

	/**
	 * @param refEntrada
	 */
	public ListaEncadeada(No<T> refEntrada) {
		this.refEntrada = null;
	}
	
	public boolean isEmpty() {
		return (refEntrada == null) ? true : false;
	}
	
	public int size() {
		int tamanho = 0;
		No<T> refAux = refEntrada;
		while(true) {
			if(refAux != null) {
				tamanho++;
				if(refAux.getProx() != null) {
					refAux = refAux.getProx();
				} else {
					break;
				}
			} else {
				break;
			}
		}
		return tamanho;
	}
	
	public void add(T conteudo) {
		No<T> novoNo = new No<>(conteudo);
		if(this.isEmpty()) {
			refEntrada = novoNo;
			return;
		}
		
		No<T> noAux = refEntrada;
		for(int i = 0; i < this.size()-1; i++) {
			noAux = noAux.getProx();
		}
		noAux.setProx(novoNo);
	}
	
	private No<T> getNo(int index) {
		
		validador(index);
		No<T> noAux = refEntrada;
		No<T> noRetorno = null;
		for(int i = 0; i < this.size()-1; i++) {
			noRetorno = noAux;
			noAux = noAux.getProx();
		}
		return noRetorno;
	}
	
	public T get(int index) {
		return getNo(index).getConteudo();
	}
	
	public T remove(int index) {
		No<T> pivo = this.getNo(index);
		if(index == 0) {
			refEntrada = pivo.getProx();
			return pivo.getConteudo();
		}
		No<T> anterior = getNo(index - 1);
		anterior.setProx(pivo.getProx());
		return pivo.getConteudo();
	}
	
	private void validador(int index) {
		if(index >= size()) {
			int ultimo = size()-1;
			throw new IndexOutOfBoundsException(
				String.format("Não existe conteúdo no índice %d desta linha. "+
				"Este índice só vai até %d", index, ultimo)
			);
		}
	}

	@Override
	public String toString() {
		String strRetorno = "";
		No<T> aux = refEntrada;
		for(int i = 0; i < this.size(); i++) {
			strRetorno += "->" + aux.getConteudo() + "->";
			aux = aux.getProx();
			
		}
		strRetorno += "null";
		
		return strRetorno;
	}
	
	
} 
