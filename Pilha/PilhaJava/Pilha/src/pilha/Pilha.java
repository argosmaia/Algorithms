/**
 * 
 */
package pilha;

/**
 * @author argosmaia
 *
 */
public class Pilha {
	private No refNoEntradaPilha;
	
	public Pilha() {
		this.refNoEntradaPilha = null;
	}
	
	public boolean isEmpty() {
		return refNoEntradaPilha == null ? true : false; 
	}
	
	public No topo() {
		return refNoEntradaPilha;
	}
	
	public void empilha(No novoNo) {
		No refAuxiliar = refNoEntradaPilha;
		refNoEntradaPilha = novoNo;
		refNoEntradaPilha.setReNo(refAuxiliar);
	}
	
	public No desempilha() {
		/*return !isEmpty() ? (refNoEntradaPilha = refNoEntradaPilha.getReNo()) : null;
		}*/
		if(!isEmpty()) {
			No noPopped = refNoEntradaPilha;
			refNoEntradaPilha = refNoEntradaPilha.getReNo();
			return noPopped;
		}
		return null;
	}
	
	@Override
	public String toString() {
		String stringRetorno = "--------------\n";
		stringRetorno += "  Pilha\n";
		stringRetorno += "--------------\n";
		
		No noAuxiliarNo = refNoEntradaPilha;
		
		while(true) {
			if(noAuxiliarNo != null) {
				stringRetorno += "Dado: " + noAuxiliarNo.getDado() +"\n";
				noAuxiliarNo = noAuxiliarNo.getReNo();
			} else {
				break;
			}
		}
		
		stringRetorno += "==============\n";
		
		return stringRetorno;
	}
}
