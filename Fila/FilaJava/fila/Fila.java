package fila;

public class Fila {
	private No refNoEntradaFila;
	
	public Fila() {
		this.refNoEntradaFila = null;
	}
	
	public boolean isEmpty() {
		return refNoEntradaFila == null ? true : false; 
	}
	
	public void enfileira(No novoNo) {
		novoNo.setRefNo(refNoEntradaFila);
		refNoEntradaFila = novoNo;
	}
	
	public No primeiro() {
		if(!this.isEmpty()) {
			No primeiroNo = refNoEntradaFila;
			while(true) {
				if(primeiroNo.getRefNo() != null) {
					primeiroNo = primeiroNo.getRefNo();
				} else {
					break;
				}
			}
		}
		return null;
	}
	
	public No desenfileirar() {
	    if (!this.isEmpty()) {
	        No primeiroNo = refNoEntradaFila;
	        refNoEntradaFila = refNoEntradaFila.getRefNo();
	        primeiroNo.setRefNo(null); // Remove a referência ao próximo nó (primeiroNo.getRefNo())
	        return primeiroNo;
	    }
	    return null;
	}
	
	
	@Override
	public String toString() {
		String stringRetorno = "--------------\n";
		stringRetorno += "  Fila\n";
		stringRetorno += "--------------\n";
		
		if(refNoEntradaFila != null) {
			while(true) {
				return "Fila [refNoEntradaFila=" + refNoEntradaFila + "]";
			}
		} else {
			stringRetorno = "null";
		}
		return stringRetorno;
	}
}
