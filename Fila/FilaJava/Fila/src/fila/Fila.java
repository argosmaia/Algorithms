package fila;

public class Fila<T> {
    private No<T> refNoEntradaFila;

    public Fila() {
        this.refNoEntradaFila = null;
    }

    public boolean isEmpty() {
        return refNoEntradaFila == null;
    }

    public void enfileira(T object) {
        No<T> novoNo = new No<>(object);
        novoNo.setRefNo(refNoEntradaFila);
        refNoEntradaFila = novoNo;
    }

    public T primeiro() {
        if (!this.isEmpty()) {
            No<T> primeiroNo = refNoEntradaFila;
            while (primeiroNo.getRefNo() != null) {
                primeiroNo = primeiroNo.getRefNo();
            }
            return primeiroNo.getObject();
        }
        return null;
    }

    public T desenfileirar() {
        if (!this.isEmpty()) {
            No<T> primeiroNo = refNoEntradaFila;
            refNoEntradaFila = refNoEntradaFila.getRefNo();
            primeiroNo.setRefNo(null);
            return primeiroNo.getObject();
        }
        return null;
    }

    @Override
    public String toString() {
        String stringRetorno = "--------------\n";
        stringRetorno += "  Fila\n";
        stringRetorno += "--------------\n";

        No<T> noAuxiliar = refNoEntradaFila;
        while (noAuxiliar != null) {
            stringRetorno += "Dado: " + noAuxiliar.getObject() + "\n";
            noAuxiliar = noAuxiliar.getRefNo();
        }

        stringRetorno += "==============\n";

        return stringRetorno;
    }
}
