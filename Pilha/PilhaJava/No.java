/**
 * 
 */
package pilha;

/**
 * @author argosmaia
 *
 */
public class No {
	private int dado;
	private No reNo = null;
	/**
	 * @param dado
	 */
	
	public No() {
	}
	
	public No(int dado) {
		this.dado = dado;
	}

	/**
	 * @return the dado
	 */
	public int getDado() {
		return dado;
	}

	/**
	 * @param dado the dado to set
	 */
	public void setDado(int dado) {
		this.dado = dado;
	}

	/**
	 * @return the reNo
	 */
	public No getReNo() {
		return reNo;
	}

	/**
	 * @param reNo the reNo to set
	 */
	public void setReNo(No reNo) {
		this.reNo = reNo;
	}

	@Override
	public String toString() {
		return "No [dado=" + dado + "]";
	}
}
